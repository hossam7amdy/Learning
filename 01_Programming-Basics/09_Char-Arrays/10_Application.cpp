#include <iostream>
using namespace std;

/*
Help our factory in managing his employees. Create a program that does the
following:
    ○ Display the following choices:
■ Enter your choice:
■ 1) Add new employee
■ 2) Print all employees
■ 3) Delete by age
■ 4) Update Salary by name
    ○ You will keep the program running forever. Display the choices and user input from 1 to 4
*/

int main(){
    int const MAX = 200;
    string names[MAX];
    int age[MAX];
    double salary[MAX];
    char gender[MAX];

    int choice, sz=0;
    while(true){
        cout << "Enter your choice:\n"
                "\t1) Add new employee\n"
                "\t2) Print all employees\n"
                "\t3) Delete by age\n"
                "\t4) Update Salary by name\n";

        cin >> choice;
        if(!(1<=choice && choice<=4)){ //Not optimal way to handle an invalid input
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if(choice==1){
            cin >> names[sz] >> age[sz] >> salary[sz] >> gender[sz];
            sz++;
        }

        else if(choice==2){
            for(int i=0; i<sz; i++){
                if(age[i]){
                    cout << names[i] << " " << age[i] << " ";
                    cout << salary[i] << " " << gender[i] << endl;
                }
            }
        }

        else if(choice==3){
            int start_age, end_age;
            cin >> start_age >> end_age;
            for(int i=0; i<sz; i++){
                if(start_age<=age[i] && age[i]<=end_age){ //assuming he is a good guy and entered the small first :D
                    names[i] = "";
                    age[i] = 0; //Not a lazy delete! I guess
                    salary[i] = 0;
                    gender[i] = ' ';
                }
            }
        }

        else if(choice==4){
            string name;
            int new_sal;
            cin >> name >> new_sal;
            bool not_found = true;

            for(int i=0; i<sz; i++){
                if(name==names[i]){
                    salary[i] = new_sal;
                    not_found = false;
                }
            }
            if(not_found)
                cout << "No employee with this name.\n";
        }
    }


    return 0;
}
