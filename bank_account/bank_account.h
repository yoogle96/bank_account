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

void addFirst(account_List * targetLink , int addAccount, string addName, int addPasssword);
void linkPrint(account_List * curr);
//void remove_account()




#endif /* bank_account_h */
