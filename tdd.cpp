#include <iostream>
#include "MyChunkyList.h"
#include "MyChunkyNode.h"
#include "ChunkyList.h"
using namespace std;

int main(){
    MyChunkyList list = MyChunkyList(1);
    string arr[3] = {"Oops","Hello","Nope"};

    list.insert(0,"shoot");
    cout<<list.listToString()<<endl;
    list.insert(1,"shoot1");
    cout<<list.listToString()<<endl;
    list.insert(2,"shoot2");
    cout<<list.listToString()<<endl;
    list.remove(2);
    cout<<list.listToString()<<endl;

    cout<<list.count()<<endl;

    return 0;
}