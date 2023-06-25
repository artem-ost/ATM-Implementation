#pragma once
#include <iostream>
class MinDispenseError : public std :: exception
{
public:
	const char* what() const noexcept override;
};

