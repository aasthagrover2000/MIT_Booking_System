#include<iostream>
#include <cmath>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define N 30
#define FLOOR 4
#define ROOM 4
static int rooms[FLOOR][ROOM]={0,0,0,0};
int extra=0;

unordered_map<char, string> m= {
{'a',"Meeting"},
{'b',"Presentation"},
{'c',"Laboratory Work"},
{'d',"Auditorium"}
};

class Club {
    protected:
        char type_of_job;
        int no_of_members;
    public:
        void getType() {
            cout<<"\nEnter type of work: ";
            cout<<"\na)Meeting \nb)Presentation \nc)Laboratory Work \nd)Auditorium \n";
            cin>>type_of_job;
        }

        void memberCount() {
            cout<<"\nEnter the number of members: ";
            cin>>no_of_members;
        }

        void dispMemCount() {
            cout<<"Number of Members = "<<no_of_members<<endl;
        }
        
        int retMemCount() {
            return no_of_members;
        }

        void dispJobType() {
            cout<<"\nThe type of work you want the room for is: "<<m[type_of_job]<<endl;
        }
        
        char retJobType(){
            return type_of_job;
        }
};

//Array of objects created for all the below types of clubs so the records can be stored.
class StudentProject : public Club {
    private:
        int buffer;
    public:
        friend int return_floor(StudentProject test);
        void getBuffer() {
            cout<<"Please enter the quantity of equipment ";
            cin>>buffer;
        }
        void x_space() {
            extra=ceil(buffer*1.5);
            no_of_members+=extra;
        }
}a[N];

class TechClub : public Club {
    private:
        float cgpa;
    public:
        friend int return_floor(TechClub test);
        void getCGPA() {
            cout<<"Please enter the cumulative CGPA of the attendees of the room: ";
            cin>>cgpa;
        }
        bool CGPA() {
            if(cgpa>10 || cgpa<6) return 0;
            else return 1;
        }
}b[N];

class NonTechClub : public Club {
    private:
        int funds;
    public:
        friend int return_floor(NonTechClub test);
        void getFunds() {
            cout<<"Please enter the funds of the Non-Technical Club: ";
            cin>>funds;
        }
        bool enough_funds(int head_cnt) {
            if(funds/head_cnt>9) return 1;
            else return 0;
        }
        
}c[N];

class Academic_block {
    protected:
        int flr=-1;
        friend class Admin;
    public:
        int return_floor(StudentProject test);
        int return_floor(TechClub test);
        int return_floor(NonTechClub test);
        //int seat_count();
        int assign_room(int cnt);
        void display_rooms();
    
}d[N*ROOM];

void Academic_block::display_rooms() {
    cout<<"\nCurrent Status of the rooms & Seat Count used in the Academic Block is : "<<endl;
    cout<<"          +-----+-----+-----+-----+";
    for(int i=0;i<FLOOR;i++) {
        cout<<endl<<"Floor "<<i<<" : | ";
        for(int j=0;j<ROOM;j++) {
            if(rooms[i][j]>=10) cout<<" "<<rooms[i][j]<<" | ";
            else cout<<" "<<rooms[i][j]<<"  | ";
        }
        cout<<"\n          +-----+-----+-----+-----+";
    }
}

int Academic_block:: return_floor(StudentProject test) {
    if(test.retJobType() == 'a') { flr=0; return 0; }
    else if(test.retJobType() == 'b') { flr=1; return 1; }
    else if(test.retJobType() == 'c') { flr=2; return 2; }
    else if(test.retJobType() == 'd') { flr=3; return 3; }
    else return -1; //default case
    
}

int Academic_block:: return_floor(TechClub test) {
    if(test.retJobType() == 'a') { flr=0;return 0; }
    else if(test.retJobType() == 'b') { flr=1; return 1; }
    else if(test.retJobType() == 'c') { flr=2; return 2; }
    else if(test.retJobType() == 'd') { flr=3; return 3; }
    else return -1; //default case
    
}

int Academic_block:: return_floor(NonTechClub test) {
    if(test.retJobType() == 'a') { flr=0; return 0; }
    else if(test.retJobType() == 'b') { flr=1; return 1; }
    else if(test.retJobType() == 'c') { flr=2; return 2; }
    else if(test.retJobType() == 'd') { flr=3; return 3; }
    else return -1; //default case
}

