/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>

typedef struct
{
    int id;
    char name[10];
    int price;
}book;

book b1[10];

int cmpprice(const void *a, const void *b)
{
    book *ia = (book *)a;
    book *ib = (book *)b;
    return strcmp(ia->name, ib->name);
}


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] >= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
void printArray(int A[], int size) 
{ 
    int i,j; 
    for (i = 0; i < size; i++) 
    {
        printf("\nprice: %d ", A[i]);
        for (j = 0; j < 10; j++)
        {
            if(A[i] == b1[j].price)
            printf("\tId: %d \tName: %s", b1[j].id, b1[j].name);
        }        
    }    

    printf("\n"); 
} 
  
int main(void)
{
    int temp[10]={};
    int i;
    
    printf("Enter Details of all the books: \n");
    for ( i = 0; i < 10; i++)
    {
        printf("\nEnter id:");
        scanf("%d", &b1[i].id);

        printf("Enter name:");
        scanf("%s", &b1[i].name);

        printf("Enter price:");
        scanf("%d", &temp[i]);
    }
    
    for (i = 0; i < 10; i++)
    {
        b1[i].price = temp[i];
    }

    mergeSort(temp, 0, 9);

    printf("\nSorted array using \"MERGE SORT\" is \n");
    printArray(temp, 10);

    
    qsort(b1, 10, sizeof(book), cmpprice);
    
    printf("\nSorted array using \"QUICK SORT\" is \n");
    for (i = 0; i < 10; i++)
    {
        printf("\nPrice: %d \tId: %d \tName: %s ", b1[i].price, b1[i].id, b1[i].name );
    }

    return 0;
}