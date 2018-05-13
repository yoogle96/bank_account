#include "bank_account.h"

void addFirst(account_List * targetLink , int addAccount, string addName, int addPasssword){
    account_List * newLink = new account_List;
    
    newLink -> Link = targetLink -> Link;
    targetLink -> Link = newLink;
    newLink -> accountNum = addAccount;
    newLink -> name = addName;
    newLink -> password = addPasssword;
}

void linkPrint(account_List * printFirst){
    account_List * curr = printFirst;
    
    while(curr != NULL)
    {
        cout << endl;
        cout << "이름 : " << curr -> name << endl;
        cout << "계좌 : " << curr -> accountNum << endl;
        cout << "비밀번호 : " << curr -> password << endl;
        curr = curr -> Link;
    }
}
