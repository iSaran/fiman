#include <iostream>
#include <fiman/fiman.h>

int main()
{
 // fiman::FinanceManager f;
 // f.set_owner();
 // f.get_owner();

  //fiman::Node *root;
  //root = new fiman::Node("R");
  //fiman::Node iason(NULL);
  //iason.set_local_id("I");

  fiman::Account account;

  //account.load_data("../resource/iason.yaml", "iason");
  account.load_tree("iason");


  account.tree[12].print();
//    YAML::Node primes = YAML::LoadFile("../resource/iason.yaml");
//    std::cout << primes.size() << "\n";
// 
//    YAML::Node primes1 = primes[0]; 
//    std::cout << primes1.size() << "\n";
// 
   
  // for (int i = 0; i < primes.size(); i++)
  //   std::cout << primes[i] << std::endl;


  // fiman::Node asset(&iason); asset.set_local_id("A");
  // fiman::Node liability(&iason); liability.set_local_id("L");

  // fiman::Node periodic_a(&asset); periodic_a.set_local_id("P");
  // fiman::Node aperiodic_a(&asset); aperiodic_a.set_local_id("A");

  // fiman::Node periodic_l(&liability); periodic_l.set_local_id("P");
  // fiman::Node aperiodic_l(&liability); aperiodic_l.set_local_id("A");

  // fiman::Node misthos(&periodic_a);
  // fiman::Node certh_iti(&misthos);

  // fiman::Node daneia_tritwn(&aperiodic_a);
  // fiman::Node apotamieusi(&aperiodic_a);


  // fiman::Node miniaia_eksoda(&periodic_l);
  // fiman::Node enoikio(&periodic_l);
  // fiman::Node logariasmoi(&periodic_l);
  // fiman::Node asfaleia(&periodic_l);
  // fiman::Node syndromes(&periodic_l);

  // fiman::Node tilefwno(&logariasmoi);
  // fiman::Node ilektriko(&logariasmoi);
  // fiman::Node nero(&logariasmoi);
  // fiman::Node koinoxrista(&logariasmoi);
  // fiman::Node thermansi(&logariasmoi);

  // fiman::Node asfalistikes_syndromes(&asfaleia);
  // fiman::Node idiwtiki_asfaleia(&asfaleia);

  // fiman::Node ieee(&syndromes);
  // fiman::Node dropbox(&syndromes);
  // fiman::Node gym(&syndromes);
  // fiman::Node germanika(&syndromes);
  // fiman::Node google_apps(&syndromes);

  // fiman::Node eforia(&aperiodic_l);
  // fiman::Node epaggelmaties(&aperiodic_l);
  // fiman::Node anoiktes_ekkremotites(&aperiodic_l);
  // fiman::Node diaskedasi(&aperiodic_l);
  // fiman::Node xrei_pros_tritous(&aperiodic_l);
  // fiman::Node metafores(&aperiodic_l);

  // fiman::Node iatrika_eksoda(&epaggelmaties);
  // fiman::Node dikigoroi(&epaggelmaties);
  // fiman::Node logistis(&epaggelmaties);

  // fiman::Node epipleon_gia_to_mina(&anoiktes_ekkremotites);
  // fiman::Node analipseis_anagkis(&anoiktes_ekkremotites);
  // fiman::Node epaggelmatika_eksoda(&anoiktes_ekkremotites);

  // fiman::Node kalokairines_diakopes(&diaskedasi);
  // fiman::Node dwra_pros_tritous(&diaskedasi);
  // fiman::Node agores_pswnia(&diaskedasi);

  // fiman::Node mama_apotamieusi(&xrei_pros_tritous);
  // fiman::Node zwi(&xrei_pros_tritous);

  //std::cout << agores_pswnia.global_id;

  //std::cout << root.number_of_children;
}
