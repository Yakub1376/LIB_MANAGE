#include <bits/stdc++.h>
#include "./Student_Panel.h"
#include "./Admin_Panel.h"

using namespace std;

void menu()
{
    int option;
    menustart:

    cout << "\n\n";
    cout << "\t\t\t--| WELLCOME TO LIBRARY MANAGEMENT |--" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t----- LIBRARY MANAGEMENT SYSTEM ------" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t 1.ADMIN" << endl;
    cout << "\t\t\t\t 2.STUDENT" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "[CHOOSE YOUR OPTION FROM 1 OR 2]" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "CHOOSE YOUR OPTION : " << endl;

    cin >> option;
    cin.ignore();
    Student student;
    Admin admin;
    switch(option)
    {
        case 1:
            admin.authentication();
            break;
        case 2:

            student.STUDENT_PANEL();
            break;

        default:
            cout << "Invalid Input" << endl;
            cout << "please choose between 1 or 2" << endl;
            goto menustart;
    }
}


void Check(){

}
