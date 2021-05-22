#include <stdio.h>
#include <stdlib.h>

int binarysearch ( int a[ ], int size, int key ) ;
int cmpfunc (const void * a, const void * b);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main( )
{
    int num,i,pos,key;

    scanf("%d",&num);
	int arr[ num ];

    for ( i = 0 ; i < num ; i++ )
	scanf("%d",&arr[i]);

    scanf("%d",&key);
	
              // Sort the array
    qsort(arr,num,sizeof(int),cmpfunc);
	// Printing the sorted array
	for ( i = 0 ; i < num ; i++ )
		printf ( "%d ", arr[ i ] ) ;
	printf ( "\n" ) ;
	

	// Perform binary search
             pos = binarysearch ( arr, num, key ) ;
	if ( pos == -1 )
		printf ( "Number not found in array\n" ) ;
	else
		printf ( "%d\n", pos ) ;

	return 0 ;
}

int binarysearch ( int arr[ ], int size, int key ){
    int l = 0;
    int r = size-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}