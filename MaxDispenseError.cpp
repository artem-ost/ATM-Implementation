#include "MaxDispenseError.h"

const char* MaxDispenseError::what() const noexcept
{
	return "Amount of money is overdrive maximum limit";
}