#pragma once
#include <iostream>
#include <chrono>
#include <mutex>


namespace cooper
{
	//counts program execution time
	class DurationTimer {
	public:
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		DurationTimer() : start(std::chrono::high_resolution_clock::now()) {}
		~DurationTimer()
		{
			end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> dur = end - start;
			std::cout<< "\n_____________________________________\n" << "Program duration time: " << dur.count() << " sec" << std::endl;
		}
	};
}