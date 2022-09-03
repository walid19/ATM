
#include <iostream>
using namespace std;
 
int CustomerAccountNumber = 12345;
int pinNumber = 54321;
int AccountBalance = 0;
 
bool ValidateCustomerDetails() {
 
    int InputAccountNumber = -1;
    int InputPinNumber = -1;
    bool isAccountInvalid = true;
    bool isPinInvalid = true;
 
    cout << "Welcome!" << endl;
 
    while (isAccountInvalid) {
 
        cout << "Please enter your Bank account number: ";
        cin >> InputAccountNumber;
 
        if (InputAccountNumber == CustomerAccountNumber) {
            isAccountInvalid = false;
        }
        else {
            cout << "Invalid Account Number! Try again." << endl;
        }
    }
    int RetryCount = 3;
    while (isPinInvalid && RetryCount) {
 
        cout << "Enter your Customer PIN: ";
        cin >> InputPinNumber;
 
        if (InputPinNumber == pinNumber) {
            isPinInvalid = false;
        }
        else {
            RetryCount--;
            if(RetryCount)
                cout << "Invalid Customer PIN number! Try again." << endl;
            else
            {
                cout << "Your Account is Locked! 3 retry Reached! Try After some time." << endl;
                return false;
            }
 
        }
 
    }
 
    return true;
 
}
 
int DisplayMenu() {
 
    int UserInputOption = -1;
 
    cout << "Welcome to Your Account!! Please choose Option to Proceed" << endl;
    cout << "    1 - View Your Account balance" << endl;
    cout << "    2 - Withdraw Cash" << endl;
    cout << "    3 - Deposit Cash" << endl;
    cout << "    4 - Exit" << endl;
    cout << "Enter an Option to Proceed: " << endl;
    cin >> UserInputOption;
 
    return UserInputOption;
 
}
 
void DisplayAccountBalance() {
 
    cout << "You Account Balance is:" << endl;
    cout << "$" << AccountBalance << endl;
 
}
 
void WithDrawMoneyFromAccount() {
 
    int UserInputOption = -1;
    int valueToWithdraw = 0;
    long CustomerRequest = 0;
    bool isNotFinished = true;
 
    do {
 
        cout << "Withdrawal options:" << endl;
        cout << "1 - $20" << endl;
        cout << "2 - $40" << endl;
        cout << "3 - $60" << endl;
        cout << "4 - $100" << endl;
        cout << "5 - $200" << endl;
        cout << "6 - cancel transaction" << endl;
        cout << "7 - Custom Amount" << endl;
        cout << "choose a withdrawal option (1-7)" << endl;
 
        cin >> UserInputOption;
        switch (UserInputOption) {
        case 1:
            valueToWithdraw = 20;
            break;
        case 2:
            valueToWithdraw = 40;
            break;
        case 3:
            valueToWithdraw = 60;
            break;
        case 4:
            valueToWithdraw = 100;
            break;
        case 5:
            valueToWithdraw = 200;
            break;
        case 6:
            isNotFinished = false;
            break;
        case 7:
            cout << "Enter Amount to WithDraw:" << endl;
            cin >> CustomerRequest;
            valueToWithdraw = CustomerRequest;
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
 
        if (valueToWithdraw != 0) {
            if (valueToWithdraw > AccountBalance) {
                cout << "Sorry!! Your Account Balance is Only $" << AccountBalance << ". You can't withdraw $" << valueToWithdraw << endl;
            }
            else {
                AccountBalance = AccountBalance - valueToWithdraw;
                isNotFinished = false;
            }
            valueToWithdraw = 0;
        }
 
    } while (isNotFinished);
 
}
 
void DepositMoneyInAccount() {
 
    int UserInputOption = -1;
    bool isNotFinished = true;
    long depositAmount = 0;
 
    do {
 
        cout << "Cash Deposit Options. Please Enter Your Selection" << endl;
        cout << "1 - $20" << endl;
        cout << "2 - $40" << endl;
        cout << "3 - $60" << endl;
        cout << "4 - $100" << endl;
        cout << "5 - $200" << endl;
        cout << "6 - cancel transaction" << endl;
        cout << "7 - Custom Amount" << endl;
        cout << "Choose a deposit option (1-7)" << endl;
 
        cin >> UserInputOption;
        switch (UserInputOption) {
        case 1:
            AccountBalance = AccountBalance + 20;
            isNotFinished = false;
            break;
        case 2:
            AccountBalance = AccountBalance + 40;
            isNotFinished = false;
            break;
        case 3:
            AccountBalance = AccountBalance + 60;
            isNotFinished = false;
            break;
        case 4:
            AccountBalance = AccountBalance + 100;
            isNotFinished = false;
            break;
        case 5:
            AccountBalance = AccountBalance + 200;
            isNotFinished = false;
            break;
        case 6:
            isNotFinished = false;
            break;
        case 7:
            cout << "Please Enter Amount to Deposit:" << endl;
            cin >> depositAmount;
            AccountBalance = AccountBalance + depositAmount;
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
 
    } while (isNotFinished);
 
}
 
int main() {
 
    if (ValidateCustomerDetails()) {
 
        int isNotFinished = true;
 
        do {
 
            switch (DisplayMenu()) {
            case 1:
                DisplayAccountBalance();
                break;
            case 2:
                WithDrawMoneyFromAccount();
                break;
            case 3:
                DepositMoneyInAccount();
                break;
            case 4:
                isNotFinished = false;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
                break;
            }
 
        } while (isNotFinished);
 
    }
 
    return 0;
 
}