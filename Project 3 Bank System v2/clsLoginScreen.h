#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "GlobalUser.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string UserName = "", Password = "";
		bool LoginFailed = false;
		short LoginTrials = 3;

		do
		{
			LoginTrials--;

			cout << "Please enter username: ";
			UserName = clsInputValidation::ReadString();

			cout << "Please enter password: ";
			Password = clsInputValidation::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.isEmpty();

			if (LoginTrials && LoginFailed)
			{
				cout << "\nInvalid username/password please try again.\n";
				cout << LoginTrials << " trial(s) left.\n\n";
			}

		} while (LoginTrials && LoginFailed);

		if (!LoginTrials && LoginFailed)
		{
			cout << "\nLogin locked after 3 failed trials.\n\n";
			return false;
		}

		CurrentUser.SaveLoginRegister();
		clsMainScreen::ShowMainMenuScreen();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}

};

