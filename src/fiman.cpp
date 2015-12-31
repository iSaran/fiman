#include <fiman/fiman.h>
#include <fiman/tools.h>
#include <iomanip> // std::setprecision Flow::Flow()
#include <sstream> // std::ostringstream Flow::Flow()
#include <fstream> // std::ifstream, std::ofstream
#include <string> // std::string, std::stod

namespace fiman
{
  Node::Node()
  {
    this->name = "empty_node";
    this->level = -1;
    this->number_of_children = -1;
    this->status = 0;
  }

  Node::Node(std::string name_, int level_)
  {
    this->name = name_;
    this->level = level_;

    this->number_of_children = 0;
    this->status = 0;
    if (this->level == 0)
    {
      this->local_id = this->name.substr(0,1);
      this->global_id = this->local_id;
    }

    //this->number_of_children = child.size();
  }

  void Node::set_parent(fiman::Node *parent_)
  {

    if (this->level != 0)
    {
      this->parent = parent_;
      DEBUG("I will create a non-root node with name "+this->name);
      DEBUG("I push back this to parent's (" + this->parent->name + ")  children");
      DEBUG("My parent has address " << this->parent );
      parent->child.push_back(this);
      parent->number_of_children = parent->child.size();
      DEBUG("I set my level and now is " << level);

      this->global_name = this->parent->global_name + "/" + this->name;

      if (parent->number_of_children < 10)
      {
        local_id = "0" + std::to_string(parent->number_of_children);

        DEBUG("I set the local id to "+local_id);
      }
      else
      {
        local_id = std::to_string(parent->number_of_children);
        DEBUG("I set the local id to "+local_id);
      }
      global_id = parent->global_id + local_id;
      DEBUG("I set the global id to "+global_id);
      DEBUG("I set the number of children of my parent to " << parent->number_of_children);
    }
    else
    {
      DEBUG("I created a root node with name " + this->name);
      this->parent = NULL; // TODO: is this necessary?
    }
  }

  void Node::set_local_id(std::string id)
  {
    local_id = id;
    if (parent != NULL)
    {
      global_id = parent->global_id + local_id;
    }
  }

  void Node::print(bool oneliner)
  {
    if (oneliner)
      std::cout << this->global_id << "__________(" << this->status << ")" << this->name << std::endl;
    else
    {
    if (this->level != 0)
    {
      std::cout << "---- Node Details Print ----" << std::endl;
      std::cout << "Node #" << this->tree_id << std::endl;
      std::cout << "Node name: " << this->name << std::endl;
      std::cout << "Node local ID: " << this->local_id << std::endl;
      std::cout << "Node global ID: " << this->global_id << std::endl;
      std::cout << "Node level: " << this->level << std::endl;
      std::cout << "Node number of children: " << this->number_of_children << std::endl;
      std::cout << "Node's parent is Node #" << this->parent << ": " << this->parent->name << std::endl;
      for (int i = 0; i < this->number_of_children; i++)
      {
        std::cout << "Node's child is Node #" << this->child[i]->tree_id << ": " << this->child[i]->name << " [" << this->child[i]->global_id << "]"<< std::endl;
      }
      std::cout << "----------------------------" << std::endl;
    }
    else
    {
      std::cout << "---- Node Details Print ----" << std::endl;
      std::cout << "Node #" << this->tree_id << std::endl;
      std::cout << "Node name: " << this->name << std::endl;
      std::cout << "Node level: " << this->level << std::endl;
      std::cout << "Node number of children: " << this->number_of_children << std::endl;
      std::cout << "Node's parent is Node NULL" << std::endl;
      for (int i = 0; i < this->number_of_children; i++)
      {
        std::cout << "Node's child is Node #" << this->child[i]->tree_id << ": " << this->child[i]->name << " [" << this->child[i]->global_id << "]"<< std::endl;
      }
      std::cout << "----------------------------" << std::endl;
    }
  }
  }

  Account::Account()
  {
    file_is_loaded = false;
  }

  Account::~Account() {};

  int Account::recognise_dots(std::string &str)
  {
  }

