#include <exception>

namespace fiman
{
  class YamlBadName : public std::exception
  {
    virtual const char* what() const throw()
    {
      std::string msg;
      msg = "You have not specified a field *name* in your YAML file: ";
      return msg.c_str();
    }
  } yaml_bad_name;

  class YamlBadFiles : public std::exception
  {
    virtual const char* what() const throw()
    {
      std::string msg;
      msg = "The YAML syntax is not right. You have to specify a *files* field with a tree and flows file";
      return msg.c_str();
    }
  } yaml_bad_files;

  class FileNotLoaded : public std::exception
  {
    virtual const char* what() const throw()
    {
      std::string msg;
      msg = "A file is not loaded correctly.";
      return msg.c_str();
    }
  } file_not_loaded;
}
