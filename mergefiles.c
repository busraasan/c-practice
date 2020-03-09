#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(){

  char file1[20];
  printf("The name of the first file: ");
  scanf("%s", file1);

  char file2[20];
  printf("The name of the second file: ");
  scanf("%s", file2);

  FILE* fp;
  fp = fopen(file1, "r");

  FILE* fp2;
  fp2 = fopen(file2, "r");

  FILE* fpm;
  fpm = fopen("mergefiles.txt", "w");

  char read_into[MAX];
  while(!feof(fp)){
    fgets(read_into, MAX, fp);
    if(!feof(fp))
      fprintf(fpm, "%s", read_into);
  }

  char read_into2[MAX];
  while (!feof(fp2)) {
    fgets(read_into2, MAX, fp2);
    if(!feof(fp2))
      fprintf(fpm, "%s", read_into2);
  }

  fclose(fp);
  fclose(fp2);
  fclose(fpm);

  printf("The content of the file mergefiles.txt is: \n");

  fpm = fopen("mergefiles.txt", "r");
  char read_into3;
  read_into3 = fgetc(fpm);
  while(read_into3 != EOF){
    printf("%c", read_into3);
    read_into3 = fgetc(fpm);
  }

  return 0;
}
