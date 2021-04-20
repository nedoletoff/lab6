#pragma once
#include <cstddef>
#define SIZE 256

typedef struct node_t
{
	char* value;
	struct node_t* prev;
	struct node_t* next;
} node_t;

typedef struct list_t
{
	node_t* head;
	node_t* tail;
	size_t size;
} list_t;

void init(list_t*);
void destroy(list_t*);
void insert_sort(list_t*, char*);
void print(list_t*);
void sort_link(list_t*, list_t*, list_t*);
int my_strcmp(char*, char*);
void get_filename(char*);
int open_file(char*);
void insert_str(char*, list_t*);
