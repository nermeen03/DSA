
#include <iostream>
#include<string.h>

using namespace std;

class Employee{
    int id;
    char name[20];
public:
    Employee(int i=-1,char n[20]="none"){
        id=i;
        strcpy(name,n);
    }
    void setId(int i){
    id=i;}
    void setName(char n[20]){
    strcpy(name,n);}
    int getId(){
    return id;}
    char* getName(){
    return name;}
    void PrintEmployee(){
        cout<<"Id is "<<getId()<<endl;
        cout<<"Name is "<<getName()<<endl;
    }
};

Employee emp[100];
int TOQ;

int EnQueue(Employee e){
    int retval=0;
    if(TOQ<100){
        retval=1;
        emp[TOQ]=e;
        TOQ++;
    }
    return retval;
}

Employee DeQueue(){
    Employee e;
    if(TOQ>0){
        e=emp[0];
        for(int i=0; i<TOQ;i++){
            emp[i]=emp[i+1];
        }
        TOQ--;
    }
    return e;
}

void PrintAll(){
    for(int i=0;i<TOQ;i++){
        emp[i].PrintEmployee();
    }
}

int main(){
    int id,choice;
    char name[20];
do{
    cout<<"1 EnQueue"<<endl;
    cout<<"2 DeQueue"<<endl;
    cout<<"3 print"<<endl;
    cout<<"4 Quit"<<endl;
    cout<<"enter a choice: ";
    cin>>choice;
    switch(choice){
    case 1:{
        cout<<"ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        Employee e(id,name);
        int result = EnQueue(e);
        if(result){
            cout<<"Success"<<endl<<endl;
        }
        else{
            cout<<"Fail"<<endl<<endl;
        }
        break;
    }
    case 2:{
        Employee e;
        e = DeQueue();
        if(e.getId()!=-1){
            cout<<"Id is "<<e.getId()<<endl;
            cout<<"Name is "<<e.getName()<<endl;
        }
        else{
            cout<<"No Data to DeQueue"<<endl;
        }
        break;
    }
    case 3:{
        if(TOQ!=0){
            PrintAll();
        }
        else{
            cout<<"No Data to Print"<<endl;
        }
        break;
    }
    }
cout<<"-----------------------------------------------------------"<<endl;
}while(choice!=4);
}


