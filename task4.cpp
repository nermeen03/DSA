#include <iostream>
#include <string.h>

using namespace std;

struct Employee{
    int id;
    char name[20];
};

Employee arr[100];

void Merge(int lb, int mid, int ub){
    Employee l2[100];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub){
        if(arr[i].id>arr[j].id){
            l2[k]=arr[j];
            j++;
            k++;
        }
        else{
            l2[k]=arr[i];
            i++;
            k++;
        }
    }
    if(i<=mid){
        while(i<=mid){
            l2[k]=arr[i];
            i++;
            k++;
        }
    }
    else{
        while(j<=ub){
            l2[k]=arr[j];
            j++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k]=l2[k];
    }

}

void MergeSort(int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        MergeSort(lb,mid);
        MergeSort(mid+1,ub);
        Merge(lb,mid,ub);
    }
}

void BubbleSort(int n){
    Employee temp;
    int swapped=1;
    int j=0;
    while(swapped){
        swapped=0;
        for(int i=0;i<n-1-j;i++){
            if(strcmp(arr[i+1].name,arr[i].name)<0){
                swapped=1;
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;

            }
        }
        j++;
    }
}

int binaryId(int lb,int ub,int key){
    int loc=-1;
    int mid;
    while(lb<=ub && loc==-1){
        mid = (lb+ub)/2;
        if(key==arr[mid].id){
            loc=mid;
        }
        else if (key < arr[mid].id) {
            ub = mid - 1;
        }
        else{
            lb=mid+1;
        }
    }
    return loc;
}

int binaryName(int lb,int ub,char key[]){
    int loc=-1;
    int mid;
    while(lb<=ub && loc==-1){
        mid = (lb + ub) / 2;
        if (strcmp(key, arr[mid].name) == 0) {
            loc = mid;
        } else if (strcmp(arr[mid].name, key) < 0) {
            ub = mid - 1;
        }
        else{
            lb=mid+1;
        }
    }
    return loc;
}

void printAll(int n){
    for(int i=0;i<n;i++){
        cout<<"id: "<<arr[i].id<<endl;
        cout<<"name: "<<arr[i].name<<endl;
    }
};


int main()
{
    int n,id,choice;
    int b=0;
    int m=0;
    char name[20];
    cout<<"enter number of employee: ";
    cin>>n;
do{
    cout<<"1 fill"<<endl;
    cout<<"2 sort by id"<<endl;
    cout<<"3 sort by name"<<endl;
    cout<<"4 search by id"<<endl;
    cout<<"5 search by name"<<endl;
    cout<<"6 print"<<endl;
    cout<<"7 Exit"<<endl;
    cout<<"enter choice: ";
    cin>>choice;

switch(choice){
    case 1:{
        for(int i=0;i<n;i++){
            cout<<"id: ";
            cin>>id;
            cout<<"name: ";
            cin>>name;
            arr[i].id=id;
            strcpy(arr[i].name,name);
        }
        break;
    }
    case 2:{
        MergeSort(0,n-1);
        m=1;
        break;
    }
    case 3:{
        BubbleSort(n);
        b=1;
        break;
    }
    case 4: {
        int loc;
        if (m == 1) {
            cout << "id: ";
            cin >> id;
            loc = binaryId(0, n - 1, id);
            if (loc > -1) {
                cout << "id: " << arr[loc].id << endl;
                cout << "name: " << arr[loc].name << endl;
            } else {
                cout << "ID not found!" << endl;
            }
        } else {
            cout << "List not sorted by ID!" << endl;
        }
        break;
    }

    case 5: {
        int loc;
        if (b == 1) {
            cout << "name: ";
            cin >> name;
            loc = binaryName(0, n - 1, name);
            if (loc > -1) {
                cout << "id: " << arr[loc].id << endl;
                cout << "name: " << arr[loc].name << endl;
            } else {
                cout << "Name not found!" << endl;
            }
        } else {
            cout << "List not sorted by name!" << endl;
        }
        break;
    }
    case 6:{
        printAll(n);
        break;
    }
}
cout<<"-------------------------------------"<<endl;

}while(choice!=7);
return 0;
}
