#pragma once
#include <vector>

class ATM;

class Bank
{
protected:
	std :: vector<ATM*> ATMs;
	int ATM_Count;
public:
	void InitializeATMs(std :: vector<std :: vector<int>> Banknotes, double min_dispense, double max_dispense);
	double GetCapital();
	Bank();
	~Bank();
	ATM* GetATM(int index);
	friend void write_in_file(Bank* bank);
};

