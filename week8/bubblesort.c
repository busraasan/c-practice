#include <stdio.h>
#define SIZE 5

void bubblesort(int array[], int type) {
		int temporary;
		for(int j = 0; j < SIZE; j++) {
			if (type == 1) {
				for(int i = 0; i < SIZE; i++){
					if(array[i]>array[i+1]){
						temporary = array[i+1];
						array[i+1] = array[i];
						array[i] = temporary;
					}
				}
			} else {
				for(int i = 0; i < SIZE; i++){
					if(array[i+1]<array[i]){
						temporary = array[i];
						array[i] = array[i+1];
						array[i+1] = temporary;
					}
				}
			}
		}
		for(int i = 0; i < SIZE; i++){
			printf("%d\n", array[i]);
		}
		
}

int main() {
	
	int array[SIZE] = {6, 5, 8, 4, 0};
	bubblesort(array, 1);
	return 0;
}