// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "breadthFirst.hpp"
#include "common.hpp"

BreadthFirst::BreadthFirst() {
  std::shared_ptr<Node> initialNode (new Node("012345678"));
  this->pending.push(initialNode);
  this->measure = false;
  this->size = 0;
}

BreadthFirst::BreadthFirst(std::string initial, bool measure) {
  std::shared_ptr<Node> initialNode (new Node(initial));
  this->pending.push(initialNode);
  this->measure = measure;
  this->size = 0;
}

BreadthFirst::~BreadthFirst() {

}

void BreadthFirst::solve() {
  if (measure) {
    this->start = std::chrono::high_resolution_clock::now();
  }
  bool solved = false;
  // Root is already in the queue
  while (!this->pending.empty()){
    // Get next node and uptate it to the matrix
    std::shared_ptr<Node> actualNode = this->pending.front();

    actualMatrix.fillMatrix(actualNode->getValue());
    this->pending.pop();
    
    // If it is the correct node, break the cicle
    if (this->actualMatrix.verifySolution()) {
      solved = true;
      if (measure) {
        // if we wanted to measure time, then we need to stop it here.
        this->end = std::chrono::high_resolution_clock::now();
        this->size = sizeof(std::shared_ptr<Node>) * this->pending.size();
        this->size += sizeof(std::string) * this->visited.size();
      }
      this->printSolution(actualNode);
      // We need the queue destructor to eliminate 
      this->pending.push(actualNode);
      break;
    }

    // Mark actualNode as checked
    this->visited.insert(actualNode->getValue());

    // Look for the next nodes
    for (int dir = 0; dir < DIRECTIONS; ++dir) {
      if (this->actualMatrix.possibleMove(dir)) {
        std::shared_ptr<Matrix> newMatrix = actualMatrix.movePiece(dir);
        // If new matrix was not previously checked, then add it to the queue
        if (this->visited.find(newMatrix->toString()) == this->visited.end()) {
          std::shared_ptr<Node> nextNode (new Node(newMatrix->toString(), actualNode));
          this->pending.push(nextNode);
        }
      }
    }
  }

  if (!solved) {
    std::cout << "The solution does not exist" << std::endl;
    if (measure) {
        // if we wanted to measure time, then we need to stop it here.
        this->end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        this->size = sizeof(std::shared_ptr<Node>) * this->pending.size();
        this->size += sizeof(std::string) * this->visited.size();
        std::cout << "Time taken in breadth-first: " << diff.count() 
                  <<  "   memory used:  " << this->size << "\n";
      }
  }
}

void BreadthFirst::printSolution(std::shared_ptr<Node> finalNode) {
  Common printer;
  while (finalNode->getParent() != 0) {
    std::cout << printer.printAsMatrix(finalNode->getValue(), SIZE) << std::endl;
    std::cout << std::endl;
    finalNode = finalNode->getParent();
  }
  // when we exit this cycle, the final node is the root, and we still need to print it
  std::cout << printer.printAsMatrix(finalNode->getValue(), SIZE) << std::endl;
  if (measure) {
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken in breadth-first: " << diff.count()
         <<  "   memory used:  " << this->size << "\n";
  }
}
