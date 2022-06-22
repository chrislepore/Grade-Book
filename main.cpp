///include files
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <windows.h>

using namespace std;

///structure
typedef struct grade_list{
    string student_name;
    string assignment_name;
    string type;
    int grade;
}G;

///prototypes
//fills selected slot with what you input
void inputFunction(vector<G> &object, int &n);

//prints out information from selected slot
void printinventory(vector <G> &object, int u);

//prints all slots in inventory
void print_all(vector <G> &object, int u);

//searches for slot
void searhFunction(vector<G> &object, int u);

//operates the flashlight
void light(int &stop);

//loads items from added text document
void loadItems(vector<G> &object, int &n);

//uses recursion to get the average grade of a student(grade type doesn't matter)
double avgRec(vector<G> &object, int j, string name_checker, int v);
double average(vector<G> &object, string name_checker, int v);

//prints out a string in a different color and then sets in back
void color_change(int y, string text);

//prints out the intro
void intro();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    //declares inventory as vector, a string operationChecker to check what operation to do, a int to determine when to stop a program,
    //a go string to stop the program before clearing the window text, and a int n to determine inputs
    vector <G> grade_book (1);
    int operationChecker;
    int n = 0;
    int stop = 0;
    string go;

    intro();

    loadItems(grade_book, n);

    do
    {
    color_change(9, "                   Menu                   ");
    color_change(9, "__________________________________________");
    color_change(9, "1: To input another grade slot");
    color_change(9, "2: To search existing grade slot");
    color_change(9, "3: To print all of the grade book");
    color_change(9, "4: To run for your life!");
    color_change(9, "__________________________________________");

    light(stop);
    if(stop == 1)
    {
        break;
    }

    //asks user what operation to do and makes sure it's a number
    cout << "what do you wish to do?? --  ";
    while(!(cin >> operationChecker))
    {
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		color_change(12, "Invalid input.  Try again: ");
    }

    //checks if a input was entered and preforms its assigned operation
    switch(operationChecker)
    {
        case 1:
            inputFunction(grade_book, n);
            cout << "continue? :";
            cin >> go;
            system("cls");
            break;
        case 2:
            searhFunction(grade_book, n);
            cout << "continue? :";
            cin >> go;
            system("cls");
            break;
        case 3:
            print_all(grade_book, n);
            cout << "continue? :";
            cin >> go;
            system("cls");
            break;
        case 4:
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl << "\t\t\t\t  ";
            color_change(12, "You ran away from the GRUE and got FIRED");
            cout<<endl << "\t\t\t\t FINAL GRADE OF EVERY STUDENT HAS BECOME ";
            color_change(12, "0%");
            cout<<endl;
            color_change(12, "\t\t\t\t\t you were never seen again.");
            cout<<endl<<endl<<endl;
            stop = 1;
            break;
    }

    }while(stop == 0);

    return 0;
}

void inputFunction(vector<G> &object, int &n)
{
    //will only increase the vector after the first slot was filled
    if(n > 0)
    {
        object.emplace_back();
    }

    //asks for student name and then makes it all lowercase
    cout << "student name: ";
    cin.ignore();
    getline(cin, object[n].student_name);
    for (unsigned int i=0;i<object[n].student_name.length();i++)
    {
         object[n].student_name[i]=tolower(object[n].student_name[i]);
    }

    //asks for assignment name and then makes it all lowercase
    cout << "assignment name: ";
    getline(cin, object[n].assignment_name);
    for (unsigned int i=0;i<object[n].assignment_name.length();i++)
    {
         object[n].assignment_name[i]=tolower(object[n].assignment_name[i]);
    }

    //asks for type and then makes it all lowercase
    cout << "type: ";
    getline(cin, object[n].type);
    for (unsigned int i=0;i<object[n].type.length();i++)
    {
         object[n].type[i]=tolower(object[n].type[i]);
    }

    //asks for the grade and makes sure it's a number
    cout << "grade: ";
    while(!(cin >> object[n].grade))
    {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		color_change(12, "Invalid input.  Try again: ");
    }

    n++;
}

void printinventory(vector <G> &object, int u)
{
    //prints out all the structs of a selected slot of the vector arsenal
    cout << "________________________________" <<endl;
    cout << "*slot "<<u + 1<<" is filled with" <<endl;
    cout << "*student name: " <<object[u].student_name << endl;
    cout << "*assignment name: " <<object[u].assignment_name << endl;
    cout << "*type: " <<object[u].type << endl;
    cout << "*grade: " <<object[u].grade << "%"<< endl;
    cout << "________________________________" <<endl;
}

