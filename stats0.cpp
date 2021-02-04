/* This program prints stats information using the array
data type.
Ben Edwards
CSC 220*/


#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int, char**){
   int stats(int[], int, double&, double&, int&);
   int stats(int[], int, bool = false);
   int stats(const char[], int, double, double, int);
   int stats(const char[], int, bool = false);
   
   int seta[] = { 5, 10, 15, 20, 25 }; 
   int alen = sizeof(seta) / sizeof(seta[0]);

   int setb[] = { 2, -2, 0, 2, -2, 2, -2, -2 };
   int blen = sizeof(setb) / sizeof(setb[0]);

   int setc[] = { 10, 9, 8, 10, 1, -1 };
   int clen = sizeof(setc) / sizeof(setc[0]);
   
   double mean = 0, median = 0; 
   int mode, range;

   range = stats(seta, alen, mean, median, mode);
   (void) stats("set A: ", range, mean, median, mode);
   range = stats(setb, blen, mean, median, mode);
   (void) stats("set B: ", range, mean, median, mode);
   range = stats(setc, clen, mean, median, mode);
   (void) stats("set C: ", range, mean, median, mode);
   
   (void) stats("set A: ", stats(seta, alen));
   (void) stats("set A: ", stats(seta, alen, true), true);  
   
   (void) stats("set B: ", stats(setb, blen));
   (void) stats("set B: ", stats(setb, blen, true), true);
   
   (void) stats("set C: ", stats(setc, clen));
   (void) stats("set C: ", stats(setc, clen, true), true);
}

//This function calculates the mean, median and mode of the array.
//It is passed the array and num of elements as a value and passed
//mean, median and mode as reference.
int stats(int set[], int nelems, double& mean, double& median, int& mode){
	int total = 0;
	for(int i = 0; i < nelems; i++)
		total += set[i];
	if(nelems > 0)
		mean = (double)total / nelems;
	int min = set[0], max = set[0];
	for(int i = 1; i < nelems; i++){
		if(set[i] > max)
			max = set[i];
		if(set[i] < set[0])
			min = set[i];
	}
	return max - min;	
}

//This function returns the product or the sum of each element in the array
//depending on the value of product passed in.  It returns the result of the
//summation or product.
int stats(int set[], int nelems, bool product){
	int result;
	if(!product){
		result = 0;
		for(int i = 0; i < nelems; i++)
			result += set[i];
	}
	if(product){
		result = 1;
		for(int j = 0; j < nelems; j++)
			result *= set[j];
	}
	return result;
}
//This function prints the heading, range, mean, median and mode
int stats(const char heading[], int range, double mean, double median, int mode){	 
	cout << heading << " range= " << range << " mean= " << mean << " median= " 
	 			     << median << " mode= " << mode << endl;
	return EXIT_SUCCESS;	
}

//This function takes in a heading and "n" which is the result of the stats 
//function above, which produces either the summation or the product of each
//element in the given array.
int stats(const char heading[], int n, bool product){     
   cout << heading;
   if(product)
   		cout << "product= " << n << endl;
   if(!product)
   		cout << "sum= " << n << endl;
   //cout << heading;
   return EXIT_SUCCESS;	
}
