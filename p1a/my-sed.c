
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ARGS (argc - 1)
/**
 *Find and replace the specified term in the stream. Then print to stdout.
 *
 */
void findAndReplace(FILE *stream, char *find_term, char *replace_term, int find_len, int replace_len){
		char *line = NULL;
		size_t len = 0;
   		ssize_t read;
		//read line by line and process it
		while ((read = getline(&line, &len, stream)) != -1) {
			char *found = strstr(line, find_term);//ptr to pos starting at str found	
   			if(found == NULL){//not found in currentline
				printf("%s", line);		
				continue;
			}
			//found
			char *tail_substring = found + strlen(find_term);//substring of str after find_term
			int line_len = strlen(line);
			int tail_len = strlen(tail_substring);
			int head_len = line_len - tail_len - find_len;
			char *head_substring = malloc(head_len + 1);//substring of str before find_term
			strncpy(head_substring, line, head_len);//copy first head_len chars to head_substring
			*(head_substring + head_len + 1)='\0';//terminate the string
			//concatenate: head + replace term + tail
			int result_len = head_len + tail_len + replace_len;
			char *result = malloc(result_len + 1);
			result = strncat(strncat(strncat(result, head_substring, head_len), replace_term, replace_len), tail_substring, tail_len);
			printf("%s", result);
			free(head_substring);
			free(result);
		}
}

/*
 *my-sed will find the first instance of a string in a line and substitute it with another. 
 *It will print the output to standard output. 
 *Instances following the first instance remain as is.
 *In case there is no candidate to substitute the line will be printed as is.
 *In case there is only 2 arguments, it will read from stdin rather than file.
 *
 * */
int main(int argc, char *argv[]) {
	if (NUM_ARGS < 2) {	
		printf("my-sed: find_term replace_term [file ...]\n");
		exit(1);
	}
	
	char *replace_term = argv[2];
	int find_empty = (strcmp(argv[1], "") == 0) ? 1: 0;
	char *find_term;
	if (find_empty == 1) {
		find_term = "\"\"";
	} else {
		find_term = argv[1];
	}
	int find_len = strlen(find_term);
	int replace_len = strlen(replace_term);

	if (NUM_ARGS == 2) {//read from stdin 
		findAndReplace(stdin, find_term, replace_term, find_len, replace_len);
		exit(0);
	}

	//NUM_FILES>=1,  NUM_ARGS >=3
	FILE *fp;
  	//open each file sequentially & read from file
  	for (int i = 3; i <= NUM_ARGS; i++) {
    		fp = fopen(argv[i], "r");
   		if (fp == NULL) {//upon failure -  exit
      			printf("my-sed: cannot open file\n");
     			exit(1);
    	 	}
		findAndReplace(fp, find_term, replace_term, find_len, replace_len);
  	}
  	fclose(fp);
	return 0;
}
