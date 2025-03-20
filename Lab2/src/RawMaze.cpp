#include "Lab2/RawMaze.hpp"
#include "Lab2/Randomizer.hpp"
#include <cstdio>


void RawMaze::setSetIndexes(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field)
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

void RawMaze::setVerticalWalls(std::vector<Cell>& horizontal_field)
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

void RawMaze::setHorizontalWalls(const std::vector<Cell>* previous_field, std::vector<Cell>& horizontal_field,
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


void RawMaze::fill()
{
    if (_field.empty() || _field.size() == 1) return;

    setSetIndexes(nullptr, _field[0]);
    setVerticalWalls(_field[0]);
    setHorizontalWalls(nullptr, _field[0], &_field[1]);

    for (size_t row = 1; row < _field.size() - 1; row++)
    {
        setSetIndexes(&_field[row - 1], _field[row]);
        setVerticalWalls(_field[row]);
        setHorizontalWalls(&_field[row - 1], _field[row] , &_field[row + 1]);
    }

    setSetIndexes(&_field[_field.size() - 2], _field[_field.size() - 1]);

    auto& horizontal_field = _field[_field.size() - 1];

    horizontal_field[0].left = Cell::Wall::CONCRETE;
    for (size_t col = 1; col < horizontal_field.size() - 1; col++)
    {
        horizontal_field[col].left = Cell::Wall::RELATED;

        if (horizontal_field[col].set_index == horizontal_field[col + 1].set_index)
        {
            horizontal_field[col].right = Cell::Wall::CONCRETE;
        }
    }
    horizontal_field[horizontal_field.size() - 1].left = Cell::Wall::RELATED;
    horizontal_field[horizontal_field.size() - 1].right = Cell::Wall::CONCRETE;

    setHorizontalWalls(&_field[_field.size() - 2], _field[_field.size() - 1], nullptr);
}


void RawMaze::print()
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
