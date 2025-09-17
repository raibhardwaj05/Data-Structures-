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
	printf("\n");
	
	return top;
}

void stacktop(node *top){
	
	if(top == NULL){
		printf("\nStack Empty\n");
	}
	else{
		printf("\n%d", top->data);
	}
	
}

void stackEmpty(node *top){
	
	if(top == NULL){
		printf("\nStack Empty\n");
	}
	else{
		printf("\nNot Empty\n");
	}
	
}

void display(node *top){
	node *temp;
	
	if(top == NULL){
		printf("\nStack Empty\n");
	}
	else{
		temp = top;
		while(temp != NULL){
			printf("\n%d", temp->data);
			temp = temp->prev;
		}
	}
}

void main(){
	node *top;
	top = NULL;
	int choice, con = 1;
	
	while(con == 1){
		printf("\n1.push\n2.pop\n3.stack top\n4.stack empty\n5.display\nYour choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				top = push(top);
				break;
			
			case 2:
				top = pop(top);
				break;
			
			case 3:
				stacktop(top);
				break;
				
			case 4:
				stackEmpty(top);
				break;
				
			case 5:
				display(top);
				break;
				
			default:
				printf("\nDo you want to continue? (0/1): )");
				scanf("%d", &con);
				break;
		}
	}
}
