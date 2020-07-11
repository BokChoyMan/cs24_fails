#include "MyChunkyNode.h"
#include <iostream>

MyChunkyNode::MyChunkyNode(int chunksize){
  _prev = nullptr;
  _next = nullptr;
  _items = new std::string[chunksize];
  _count = 0;
  _size = chunksize;
  _rel_index = 0;
}

MyChunkyNode::MyChunkyNode(std::string item, MyChunkyNode* prev,
                          MyChunkyNode* next, int chunksize){
  _prev = prev;
  _next = next;
  _size = chunksize;
  _items = new std::string[chunksize];
  _items[0] = item;
  _count = 1;
  _rel_index = 0;
}

int MyChunkyNode::count() const{
  return _count;
}

int MyChunkyNode::i_count(){
  int num = 0;
    for(int i = 0; i<_size; i++){
      if(!items()[i].empty()||items()[i].compare("")!=0)
        num++;
    }
    _count = num;
  return _count;
}

void MyChunkyNode::i_count(int i){
  int num = 0;
    for(int i = 0; i<_size; i++){
      if(!items()[i].empty()||items()[i].compare("")!=0)
        num++;
    }
    _count = num+i;
}

std::string* MyChunkyNode::items() const{
  return _items;
}

MyChunkyNode* MyChunkyNode::prev() const{
  return _prev;
}

MyChunkyNode* MyChunkyNode::next() const{
  return _next;
}
//case1: odd
//case2: even
void MyChunkyNode::split(int case_type){
  MyChunkyNode* new_Node = new MyChunkyNode(_size);
  new_Node->setNext(this->_next);
  this->setNext(new_Node);
  new_Node->setPrev(this);
  int chunksize = this->i_count();

  //odd case
  if(case_type == 1){
    for(int i = chunksize-1; i>chunksize/2; i--){
        new_Node->_items[chunksize-1-i] = this->_items[i];
        this->_items[i] = "";
    }
  } 

  //even case
  else if(case_type == 2){
    for(int i = chunksize-1; i>chunksize/2; i--){
      new_Node->_items[chunksize-1-i] = this->_items[i];
      this->_items[i] = "";
    }
  }

  new_Node->i_count();
  this->i_count();

  
    
}

void MyChunkyNode::setNext(MyChunkyNode* next) {_next = next;}

void MyChunkyNode::setPrev(MyChunkyNode* prev) {_prev = prev;}

void MyChunkyNode::setRel_index(int index){
    if(index<0)
        _rel_index = 0;
    else
        _rel_index = index;
}

int MyChunkyNode::rel_index(){return _rel_index;}

bool MyChunkyNode::isFull(){
    bool result = true;
    for(int i = 0; i<_size; i++){
        if(this->items()[i].empty()||this->items()[i].compare("")==0){
            result = false;
        }
    }
    return result;
}

bool MyChunkyNode::isEmpty(){
    bool result = true;
    for(int i = 0; i<_size; i++){
        if(!this->items()[i].empty()||this->items()[i].compare("")!=0){
            result = false;
        }
    }
    return result;
}

void MyChunkyNode::init_arr(std::string* arr){
    for(int i = 0; i<_size; i++){
      arr[i]="";
    }
}

std::string MyChunkyNode::nodeToString(){
    std::string str = "";
    str+="[";
        for(int i = 0; i<this->_size; i++){
            if((this->items()[i].empty()) || this->items()[i].compare("")==0)
                str+="_,";
            else
                str += this->items()[i]+ ",";
        }
    str+="]";
    return str;
}

MyChunkyNode::~MyChunkyNode(){
  delete[] _items;
}
