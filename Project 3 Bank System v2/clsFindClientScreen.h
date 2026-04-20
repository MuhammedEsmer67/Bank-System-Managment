#pragma once
#include "clsClient.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsFindClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_____________________________________________\n\n";
		cout << "Account Number : " << Client.getAccountNumber() << endl;
		cout << "Pin Code       : " << Client.getPinCode() << endl;
		cout << "Full Name      : " << Client.GetFullName() << endl;
		cout << "Email          : " << Client.getEmail() << endl;
		cout << "Phone Number   : " << Client.getPhoneNumber() << endl;
		cout << "Account Balance: " << Client.getAccountBalance() << endl;
		cout << "_____________________________________________\n\n";
	}

public:

	static void FindClient()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::FindClient))
			return;

		_DrawScreenHeader("Find Client Screen");

		string AccountNumber = "";

		cout << "Please enter account number: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!(clsClient::isClientExist(AccountNumber)))
		{
			cout << "Account number is not found, please enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);

		if (Client.isEmpty())
			cout << "\nClient is empty :-(\n\n";
		else
			cout << "\nClient Found :-)\n\n";

		_PrintClient(Client);
	}

};

