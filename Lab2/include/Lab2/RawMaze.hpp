#pragma once
#include "Cell.hpp"
#include <vector>


class RawMaze
{
private:
    size_t _set_index;
    std::vector<std::vector<Cell>> _field;

public:
    RawMaze() : _set_index(0) {}

    RawMaze(size_t size)
    {
        _field.resize(size);
        for (auto& item : _field) item.resize(size);
    }

    RawMaze(const RawMaze& src) : _field(src._field) {}

    RawMaze(RawMaze&& src) noexcept : _field(std::move(src._field)) {};

public:
    void operator=(const RawMaze& src) { _field = src._field; }

    void operator=(RawMaze&& src) noexcept { _field = std::move(src._field); }

private:
    void setSetIndexes(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field);

    void setVerticalWalls(std::vector<Cell>& horizontal_field);

    void setHorizontalWalls(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field,
                            const std::vector<Cell>* next_field);

public:
    void fill();

    void print();
};
