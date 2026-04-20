#pragma once
#include "clsScreen.h"
#include "clsListCurrencies.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOptionType { ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4, MainMenu = 5 };

	static short _ReadCurrencyExchangeOption()
	{
		cout << clsUtility::Tabs(4) << "Choose any option? (1 to 5) ";
		short OptionType = clsInputValidation::ReadShortBetween(1, 5, clsUtility::Tabs(4) + "Choose number between 1 and 5. ",
			clsUtility::Tabs(4) + "Invalid number, please try again. ");

		return OptionType;
	}

	static void _ListCurrenciesScreen()
	{
		clsListCurrencies::ShowListCurrenciesScreen();
	}

	static void _FindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _UpdateRateScreen()
	{
		clsUpdateRateScreen::UpdateRateScreen();
	}

	static void _CurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::CurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "please press any key to go back to currency exchange menu screen... ";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _PerformCurrencyExchangeOption(enCurrencyExchangeOptionType OptionType)
	{
		switch (OptionType)
		{
		case enCurrencyExchangeOptionType::ListCurrencies:
		{
			system("cls");
			_ListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptionType::FindCurrency:
		{
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptionType::UpdateRate:
		{
			system("cls");
			_UpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case enCurrencyExchangeOptionType::CurrencyCalculator:
		{
			_CurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		default: {}
		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::CurrencyExchange))
			return;

		_DrawScreenHeader("Currency Exchange Screen");

		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(5) << "    Currency Exchange Menu\n";
		cout << clsUtility::Tabs(4) << "============================================\n";
		cout << clsUtility::Tabs(4) << "   [1] List Currencies.\n";
		cout << clsUtility::Tabs(4) << "   [2] Find Currency.\n";
		cout << clsUtility::Tabs(4) << "   [3] Update Rate.\n";
		cout << clsUtility::Tabs(4) << "   [4] Currency Calculator.\n";
		cout << clsUtility::Tabs(4) << "   [5] Main Menu.\n";
		cout << clsUtility::Tabs(4) << "============================================\n";

		_PerformCurrencyExchangeOption(enCurrencyExchangeOptionType(_ReadCurrencyExchangeOption()));
	}

};

