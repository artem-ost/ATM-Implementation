#pragma once
#include <iostream>
class InsufficientAmountOfMoney : public std :: exception
{
public:
	const char* what() const noexcept override;
};

