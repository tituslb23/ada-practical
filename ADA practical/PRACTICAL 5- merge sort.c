#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void Combine(int arr[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int leftArray[leftLength];
    int rightArray[rightLength];
    int i, j, k;

    for (i = 0; i < leftLength; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < rightLength; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    i = 0; j = 0; k = left;

    while (i < leftLength && j < rightLength) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftLength) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightLength) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = floor(left + right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);        
        Combine(arr, left, mid, right);
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

        MergeSort(input_array, 0, array_size - 1);

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

        MergeSort(input_array, 0, array_size - 1);

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

        MergeSort(input_array, 0, array_size - 1);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Worst Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);
    }
}
