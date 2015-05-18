#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H

#include "object.h"
#include "tdalist.h"

class FSCursorList : public TDAList{
  protected:
    struct Row{
        int next;
        Object* data;
    };
    int capacity;
    Row* rows;
    int head;
  public:
    FSCursorList(int);
    virtual ~FSCursorList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual Object* erase(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isEmpty()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
    int nextAvail();
};

#endif