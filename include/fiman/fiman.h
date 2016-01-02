#ifndef FIMAN_H
#define FIMAN_H

#include <iostream> // std::cout, std::cin
#include <vector> // std::vector
#include <ctime> // std::tm, std::time in fiman::Flow
#include <map> //std::map in fiman::Account

namespace fiman
{

  class Node
  {
    public:
      std::string name;
      int level;
      int number_of_children;
      float status;
      std::string local_id;
      std::string global_id;
      std::string global_name;
      fiman::Node *parent;
      std::vector<fiman::Node*> child;
      int tree_id;

      Node();
      Node(std::string name_, int level_);
      void set_local_id(std::string id);
      void set_parent(fiman::Node *par);
      void print(bool oneliner = false);
  };

  class Flow
  {
    private:
      std::string comment;
      bool inflow;
      std::tm *date;
      std::string h_date;
      std::string h_flow;
      std::string h_amount;

      int h_fields_no = 5;

    public:
      float amount;
      std::vector<std::string> h_fields;
      fiman::Node *node;
      Flow(fiman::Node *node, float amount_, std::string comment_);
      Flow();
      void print();
      void write_to_file(std::string file_);
      void decode_h_flow(std::string h_flow_);
      ~Flow();
  };

  class Tree
  {
    private:
      std::string file;
      int size;
      int max_level;
      bool is_loaded;

    public:
      std::vector<fiman::Node> nodes;
      std::map<std::string, int> id;

      Tree(std::string file_);
      void print(int level_ = 100);
      void update();

      /**
       * Loads a fiman::Tree from a file .tree.
       * The function reads the for each node of the tree: the name and the
       * level of the node. The level of the nodes is depicted by dots before
       * the name. So, the function creates a fiman::Node object for each node
       * based on name and level (calling the constructor of fiman::Node). Then
       * before the function pushes this fiman::Node into the tree, it sets the
       * fiman::Node::tree_id depending on the current index of the vector containing
       * the tree. Finally, it sets the for each node of the tree its parent.
       * As a last step set the the std::map fiman::Tree::id in order to map
       * the global id of each node with the index in the std::vector storing the tree.
       */
      void load();
  };

  class FlowList
  {
    private:
      std::string file;
      int size;
      bool is_loaded;

    public:
      std::vector<fiman::Flow> flows;
      FlowList(std::string file_);
      void load();
      void print(int last_ = 100);
  };

  class Account
  {
    public:
      std::string name;
      std::vector<fiman::Node> tree;
      std::map<std::string, int> id;
      std::vector<fiman::Flow> flow_list;

      bool file_is_loaded;

      void set_flow_node();
      bool load_tree(std::string file);
      void load_flows(std::string file);

      int recognise_dots(std::string &str);
      void print_tree(int level_);

      Account();
      ~Account();
  };

};
#endif // FIMAN_H