void print_all(vector <G> &object, int u)
{
    //if there is at least one inventory slot filled it will output all the slots in the inventory
    if(u >= 1)
    {
        for(unsigned int i = 0; i < object.size(); i++)
        {
            printinventory(object, i);
        }
    }else
    {
        color_change(12, "------ sorry nothing has been inputed to search -------");
    }
}

void searhFunction(vector<G> &object, int u)
{
    //declares all variables for searchFunction
    int search_it;
    string category;
    int t = 0;
    int low;
    int high;
    string sorry = "*******sorry no result*******";

    //checks if at least 1 slot has been entered into the inventory before hand
    if(u >= 1)
    {
        //asks for what search category to search and makes sure it's a number. if the input does not equal any of the categories then
        //"-----sorry not a category-------" is outputted
        color_change(9, "Pick a category to search by --- student name(1), assignment name(2), type(3), grade(4), student average grade(5) : ");
        while(!(cin >> search_it))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            color_change(12, "Invalid input.  Try again: ");
        }
        //if one of the case numbers is typed it will preform the operation for that case
        switch(search_it)
        {
            //asks for the students name and makes it lower case. then it will go through the vector and print out every slot with the same student name
            //if there are none then it will say sorry no result
            case 1:
                cout << "what student: ";
                cin.ignore();
                getline(cin, category);
                for(unsigned int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(unsigned int i = 0; i < object.size(); i++)
                {
                    if(object[i].student_name == category)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    color_change(12, sorry);
                }
                break;

            //asks for the assignment name and makes it lower case. then it will go through the vector and print out every slot with the same assignment name
            //if there are none then it will say sorry no result
            case 2:
                cout << "what assignment name: ";
                cin.ignore();
                getline(cin, category);
                for(unsigned int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(unsigned int i = 0; i < object.size(); i++)
                {
                    if(object[i].assignment_name == category)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    color_change(12, sorry);
                }
                break;

            //asks for the type and makes it lower case. then it will go through the vector and print out every slot with the same type
            //if there are none then it will say sorry no result
            case 3:
                cout << "what type: ";
                cin.ignore();
                getline(cin, category);
                for(unsigned int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(unsigned int i = 0; i < object.size(); i++)
                {
                    if(object[i].type == category)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    color_change(12, sorry);
                }
                break;

            //asks for the low and high grade and makes sure it's a number. then it will go through the vector and print out every slot between the
            //low and high grade. if there are none then it will say sorry no result
            case 4:
                cout << "low grade: ";
                while(!(cin >> low))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    color_change(12, "Invalid input.  Try again: ");
                }
                cout << "high grade: ";
                while(!(cin >> high))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    color_change(12, "Invalid input.  Try again: ");
                }
                for(unsigned int i = 0; i < object.size(); i++)
                {
                    if(object[i].grade >= low && object[i].grade <= high)
                    {
                        printinventory(object, i);
                        t++;
                    }
                }
                if(t == 0)
                {
                    color_change(12, sorry);
                }
                break;

            //asks for the student name, makes it lower case and then searches through the vector for any with the same student name.
            //first it uses the number of slots found to make a array and then fills it with the grades it found then it will output the average of the array of ints
            case 5:
                cout<< "which student? ";
                cin.ignore();
                getline(cin, category);
                for(unsigned int i=0;i<category.length();i++)
                {
                    category[i]=tolower(category[i]);
                }
                for(unsigned int i = 0; i <object.size(); i++)
                {
                    if(category == object[i].student_name)
                    {
                        t++;
                    }
                }
                if(t == 0)
                {
                    color_change(12, sorry);
                }else
                {
                    cout << "This students average is " << average(object, category, t) << "%" <<endl;
                }
                break;
        }
    }else
    {
        color_change(12, "------ sorry nothing has been inputed to search -------");
    }
}

