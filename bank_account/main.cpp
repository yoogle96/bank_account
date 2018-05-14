#include "bank_account.h"
using namespace std;

int main(void) {
    int select = 0;
    int case1_Select = 0;
    int inAccount = 0;
    int inPassword = 0;
    int removeAccount;
    string inName;
    account_List * head = new account_List;
    
    head -> Link = NULL;
    while(1){
        cout << "-----------" << endl;
        cout << "1. 계좌 관리" << endl;
        cout << "2. 잔액 관리" << endl;
        cout << "3. 출력" << endl;
        cout << "0 .종료" << endl;
        cout << "-----------" << endl;
        cout << "입력 :" ;
        cin >> select;
        
        switch (select) {
            case 1:
                cout << "1. 계좌 생성" << endl;
                cout << "2. 계좌 삭제" << endl;
                cout << "입력 :";
                cin >> case1_Select;
                
                cin.clear();                // 입력 버퍼 지우기
                cin.ignore(1000, '\n');     // 입력 버퍼 지우기
                
                if(case1_Select == 1)       // 계좌 생성 선택
                    addFirst(head, inAccount, inName, inPassword);
                
                else if(case1_Select == 2){ // 계좌 삭제 선택
                    cout << "삭제할 계좌의 계좌번호를 입력하세요 : ";
                    cin >> removeAccount;
                    removeList(head, removeAccount);
                }
                
                else
                    cout << "잘못된 정보를 입력하셨습니다." << endl;
                break;
                
            case 2:
                account_List * accountMoney; // 계좌번호를 찾아서 그 계좌의 노드(주소)를 저장할 공간을 생성
                int money; // 사용자가 입력할 입출금 금액
                
                cout << "계좌번호를 입력하세요 :";
                cin >> inAccount;
                accountMoney = compareAccount(head , inAccount); // compareAccount 함수에 head의 주소와 사용자가 입력한 계좌를 넘겨줘서 비교한후 compareAccount 함수에서 비교하여 일치 하는 노드의 주소를 반환해 accountMoney 공간에 저장
                if(accountMoney == NULL) // 일치하는 값이 없으면 NULL을 반환함으로써 NULL일경우 case2를 탈출
                    break;
                
                cout << "비밀번호를 입력하세요 : ";
                cin >> inPassword;
                
                if(accountMoney -> password != inPassword){
                    cout << "비밀번호가 틀렸습니다." << endl;
                    break;
                }
                cout << "1. 입금" <<endl;
                cout << "2. 출금" <<endl;
                cin >> select;
                
                if(select == 1) // 입금을 선택할경우
                {
                    cout << "입금할 금액을 입력하세요 : ";
                    cin >> money;
                    inMoney(accountMoney, money); // inMoney함수에 현재 저장돼있는 accountMoney와 금액을 보내줌으로써 함수안에서 잔액을 추가한다.
                }
                else if(select == 2) // 출금을 선택할경우
                {
                    cout << "출금할 금액을 입력하세요 :";
                    cin >> money;
                    outMoney(accountMoney, money); // outMoney함수에 현재 저장돼있는 accountMoney와 금액을 보내줌으로써 함수안에서 잔액을 절감?한다.
                }
                else
                {
                    cout << "잘못된 값을 입력하셨습니다." <<endl;
                }
                break;
                
            case 3:
                    linkPrint(head -> Link);
                break;
                
            case 0:
                return 0;
                
            default:
                return 0;
        }
    }
    return 0;
}
