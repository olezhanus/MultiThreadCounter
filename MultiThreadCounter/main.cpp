#include <iostream>
#include <vector>
#include <cstdlib>
#include "Timer.h"
#include "MultiThreadSum.h"

void print_vector(const std::vector<int> &vec)
{
	for (auto &i : vec)
	{
		std::cout << i << ' ';
	}
}

int main()
{
	srand(time(0));
	size_t size = 0;
	std::cout << "enter size of a vector: ";
	std::cin >> size;
	std::cout << std::endl;
	std::vector<int> vec;

	for (size_t i = 0; i < size; ++i)
	{
		vec.push_back(rand());
	}

	size_t threads_count = 0;
	while (true)
	{
		std::cout << "enter number of threads or any symbol to quit: ";
		if (!(std::cin >> threads_count))
		{
			break;
		}

		Timer t;

		t.start();
		auto sum = MultiThreadSum(vec, threads_count);
		t.stop();
		std::cout << "sum of vector = " << sum << "; time = " << t.duration().count() << "ms" << std::endl << std::endl;
	}

	return 0;
}