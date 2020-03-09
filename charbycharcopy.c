#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(){

  char sourcefile[20];
  printf("The name of the source file: ");
  scanf("%s", sourcefile);

  char copiedfile[20];
  printf("The name of the copy file: ");
  scanf("%s", copiedfile);

  FILE* fp;
  fp = fopen(sourcefile, "r");

  FILE* fp2;
  fp2 = fopen(copiedfile, "w");

  char read_into;
  while(1){
    read_into = fgetc(fp);
    if(read_into == EOF){
      break;
    } else {
      fputc(read_into, fp2);
    }
  }
  printf("The file %s copied successfully into %s.\n", sourcefile, copiedfile);
  return 0;
}
