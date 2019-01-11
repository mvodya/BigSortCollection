#include <ctime>
#include <iostream>
#include <random>
#include "bigsortlib/visualm.h"

using namespace sortlib;

// Elements count
#define N 200

// Array
int arr[N];

// Swaping two elements
void swap(int a, int b, int* m) {
  int tmp = m[a];
  m[a] = m[b];
  m[b] = tmp;
}

// Insertion sorting
void insertion_sort(int* m) {
  for (int i = 1; i < N; i++) {
    int k = i;
    while (k > 0 && m[k] < m[k - 1]) {
      swap(k, k - 1, m);
      k--;
      // Delay
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
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
  // Insertion sorting
  std::cout << "Sorting started\n";
  insertion_sort(arr);
  std::cout << "Sorting done\n";
}

VisualModule* vm;
int main() {
  vm = new VisualModule("Insertion sort", thread, arr, N);
  return 0;
}