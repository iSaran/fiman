#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>
#include <sstream> //std::istringstream

const std::string tree_file = "iason111";
const std::string flow_file = "flows";

int main()
{
  std::cout << "FiMan is initializing..." << std::endl;

  fiman::Tree *tree;
  fiman::FlowList *flow_list;

  try
  {
    tree = new fiman::Tree("iason111");
    flow_list = new fiman::FlowList("flows");

    static fiman::Config config("config");
    flow_list->connect_with_node(tree);
    tree->update();
  }
  catch (std::exception& e)
  {
    std::cout << "\nErrors during initialization " << std::endl;
    std::cout << "!!! Error: " << e.what() << std::endl;
    return 0;
  }


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
      std::cout << "help,?:                        display this help" << std::endl;
      std::cout << "print:                         print data in screen " << std::endl;
      std::cout << "  - tree:                      print the tree" << std::endl;
      std::cout << "  - flow,flows,flowlist" << std::endl;
      std::cout << "     - last [N]:               print the last N flows" << std::endl;
      std::cout << "     - id [X]:                 print every flow with ID X" << std::endl;
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
        tree->print();
      }
      else if (cmd == "flow" || cmd == "flows" || cmd == "flowlist")
      {
        std::string temp_cmd;

        command >> cmd;
        temp_cmd = cmd;
        command >> cmd;

        if (!cmd.empty())
        {
          flow_list->print(temp_cmd, cmd);
        }
        else
        {
          std::cout << "print flowlist " << temp_cmd << ": You have to specify an argument." << std::endl;
        }
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
