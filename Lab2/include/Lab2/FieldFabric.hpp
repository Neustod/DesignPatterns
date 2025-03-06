#pragma once
#include "Maze.hpp"


class FieldFabric
{
public:
    FieldFabric() {}

    virtual ~FieldFabric() {}

public:
    virtual Maze& create(size_t) = 0;
};
