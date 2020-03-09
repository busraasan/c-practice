#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE* fp;
  char input[1000];
  printf("Enter the input which will written in test.txt: ");
  fgets(input, sizeof input, stdin);
  fp = fopen("test.txt", "w");
  if(fp == NULL){
    printf("Error in opening file.\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fp, "%s", input);
  fclose(fp);
  return 0;
}
