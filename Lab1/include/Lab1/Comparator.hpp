#pragma once
#include <functional>



template<typename _Ty>
class Comparator 
{
private:
	using compair_handler = std::function<bool(const _Ty&, const _Ty&)>;

	compair_handler _compair_handler;

public:
	Comparator(compair_handler&& compair_handler) : _compair_handler(std::move(compair_handler)) {}

	bool compair(const _Ty& a, const _Ty& b) const
	{
		return _compair_handler(a, b);
	}
};