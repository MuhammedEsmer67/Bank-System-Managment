#pragma once
#include "clsClient.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsUpdateClientScreen : protected clsScreen
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

	static void UpdateClient()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::UpdateClient))
			return;

		_DrawScreenHeader("Update Client Screen");

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
		cout << "\nUpdate Client:\n\n";
		_ReadClientInfo(Client);
		
		cout << "\nAre you sure you want to update this client? (yes:1, no:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();
		
		if(isUpdate)
		{
			clsClient::enSaveResults Results = Client.Save();

			switch (Results)
			{
			case clsClient::EmptyObject:
			{
				cout << "\nError: account was not saved because it's empty.\n\n";
				break;
			}
			case clsClient::FilledObject:
			{
				cout << "\nAccount updated successfully :-)\n\n";
				break;
			}
			}
		}
		else
			cout << "\nUpdated Failed.\n\n";
	}

};

