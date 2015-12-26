#include <fiman/fiman.h>
#include <fiman/tools.h>

#include <fstream>

namespace fiman
{
  FinanceManager::FinanceManager() {}
  FinanceManager::~FinanceManager() {}
  int FinanceManager::set_owner()
  {
    fiman::Owner a;
    std::string name, last_name;
    std::cout << "Type the owner's name: ";
    std::cin >> name;
    std::cout << "Type the owner's lastname: ";
    std::cin >> last_name;
    a.name = name;
    a.last_name = last_name;
    this->owner = a;
    return 0;
  }
  int FinanceManager::get_owner()
  {
    std::cout << "This manager belongs to " << this->owner.name << " " << this->owner.last_name << std::endl;
    return 0;
  }
  void FinanceManager::create_tree()
  {
  }
  Owner::Owner() {}
  Owner::~Owner() {}
  Node::Node(std::string name_, int level_) 
  {
    this->name = name_;
    this->level = level_;

    this->number_of_children = 0;

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
      DEBUG("I set my level and now is " << level);

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
      parent->number_of_children = parent->child.size();
      DEBUG("I set the number of children of my parent to " << parent->number_of_children);
    }
    else
    {
      DEBUG("I created a root node with name " + this->name);
      this->parent = NULL;
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
  void Node::print()
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
  Account::Account()
  {
    file_is_loaded = false;
  }
  Account::~Account() {};
  bool Account::load_data(std::string file, std::string name)
  {
    if (file_is_loaded)
    {
      return false;
    }

    YAML::Node ynode = YAML::LoadFile(file);
    if (ynode.IsNull())
    {
      std::cout << "YAML file " << file << " not found." << std::endl;
      return false;
    }

    //if (ynode["iason"])
     // std::cout << "yo" << std::endl;

    std::cout << ynode.size() << std::endl;
   // for (std::size_t i=0;i<primes.size();i++) {
   //   std::cout << primes[i].as<int>() << "\n";
   // }

     //YAML::Node spriteNode = ynode[1];
    // if (spriteNode.IsNull())
    // {
    //   std::cout << "Sprite node " << name << " not found." << std::endl;
    //   return false;
    // }

    //std::string m_psSpritesheetPath = spriteNode["fds"].as<std::string>();
  }
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
      }
    }
  }
};
