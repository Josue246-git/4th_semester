#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int array[], int size) {
    int temp =0;

  // loop to access each array element
  for (int step = 0; step < size; ++step) {
    temp = 0;
    // loop to compare array elements
    for (int i = 0; i < size - step; ++i) {
      // compare two adjacent elements
      // change > to < to sort in descending order

      if (array[i] > array[i + 1]) {
        // swapping elements if elements
        // are not in the intended order
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // find array's length; division entre el tamaño de bytes del array y uno de sus elementos, solo cuando se define los valores del array 
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}