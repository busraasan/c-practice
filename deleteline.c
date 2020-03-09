#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main(){

  char filename[20];
  printf("The name of the file to be opened: ");
  scanf("%s", filename);

  int line = 0;
  printf("The name of the line to be removed: ");
  scanf("%d", &line);
  //bak linelar 1 2 3 diye gidiyor dikkat et. line++ yapma. Sen sayıyosun ya en başından tabi counter ile o yüzden.

  FILE* fp;
  fp = fopen(filename, "r");
  FILE* temp;
  char tempfilename[] = "temporary.txt";
  temp = fopen(tempfilename, "w");

  if(fp == NULL){
    printf("Could not open the temporary file.\n");
    exit(EXIT_FAILURE);
  }
  if(temp == NULL){
    printf("Coult not open the temporary file.\n");
    exit(EXIT_FAILURE);
  }

  int counter = 0;
  char read_into[MAX];
  while(!feof(fp)){
    strcpy(read_into, "\0"); //bunu koymak bir şeyi değiştirmiyor neden koyduk?
    fgets(read_into, MAX, fp);
    if(!feof(fp)){
      counter++;
      if(counter != line){ //istediğimiz line dışındakileri temporary dosyaya yazdırıyoruz.
        fprintf(temp, "%s", read_into);
      }
    }
  }
  fclose(fp);
  fclose(temp);
  remove(filename);
  rename(tempfilename, filename);

  /---read the file into std output---/

  fp = fopen(filename, "r");
  char read_into2;
  read_into2 = fgetc(fp);
  printf("The content of the file is now: \n");
  while(!feof(fp)){
    printf("%c", read_into2);
    read_into2 = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
