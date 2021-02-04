#include <string>
#include <iostream>

using namespace std;

/*
 * This C++ program can be use to get inputs
 * for the csc220 #Knuth programming assignment.
 *
 * @creator gdt
 * @created 02017.09.04
 * @updated 02018.08.28
 */

int main(int, char**) {

   void knuth(int);
   const int EXIT = 0;
   int n;
   do {
      cerr << "Enter a whole number (" << EXIT << " to exit): ";
      cin >> n;
      if (n == EXIT)
         break;
      knuth(n < 0 ? -n : n);
   } while (true);

}

// prints the prime factorization for a composite number
//
void knuth(int n) {

   cout << n << " = ";
   // to be implemented...
   //Implemented by Ben Edwards for CSC 220 Donald Knuth Assignment
   bool prime = false;
   for(int i = 2; i < n; i++)
   {          
       if(n % i == 0){
         double temp = n / i;
         cout << i << " * ";         
         n = temp;
         i--;
         prime = true;
       }    
       
       if(n - i == 1)
         cout << n;      
     
   }
   if(prime == false)
	 cout << "(prime)";
   cout << endl;

}

/*
   example outputs for inputs 42, 7, 100, -101

   42 = 2 * 3 * 7
   7 = 7 (prime)
   100 = 2 * 2 * 5 * 5
   101 = 101 (prime)

*/
