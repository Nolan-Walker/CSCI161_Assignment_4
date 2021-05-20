//
//  stack.cpp
//  Assignment4
//
//  Created by Nolan Caissie on 2017-03-14.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "stack.h"
#include <iostream>
//   privately accessible data fields
//   for the stack class:
//      StackElement *sptr;
//      int maxsize;
//      int currentsize;

// default constructor, the maximum stack size is
//    determined by DEFAULTMAX const in stack.h
stack::stack()
{
    maxsize = DEFAULTMAX;
    currentsize = 0;
    sptr = new StackElement[maxsize];
}

// constructor using the passed size
// as the maximum stack size
// if the passed size is a positive integer,
// otherwise uses DEFAULTMAX
stack::stack(int size)
{
    if (size > 0) maxsize = size;
    else maxsize = DEFAULTMAX;
    currentsize = 0;
    sptr = new StackElement[maxsize];
}

// destructor - deallocate stack space
stack::~stack()
{
    delete [] sptr;
}

// push new data on stack
void stack::push(StackElement data)
{
    // check to ensure stack is not already full
    if (currentsize < maxsize) {
        // add new element to top space on stack
        // and increment size counter
        // (index of top element)
        sptr[currentsize++] = data;
    } else {
        std::cerr << "Cannot push onto a full stack" << std::endl;
    }
}

// remove top stack element
void stack::pop()
{
    // check to ensure stack is not already empty
    if (currentsize > 0) {
        // decrement size counter
        // (which is also index of top element)
        currentsize--;
    } else {
        std::cerr << "Cannot pop from an empty stack"
        << std::endl;
    }
}

// get copy of top stack element
StackElement stack::top()
{
    // check to ensure stack is not currently empty
    if (currentsize > 0) {
        // return copy of top element
        return (sptr[currentsize-1]);
    } else {
        std::cerr << "Cannot examine top of empty stack, "
        << "returning default value" << std::endl;
        return defaultelement;
    }
}

// return True iff stack is empty
bool stack::isempty()
{
    return (currentsize == 0);
}

// return True iff stack is full
bool stack::isfull()
{
    return (currentsize == maxsize);
}
