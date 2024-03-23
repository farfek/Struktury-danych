#ifndef HEADERS_HPP
#define HEADERS_HPP
#include <iostream>
using namespace std;
template <typename T>
class DynamicArray {
private:
    T* ptr; //wskaŸnik na pocz¹tek tablicy.
    int capacity; //maksymalny rozmiar tablicy.
    int size; //Ile elementów jest w tablicy.

public:
    DynamicArray(int cap, int free); //Konstruktor w którym podajemy rozmiar tablicy, 
    //oraz ile elementów jest pustych. Wype³nia on ka¿d¹ komórkê wartoœci¹ jego indeksu.
    ~DynamicArray(); //Destruktor usuwa wskaŸnik tablicy i zwalnia pamiêæ.
    void addBack(T value); //Dodaje element o wartoœci wpisanej na koniec tablicy.
    void removeBack(); //Usuwa element znajduj¹cy siê na koñcu tablicy.
    void addFront(T value); //Dodaje element o wartoœci wpisanej na pocz¹tek tablicy.
    void removeFront(); //Usuwa element znajduj¹cy siê na pocz¹tku tablicy.
    void add(T value, int index); //Dodaje element o wartoœci wpisanej na wpisane przez u¿ytkownika miejsce w tablicy.
    void remove(int index); //Usuwa element we wpisanym miejscu przez u¿ytkownika.
    void printOut(); // Funkcja wyœwietla wszystkie elementy tablicy oraz jej capacity oraz size.
    int search(T data); //Wyszukuje czy w tablicy znajduje siê podana wartoœæ.
};

template<typename t>
void tests(t n); //Funkcja s³u¿¹ca pomiarom czasów dzia³añ na tablicach o ró¿nych podanych rozmiarach.

#endif // HEADERS_HPP
