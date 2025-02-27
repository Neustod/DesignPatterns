#pragma once
#include "Lab1/ISortingAlgo.hpp"


template<typename _Ty>
class ABubbleSort : public ISortingAlgo<_Ty>
{
protected:
	ABubbleSort() {};

	virtual void swap(_Ty&, _Ty&, const Comparator<_Ty>&) const = 0;

public:
	void sort(_Ty* data, size_t size , const Comparator<_Ty>& comparator) const override
	{
		for (size_t i = 0; i < size; i++) 
		{
			for (size_t j = 0; j < size - i - 1; j++) 
			{
				swap(data[j], data[j + 1], comparator);
			}
		}
	}
};