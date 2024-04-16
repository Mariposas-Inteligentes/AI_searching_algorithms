// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "greedyBreadthFirst.hpp"

GreedyBreadthFirst::GreedyBreadthFirst() {
  this->init("142350678");
  this->measure = false;
}

GreedyBreadthFirst::GreedyBreadthFirst(std::string initialState, bool measure) {
  this->init(initialState);
  this->measure = measure;
}

void GreedyBreadthFirst::init(std::string initialState) {
  int cost = this->common.heuristic(initialState);
  std::shared_ptr<Node> initialNode(new Node(initialState));
  initialNode->setCost(cost);
  this->openList.push(initialNode);
  this->bytes = 0;
}

GreedyBreadthFirst::~GreedyBreadthFirst() {
}

void GreedyBreadthFirst::solve() {
  if (measure) {
    this->start = std::chrono::high_resolution_clock::now();
  }
  bool solved = false;
  while (!this->openList.empty()) {
    std::shared_ptr<Node> actualNode = this->openList.top();
    actualMatrix.fillMatrix(actualNode->getValue());
    this->openList.pop();

    if (this->actualMatrix.verifySolution()) {
      solved = true;

      if (measure) {
        // if we wanted to measure time, then we need to stop it here.
        this->end = std::chrono::high_resolution_clock::now();
      }
      this->printSolution(actualNode);
      this->openList.push(actualNode);
      break;
    }

    this->closedList.insert(actualNode->getValue());
    this->findMovements(actualNode);
  }

  if (!solved) {
    std::cout << "The solution does not exist" << std::endl;
    if (measure) {
        // if we wanted to measure time, then we need to stop it here.
        this->end = std::chrono::high_resolution_clock::now();
        this->printStats();
      }
  }
}

void GreedyBreadthFirst::findMovements(std::shared_ptr<Node>& actualNode) {
  for (int dir = 0; dir < DIRECTIONS; ++dir) {
    if(this->actualMatrix.possibleMove(dir)) {
      std::shared_ptr<Matrix> newMatrix = actualMatrix.movePiece(dir);
      // If new matrix was not previously checked, then add it to the queue
      if (this->closedList.find(newMatrix->toString()) == this->closedList.end()) {
        std::shared_ptr<Node> nextNode (new Node(newMatrix->toString(), actualNode));
        int cost = this->common.heuristic(nextNode->getValue());
        nextNode->setCost(cost);
        this->openList.push(nextNode);
      }
    }
  } 
}

void GreedyBreadthFirst::printSolution(std::shared_ptr<Node> finalNode) {
  while (finalNode->getParent() != 0) {
    std::cout << this->common.printAsMatrix(finalNode->getValue(), SIZE) << std::endl;
    std::cout << std::endl;
    finalNode = finalNode->getParent();
  }
  // when we exit this cycle, the final node is the root, and we still need to print it
  std::cout << this->common.printAsMatrix(finalNode->getValue(), SIZE) << std::endl;

  if (measure) {
    this->printStats();
  }
}

void GreedyBreadthFirst::printStats() {
  std::chrono::duration<double> diff = end - start;
  this->bytes = sizeof(std::shared_ptr<Node>) * this->openList.size();
  this->bytes += sizeof(std::string) * this->closedList.size();
  std::cout << "Time taken in greedy breadth-first: " << diff.count()
            <<  "   memory used:  " << this->bytes << std::endl;
}
