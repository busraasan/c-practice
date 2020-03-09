#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE* fp;
  fp = fopen("textfile.txt", "w");
  char input[100];

  int lines = 0;
  printf("Enter the number of lines to be written: ");
  scanf("%d", &lines);
  printf("Enter the lines to be written: ");
  for(int i = 0; i <= lines; i++){
    fgets(input, sizeof input, stdin);
    fputs(input, fp);
  }
  fclose(fp);

  /-----readfile----/
  //newline'ı kim koyuyor read'e başlarken?

  FILE* fp2;
  fp2 = fopen("textfile.txt", "r");
  char read_inside;

  read_inside = fgetc(fp2);
  while(!feof(fp2)){
    printf("%c", read_inside);
    read_inside = fgetc(fp2);
  }
  fclose(fp2);

  return 0;
}
