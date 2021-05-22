#include <stdio.h>
#include <stdlib.h>

// Only add this function contents
void sortIncDec(int arr[],int n){
	// START //
	int array_div = n / 2;
	int a, b;
	int even_array_length, odd_array_length;
	if(n % 2 != 0){
		even_array_length = array_div + 1;
		odd_array_length = array_div;
	}else{
		even_array_length = array_div;
		odd_array_length = array_div;
	}
	int even[even_array_length];
	int odd[odd_array_length];
	int even_count = 0, odd_count = 0;
	for(int i=0;i<n;i++){
		if(i % 2 == 0){
			even[even_count] = arr[i];
			even_count++;
		}else{
			odd[odd_count] = arr[i];
			odd_count++;
		}
	}
	for(int i=0;i<even_array_length;++i){
		for(int j=i+1;j<even_array_length;++j){
			if(even[i] > even[j]){
				a = even[i];
				even[i] = even[j];
				even[j] = a;
			}
		}
	}

	for(int i=0;i<even_array_length;i++){
		printf("%d ",even[i]);
	}

	for(int i=0;i<odd_array_length;++i){
		for(int j=i+1;j<odd_array_length;++j){
			if(odd[i] < odd[j]){
				b = odd[i];
				odd[i] = odd[j];
				odd[j] = b;
			}
		}
	}
	for(int i=0;i<odd_array_length;i++){
		printf("%d ",odd[i]);
	}
	// END //
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sortIncDec(arr,n);
}