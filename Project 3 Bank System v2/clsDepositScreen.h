#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsClient.h"

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber = "";

		cout << "Please enter account number: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!(clsClient::isClientExist(AccountNumber)))
		{
			cout << "Account number is not found, please enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "Please enter deposit amount: ";
		float DepositAmount = clsInputValidation::ReadPositiveFloat("Please enter positive deposit amount: ", "Invalid number, please try again: ");

		cout << "\nAre you sure you want to make this transaction? (yes:1, no:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();

		if (isUpdate)
		{
			Client.Deposit(DepositAmount);
			cout << "\nTransaction has been made successfully :-)\n";
			cout << "New balance: " << Client.getAccountBalance() << endl << endl;
		}
		else
			cout << "\nTransaction failed :-(\n\n";
	}

};

