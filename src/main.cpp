#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

int main()
{
  fiman::Account account;
  DEBUG("FDSFDS");
  account.load_tree("test");
  std::cout << "Number of nodes: " << account.tree.size() << std::endl;
  for (int i = 0; i < account.tree.size(); i++)
    account.tree[i].print();
}
