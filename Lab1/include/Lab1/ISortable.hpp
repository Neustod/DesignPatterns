#pragma once
#include "Lab1/ISortingAlgo.hpp"


template<typename _Ty>
class ISortable 
{
public:
	virtual ~ISortable() {}
	virtual void sort(const ISortingAlgo<_Ty>&, const Comparator<_Ty>&) = 0;
};