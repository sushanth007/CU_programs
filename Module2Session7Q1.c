#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 1000

int main() {
    int total_nodes;
    scanf("%d",&total_nodes);
    int numbers[MAX] = {}; 
    for(int i=0;i<total_nodes;i++){
        scanf("%d",&numbers[i]);
    }
    for(int i=0;i<total_nodes;i++){
        printf("%d ",numbers[i]);
    }
	return 0;
}