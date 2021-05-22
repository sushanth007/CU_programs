#include <stdio.h>
#include <stdlib.h>
int linearsearch ( int a[ ], int size, int n );
int main(){
    int num,i,pos,key;
    scanf("%d",&num);
	int arr[ num ];
    for ( i = 0 ; i < num ; i++ )
	scanf("%d",&arr[i]);

    scanf("%d",&key);
    pos = linearsearch ( arr, num, key ) ;
	if ( pos == -1 )
		printf ( "Number not found in array\n" ) ;
	else
		printf ( "%d\n", pos ) ;

        return 0;
}

int linearsearch(int a[], int size, int n){
    for(int i=0;i<size;i++){
        if(a[i] == n){
            return i;
        }
    }
    return -1;
}