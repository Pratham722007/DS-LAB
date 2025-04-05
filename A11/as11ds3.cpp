#include <iostream>
#include <vector>
using namespace std;

// Get the maximum value in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

// Counting sort for a specific digit place (exp = 1, 10, 100, ...)
void countingSort(int arr[], int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) 
        arr[i] = output[i];
}

// Radix Sort Function
void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}