class Admin {
    public:
        void Denial(Academic_block *deny) {
            if((*deny).flr==-1) cout<<"\nADMIN ERROR: Room type selected does not exist. Please try again later or change your requirements.\n";
            else cout<<"\nADMIN ERROR: All compatible rooms occupied. Please try again later or change your requirements.\n";
        }
        
        void cgpa_req() {
            cout<<"\nADMIN ERROR: Sorry, CGPA requirement not fulfilled.";
        }
        
        void funds_req() {
            cout<<"\nADMIN ERROR: Sorry, Funds requirement not fulfilled.";
        }
};

int Academic_block:: assign_room(int cnt) {
    if(flr==-1) {
        Admin prof;
        prof.Denial(this);
        return -1;
    } //call Admin somehow
    cout<<"EXTRA: "<<extra<<endl;
    if(cnt<=15 && rooms[flr][0]==0) { rooms[flr][0]=cnt-extra; return (flr+1)*100+1; }
    else if (cnt<=25 && rooms[flr][1]==0) { rooms[flr][1]=cnt-extra; return (flr+1)*100+2; }
    else if (cnt<=35 && rooms[flr][2]==0) { rooms[flr][2]=cnt-extra; return (flr+1)*100+3; }
    else if (cnt<=45 && rooms[flr][3]==0) { rooms[flr][3]=cnt-extra; return (flr+1)*100+4; }
    else  {
        Admin prof;
        prof.Denial(this);
        return -1;
    } //call Admin somehow
}
int main()
{   int SP,TC,NTC,AB;//Kepps track of the respective number of organizations.
    int choice,sol,r;
    SP=TC=NTC=AB=0;
    cout<<"Please select a type of organization:\n";
    cout<<"1.Student Project \n2.Tech Club \n3.Non-Tech Club \n4.Display Academic Block rooms status \nOr press any key to exit. \n";
    cin>>choice;
    bool flag=0,check;
    while(1) {
        ::extra=0;
    switch (choice) {
        case 1:
            cout<<"\nStudent Project";
            a[SP].getType();
            a[SP].memberCount();
            a[SP].dispJobType();
            a[SP].dispMemCount();
            a[SP].getBuffer();
            a[SP].x_space();
            
            sol=d[AB].return_floor(a[SP]);
            if(sol!=-1) cout<<"\nFloor: "<< sol;
            
            r=d[AB].assign_room(a[SP].retMemCount());
            if(r!=-1) cout<<"\nRoom Allotted: "<< r <<endl;
            
            d[AB].display_rooms();
            SP++; AB++;
            break;
        
        case 2:
            cout<<"\nTech Club";
            b[TC].getType();
            b[TC].memberCount();
            b[TC].dispJobType();
            b[TC].dispMemCount();
            b[TC].getCGPA();
            check=b[TC].CGPA();
            
            if(check) {
                sol=d[AB].return_floor(b[TC]);
                if(sol!=-1) cout<<"\nFloor: "<< sol;
                r=d[AB].assign_room(b[TC].retMemCount());
                if(r!=-1) cout<<"\nRoom Allotted: "<< r <<endl;
            }
            
            else {
                Admin logi;
                logi.cgpa_req();
            }
            
            d[AB].display_rooms();
            TC++; AB++;
            break;
        
        case 3:
            cout<<"\nNon Tech Club";
            c[NTC].getType();
            c[NTC].memberCount();
            c[NTC].dispJobType();
            c[NTC].dispMemCount();
            c[NTC].getFunds();
            check=c[NTC].enough_funds(c[NTC].retMemCount());
            
            if(check) {
                sol=d[AB].return_floor(c[NTC]);
                if(sol!=-1)cout<<"\nFloor: "<< sol;
                r=d[AB].assign_room(c[NTC].retMemCount());
                if(r!=-1) cout<<"\nRoom Allotted: "<< r <<endl;
            }
            
            else {
                Admin logi;
                logi.funds_req();
            }
            
            d[AB].display_rooms();
            NTC++; AB++;
            break;
        
        case 4:
            d[AB].display_rooms();
            break;
        default:
            flag=1;
            break;
    }
    if(flag) break;
    cout<<"\nPlease select a type of organization: ";
    cout<<"\n1.Student Project\n2.Tech Club\n3.Non-Tech Club \n4.Display Academic Block rooms status \nOr press any key to exit. \n";
    cin>>choice;
   }
    
    return 0;
}
