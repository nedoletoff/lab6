#pragma once

typedef struct
{
	char* data;
	size_t size;
	size_t capacity;
} vector_t;

typedef struct node_t 
{
	vector_t value;
	struct node_t* prev;
	struct node_t* next;
} node_t;

typedef struct
{
	node_t* head;
	node_t* tail;
	size_t size;
} list_t;
