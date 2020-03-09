#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE* fp;
  char read_inside;
  char filename[20];

  printf("Enter the filename: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");

  if(fp == NULL){
    printf("Error in file opening.\n");
    exit(EXIT_FAILURE);
  }
  //fscanf(fp, "%s", read_inside); reads until space.
  //fread(read_inside, sizeof(read_inside), 1, fp); //bunu sor, sonda iki random sayı veriyor.
  //printf("%s\n", read_inside);

  read_inside = fgetc(fp);
  while(!feof(fp)){
    printf("%c", read_inside);
    read_inside = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
