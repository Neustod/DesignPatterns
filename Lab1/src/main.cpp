#include <cstdlib>
#include <stdio.h>
#include "Lab1/Container.hpp"
#include "Lab1/BubbleSort.hpp"
#include <time.h>


int main()
{
	Container<int, 10> arr;
	Comparator<int> comparator([](const int& a, const int& b) { return a > b; });

	srand(time(0));

	for (auto& item : arr) 
	{
		item = rand() % 101;
		printf("%d ", item);
	}
	printf("\n");

	arr.sort(BubbleSort<int>{}, comparator);

	for (auto& item : arr) printf("%d ", item);
	printf("\n");

	getchar();
	return 0;
}
