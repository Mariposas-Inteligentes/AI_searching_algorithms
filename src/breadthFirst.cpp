#include "breadthFirst.hpp"

BreadthFirst::BreadthFirst() {
  this->pending.push(new Node("142350678"));
}

BreadthFirst::BreadthFirst(std::string initial) {
  this->pending.push(new Node(initial));
}

BreadthFirst::~BreadthFirst() {

}

void BreadthFirst::solve() {
  bool solved = false;
  // Root is already in the queue
  while (!this->pending.empty()){
    // Get next node and uptate it to the matrix
    Node* actualNode = this->pending.front();

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
          this->pending.push(new Node(newMatrix->toString(), actualNode));
        }
        delete newMatrix;
      }
    }
  }

  if (!solved) {
    std::cout << "The solution does not exist" << std::endl;
  }
}

void BreadthFirst::printAsMatrix(std::string text) {
  for (int i = 0; i < text.length(); ++i) {
    if (i % SIZE == 0) {
      std::cout << "\n";
    }

    if (text[i] != '0') {
      std::cout << text[i] << " ";
    } else {
      std::cout << "_ ";
    }
  }
}

void BreadthFirst::printSolution(Node * finalNode) {
  while (finalNode->getParent() != 0) {
    this->printAsMatrix(finalNode->getValue());
    std::cout << std::endl;
    finalNode = finalNode->getParent();
  }
  // when we exit this cycle, the final node is the root, and we still need to print it
  this->printAsMatrix(finalNode->getValue());
}
