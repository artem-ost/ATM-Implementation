#include "InsufficientAmountOfMoney.h"

const char* InsufficientAmountOfMoney::what() const noexcept
{
	return "That ATM doesn't have money";
}