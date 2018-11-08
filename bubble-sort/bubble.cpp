#include <ctime>
#include <iostream>
#include <random>
#include "bigsortlib/visualm.h"

// Elements count
#define N 100

// Array
int arr[N];

// Swaping two elements
void swap(int a, int b, int* m) {
  int tmp = m[a];
  m[a] = m[b];
  m[b] = tmp;
}

// Bubble sorting
void bubble(int* m) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      // Swaping, if next element is greater
      if (j != N - 1 && m[j] < m[j + 1]) swap(j, j + 1, m);
      // Delay
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}

// Thread function
void thread() {
  // Fill array
  for (int i = 0; i < N; i++) arr[i] = i * ((float)PALETTE / N);
  // Wait 2s
  std::this_thread::sleep_for(std::chrono::seconds(2));

  // Random seed
  std::srand(unsigned(std::time(0)));
  // Random swap
  for (int i = 0; i < N; i++) {
    int a = rand() % (N - 1);
    int b = rand() % (N - 1);
    swap(a, b, arr);
    std::this_thread::sleep_for(std::chrono::microseconds(1));
  }

  // Wait 2s
  std::this_thread::sleep_for(std::chrono::seconds(2));
  // Bubble sorting
  std::cout << "Sorting started\n";
  bubble(arr);
  std::cout << "Sorting done\n";
}

VisualModule* vm;
int main() {
  vm = new VisualModule("Bubble sort", thread, arr, N);
  return 0;
}