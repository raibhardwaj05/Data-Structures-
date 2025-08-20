#include<stdio.h> 
#include<stdlib.h>

// structure to make a custom array (BLUEPRINT)
struct myArray{
    // total size to be reverved
    int total_size;

    // total size to be used
    int used_size;

    // int ptr pointing to the 1st element of the array
    int *element1_ptr;
};

// struct myArray *struct_add → means we pass the address of a struct variable
void createArray(struct myArray *struct_add, int tsize, int usize){

    // (*struct_add).total_size = tsize;
    // (*struct_add).used_size = usize;
    // (*struct_add).element1_ptr = (int *)malloc(tsize * sizeof(int));


    // ptr = malloc(N * sizeof(int)) → reserves space for N integers
    struct_add->total_size = tsize;
    struct_add->used_size = usize;
    struct_add->element1_ptr = (int *)malloc(tsize * sizeof(int));
    
}

void show(struct myArray *array){
    for(int i = 0; i < array->used_size; i++){
        printf("%d ", (array->element1_ptr)[i]);
    }
}

int main()
{   
    struct myArray marks;
    createArray(&marks, 10, 2);

    show(&marks);

    return 0;
}