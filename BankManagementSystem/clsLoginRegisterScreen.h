#pragma once
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintRegisterRecord(clsUser::stUserLoginData UserData)
	{
		cout << clsUtility::Tabs(2) << " | " << left << setw(30) << UserData.Date;
		cout << clsUtility::Tabs(2) << " | " << left << setw(20) << UserData.UserName;
		cout << clsUtility::Tabs(2) << " | " << left << setw(12) << UserData.Password;
		cout << clsUtility::Tabs(2) << " | " << left << setw(12) << UserData.Permissions << endl;
	}

public:

	static void LoginRegisterScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::LoginRegister))
			return;

		vector <clsUser::stUserLoginData> vUsersData = clsUser::LoadRegisterLoginData();

		string Title = "Login Register List Screen", SubTitle = "(" + to_string(vUsersData.size()) + ")" + " Record(s)";
		_DrawScreenHeader(Title, SubTitle, 4);

		cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2) << " | " << left << setw(30) << "Date - Time";
		cout << clsUtility::Tabs(2) << " | " << left << setw(20) << "User Name";
		cout << clsUtility::Tabs(2) << " | " << left << setw(12) << "Password";
		cout << clsUtility::Tabs(2) << " | " << left << setw(12) << "Permissions\n";
		cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________________\n\n";

		if(vUsersData.size()==0)
			cout << clsUtility::Tabs(7) << "No register records avalaible on the system.\n";

		else
		{
			for (clsUser::stUserLoginData User : vUsersData)
				_PrintRegisterRecord(User);

			cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________________\n\n";
		}
	}

};

