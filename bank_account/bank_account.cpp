#include "bank_account.h"

void addFirst(account_List * targetLink , int &inAccount, string &inName, int &inPasssword){
    cout << "이름을 입력하세요 : ";
//    cin >> inName;
    getline(cin, inName);
    cout << "계좌를 입력하세요 : (7자리)";
    cin >> inAccount;
    cout << "비밀번호를 입력하세요 : ";
    cin >> inPasssword;
    
    account_List * newLink = new account_List;
    
    newLink -> Link = targetLink -> Link;
    targetLink -> Link = newLink;
    newLink -> accountNum = inAccount;
    newLink -> name = inName;
    newLink -> password = inPasssword;
}

void linkPrint(account_List * printFirst){
    account_List * curr = printFirst;
    
    while(curr != NULL)
    {
        cout << endl;
        cout << "이름 : " << curr -> name << endl;
        cout << "계좌 : " << curr -> accountNum << endl;
        cout << "잔액 :" << curr -> money << endl;
        cout << "비밀번호 : " << curr -> password << endl;
        curr = curr -> Link;
    }
}

void removeList(account_List * currPostion, int removeAccount){
    account_List * deleteAccount;
    
//    if(currPostion -> Link == NULL){
//        cout << "데이터가 없습니다." << endl;
//    }
    while(1)
    {
        if(currPostion -> Link == NULL){
            cout << "계좌가 존제하지 않습니다." << endl;
            break;
        }
        
        else if(currPostion -> Link -> accountNum == removeAccount){
            int comparePassword;
            cout << "비밀번호를 입력하세요 :";
            cin >> comparePassword;
            if(comparePassword != currPostion -> Link -> password){
                cout << "비밀번호가 틀립니다." << endl;
                break;
            }
            
            
            deleteAccount = currPostion -> Link;
            currPostion -> Link = currPostion -> Link -> Link;
            delete(deleteAccount);
            break;
        }
        
        currPostion = currPostion -> Link;
    }
}

account_List * compareAccount (account_List * currPostion, int compareData){
    while(1)
    {
        if(currPostion -> Link == NULL){
            cout << "계좌가 존제하지 않습니다." << endl;
            break;
        }
        
        else if(currPostion -> Link -> accountNum == compareData){
            return currPostion -> Link;
        }
        currPostion = currPostion -> Link;
    }
    return NULL;
}

void inMoney(account_List * inMoneyAcc, int addMoney){
    inMoneyAcc -> money += addMoney;
}
void outMoney(account_List * outMoneyAcc, int minMoney){
    outMoneyAcc -> money -= minMoney;
}
