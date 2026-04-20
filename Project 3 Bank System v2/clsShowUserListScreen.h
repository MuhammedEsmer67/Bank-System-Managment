#pragma once
#include "clsUser.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include <iomanip>

class clsShowUserListScreen : protected clsScreen
{
private:

	static void _PrintUsersRecordLine(clsUser User)
	{
		cout << clsUtility::Tabs(1) << " | " << left << setw(15) << User.getUserName();
		cout << clsUtility::Tabs(1) << " | " << left << setw(20) << User.GetFullName();
		cout << clsUtility::Tabs(1) << " | " << left << setw(12) << User.getPhoneNumber();
		cout << clsUtility::Tabs(1) << " | " << left << setw(20) << User.getEmail();
		cout << clsUtility::Tabs(1) << " | " << left << setw(10) << User.getPassword();
		cout << clsUtility::Tabs(1) << " | " << left << setw(12) << User.getPermissions() << endl;
	}

public:

	static void ShowUserListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "User List Screen";
		string SubTitle = "(" + to_string(vUsers.size()) + ")" + " User(s)";

		_DrawScreenHeader(Title, SubTitle, 4);
		cout << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(1) << " | " << left << setw(15) << "User Name";
		cout << clsUtility::Tabs(1) << " | " << left << setw(20) << "Full Name";
		cout << clsUtility::Tabs(1) << " | " << left << setw(12) << "Phone Number";
		cout << clsUtility::Tabs(1) << " | " << left << setw(20) << "Email Address";
		cout << clsUtility::Tabs(1) << " | " << left << setw(10) << "Password";
		cout << clsUtility::Tabs(1) << " | " << left << setw(12) << "Permissions\n";
		cout << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________\n\n";

		if (vUsers.size() == 0)
			cout << clsUtility::Tabs(7) << "No users avalaible on the system.\n";
		else
		{
			for (clsUser& User : vUsers)
				_PrintUsersRecordLine(User);

			cout << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________\n\n";
		}

	}

};

