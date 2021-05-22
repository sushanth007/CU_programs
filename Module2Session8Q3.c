#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_end(struct node *start, int element);
struct node *insert_into_empty(struct node *start, int element);
int minimum(struct node *start,int n);
int count_nodes(struct node *start);
int getJ_Element(struct node *start, int j);

int main() {
    struct node *start = NULL;
    int n, a = 0, b = 1, sum = 0;
    int counter = 0;
    scanf("%d",&n);
    while(sum <= n){
        counter = counter + 1;
        if(counter == 1){
            start = insert_into_empty(start, sum);
        }else{
            insert_at_end(start, sum);
        }
        a = b;
        b = sum;
        sum = a + b;
    }
    int getMinimum = minimum(start,n);
    printf("%d",getMinimum);
	return 0;
}

void insert_at_end(struct node *start, int element){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = start;
    while(p->next != NULL){
        p = p->next;
    }
    temp->next = NULL;
    temp->data = element;
    p->next = temp;
}

struct node *insert_into_empty(struct node *start, int element){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;
    start = temp;
    return start;
}

int count_nodes(struct node *start){
    struct node *temp = start;
    int counter = 0;
    while(temp != NULL){
        counter = counter + 1;
        temp = temp->next;
    }
    return counter;
}

int getJ_Element(struct node *start, int j){
    struct node *temp = start;
    for(int i=1;i<=j;i++){
        temp = temp->next;
    }
    return temp->data;
}

int minimum(struct node *start,int n){
    int size = count_nodes(start);
    int count = 0, j = size-1;
    int j_element;
    while(n > 0){
        j_element = getJ_Element(start, j);
        count += (n / j_element);
        n %= (getJ_Element(start, j));
        j--;
    }
    return count;
}
