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

  char read_into[1000];
  while(!feof(fp)){
    fgets(read_into, MAX, fp);
    if(!feof(fp)) //when i dont put this last line occurs twice.
      fprintf(fp2, "%s", read_into);
  }

  printf("The file %s copied successfully into %s.\n", sourcefile, copiedfile);
  return 0;
}
