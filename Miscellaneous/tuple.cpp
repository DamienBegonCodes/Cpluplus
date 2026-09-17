#include <utility>
#include <string>
#include <iostream>

void foo(int arg1, char arg2, std::string arg3) {}

int main()
{
    std::cout << "### Some tests on tuples ###" << std::endl << std::endl;
    
    // ### Printing a tuple
    std::cout << "1) Printing a tuple :" << std::endl;
    
    std::tuple<int, char, std::string> t1(3, 'a', "arbre");

    std::cout << "  Tuple t1 : (" << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << ")" << std::endl;


    // ### Creating a tuple using std::make_tuple
    std::cout << "2) Creating a tuple using std::make_tuple :" << std::endl;

    int var(3234);
    auto t2(std::make_tuple("HAHA", var, '%'));

    std::cout << "  Tuple t2 : (" << std::get<0>(t2) << ", " << std::get<1>(t2) << ", " << std::get<2>(t2) << ")" << std::endl;
    var = 0;

    // ### Unpacking a tuple with structured bindings and std::tie
    std::cout << "3) Unpacking a tuple with structured bindings and std::tie :" << std::endl;

    auto [var_t1_1, var_t1_2, var_t1_3] = t1;
    
    std::string var_t2_1;
    int var_t2_2;
    char var_t2_3;
    std::tie(var_t2_1, var_t2_2, var_t2_3) = t2;

    std::cout << "  Tuple t1 (unpacked with structured bindings) : (" << var_t1_1 << ", " << var_t1_2 << ", " << var_t1_3 << ")" << std::endl;
    std::cout << "  Tuple t2 (unpacked with std::tie) : (" << var_t2_1 << ", " << var_t2_2 << ", " << var_t2_3 << ")" << std::endl;

    // ### Skip an element with std::ignore
    std::cout << "4) Skip an element with std::ignore :" << std::endl;

    // auto [a, std::ignore, c] = t1; ### THIS DOES NOT WORK
    std::string a;
    char c;
    std::tie(a, std::ignore, c) = t2; 

    std::cout << "  Tuple t2 (unpacked with std::tie, ignoring 2nd element) : (" << a << ", " << "\"ignored element\"" << ", " << c << ")" << std::endl;

    // ### Concatenate tuples
    std::cout << "5) Concatenate tuples :" << std::endl;

    auto t3(std::tuple_cat(t1, t2));
    std::cout   << "  Tuple t3 (concatenation of t1 and t2) : (" << std::get<0>(t3) << ", " << std::get<1>(t3) << ", " << std::get<2>(t3) << ", "
                << std::get<3>(t3) << ", " << std::get<4>(t3) << ", " << std::get<5>(t3) << ")" << std::endl;

}