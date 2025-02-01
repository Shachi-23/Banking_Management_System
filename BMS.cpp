#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class account
{
    int accno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int retaccno() const;
    int retdeposit() const;
    char rettype() const;

};

void account::create_account()
{
    cout << "\nEnter The Account No. :";
    cin>> accno;
    cout << "\nEnter The Name Of The Account Holder : ";
    cin.ignore();
    cin.getline(name,50);
    cout << "\nEnter Type of The Account(C/S): ";
    cin >> type;
    type=toupper(type);
    cout<<"\nEnter The Initial amount(>=500 for saving and >=1000 for current) :";
    cin >> deposit;
    cout << "\n\n\n Account Created...";

}

void account::show_account() const
{
    cout << "\nAccount No."<<accno;
    cout << "\nAccount Holder Name:";
    cout << name;
    cout << "\nType of Account : "<< type;
    cout << "\nBalance Amount : "<< deposit;
}

void account::modify()
{
    cout << "\nAccount No. :" <<accno;
    cout << "\nModify Account Holder Name:";
    cin.ignore();
    cin.getline(name,50);
    cout<< "\nModify Type of The Accpunt :";
    cin >> type;
    type=toupper(type);
    cout << "\nModify Balance Amount :";
    cin >> deposit;

}

void account::dep(int x)
{
    deposit=deposit+x;
}

void account::draw(int x)
{
    deposit=deposit-x;
}

void account::report() const
{
    cout << accno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit <<endl;
}

int account::retaccno() const
{
    return accno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const 
{
    return type;
}


void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
void intro();

int main()
{
    char ch;
    int num; 
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. NEW ACCOUNT";
        cout << "\n\n\t02. DEPOSIT AMOUNT";
        cout << "\n\n\t03. WITHDRAW AMOUNT";
        cout << "\n\n\t04. BALANCE ENQUIRY";
        cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t06. CLOSE AN ACCOUNT";
        cout << "\n\n\t07. MODIFY AN ACCOUNT";
        cout << "\n\n\t08. EXIT";
        cout << "\n\n\tSelect Your Option (1-8)";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case '1':
                write_account();
                break;
            case '2':
                cout<<"\n\n\tEnter The Account Number :";cin>>num;
                deposit_withdraw(num,1);
                break;
            case '3':
                cout << "\n\n\tEnter The Account Number :";cin >>num;
                deposit_withdraw(num,2);
                break;
            case '4':
                cout<< "\n\n\tEnter The Account Number :"; cin>> num;
                display_sp(num);
                break;
            case '5':
                display_all();
                break;
            case '6':
                cout << "\n\n\tEnter The Account Number :",cin >> num;
                delete_account(num);
                break;
            case '7':
                cout <<"\n\n\tEnter The Account Number:",cin>>num;
                modify_account(num);
                break;
            case '8':
                cout<<"\n\n\tThanks For Using Banking Management System";
                break;
            default:
                cout<<"\a";

        }
        cin.ignore();
        cin.get();

    } while (ch!='8');
    return 0;
    
}

void write_account()
{
    account ac;
    ofstream outfile;
    outfile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char*>(&ac), sizeof(account));
    outfile.close();
}


void display_sp(int n)
{
    account ac;
    bool flag =false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout << "File Could Not Be Open!! Press Any Key...";
        return;
    }
    cout <<"\n BALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char*> (&ac),sizeof(account)))
    {
        if(ac.retaccno() == n)
        {
            ac.show_account();
            flag=true;
        }
    }
    inFile.close();
    if(flag == false)
    {
        cout << "\n\nAccount Number Does Not Exist";
    }
}

void modify_account(int n)
{
    account ac;
    bool found = false;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File Could Not Be Open!! Press Any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retaccno() == n)
        {
            ac.show_account();
            cout << "\n\n Enter The New Details Of Account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        cout << "\n\n Record Not Found";
    }
}


void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not open!! Press Any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char*> (&ac),sizeof(account)))
    {
        if(ac.retaccno()!= n)
        {
            outFile.write(reinterpret_cast<char*> (&ac),sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("temp.dat","account.dat");
    cout << "\n\n\t Record Deleted...";
}

void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File Could Not Open!! Press Any Key...";
        return;
    }
    cout << "\n\n\t\t ACCOUNT HOLDER LIST\n\n";
    cout << "**********************************************\n";
    cout << "A/C number.       NAME       TYPE     BALANCE\n";
    cout << "**********************************************\n";
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}


void deposit_withdraw(int n,int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat",ios::binary | ios::in | ios::out); 
    if(!File)
    {
        cout<<"File could not be open!! Press Any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char*> (&ac),sizeof(account));
        if(ac.retaccno() == n)
        {
            ac.show_account();
            if(option==1)
            {
                cout <<"\n\n\tTo DEPOSIT AMOUNT";
                cout<< "\n\nEnter The Amount To Be Deposited";
                cin >> amt;
                ac.dep(amt);
            }
            if(option == 2)
            {
                cout << "\n\n\tTo WITHDRAW AMOUNT";
                cout << "\n\nEnter The Amount To Be Withdraw";
                cin >> amt;
                int bal = ac.retdeposit()-amt;
                if((bal < 500 && ac.rettype()== 'S')||(bal < 1000 && ac.rettype()=='C'))
                {
                    cout << "Insufficient balance";
                }
                else
                {
                    ac.draw(amt);
                }
            }
            int pos =(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char*> (&ac),sizeof(account));
            cout << "\n\n\t Record Updated";
            found = true;
        }

    }
    File.close();
    if(found == false)
    {
        cout << "\n\n\t Record Not Found";
    }
}

void intro()
{
    cout<<"\n\n\n \t\t\t BANKING MANAGMENT SYSTEM "<<endl;
    cin.get();
}
