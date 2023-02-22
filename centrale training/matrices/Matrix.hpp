#pragma once
#include <iostream>
#include <array>
#include <initializer_list>
#include <vector>
#include <concepts>

namespace matrix {
  template<typename T> concept Field =
    std::default_initializable<T> &&
    std::copy_constructible<T> &&
    std::move_constructible<T> &&
    std::destructible<T> &&
    std::equality_comparable<T> &&
    requires(T a, T b) {                 
			{ a + b } -> std::convertible_to<T>;
			{ a - b } -> std::convertible_to<T>;
			{ a * b } -> std::convertible_to<T>;
			{ a / b } -> std::convertible_to<T>;
  };
  
  // Forward declaration of class template Matrix
  template<size_t dim1, size_t dim2, Field Scalar> class Matrix;

  // Forward declaration of external operator <<
  template<size_t dim1, size_t dim2, Field Scalar>
  std::ostream& operator<<(std::ostream&, const Matrix<dim1, dim2, Scalar>&);

  template<size_t dim1, size_t dim2, Field Scalar, bool stack> struct Storage;
  
  template<size_t dim1, size_t dim2, Field Scalar> struct Storage<dim1, dim2, Scalar, true> {
    std::array<Scalar, dim1 * dim2> coefs_; // Components will be stored from top to bottom, left to right

    static const bool on_stack = true;
  };

  template<size_t dim1, size_t dim2, Field Scalar> struct Storage<dim1, dim2, Scalar, false> {
    std::vector<Scalar> coefs_; // Components will be stored from top to bottom, left to right

    static const bool on_stack = false;
    
    Storage() {
      coefs_.resize(dim1 * dim2);
    }
  };

  constexpr size_t limit_size_on_stack = 10000;
  constexpr bool best_on_stack(size_t n_rows, size_t n_cols) { return n_rows * n_cols < limit_size_on_stack; }

  // Definition of template class Matrix
  template<size_t dim1, size_t dim2, Field Scalar=double>
  class Matrix : public Storage<dim1, dim2, Scalar, best_on_stack(dim1, dim2)> {

  public:
    using scalar_type = Scalar;
  
    Matrix(Scalar value = Scalar());
    Matrix(const Matrix&) = default;
    Matrix(const std::initializer_list<std::initializer_list<Scalar>>&);

    // Read/write accessor
    Scalar& operator[](const std::pair<size_t, size_t>&);

    // Serialization operator is friend
    friend std::ostream& operator<<<dim1, dim2, Scalar>(std::ostream&, const Matrix<dim1, dim2, Scalar>&);

    // All instances of template Matrix are friend
    template <size_t, size_t, Field> friend class Matrix;
  
    // Returns the dimension of the matrix
    inline std::pair<size_t,size_t> dims() const { return std::make_pair(dim1, dim2); }

    // Addition assignment operator
    Matrix<dim1, dim2, Scalar>& operator+=(const Matrix<dim1, dim2, Scalar>&);

    // Addition internal operator
    Matrix<dim1, dim2, Scalar> operator+(const Matrix<dim1, dim2, Scalar>&) const;

    // Multiplication internal operator
    template<size_t dim3>
    Matrix<dim1, dim3, Scalar> operator*(const Matrix<dim2, dim3, Scalar>&) const;

    // General multiplication operator to generate error messages
    template<size_t dim3, size_t dim4>
    Matrix<dim1, dim4, Scalar> operator*(const Matrix<dim3, dim4, Scalar>&) const;
    
  };

  /* ------------- Definition of methods and operators -------------- */

  template<size_t dim1, size_t dim2, Field Scalar>
  Matrix<dim1, dim2, Scalar>::Matrix(Scalar value) 
  {
    for(Scalar& elt : this->coefs_) elt = value;
  }


