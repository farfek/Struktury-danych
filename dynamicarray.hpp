#ifndef HEADERS_HPP
#define HEADERS_HPP
#include <iostream>
using namespace std;
template <typename T>
class DynamicArray {
private:
    T* ptr; //wska�nik na pocz�tek tablicy.
    int capacity; //maksymalny rozmiar tablicy.
    int size; //Ile element�w jest w tablicy.

public:
    DynamicArray(int cap, int free); //Konstruktor w kt�rym podajemy rozmiar tablicy, 
    //oraz ile element�w jest pustych. Wype�nia on ka�d� kom�rk� warto�ci� jego indeksu.
    ~DynamicArray(); //Destruktor usuwa wska�nik tablicy i zwalnia pami��.
    void addBack(T value); //Dodaje element o warto�ci wpisanej na koniec tablicy.
    void removeBack(); //Usuwa element znajduj�cy si� na ko�cu tablicy.
    void addFront(T value); //Dodaje element o warto�ci wpisanej na pocz�tek tablicy.
    void removeFront(); //Usuwa element znajduj�cy si� na pocz�tku tablicy.
    void add(T value, int index); //Dodaje element o warto�ci wpisanej na wpisane przez u�ytkownika miejsce w tablicy.
    void remove(int index); //Usuwa element we wpisanym miejscu przez u�ytkownika.
    void printOut(); // Funkcja wy�wietla wszystkie elementy tablicy oraz jej capacity oraz size.
    int search(T data); //Wyszukuje czy w tablicy znajduje si� podana warto��.
};

template<typename t>
void tests(t n); //Funkcja s�u��ca pomiarom czas�w dzia�a� na tablicach o r�nych podanych rozmiarach.

#endif // HEADERS_HPP
