#include <stdio.h>
#define MAX 100

int nums[MAX] = {3, 8, 3, 2, 4};
int n = 5;
int nums2[MAX] = {1, 4, 1, 2, 2};
int n2 = 5;


// Print all elements of the given array.
void print_all(int nums[], int length){
    for(int i=0; i<length; i++)
        printf("%d ", nums[i]);
    printf("\n");
}


// Find the subscript of the first element with value v.
int search(int nums[], int length, int v){
    for(int i=0; i<length; i++)
        if(nums[i] == v) return i;
    
    return -1;
}


// Insert the new element before element with subscript `i`.
int insert(int* nums, int length, int inserted_loc, int inserted_value){
    if(inserted_loc >= length) return -1;
    
    for(int i=length; i>inserted_loc; i--)
        nums[i] = nums[i-1];
        
    nums[inserted_loc] = inserted_value;
    return 0;
}


// Delete the element in the subscript `i`.
int delete(int* nums, int length, int deleted_loc){
    if(deleted_loc >= length) return -1;
    
    for(int i=deleted_loc; i<length; i++){
        nums[i] = nums[i+1];
    }
    
    return 0;
}


// append one array with another.
int join(int* nums1, int length1, int* nums2, int length2){
    for(int i=0; i<length2; i++)
        nums1[length1+i] = nums2[i];
    
    return 0;
}


int main(){
    join(nums, n, nums2, n2); n+=n2;
    print_all(nums, n);
}

