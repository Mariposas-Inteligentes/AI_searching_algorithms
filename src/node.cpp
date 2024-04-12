// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "node.hpp"

Node::Node(std::string value) {
  this->value = value;
  this->parentNode = 0;
  this->cost = 0;
}

Node::Node(std::string value, std::shared_ptr<Node> parent) {
  this->value = value;
  this->parentNode = parent;
  this->cost = 0;
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

int Node::getCost() {
  return this->cost;
}

void Node::setCost(int cost) {
  this->cost = cost;
}

// TODO(Luis): Delete
void Node::print() {
  std::cout << "Cost: " << this->cost <<"\n";
}