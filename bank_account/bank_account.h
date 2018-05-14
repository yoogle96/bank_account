#ifndef bank_account_h
#define bank_account_h
#include <iostream>
#include <string>

using namespace std;

struct account_List{
    account_List * Link;
    int accountNum;
    string name;
    int password;
    int money = 0;
};

void addFirst(account_List * targetLink , int &inAccount, string &inName, int &inPasssword);
void linkPrint(account_List * curr);
void removeList(account_List * currPostion, int removeAccount);
account_List * compareAccount (account_List * currPostion, int compareData);
void inMoney(account_List * inMoneyAcc, int addMoney);
void outMoney(account_List * outMoneyAcc, int minMoney);





#endif /* bank_account_h */
