#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE (512)
#define NUM_FILES (argc - 1)

int main(int argc, char *argv[]) {
  if (NUM_FILES == 0) exit(0); 
  FILE *fp;//file pointer
  //open each file sequentially
  for (int i = 1; i <= NUM_FILES; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {//upon failure -  exit
      printf("my-cat: cannot open file\n");
      exit(1);
    }
    char buffer[BUFFER_SIZE];//buffer
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      printf("%s", buffer);
    }
  }
  fclose(fp);
  return 0;
}
  
