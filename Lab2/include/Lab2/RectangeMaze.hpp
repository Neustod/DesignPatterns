#pragma once
#include "Maze.hpp"
#include "MazeBuilder.hpp"
#include <cstdio>
#include <vector>


class RectangleMaze : public Maze
{
private:
    std::vector<std::vector<Cell>> _field;

public:
    RectangleMaze(size_t width, size_t heigth)
    {
        if (heigth != 0 && width != 0)
        {
            _field.resize(heigth);

            for (size_t i = 0; i < heigth; i++)
            {
                _field[i].resize(width);
            }
        }
    }

public:
    constexpr const std::vector<std::vector<Cell>>& Field() const { return _field; }

    constexpr std::vector<std::vector<Cell>>& Field() { return _field; }

public:
    void fill(MazeBuilder& builder) override { builder.build(_field); }

    void print() const override 
    {
        printf("#");
        for (size_t col = 0; col < _field[0].size(); col++)
        {
            printf(_field[0][col].top == Cell::Wall::CONCRETE ? "#" : " ");
            printf("#");
        }

        for (size_t row = 0; row < _field.size(); row++)
        {
            printf(_field[row][0].left == Cell::Wall::CONCRETE ? "\n#" : "\n ");
            for (size_t col = 0; col < _field[row].size(); col++)
            {
                printf(" ");
                printf(_field[row][col].right == Cell::Wall::CONCRETE ? "#" : " ");
            }

            printf("\n#");
            for (size_t col = 0; col < _field[row].size(); col++)
            {
                printf(_field[row][col].bottom == Cell::Wall::CONCRETE ? "#" : " ");
                printf("#");
            }
        }
    }
};
