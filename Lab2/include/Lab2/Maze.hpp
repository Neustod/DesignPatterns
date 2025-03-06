#pragma once
#include "MazeBuilder.hpp"


class Maze
{
public:
    virtual ~Maze() {}

    virtual void fill(MazeBuilder& builder) = 0;

    virtual void print() const = 0;
};
