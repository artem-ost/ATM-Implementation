#include <iostream>
#include "Bank.h"	
#include "ATM.h"
#include "write_in_file.h"
#include "read_from_file.h"

int main()
{
	Bank bank;

	double min_dispense = 1000;
	double max_dispense = 5000;

	std::vector<std::vector<int>> b =
	{
		{10,20,40,30,30,50,40,60,80},
		{120,300,50,20,30,40,20,30,10},
		{900,600,250,5420,320,501,47,62,91},
	};

	bank.InitializeATMs(b, min_dispense, max_dispense);

	std::cout << bank.GetCapital() << std::endl;

	std::vector<int> m = { 120,300,50,20,30,40,20,30,10 };

	bank.GetATM(0)->Load_Money(m);
	bank.GetATM(1)->Load_Money(m);
	bank.GetATM(2)->Load_Money(m);

	std::cout << bank.GetCapital() << std::endl;

	std :: vector<int> k = bank.GetATM(0)->Dispense_Money(5000);

	for (int i = 0; i < k.size(); i++)
	{
		std::cout << "k: " << k[i] << std::endl;
	}

	std::cout << bank.GetCapital() << std ::endl;
	write_in_file(&bank);
	read_from_file("ATM_DB.txt");

	return 0;
}