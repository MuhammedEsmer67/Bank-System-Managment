#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"

class clsDleteUserScreen : protected clsScreen
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

	static void DeleteUser()
	{
		_DrawScreenHeader("Delete User Screen");

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

		cout << "\nAre you sure you want to delete this user? (yes:1, no:0): ";
		bool isDelete = clsInputValidation::ReadBoolean();

		if (isDelete)
		{
			User.DeleteUser();
			cout << "\nUser deleted successfully :-)\n";
			_PrintUser(User);
		}
		else
			cout << "\nFailed, user have not deleted.\n\n";
	}

};

