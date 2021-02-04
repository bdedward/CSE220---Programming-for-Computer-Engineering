#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
	char const* file = "mytail.in.txt";
	int f = 10;
	FILE* fp = fopen(file, "r");
	char line[512];
	
	while(fgets(line, sizeof(line), fp)){
		printf("%s", line);
	}	
	fclose(fp);
   
}
