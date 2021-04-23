#include "pr.hpp"
#include <iostream>

#define NUM 3

int main()
{
	char txtfile[NUM][SIZE] = {'\0'};
	list_t l[NUM];
	list_t res[2];
	list_t aaaa;
	node_t* n;
	init(&aaaa);
	std::cout << aaaa.size << " - size" << std::endl;
	for (int i = 0; i < NUM; ++i)
		init(&(l[i]));
	for (int i = 0; i < 2; ++i)
		init(&(res[i]));

	std::cout << "File to read:" << std::endl;
	for (int i = 0; i < NUM; ++i)
		do
		  get_filename(txtfile[i]);
		while (open_file(txtfile[i]));


//	for (int i = 0; i < NUM; ++i)
//	{
//		insert_str(txtfile[i], &(l[i]));
//	}
//	node_t* n = l[1].head;
//	std::cout << n << " - nnn" << std::endl;
//	std::cout << n->value << " em" << std::endl;
	insert_str(txtfile[0], &aaaa);
	n = aaaa.head;
	std::cout << "fuck\n" << std::endl;
	print(n, aaaa.size);
	std::cout << aaaa.size << " - size" << std::endl;

	sort_link(&(l[0]), &(l[1]), &(res[0]));
//	std::cout << "sortlink 1" << std::endl;

	for (int i = 0; i < NUM-2; ++i)
	{
		sort_link(&(l[i+2]), &(res[i%NUM]), &(res[(i+1)%NUM]));
		std::cout << "sortlink " << i+2 << std::endl;
	}

//	print((res[NUM%2]));

	std::cout << "nu i gde???" << std::endl;

	for (int i = 0; i < NUM; ++i)
		destroy(&(l[i]));
	for (int i = 0; i < 2; ++i)
		destroy(&(res[i]));
	return 0;
}
