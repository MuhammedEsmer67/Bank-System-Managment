#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsUpdateRateScreen : protected clsScreen
{
private:

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

public:

	static void UpdateRateScreen()
	{
		_DrawScreenHeader("Update Rate Screen");

		cout << "Please enter country name: ";
		string CountryName = clsInputValidation::ReadText();

		while (!clsCurrency::isCurrencyExistByCountryName(CountryName))
		{
			cout << "Invalid country name, please try again: ";
			CountryName = clsInputValidation::ReadText();
		}

		clsCurrency Currency = clsCurrency::FindByCountryName(CountryName);
		_PrintCurrency(Currency);

		cout << "Please enter new currency rate: ";
		float CurrencyRate = clsInputValidation::ReadPositiveFloat("Please enter positive number: ", "Invalid number, please try again: ");

		cout << "\nAre you sure you want to update this currency? (Yes:1, No:0) ";
		bool isUpdate = clsInputValidation::ReadBoolean();

		if (isUpdate)
		{
			Currency.UpdateCurrencyRate(CurrencyRate);
			cout << "\nCurrency rate updated successfully :-)\n";
			_PrintCurrency(Currency);
		}
		else
			cout << "\nCurrency updated failed :-(\n\n";
	}

};

