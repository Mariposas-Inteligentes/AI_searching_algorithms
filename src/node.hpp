#ifndef NODE
#define NODE

#include <string>
#include <memory>

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
};

#endif
