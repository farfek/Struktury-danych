#include <iostream>
#include "dynamicarray.hpp"
#include "dynamicarray.cpp"
using namespace std;

int main() {
	
	tests<int>(1);
	tests<int>(10);
	tests<int>(100);
	tests<int>(1000);
	tests<int>(10000);
	tests<int>(100000);
	tests<int>(1000000);

	return 0;

}