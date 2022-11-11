#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string book_name, book_code, subject_name, writter_name;
    public:
        //void ADMIN_PANEL();     //AUTHENTICATION LEFT
        void STUDENT_PANEL();   //AUTHENTICATION LEFT
        //void SHOW_STUDENT();    //DONE
        //void ADD_BOOK();        //DONE
        //void DELETE_BOOK();     //WORKING.....
        //void SEARCH_BOOK();     //Having some problem
        void BORROWED_BOOK();   //
        void DISPLAY_BOOK();
};


void Student:: STUDENT_PANEL(){
    int option2;
    menustart:

    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t------------ STUDENT PANEL -----------" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t 1.DISPLAY BOOK" << endl;
    cout << "\t\t\t\t 2.BORROWED BOOK" << endl;
    cout << "\t\t\t\t 3.LOG OUT" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "[CHOOSE YOUR OPTION FROM 1 TO 4]" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "CHOOSE YOUR OPTION : " << endl;

    cin >> option2;

    switch(option2)
    {
        case 1:
        {
            char a;
            DISPLAY_BOOK();
            cout << "Press any key character to continue to admin menu" << endl;
            cin >> a;
            goto menustart;
        }
        case 2:
        {
            char a;
            BORROWED_BOOK();
            cout << "Press any key character to continue to admin menu" << endl;
            cin >> a;
            goto menustart;
        }
        case 3:
            break;
        default:
            cout << "you have enter the wrong code please choose between 1 to 3" << endl;
            break;
    }
}

