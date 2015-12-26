#ifndef FIMAN_H
#define FIMAN_H

#include <iostream>
#include <vector>

#include "yaml-cpp/yaml.h"

namespace fiman
{

  class Owner
  {
   public:
      std::string name;
      std::string last_name;
      Owner();
      ~Owner();
  };

  class Node
  {
    private:
      float status;

    public:
      std::string local_id;
      std::string global_id;
      std::string name;
      fiman::Node *parent;
      std::vector<fiman::Node*> child;
      int number_of_children;
      int level;
      int tree_id;

      Node(std::string name_, int level_);
      void set_local_id(std::string id);
      void set_parent(fiman::Node *par);
      void print();
  };

  class Account
  {
    public:
      std::string name;
      std::vector<fiman::Node> tree;
      bool file_is_loaded;

      bool load_data(std::string file, std::string name);
      bool load_tree(std::string file);
      int recognise_dots(std::string &str);

      Account();
      ~Account();
  };

  class FinanceManager
  {
    public:
      FinanceManager();
      ~FinanceManager();
      fiman::Owner owner;
      int set_owner();
      int get_owner();

      void create_tree();
  };

};
#endif // FIMAN_H
