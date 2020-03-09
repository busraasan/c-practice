#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 25

bool check_num(char input[]);
void fix_num(char digits[]);

int main(){

  char input[MAX];
  printf("Enter the number: ");
  scanf("%s", input);

  fix_num(input);
  printf("%d\n", check_num(input));
  return 0;
}

bool check_num(char input[]){

  int size = strlen(input);
  int total = 0;

  for(int i = size; i>0; i--){
    if(i%2 == 1){
      total += (int)input[i] - '0';
    } else {
      if((int)input[i] - '0' < 5){
        total += ((int)input[i] - '0')*2;
      } else {
        total += ((int)input[i] - '0')*2 - 9;
      }
    }
  }
  printf("%d\n", total);
  if(total%10 == 0){
    return true;
  } else {
    return false;
  }
}

int fix_num(char num[]){
  int unknown; //soru işaretini tutan karakter.
  int size = strlen(num);
  int sum = 0;
  for(int i = size; i>0; i--){
    if(num[i] == '?'){
      unknown = i;
      continue;
    }
    if(i%2 == 1){
      sum += (int)num[i] - '0';
    } else {
      if((int)num - '0' < 5){
        sum += ((int)num[i] - '0')*2;
      } else {
        sum += ((int)num[i] - '0')*2 - 9;
      }
    }
  }

  if(total%10 == 0){
    return 0;
  } else {

    int sum2 = (sum/10)*10 + 10; //toplamın bi üstündeki 10a bölünen sayıya eşitliyoruz.

    if((size-unknown)%2 == 1){
      return (sum2-sum+9) / 2;
    } else {
      return (sum2-sum) / 2;
    }
  }

} //end of fix_num
