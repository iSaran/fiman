#ifndef FIMAN_H
#define FIMAN_H

#include <iostream>
#include <vector>
#include <ctime> // tm, time in fiman::Flow
#include <map> //std::map in fiman::Account

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
      std::string global_name;
      fiman::Node *parent;
      std::vector<fiman::Node*> child;
      int number_of_children;
      int level;
      int tree_id;

      Node();
      Node(std::string name_, int level_);
      void set_local_id(std::string id);
      void set_parent(fiman::Node *par);
      void print();
      void print_oneliner();
  };

  class Flow
  {
    private:
      std::string comment;
      float amount;
      bool inflow;
      std::tm *date;
      std::string h_date;
      std::string h_flow;
      std::string h_amount;

      int h_fields_no = 5;

    public:
      std::vector<std::string> h_fields;
      fiman::Node *node;
      Flow(fiman::Node *node, float amount_, std::string comment_);
      Flow();
      void print();
      void write_to_file(std::string file_);
      void decode_h_flow(std::string h_flow_);
      ~Flow();
  };

  class Account
  {
    public:
      std::string name;
      std::vector<fiman::Node> tree;
      //std::vector<fiman::Flow> flows;
      std::map<std::string, int> id;
      std::vector<fiman::Flow> flow_list;

      bool file_is_loaded;

      void set_flow_node();
      bool load_data(std::string file, std::string name);
      bool load_tree(std::string file);
      void load_flows(std::string file);

      int recognise_dots(std::string &str);
      void print_tree(int level_);

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
