#pragma once
#include "clsUser.h"
#include "GlobalUser.h"
#include "clsUtility.h"

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "", short Tabs = 3)
	{
		cout << clsUtility::Tabs(Tabs) << "_____________________________________________________________________\n\n";
		cout << clsUtility::Tabs(Tabs + 3) << Title << endl;

		if(SubTitle != "")
			cout << clsUtility::Tabs(Tabs + 3) << SubTitle << endl;

		cout << clsUtility::Tabs(Tabs) << "_____________________________________________________________________\n\n";
		cout << clsUtility::Tabs(Tabs) << "User: " << CurrentUser.getUserName() << endl;
		cout << clsUtility::Tabs(Tabs) << "Date: " << clsDate::FormatDate(clsDate::GetSystemDate()) << endl << endl;
	}

	static bool _CheckAccessRights(clsUser::enPermissions Permission, string Title = "Access Denied Please Contact Your Admin", short Tabs = 3)
	{
		if (!CurrentUser.isPermissionAccessible(Permission))
		{
			cout << clsUtility::Tabs(Tabs) << "_____________________________________________________________________\n\n";
			cout << clsUtility::Tabs(Tabs + 2) << Title << endl;
			cout << clsUtility::Tabs(Tabs) << "_____________________________________________________________________\n\n";
			return false;
		}

		return true;
	}

};

