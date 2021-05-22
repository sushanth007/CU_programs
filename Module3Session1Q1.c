#include<stdio.h>
int maxSubArraySum(int array[], int start, int size);

// Copy this Function only
int maxSubArraySum(int array[], int start, int size){
    int m=0,l=0;
    
    int largest=array[0];
    for(int i=0;i<=size;i++)
    {
        int sum=0;
        for(int j=i;j<=size;j++)
        {
            sum=sum+array[j];
            if(sum>largest)
            {
                m=i;l=j;
                largest=sum;
            }
        }
    }
    printf("%d",largest);
}

// Function end

int main()
{
    int size,m=0,l=0;
 
    printf("Type the length of the array\n");
    scanf("%d",&size);
    int array[size];
    printf("type the elements of the array\n");
 
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
 
    }
    maxSubArraySum(array,0,size-1);
 
    // int largest=array[0];
    // for(int i=0;i<size;i++)
    // {
    //     int sum=0;
    //     for(int j=i;j<size;j++)
    //     {
    //         sum=sum+array[j];
    //         if(sum>largest)
    //         {
    //             m=i;l=j;
    //             largest=sum;
    //         }
    //     }
    // }
 
    // printf("\n The largest contigous subarray is");
    // for(int z=m;z<=l;z++)
    // {
    //     printf(" %d ",array[z]);
    // }
    // printf("\n The sum of the largest contigous subarray is");
    // printf(" %d",largest);
    return 0;
}