#pragma once
#include <vector>
#include <cstdlib>
#include "Bank.h"

class ATM : public Bank
{
private:
	std::vector<int> Banknotes;
	std::vector<int> Banknotes_Count;
	double min_dispense;
	double max_dispense;
public:
	double CashInATM();
	void Load_Money(std::vector<int> Money);
	std::vector<int> Dispense_Money(double Cash);
	ATM();
	ATM(std::vector<int> Banknotes_Count, double min_dispense, double max_dispense);
	friend void write_in_file(Bank* bank);
};

