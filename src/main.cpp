#include <iostream>
#include <fiman/fiman.h>

int main()
{
  fiman::Account account;
  account.load_tree("test");
  account.tree[12].print();
}
