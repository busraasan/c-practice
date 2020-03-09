#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

void removeAll(char * str, const char * toRemove);

int main()
{
    FILE* fp;
    FILE* ftemp;
    char path[100];
    char filename[25];

    char toRemove[100];
    char buffer[1000];

    printf("Enter the source file: ");
    scanf("%s", filename);

    printf("Enter the word to remove: ");
    scanf("%s", toRemove);

    fp = fopen(filename, "r");
    ftemp = fopen("temp.txt", "w");

    if(fp == NULL || ftemp == NULL){
      printf("Could not open the file.\n");
      exit(EXIT_FAILURE);
    }

    while(fgets(buffer, BUFFER_SIZE, fp) != NULL){
      removeAll(buffer, toRemove);
      fputs(buffer, ftemp);
    }

    fclose(fp);
    fclose(ftemp);

    remove(filename);
    rename("temp.txt", filename);

    printf("All %s removed successfully.\n", toRemove);

    return 0;
}

void removeAll(char *str, const char *toRemove){

  int i, j, stringLen, toRemoveLen;
  int found;

  stringLen = strlen(str);
  toRemoveLen = strlen(toRemove);

  //her harfte (i) kaldırılacak kelimenin uzunluğu kadar(j) ilerleterek eşit mi diye bakıyoruz.
  for(i = 0; i <= stringLen; i++){

    found = 1;

    for(j = 0; j < toRemoveLen; j++){
      if(str[i + j] != toRemove[j]){
        found = 0;
        break;
      }
    }
    //kelime mi değil mi diye bakıyoruz ne ile bittiğine bakarak.
    if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') {
      found = 0;
    }

    if(found == 1){
      /* i = 0. j = 0. j <= kelimeyi attıktan sonra kalan satır uzunluğu.
      str[0] iken bulduğumuz kelimeyi str[toRemoveLen] yaparak atlıyoruz.
      Atladığımız için de stringLen'den gene toRemoveLen'i çıkarıyoruz.

      i -1 olunca bozuluyor.
      */

      //ANLAMADIM.
      for(j = i; j <= stringLen - toRemoveLen; j++){
        str[j] = str[j + toRemoveLen];
      }

      stringLen = stringLen - toRemoveLen;
      printf("%d\n", i);
      //matching next occurance of word from current index.
      i--;
      printf("%d\n", i);
    }
  }

}
