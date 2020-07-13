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
  MyChunkyNode* tail=nullptr;
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
    MyChunkyNode* _tail;
    for(MyChunkyNode* node = _head; node!=nullptr; node = next){
      if(node->next()==nullptr){
        _tail = node;
      }
      next = node->next();
    }

    //head
    if((index == 0)&&(node->isFull())){
        debug("break1");
        MyChunkyNode* new_node = new MyChunkyNode(item, nullptr, _head, _chunksize);
        _head = new_node;
        node->setPrev(new_node);
    }
    //tail
    else if(node==_tail&&(index==count()-1)&&node->isFull()){
        debug("break2");
        MyChunkyNode* new_node;
        if(_chunksize==1){
          new_node = new MyChunkyNode(item, _tail->prev(), _tail, _chunksize);
          _tail->prev()->setNext(new_node);
          _tail->setPrev(new_node);
        }
        else{
          new_node = new MyChunkyNode(_tail->items()[_chunksize-1], _tail, nullptr, _chunksize);
          _tail->items()[_chunksize-1]=item;
          _tail->setNext(new_node);
        }
        node->i_count();
        new_node->i_count();
    }
    //just full
    else if(node->isFull()){
        debug("break3");
        int i_node = node->rel_index();
        std::string temp = node->items()[node->i_count()-1];
        //int temp_i = _chunksize-1-i_node+index;
        //int temp_i = node->i_count() - i_node + index;
    
        //shift right
        for(int i = _chunksize-2; i>=i_node; i--){
          node->items()[i+1]= node->items()[i];
        }
        //insert
        node->items()[i_node]=item;
        
        
        debug("break4");
        
        if(_chunksize ==1){
          node->split(1);
          node->i_count();
          node = nodeIndex(index);
          node->i_count();
          node = node->next();
          node->items()[0]=temp;
          node->i_count();
        }
        else{
          node->split(1,temp);
          node->i_count();
          node = nodeIndex(index);
          node->i_count();
          /*
          node = nodeIndex(temp_i);
          for(int i = _chunksize-2; i>=node->rel_index(); i--){
            if(!node->items()[i].empty()&&node->items()[i].compare("")!=0)
              node->items()[i+1]= node->items()[i];
          }
          node->items()[node->rel_index()+1] = temp;
          */
        }
        node->i_count();
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
    //merge check

    debug("break8");
    if(_head == _tail){
      return;
    }
    else{
      for(MyChunkyNode* node = _head; node->next()!=nullptr; node = next){
          next = node->next();
          int count = node->i_count() + next->i_count();
          if(count<=_chunksize/2){
            merge(node,next);
          }
      }
    }
   
}

std::string& MyChunkyList::lookup(int index){
  if((index < 0) || (index >= count())) {	
        // Invalid index!  Throw an exception.	
        throw std::out_of_range("Invalid index.");	
  }
  //std::string* result;
  MyChunkyNode* node = nodeIndex(index);
  int i = node->rel_index();
  //result = node->items()+i;
  return node->items()[i];
}

void MyChunkyList::remove(int index){
  if((index < 0) || (index >= count())) {	
        // Invalid index!  Throw an exception.	
        throw std::out_of_range("Invalid index.");	
  }
  MyChunkyNode* node = nodeIndex(index);
  if(index==0){
    _head->items()[0]="";
  }
  else{
    for(int i = 1 ; i<node->i_count()-1; i++){
      node->items()[i]= node->items()[i+1];
    }
    node->items()[node->i_count()-1]="";
  }

  node->i_count();
  _count--;

 if(node->isEmpty()){
    if(node!=head()&&node!=tail()){
      node->prev()->setNext(node->next());
      node->next()->setPrev(node->prev());
    }
    else if(node==tail()&&node==head()){
      delete node;
      _head = nullptr;
      return;
    }
    else if(node==tail()){
      node->prev()->setNext(nullptr);
      delete node;
      return;  
    }
    else if(node==head()){
      node->next()->setPrev(nullptr);
      _head = node->next();
      delete node;
      return;
    }
    delete node;
    return;
  }
  if(node==head()){
    int countNext = node->i_count() + node->next()->i_count();
    if(countNext<=_chunksize/2){
      merge(node,node->next());
    }
  }
  else if(node==tail()){
    int countPrev = node->i_count() + node->prev()->i_count();
    if(countPrev<=_chunksize/2){
      merge(node->prev(),node);
    }
  }
  else{
    int countPrev = node->i_count() + node->prev()->i_count();
    int countNext = node->i_count() + node->next()->i_count();

    if(countPrev<=_chunksize/2){
      merge(node->prev(),node);
    }
    else if(countNext<=_chunksize/2){
      merge(node,node->next());
    }
  }
  node->i_count();
}

void MyChunkyList::merge(MyChunkyNode* node1, MyChunkyNode* node2){
  int m = node1->i_count();
  int n = node2->i_count();
  for (int i = 0; i < m + n; i++) {
      if (i >= m){
        node1->items()[i] = node2->items()[i - m];
        node2->items()[i - m]="";
      }
	}
  node1->i_count();
  if(node2!=head()&&node2!=tail()){
    node2->prev()->setNext(node2->next());
    node2->next()->setPrev(node2->prev());
  }
  else if(node2==tail()&&node2==head()){
    delete node2;
    _head = nullptr;
    return;
  }
  else if(node2==tail()){
    node2->prev()->setNext(nullptr);  
  }
  else if(node2==head()){
    node2->next()->setPrev(nullptr);
    _head = node2->next();
  }
  delete node2;
  
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
        if((next==nullptr)&&(node_i==item_i-1)){
          MyChunkyNode* new_node = new MyChunkyNode(_chunksize);
          new_node->setPrev(node);
          node->setNext(new_node);
        }
        next = node->next();
      }
    }
  //index at that point already exists
  else{
    node_i=-1;
    for(node = _head; node!=nullptr; node = next){
      for(int i = 0; i<_chunksize; i++){
          if(!node->items()[i].empty()||node->items()[i].compare("")!=0){
            node_i++;
            debug("break0.1");
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
        //std::cout<<"node: "<<node<<std::endl;
        //std::cout<<"node->next(): "<<node->next()<<std::endl;
        str+=node->nodeToString();
        next = node->next();
        //std::cout<<"next: "<<next<<std::endl;
    }
    return str;
}

void MyChunkyList::debug(std::string msg){
  bool debug = false;
  if(debug)
    std::cout<<msg<<std::endl;
}

void MyChunkyList::debug(int msg){
  bool debug = false;
  if(debug)
    std::cout<<msg<<std::endl;
}

MyChunkyList::~MyChunkyList() {
  ChunkyNode* next;
  for(ChunkyNode* node = _head; node!=nullptr; node = next){
    next = node->next();
    delete node;
  }
}
