#pragma once
#include <iostream>
class UndefinedATM : public std:: exception
{
public:
	const char* what() const noexcept override;
};

