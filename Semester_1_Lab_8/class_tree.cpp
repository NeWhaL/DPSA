#include "class_tree.h"

void Tree::Print() const { Print(root); }

void Tree::Print(Node *node) const {
  if (not node)
    return;
  int count = 1;
  for (Node *current = node; current; current = current->brother, count++)
    std::cout << count << ") " << current->component_name << "   ";
  std::cout << std::endl;
  Print(node->son);
}

void Tree::PrintAmountComponents() const { PrintAmountComponents(root, 1); }

void Tree::PrintAmountComponents(Node *node, int level) const {
  if (not node)
    return;
  int count = 0;
  for (Node *current = node; current; current = current->brother, count++)
    ;
  std::cout << "Количество деталей типа " << node->component_name
            << " == " << count << std::endl;
  PrintAmountComponents(node->son, level + 1);
}

void Tree::AddElement(std::string component_name) {
  AddElement(root, component_name);
}

void Tree::AddElement(Node *&node, std::string component_name) {
  if (not node)
    node = new Node(component_name);
  else if (node->component_name == component_name)
    AddElement(node->brother, component_name);
  else
    AddElement(node->son, component_name);
}
