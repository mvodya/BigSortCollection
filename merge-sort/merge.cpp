#include <ctime>
#include <iostream>
#include <random>
#include "bigsortlib/visualm.h"

using namespace sortlib;

// Elements count
#define N 500

// Array
int arr[N];

// Swaping two elements
void swap(int a, int b, int* m) {
  int tmp = m[a];
  m[a] = m[b];
  m[b] = tmp;
}

// Merge sorting
void merge(int* m, int size) {
  if (size > 1) {
    int const left_size = size / 2;
    int const right_size = size - left_size;
    
    merge(&m[0], left_size);
    merge(&m[left_size], right_size);

    int lidx = 0, ridx = left_size, idx = 0;
    int *tmpm = new int[size];

    // Cursor buffer
    int color = -1;
    int position = -1;

    while (lidx < left_size || ridx < size) {
      if (position != -1)
        m[position] = color;
      if (m[lidx] < m[ridx]) {
        tmpm[idx++] = m[lidx];
        lidx++;
      }
      else {
        tmpm[idx++] = m[ridx];
        ridx++;
      }
      if (lidx == left_size) {
        for (int i = 0; i < size - ridx; i++) {
          tmpm[idx++] = m[ridx + i];
        }
        break;
      }
      if (ridx == size) {
        for (int i = 0; i < left_size - lidx; i++) {
          tmpm[idx++] = m[lidx + i];
        }
        break;
      }
      position = idx;
      color = m[idx];
      m[idx] = 0;
      // Delay
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
    // Copy tempory to original array
    for (int i = 0; i < size; i++)
      m[i] = tmpm[i];
    // Remove tempory
    delete[] tmpm;
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
  // Merge sorting
  std::cout << "Sorting started\n";
  merge(arr, N);
  std::cout << "Sorting done\n";
}

VisualModule* vm;
int main() {
  vm = new VisualModule("Merge sort", thread, arr, N);
  return 0;
}