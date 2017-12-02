
#include <stdio.h>
#include <stdlib.h>

void Swap(int * list, int firstIndex, int secondIndex) {
 int temp;
 temp = list[firstIndex];
 list[firstIndex] = list[secondIndex];
 list[secondIndex]= temp;
}

int Partition(int * list, int start, int end) {

 int pIndex = start;
 int pivot = list[end];
 int i,temp;

 for(i=start;i<end;i++) {
    if(list[i] <= pivot) {
        Swap(list,i,pIndex);
        pIndex++;
    }
 }

 Swap(list,pIndex,end);
 return pIndex;

}

void QuickSort(int * list, int start, int end) {

 if(start<end) {
     int pIndex = Partition(list,start,end);

     QuickSort(list,start,pIndex-1);
     QuickSort(list,pIndex+1,end);
 }
}

void Merge(int *list,int *left,int leftLen,int * right,int rightLen) {

 int i,j,k;
 i = j = k = 0;
 
 while(i < leftLen && j < rightLen) {
     if(left[i] <= right[j]) {
         list[k++] = left[i++];
     } else { 
         list[k++] = right[j++];
     }
 }
 while (i<leftLen) list[k++] = left[i++];
 while (j<rightLen) list[k++] = right[j++];

}



void MergeSort(int *list,int n) {

 if(n/2 >0){
     int mid = n/2;
  
     int * left = (int *) malloc(mid*sizeof(int));
     int * right = (int *) malloc((n-mid)*sizeof(int));
 
     for(int i=0;i<mid;i++) left[i] = list[i];
     for(int i = mid;i<n;i++) right[i-mid] = list[i];

     MergeSort(left,mid);
     MergeSort(right,n-mid);
 
    Merge(list,left,mid,right,n-mid);
 }

}


int main() {

 int sort_list[10];
 for(int i=0; i<10; i++) {
     printf("\nEnter your number for the list\n");
     scanf("%d",&sort_list[i]);
 }

 //MergeSort(sort_list,10);

 QuickSort(sort_list,0,9);
 for(int i=0; i<10; i++) {
     printf(" %d ",sort_list[i]);
 }
 printf("\n");

}
