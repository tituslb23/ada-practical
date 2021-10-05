#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int BinarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = floor((high + low)/2);
        if (key == arr[mid]) {
            return mid;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(void) {

    int test_cases_size[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

    for (int t = 0; t < 7; t++) {
        int array_size = test_cases_size[t];
        int input_array[array_size];
        for (int i = 0; i < array_size; i++){
            input_array[i] = i;          
        }

        //Best Case Scenario
        int key = input_array[0];

        struct timeval starting_time, ending_time;
        gettimeofday(&starting_time, NULL);

        BinarySearch(input_array, array_size, key);
    
        gettimeofday(&ending_time, NULL);

        double net_time_taken;
        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Best Case Scenario for %d Elements is %lf Micro Seconds\n", array_size, net_time_taken);

        //Average Case Scenario
        key = input_array[rand()%array_size];

        gettimeofday(&starting_time, NULL);

        BinarySearch(input_array, array_size, key);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Average Case Scenario for %d Elements is %lf Micro Seconds\n", array_size, net_time_taken);

        //Worst Case Scenario
        key = array_size + 1;
    
        gettimeofday(&starting_time, NULL);

        BinarySearch(input_array, array_size, key);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Worst Case Scenario for %d Elements is %lf Micro Seconds\n", array_size, net_time_taken);

    }
	return 0;
}
