#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition_first(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1,j=high;
    while(i<=j){
        while(i<=high && a[i]<=pivot) i++;
        while(a[j]>pivot) j--;
        if(i<j) swap(&a[i],&a[j]);
    }
    swap(&a[low],&a[j]);
    return j;
}

int partition_last(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

int partition_random(int a[],int low,int high){
    int r=low+rand()%(high-low+1);
    swap(&a[r],&a[high]);
    return partition_last(a,low,high);
}

void quick_first(int a[],int low,int high){
    if(low<high){
        int p=partition_first(a,low,high);
        quick_first(a,low,p-1);
        quick_first(a,p+1,high);
    }
}

void quick_last(int a[],int low,int high){
    if(low<high){
        int p=partition_last(a,low,high);
        quick_last(a,low,p-1);
        quick_last(a,p+1,high);
    }
}

void quick_random(int a[],int low,int high){
    if(low<high){
        int p=partition_random(a,low,high);
        quick_random(a,low,p-1);
        quick_random(a,p+1,high);
    }
}

int main(){
    printf("ch.sc.u4cse24149\n");
    int n,choice;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&choice);
    srand(time(0));
    if(choice==1) quick_first(a,0,n-1);
    else if(choice==2) quick_last(a,0,n-1);
    else if(choice==3) quick_random(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

