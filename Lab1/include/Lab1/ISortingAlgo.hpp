#pragma once
#include "Comparator.hpp"


template<typename _Ty>
class ISortingAlgo 
{
public:
	virtual ~ISortingAlgo() {}
	virtual void sort(_Ty* data, size_t size, const Comparator<_Ty>&) const = 0;
};