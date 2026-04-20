#pragma once
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionOptionType { Deposit = 1, Withdraw = 2, ShowTotalBalances = 3, Transfer = 4, TransferLog = 5, MainMenu = 6 };

	static short _ReadTransactionOption()
	{
		cout << clsUtility::Tabs(4) << "Choose any option? (1 to 6) ";
		short OptionType = clsInputValidation::ReadShortBetween(1, 6, clsUtility::Tabs(4) + "Choose number between 1 and 6. ",
			clsUtility::Tabs(4) + "Invalid number, please try again. ");

		return OptionType;
	}

	static void _DepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _WithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _TransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::TransferLogScreen();
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "please press any key to go back to transactions menu screen... ";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _PerformTransactionsMenuOption(enTransactionOptionType OptionType)
	{
		switch (OptionType)
		{
		case enTransactionOptionType::Deposit:
		{
			system("cls");
			_DepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionOptionType::Withdraw:
		{
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionOptionType::ShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionOptionType::Transfer:
		{
			system("cls");
			_TransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionOptionType::TransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		default: { }
		}
	}

public:

	static void ShowTransactionsMenu()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::Transactions))
			return;

		_DrawScreenHeader("Transactions Screen");

		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(6) << "Transactions Menu\n";
		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(4) << "   [1] Deposit.\n";
		cout << clsUtility::Tabs(4) << "   [2] Withdraw.\n";
		cout << clsUtility::Tabs(4) << "   [3] Total Balances.\n";
		cout << clsUtility::Tabs(4) << "   [4] Transfer.\n";
		cout << clsUtility::Tabs(4) << "   [5] Transfer Log.\n";
		cout << clsUtility::Tabs(4) << "   [6] Main Menu.\n";
		cout << clsUtility::Tabs(4) << "============================================\n";

		_PerformTransactionsMenuOption(enTransactionOptionType(_ReadTransactionOption()));
	}

};

