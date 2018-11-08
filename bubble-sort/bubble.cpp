#include <iostream>
#include "bigsortlib/visualm.h"

VisualModule* vm;
int arr[1000];

int n = 0;

void update() {
  while (true) {
    arr[n % 1000] += 10;
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    n++;
  }
}

int main() {
  for (int i = 0; i < 1000; i++) {
    arr[i] = i * ((float)PALETTE / 1000);
  }
  vm = new VisualModule("Bubble sort", update, arr, 1000);
  return 0;
}