#pragma once
#include <cstring>


class Cell
{
public:
    typedef struct _point
    {
        int x, y;

        explicit _point() : x(0), y(0) {}
        explicit _point(int x, int y) : x(x), y(y) {}
    } POINT;

public:
    enum class Wall
    {
        EMPTY,
        CONCRETE,
        RELATED
    };

    Wall top, right, bottom, left;
    size_t set_index;

    POINT point;

public:
    Cell(POINT point = POINT{}) : point(point), set_index(0) {}
};
