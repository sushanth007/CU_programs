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
void display_list(struct node *start);
struct node *insert_into_empty(struct node *start, int element);

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
    display_list(start);
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

void display_list(struct node *start){
    struct node *p = start;
    if(p == NULL){
        printf("\nList is empty.");
    }else{
        while(p != NULL){
            printf("%d ",p->data);
            p = p->next;
        }
    }
    printf("\n");
}