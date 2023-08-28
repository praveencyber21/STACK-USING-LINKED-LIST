#include<stdio.h>
#include<stdlib.h>

 
struct Node {
	int data;
	struct Node* next;
	struct Node* top;
};


struct Node* head = NULL;
struct Node* top = NULL; 

void push(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	newNode -> data = data;
	
	if(top == NULL)
	{
		newNode -> next = NULL;
		top = newNode;
	}
	else
	{ 
		newNode -> next = top;
		top = newNode;
	}
	//Top pointer points the head node
//	top = head;
	printf("Data Inserted\n");
	
}

void pop()
{
	struct Node* temp = top;
	
	int popped;
	if(temp == NULL)
	{
		printf("Stack Underflow\n");
		return;
	}
	else
	{
		popped = temp -> data;
		top = temp -> next;
		free(temp);
		
	}
		printf("Poped Element is %d\n", popped);
}

void display()
{
	struct Node* temp = top;
	
	if(top == NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	else
	{
			while(temp != NULL)
		{
			printf("%d\n", temp -> data );
			temp = temp -> next;
			
		}
	}

}
int main()
{
	
	int choice, data;
	while(1)
	{
		printf("--------------STACK USING LINKED LIST MENU--------------\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("-----------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				push(data);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				display();
				break;
			
			case 4:
				exit(0);
				
			default:
				printf("Invalid Choice\n");
		}
	}
}
