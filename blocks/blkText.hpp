#pragma once

#include <string>
#include <blkBlock.hpp>

namespace blk {

  enum class align : char {left, center, right};
  
  expr text(const std::string& label, align alignment = align::center);

  class Text : public Block {
  private:

    std::string label;

    static int compute_ref_width(const std::string& label, align alignment);
    
    Text(const std::string& label, align alignment);

  public:
    friend expr text(const std::string& label, align alignment);
    Text() = delete;
    Text(Text& block) = delete;
    virtual ~Text();

    Text& operator=(Text& block) = delete;
    virtual void print_inbounds_line(std::ostream& os, int line) const override;
  };

}

