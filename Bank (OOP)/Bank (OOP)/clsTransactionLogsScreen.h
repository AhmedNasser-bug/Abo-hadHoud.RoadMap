#pragma once
#include "clsScreen.h"
class clsTransactionLogs :
    public clsScreen
{
private:
    

    static inline void PrintTransferLogRecordLine(clsBankClient::stTransactionLog TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Date;
        cout << "| " << setw(8) << left << TransferLogRecord.SenderAccNum;
        cout << "| " << setw(8) << left << TransferLogRecord.RecieverAccNum;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SenderBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.RecieverBalance;
        cout << "| " << setw(8) << left << TransferLogRecord.CurrentUserName;


    } inline void _PrintTransactionLog( clsBankClient::stTransactionLog TransactionLog) {

    }

public:

    static inline void ShowTransactionLogsScreen() {

        PrintScreenTitle("Transaction Logs");

        vector<clsBankClient::stTransactionLog> TransactionLogs = clsBankClient::LoadTransferLogsFromFile();

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (TransactionLogs.size() == 0) {
            cout << "\t\t\t\tNo Transfers Available In the System!";
            return;
        }

        for (clsBankClient::stTransactionLog Record : TransactionLogs)
        {

            PrintTransferLogRecordLine(Record);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
    
};

