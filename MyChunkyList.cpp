#include "MyChunkyList.h"


MyChunkyList::MyChunkyList(int chunksize){
  _head = nullptr;
  _chunksize = chunksize;
  _count = 0;
}

int MyChunkyList::count() const{
  return _count;
}

ChunkyNode* MyChunkyList::head() const{
  return _head;
}

ChunkyNode* MyChunkyList::tail() const{
  MyChunkyNode* next;
  MyChunkyNode* tail = nullptr;
  for(MyChunkyNode* node = _head; node!=nullptr; node = next){
    next = node->next();
    if(!node->next())
      tail = node;
  }
  return tail;
}

void MyChunkyList::insert(int index, const std::string& item){
    if((index < 0) || (index > count())) {	
        // Invalid index!  Throw an exception.	
        throw std::out_of_range("Invalid index.");	
    }	  
    debug("break0");

    //first insert
    if(_count == 0 )
      _head = new MyChunkyNode(_chunksize);

    MyChunkyNode* node = nodeIndex(index);
    MyChunkyNode* next;
    MyChunkyNode* tail = nullptr;
    for(MyChunkyNode* node = _head; node!=nullptr; node = next){
      next = node->next();
      if(!node->next())
        tail = node;
    }

    //head
    if((index == 0)&&(node->isFull())){
        debug("break1");
        MyChunkyNode* new_node = new MyChunkyNode(item, nullptr, _head, _chunksize);
        _head = new_node;
        node->setPrev(new_node);
    }
    //tail
    else if(node==tail&&(index==count()-1)&&node->isFull()){
        debug("break2");
        MyChunkyNode* new_node = new MyChunkyNode(item, tail, nullptr, _chunksize);
        tail->setNext(new_node);
        node->i_count();
        new_node->i_count();
    }
    //just full
    else if(node->isFull()){
        debug("break3");
        int i_node = node->rel_index();
        std::string temp = node->items()[node->i_count()-1];
        int temp_i = node->i_count()-1 - i_node + index;

        //shift right
        for(int i = node->i_count()-1; i>=i_node; i--){
          node->items()[i+1]= node->items()[i];
        }
        //insert
        node->items()[i_node]=item;

        node->split(1);
        debug("break4");
        node = nodeIndex(index);
        node->i_count();
        insert(temp_i,temp);
        node->i_count();
        return;
    }
    //theres some space
    else{
        debug("break5");
        int i_node = node->rel_index();
        //if(index>=_chunksize)
           // std::cout<<"out of range"<<std::endl;
  
        if((node->items()[i_node].empty())||node->items()[i_node].compare("")==0){
            debug("brea5.5");
            node->items()[i_node] = item;
  
            node->i_count();
        }
        else{
            debug("break6");
            int i_node = node->rel_index();
            for(int i = node->i_count()-1; i>=i_node; i--){
              node->items()[i+1]= node->items()[i];
            }
            node->items()[i_node]=item;
            node->i_count();
        }
        //std::string temp =;
        //node->items()[node->rel_index()]=temp;
    }

    debug("break7");
    
    _count++;
}

std::string& MyChunkyList::lookup(int index){
  std::string* result;
  MyChunkyNode* node = nodeIndex(index);
  int i = node->rel_index();
  result = node->items()+i;
  return *result;
}

void MyChunkyList::remove(int index){
  if(index==0)
    _head->items()[0]="";
  MyChunkyNode* node = nodeIndex(index);
  for(int i = 1 ; i<node->i_count()-1; i++){
    node->items()[i]= node->items()[i+1];
  }
  node->items()[node->i_count()-1]="";
  
 if(node->isEmpty()){
    if(node!=head()){
      node->prev()->setNext(node->next());
    }
    else if(node!=tail()){
      node->next()->setPrev(node->prev());  
    }
    delete node;
  }
    
  
  _count--;
}

MyChunkyNode* MyChunkyList::nodeIndex(int item_i){
    MyChunkyNode* next;
    int node_i = -1;
    MyChunkyNode* node_with_index = nullptr;
    MyChunkyNode* node;
    if(item_i==0){
      node_with_index = _head;
      node_with_index->setRel_index(0);
      return node_with_index;
    }

    //index at that point doesnt exist yet
    else if(item_i >= this->count()){
      for(node = _head; node!=nullptr; node = next){
        for(int i = 0; i<_chunksize; i++){
            if(!node->items()[i].empty()||node->items()[i].compare("")!=0){
              node_i++;
            }
            else if((node_i==item_i-1)&&(node->items()[i].empty()||node->items()[i].compare("")==0)){
              node_i++;
              node->setRel_index(i);
              node_with_index = node;
              return node_with_index;
            }
        }
        next = node->next();
        if((node->next()==nullptr)&&(node_i==item_i-1)){
          MyChunkyNode* new_node = new MyChunkyNode(_chunksize);
          new_node->setNext(next);
          new_node->setPrev(node);
          node->setNext(new_node);
        }
        next = node->next();
      }
    }
  else{
    node_i=-1;
    for(node = _head; node!=nullptr; node = next){
      for(int i = 0; i<_chunksize; i++){
          if(!node->items()[i].empty()||node->items()[i].compare("")!=0){
            node_i++;
            if(node_i==item_i){
              node->setRel_index(i);
              node_with_index = node;
              return node_with_index;
            } 
          } 
      }
      next = node->next();
    }
  }
  return node_with_index;
}

std::string MyChunkyList::listToString(){
    std::string str = "";
    MyChunkyNode* next;
    for(MyChunkyNode* node = _head; node!=nullptr; node = next){
        str+=node->nodeToString();
        next = node->next();
    }
    return str;
}

void MyChunkyList::debug(std::string msg){
  bool debug = false;
  if(debug)
    std::cout<<msg<<std::endl;
}

MyChunkyList::~MyChunkyList() {
  delete _head;
}
