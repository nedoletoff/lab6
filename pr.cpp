#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "pr.hpp"

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
//	std::cout << "push_back" << std::endl;
	node_t* n;
	node_t* cur;
	n = (node_t*) malloc(sizeof(node_t));
//	n->value = "";
	for (int i = 0; i < SIZE; ++i)
		n->value[i] = val[i];
       	n->next = NULL;
	if (l->head == NULL)
	{
		std::cout << "aded first element" << std::endl;
		n->prev = NULL;
		l->head = n;
	}
	else
	{
		cur = l->tail; cur->next = n;
		n->prev = cur;
//		std::cout << "added " << l->size << std::endl;
	}
	l->tail = n;
	++l->size;
}



void push_before(list_t* l, node_t* cur, char* val)	//done
{
//	std::cout << "push_before" << std::endl;
	node_t* q = l->head;
//	std::cout << "\n"  << cur->value << " ";
//	if (cur == l->head)
//		std::cout << "NULL\n";
//	else
//		std::cout << cur->prev->value << "    ";
	print(q, l->size);
	node_t* n;
	n = (node_t*) malloc(sizeof(node_t));
	for (int i = 0; i < SIZE; ++i)
		n->value[i] = val[i];
       	n->next = cur;
	if (l->head == cur)
	{
		l->head = n;
		n->prev = NULL;
//		std::cout << "in head";
	}
	else
	{
		cur->prev->next = n;
		n->prev = cur->prev;
//		std::cout << cur->value << " " << cur->prev->value << std::endl;
	}
	cur->prev = n;

	++l->size;
//	std::cout << n->prev->value << " n->prev->value" << std::endl;
//	std::cout << "added " << l->size << std::endl;
	q = l->head;
	print(q, l->size);

}

void print(node_t* cur, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << cur->value << "\t";
		cur = cur->next;
		if (cur == NULL)
			break;
	}
	printf("\n");
}

void insert_sort(list_t* l, char* val)	//doesnt work ???
{
//	std::cout << "insert_sort started" << std::endl;
//	std::cout << val << std::endl;
//	int count = 0;
	if (l->head == NULL)
		push_back(l, val);
	else
	{
		node_t* cur;
		cur = l->head;
		std::cout << val << std::endl;
		while (my_strcmp(val, cur->value) == 1)
		{
//			std::cout << "\'" << std::endl;
			if (cur->next == NULL)
			{
				push_back(l, val);
				return;
			}
			cur = cur->next;
		}
//		std::cout << cur->value << std::endl;
//		std::cout << "word added" << std::endl; 
		push_before(l, cur, val);
	}
}

int my_strcmp(char* str1, char* str2) // -1 <=; 1 >; 0 =;
{
//	std::cout << str1 << " - " << str2 << std::endl;
	int i = 0;
	while (str1[i] == str2[i] && str2[i] != '\0' && str1[i] != '\0')
		     ++i;
//	std::cout << i << " ";
	if (str1[i] <= str2[i])
		return -1;
	if (str1[i] > str2[i])
		return 1;
	if (str2[i] == '\0')
		return 0;
	std::cout << "wtf" << std::endl;
	return -3;
}

void my_link(list_t* first, list_t* next) //not need not done
{
	first->tail->next = next->head;
	first->tail = next->tail;
	next->head = first->head;
}

void sort_link(list_t* one, list_t* another, list_t* result)	//???
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

void get_filename(char* n)	//done
{
	int check = -2;
	while (check <= 0)
	{
		if (check == -1)
			std::cout << "Try again" << std::endl;
		std::cout<< "Type file name" << std::endl;
		std::cin.getline(n, SIZE);
		for (int i = 0; i < SIZE; ++i)
		{
			if (n[i] == '\0')
			{
				check = i;
				break;
			}
			if (n[i] <= ' ')
			{
				check = -1;
				break;
			}
		}
	}
}

int open_file(char* name)	//done
{
	FILE* rFile = fopen(name, "r");
	if (!(rFile))
	{
		std::cout << "File doesnt exist" << std::endl;
		return 1;
	}
	fclose(rFile);
	return 0;
}

void insert_str(char* filename, list_t* l)	//done
{
	FILE* rFile = fopen(filename, "r");
	char str[SIZE] = {'\0'};
	char ch = '\0';
	int count = 0;

	while ((ch = char(fgetc(rFile))) != EOF)
	{
		if (ch > ' ')
		{
			str[count++] = ch;
		}
		else
		{
	  		if (count > 0)
			{
				insert_sort(l, str);
//				std::cout << str << std::endl;
			}
			for (int i = 0; i < count; i++)
	    			str[i] = '\0';
			count = 0;
		}
	}
}
