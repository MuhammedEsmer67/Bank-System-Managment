#pragma once
#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_____________________________________________\n\n";
		cout << "Account Number : " << Client.getAccountNumber() << endl;
		cout << "Full Name      : " << Client.GetFullName() << endl;
		cout << "Account Balance: " << Client.getAccountBalance() << endl;
		cout << "_____________________________________________\n\n";
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		string AccountNumber = "";

		cout << "Please enter account number to transfer From: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!(clsClient::isClientExist(AccountNumber)))
		{
			cout << "Account number is not found, please enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsClient ClientFrom = clsClient::Find(AccountNumber);
		_PrintClient(ClientFrom);


		cout << "Please enter account number to transfer To: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!(clsClient::isClientExist(AccountNumber)))
		{
			cout << "Account number is not found, please enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsClient ClientTo = clsClient::Find(AccountNumber);
		_PrintClient(ClientTo);

		cout << "Please enter transfer amount: ";
		float TransferAmount = clsInputValidation::ReadPositiveFloat("Please enter positive transfer amount: ", "Invalid number, please try again: ");

		while (ClientFrom.isBalanceExceed(TransferAmount))
		{
			cout << "\nError: transfer amount is larger than account balance, please try again: ";
			TransferAmount = clsInputValidation::ReadPositiveFloat("Please enter positive transfer amount: ", "Invalid number, please try again: ");
		}

		cout << "\nAre you sure you want to make this transaction? (yes:1, no:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();

		if (isUpdate)
		{
			ClientFrom.Transfer(ClientTo, TransferAmount);
			cout << "\nTransaction has been made successfully :-)\n";
		}
		else
			cout << "\nTransaction failed :-(\n\n";

		_PrintClient(ClientFrom);
		_PrintClient(ClientTo);
	}

};

