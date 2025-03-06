#include "../include/Lab2/Randomizer.hpp"
#include <cstdlib>
#include <ctime>


Randomizer* Randomizer::_instance = nullptr;

Randomizer::Randomizer()
{
    srand(time(0));
}

const Randomizer& Randomizer::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Randomizer();
    }
    return *_instance;
}

void Randomizer::releaseInstance()
{
    if (_instance != nullptr)
    {
        delete _instance;
        _instance = nullptr;
    }
}

int32_t Randomizer::randInt32(int32_t left_bound, int32_t right_bound) const
{
    return rand() % (right_bound - left_bound) + left_bound;
}
