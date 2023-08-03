#pragma once
#include <vector>
#include <thread>
#include <atomic>

size_t MultiThreadSum(const std::vector<int> &vec, size_t threads_count);

