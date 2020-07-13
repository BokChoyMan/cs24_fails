#include <iostream>
#include "MyChunkyList.h"
#include "MyChunkyNode.h"
#include "ChunkyList.h"
using namespace std;

int main(){
    MyChunkyList list = MyChunkyList(6);
    string arr[3] = {"Oops","Hello","Nope"};
    list.insert(0,"shoot");
    cout<<"insert(1): "<<list.listToString()<<endl;
    list.insert(1,"shoot1");
    cout<<"insert(1): "<<list.listToString()<<endl;
    list.insert(1,"shoot2");
    cout<<"insert(1): "<<list.listToString()<<endl;
    list.insert(1,"shoot3");
    cout<<"insert(1): "<<list.listToString()<<endl;
    list.insert(1,"shoot4");
    cout<<"insert(1): "<<list.listToString()<<endl; 
    list.insert(1,"shoot5");
    cout<<"insert(1): "<<list.listToString()<<endl;
    list.insert(3,"X");
    cout<<"insert(3): "<<list.listToString()<<endl;
    /*
    list.remove(9);
    cout<<"remove(9): "<<list.listToString()<<endl;
    list.remove(7);
    cout<<"remove(7): "<<list.listToString()<<endl;
    list.remove(5);
    cout<<"remove(5): "<<list.listToString()<<endl;
    list.remove(4);
    cout<<"remove(4): "<<list.listToString()<<endl;
    for(int i = 0; i < list.count(); i++){
        cout<<"index "<<i<<": "<<list.lookup(i)<<endl;
        //list.remove(i);
        //cout<<list.listToString()<<endl;
    }
    */
/*
ChunkyNode* prev = nullptr;
    ChunkyNode* curr = list.head();
    while(curr != nullptr) {
        if(curr->prev() == prev){
            cout<<"true"<<endl;
        }
        else{
            cout<<"head false"<<endl;
        }
        prev = curr;
        curr = curr->next();
    }

    if(list.tail() == prev){
        cout<<"tail True"<<endl;
    }
    else{
        cout<<"tail false"<<endl;
    }
    */
   // cout<<"head: "<<list.head()<<endl;
    //cout<<"Tail: "<<list.tail()<<endl;
    //cout<<"head->next(): "<<list.head()->next()<<endl;
    //cout<<"head->next()->next(): "<<list.head()->next()->next()<<endl;
    //cout<<list.listToString()<<endl;
    /*
    list.remove(4);
    cout<<list.listToString()<<endl;
    list.remove(3);
    cout<<list.listToString()<<endl;
    list.remove(2);
    cout<<list.listToString()<<endl;
*/
    cout<<"count: "<<list.count()<<endl;
    

    return 0;
}