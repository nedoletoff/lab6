#include "func.hpp"
#include "list_t.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>

void get_filename(char* n)
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

int open_file(char* name)
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

void insert_str(char* filename, list_t* l)
{
  FILE* rFile = fopen(filename, "r");
  char[SIZE] = {'/0'};
  int count = 0;

	while ((ch = char(fgetc(rFile))) != EOF)
  {
    count = 0;
    while (ch > ' ')
      char[count++] = ch;
    insert_sort(l, char);
    for (int i = 0; i < count; i++)
      char[i] = '\0';
  }
}
