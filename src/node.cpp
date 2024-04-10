#include "node.hpp"

Node::Node(std::string value) {
  this->value = value;
  this->parentNode = 0;
}

Node::Node(std::string value, Node* parent) {
  this->value = value;
  this->parentNode = parent;
}

Node::~Node() {
  if (this->parentNode != 0) {
    delete parentNode;
  }
}

void Node::setParent(Node* parent) {
  this->parentNode = parent;
}

std::string Node::getValue() {
  return this->value;
}

Node* Node::getParent() {
  return this->parentNode;
}

