#include <stdio.h>

void insertSorted(float bucket[], int *size, float value) 
{
    int i = *size - 1;
    while(i>=0 && bucket[i]>value)
    {
        bucket[i+1]=bucket[i];
        i--;
    }
    bucket[i+1]=value;
    (*size)++;
}

void bucketSort(float arr[], int n) 
{
    float buckets[n][n];
    int bucketSizes[n];
    for(int i=0;i<n;i++) bucketSizes[i]=0;

    for(int i=0;i<n;i++)
    {
        int index=n*arr[i];
        insertSorted(buckets[index], &bucketSizes[index], arr[i]);
    }

    int idx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<bucketSizes[i];j++)
        {
            arr[idx++]=buckets[i][j];
        }
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    float arr[n];
    printf("Enter %d elements (0<=value<1):\n",n);
    for(int i=0;i<n;i++) scanf("%f",&arr[i]);

    bucketSort(arr,n);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%.2f ",arr[i]);
    printf("\n");
    return 0;
}
