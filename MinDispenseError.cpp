#include "MinDispenseError.h"

const char* MinDispenseError::what() const noexcept
{
	return "Amount of money is less than the minimum limit";
}