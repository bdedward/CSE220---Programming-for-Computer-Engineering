/*

This program takes an array of characters of max length
127, and reverses the array.  The user may only enter
digits and letters.

creator - bde
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

main(int, char**){
	char* reverse(char*, int, int);
	bool arrayCheck(char*);
	
	char c[127];
	cout << "Enter at most 127 letters and digits (press ENTER when done): ";
	cin >> c;
	bool check = arrayCheck(c);
	if(check == false){
		cout << "You have entered an invalid character (only letters/digits accepted). \nGoodbye.";
		exit(EXIT_FAILURE);
	}
	int size = strlen(c);
	if(size > 127){
		cout << "You were to enter at most 127 letters/digits.  You have exceeded this limit. \nGoodbye.";
		exit(EXIT_FAILURE);
	}
	cout << c << " reversed is ";
	reverse(c, 0, size - 1);
	cout << c;
}

char* reverse(char* c, int first, int last){
	if(first >= last)
	return c;
	char temp = c[first];
	c[first] = c[last];
	c[last] = temp;
	return reverse(c, first +1, last -1);
}

bool arrayCheck(char* c){
	bool valid = true;
	for(int i = 0; i < strlen(c); i++)
		if(c[i] < 'A' || c[i] > 'Z')
			if(c[i] < '0' || c[i] > '9' && c[i] < 'a' || c[i] > 'z')
				valid = false;
	return valid;
}



