#include <fiman/tools.h>

namespace fiman
{
  namespace tools
  {
    void find_empty(std::vector<std::string> &vec)
    {
      /**
       * Check every line of tree file
       */
      for (int i = 0; i < vec.size(); i++)
      {
        /**
         * Check if the current line has no characters
         * and erase these empty lines
         */
        if (vec[i].find_first_not_of(' ') == std::string::npos)
        {
          vec.erase(vec.begin() + i);
          i--;
        }
      }
    }

    int recognise_starting_dots(std::string &str)
    {
      int dot_counter = 0;

      /**
       * Find how many dots there are at the beginning
       * of the string, by finding the position of the
       * first character that it is not a dot
       */
      dot_counter = str.find_first_not_of('.');

      /* Erase all the dots from the string */
      str.erase(0, dot_counter);

      return dot_counter;
    }
  }
}
