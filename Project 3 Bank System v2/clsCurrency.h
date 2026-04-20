#pragma once
#include "clsString.h"
#include "clsDate.h"
#include "clsUtility.h"
#include <fstream>
#include <string>

class clsCurrency
{
private:

	enum enMode { Empty = 1, Update = 2 };

	enMode _Mode;
	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _CurrencyRate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Delim = "#//#")
	{
		vector <string> vCurrencyObject = clsString::Split(Line, Delim);

		return clsCurrency(enMode::Update, vCurrencyObject[0], vCurrencyObject[1], vCurrencyObject[2], stof(vCurrencyObject[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Delim = "#//#")
	{
		return Currency.getCountryName() + Delim + Currency.getCurrencyCode() + Delim + Currency.getCurrencyName() + Delim + to_string(Currency.getCurrencyRate());
	}

	static vector <clsCurrency> _LoadDataFile()
	{
		vector <clsCurrency> vCurrency;
		fstream File;

		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			
			while (getline(File, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
		}

		File.close();

		return vCurrency;
	}

	static void _SaveDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (File.is_open())
		{
			string Line = "";

			for (clsCurrency& Currency : vCurrencies)
			{
				Line = _ConvertCurrencyObjectToLine(Currency);
				File << Line << endl;
			}
		}

		File.close();
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadDataFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.getCountryName() == _CountryName)
			{
				Currency = *this;
				break;
			}
		}

		_SaveDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyObject() { return clsCurrency(enMode::Empty, "", "", "", 0); }

public:

	clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float CurrencyRate)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_CurrencyRate = CurrencyRate;
	}

	string getCountryName() { return _CountryName; }

	string getCurrencyCode() { return _CurrencyCode; }

	string getCurrencyName() { return _CurrencyName; }

	static vector <clsCurrency> GetCurrenciesList() { return _LoadDataFile(); }

	float getCurrencyRate() { return _CurrencyRate; }

	void UpdateCurrencyRate(float CurrencyRate)
	{
		_CurrencyRate = CurrencyRate;
		_Update();
	}

	bool isEmpty()
	{
		return (_Mode == enMode::Empty);
	}

	static vector <clsCurrency> FindEntireCurrencyCodes(string CurrencyCode)
	{
		vector <clsCurrency> vCurrenciesData = _LoadDataFile();
		vector <clsCurrency> vCurrencies;

		for (clsCurrency& Currency : vCurrenciesData)
		{
			if (Currency.getCurrencyCode() == clsString::ToUpperCase(clsString::Trim(CurrencyCode)))
				vCurrencies.push_back(Currency);
		}

		return vCurrencies;
	}

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{
		vector <clsCurrency> vCurrencies = _LoadDataFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (clsString::ToUpperCase(Currency.getCurrencyCode()) == clsString::ToUpperCase(clsString::Trim(CurrencyCode)))
				return Currency;
		}

		return _GetEmptyObject();
	}

	static clsCurrency FindByCountryName(string CountryName)
	{
		vector <clsCurrency> vCurrencies = _LoadDataFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (clsString::ToUpperCase(Currency.getCountryName()) == clsString::ToUpperCase(CountryName))
				return Currency;
		}

		return _GetEmptyObject();
	}

	static bool isCurrencyExistByCountryName(string CountryName)
	{
		clsCurrency Currency = FindByCountryName(CountryName);

		return (!Currency.isEmpty());
	}

	static bool isCurrencyExistByCurrencyCode(string CurrencyCode)
	{
		clsCurrency Currency = FindByCurrencyCode(CurrencyCode);

		return (!Currency.isEmpty());
	}

	float ToUSD(float Amount)
	{
		return Amount / _CurrencyRate;
	}

	float FromCurrencyToAnother(clsCurrency CurrencyTo, float Amount)
	{
		float USDAmount = ToUSD(Amount);

		if (CurrencyTo.getCurrencyCode() == "USD")
			return USDAmount;

		return USDAmount * CurrencyTo.getCurrencyRate();
	}

};

