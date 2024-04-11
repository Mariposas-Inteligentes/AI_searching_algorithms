// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "breadthFirst.hpp"
#include "ids.hpp"
#include "ids_h.hpp"

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

  // IDS* Algorithm
  std::cout << "\n\nIDS* Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
  std::cout << "Solution printed from start to end: \n";
  Ids_H idsh_algorithm(initial);
  idsh_algorithm.solve();

  return 0;
}