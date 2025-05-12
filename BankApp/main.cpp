#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

struct Transaction
{
    string tipTR;
    int summ;
    string time;
    string recipientNum;
};

class Account
{
private:
    string cartNum;
    string pin_kod;

    string SIn_cartNum;
    string SIn_pin_kod;

    float balance;

    int startB = 2;
    int endB = 10000;

    vector <Transaction> _Transaction;

    ofstream OFfile;
    ifstream IFfile;
public:

    Account()
    {
        //OFfile.open("Acc.txt", ios::out);
    }

    ~Account() {
        if (OFfile.is_open())
            OFfile.close();
        cout << "File Acc is closed...." << endl;
        if(IFfile.is_open())
            IFfile.close();
        cout << "File Acc is closed...." << endl;
        cartNum = "0";
        pin_kod = "0";
        balance = 0;
    }

    void SUp() // Sign up
    {
        OFfile.open("Acc.txt", ios::out);
        if(OFfile.is_open())
        {
        cout << "Sign Up your Account..." << endl;
        cout << "Input cart number(5 numbers): ";
        cin >> cartNum;
            if(cartNum.size() == 5)
            {
                OFfile << cartNum << endl;
            }
            else
            {
                cout << "Wrong Cart Num Size..." << endl;
                Sleep(500);
                exit(0);
            }
        cout << "Input pin-kod(4 numbers)";
        cin >> pin_kod;
            if(pin_kod.size() == 4)
            {
                OFfile << pin_kod << endl;
            }
            else
            {
                cout << "Wrong pin-kod size..." << endl;
                Sleep(500);
                exit(0);
            }
            Sleep(10);
            system("cls");
            cout << "Account has been created..." << endl;
            balance = rand() % (endB - startB + 1) + startB;
            cout << "Your balance = " << balance << endl;
            OFfile << balance << endl;
            return;
        }
        else
        {
            cout << "Error, File not open..." << endl;
            Sleep(500);
            exit(0);
        }

    }

    void SIn()
    {
        IFfile.open("Acc.txt", ios::in);
        if(IFfile.is_open())
        {
        cout << "Sign In your Account..." << endl;
        cout << "Input cart number: ";
        cin >> SIn_cartNum;
        getline(IFfile, cartNum);
        IFfile.seekg(0);
        //cout << cartNum << endl;
            if(SIn_cartNum == cartNum)
            {
                cout << "Input pin - kod: ";
                cin >> SIn_pin_kod;
                int target_line_number = 1;
                int line_count = 0;
                while(getline(IFfile, pin_kod) && line_count < target_line_number)
                {
                    line_count++;
                }
                IFfile.seekg(0);
                if(SIn_pin_kod == pin_kod)
                {
                    system("cls");
                    cout << "Successful!!!..." << endl;
                    cout << "Your are logged in Account." << endl;
                    cout << "Choose operation: \n" << "1.View balance. \n" << "2.Cash out. \n" << "3.Cash in. \n"
                         << "4.View transaction history. \n" << "5.Logout from account." << endl;
                    int x1;
                    cin >> x1;
                    IFfile.seekg(11);
                    IFfile >> balance;
                    if(x1 == 1)
                    {
                        system("cls");
                        cout << "Your Balance = " << balance << endl;
                        Sleep(1000);
                        return;
                    }
                    else if(x1 == 2)
                    {
                        system("cls");
                        int CashOut;
                        cout << "Cash Out..." << endl;
                        cout << "Cash = ";
                        cin >> CashOut;
                        balance -= CashOut;
                        cout << "Balance = " << balance << endl;
                        Sleep(500);
                        return;
                    }
                    else if(x1 == 3)
                    {

                    }
                    else if(x1 == 4)
                    {

                    }
                    else if(x1 == 5)
                    {

                    }

                }
                else
                {
                    cout << "Wrong pin - kod..." << endl;
                    Sleep(500);
                    exit(0);
                }
            }
            else
            {
                cout << "Wrong cartNum..." << endl;
                Sleep(500);
                exit(0);
            }
        }
        else
        {
            cout << "File is not open for read..." << endl;
        }
    }

};

int main()
{
    srand(time(0));
    int x = 0;
    cout << "_Online Bank_" << endl;
    cout << "Choose: \n" << "1.Sign up. \n" << "2.Sign in." << endl;
    cin >> x;
    if(x == 1)
    {
        Account obj;
        obj.SUp();
    }
    else if(x == 2)
    {
        Account obj;
        obj.SIn();
    }
    else
    {
        cout << "Wrong!!!" << endl;
    }
    Sleep(500);
    return 0;
}
