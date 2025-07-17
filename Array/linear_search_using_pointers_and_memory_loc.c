/*
These types of memory loc based linear search is used in resource constrain systems like embedded systems, device drivers, etc
where there is limited presence of memory.
*/
#include<stdio.h>

void LinearSearch(int *arr_ptr, int sensor, int size){
    int *end_ptr = arr_ptr + size; //arr_ptr points to an int, and size is an int. 
    //So, arr_ptr + size means: "move the pointer size number of int sizes forward from the address arr_ptr currently holds."
    while (arr_ptr < end_ptr)
    {
        if (*arr_ptr == sensor)
        {
            printf("Success at loc %p \n", (void *)&arr_ptr);
            return;
        }
        arr_ptr++;
    }
    printf("Unsuccessful\n");
}

int main(){
    int sensorID[] = {001,002,003,004,005,006};
    int search_sensor = 3;
    int total_sensors = sizeof(sensorID)/sizeof(sensorID[0]);
    LinearSearch(sensorID, search_sensor, total_sensors);
    return 0;
}