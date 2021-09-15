#include<iostream>
//#include<bits/stdc++>
using namespace std;

#define N 30
#define FLOOR 4
#define ROOM 4
static int rooms[FLOOR][ROOM]={0,0,0,0};
#define xyz 50 
class Club {
    //protected:
    public:
        char type_of_job;
        int no_of_members;
    
        void getType() {
            cout<<"\nEnter type of job: ";
            cout<<"a)Meeting \nb)Presentation \nc)Computer stuff \nd)Auditorium \n";
            cin>>type_of_job;
        }

        void memberCount() {
            cout<<"\nEnter the number of members: ";
            cin>>no_of_members;
        }

        void dispMemCount() {
            cout<<endl<<no_of_members<<endl;
        }

        void dispJobType() {
            cout<<endl<<type_of_job<<endl;
        }
        
        char retJobType(){
            return type_of_job;
        }
};

//Array of objects created for all the below types of clubs so the records can be stored.
class StudentProject : public Club {
public:
    friend int return_floor(StudentProject test);
}a[N];

class TechClub : public Club {
public:
    friend int return_floor(TechClub test);
}b[N];

class NonTechClub : public Club {
public:
    friend int return_floor(NonTechClub test);
}c[N];


class Academic_block {
    protected:
        int flr=-1;
    public:
        void display_rooms();
        int return_floor(StudentProject test);
        int return_floor(TechClub test);
        int return_floor(NonTechClub test);
        int seat_count();
        int assign_room();
    
}d[N*ROOM];

void Academic_block::display_rooms() {
    cout<<"Current Status of the rooms in the Academic Block are : "<<endl;
    cout<<"+---------------------------+"<<endl;
    for(int i=0;i<FLOOR;i++) {
        cout<<"| ";
        for(int j=0;j<ROOM;j++) {
            cout<<" "<<rooms[i][j]<<"| ";
        }
        cout<<endl<<"+---------------------------+";
    }
    cout<<"+---------------------------+";
}
int Academic_block:: return_floor(StudentProject test) {
    //cout<<"\nwelcome to floor "<< test.type_of_job;
    if(test.type_of_job == 'a') return 0;
    else if(test.type_of_job == 'b') return 1;
    else if(test.type_of_job == 'c') return 2;
    else if(test.type_of_job == 'd') return 3;
    else return -1; //default case
    
}

int Academic_block:: return_floor(TechClub test) {
    if(test.type_of_job == 'a') return 0;
    else if(test.type_of_job == 'b') return 1;
    else if(test.type_of_job == 'c') return 2;
    else if(test.type_of_job == 'd') return 3;
    else return -1; //default case
    
}

int Academic_block:: return_floor(NonTechClub test) {
    //cout<<"\nwelcome to floor "<< test.type_of_job;
    if(test.type_of_job == 'a') return 0;
    else if(test.type_of_job == 'b') return 1;
    else if(test.type_of_job == 'c') return 2;
    else if(test.type_of_job == 'd') return 3;
    else return -1; //default case
    
}
/*int Academic_block:: return_floor(Club test) {
    cout<<"\nwelcome to floor "<< test.type_of_job;
    if(test.type_of_job == 'a') return 0;
    else if(test.type_of_job == 'b') return 1;
    else if(test.type_of_job == 'c') return 2;
    else if(test.type_of_job == 'd') return 3;
    else return -1; //default case
}*/
int main()
{   int SP,TC,NTC,AB;//Kepps track of the respective number of organizations.
    int choice,sol;
    SP=TC=NTC=AB=0;
    cout<<"Please select a type of organization:\n";
    cout<<"1.Student Project \n2.Tech Club \n3.Non-Tech Club \n4.Exit  \n";
    cin>>choice;
    bool flag;
    while(1) {
    switch (choice) {
        case 1:
            cout<<"\nStudent Project";
            a[SP].getType();
            a[SP].memberCount();
            a[SP].dispJobType();
            a[SP].dispMemCount();
           
            sol=d[AB].return_floor(a[SP]);
            //int sol = d[AB].return_floor(a[SP]);
            cout<<"\nFloor: "<< sol;
            SP++; AB++;
            break;
        case 2:
            cout<<"\nTech Club";
            b[TC].getType();
            b[TC].memberCount();
            b[TC].dispJobType();
            b[TC].dispMemCount();
            
            sol=d[AB].return_floor(b[TC]);
            //int sol = d[AB].return_floor(a[SP]);
            cout<<"\nFloor: "<< sol;
            TC++; AB++;
            break;
        case 3:
            cout<<"\nNon Tech Club";
            c[NTC].getType();
            c[NTC].memberCount();
            c[NTC].dispJobType();
            c[NTC].dispMemCount();
            
            sol=d[AB].return_floor(c[NTC]);
            //int sol = d[AB].return_floor(a[SP]);
            cout<<"\nFloor: "<< sol;
            NTC++; AB++;
            break;
        case 4:
            flag=1;
            break;
        default:
            flag=1;
            break;
    }
    if(flag) break;
    cout<<"\n1.Student Project\n2.Tech Club\n3.Non-Tech Club\n4.Exit\n";
    cin>>choice;
   }
    
    return 0;
}
