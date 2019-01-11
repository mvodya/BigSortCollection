#include <ctime>
#include <iostream>
#include <random>
#include "bigsortlib/visualm.h"

using namespace sortlib;

// Elements count
#define N 1000

// Array
int arr[N];

// Swaping two elements
void swap(int a, int b, int* m) {
  int tmp = m[a];
  m[a] = m[b];
  m[b] = tmp;
}

// Quick sorting
void quick(int* m, int n) {
  int i = 0, j = n;  // Set pointers
  int buf;           // Buffer

  int p = m[n >> 1];  // Footing central element

  // Separation and comparison
  do {
    while (m[i] < p) i++;
    while (m[j] > p) j--;

    // Moving elements at pointer boundaries
    if (i <= j) {
      swap(i, j, m);
      i++;
      j--;
    }

    // Delay
    std::this_thread::sleep_for(std::chrono::microseconds(1));
  } while (i <= j);

  // Recursive calls
  if (j > 0) quick(m, j);
  if (n > i) quick(&m[i], n - i);
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
  // Quick sorting
  std::cout << "Sorting started\n";
  quick(arr, N - 1);
  std::cout << "Sorting done\n";
}

VisualModule* vm;
int main() {
  vm = new VisualModule("Quick sort", thread, arr, N);
  return 0;
}