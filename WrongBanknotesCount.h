#pragma once
#include <iostream>
class WrongBanknotesCount : public std::exception
{
public:
	const char* what() const noexcept override;
};

