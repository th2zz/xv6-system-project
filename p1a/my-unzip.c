#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM_FILES (argc - 1)
void decode(char *str) {
  int len = strlen(str);
  int value = 0;
  for (int i = 0; i < len; i+= 2) {
    value = atoi(&str[i]);
    if ((i + 1) <= len) {
      for (int j = 0; j < value; j++) {
        printf("%c", str[i+1]);
      }  
    }
  }
}


int main (int argc, char *argv[]) {
  FILE *fp;
  char *line = NULL;
  size_t n = 0;
  ssize_t len;
  if (argc == 1) {
    printf("my-unzip: file1 [file2 ...]\n");
    exit(1);
  }
  
  for (int i = 0; i < NUM_FILES; i++) {
    fp = fopen(argv[i + 1], "rb");
    if (fp == NULL) {
      printf("my-unzip: cannot open file\n");
      exit(1);
    }
    while ((len = getline(&line, &n, fp)) != -1) {
      decode(line);
    }

  }
  free(line);
  line = NULL;
  return 0;
}
