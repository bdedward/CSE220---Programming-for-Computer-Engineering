#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv){
//function prototypes
int getInput(void); 
void printLine(char, char, int); 
void printStats(int, int); 
bool again = true;
int numsquares = 0;
int length = 0;
	do{
		int input = getInput();
		if (input == -1)
			again = false;
		else{
			++numsquares;
			length += input;
			//top line of square
			printLine('+','-', input - 2);
			//interior lines of square
			printLine('|', ' ', input);
			//bottom line of sqare
			if(input > 1)
			printLine('+','-', input - 2);
		}		
   }while(again);
printStats(length, numsquares);
}

int getInput(){
	int length = -1;
	cout << endl << "Enter length between 0 and 64 (-1 to exit): ";
	cin >> length;		
	while(length < -1 || length > 64){
		cout << length << " is invalid.  " << endl;
		cout << "Length must be between 0 and 64 inclusive, or enter -1 to exit." << endl;
		length = getInput();
	} 
return length;	
}

void printLine(char a, char b, int x){
if(x >= 0){	
	if(a == '+'){
			cout << a;	
			for(int i = 0; i < x; i++)
				cout << b;	
			cout << a << endl;
	}
	else 	
		for(int k = 0; k < x - 2; k++){		
		cout << a;	
			for(int i = 0; i < x - 2; i++){	
			cout << b;
			}
		cout << a << endl;			
  	   }
}
else{
	if(x == -1)
		cout << a;
	cout << endl;
}
}

void printStats(int x, int y){
	cout << y << " squares printed.  " << "Average length: " << x/(double)y;	
}
