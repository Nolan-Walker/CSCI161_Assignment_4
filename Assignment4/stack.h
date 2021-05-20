//
//  stack.h
//  Assignment4
//
//  Created by Nolan Caissie on 2017-03-14.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef stack_h
#define stack_h
// DEFAULTMAX --- default maximum stack size
const int DEFAULTMAX = 128;

// StackElement is used to determine the type of
// data stored in the stack
typedef char StackElement;

// defaultelement can be used as a default
// stack element value
const char defaultelement = '\0';

// Stack class, using an array-based implementation,
// where the constructor dynamically allocates
// the array using either the DEFAULTMAX size or
// a size specified by passing a positive integer
// parameter to the constructor
//
// the usual stack operations are available:
//    top, pop, push, isempty, and isfull
//
class stack {
public:
    stack();           // default constructor
    stack(int size);   // constructor for passed size
    ~stack();          // destructor
    // push new data on stack
    void push(StackElement data);
    void pop();        // remove top stack element
    // get copy of top stack element
    StackElement top();
    bool isempty(); // return True iff stack is empty
    bool isfull();  // return True iff stack is full
private:
    StackElement *sptr;
    int maxsize;
    int currentsize;
};

#endif /* stack_h */