void light(int &stop)
{
    bool sw2;
    int test = 0;
    int e = 0;

    while(e != 3)
    {
        //makes switch 1 random each time
        srand( time(NULL) );
        bool sw1 = rand() % 2;

        cout << "_______________________"<<endl;
        cout << "chance " << e+1 <<endl;
        cout << "switch 1 is: ~~" <<endl;
        cout << "switch 2: ";
        //if you hit a incorrect button you lose
        if(!(cin >> sw2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl << "\t\t\t";
            color_change(12, "You missed the button!! the light turned off! the GRUE has come...");
            cout<<endl << "\t\t\t\t FINAL GRADE OF EVERY STUDENT HAS BECOME ";
            color_change(12, "0%");
            cout<<endl;
            color_change(12, "\t\t\t\t\t you were never seen again.");
            cout<<endl<<endl<<endl;
            stop = 1;
            break;
        }
        else
        {
            cout << "_______________________"<<endl<<endl;
        }

        //ex-or gate
        if(sw1 != sw2)
        {
            return;
        }
        else
        {
            test++;
        }

        e++;
    }
    // gives you three tries
    if(test == 3)
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl << "\t\t\t  ";
        color_change(12, "The light turned off! you hear the roar of the GRUE...");
        cout<<endl << "\t\t\t\t FINAL GRADE OF EVERY STUDENT HAS BECOME ";
        color_change(12, "0%");
        cout<<endl;
        color_change(12, "\t\t\t\t\t you were never seen again.");
        cout<<endl<<endl<<endl;
        stop = 1;
    }
}

void loadItems(vector<G> &object, int &n)
{
    G p;
    ifstream myfile;
    myfile.open ("inventory.txt");
    if (myfile.is_open())
    {
        color_change(2, "Loading Inventory...");
        cout<<endl;
        while (!myfile.eof())
        {
            // ignore newline character
            myfile.ignore();

            object.push_back(p);

            //gets all the lines from the text document and makes it lower case
            getline (myfile,object[n].student_name);
            for (unsigned int i=0;i<object[n].student_name.length();i++)
            {
                object[n].student_name[i]=tolower(object[n].student_name[i]);
            }

            getline (myfile,object[n].assignment_name);
            for (unsigned int i=0;i<object[n].assignment_name.length();i++)
            {
                object[n].assignment_name[i]=tolower(object[n].assignment_name[i]);
            }

            getline (myfile,object[n].type);
            for (unsigned int i=0;i<object[n].type.length();i++)
            {
                object[n].type[i]=tolower(object[n].type[i]);
            }

            myfile>>object[n].grade;
            n++;
        }
        myfile.close();
        object.erase (object.end());
    }
    else
    {
        color_change(12, "Unable to open file");
        cout<<endl;
    }
}

// Recursively computes average of a[]
double avgRec(vector<G> &object, int j, string name_checker, int v)
{
    int o = 0;
    int a[v];

    //determines the size of the array
    for(unsigned int i = 0; i <object.size(); i++)
    {
        if(name_checker == object[i].student_name)
        {
            a[o] = object[i].grade;
            o++;
        }
    }
    int x = sizeof(a)/sizeof(a[0]);

    // Last element
    if (j == x-1)
        return a[j];

    // When index is 0, divide sum computed so
    // far by x.
    if (j == 0)
        return ((a[j] + avgRec(object, j+1, name_checker, v))/x);

    // Compute sum
    return (a[j] + avgRec(object, j+1, name_checker, v));
}

// Function that return average of an array.
double average(vector<G> &object, string name_checker, int v)
{
     return avgRec(object, 0, name_checker, v);
}

void color_change(int y, string text)
{
    //changes the color based on y, prints the string text and then sets the color back
    SetConsoleTextAttribute(console, y);
    cout << text << endl;
    SetConsoleTextAttribute(console, 15);
}

void intro()
{
    //sets text to yellow
    SetConsoleTextAttribute(console, 14);

    int t = 0;
    //goes through the string array and prints it pausing a little bit between chars
    string text = "You are a professor who is rushing to get all his grades done by the end of semester. It's late, the sun's been   down for a while and your only source of light is a flickering flashlight. You see a figure in the distance...    it's the one... the one from the legends! THE GRUE! You stay frozen in your seat, not sure to run from it or      continue to grade and pretend it's not there. When the light goes out for a moment it seems ready to attack and   you now see that this flashlight is your one and only life line. You must keep your flashlight on using the       switch and complete your grade book... or you might find out yourself why no one knows what the GRUE looks like...";
    for(unsigned int x = 0; x < text.length(); x++)
    {
        cout << text[x];
        // Pause between letters
        Sleep(30);
        t++;
        if(t == 114)
        {
            //goes to next line so the intro doesn't get cut off
            cout<<endl;
            t = 0;
        }
    }
    cout<<endl<< "________________________________________________________________________________________________________________" <<endl<<endl;

    // set color to back
    SetConsoleTextAttribute(console, 15);
}
