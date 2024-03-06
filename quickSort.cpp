#include <iostream>
using namespace std;
void quickSort(int array[], int low, int high) {
    int i = low, j = high;
    if (i >= j)return;
    while (i != j) {
        while (array[j] >= array[low] && i < j) {
            j--;
        }
        while (array[i] <= array[low] && i < j) {
            i++;
        }
        swap(array[i], array[j]);
    }
    swap(array[i], array[low]);
    quickSort(array, low, i - 1);
    quickSort(array, i + 1, high);
}
int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++)a[i] = rand();
    quickSort(a, 0, 9);
    for (auto& i : a)cout << i << ' ';
}