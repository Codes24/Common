#ifndef STACK_H
#define STACK_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node
{
	char* command;
	struct node* nextNode;
}node;

typedef struct stack
{
	struct node* tail;
	struct node* head;
	int size;
	int currentSize;
}stack;

stack* setupStack()
{
	stack* s = malloc(sizeof(stack));
	s->size = 10;
	s->currentSize = 0;
	s->tail = NULL;
	s->head = NULL;
	return s;
}

void push(stack* s, const char* cmd)
{
	if (s->head == NULL)
	{
		node* n = malloc(sizeof(node));
		n->command = malloc(100);
		strcpy(n->command, cmd);
		n->nextNode = NULL;
		s->head = n;
		s->tail = n;
		s->currentSize++;
	}
	else
	{
		node* n = malloc(sizeof(node));
		n->command = malloc(100);
		strcpy(n->command, cmd);
		n->nextNode = NULL;
		s->tail->nextNode = n;
		s->tail = n;
		s->currentSize++;
		if (s->currentSize > 10)
		{
			node* newHead = s->head->nextNode;
			free(s->head);
			s->head = newHead;
		}
	}
}

node* pop(stack* s)
{
	if(s->head == NULL)
		return NULL;
	else if(s->currentSize == 1)
	{
		node* i = s->head;
		s->head = NULL;
		s->tail = NULL;
		s->currentSize--;
		return i;
	}
	else
	{
		node* i = s->head;
		while(i->nextNode != s->tail)
		{
			i = i->nextNode;
		}
		node* r = s->tail;
		s->tail = i;
		s->tail->nextNode = NULL;
		s->currentSize--;
		return r;
	}
}

void display(stack* s)
{
	node* i = s->head;
	int j = s->currentSize-1;
	while(i != NULL)
	{
		printf("    %d.  %s", j, i->command);	
		i = i->nextNode;
		j--;
	}
}

#endif