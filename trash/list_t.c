#include <stdio.h>
#include <stdlib.h>
#include "list_t.h"

void init(list_t* l)		//done
{
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
}

void destroy(list_t* l)		//done
{
	node_t* cur = l->head;
	node_t* perv = NULL;
	while (cur != NULL)
	{
		perv = cur;
		cur = cur->next;
		free(perv);
	}
}

void push_back(list_t* l, char* val)	//done(?)
{
	node_t* n;
	node_t* cur;
	n = (node_t*) malloc(sizeof(node_t));
	n->value = val; n->next = NULL;
	if (l->head == NULL)
	{
		n->prev = NULL;
		l->head = n;
	}
	else
	{
		cur = l->tail; cur->next = n;
		n->prev = cur;
	}
	l->tail = n;
	++l->size;
}

void push_before(list_t* l, node_t* cur, char* val)	//done
{
	node_t* n;
	n = (node_t*) malloc(sizeof(node_t));
	n->value = val; n->next = cur;
	n->prev = cur->prev; cur->prev = n;
	if (l->head == cur)
		l->head = n;
	else
		cur->prev->next = n;
	++l->size;

}

void print(list_t* l)		//done
{
	node_t*cur = l->head;
	while (cur != NULL)
	{
		printf("%s ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

void insert_sort(list_t* l, char* val)	//done
{
	if (l->head == NULL)
		push_back(l, val);
	else
	{
		node_t* cur;
		cur = l->head;
		while (my_strcmp(val, cur->value) == 1)
		{
			if (cur->next == NULL)
			{
				push_back(l, val);
				return;
			}
			cur = cur->next;
		}
		push_before(l, cur, val);
	}
}

void push_front(list_t* l, char* val)	//not need
{
	node_t* n = (node_t*) malloc(sizeof(node_t));
	if (l->tail == l->head)
		l->tail = n;
	n->value = val;
	n->prev = NULL;
	n->next = l->head;
	l->head->prev = n;
	l->head = n;
	++l->size;
}

int my_strcmp(char* str1, char* str2) // -1 <; 1 >; 0 =;
{
	int i = 0;
	while (str1[i] == str2[i] && str2[i] != '\0')
	       ++i;
	if (str1[i] < str2[i])
		return -1;
	if (str1[i] > str2[i])
		return 1;
	if (str2[i] == '\0')
		return 0;
	return 2;
}

void my_link(list_t* first, list_t* next) //not need not done
{
	first->tail->next = next->head;
	first->tail = next->tail;
	next->head = first->head;
}

void sort_link(list_t* one, list_t* another, list_t* result)	//done
{
	node_t* first = one->head;
	node_t* second = another->head;
	while (first != NULL && second != NULL)
	{
		if (my_strcmp(first->value, second->value) == 1)
		{
			push_back(result, second->value);
			second = second->next;
		}
		else
		{
			push_back(result, first->value);
			first = first->next;
		}
	}
	if (first == NULL)
		while (second != NULL)
		{
			push_back(result, second->value);
			second = second->next;
		}
	else
		while (first != NULL)
		{
			push_back(result, first->value);
			first = first->next;
		}
}
