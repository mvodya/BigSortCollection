#include <iostream>
#include "bigsortlib/visualm.h"

VisualModule* vm;

void update() { std::cout << "up\n"; }

int main() {
  vm = new VisualModule("Bubble sort", update);
  system("pause");
  return 0;
}