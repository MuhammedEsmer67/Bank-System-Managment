#pragma once
#include "clsScreen.h"
#include "clsClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogRecord(clsClient::stTransferLogInfo TransferLog)
	{
		cout << clsUtility::Tabs(1) << " | " << left << setw(25) << TransferLog.Date;
		cout << " | " << left << setw(15) << TransferLog.SourceAccountNumber;
		cout << " | " << left << setw(15) << TransferLog.DestinationAccountNumber;
		cout << " | " << left << setw(15) << TransferLog.TransferAmount;
		cout << " | " << left << setw(15) << TransferLog.SourceAccountBalance;
		cout << " | " << left << setw(15) << TransferLog.DestinationAccountBalance;
		cout << " | " << left << setw(17) << TransferLog.UserName << endl;
	}

public:

	static void TransferLogScreen()
	{
		vector <clsClient::stTransferLogInfo> vTransferLogData = clsClient::LoadTransferData();

		string Title = "Transfer Log List Screen", SubTitle = "(" + to_string(vTransferLogData.size()) + ")" + " Record(s)";
		_DrawScreenHeader(Title, SubTitle, 4);

		cout << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(1) << " | " << left << setw(25) << "Date - Time";
		cout << " | " << left << setw(15) << "s.Acc No";
		cout << " | " << left << setw(15) << "d.Acc No";
		cout << " | " << left << setw(15) << "T.Amount";
		cout << " | " << left << setw(15) << "s.Balance";
		cout << " | " << left << setw(15) << "d.Balance";
		cout << " | " << left << setw(17) << "User Name";
		cout << endl << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";

		if (vTransferLogData.size() == 0)
			cout << clsUtility::Tabs(7) << "No transfer log records avalaible on the system.\n";

		else
		{
			for (clsClient::stTransferLogInfo TransferLog : vTransferLogData)
				_PrintTransferLogRecord(TransferLog);

			cout << clsUtility::Tabs(1) << "___________________________________________________________________________________________________________________________________\n\n";
		}
	}

};

