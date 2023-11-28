#include "class_tree.h"
// #include <iostream>

using namespace std;

int main() {

  Tree tree;

  tree.AddElement("Капот");
  for (int i = 0; i < 4; ++i) {
    tree.AddElement("Колесо");
  }
  for (int i = 0; i < 4; ++i) {
    tree.AddElement("Дверь");
  }
  tree.AddElement("Руль");
  tree.AddElement("Мотор");
  for (int i = 0; i < 5; ++i) {
    tree.AddElement("Кресло");
  }
  tree.AddElement("Лобовое стекло");
  for (int i = 0; i < 3; ++i) {
    tree.AddElement("Стеклo заднего вида");
  }
  tree.Print();
  std::cout << "Вывод количества каждого компонента автомобиля\n";
  tree.PrintAmountComponents();
  return 0;
}
