#pragma once
#include "clsClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsClient& Client)
	{
		cout << "First Name: ";
		Client.setFirstName(clsInputValidation::ReadText());

		cout << "Last Name: ";
		Client.setLastName(clsInputValidation::ReadText());

		cout << "Email: ";
		Client.setEmail(clsInputValidation::ReadString());

		cout << "Phone Number: ";
		Client.setPhoneNumber(clsInputValidation::ReadString());

		cout << "Pin Code: ";
		Client.setPinCode(clsInputValidation::ReadString());

		cout << "Account Balance: ";
		Client.setAccountBalance(clsInputValidation::ReadPositiveFloat("Failed, please enter a positive number: ", "Invalid number, please try again: "));
	}
	
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

	static void AddNewClient()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::AddNewClient))
			return;

		clsScreen::_DrawScreenHeader("Add New Client Screen");

		string AccountNumber = "";

		cout << "Please enter account number: ";
		AccountNumber = clsInputValidation::ReadString();

		while (clsClient::isClientExist(AccountNumber))
		{
			cout << "Account number is already used, enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsClient NewClient = clsClient::GetNewClient(AccountNumber);

		cout << "\nAdd New Client:\n\n";
		_ReadClientInfo(NewClient);
		_PrintClient(NewClient);

		cout << "\nAre you sure you want to add new client? (yes:1, no:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();

		if(isUpdate)
		{
			clsClient::enSaveResults Results = NewClient.Save();

			switch (Results)
			{
			case clsClient::enSaveResults::EmptyObject:
			{
				cout << "\nError: account was not saved because it's empty.\n\n";
				break;
			}
			case clsClient::enSaveResults::AccountNumberExist:
			{
				cout << "\nError: account was not saved because account number is used!\n\n";
				break;
			}
			case clsClient::enSaveResults::FilledObject:
			{
				cout << "\nAccount added successfully :-)\n\n";
				break;
			}
			}
		}

		else
			cout << "\Adding Failed.\n\n";

	}

};

