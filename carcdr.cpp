/*
	This program takes an integer array and prints the first
element of the array.  Then points to an array that does
not include the first element.  The function repeats until
the int array is empty.

creator - bde
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int, char**){
	int car(int* list);
	int* cdr(int* list);
	
	int list[] = {5, 8, 13, 21, 34};
	int length = sizeof(list) / sizeof(list[0]);	
	int* p = list; //pointer to first element
	int* end = list + length - 1; //pointer to last element in array
	int newlen = end - p; // defines newlen as first pointer minus last
	
	//Repeats until newlen is 0 (array is empty)
	while(newlen >= 0){			
		cout << "(car '( ";
		for(int i = 0; i < newlen + 1; i++)
			cout << *(p + i) << " "; 
		cout << ")) = ";
		
		int first = car(p);			
		cout << first << endl;
		
		cout << "(cdr '( ";
		for(int i = 0; i < newlen + 1; i++)
			cout << *(p + i) << " ";
		cout << ")) = ";
		
		// pointer to the next element not including first
		p = cdr(p);  		
		cout << "( ";
		for(int i = 0; i < newlen; i++)
			cout << *(p+i) << " ";
		cout << ")";
		cout << endl << endl;
		newlen = end - p;
	}		

}

int car(int* list){
	return list[0];
}

int* cdr(int* list){
	list += 1;
	return list;
}
