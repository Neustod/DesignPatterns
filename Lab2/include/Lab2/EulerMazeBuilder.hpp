#pragma once
#include "MazeBuilder.hpp"


class EulerMazeBuilder : public MazeBuilder
{
private:
    size_t _set_index;

private:

    void setSetIndexes(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field);

    void setVerticalWalls(std::vector<Cell>& horizontal_field);

    void setHorizontalWalls(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field,
                            const std::vector<Cell>* next_field);

public:
    EulerMazeBuilder() : _set_index(0) {}

    void build(std::vector<std::vector<Cell>>& field) override;
};
