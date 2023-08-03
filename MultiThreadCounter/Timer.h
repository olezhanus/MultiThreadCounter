#pragma once
#include <iostream>
#include <chrono>

class Timer
{
public:
	void start();
	void stop();
	auto duration() -> std::chrono::milliseconds;
private:
	std::chrono::steady_clock::time_point _begin, _end;
	std::chrono::milliseconds _duration;
};

