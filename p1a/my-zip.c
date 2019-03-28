#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_FILES (argc - 1)
void encode(char* str) {;
  int cnt = 1;
  int len = strlen(str);
  char c;
  for (int i = 0; i < len; i++) {
      c = str[i];
      if (i + 1 < len && str[i] == str[i + 1]) {
          cnt++;
          continue;
      } else {
          fwrite(&cnt, sizeof(int), 1, stdout);
          fwrite(&c, sizeof(char), 1, stdout);
          cnt = 1;
      }
  }
}
int main (int argc, char *argv[]) {
  FILE *fp;
  char *line = NULL;  
  size_t n = 0;
  ssize_t len; 
  if (argc == 1) {
    printf("my-zip: file1 [file2 ...]\n");
    exit(1);
  }
  for (int i = 0; i < NUM_FILES; i++) {
    fp = fopen(argv[i + 1], "r");
    if (fp == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }
    while ((len = getline(&line, &n, fp)) != -1) {
      encode(line);  
    }
    
  }
  free(line);
  line = NULL;
  return 0;
}
