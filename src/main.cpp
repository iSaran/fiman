#include <iostream>
#include <fiman/fiman.h>
#include <fiman/tools.h>

int main()
{
  fiman::Account account;
  fiman::Tree tree("iason111");
  fiman::FlowList flow_list("flows");
  tree.print();

  //fiman::Flow input_flow(&account.tree[4], 912.31, "iasonas");
  //input_flow.write_to_file("flows");
  //account.load_flows("flows");
  //account.set_flow_node();
  //for (int i = 0; i < account.flow_list.size(); i++)
  //{
  //  account.flow_list[i].print();
  //}
  
}
