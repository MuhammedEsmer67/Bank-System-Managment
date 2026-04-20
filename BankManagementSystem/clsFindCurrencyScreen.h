#pragma once
#include "clsScreen.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enCurrencyOption { CurrencyCode = 1, CountryName = 2};

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_____________________________________________\n\n";
		cout << "Country Name      : " << Currency.getCountryName() << endl;
		cout << "Currency Code     : " << Currency.getCurrencyCode() << endl;
		cout << "Currency Name     : " << Currency.getCurrencyName() << endl;
		cout << "Currency Rate(1$) : " << Currency.getCurrencyRate() << endl;
		cout << "_____________________________________________\n\n";
	}

	static void _FindByCurrencyCode()
	{
		string CurrencyCode = "";
		cout << "\nPlease enter currency code: ";
		CurrencyCode = clsInputValidation::ReadString();

		vector <clsCurrency> vCurrencies = clsCurrency::FindEntireCurrencyCodes(CurrencyCode);

		while (vCurrencies.size() == 0)
		{
			cout << "Currency code is not found, please enter another currency code: ";
			CurrencyCode = clsInputValidation::ReadString();
			vCurrencies = clsCurrency::FindEntireCurrencyCodes(CurrencyCode);
		}

		if (vCurrencies.size())
		{
			cout << "Currency Found :-)\n\n";

			for (clsCurrency& Currency : vCurrencies)
				_PrintCurrency(Currency);
		}
		else
			cout << "Currency is not exist\n\n";
	}

	static void _FindByCountryName()
	{
		string CountryName = "";
		cout << "\nPlease enter country name: ";
		CountryName = clsInputValidation::ReadText();

		while (!clsCurrency::isCurrencyExistByCountryName(CountryName))
		{
			cout << "Country name is not found, please enter another country name: ";
			CountryName = clsInputValidation::ReadText();
		}

		clsCurrency Currency = clsCurrency::FindByCountryName(CountryName);

		if (Currency.isEmpty())
			cout << "\nCurrency is not exist :-(\n\n";
		else
			cout << "\nCurrency is found :-)\n\n";

		_PrintCurrency(Currency);
	}

	static void _PerformCurrencyOption(enCurrencyOption CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case enCurrencyOption::CurrencyCode:
			_FindByCurrencyCode();
			break;
		case enCurrencyOption::CountryName:
			_FindByCountryName();
			break;
		}
	}

public:

	static void FindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "Find by: [1] Currency Code or [2] Country Name? ";
		_PerformCurrencyOption(enCurrencyOption(clsInputValidation::ReadShortBetween(1, 2, "Error: enter 1 or 2: ", "Invalid number, please try again: ")));

	}

};

