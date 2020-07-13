#ifndef MYCHUNKYNODE_H
#define MYCHUNKYNODE_H

#include "ChunkyNode.h"

class MyChunkyNode: public ChunkyNode {
  
  MyChunkyNode* _prev;
  MyChunkyNode* _next;
  std::string* _items;
  int _size;
  int _count;
  int _rel_index;

public:
  MyChunkyNode(int chunksize);

  MyChunkyNode(std::string item, MyChunkyNode* prev,
              MyChunkyNode* next, int chunksize);

  // Returns the number of items stored in this Node.
  int count() const;

  // Returns the items at this node as a C array.
  std::string* items() const;

  // Returns a pointer to the Node before this one, or nullptr.
  MyChunkyNode* prev() const;

  // Returns a pointer to the Node after this one, or nullptr.
  MyChunkyNode* next() const;

  void split(int case_type);

  void split(int case_type, std::string temp);

  void setNext(MyChunkyNode* next);

  void setPrev(MyChunkyNode* prev);

  void setRel_index(int index);

  int rel_index();

  bool isFull();

  bool isEmpty();

  void init_arr(std::string* arr);

  int i_count();

  void i_count(int num);

  std::string nodeToString();

  // Don't forget!
  ~MyChunkyNode();
};

#endif
