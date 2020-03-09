#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE* fp;
  fp = fopen("numberoflines.txt", "r");

  if(fp == NULL){
    printf("Could not open the file.\n");
    exit(EXIT_FAILURE);
  }

  int ctr = 0;
  char c;
  for(c = getc(fp); !feof(fp); c = getc(fp)){
    if(c == '\n'){
      ctr++;
    }
  }
  printf("%d\n", ctr);

/-----kendi kodum, pointerı başa getirerek-----/

  fseek(fp, 0, SEEK_SET);
  int counter = 0;
  char read_into[100];

  while(!feof(fp)){
    fgets(read_into, sizeof(read_into), fp);
    counter++;
  }

  fclose(fp);
  printf("%d\n", counter-1);
  return 0;
}
