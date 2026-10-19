#include "../../headers/Sort.h"
#include <cstdlib>
#include <conio.h>
#include <random>
#include <chrono>

int rand_int(int from, int to) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(from, to);
	return dist(rng);
}