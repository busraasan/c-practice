#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 128
#define RSIZE 10

int main(){

  FILE* fp;
  char filename[20];
  char line[RSIZE][LSIZE];
  int i = 0;

  printf("Enter the file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  while(fgets(line[i], LSIZE, fp)){
    line[i][strlen(line[i]) - 1] = '\0';
    i++;
  }

  printf("The contents of the file are: \n");
  for(int j = 0; j < i; j++){
    printf("%s\n", line[j]);
  }
  printf("\n");
  fclose(fp);
  return 0;
}
