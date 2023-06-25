#include "Bank.h"
#include "ATM.h"
#include "UndefinedATM.h"
#include <iostream>
#include "write_in_file.h"

Bank :: Bank() {}

Bank :: ~Bank()
{
	for (int i = 0; i < ATM_Count - 1; i++)
	{
		if (ATMs[i] != nullptr)
		{
			delete ATMs[i];
		}
	}
}

double Bank::GetCapital()
{
	double sum = 0;

	for (int i = 0; i < ATM_Count; i++)
	{
		sum += ATMs[i]->CashInATM();
	}

	return sum;
}

void Bank::InitializeATMs(std::vector<std::vector<int>> Banknotes, double min_dispense, double max_dispense)
{
	for (int i = 0; i < Banknotes.size(); i++)
	{
		ATM* temp_atm = new ATM(Banknotes[i], min_dispense, max_dispense);
		ATMs.push_back(temp_atm);
	}

	this->ATM_Count = ATMs.size();
}

ATM* Bank::GetATM(int index)
{
	try
	{
		if (index < 0 || index > ATM_Count - 1)
		{
			throw UndefinedATM();
		}
		return ATMs[index];
	}
	catch (UndefinedATM& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}