  bool Account::load_tree(std::string file_)
  {
    std::vector<std::string> node_names;
    std::string path, temp;

    /**
     * Find the path of the file
     */
    path = "../resource/" + file_ + ".tree";
    std::ifstream file(path);

    /**
     * Read the file and put each line in node_names vector.
     * Then, close the file.
     */
    if (file.is_open())
    {
      while(file.good())
      {
        std::getline(file, temp);
        //std::cout << "Getting line" << temp << std::endl;
        node_names.push_back(temp);
      }
    }
    file.close();

    /* Clean up the vector from empty lines */
    fiman::tools::find_empty(node_names);

    int level;

    /**
     * Parse each element of the node_names vector
     * as an object fiman::Node
     */
    for (int i = 0; i < node_names.size(); i++)
    {
      level = fiman::tools::recognise_starting_dots(node_names[i]);
      fiman::Node temp_node(node_names[i], level);
      temp_node.tree_id = i;
      this->tree.push_back(temp_node);
    }

    /**
     * Find the level of each node based on starting dots
     * and remove the dots from the names
     */

    for (int i = 0; i < this->tree.size(); i++)
    {
      if ( this->tree[i].level != 0)
      {
        /**
         * The node's parent can be found if we search the list
         * of the nodes backwards. The first node whose level is
         * the node's level minus 1 is its parent
         */
        for (int j = i; j >= 0; j--)
        {
          if (this->tree[j].level == (this->tree[i].level - 1))
          {
            DEBUG("I set the parent of " << tree[i].name << " to be " << tree[j].name);
            this->tree[i].set_parent(&this->tree[j]);
            break;
          }
        }
        this->id[tree[i].global_id] = i;
      }
    }
  }

  void Account::print_tree(int level_)
  {
    for (int i = 0; i < this->tree.size(); i++)
    {
      if (tree[i].level <= level_)
      {
        this->tree[i].print(true);
      }
    }
  }

  void Account::load_flows(std::string file_)
  {
    std::cout << "Loading flows from file " << file_ << ".csv" << " file...";
    std::string path, temp_line;

    /**
     * Find the path of the file
     */
    path = "../resource/" + file_ + ".csv";
    std::ifstream file(path);

    if (file.is_open())
    {
      while(file.good())
      {
        fiman::Flow temp_flow;
        std::getline(file, temp_line);
        if (temp_line.empty())
          continue;
        temp_flow.decode_h_flow(temp_line);
        this->flow_list.push_back(temp_flow);
      }
    }
    file.close();
    std::cout << " Done." << std::endl;
  }

  void Account::set_flow_node()
  {
    for (int i = 0; i < this->flow_list.size(); i++)
    {
      this->flow_list[i].node = &this->tree[this->id[this->flow_list[i].h_fields[1]]];
      this->flow_list[i].node->status += this->flow_list[i].amount;
    }
  }

  Flow::Flow(fiman::Node *node_, float amount_, std::string comment_ = "")
  {
    node = node_;
    amount = amount_;
    comment = comment_;

    /* Get current time */
    time_t raw_current_time;
    std::time(&raw_current_time);
    date = localtime(&raw_current_time);

    /* Create [h]uman readable current date */
    h_date = std::to_string(date->tm_mday) + "/" + std::to_string(date->tm_mon + 1) + "/" +  std::to_string(date->tm_year + 1900);

    /* Create [h]uman readable amount (with 2 decimals) */
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << this->amount;
    this->h_amount = stream.str();

    /* Create [h]uman readable flow for writing in csv file */
    h_flow = "";
    h_fields = {
      this->h_date,
      this->node->global_id,
      this->node->name,
      this->h_amount,
      this->comment
    };
    this->h_fields_no = this->h_fields.size();

    for (int i = 0; i < this->h_fields_no; i++)
      h_flow += h_fields[i] + ",";
    h_flow = h_flow.substr(0, h_flow.size() - 1);
    std::cout << h_flow << std::endl;
    //h_flow = this->h_date + "," + this->node->global_id + "," + this->node->name + "," + h_amount + "," + this->comment;
  }

  Flow::Flow()
  {
  }

  void Flow::decode_h_flow(std::string h_flow_)
  {
    int start = 0, end = 0;

    for (int i = 0; i < this->h_fields_no; i++)
    {
      end = h_flow_.find_first_of(',');
      this->h_fields.push_back(h_flow_.substr(start, end));
      h_flow_.erase(start, end+1);
    }

    this->h_date = this->h_fields[0];
    this->h_amount = this->h_fields[3];
    this->comment = this->h_fields[4];

    this->amount = std::stod(this->h_amount);
  }

  void Flow::print()
  {
    std::cout << "*---- Flow Details Print ----*" << std::endl;
    std::cout << "* Flow h_date: " << this->h_date << std::endl;
    std::cout << "* Flow node's global ID: " << this->node->global_id << std::endl;
    std::cout << "* Flow node's name: " << this->node->name << std::endl;
    std::cout << "* Flow amount: " << this->h_amount << std::endl;
    std::cout << "* Flow comment: " << this->comment << std::endl;
    std::cout << "*----------------------------*" << std::endl;
  }

  void Flow::write_to_file(std::string file_)
  {
    std::string path = "../resource/" + file_ + ".csv";
    std::ofstream file(path, std::ios::app);

    std::cout << "Written flow to file " << file_ << ".csv" << " file..." << std::endl;

    if (file.is_open())
    {
      file << this->h_flow << std::endl;
    }
    file.close();
  }

  Flow::~Flow() {}
};
