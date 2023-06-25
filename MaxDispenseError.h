#pragma once
#include <iostream>
class MaxDispenseError : public std ::exception
{
public:
	const char* what() const noexcept override;
};

