#pragma once
#include <cstdint>


class Randomizer
{
private:
    static Randomizer* _instance;

private:
    Randomizer();

public:
    Randomizer(const Randomizer&) = delete;

    Randomizer(Randomizer&&) noexcept = delete;

    void operator=(const Randomizer&) = delete;

    void operator=(Randomizer&&) noexcept = delete;

public:
    static const Randomizer& getInstance();

    static void releaseInstance();

    int32_t randInt32(int32_t left_bound, int32_t right_bound) const;

    ~Randomizer() { releaseInstance(); }
};
