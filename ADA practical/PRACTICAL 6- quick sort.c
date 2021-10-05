#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition (int arr[], int start, int end) { 
    int pivot = arr[end];  
    int i = (start - 1); 
    for (int j = start; j <= end - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1); 
} 

void QuickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = Partition(arr, start, end);

        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
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

        QuickSort(input_array, 0, array_size - 1);

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

        QuickSort(input_array, 0, array_size - 1);

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

        QuickSort(input_array, 0, array_size - 1);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Worst Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);
    }
}
