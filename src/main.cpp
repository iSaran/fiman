#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

int main()
{
  fiman::Account account;
  DEBUG("FDSFDS");
  account.load_tree("test");
  account.tree[12].print();
}
