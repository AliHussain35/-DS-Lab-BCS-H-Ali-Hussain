#include <iostream>
using namespace std;
//24k0578 lab1 q1
class BankAcc {
    private:
        int accnum;
        float balance;

    public:
    
        BankAcc(){ //default constructor
            accnum = 1011101;
            balance = 0.0;
        }

        BankAcc(int accnumber, float bal) { //parameterised constructor
            accnum = accnumber;
            balance = bal;
        }

        BankAcc(const BankAcc &b){  //copy constructor
            accnum = b.accnum;   
            balance = b.balance; 
        }

        void deduct(float amount){
            balance = balance - amount;
            cout<<"deducted"<<endl;
        }
        float getBalance(){
            return balance;
        }
};

int main() {
    BankAcc account1;
    cout<<"Account 1 Balance = $"<<account1.getBalance()<<endl;
    BankAcc account2(2022201, 1000.0);
    cout<<"Account 2 Balance= $"<<account2.getBalance()<<endl;
    BankAcc account3 = account2;
    cout<<"Account 3 Balance= $"<<account2.getBalance()<<endl;
    account3.deduct(200);
    cout<<"Account 3 Balance after withdrawal= $"<<account3.getBalance()<<endl;
    cout<<"Account2 Balance = $"<<account2.getBalance()<<endl;
    return 0;
}

