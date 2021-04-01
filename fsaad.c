#include <stdio.h>
#include <stdbool.h>
 
#define MAX 10
 
int arr[MAX] = {6, 7, 0, 2, 8, 1, 3, 9, 4, 5};
 
// ham de trao doi gia tri
void swap(int num1, int num2){
    int temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
}
 
// ham de chia mang thanh 2 phan, su dung phan tu chot (pivot)
int partition(int left, int right, int pivot){
    int leftPointer = left -1;
    int rightPointer = right;
 
    while(true){
 
        while(arr[++leftPointer] < pivot){
            //khong lam gi
        }
 
        while(rightPointer > 0 && arr[--rightPointer] > pivot){
            //khong lam gi
        }
 
        if(leftPointer >= rightPointer){
            break;
        }else{
            printf(" Phan tu duoc trao doi :%d,%d\n", 
            arr[leftPointer],arr[rightPointer]);
            swap(leftPointer,rightPointer);
        }
 
    }
 
    printf(" Phan tu chot duoc trao doi :%d, %d\n", arr[leftPointer],arr[right]);
    swap(leftPointer,right);
    printf("Mang sau moi lan trao doi: "); 
    display();
    return leftPointer;
}
 
// ham sap xep
void quickSort(int left, int right) {
    if(right-left <= 0){
        return;
    } else {
        int pivot = arr[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left, partitionPoint-1);
        quickSort(partitionPoint+1, right);
    }
}
 
void display() {
     int i;
     printf("[");
 
     // Duyet qua tat ca phan tu
     for(i = 0; i < MAX; i++){
          printf("%d ", arr[i]);
     }
 
     printf("]\n");
}
 
main() {
    printf("Mang du lieu dau vao: ");
    display();
    printf("-----------------------------\n");
    quickSort(0, MAX-1);
    printf("-----------------------------\n");
    printf("Mang sau khi da sap xep: ");
    display();
}
