#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

const std::string tree_file = "iason111";
const std::string flow_file = "flows";

int main()
{
  int option;
  fiman::Account account;
  std::cout << "FiMan is initializing..." << std::endl;
  std::cout << "Loading tree from " << tree_file << ".tree" << " file...";
  account.load_tree(tree_file);
  std::cout << " Done." << std::endl;

  std::cout << "Loading flows from " << flow_file << ".csv" << " file...";
  account.load_flows("flows");
  account.set_flow_node();
  for (int i = 0; i < account.flow_list.size(); i++)
  {
    account.flow_list[i].print();
  }

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

  while(true)
  {
    std::cout << "===== Menu =====" << std::endl;
    std::cout << "1. Print tree." << std::endl;
    std::cout << "2. Add new flow." << std::endl;
    std::cout << "================" << std::endl;

    std::cout << "fiman command > ";
    std::cin >> option;

    switch (option)
    {
      case 1:
        std::cout << "Insert the level of printing > ";
        std::cin >> level_;
        account.print_tree(level_);
        break;
      case 2:
        std::cout << "Insert flow id > ";
        std::cin >> flow_id;
        std::cout << "Insert flow amount > ";
        std::cin >> flow_amount;
        std::cout << "Insert flow comment > ";
        std::cin >> flow_comment;
        fiman::Flow new_flow(&account.tree[account.id[flow_id]], flow_amount, flow_comment);
        new_flow.print();
        new_flow.write_to_file(flow_file);
        account.load_flows("flows");
        account.set_flow_node();
        break;
    }
  }
  fiman::Flow flow(&account.tree[0], 300.00, "gamiesai");
  flow.print();
}
