#include <iostream>
#include "bigsortlib/visualm.h"

VisualModule* vm;
int arr[100];

int n = 0;

void update() {
  n++;
}

int main() {
  for (int i = 0; i < 100; i++) {
    arr[i] = i * ((float)PALETTE / 100);
  }
  vm = new VisualModule("Bubble sort", update, arr, 100);
  return 0;
}