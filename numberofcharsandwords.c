#include <stdio.h>
#include <stdlib.h>

int main(){

  char filename[20];
  printf("The name of the file to be opened: ");
  scanf("%s", filename);

  FILE* fp;
  fp = fopen(filename, "r");

  char read_inside;
  int counter = 0;
  int word = 0;
  while(!feof(fp)){
    if(read_inside == ' ' || read_inside == '\n'){
      word++;
    } else {
      counter++;
    }
    read_inside = fgetc(fp);
  }
  fclose(fp);
  printf("The number of characters: %d\n", counter-1);
  printf("The number of words: %d\n", word);
  return 0;
}
