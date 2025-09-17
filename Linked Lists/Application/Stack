#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
}node;

node *push(node *top){
	node *newnode;
	int items;
	
	printf("\nHow many items?: ");
	scanf("%d", &items);
	
	while(items > 0){
		newnode = (node*)malloc(sizeof(node));
		newnode->prev = NULL;
		printf("\n Enter the data: ");
		scanf("%d", &newnode->data);
		
		if(top == NULL){
			top = newnode;
		}
		else{
			newnode->prev = top;
			top = newnode;			
		}
		
		items--;
	}
	
	return top;
}

node *pop(node *top){
	node *temp;
	
	printf("\nPOP elements\n");
	
	if(top == NULL){
		printf("\nStack Empty\n");
	}
	else{
		temp = top;
		printf("%d\n", top->data);
		top = top->prev;
		
		free(temp);
	}
	
	return top;
}

void stacktop(node *top){
	
}

void main(){
	node *top;
	top = NULL;
	
	top = push(top);
	top = pop(top);
	top = pop(top);
}
