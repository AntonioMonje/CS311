//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Antonio Monje
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
  top = -1; // indicate an empty stack
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing to do }
}  
//PURPOSE:  checks top and returns true if empty, false otherwise.
// ** In the comment, make sure you define "empty" in terms of top.
// "empty" means that nothing is in the top stack so the stack has nothing inside
bool stack::isEmpty()
{ 
  if (top == -1) return true;//if the top is -1 the stack is empty 
  else return false; //if its not -1 return false
}

//PURPOSE: checks top and returns true if full, false otherwise.
//** In the comment, make sure you define "full" in terms of top.
// "full" means that the stack has been filled and the top element maxed out the size of the// array
bool stack::isFull()
{ if (top == MAX-1 ) return true; //if the stack is full or max size return true
  else return false; // if its not max size or full return true
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
// Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if (isFull()) //if the stack is full throw overflow
    {
      throw Overflow();
    }
  else //if the stack is not full increment and push in a element
    {
      top++; el[top] = elem; 
    }
} 

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ if (isEmpty())//if the stack is empty throw underflow error
    {
      throw Underflow();
    }
  else { elem = el[top]; top--;}//if the stack is not empty take a element out and increment
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ if (isEmpty()) // if its empty throws underflow
    {
      throw Underflow();
    }
  else// it puts the top element into elem to pass it by reference
    {
      elem = el[top];
    } 
}
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: for loop from the top element incremeneting down display the stack elements
void stack::displayAll()
{  if (isEmpty()) cout << "[ empty ]" << endl;
  else for (int i=top; i>=0; i--)// for loop from the top to bottom to display elements
    { cout << el[i] << endl; }
  cout << "--------------" << endl;
}


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALGORITHM:while loop that pops out element until the stack is empty
void stack::clearIt()
{// ** comment a local variable
  int i = top; // i is used so that it starts at the top element
  while(!isEmpty())//while loop that pops out element until the stack is empty
   {
      pop(el[i]);
   }
}
 

