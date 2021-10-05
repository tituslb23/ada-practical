#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void BubbleSort(int input_array[], int arra_size) {
	for (int i = 0; i < arra_size; i++) {
		int break_condtition = 0;
		for (int j = 0; j < arra_size; j++) {
			if (input_array[j] > input_array[j + 1]) {
				int temp = input_array[j];
				input_array[j] = input_array[j + 1];
				input_array[j + 1] = temp;
				break_condtition = 1;
			}
		}
		if (break_condtition == 0) {
			break;
		}
	}    
}

int main(void) {

    int test_cases_size[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

    for (int t = 0; t < 7; t++) {
        int array_size = test_cases_size[t];
        int input_array[array_size];

        //Best Case Scenario
        for (int i = 0; i < array_size; i++){
            input_array[i] = i;     
        }

        struct timeval starting_time, ending_time;
        gettimeofday(&starting_time, NULL);

        BubbleSort(input_array, array_size);

        gettimeofday(&ending_time, NULL);

        double net_time_taken;
        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Best Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);

        //Average Case Scenario
        for (int i = 0; i < array_size; i++){
            input_array[i] = rand()%array_size;     
        }

        gettimeofday(&starting_time, NULL);

        BubbleSort(input_array, array_size);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Average Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);
    
        //Worst Case Scenario
        for (int i = 0; i < array_size; i++){
            input_array[i] = array_size-i;     
        }

        gettimeofday(&starting_time, NULL);

        BubbleSort(input_array, array_size);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Worst Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);
    }
}
