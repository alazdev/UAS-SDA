#include <iostream>

using namespace std;

// Function Binary Search
int binarySearch(int arr[], int size, int target, int indices[]) {
    int left = 0;
    int right = size - 1;
    int foundCount = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            indices[foundCount] = mid + 1;
            foundCount++;
        }

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return foundCount;
}

// Function Linear Search
int linearSearch(int arr[], int size, int target, int indices[]) {
    int foundCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            indices[foundCount] = i + 1;
            foundCount++;
        }
    }

    return foundCount;
}

// Function Tambahan untuk Dilakukan test
void printOutput(int target, int indices[], int count) {
    if (count > 0) {
        cout << "Output: Angka " << target << " ada di indeks ke ";
        for (int i = 0; i < count; i++) {
            cout << indices[i] << (i < count - 1 ? ", " : "");
        }
        cout << endl;
    } else {
        cout << "Output: Angka " << target << " tidak ada dalam array" << endl;
    }
}

int main() {
    int arr[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Indeks untuk melacak posisi (indeks) di mana elemen yang dicari ditemukan dalam array.
    int indices[size];

    /**
     * [NOTE]
     * Sebenarnya binarySearch dapat dilakukan jika datanya sudah terurut,
     * Menurut test case yang diberikan metode search yang paling tepat adalah Linear Search
     * Jadi di c++ ini saya buat 2 versi
     * 1. Binary Search tanpa diurutkan
     * 2. Linear Search sesuai array yang ada
    */

    // Test Case 1 - Binary Search
    int target1 = 1;
    int count1 = binarySearch(arr, size, target1, indices);
    cout << "Binary Search - Input: " << target1 << endl;
    printOutput(target1, indices, count1);

    // Test Case 1 - Linear Search
    int count1Linear = linearSearch(arr, size, target1, indices);
    cout << "\nLinear Search - Input: " << target1 << endl;
    printOutput(target1, indices, count1Linear);

    // Test Case 2 - Binary Search
    int target2 = 50;
    int count2 = binarySearch(arr, size, target2, indices);
    cout << "\n\nBinary Search - Input: " << target2 << endl;
    printOutput(target2, indices, count2);

    // Test Case 2 - Linear Search
    int count2Linear = linearSearch(arr, size, target2, indices);
    cout << "\nLinear Search - Input: " << target2 << endl;
    printOutput(target2, indices, count2Linear);

    // Test Case 3 - Binary Search
    int target3 = 100;
    int count3 = binarySearch(arr, size, target3, indices);
    cout << "\n\nBinary Search - Input: " << target3 << endl;
    printOutput(target3, indices, count3);

    // Test Case 3 - Linear Search
    int count3Linear = linearSearch(arr, size, target3, indices);
    cout << "\nLinear Search - Input: " << target3 << endl;
    printOutput(target3, indices, count3Linear);

    // Input sendiri
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    int userInput;
    cin >> userInput;

    // Binary Search
    int userCount = binarySearch(arr, size, userInput, indices);
    cout << "\nBinary Search - Input: " << userInput << endl;
    printOutput(userInput, indices, userCount);

    // Linear Search
    int userCountLinear = linearSearch(arr, size, userInput, indices);
    cout << "\nLinear Search - Input: " << userInput << endl;
    printOutput(userInput, indices, userCountLinear);

    return 0;
}