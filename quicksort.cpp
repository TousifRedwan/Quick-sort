#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int intArray[MAX];
void input(int c)
{
    int i;
    for (i=0;i<c;i++)
    {
        scanf("%d", &intArray[i]);
    }
}

void printline(int count) {
   int i;

   for(i = 0;i < count-1;i++) {
      printf("=");
   }

   printf("=\n");
}

void display(int c) {
   int i;
   printf("[");

   // navigate through all items
   for(i = 0;i < c;i++) {
      printf("%d ",intArray[i]);
   }

   printf("]\n");
}

void swap(int num1, int num2) {
   int temp = intArray[num1];
   intArray[num1] = intArray[num2];
   intArray[num2] = temp;
}

int partition(int left, int right, int pivot,int c) {
   int leftPointer = left -1;
   int rightPointer = right;

   while(true) {
      while(intArray[++leftPointer] < pivot) {
         //do nothing
      }

      while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
         //do nothing
      }

      if(leftPointer >= rightPointer) {
         break;
      } else {
         printf(" item swapped :%d,%d\n", intArray[leftPointer],intArray[rightPointer]);
         swap(leftPointer,rightPointer);
      }
   }

   printf(" pivot swapped :%d,%d\n", intArray[leftPointer],intArray[right]);
   swap(leftPointer,right);
   printf("Updated Array: ");
   display(c);
   return leftPointer;
}

void quickSort(int left, int right,int c) {
   if(right-left <= 0) {
      return;
   } else {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot,c);
      quickSort(left,partitionPoint-1,c);
      quickSort(partitionPoint+1,right,c);
   }
}

int main() {
    int num;
     printf("Input numbers of the array: ");
    scanf("%d",&num);
   printf("Input Array: ");
   input(num);
   display(num);
   printline(50);
   quickSort(0,num-1,num);
   printf("Output Array: ");
   display(num);
   printline(50);
}
