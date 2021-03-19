#pragma once
#include "arrays.h"

void init(list_t*);
void destroy(list_t*);
void push_back(list_t*, int);
void print(list_t*);
int set(list_t*, int, int);
int get(list_t*, int, int*);
void erase(list_t*, node_t*);
void push_front(list_t*, int);
int find(list_t*, int, node_t**);
