// Authors: Luis Solano, Angie Solís, Emilia Víquez
#include "ids.hpp"

#include <iostream>

int main(int argc, char **argv)
{
  std::string initial = "724506831";
  if (argc == 2)
  {
    initial = argv[1];
  }
  // IDS Algorithm
  std::cout << "IDS Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
  Ids ids_algorithm(initial);
  ids_algorithm.solve();

  return 0;
}