#ifndef TOOLS_H
#define TOOLS_H
#include <vector> // std::vector
#include <string> // std::string
#include <iostream> // std::cout, std::endl;

const bool debug_enabled = true;
#define DEBUG(x) do { \
 if (debug_enabled) \
  {\
    std::cerr << __func__ << "() [" << __FILE__ << ", L:" << __LINE__ << "]> " << x << std::endl; \
  } \
} while(0)

namespace fiman
{
  namespace tools
  {
    void find_empty(std::vector<std::string> &vec);
    int recognise_starting_dots(std::string &str);
  }
}
#endif
