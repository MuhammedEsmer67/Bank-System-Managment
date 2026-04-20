#pragma once
#include "clsClient.h"
#include "clsScreen.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _GetClientBalanceRecord(clsClient Client)
	{
		cout << clsUtility::Tabs(3) << " | " << left << setw(15) << Client.getAccountNumber();
		cout << " | " << left << setw(20) << Client.GetFullName();
		cout << " | " << left << setw(12) << Client.getAccountBalance() << endl;
	}

public:

	static void ShowTotalBalances()
	{
		vector <clsClient> vClients = clsClient::GetClientsList();

		_DrawScreenHeader("Total Balances List Screen", "(" + to_string(vClients.size()) + ") Client(s).");

		cout << endl << clsUtility::Tabs(3) << "_____________________________________________________________________\n\n";
		cout << clsUtility::Tabs(3) << " | " << left << setw(15) << "Account Number";
		cout << " | " << left << setw(20) << "Client Name";
		cout << " | " << left << setw(12) << "Account Balance";
		cout << endl << clsUtility::Tabs(3) << "_____________________________________________________________________\n\n";

		if (vClients.size() == 0)
			cout << clsUtility::Tabs(6) << "No clients avalaible on the system.\n";
		else
		{
			float TotalBalances = clsClient::GetClientsTotalBalances();

			for (clsClient& Client : vClients)
				_GetClientBalanceRecord(Client);

			cout << clsUtility::Tabs(3) << "_____________________________________________________________________\n\n";

			cout << clsUtility::Tabs(6) << "Total Balances = " << TotalBalances << endl;
			cout << clsUtility::Tabs(5) << "(" << clsUtility::NumberToText(int(TotalBalances)) << ")" << endl << endl;
		}

	}

};

