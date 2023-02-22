#pragma once

#include <blkBlock.hpp>

namespace blk {
  expr beside(expr op1, expr op2);

  class Beside : public Block {
  private:
    
    expr op1;
    expr op2;

    // These functions make auxiliary size and ref computation for the
    // resulting block, from the two operands. Use them as arguments
    // to the conctruction of super class Block in the Beside
    // constructor.
    static int compute_width     (expr op1, expr op2);
    static int compute_height    (expr op1, expr op2);
    static int compute_ref_width (expr op1, expr op2);
    static int compute_ref_height(expr op1, expr op2);
    
    Beside(expr op1, expr op2);

  public:
    friend expr beside(expr op1, expr op2);
    Beside() = delete;
    Beside(Beside& block) = delete;
    virtual ~Beside();

    Beside& operator=(Beside& block) = delete;
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
