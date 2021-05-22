#include <stdio.h>
#include <stdlib.h>

int getLinearSearchUnsuccessfulComparisonCount(int* inputArr, int key, int size){
	// COPY START
	int count = 0;
	for(int i=0;i<size;i++){
		if(inputArr[i] == key){
			return count;
		}else{
			count++;
		}
	}
	return count;

	// COPY END 
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int key;
	scanf("%d",&key);
	int result = getLinearSearchUnsuccessfulComparisonCount(arr, key, size);
	printf("%d",result);
	return 0;
}