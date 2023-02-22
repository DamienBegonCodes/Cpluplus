#pragma once

namespace blk {
  expr move_ref(expr op, int ref_width, int ref_height);

  class MoveRef : public Block {
  private:
    
    expr op;
    
    MoveRef(expr op, int ref_width, int ref_height);

  public:
    friend expr move_ref(expr op, int ref_width, int ref_height);
    MoveRef() = delete;
    MoveRef(MoveRef& block) = delete;
    virtual ~MoveRef();

    MoveRef& operator=(MoveRef& block) = delete;
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };
}
