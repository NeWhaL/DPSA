#include <iostream>

class Tree {
  struct Node {
    std::string component_name;
    Node *son;
    Node *brother;

    Node(std::string component_name)
        : component_name(component_name), son(nullptr), brother(nullptr) {}
  };

  Node *root;

  void AddElement(Node *&node, std::string component_name);
  void PrintAmountComponents(Node *node, int level) const;
  void Print(Node *node) const;

public:
  Tree() : root(nullptr) {}
  void PrintAmountComponents() const;
  void Print() const;
  void AddElement(std::string component_name);
};
