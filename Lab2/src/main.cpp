#include <cstdlib>
#include <stdio.h>
#include "Lab2/RectangleFieldFabric.hpp"
#include "Lab2/EulerMazeBuilder.hpp"


int main(int argc, char* argv[])
{
	RectangleFieldFabric fabric;
	EulerMazeBuilder builder;

	size_t maze_size{ 3 };

	if (argc > 1)
	{
		maze_size = atoll(argv[1]);
	}
	else
	{
		printf("Enter maze size >> ");
		scanf("%zu", &maze_size);
	}

	if (maze_size < 3) maze_size = 3;

	Maze& maze = fabric.create(maze_size);
	maze.fill(builder);

	maze.print();
	printf("\n");

	return 0;
}
