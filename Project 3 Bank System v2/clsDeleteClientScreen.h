#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidation.h"

class clsDeleteClientScreen : protected clsScreen
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

	static void DeleteClient()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::DeleteClient))
			return;

		_DrawScreenHeader("Delete Client Screen");

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
	
		cout << "\nAre you sure you want to delete this client? (yes:1, no:0): ";
		bool isDelete = clsInputValidation::ReadBoolean();
	
		if (isDelete)
		{
			Client.DeleteClient();
			cout << "\nClient deleted successfully :-)\n";
			_PrintClient(Client);
		}
		else
			cout << "\nFailed, cliend have not deleted.\n\n";
	}

};

