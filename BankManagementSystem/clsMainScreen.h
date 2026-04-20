#pragma once
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsLoginScreen.h"
#include "GlobalUser.h"

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptionType { ListClients = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4,
								FindClient = 5, Transactions = 6, ManageUsers = 7, LoginRegister = 8, CurrencyExchange = 9, Logout = 10 };

	static short _ReadMainMenuOption()
	{
		cout << clsUtility::Tabs(4) << "Choose any option? (1 to 10) ";
		short OptionType = clsInputValidation::ReadShortBetween(1, 10, clsUtility::Tabs(4) + "Choose number between 1 and 10. ",
																clsUtility::Tabs(4) + "Invalid number, please try again. ");

		return OptionType;
	}

	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientListScreen();
	}

	static void _AddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _DeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _UpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _FindClientScreen()
	{
		clsFindClientScreen::FindClient();
	}

	static void _TransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::LoginRegisterScreen();
	}

	static void _CurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("");
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nplease press any key to go back to main menu screen... ";
		system("pause>0");
		ShowMainMenuScreen();
	}

	static void _PerformMainMenuOption(enMainMenuOptionType OptionType)
	{
		switch (OptionType)
		{
		case enMainMenuOptionType::ListClients:
		{
			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::AddNewClient:
		{
			system("cls");
			_AddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::DeleteClient:
		{
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::UpdateClient:
		{
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::FindClient:
		{
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::Transactions:
		{
			_TransactionsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::ManageUsers:
		{
			_ManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::LoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptionType::CurrencyExchange:
		{
			_CurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		default:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public:

	static void ShowMainMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Menu Screen");

		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(6) << "Main Menu\n";
		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(4) << "   [1] Show Client List.\n";
		cout << clsUtility::Tabs(4) << "   [2] Add New Client.\n";
		cout << clsUtility::Tabs(4) << "   [3] Delete Client.\n";
		cout << clsUtility::Tabs(4) << "   [4] Update Client.\n";
		cout << clsUtility::Tabs(4) << "   [5] Find Client.\n";
		cout << clsUtility::Tabs(4) << "   [6] Transactions.\n";
		cout << clsUtility::Tabs(4) << "   [7] Manage Users.\n";
		cout << clsUtility::Tabs(4) << "   [8] Show Login Register.\n";
		cout << clsUtility::Tabs(4) << "   [9] Currency Exchange.\n";
		cout << clsUtility::Tabs(4) << "   [10] Logout.\n";
		cout << clsUtility::Tabs(4) << "============================================\n";

		_PerformMainMenuOption(enMainMenuOptionType(_ReadMainMenuOption()));
	}

};

