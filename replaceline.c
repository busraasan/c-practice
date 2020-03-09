#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main(){

  char filename[20];
  printf("The name of the file to be opened: ");
  scanf("%s", filename);

  char input[200];
  printf("Enter the content of the new line: ");
  scanf("%s", input);

  int line = 0;
  printf("The name of the line to be changed: ");
  scanf("%d", &line);

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
      } else {
        fprintf(temp, "%s\n", input);
      }
    }
  }
  fclose(fp);
  fclose(temp);
  remove(filename);
  rename(tempfilename, filename);
  printf("Replacement is successfull.\n");
  return 0;
}
