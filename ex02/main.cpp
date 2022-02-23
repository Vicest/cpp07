#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
#define TINY_MAX 10
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (tmp[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (test[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		test[0] = -42;
		if (tmp[0] == test[0])
			std::cerr << "Value changed in copied arrays." << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	{
		Array<char> empty(0);
		if (empty.size() != 0)
			std::cerr << "Case zero size fail." << std::endl;
		Array<char> some(TINY_MAX);
		for (int i = 0; i < TINY_MAX; i++)
			some[i] = '#';
		Array<char> ctor_cpy(some);
		empty = some;
		for (int i = 0; i < TINY_MAX; i++)
			std::cout << some[i] << std::endl;
		std::cout << std::endl;
		some[TINY_MAX / 2]++;
		for (int i = 0; i < TINY_MAX; i++)
			std::cout << some[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < TINY_MAX; i++)
			std::cout << ctor_cpy[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < TINY_MAX; i++)
			std::cout << empty[i] << std::endl;
		std::cout << std::endl;


	}
	system("leaks -q arrtst");
    return 0;
}
