#include "ATM.h"
#include "WrongBanknotesCount.h"	
#include "MaxDispenseError.h"
#include "MinDispenseError.h"
#include "InsufficientAmountOfMoney.h"
#include <iostream>
#include "write_in_file.h"

ATM :: ATM() 
{
	this->Banknotes = { 1,2,5,10,20,50,100,200,500 };
}

ATM::ATM(std::vector<int> Banknotes_Count, double min_dispense, double max_dispense)
{
	this->Banknotes_Count = Banknotes_Count;
	this->min_dispense = min_dispense;
	this->max_dispense = max_dispense;

	this->Banknotes = { 1,2,5,10,20,50,100,200,500 };
}

double ATM::CashInATM()
{
	double cash = 0;

	for (int i = 0; i < Banknotes_Count.size(); i++)
	{
		cash += Banknotes_Count[i] * Banknotes[i];
	}

	return cash;
}

void ATM::Load_Money(std :: vector<int> Money)
{
	try
	{
		if (Money.size() > 9 || Money.size() < 9)
		{
			throw WrongBanknotesCount();
			return;
		}

		for (int i = 0; i < 9; i++)
		{
			Banknotes_Count[i] += Money[i];
		}
	}
	catch (WrongBanknotesCount& ex)
	{ 
		std::cout << ex.what() << std::endl;
	}
}

std::vector<int> ATM::Dispense_Money(double Cash)
{
	try
	{
		if (Cash > max_dispense)
		{
			throw MaxDispenseError();
		}
		else if (Cash < min_dispense)
		{
			throw MinDispenseError();
		}
		else if (Cash > this->CashInATM())
		{
			throw InsufficientAmountOfMoney();
		}
		else
		{
			double temp_cash = Cash;
			int i = 8;

			std::vector<int> money = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			while (i >= 0)
			{
				if (temp_cash >= Banknotes[i])
				{
					money[i]++;
					--Banknotes_Count[i];
					temp_cash -= Banknotes[i];
				}
				else if (temp_cash < Banknotes[i])
				{
					i--;
				}
				else if (temp_cash == 0)
				{
					break;
				}
			}
			return money;
		}
	}
	catch (MaxDispenseError& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (MinDispenseError& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (InsufficientAmountOfMoney& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}