#include <bits/stdc++.h>
using namespace std;

void login()
{
    string id, password;
    cout << "\n\t\t\tEnter your ID and PASSWORD \n"
         << endl;
    cout << "Enter your ID  : ";
    cin >> id;
    cout << "Enter Password : ";
    cin >> password;
    string pass, loginid;
    int count = 0;
    ifstream in("record.txt");

    while (in >> loginid >> pass)
    {
        if (loginid == id && pass == password)
        {
            count = 1;
            break;
        }
    }
    if (count != 0)
    {
        system("cls");
        cout << "\n\n________________LOGIN Successfull_______________________" << endl;
    }
    else
    {
        system("cls");
        cout << "\n\n_______LOGIN ERROR !  Check your login credentials______" << endl;
    }
}

void registration()
{
    string id, password;
    cout << "\n\t\t\tEnter your ID and PASSWORD \n"
         << endl;
    cout << "Enter your ID  : ";
    cin >> id;
    ////////////////
    ifstream in("record.txt");
    string loginid;
    while (in >> loginid)
    {
        if (loginid == id)
        {
            system("cls");
             cout<<"\n\n_______________ "<<id<< "  had already registered ___________________"<<endl;
             return;
        }
    }
    /////////////////
    cout << "Enter Password : ";
    cin >> password;
    ofstream out("record.txt", ios::app);
    out << id << "\t" << password << endl;
    cout<<"_________________"<<" Succefully registerd as "<<id<<"_____________________"<<endl;
}

void forgot()
{
    string id, loginid,password;
    int count = 0;
    cout<<"\n\n\t\tEnter your Login ID :\t";
    cin>>loginid;
    ifstream in("record.txt");
    while(in>>id>>password){
        if(id==loginid){
            system("cls");
            cout<<"\n___________________Your Password is : "<<password<<"__________________";
            count=1;
        }
    }
    if(count==0)
    {
        system("cls");
        cout<<"\n_______________Account not FOUND!_______________\n___________Please check your Login ID___________";
    }
}

void changePassword(){
        string id, loginid,password,newPassword;
    int count = 0;
    cout<<"\n\n\t\tEnter your Login ID :\t";
    cin>>loginid;
    ifstream in("record.txt");
    while(in>>id>>password){
        if(id==loginid){
            system("cls");
            cout<<"\nEnter new Password : ";
            cin>>newPassword;
            password = newPassword;
            // ofstream out("record.txt", ios::app);
            // out << id << "\t" << password << endl;
            count=1;
            cout<<"\n_______________Password Successfully Changed____________________";
        }
    }
    if(count==0)
    {
        system("cls");
        cout<<"\n_______________Account not FOUND!_______________\n___________Please check your Login ID___________";
    }
}


int main()
{
    string userID, password;
    cout << "\n\n\t\t\tEnter 1 to LOGIN           |" << endl;
    cout << "\t\t\tEnter 2 to Registre        |" << endl;
    cout << "\t\t\tEnter 3 to Forgot Password |" << endl;
    cout << "\t\t\tEnter 4 to Change Password |" << endl;
    cout << "\t\t\tEnter 0 to exit            |" << endl;
    int choice;
    cout << "\n\n\tEnter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
            main();
            break;
    case 2:
        registration();
        main();
        break;
    case 3:
        forgot();
        main();
        break;
    case 4:
        changePassword();
        main();
        break;
    case 0:
        system("cls");
        break;
    default:
        cout << "Enter Valid Choice !" << endl;
    }
}