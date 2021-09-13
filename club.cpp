#include<iostream>
//#include<bits/stdc++>
using namespace std;

#define N 30

class Club {
    protected:
        char type_of_job;
        int no_of_members;
    public:
        void getType() {  
            cout<<"\nEnter type of job: ";
            cout<<"a)Meeting\nb)Presentation\nc)Computer stuff\nd)Auditorium\n";
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
};

//Array of objects created for all the below types of clubs so the records can be stored.
class StudentProject : public Club {

}a[N];

class TechClub : public Club {

}b[N];

class NonTechClub : public Club {

}c[N];



int main()
{   int SP,TC,NTC;//Kepps track of the respective number of organizations.
    int choice;
    SP=TC=NTC=0;
    cout<<"Please select a type of organization:\n";
    cout<<"1.Student Project\n2.Tech Club\n3.Non-Tech Club\n4.Exit\n";
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
        SP++;
        break;
    case 2:
        cout<<"\nTech Club";
        b[TC].getType();
        b[TC].memberCount();
        b[TC].dispJobType();
        b[TC].dispMemCount();
        TC++;
        break;
    case 3:
        cout<<"\nNon Tech Club";
        c[NTC].getType();
        c[NTC].memberCount();
        c[NTC].dispJobType();
        c[NTC].dispMemCount();
        NTC++;
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
