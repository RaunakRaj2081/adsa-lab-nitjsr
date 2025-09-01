#include <stdio.h>

int getBit(int num,int bit){ return (num>>bit)&1; }

void radixExchangeSort(int arr[], int low, int high, int bit)
{
    if(low>=high || bit<0) return;
    int i=low,j=high;

    while(i<=j)
    {
        while(i<=j && getBit(arr[i],bit)==0) i++;
        while(i<=j && getBit(arr[j],bit)==1) j--;
        if(i<j)
        {
            int temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    radixExchangeSort(arr,low,j,bit-1);
    radixExchangeSort(arr,j+1,high,bit-1);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n],max;
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    max=arr[0];
    for(int i=1;i<n;i++) if(arr[i]>max) max=arr[i];

    int bits=0;
    while(max>>bits) bits++;

    radixExchangeSort(arr,0,n-1,bits-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
