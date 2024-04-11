#include "node.hpp"

Node::Node(std::string value) {
  this->value = value;
  this->parentNode = 0;
}

Node::Node(std::string value, std::shared_ptr<Node> parent) {
  this->value = value;
  this->parentNode = parent;
}

Node::~Node() {

}

void Node::setParent(std::shared_ptr<Node> parent) {
  this->parentNode = parent;
}

std::string Node::getValue() {
  return this->value;
}

std::shared_ptr<Node> Node::getParent() {
  return this->parentNode;
}

