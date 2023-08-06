#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string names[], string addresses[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j] > names[j+1]) {
                // Tukar posisi nama
                swap(names[j], names[j+1]);
                // Tukar posisi alamat sesuai dengan nama
                swap(addresses[j], addresses[j+1]);
            }
        }
    }
}

void selectionSort(string names[], string addresses[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (names[j] < names[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Tukar posisi nama
            swap(names[i], names[minIndex]);
            // Tukar posisi alamat sesuai dengan nama
            swap(addresses[i], addresses[minIndex]);
        }
    }
}

void printArrays(string names[], string addresses[], int n) {
    for (int i = 0; i < n; i++) {
        cout << names[i] << " | " << addresses[i] << endl;
    }
}

int main() {
    const int n = 8;
    string names[n] = {"Fahmi", "Romi", "Andri", "Fadillah", "Ruli", "Rudi", "Dendi", "Zaki"};
    string addresses[n] = {"Jakarta", "Solo", "Jakarta", "Banyuwangi", "Bandung", "Bali", "Purwokerto", "Madiun"};
    
    string cloneNames[n], cloneAddresses[n];
    
    for (int i = 0; i < n; i++) {
        cloneNames[i] = names[i];
    }
    for (int i = 0; i < n; i++) {
        cloneAddresses[i] = addresses[i];
    }

    cout << "Data sebelum diurutkan:" << endl;
    printArrays(names, addresses, n);


    bubbleSort(names, addresses, n);

    cout << "\nData setelah diurutkan berdasarkan nama dengan metode bubble sort:" << endl;
    printArrays(names, addresses, n);
    

    selectionSort(cloneNames, cloneAddresses, n);
    
    cout << "\nData setelah diurutkan berdasarkan nama dengan metode selection sort:" << endl;
    printArrays(cloneNames, cloneAddresses, n);


    return 0;
}