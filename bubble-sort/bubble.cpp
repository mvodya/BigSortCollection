#include <iostream>
#include "bigsortlib/visualm.h"

VisualModule* vm;
int arr[100];

int n = 0;

void update() {
  n++;
  for (int i = 0; i < 100; i++) {
    arr[i] = i * 17.8f;
  }
}

int main() {
  vm = new VisualModule("Bubble sort", update, arr, 100);
  //system("pause");
  return 0;
}