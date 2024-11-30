
#include <iostream>
#include<string.h>
using namespace std;
class Employee{
    int ID;
    char name[20];
public:
    Employee(int d=-1,char n[20]="none"){
        ID=d;
        strcpy(name,n);
    }
    int getId(){
    return ID;}
    char* getName(){
    return name;}

    void Print(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Name: "<<name<<endl;}

    void Fill(int d,char n[20]){
        ID=d;
        strcpy(name,n);
    }
};

struct Node{
    Node* pPrev;
    Employee emp;
    Node* pNext;
};

Node* pHead;
Node* pTail;

Node* CreateNode(int i,char n[20]){
    Node* ptr;
    ptr=new (Node);
    if(ptr){
        ptr->emp.Fill(i,n);
        ptr->pNext=NULL;
        ptr->pNext=NULL;
    }
    return ptr;
}
int AddNode(int i,char n[20]){
    int relval=0;
    Node* ptr;
    ptr=CreateNode(i,n);
    if(ptr){
        relval=1;
        if(!pHead){
            pHead=pTail=ptr;
        }
        else{
            ptr->pPrev=pTail;
            pTail->pNext=ptr;
            pTail=ptr;

        }
    }
    return relval;
}

int InsertNode(int i,char n[20],int loc){
    Node* ptr;
    Node* temp;
    int retval=0;
    ptr=CreateNode(i,n);
    if(ptr){
        retval=1;
        if(pHead==NULL){ //empty
            pHead=pTail=ptr;
        }
        else{ //not empty
            if(loc==0){
                ptr->pNext=pHead;
                pHead=ptr;
            }
            else{
                temp=pHead;
                for(int i=0;i<loc-1 && temp!=NULL;i++){ //temp->pNext!=NULL
                    temp=temp->pNext;
                }
                if(temp==pTail || temp==NULL){
                    pTail->pNext=ptr;
                    ptr->pPrev = pTail;
                    pTail = ptr;
                }
                else{
                    ptr->pNext= temp->pNext;
                    ptr->pNext->pPrev = ptr;
                    temp->pNext = ptr;
                    ptr->pPrev = temp;
                }
            }
        }
    }
    return retval;
}

void SearchId(int i){
    if(pHead==NULL){
        cout<<"not found";
    }
    else{
        Node* ptr;
        ptr=pHead;
        while(ptr->emp.getId()!=i && ptr!=NULL){
            ptr=ptr->pNext;
        }
        if(ptr!=NULL){
            ptr->emp.Print();
        }
        else{
            cout<<"not found";
        }
    }
}

void SearchName(char n[20]){
    if(pHead==NULL){
        cout<<"not found";
    }
    else{
        Node* ptr;
        ptr=pHead;
        while(strcmp(ptr->emp.getName(),n) && ptr!=NULL){
            ptr=ptr->pNext;
        }
        if(ptr!=NULL){
            ptr->emp.Print();
        }
        else{
            cout<<"not found";
        }
    }
}

void FreeList(){
    Node* ptr;
    while(pHead){
        ptr=pHead;
        pHead=ptr->pNext;
        delete(ptr);
    }
    pTail=NULL;
}

void PrintAll(){
    Node* ptr;
    ptr=pHead;
    if(pHead==NULL){
        cout<<"Empty list"<<endl;
    }
    while(ptr){
        ptr->emp.Print();
        ptr=ptr->pNext;
    }

}

void DeleteNode(int i){
      Node* ptr;
      ptr=pHead;

    if (pTail == NULL && pHead  == NULL) {
            cout << "List is empty" << endl;
            return;
        }
    while(ptr!=NULL && ptr->emp.getId() != i)
    {
        ptr =ptr->pNext;
    }
    cout<<"b";
    cout<<ptr;
        if(ptr==NULL){
            cout<<"not found";
        }
        else{
            if(pHead == pTail && pHead!=NULL){ // first element and single node
                cout<<"del first only\n";
                pHead = pTail = NULL;
                delete (ptr);
                cout<<"del fisrt\n";
            }
            else if(pHead == ptr && pHead != pTail){ // first element and not single node
                cout<<"del first and not single\n";
                pHead=ptr->pNext;
                ptr->pNext->pPrev =NULL;
                delete (ptr);
                cout<<"del fisrt\n";
            }
            else{ //mid or last

                if(ptr == pTail && pHead != pTail){ //last
                    cout<<"del last\n";
                    pTail = ptr->pPrev;
                    ptr->pPrev -> pNext = NULL;
                cout<<"del last\n";
                    delete (ptr);
                }
                else{
                    cout<<"del mid\n";
                    (ptr->pPrev)->pNext=ptr->pNext;
                    (ptr->pNext)->pPrev=ptr->pPrev;
                    cout<<"do mid\n";
                    delete(ptr);

                }
            }
        }

}
int main()
{
    int x,result,id,loc;
    char name[20];
    cout<<"1 Add node"<<endl;
    cout<<"2 Insert node"<<endl;
    cout<<"3 Print All"<<endl;
    cout<<"4 Search by ID"<<endl;
    cout<<"5 Search by Name"<<endl;
    cout<<"6 Delete by ID"<<endl;
    cout<<"7 Free List"<<endl;

do{
    cout<<"enter a choice: ";
    cin>>x;

switch(x){
    case 1:{
        cout<<"id: ";
        cin>>id;
        cout<<"name: ";
        cin>>name;
        result=AddNode(id,name);
        if(result==1){
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Fail"<<endl;
        }
        break;
    }
    case 2:{
        cout<<"id: ";
        cin>>id;
        cout<<"name: ";
        cin>>name;
        cout<<"location: ";
        cin>>loc;
        result=InsertNode(id,name,loc);
        if(result==1){
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Fail"<<endl;
        }
        break;
    }
    case 3:{
        PrintAll();
        break;
    }
    case 4:{
        cout<<"id: ";
        cin>>id;
        SearchId(id);
        break;
    }
    case 5:{
        cout<<"name: ";
        cin>>name;
        SearchName(name);
        break;
    }
    case 6:{
        cout<<"id: ";
        cin>>id;
        DeleteNode(id);
        break;
    }
    case 7:{
        FreeList();
        break;
    }
}
}while(x!=8);
    return 0;
}

