#ifndef NODE
#define NODE

#include <string>
#include <memory>

class Node {
  private:
    std::string value;
    std::shared_ptr<Node> parentNode;
  public:
    Node(std::string value);
    Node(std::string value, std::shared_ptr<Node> parent);
    ~Node();
    void setParent(std::shared_ptr<Node> parent);
    std::string getValue();
    std::shared_ptr<Node> getParent();
};

#endif
