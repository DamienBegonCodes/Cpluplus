#pragma once

#include <iostream>
#include <memory>


namespace blk {

  class Block;
  using expr = std::shared_ptr<const Block>;

  std::ostream& operator<<(std::ostream& os, expr e);
  
  class Block {
  private:
    
    int width;
    int height;
    int ref_width;
    int ref_height;

    // Returns the lowest line number which is in the block.
    int min_line() const;

    // Returns 1 + the highest line number which is in the block.
    int max_line() const;

  protected:
    void print_line(std::ostream& os, int line) const;
    virtual void print_inbounds_line(std::ostream& os, int line) const = 0;
    static void call_print(const expr& block, std::ostream& os, int line) {block->print_line(os, line);}
    
  private:

    // This will call the private min_line and max_line methods, this
    // is why it has to be a friend of the class.
    friend std::ostream& operator<<(std::ostream& os, expr block);
  
  protected:
    Block(int width, 
	  int height,
	  int ref_width,
	  int ref_height);

  public:
    Block() = delete;
    Block(Block& block) = delete; 
    virtual ~Block();

    Block& operator=(Block& block) = delete;


    int get_width()      const;
    int get_height()     const;
    int get_ref_width()  const;
    int get_ref_height() const;
  };
}
