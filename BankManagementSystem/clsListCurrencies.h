#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsListCurrencies : protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << clsUtility::Tabs(2) << " | " << left << setw(30) << Currency.getCountryName();
		cout << " | " << left << setw(20) << Currency.getCurrencyCode();
		cout << " | " << left << setw(30) << Currency.getCurrencyName();
		cout << " | " << left << setw(12) << Currency.getCurrencyRate() << endl;
	}

public:

	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrencyData = clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen", SubTitle = "(" + to_string(vCurrencyData.size()) + ")" + " Record(s)";
		_DrawScreenHeader(Title, SubTitle, 4);

		cout << clsUtility::Tabs(2) << "________________________________________________________________________________________________________\n\n\n";
		cout << clsUtility::Tabs(2) << " | " << left << setw(30) << "Country Name";
		cout << " | " << left << setw(20) << "Currency Code";
		cout << " | " << left << setw(30) << "Currency Name";
		cout << " | " << left << setw(12) << "C.Rate/(1$)\n";
		cout << clsUtility::Tabs(2) << "________________________________________________________________________________________________________\n\n\n";

		for (clsCurrency Currency : vCurrencyData)
			_PrintCurrencyRecord(Currency);

		cout << clsUtility::Tabs(2) << "________________________________________________________________________________________________________\n\n\n";
	}

};

