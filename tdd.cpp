#include <iostream>
#include "MyChunkyList.h"
#include "MyChunkyNode.h"
#include "ChunkyList.h"
using namespace std;

int main(){
    MyChunkyList list = MyChunkyList(3);
    string arr[3] = {"Oops","Hello","Nope"};

    list.insert(0,"shoot");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot1");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot2");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot3");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot4");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot5");
    cout<<"count: "<<list.count()<<endl;
    cout<<"head: "<<list.head()<<endl;
    cout<<"Tail: "<<list.tail()<<endl;
    cout<<"head->next(): "<<list.head()->next()<<endl;
    cout<<"head->next()->next(): "<<list.head()->next()->next()<<endl;
    cout<<list.listToString()<<endl;
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