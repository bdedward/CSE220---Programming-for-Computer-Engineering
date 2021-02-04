#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

main(int, char**){
   size_t strlen(const char *__s);
   int    strcmp(const char *__s1, const char *__s2);
   char*  strcpy(char *__s1, const char *__s2);
   char*  strcat(char *__s1, const char *__s2);
   char again;
		char s1[512];
		char s2[512];
		cout << "Enter the first string: ";
		cin >> s1;					
		cout << "Enter the second string: ";
		cin >> s2;
		
		int size = strlen(s1);
		cout << s1 << " is length: " << size << endl;
		size = strlen(s2);
		cout << s2 << " is length: " << size << endl;
	
		int compare = strcmp(s1, s2);
		if(compare == 0)
			cout << endl << s1 << " equals " << s2 << endl;
		else
			cout << endl << s1 << " does not equal " << s2 << endl;
	
		cout << endl << "After String 2 copied into String 1";
		strcpy(s1, s2);
		cout << endl << "\tString 1 is: " << s1 << endl;
		cout << "\tString 2 is: " << s2 << endl;
	
		cout << "After String 2 concatenated onto String 1" << endl;
		strcat(s1, s2);
		cout << "\tString 1: " << s1 << endl << "\tString 2: " << s2;
}

size_t strlen(const char *__s){
	int size = 0;
	for(int i = 0; __s[i] != 0; i++)
		size++;
	return size;	
}

char* strcpy(char *__s1, const char *__s2){
	for(int i = 0; i <= strlen(__s2); i++)
		__s1[i] = __s2[i];
}

int strcmp(const char *__s1, const char *__s2){
	int result;
	if(strlen(__s1) == strlen(__s2))
		for(int i = 0; i < strlen(__s1); i++)
			if(__s1[i] == __s2[i])
				result = 0;
			else{
				result = 1;
				i = strlen(__s1);
			}
	else
		result = 1;
	return result;
}
char* strcat(char *__s1, const char *__s2){
	int newsize = strlen(__s1) + strlen(__s2);	
	int j = 0;	
		for(int i = strlen(__s1); i < newsize; i++){
			__s1[i] = __s2[j];	
			j++;
		}	
}
