/* This program prints stats information using the array
data type.
Ben Edwards
CSC 220*/


#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//function used in qsort
int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpfunc (const void* a, const void* b){
	
}

int main(int, char**){
   int stats(int[], int, double&, double&, int&);
   int stats(int[], int, bool = false);
   int stats(const char[], int, double, double, int);
   int stats(const char[], int, bool = false);
   bool search(int*, int, int, const char[]);
   void searchResult(const char[], bool, int);
   void printArray(int[], int, const char[]);
   void newLine();
   
   int seta[] = { 5, 10, 15, 20, 25 }; 
   int alen = sizeof(seta) / sizeof(seta[0]);

   int setb[] = { 2, -2, 0, 2, -2, 2, -2, -2 };
   int blen = sizeof(setb) / sizeof(setb[0]);

   int setc[] = { 10, 9, 8, 10, 1, -1 };
   int clen = sizeof(setc) / sizeof(setc[0]);
   
   int dlen = alen + blen + clen;
   int *setd = (int *)malloc(dlen * sizeof(int));
   
   for(int i = 0; i < alen; i++)
   		setd[i] = seta[i];
   for(int i = alen; i < alen + blen; i++)
   		setd[i] = setb[i - alen];
   for(int i = alen + blen; i < dlen; i++)
   		setd[i] = setc[i - alen - blen];  		
      
   qsort(seta, alen, sizeof(int), compare);
   qsort(setb, blen, sizeof(int), compare);
   qsort(setc, clen, sizeof(int), compare);   
   qsort(setd, dlen, sizeof(int), compare);
   
   double mean = 0, median = 0; 
   int mode, range;
   
   printArray(seta, alen, "set A:");
   range = stats(seta, alen, mean, median, mode);
   (void) stats("set A: ", range, mean, median, mode);
   (void) stats("set A: ", stats(seta, alen));
   (void) stats("set A: ", stats(seta, alen, true), true);
   newLine();
   
   printArray(setb, blen, "set B:");
   range = stats(setb, blen, mean, median, mode);
   (void) stats("set B: ", range, mean, median, mode);
   (void) stats("set B: ", stats(setb, blen));
   (void) stats("set B: ", stats(setb, blen, true), true);
   newLine();
   
   printArray(setc, clen, "set C:");
   range = stats(setc, clen, mean, median, mode);
   (void) stats("set C: ", range, mean, median, mode);
   (void) stats("set C: ", stats(setc, clen));
   (void) stats("set C: ", stats(setc, clen, true), true);
   newLine();
   
   printArray(setd, dlen, "set D:");
   range = stats(setd, dlen, mean, median, mode);
   (void) stats("set D: ", range, mean, median, mode);  
   (void) stats("set D: ", stats(setd, dlen));
   (void) stats("set D: ", stats(setd, dlen, true), true);
   newLine();
   
   int value;
   char repeat;
   
   do{   
    bool found;
   	cout << "Enter Integer Search Value: ";
   	cin >> value;
   	if(!cin){
   		cout << "You have not entered an integer. Goodbye.";	
   		exit(EXIT_FAILURE);
	}
   	found = search(seta, alen, value, "seta");
    searchResult("seta ", found, value);
    
   	found = search(setb, blen, value, "setb");
   	searchResult("setb ", found, value);
   	
   	found = search(setc, clen, value, "setc");
   	searchResult("setc ", found, value);
   	
   	found = search(setd, dlen, value, "setd");
   	searchResult("setd ", found, value);
   	cout << endl << "Do you want to do another search? ";   	
   	cin >> repeat;
   	while(repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N'){
   		cout << endl << "You have entered an invalid choice. ";
   		cout << "Acceptable responses are: \"Y,\" \"y,\" \"N,\" or \"n.\"";
   		cout << endl << "Do you want to do another search? ";
   		cin >> repeat;
	   }
   }while(repeat == 'y' || repeat == 'Y');
}

//This function calculates the mean, median and mode of the array.
//It is passed the array and num of elements as a value and passed
//mean, median and mode as reference.
int stats(int set[], int nelems, double& mean, double& median, int& mode){
	int total = 0;
	int middle = set[nelems /  2 - 1] + set[nelems / 2];
	//median calculation
	if(nelems % 2 == 0)
	   median = (double)middle/ 2;
	else
	   median = set[nelems / 2];
	   
	//mode calculation
	qsort(set, nelems, sizeof(int), compare); //sorting array before looking for mode
    int count = 1;
    int maxnum = 0;
    mode = -99;  // arbitary value chosen for mode in case of mode 
				 // acquisition fails (modeless).
				 
    for (int i = 0; i < nelems; i++)
        if (set[i] == set[i + 1] ){
            count++;
            if (count > maxnum){
            	mode = set[i];
                maxnum = count;                
            }
        }         
		else
        	count = 1;         
    

	
	//mean calculation
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
	cout << heading << "range= " << range << "; mean= " << mean << "; median= " 
	 			     << median << "; mode= ";
	if(mode != -99)
	cout << mode << endl;
	else
	cout << "modeless" << endl;
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
   return EXIT_SUCCESS;	
}

bool search(int* set, int nelems, int search_value, const char heading[]){
	bool found;
	int* search = (int*) bsearch (&search_value, set, nelems, sizeof (int), compare);	
	if(search != NULL)
		found = true;
	else
		found = false;
	return found;		
}

bool searchResult(const char heading[], bool found, int value){
	if(found == true)
   		cout << value << " found in " << heading << endl;
   	else
   		cout << value << " not found in " << heading << endl;
}

void printArray(int set[], int nelems, const char heading[]){
   cout << heading << "{";
   for(int i = 0; i < nelems; i++){
   	  if(i < nelems && i > 0)
   	  	cout << ", " << set[i];
   	  else
   	  	cout << set[i];
   }
   cout << "}" << endl;
}

void newLine(){
	cout << endl;
}