  template<size_t dim1, size_t dim2, Field Scalar>
  Matrix<dim1, dim2, Scalar>::Matrix(const std::initializer_list<std::initializer_list<Scalar>>& coefs) 
  {
    if(coefs.size() != dim1) throw std::runtime_error("Init: bad number of lines");
    auto dst = this->coefs_.begin();
    for(auto lineCoefs : coefs) 
    {
      if(lineCoefs.size() != dim2) throw std::runtime_error("Init: bad number of columns");
      for(auto coef : lineCoefs)
        *dst++ = coef;
    }
  }

  template<size_t dim1, size_t dim2, Field Scalar>
  std::ostream& operator<<(std::ostream&os, const Matrix<dim1, dim2, Scalar>& M) {
    auto coef = M.coefs_.begin();
    for(size_t i = 0; i != dim1; ++i)
    {
      for(size_t j = 0; j != dim2; ++j)
	      os << ' ' << *coef++;
      os << std::endl;
    }
    return os;
  }

  template<size_t dim1, size_t dim2, Field Scalar>
  Scalar& Matrix<dim1, dim2, Scalar>::operator[](const std::pair<size_t,size_t>& p) { return this->coefs_[p.first * dim2 + p.second]; }

  template<size_t dim1, size_t dim2, Field Scalar>
  Matrix<dim1, dim2, Scalar>& Matrix<dim1, dim2, Scalar>::operator+=(const Matrix<dim1, dim2, Scalar>& other) {
    auto src = other.coefs_.begin();
    for(auto dst = this->coefs_.begin(), end = this->coefs_.end(); dst != end; ++dst, ++src) *dst += *src;
    return *this;
  }

  template<size_t dim1, size_t dim2, Field Scalar>
  Matrix<dim1, dim2, Scalar> Matrix<dim1, dim2, Scalar>::operator+(const Matrix<dim1, dim2, Scalar>& other) const {
    Matrix res(*this);
    res += other;
    return res;
  }

  template<typename Scalar, int count, size_t dim3>
  struct Unroll
  {
    static void add_src_prod(const Scalar* src1, const Scalar* src2, Scalar* dst)
    {
      if constexpr(count > 0)
      {
        *dst += *src1++ * *src2;
        src2 += dim3;
        Unroll<Scalar, count-1, dim3>::add_src_prod(src1, src2, dst);
      }
    }
  };

  template<size_t dim1, size_t dim2, Field Scalar>
  template<size_t dim3>
  Matrix<dim1, dim3, Scalar> Matrix<dim1, dim2, Scalar>::operator*(const Matrix<dim2, dim3, Scalar>& other) const {
    Matrix<dim1, dim3, Scalar> res;
    auto pr = res.coefs_.begin();
    if constexpr(dim2 == 1) 
    {
      for(auto& c1 : this->coefs_)
        for(auto& c2 : other.coefs_) *pr++ = c1 * c2;
    } 
    else {      
      for(size_t i = 0; i != dim1; ++i)
      {
        for(size_t j = 0; j != dim3; ++j, ++pr) 
        {
          auto p1 = this->coefs_.begin() + i * dim2;
          auto p2 = other.coefs_.begin() + j;
          size_t nb_iter = dim2 / 4;
          constexpr int remainder = dim2 % 4;
          for(size_t k = 0; k != nb_iter; ++k)
            Unroll<Scalar,4,dim3>::add_src_prod(p1, p2, pr);
          Unroll<Scalar,remainder,dim3>::add_src_prod(p1, p2, pr);
        }
      }
    }
    return res;
  }

  template<size_t dim1, size_t dim2, Field Scalar>
  template<size_t dim3, size_t dim4>
  Matrix<dim1, dim4, Scalar> Matrix<dim1, dim2, Scalar>::operator*(const Matrix<dim3, dim4, Scalar>& other) const {
    static_assert(dim2 == dim3, "Inconsistent matrix size for product");
    if constexpr (dim2 == dim3)
	    return *this * other;
  }  
}