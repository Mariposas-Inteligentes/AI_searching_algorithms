// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef COMMON
#define COMMON

#include <sstream>
#include <string>

class Common {
  // Data for objective: 012345678
  // Each space in the array contains the distance for each number 
  // in each position.
  const std::string distance[9] = {"000000000"   // distance for 0
                                  ,"101212323"   // distance for 1
                                  ,"210321432"   // distance for 2
                                  ,"123012123"   // distance for 3
                                  ,"212101212"   // distance for 4
                                  ,"321210321"   // distance for 5
                                  ,"234123012"   // distance for 6
                                  ,"323212101"   // distance for 7
                                  ,"432321210"}; // distance for 8

  public:
    int heuristic(const std::string actual);
    std::string printAsMatrix(std::string text, int size);
};

#endif  // COMMON
