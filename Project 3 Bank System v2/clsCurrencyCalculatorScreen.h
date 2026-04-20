#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n_____________________________________________\n\n";
		cout << "Country Name      : " << Currency.getCountryName() << endl;
		cout << "Currency Code     : " << Currency.getCurrencyCode() << endl;
		cout << "Currency Name     : " << Currency.getCurrencyName() << endl;
		cout << "Currency Rate(1$) : " << Currency.getCurrencyRate() << endl;
		cout << "_____________________________________________\n\n";
	}

	static clsCurrency _ReadCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = clsInputValidation::ReadString();

		while (!clsCurrency::isCurrencyExistByCurrencyCode(CurrencyCode))
		{
			cout << "\nInvalid currency code, please try again: ";
			CurrencyCode = clsInputValidation::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		return Currency;
	}

	static void _CurrencyCalculations(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		cout << "\nConvert From:";
		_PrintCurrency(CurrencyFrom);

		if (!(CurrencyFrom.getCurrencyCode() == "USD"))
		{
			float USDAmount = CurrencyFrom.ToUSD(Amount);

			cout << Amount << " " << CurrencyFrom.getCurrencyCode() << " = " << USDAmount << " USD " << endl;

			if (CurrencyTo.getCurrencyCode() == "USD")
				return;
		}

		float ForeignAmount = CurrencyFrom.FromCurrencyToAnother(CurrencyTo, Amount);

		cout << "\nConverting from USD to:";
		_PrintCurrency(CurrencyTo);

		cout << Amount << " " << CurrencyFrom.getCurrencyCode() << " = " << ForeignAmount << " " << CurrencyTo.getCurrencyCode() << endl;
	}

public:

	static void CurrencyCalculatorScreen()
	{
		bool isPerform = true;

		while (isPerform)
		{
			system("cls");

			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyFrom = _ReadCurrency("Please enter currency code to convert from: ");
			clsCurrency CurrencyTo = _ReadCurrency("Please enter currency code to convert to: ");

			cout << "\nPlease enter amount to exchange: ";
			float ExchangeAmount = clsInputValidation::ReadPositiveFloat("Please enter a positive number: ", "Invalid number, please try again: ");

			_CurrencyCalculations(CurrencyFrom, CurrencyTo, ExchangeAmount);

			cout << "\nDo you want to perform another calculation? (Yes:1, No:0) ";
			isPerform = clsInputValidation::ReadBoolean();
			cout << endl;
		}
	}

};

