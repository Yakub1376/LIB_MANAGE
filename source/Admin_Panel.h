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
        void ADMIN_PANEL();    
        void SHOW_STUDENT(); 
        void ADD_BOOK();       
        void DELETE_BOOK();    
        void SEARCH_BOOK();     
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
                string s;
                ADD_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                getline(cin,s);
                cin.ignore();
                goto here;
            }
            case 2:
            {
                string s;
                DELETE_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                getline(cin,s);
                cin.ignore();
                goto here;
            }
            case 3:
            {
                string s;
                DISPLAY_BOOK();
                cout << "Press any key character to continue to admin menu" << endl;
                getline(cin,s);
                cin.ignore();
                goto here;
            }
            case 4:
            {
                string s;
                SHOW_STUDENT();
                cout << "Press any key character to continue to admin menu" << endl;
                getline(cin,s);
                cin.ignore();
                goto here;
            }
            case 5:
                break;
            default:
            {
                cout << "you have enter the wrong code please choose between 1 to 5" << endl;
                goto here;
                //break;
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
        cin>>pass;

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

void Admin:: SHOW_STUDENT()
{
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

void Admin :: DISPLAY_BOOK(){
    fstream file;
    int book_no;

    cout << "\t\t\t--| These are the Book available at that moment |--";
    cout << "\n";

    file.open("book.txt", ios :: in);
    while(file >> book_code)
    {
        file >> book_name;
        file >> subject_name;
        file >> writter_name;

        cout << "Book ID: " << book_code << endl;
        cout << "Book Name: " << book_name << endl;
        cout << "Subject Name: " << subject_name << endl;
        cout << "Writer Name: " << writter_name << endl;
        cout << "\n";
    }
    file.close();
}

void Admin:: ADD_BOOK(){
    fstream file;
    cout << "\t\t\t---| To Add Book |---";
    cout << "\n";

    cout << "Enter The Book Code : ";
    cin >> book_code;       //new book code

    cout << "Enter The Book Name : ";
    getline(cin,book_name);
    cin.ignore();      //new book name

    cout << "Enter The Subject Name : ";
    cin >> subject_name;        //new subject name

    cout << "Enter The writter Name : ";
    cin >> writter_name;        //new writter name

    file.open("book.txt", ios :: app | ios :: out);         //to show the new book details
    file << book_code << endl;
    file << book_name << endl;
    file << subject_name << endl;
    file << writter_name << endl;
    file.close();
}

void Admin :: DELETE_BOOK()
{
    
    string book_no;
    fstream file;
    vector<bookdata> book_details;
    cout << "\t\t\t ---| TO DELETE BOOKS |--- " << endl;
    file.open("book.txt", ios :: in);

    while(file >> book_code)
    {
        file >> book_name;
        file >> subject_name;
        file >> writter_name;

        bookdata temp_book_data;
        temp_book_data.book_code = book_code;
        temp_book_data.book_name = book_name;
        temp_book_data.subject_name = subject_name;
        temp_book_data.writter_name = writter_name;
        book_details.push_back(temp_book_data);
    }
    file.close();
    cout << "\t\t\t please enter the book code which you want to delete " << endl;
    cin >> book_no;
    
    fstream file2;
    file2.open("book.txt", ios :: out);
    for(int i = 0; i < book_details.size(); i++)
    {
        if(book_no != book_details[i].book_code)
        {
            file2 << book_details[i].book_code<<endl;
            file2 << book_details[i].book_name<<endl;
            file2 << book_details[i].subject_name<<endl;
            file2 << book_details[i].writter_name<<endl;
        }
    }
    file2.close();
}
