#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>
#include <sstream> //std::istringstream

const std::string tree_file = "iason111";
const std::string flow_file = "flows";

int main()
{
  std::cout << "FiMan is initializing..." << std::endl;

  fiman::Tree tree("iason111");
  fiman::FlowList flow_list("flows");
  flow_list.connect_with_node(&tree);
  tree.update();

  //tree.print("neg");
  //tree.print("32");

  std::string flow_id;
  float flow_amount;
  std::string flow_comment;

  int level_;

  std::string line;
  std::cout << "fiman >> ";
  while(std::getline(std::cin, line))
  {
    std::istringstream command(line);
    std::string cmd;
    command >> cmd;
    if (cmd == "help" || cmd == "?")
    {
      std::cout << std::endl;
      std::cout << "Commands:" << std::endl;
      std::cout << "help - display this help" << std::endl;
      std::cout << "print tree" << std::endl;
      std::cout << std::endl;
    }
    else if (cmd == "exit" || cmd == "q" || cmd == "quit" || cmd == "x")
    {
      break;
    }
    else if (cmd == "print")
    {
      command >> cmd;
      if (cmd == "tree")
      {
        command >> cmd;
        tree.print();
      }
      else
      {
        std::cout << std::endl;
        std::cout << "You have to specify what you want to print:" << std::endl;
        std::cout << "- tree: Print the tree" << std::endl;
        std::cout << "- flows: Print the last [N] flows" << std::endl;
        std::cout << std::endl;
      }
    }
    else if (cmd == "")
    {
    }
    else
    {
      std::cout << cmd << ": command not found. Try \'help\' or \'?\'." << std::endl;
    }
    std::cout << "fiman >> ";
  }

}
