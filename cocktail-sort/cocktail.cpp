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

// Cocktail sorting
void cocktail(int* m) {
  int left = 0, right = N - 1;
  while (left <= right) {
    for (int i = left; i < right; i++) {
      if (m[i] > m[i + 1]) swap(i, i + 1, arr);
      // Delay
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    right--;
    for (int i = right; i > left; i--) {
      if (m[i] < m[i - 1]) swap(i, i - 1, arr);
      // Delay
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    left++;
    std::cout << left << " - " << right << std::endl;
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
  // Cocktail sorting
  std::cout << "Sorting started\n";
  cocktail(arr);
  std::cout << "Sorting done\n";
}

VisualModule* vm;
int main() {
  vm = new VisualModule("Cocktail sort", thread, arr, N);
  return 0;
}