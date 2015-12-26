#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

int main()
{
  int option;
  fiman::Account account;
  std::cout << "FiMan is initializing..." << std::endl;
  std::cout << "Loading tree from tree file...";
  account.load_tree("iason");
  std::cout << " Done." << std::endl;

  std::string flow_id;
  float flow_amount;
  std::string flow_comment;

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
        account.print_tree();
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
        break;
    }
  }
  fiman::Flow flow(&account.tree[0], 300.00, "gamiesai");
  flow.print();
}
