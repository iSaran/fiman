#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

const std::string tree_file = "iason111";
const std::string flow_file = "flows";

int main()
{
  int option;
  std::cout << "FiMan is initializing..." << std::endl;
  std::cout << "Loading tree from " << tree_file << ".tree" << " file...";
  std::cout << " Done." << std::endl;

  std::cout << "Loading flows from " << flow_file << ".csv" << " file...";

  std::string flow_id;
  float flow_amount;
  std::string flow_comment;

  int level_;

  //std::string line;
  //while(std::getline(cin, line))
  //{
  //  std::istringstream command(line);
  //  std::string cmd;
  //  command >> cmd;
  //  if (cmd == "help" || cmd == "?")
  //  {
  //    std::cout << "Commands:" << std::endl;
  //              << "help - display this help" << std::endl;
  //              << "print tree" << std::endl;
  //  }
  //  else if (cmd == "print tree")
  //  {
  //  }

  //}

}
