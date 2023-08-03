#include "MultiThreadSum.h"

size_t MultiThreadSum(const std::vector<int> &vec, size_t threads_count)
{
	std::atomic_ullong sum = 0;
	std::vector<std::thread> threads;
	if (threads_count < vec.size())
	{
		for (size_t i = 0; i < threads_count; ++i)
		{
			size_t begin = vec.size() / threads_count * i;
			size_t end = (i == threads_count - 1) ?
				vec.size() - 1 :
				(vec.size() / threads_count * (i + 1)) - 1;

			threads.emplace_back([&sum, &vec, begin, end]()
				{
					size_t thread_sum = 0;
					for (size_t j = begin; j <= end; ++j)
					{
						thread_sum += vec[j];
					}
					sum += thread_sum;
				});
		}
	}
	else
	{
		for (size_t i = 0; i < vec.size(); ++i)
		{
			threads.emplace_back([&sum, &vec, i]()
				{
					sum += vec[i];
				});
		}
	}

	for (auto &th : threads)
	{
		if (th.joinable())
		{
			th.join();
		}
	}
	return sum;
}