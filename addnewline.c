#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(){

  char filename[20];
  printf("The name of the file to be opened: ");
  scanf("%s", filename);

  int lines = 0;
  printf("Enter the lines to be written: ");
  scanf("%d", &lines);

  FILE* fp;
  fp = fopen(filename, "a+");

  /---taking input---/

  printf("Enter the input: ");
  char input[MAX] = "\0";
  for(int i = 0; i <= lines; i++){ //burada neden <= yaptık ya, 4 kere olmadı mı şimdi loop?
    fgets(input, sizeof input, stdin);
    fprintf(fp, "%s", input);
    //fputs(input, fp); bunu da kullanabilirsin.
    //fwrite(input, sizeof input, 1, fp); yazacağım şeyin gerçek boyutunu bilmem gerekiyor.
  }
  fclose(fp);

  /---read the updated file---/

  fp = fopen(filename, "r");
  printf("The new content of the file:\n");
  char read_into;

  read_into = fgetc(fp);
  while(!feof(fp)){
    printf("%c", read_into);
    read_into = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
