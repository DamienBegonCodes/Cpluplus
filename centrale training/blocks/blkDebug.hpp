#pragma once
#include <blkBlock.hpp>

namespace blk {
  // This is a factory that builds a debug block.
  expr debug(char label, int width, int height, int ref_width, int ref_height);

  class Debug : public Block {
  private:
    
    char label;
    Debug(char label, int width, int height, int ref_width, int ref_height);
    
  public:
    friend expr debug(char label, int width, int height, int ref_width, int ref_height);
    Debug() = delete;
    Debug(Debug& block) = delete;
    virtual ~Debug();

    Debug& operator=(Debug& block) = delete;

    // This one has to be implemented.
    virtual void print_inbounds_line(std::ostream& os, int line) const override;

  };
}
