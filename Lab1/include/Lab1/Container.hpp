#pragma once
#include "Lab1/ISortable.hpp"
#include <array>


template<typename _Ty, size_t _Size>
class Container : public std::array<_Ty, _Size>, ISortable<_Ty>
{
public:
	void sort(const ISortingAlgo<_Ty>& algo, const Comparator<_Ty>& comparator) override
	{
		algo.sort(this->data(), this->size(), comparator);
	}
};
