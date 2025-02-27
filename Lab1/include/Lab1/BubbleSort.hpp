#pragma once
#include "Lab1/ABubbleSort.hpp"

template<typename _Ty>
class BubbleSort : public ABubbleSort<_Ty>
{
private:
	void swap(_Ty& a, _Ty& b, const Comparator<_Ty>& comparator) const override
	{
		if (comparator.compair(a, b)) std::swap(a, b);
	}
};
