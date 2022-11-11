#include <bits/stdc++.h>

using namespace std;


class bookdata{
    public:
        string book_code,book_name, subject_name, writter_name;
};




class Admin{
    private:
        string admin_name,admin_pass,book_name, book_code, subject_name, writter_name,student_name,student_ID;
    public:
        void ADMIN_PANEL();     //AUTHENTICATION LEFT
        void SHOW_STUDENT();    //DONE
        void ADD_BOOK();        //DONE
        void DELETE_BOOK();     //WORKING.....
        void SEARCH_BOOK();     //Having some problem
        void DISPLAY_BOOK();
        void authentication();
};

void Admin:: ADMIN_PANEL()
{
    fstream file;
    menustart:
        int option2;
        here:

        cout << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t------------- ADMIN PANEL ------------" << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t 1.ADD BOOK" << endl;
        cout << "\t\t\t\t 2.REMOVE BOOK" << endl;
        cout << "\t\t\t\t 3.SHOW BOOK" << endl;
        cout << "\t\t\t\t 4.SHOW STUDENT" << endl;
        cout << "\t\t\t\t 5.LOG OUT" << endl;

        cout << "\n";
        cout << "\t\t\t---------------------------------" << endl;
        cout << "[CHOOSE YOUR OPTION FROM 1 TO 5]" << endl;
        cout << "\n";
        cout << "\t\t\t---------------------------------" << endl;
        cout << "CHOOSE YOUR OPTION : " << endl;

        cin >> option2;

        switch(option2)
        {
            case 1:
            {
                char a;
                ADD_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                cin >> a;
                goto here;
            }
            case 2:
            {
                char a;
                DELETE_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                cin >> a;
                goto here;
            }
            case 3:
            {
                char a;
                DISPLAY_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                cin >> a;
                goto here;
            }
            case 4:
            {
                char a;
                SHOW_STUDENT();
                cout << "Press any key character to continue to admin menu" << endl;
                cin >> a;
                goto here;
            }
            case 5:
                break;
            default:
            {
                cout << "you have enter the wrong code please choose between 1 to 5" << endl;
                goto here;
                break;
            }
        }

}

void  Admin ::  authentication()//to take user name & password,verifying then open main menu
{
    int i,f=3;
    string username,pass;
        Here:
        cout<< "Enter Username: ";
        cin>> username;
        cout<<"Enter Password: ";
        cin>> pass;

        ifstream open("admin.txt");
        string name,passw;
        open>>name;
        open>>passw;
        open.close();
        if(username==name&&pass==passw)
        {
            cout<<endl;
            cout<<"Welcome "<<username<<endl;
            ADMIN_PANEL();
        }
         else
        {
            for(i=2; i>0; i--)
            {
                cout<<"Wrong username or Password!"<<endl<<endl;
                if(f!=1)
                {
                    cout<< "Try Again!"<<endl<<endl;
                }
                f-=1;
                cout<<"You Have "<< f <<" Attempts Left!"<<endl<<endl;
                cin.ignore();
                if(f==0)
                {
                    cout<< "Authentication Failed! Please Run The Program Again!"<<endl;
                    break;
                }
                goto Here;
            }


        }
    }
void Admin:: SHOW_STUDENT(){
    fstream file;
    cout << "\t\t\t----|    These are are Student   |----" << endl;
 
    file.open("student.txt", ios :: in);
 
    while(file >> student_name)
    {
        file >> student_ID;
 
        cout << "Student name : " << student_name << endl;
        cout << "Student ID   : " << student_ID << endl;
        cout << endl;
    }
    file.close();
}