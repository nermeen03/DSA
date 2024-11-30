
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

struct Node{
    Employee emp;
    Node* pPrev;
};

Node* pTail;

int Push(int i,char n[20]){
    int retval=0;
    Node* ptr;
    ptr=new (Node);
    if(ptr){
        retval=1;
        ptr->emp.setId(i);
        ptr->emp.setName(n);
        if(pTail==NULL){
            pTail=ptr;
            ptr->pPrev=NULL;
        }
        else{
           ptr->pPrev=pTail;
           pTail=ptr;
        }
    }
    return retval;
}

Employee Pop(){
    Employee e;
    Node* ptr=pTail;
    if(pTail!=NULL){
       pTail=pTail->pPrev;
       e.setId(ptr->emp.getId());
       e.setName(ptr->emp.getName());
    }
    delete(ptr);
    return e;
}

void PrintAll(){
    Node* ptr;
    ptr=pTail;
    if(ptr!=NULL){
        ptr->emp.PrintEmployee();
        ptr=ptr->pPrev;
    }
}

int main(){
    int id,choice;
    char name[20];
do{
    cout<<"1 Push"<<endl;
    cout<<"2 pop"<<endl;
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
        int result = Push(id,name);
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
        e = Pop();
        if(e.getId()!=-1){
            cout<<"Id is "<<e.getId()<<endl;
            cout<<"Name is "<<e.getName()<<endl;
        }
        else{
            cout<<"No Data to pop "<<endl;
        }
        break;
    }
    case 3:{
        if(pTail!=NULL){
            PrintAll();
        }
        else{
            cout<<"No Data to print "<<endl;
        }
        break;
    }
    }
cout<<"-----------------------------------------------------------"<<endl;
}while(choice!=4);
}

