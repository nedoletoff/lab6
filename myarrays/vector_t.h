#pragma once
#include "arrays.h"

void init(vector_t*);
void destroy(vector_t*);
void push_back(vector_t*, char);
int set(vector_t*, int, char);
int get(vector_t*, int, char*);
void insert(vector_t*, int, char);
void erase(vector_t*, int);
void pop_back(vector_t*);
void shrink_to_fit(vector_t*);
void print(vector_t*);
int find(vector_t*, char);

