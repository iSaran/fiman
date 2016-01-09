#include <fiman/tools.h>
#include <fiman/exceptions.h>

namespace fiman
{
  Config::Config()
  {
    /* The config file is hardcoded as config.yml in resource dir */
    std::string file_ = "config";

    std::cout << "Loading configuration from " << file_ << ".yml" << " file...";

    /* Set the name of the file associated with the tree */
    this->file = file_;

    /* Load the tree from tree file */
    try
    {
      this->load();
    }
    catch (std::exception& e)
    {
      std::cout << "\nCouldn't load " << this->file << " correctly..." << std::endl;
      std::cout << "!!! Error: " << e.what() << std::endl;
      throw file_not_loaded;
      return;
    }
    std::cout << " Done." << std::endl;
  }

  void Config::load()
  {
    /* The path of the config file is fixed */
    std::string path = "../resource/" + this->file + ".yml";

    /* Load the YAML file as a YAML node */
    YAML::Node config = YAML::LoadFile(path);

    if (!config["name"])
      throw yaml_bad_name;
    if (!config["tree_file"] || !config["flow_file"])
      throw yaml_bad_files;

    this->name = config["name"].as<std::string>();
    this->tree_file = config["tree_file"].as<std::string>();
    this->flow_file = config["flow_file"].as<std::string>();

  }

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

    int number_of_digits(float num)
    {
      int digits = 0;
      bool negative = false;
      if (num < 0)
      {
        num = -num;
        negative = true;
      }
      if (num < 10)
      {
        digits = 1;
        return digits;
      }
      while(num > 1)
      {
        num /= 10;
        digits++;
      }
      if (negative)
        digits++;
      return digits;
    }

  }
}
