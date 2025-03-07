#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main(){

    int c;
    cout << "\t\t\t____________________________________________________________\n\n\n";
    cout << "\t\t\t                      Welcome To Login Page                 \n\n\n";
    cout << "\t\t\t------------------------------MENU--------------------------\n";
    cout << "\t\t\t                                                            \n\n";
    cout << "\t| Press 1 to LOGIN                       \n";
    cout << "\t| Press 2 to REGISTER                    \n";
    cout << "\t| Press 3 if YOU FORGOT PASSWORD         \n";
    cout << "\t| Press 4 to EXIT                        \n";
    cout << "\n\tEnter Your Choice:                       ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        system("clear");
        cout << "Thank You, See you soon!!" << endl;
        break;
    default:
        system("clear");
        cout << "Please Enter a valid number!!" << endl;
        main();
        break;
    }


    return 0;
}

void login(){
    bool flag = false;
    string userName, password, name, pass;

    system("clear");
    cout << "Enter User Name: " ;
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;

    ifstream rfile;
    rfile.open("records.txt");
    while(rfile>>name>>pass){
        if(name==userName && password == pass){
            flag = true;
            system("clear");
        }
    }
    rfile.close();
    if(flag){
        cout << "Your LOGIN is Successfull" << endl;
    }
    else{
        cout << "Please check username and password!" << endl;
    }
}

void registration(){
    string r_userName, r_password;
    system("clear");
    cout << "\t Enter a user name: ";
    cin >> r_userName;
    cout << "\t Enter a password: ";
    cin >> r_password;

    ofstream rfile("records.txt", ios::app);
    rfile << r_userName << ' ' << r_password << endl;

    system("clear");
    main();
}

void forgot(){
    int option;

    system("clear");
    cout << "\t\t Forgot Your PASSWORD?\n\n";
    cout << "\t| Press 1 to search by username       \n";
    cout << "\t| Press 2 to go back to Main Menu     \n\n";
    cout << "\n\tEnter Your Choice:                   ";
    cin >> option;

    switch(option)
    {
        case 1:
        {
            system("clear");
            bool flag = false;
            string s_userName, s_name, s_pass;
            cout << "\t Enter a user name: ";
            cin >> s_userName;

            ifstream s_file("records.txt");
            while(s_file>>s_name>>s_pass){
                if(s_name == s_userName){
                    flag = true;
                }
            }
            s_file.close();
            system("clear");
            if(flag){
                cout << "your password is " << s_pass << endl;
                main();
            }
            else{
                cout << "Your account is NOT FOUND!" << endl;
                main();
            }
        }
            break;

        case 2:
            system("clear");
            main();
            break;
        
        default:
            forgot();
            break;
    }

}