#pragma once

#include <blkBlock.hpp>

namespace blk {
  expr over(expr op1, expr op2);

  class Over : public Block {
  private:
    
    expr op1;
    expr op2;

    static int compute_width     (expr op1, expr op2);
    static int compute_height    (expr op1, expr op2);
    static int compute_ref_width (expr op1, expr op2);
    static int compute_ref_height(expr op1, expr op2);
    
    Over(expr op1, expr op2);

  public:
    friend expr over(expr op1, expr op2);
    Over() = delete;
    Over(Over& block) = delete;
    virtual ~Over();

    Over& operator=(Over& block) = delete;
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
