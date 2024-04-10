#ifndef NODE
#define NODE

#include <string>

class Node {
  private:
    std::string value;
    Node* parentNode;
  public:
    Node(std::string value);
    Node(std::string value, Node* parent);
    ~Node();
    void setParent(Node* parent);
    std::string getValue();
    Node* getParent();
};

#endif
