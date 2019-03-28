
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_FILES (argc - 1)
/**
 *This method read and print uniq lines from the stream specified.
 *
 **/
void print_uniq_lines(FILE *stream) {
	char *curr_line = NULL;
        size_t curr_len = 0;
        ssize_t curr_read;
        char *temp = NULL;
        size_t temp_len = 0;
        ssize_t temp_read;
	//read the first line from stream and rewind
        if((temp_read = getline(&temp, &temp_len, stream)) != -1){
        	printf("%s", temp);
                rewind(stream);
        }
        while((curr_read = getline(&curr_line, &curr_len, stream)) != -1) {
		int equal = strcmp(curr_line, temp) == 0 ? 1:0;
                if (equal == 1) {
                	continue;
                }
                //now are at a line different from 1st line
                printf("%s", curr_line);
                //fseek(stream, -strlen(curr_line), SEEK_CUR);//move file pointer back
                //temp_read = getline(&temp, &temp_len, stream);//make a copy of that into temp
		temp = realloc(temp, strlen(curr_line) + 1);
		temp = strcpy(temp, curr_line);
	}
	free(temp);
}

/*
 *my-uniq finds out adjacent duplicate lines in files, and prints them.
 *
 * */
int main(int argc, char *argv[]) {
	if (NUM_FILES == 0) {//read from stdin	
		print_uniq_lines(stdin);
		exit(0);
	}
	//NUM_FILES>=1
	FILE *fp;
  	//open each file sequentially & read from file
  	for (int i = 1; i <= NUM_FILES; i++) {
    		fp = fopen(argv[i], "r");
   		if (fp == NULL) {//upon failure -  exit
      			printf("my-uniq: cannot open file\n");
     			exit(1);
    	 	}
    	 	print_uniq_lines(fp);
  	}
  	fclose(fp);
	return 0;
}
