#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct MaxHeap {
    int size;
    int* array;
};

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b;  
    *b = t; 
}

void maxHeapify(struct MaxHeap* maxHeap, int idx) {
    int largest = idx; 
    int left = (idx << 1) + 1;  
    int right = (idx + 1) << 1; 

    if (left < maxHeap->size &&
        maxHeap->array[left] > maxHeap->array[largest])
        largest = left;

    if (right < maxHeap->size &&
        maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}

struct MaxHeap* createAndBuildHeap(int *array, int size) {
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size; 
    maxHeap->array = array; 

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

void heapSort(int* array, int size) {
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;

        maxHeapify(maxHeap, 0);
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

        heapSort(input_array, array_size);

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

        heapSort(input_array, array_size);

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

        heapSort(input_array, array_size);

        gettimeofday(&ending_time, NULL);

        net_time_taken = (ending_time.tv_sec - starting_time.tv_sec) * 1e6;
        net_time_taken = (net_time_taken + (ending_time.tv_usec - 
                                starting_time.tv_usec)) * 1e-6;

        printf("Worst Case Scenario for %d Elements is %lf Milli Seconds\n", array_size, net_time_taken*1000);
    }
}
