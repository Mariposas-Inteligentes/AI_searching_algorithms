// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids.hpp"
#include "breadthFirst.hpp"

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
  std::cout << "Solution printed from start to end: \n";
  Ids ids_algorithm(initial);
  ids_algorithm.solve();

  // Breadth-First Algorithm
  std::cout << "\n\nBreadth-First Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
  std::cout << "Solution printed from end to start: \n";
  BreadthFirst bf_algorithm(initial);
  bf_algorithm.solve();



  return 0;
}