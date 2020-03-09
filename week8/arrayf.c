#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

void calculateCumulativeAverage(double exchange_rate[], double cumulative_average[], int size) {
	double total = 0;
	for(int i = 0; i < size; i++) {
		total += exchange_rate[i];
		cumulative_average[i] = total/(i+1);
	}
}

void calculateMovingAverage(double exchange_rate[], double moving_average[], int moving_average_size) {
	for(int i = 0; i < moving_average_size; i++){
		moving_average[i] = 0;
	}
	for (int i = moving_average_size - 1; i <size; i++) {
		double sub_total = 0;
		for (int j = i; j > i - moving_average_size; j--) {
			sub_total += moving_average[j];
		}
		moving_average[i] = sub_total / moving_average_size;
	}
}

/*double movingAv()
int main() {
	
	printf("Enter data:\n");
	double data[SIZE];
	double av;
	for(int i = 0; i < SIZE; i++){
		scanf("%lf", &data[i]);
	}
	av = movingAv(double data[SIZE]);
	return 0;
}

void movingAv(double moving_average[SIZE]) {
	
	for(int i = 0; ,i < MOVING_SIZE - 1; i++) {
		moving_average[i] = 0;
	}
	for(int i = MOVING_SIZE -1; i < SIZE; i++) {
		double sub_total = 0;
		for(int j = i; j > i - MOVING_SIZE; j--) {
			sub_total = sub_total + data[j];
		}
		moving_average[i] = sub_total / MOVING_SIZE;
	}
	printf("Moving Averages:\n");
	for (int i = 0; i < SIZE; i++){
		printf("%d : %lf", i, moving_average[i]);
	}
	
} */
