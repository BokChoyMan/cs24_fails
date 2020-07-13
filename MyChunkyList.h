#ifndef MYCHUNKYLIST_H
#define MYCHUNKYLIST_H

#include "ChunkyList.h"
#include "MyChunkyNode.h"
#include <iostream>

class MyChunkyList: public ChunkyList {
  
  MyChunkyNode* _head;
  int _chunksize;
  int _count;

public:

  MyChunkyList(int chunksize);

  // Returns the number of items (not Nodes) in the list.
  int count() const;

  // Returns a pointer to the first Node in the list, or nullptr.
  ChunkyNode* head() const;

  // Returns a pointer to the last Node in the list, or nullptr.
  ChunkyNode* tail() const;

  void find_Tail();

  // Inserts an item at index.
  // Throws std::out_of_range if index is negative or > count().
  void insert(int index, const std::string& item);

  // Returns a reference to the item at index.
  // Throws std::out_of_range if there is no such item.
  std::string& lookup(int index);

  // Removes the item at index.
  // Throws std::out_of_range if there is no such item.
  void remove(int index);

  MyChunkyNode* nodeIndex(int item_i);

  void merge(MyChunkyNode* node1, MyChunkyNode* node2);

  std::string listToString();

  void debug(std::string msg);
  void debug(int msg);
  // Don't forget!
  ~MyChunkyList();

  
};


#endif
