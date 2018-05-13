#include "bank_account.h"
using namespace std;

int main(void) {
    int select = 0;
    int inAccount = 0;
    int inPassword = 0;
    string inName;
    account_List * head = new account_List;
    
    head -> Link = NULL;
    while(1){
        cout << "-----------" << endl;
        cout << "1. 계좌 관리" << endl;
        cout << "2. 출력" << endl;
        cout << "3. 계좌 삭제" << endl;
        cout << "0 .종료" << endl;
        cout << "-----------" << endl;
        cout << "입력 :" ;
        cin >> select;
        
        switch (select) {
            case 1:
                cout << "계좌를 입력하세요 : (7자리)";
                cin >> inAccount;
                cout << "이름을 입력하세요 : ";
                cin >> inName;
                cout << "비밀번호를 입력하세요 : ";
                cin >> inPassword;
                addFirst(head, inAccount, inName, inPassword);
                break;
                
            case 2:
                linkPrint(head -> Link);
                break;
                
            case 3:
              
                break;
                
            case 0:
                return 0;
                
            default:
                return 0;
        }
    }
   
    
    
    return 0;
}
