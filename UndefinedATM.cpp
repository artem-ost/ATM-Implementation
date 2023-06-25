#include "UndefinedATM.h"

const char* UndefinedATM::what() const noexcept
{
	return "ATM that you tried to find doesn't exist";
}