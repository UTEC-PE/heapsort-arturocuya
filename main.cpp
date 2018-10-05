#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapify(int* array, int sizeofHeap, int i)
{
    int lar = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    if (l < sizeofHeap && array[l] > array[lar]) lar = l; 
  
    if (r < sizeofHeap && array[r] > array[lar]) lar = r; 
  
    if (lar != i) 
    { 
        swap(array[i], array[lar]); 
        heapify(array, sizeofHeap, lar); 
    } 
}

void heapsort(int* array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--) heapify(array, size, i); 
  
    for (int i=size-1; i>=0; i--) 
    { 
        swap(array[0], array[i]); 
        heapify(array, i, 0); 
    }     
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}