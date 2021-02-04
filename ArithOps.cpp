#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

/* This program prompts the user for two integers
to complete a given arithmetic operation *, +, - and /
Prints an error message and exit the program if the user enters an invalid operator.
Prompt the user to enter another integer number. If the arithmetic operator is divide, 
then print an error message and exit the program if this integer input is 0. Print the 
result obtained when the arithmetic operator is applied to the entered numbers. If the 
result is a quotient, then print a warning message that integer arithmetic was executed.
*/
void divide(int, int);
void add(int, int);
void subtract(int, int);
void multiply(int, int);

int main(int argc, char** argv){
	int num1, num2;
	char arith = ' ';
	cout << "enter an integer: ";
	cin >> num1;
	cout << "enter an arithmetic operator: ";
	cin >> arith;
	
	if(arith != '+' && arith != '-' && arith !='/' && arith != '*'){
		cout << endl << "*** error: invalid operator inputted. Use *, +, -, or / only.";	
		exit(EXIT_FAILURE);
	}	
	
	cout << "enter an integer: ";
	cin >> num2;
	cout << endl;
	
	
	if(arith == '/' && num2 == 0){
		cout << "*** error: cannot divide by zero";	
		exit(EXIT_FAILURE);
	}	

	
	switch (arith)
	{
		case '*': multiply(num1, num2);
			break;
		case '+': add(num1, num2);
			break;
		case '-': subtract(num1, num2);
			break;
		case '/': divide(num1, num2);
			break;
	}
}   

void divide(int x, int y){
	cout << x << " / " << y << " = " << x / y;
	if(x % y > 0){
		cout << "\t" << "(warning: integer division executed)";
		cout << endl << x << " / " << y << " = ";		
		cout << (double) x / (double) y;
	}
}

void add(int x, int y){
	cout << x << " + " << y << " = " << x + y;
}
void subtract(int x, int y){
	cout << x << " - " << y << " = " << x - y;
}	

void multiply(int x, int y){
	cout << x << " * " << y << " = " << x * y;
}
