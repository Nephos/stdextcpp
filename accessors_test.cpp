#include "accessors.hpp"
#include <string>
#include <iostream>

class Guy
{
public:
  Guy() {}
  virtual ~Guy() {}

  reader_accessor(fname, std::string)
  writer_accessor(fname, std::string)
  std::string fname;
  create_attr(lname, std::string)
};

int main() {
  Guy me;
  me.set_fname("Arthur");
  me.set_lname("Poulet");
  std::cout << me.get_fname() << " - " << me.get_lname() << std::endl;
  return 0;
}
