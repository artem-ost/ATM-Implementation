#pragma warning(disable : 4996)
#include "write_in_file.h"
#include "Bank.h"
#include "ATM.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

void write_in_file(Bank* bank)
{
	std::ofstream wfile;

	wfile.open("ATM_DB.txt");

	if (!wfile.is_open())
	{
		std::cout << "File opening error while writing in" << std::endl;
	}
	else
	{
		auto now = std::chrono::system_clock::now();
		std::time_t end_time = std::chrono::system_clock::to_time_t(now);

		wfile << "Current Data & Time: " << std::ctime(&end_time) << std::endl;

		wfile << "ATMs in Bank: " << bank->ATM_Count << std :: endl;

		wfile << "Bank Capital: " << bank->GetCapital() << std::endl;

		for (int i = 0; i < bank->ATM_Count; i++)
		{
			wfile << " ATM #" << i + 1 << ": " << std::endl;
			wfile << "\t ATM capital: " << bank->ATMs[i]->CashInATM() << std::endl;
			wfile << "\t ATM min/max dispense: " << bank->ATMs[i]->min_dispense << "/" << bank->ATMs[i]->max_dispense << std :: endl;
			wfile << "\t ATM Banknotes: " << std::endl;
			for (int j = 0; j < bank->ATMs[i]->Banknotes_Count.size(); j++)
			{
				wfile << "\t\t" << bank->ATMs[i]->Banknotes[j] << ": " << bank->ATMs[i]->Banknotes_Count[j] << std :: endl;
			}
		}

	}

	wfile.close();
}