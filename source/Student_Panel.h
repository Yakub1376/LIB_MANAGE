#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string book_name, book_code, subject_name, writter_name;
    public:
        void STUDENT_PANEL();
        void DISPLAY_BOOK();
};


void Student:: STUDENT_PANEL(){
    int option2;
    menustart:
        fstream stfile;
        string stname,stid;
        cout<< "Enter Your Name: ";
        getline(cin,stname);
        cout<<"Enter Your ID: ";
        getline(cin,stid);
        stfile.open("student.txt", ios :: app | ios :: out);
        stfile<<stname<<endl;
        stfile<<stid<<endl;
        stfile.close();
    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t------------ STUDENT PANEL -----------" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t 1.DISPLAY BOOK" << endl;
    cout << "\t\t\t\t 2.LOG OUT" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "[CHOOSE YOUR OPTION FROM 1 or 2]" << endl;
    cout << "\n";
    cout << "\t\t\t---------------------------------" << endl;
    cout << "CHOOSE YOUR OPTION : " << endl;

    cin >> option2;

    switch(option2)
    {
        case 1:
        {
            string s;
            DISPLAY_BOOK();
            cout << "Press any key character to continue to student menu" << endl;
            cin>>s;
            cin.ignore();
            goto menustart;
        }
        case 2:
            break;
        default:
            cout << "\t\tyou have enter a wrong code"<<endl<<"run the program again & please  choose between 1 to 2" << endl;
            break;
    }
}
void Student :: DISPLAY_BOOK(){
    fstream file;
    int book_no;

    cout << "\t\t\t--| These are the Book available at that moment |--";
    cout << "\n";

    file.open("book.txt", ios :: in);
    while(file >> book_code)
    {   file.ignore();
        getline(file,book_name);
        getline(file,subject_name);
        getline(file,writter_name);

        cout << "Book ID: " << book_code << endl;
        cout << "Book Name: " << book_name << endl;
        cout << "Subject Name: " << subject_name << endl;
        cout << "Writer Name: " << writter_name << endl;
        cout << "\n";
    }
    file.close();
}

