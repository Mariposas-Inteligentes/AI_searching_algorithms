#ifndef NODE
#define NODE

#include <string>
#include <memory>

#include <iostream>

class Node {
  private:
    std::string value;
    std::shared_ptr<Node> parentNode;
    int cost;
  
  public:
    Node(std::string value);
    Node(std::string value, std::shared_ptr<Node> parent);
    ~Node();
    void setParent(std::shared_ptr<Node> parent);
    void setCost(int cost);
    std::shared_ptr<Node> getParent();
    int getCost();
    std::string getValue();

    // TODO(Luis): Delete
    void print();
};

struct CompareNodes {
  bool operator()(const std::shared_ptr<Node> lf, const std::shared_ptr<Node> rg) const {
    return lf->getCost() > rg->getCost();
  }
};

#endif
