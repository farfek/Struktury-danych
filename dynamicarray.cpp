#include <iostream>
#include "dynamicarray.hpp"
#include <chrono>
using namespace std;
using namespace chrono;

template <typename T>
DynamicArray<T>::DynamicArray(int cap, int free) {

    capacity = cap;
    size = 0;
    ptr = new T[cap];

    for (int i = 0; i < cap - free; i++) {
        ptr[i] = i;
        size += 1;
    }

}

template <typename T>
DynamicArray<T>::~DynamicArray() {

    delete[] ptr;

}

template <typename T>
void DynamicArray<T>::addBack(T value) {

    if (size < capacity) {
        ptr[size] = value;
        size += 1;
    }
    else {
        capacity *= 2;
        T* swap = ptr;
        ptr = new T[capacity];
        for (int i = 0; i < size; i++) {
            ptr[i] = swap[i];
        }
        ptr[size] = value;
        size += 1;
        delete[] swap;
    }

}

template <typename T>
void DynamicArray<T>::removeBack() {

    if (size > 0) {
        size -= 1;
    }

}

template <typename T>
void DynamicArray<T>::addFront(T value) {

    if (size < capacity) {
        for (int i = size; i > 0; i--) {
            ptr[i] = ptr[i - 1];
        }
        ptr[0] = value;
        size += 1;
    }
    else {
        capacity *= 2;
        T* swap = ptr;
        ptr = new T[capacity];
        ptr[0] = value;
        for (int i = 0; i < size; i++) {
            ptr[i + 1] = swap[i];
        }
        size += 1;
        delete[] swap;
    }

}

template <typename T>
void DynamicArray<T>::removeFront() {

    if (size > 0) {
        size -= 1;
        for (int i = 0; i < size; i++) {
            ptr[i] = ptr[i + 1];
        }
    }

}

template <typename T>
void DynamicArray<T>::add(T value, int index) {

    if (0 <= index && index < size) {
        if (size < capacity) {
            for (int i = size; i >= index; i--) {
                ptr[i + 1] = ptr[i];
            }
            ptr[index] = value;
            size += 1;
        }
        else {
            T* swap = ptr;
            capacity *= 2;
            ptr = new T[capacity];
            for (int i = size; i >= index; i--) {
                ptr[i + 1] = swap[i];
            }
            for (int i = 0; i < index; i++) {
                ptr[i] = swap[i];
            }
            ptr[index] = value;
            size += 1;
        }
    }
    else {
        cout << "Incorrect index!" << endl;
    }

}

template <typename T>
void DynamicArray<T>::remove(int index) {

    if (0 <= index && index < size) {
        for (int i = index; i < size - 1; ++i) {
            ptr[i] = ptr[i + 1];
        }
        size -= 1;
    }
    else {
        cout << "Incorrect index!" << endl;
    }

}

template <typename T>
void DynamicArray<T>::printOut() {

    cout << "Dynamic array:" << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Size: " << size << endl;
    if (size == 0) {
        cout << "Array is empty." << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

}

template <typename T>
int DynamicArray<T>::search(T data) {

    if (size != 0) {
        for (int i = 0; i < size; i++) {
            if (data == ptr[i]) {
                return i;
            }
        }
        return -1;

    }

}

template<typename t>
void tests(t n) {

    DynamicArray<int> dodajp(n, 0);
    auto start = high_resolution_clock::now();
    dodajp.addFront(36);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodania elementu na poczatku w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> usunp(n, 0);
    start = high_resolution_clock::now();
    usunp.removeFront();
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu na poczatku w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> dodajk(n, 0);
    start = high_resolution_clock::now();
    dodajk.addBack(36);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodawania elementu na koncu w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> usunk(n, 0);
    start = high_resolution_clock::now();
    usunk.removeBack();
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu na koncu w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> dodajs(n, 0);
    start = high_resolution_clock::now();
    dodajs.add(0, n / 2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodawania elementu w polowie w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> usuns(n, 0);
    start = high_resolution_clock::now();
    usuns.remove(n / 2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu w polowie w przypadku tablicy zapelnionej z " << n << " elementami: " << duration.count() << endl;
    
    DynamicArray<int> dodajp2(n + 1, 1);
    start = high_resolution_clock::now();
    dodajp2.addFront(36);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodawania elementu na poczatku w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> usunp2(n + 1, 1);
    start = high_resolution_clock::now();
    usunp2.removeFront();
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu na poczatku w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> dodajk2(n + 1, 1);
    start = high_resolution_clock::now();
    dodajk2.addBack(36);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodawania elementu na koncu w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> usunk2(n + 1, 1);
    start = high_resolution_clock::now();
    usunk2.removeBack();
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu na koncu w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> dodajs2(n  + 1, 1);
    start = high_resolution_clock::now();
    dodajs2.add(0, n / 2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji dodawania elementu w polowie w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> usuns2(n + 1, 1);
    start = high_resolution_clock::now();
    usuns2.remove(n / 2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji usuwania elementu w polowie w przypadku tablicy z wolnym miejscem z " << n << " elementami: " << duration.count() << endl;
    
    int i = 0;
    DynamicArray<int> szukajs1(n, 0);
    start = high_resolution_clock::now();
    szukajs1.search(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu ktory znajduje sie na poczatku tablicy z " << n << " elementami: " << duration.count() << endl;

    i = n / 4;
    DynamicArray<int> szukajs2(n, 0);
    start = high_resolution_clock::now();
    szukajs2.search(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu ktory znajduje sie w 1/4 tablicy z " << n << " elementami: " << duration.count() << endl;

    i = n / 2;
    DynamicArray<int> szukajs3(n, 0);
    start = high_resolution_clock::now();
    szukajs3.search(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu ktory znajduje sie w 1/2 tablicy z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> szukajs4(n, 0);
    i = 3 * (n / 4);
    start = high_resolution_clock::now();
    szukajs4.search(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu ktory znajduje sie w 3/4 tablicy z " << n << " elementami: " << duration.count() << endl;

    DynamicArray<int> szukajs5(n, 0);
    start = high_resolution_clock::now();
    szukajs5.search(n);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu ktory znajduje sie na koncu tablicy z " << n << " elementami: " << duration.count() << endl;

    i = n + 25;
    DynamicArray<int> szukajp(n, 0);
    start = high_resolution_clock::now();
    szukajp.search(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Dlugosc operacji szukania elementu bez powodzenia z " << n << " elementami: " << duration.count() << endl;

    cout << endl << endl << endl;
    
}