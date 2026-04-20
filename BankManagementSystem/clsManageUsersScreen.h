#pragma once
#include "clsShowUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersOptionType { 
		ListUsers = 1, AddNewUser = 2, DeleteUser = 3,
		UpdateUser = 4, FindUser = 5, MainMenu = 6 };

	static short _ReadUserMenuOption()
	{
		cout << clsUtility::Tabs(4) << "Choose any option? (1 to 6) ";
		short OptionType = clsInputValidation::ReadShortBetween(1, 6, clsUtility::Tabs(4) + "Choose number between 1 and 6. ",
			clsUtility::Tabs(4) + "Invalid number, please try again. ");

		return OptionType;
	}

	static void _ShowUsersListScreen()
	{
		clsShowUserListScreen::ShowUserListScreen();
	}

	static void _AddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}

	static void _DeleteUserScreen()
	{
		clsDleteUserScreen::DeleteUser();
	}

	static void _UpdateUserScreen()
	{
		clsUpdateUserScreen::UpdateUser();
	}

	static void _FindUserScreen()
	{
		clsFindUserScreen::FindUserScreen();
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "please press any key to go back to manage users menu screen... ";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _PerformManageUsersMenuOption(enManageUsersOptionType OptionType)
	{
		switch (OptionType)
		{
		case enManageUsersOptionType::ListUsers:
		{
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOptionType::AddNewUser:
		{
			system("cls");
			_AddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOptionType::DeleteUser:
		{
			system("cls");
			_DeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOptionType::UpdateUser:
		{
			system("cls");
			_UpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOptionType::FindUser:
		{
			system("cls");
			_FindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		default: { }
		}
	}

public:

	static void ShowManageUsersMenu()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::ManageUsers))
			return;

		_DrawScreenHeader("Manage Users Screen");

		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(6) << "Manage Users Menu\n";
		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(4) << "   [1] Show Users List.\n";
		cout << clsUtility::Tabs(4) << "   [2] Add New User.\n";
		cout << clsUtility::Tabs(4) << "   [3] Delete User.\n";
		cout << clsUtility::Tabs(4) << "   [4] Update User.\n";
		cout << clsUtility::Tabs(4) << "   [5] Find User.\n";
		cout << clsUtility::Tabs(4) << "   [6] Main Menu.\n";
		cout << clsUtility::Tabs(4) << "============================================\n";

		_PerformManageUsersMenuOption(enManageUsersOptionType(_ReadUserMenuOption()));
	}

};

