/*
	This program prints the first 32 numbers of the
Padovan Sequence, which is defined as 
                             p(n) = p(n-2) + p(n-3) = 0
                    where    p(0) = 1, p(1) = p(2) = 0
                             
    creator - bde
    
*/                             

#include <iostream>

using namespace std;

int main(int, char**) {
    const int HOW_MANY = 32;
    int padovan(int);
    for (int n = 1; n <= HOW_MANY; n++) 
    	cout << "padovan(" << n << ") = " 
             << padovan(n - 1) << endl;
}

int padovan(int n){
	if(n == 0)
		return 1;
	else if(n == 1 || n == 2)	
		return 0;
	else 
		return padovan(n - 2) + padovan(n - 3);
}
