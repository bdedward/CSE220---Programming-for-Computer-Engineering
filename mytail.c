/*
author: bde

description:
	This program reads the file "mytail.in.txt"
and prints the last 10 lines of the file to
the standard output stream.

	This program also allows the user to specify 
how many lines will be printed. If number
exceeds the number of lines, then the 
program will print all lines of the file.
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char const* file;
	int n = 10;
	if(argc == 1){
		fprintf(stderr, "%s", "You did not specify a file to be opened.\n");
		return EXIT_FAILURE;
	}
	if(argc == 2)
		file = argv[1];
	if(argc == 3){
		n = atoi(argv[1]);
		file = argv[2];
	}
	
	FILE* fp = fopen(file, "r");
	if(fp == 0 && argc == 3){
		fprintf(stderr, "%s%s%s%d%s","could not open ", argv[2], " errno= ", errno,"\n");
		return EXIT_FAILURE;
	}
	else if(fp == 0){
		fprintf(stderr, "%s%s%s%d%s","could not open ", argv[1], " errno= ", errno, "\n");
		return EXIT_FAILURE;
	}
	char line[512];
	int i = 0;
	
	int count = 0;
	//intended to be a counter for number of lines in file
	while(1){
		if(feof(fp)) break;	
		fgets(line, sizeof(line),fp);	
		count++;
	}
	rewind(fp);
	
	//checks for input greater than # of lines
    if(n > count)
    	n = count;
    
	//finds the starting point for the last n lines
	for(i = 0; i <= count - n; i++){
		fgets(line, sizeof(line), fp);
	}
	
	//prints the last "n" lines of the file
	for(i = 0; i < n; i++){		
		printf("%s", line);
		if(feof(fp)) break;	
		fgets(line, sizeof(line),fp);		
	}

	fclose(fp);
	  
}
