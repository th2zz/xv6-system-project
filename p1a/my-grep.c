#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
   FILE *fp;//file ptr
   char *line = NULL; //line pointer for reading a line
   size_t n = 0;
   ssize_t len;
   //type size & line length for getline
   
   if (argc == 1) { //no commandline arguments
     printf("my-grep: searchterm [file ...]\n");
     exit(1);
   } else if (argc == 2) { //no files specified 
     while ((len = getline(&line, &n, stdin)) != -1) {
       if (strstr(line, argv[1]) != NULL) {
         printf("%s", line);//read from stdin, then print
       }
     }
      
   } else { //one or more file
     for (int i = 2; i <= (argc - 1); i++) {
       fp = fopen(argv[i], "r");
       if (fp == NULL) {
         printf("my-grep: cannot open file\n");
         exit(1);
       }
       //print all lines matched for this file
       while ((len = getline(&line, &n, fp)) != -1) {
         if (strstr(line, argv[1]) != NULL) {
	   printf("%s", line);
	 }
       }
       fclose(fp);
     }
   }
   free(line);
   line = NULL;
   return 0;
}
