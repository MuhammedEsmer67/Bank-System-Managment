#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsFindUserScreen : protected clsScreen
{
private:

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

	static void FindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName = "";

		cout << "Please enter user name: ";
		UserName = clsInputValidation::ReadString();

		while (!(clsUser::isUserExist(UserName)))
		{
			cout << "User name is not found, please enter another one: ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (User.isEmpty())
			cout << "\nUser is empty :-(\n";
		else
			cout << "\nUser Found :-)\n";

		_PrintUser(User);
	}
};

