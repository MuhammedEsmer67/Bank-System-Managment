#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsUpdateUserScreen : protected clsScreen
{
private:

	static short _ReadPermissions()
	{
		bool isGive = false;
		short Permissions = 0;

		cout << "Do you want to give user full access? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
		{
			Permissions = clsUser::enPermissions::All;
			return Permissions;
		}

		cout << "Do you want to give user access to list clients? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::ListClients;

		cout << "Do you want to give user access to add new client? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::AddNewClient;

		cout << "Do you want to give user access to delete client? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::DeleteClient;

		cout << "Do you want to give user access to update client? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::UpdateClient;

		cout << "Do you want to give user access to find client? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::FindClient;

		cout << "Do you want to give user access to transactions? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::Transactions;

		cout << "Do you want to give user access to login register screen? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::LoginRegister;

		cout << "Do you want to give user access to currency exchange screen? (Yes:1, No:0) ";
		isGive = clsInputValidation::ReadBoolean();
		if (isGive)
			Permissions += clsUser::enPermissions::CurrencyExchange;

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "First Name: ";
		User.setFirstName(clsInputValidation::ReadText());

		cout << "Last Name: ";
		User.setLastName(clsInputValidation::ReadText());

		cout << "Email: ";
		User.setEmail(clsInputValidation::ReadString());

		cout << "Phone Number: ";
		User.setPhoneNumber(clsInputValidation::ReadString());

		cout << "Password: ";
		User.setPassword(clsInputValidation::ReadString());

		cout << "Permissions:\n\n";
		User.setPermissions(_ReadPermissions());
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n_____________________________________________\n\n";
		cout << "User Name    : " << User.getUserName() << endl;
		cout << "Password     : " << User.getPassword() << endl;
		cout << "Full Name    : " << User.GetFullName() << endl;
		cout << "Email        : " << User.getEmail() << endl;
		cout << "Phone Number : " << User.getPhoneNumber() << endl;
		cout << "Permissions  : " << User.getPermissions() << endl;
		cout << "_____________________________________________\n\n";
	}

public:

	static void UpdateUser()
	{
		_DrawScreenHeader("Update User Screen");

		string UserName = "";

		cout << "Please enter user name: ";
		UserName = clsInputValidation::ReadString();

		while (!(clsUser::isUserExist(UserName)))
		{
			cout << "User name is not found, please enter another one: ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);
		cout << "\nUpdate User:\n\n";
		_ReadUserInfo(User);

		cout << "\nAre you sure you want to update this user? (yes:1, no:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();

		if (isUpdate)
		{
			clsUser::enSaveResults Results = User.Save();

			switch (Results)
			{
			case clsUser::EmptyObject:
			{
				cout << "\nError: user was not saved because it's empty.\n\n";
				break;
			}
			case clsUser::FilledObject:
			{
				cout << "\nUser updated successfully :-)\n\n";
				break;
			}
			}
		}
		else
			cout << "\nUpdated Failed.\n\n";
	}

};

