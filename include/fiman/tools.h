#ifndef TOOLS_H
#define TOOLS_H
#include <vector> // std::vector
#include <string> // std::string
#include <iostream> // std::cout, std::endl;
#include <yaml-cpp/yaml.h>

const bool debug_enabled = false;
#define DEBUG(x) do { \
 if (debug_enabled) \
  {\
    std::cerr << __func__ << "() [" << __FILE__ << ", L:" << __LINE__ << "]> " << x << std::endl; \
  } \
} while(0)

namespace fiman
{
  class Config
  {
    public:
      std::string file;
      std::string name;
      std::string tree_file;
      std::string flow_file;

      Config(std::string file_);
      void load();
  };

  namespace tools
  {
    void find_empty(std::vector<std::string> &vec);
    int recognise_starting_dots(std::string &str);
    int number_of_digits(float num);
  }
}
#endif
