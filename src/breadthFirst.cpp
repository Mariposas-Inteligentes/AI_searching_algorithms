#include "breadthFirst.hpp"
#include "common.hpp"

BreadthFirst::BreadthFirst() {
  std::shared_ptr<Node> initialNode (new Node("142350678"));
  this->pending.push(initialNode);
}

BreadthFirst::BreadthFirst(std::string initial) {
  std::shared_ptr<Node> initialNode (new Node(initial));
  this->pending.push(initialNode);
}

BreadthFirst::~BreadthFirst() {

}

void BreadthFirst::solve() {
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
        Matrix *newMatrix = actualMatrix.movePiece(dir);
        // If new matrix was not previously checked, then add it to the queue
        if (this->visited.find(newMatrix->toString()) == this->visited.end()) {
          std::shared_ptr<Node> nextNode (new Node(newMatrix->toString(), actualNode));
          this->pending.push(nextNode);
        }
        delete newMatrix;
      }
    }
  }

  if (!solved) {
    std::cout << "The solution does not exist" << std::endl;
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
}
