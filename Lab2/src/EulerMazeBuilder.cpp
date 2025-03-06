#include "Lab2/EulerMazeBuilder.hpp"
#include "Lab2/Randomizer.hpp"
#include <cstdlib>


void EulerMazeBuilder::setSetIndexes(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field)
{
    if (previous_field == nullptr)
    {
        for (auto& cell : horizontal_field)
        {
            cell.set_index = ++_set_index;
        }
    }
    else
    {
        size_t prev_size = previous_field->size();
        size_t curr_size = horizontal_field.size();
        int diff_between = (curr_size - prev_size) / 2;

        for (size_t i = 0; i < curr_size; i++)
        {
            if
            (
                i - diff_between < 0 ||
                i - diff_between >= prev_size ||
                (*previous_field)[i - diff_between].bottom == Cell::Wall::CONCRETE
            )
            {
                horizontal_field[i].set_index = ++_set_index;
            }
            else
            {
                horizontal_field[i].set_index = (*previous_field)[i - diff_between].set_index;
            }
        }

    }
}

void EulerMazeBuilder::setVerticalWalls(std::vector<Cell>& horizontal_field)
{
    const auto& rander = Randomizer::getInstance();
    size_t field_size = horizontal_field.size();

    for (size_t i = 0; i < field_size; i++)
    {
        if (i == 0)
        {
            horizontal_field[i].left = Cell::Wall::CONCRETE;
        }
        else if (i == field_size - 1)
        {
            horizontal_field[i].left = Cell::Wall::RELATED;
            horizontal_field[i].right = Cell::Wall::CONCRETE;
            continue;
        }
        else
        {
            horizontal_field[i].left = Cell::Wall::RELATED;
        }

        if (rander.randInt32(0, 2) == 0)
        {
            if (horizontal_field[i].set_index == horizontal_field[i + 1].set_index)
            {
                horizontal_field[i].right = Cell::Wall::CONCRETE;
            }
            else
            {
                horizontal_field[i].right = Cell::Wall::EMPTY;
                auto tmp_set_index = horizontal_field[i + 1].set_index;

                for (size_t j = i + 1; j < field_size; j++)
                {
                    if (horizontal_field[j].set_index == tmp_set_index)
                    {
                        horizontal_field[j].set_index = horizontal_field[i].set_index;
                    }
                }
            }
        }
        else
        {
            horizontal_field[i].right = Cell::Wall::CONCRETE;
        }
    }

}

void EulerMazeBuilder::setHorizontalWalls(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field,
                                              const std::vector<Cell>* next_field
)
{
    const auto& rander = Randomizer::getInstance();

    size_t prev_size = previous_field != nullptr ? previous_field->size() : 0;
    size_t curr_size = horizontal_field.size();
    size_t next_size = next_field != nullptr ? next_field->size() : 0;
    int diff_between = (curr_size - prev_size) / 2;

    auto isBottom = [&](size_t field_index, size_t set_index)
    {
        for (size_t i = 0; i < curr_size; i++)
        {
            if (i == field_index) continue;
            if (horizontal_field[i].set_index == set_index && horizontal_field[i].bottom == Cell::Wall::EMPTY) return true;
        }
        return false;
    };


    for (size_t i = 0; i < curr_size; i++)
    {
        if(i - diff_between < 0 || i - diff_between >= prev_size)
        {
            horizontal_field[i].top = Cell::Wall::CONCRETE;
        }
        else
        {
            horizontal_field[i].top = Cell::Wall::RELATED;
        }
    }


    diff_between = (curr_size - next_size) / 2;

    for (size_t i = 0; i < curr_size; i++)
    {
        horizontal_field[i].bottom = Cell::Wall::CONCRETE;

        if(i - diff_between < 0 || i - diff_between >= next_size)
        {
            horizontal_field[i].bottom = Cell::Wall::CONCRETE;
        }
        else
        {
            horizontal_field[i].bottom = rander.randInt32(0, 2) == 1 && isBottom(i, horizontal_field[i].set_index) ?
            Cell::Wall::CONCRETE : Cell::Wall::EMPTY;
        }
    }
}

void EulerMazeBuilder::build(std::vector<std::vector<Cell>>& field)
{
    if (field.empty() || field.size() == 1) return;

    setSetIndexes(nullptr, field[0]);
    setVerticalWalls(field[0]);
    setHorizontalWalls(nullptr, field[0], &field[1]);

    for (size_t row = 1; row < field.size() - 1; row++)
    {
        setSetIndexes(&field[row - 1], field[row]);
        setVerticalWalls(field[row]);
        setHorizontalWalls(&field[row - 1], field[row] , &field[row + 1]);
    }

    setSetIndexes(&field[field.size() - 2], field[field.size() - 1]);
    field[field.size() - 1][0].left = Cell::Wall::CONCRETE;
    field[field.size() - 1][field[field.size() - 1].size() - 1].right = Cell::Wall::CONCRETE;
    setHorizontalWalls(&field[field.size() - 2], field[field.size() - 1], nullptr);
}

