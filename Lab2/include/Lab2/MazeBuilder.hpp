#pragma once
#include <vector>
#include "Cell.hpp"


class MazeBuilder
{
public:
    virtual ~MazeBuilder() {}

    virtual void build(std::vector<std::vector<Cell>>&) = 0;
};
