#pragma once
#include "FieldFabric.hpp"
#include "RectangeMaze.hpp"


class RectangleFieldFabric : public FieldFabric
{
public:
    RectangleFieldFabric() {}

public:
    RectangleMaze& create(size_t sqr_size) override
    {
        return *new RectangleMaze(sqr_size, sqr_size);
    }
};
