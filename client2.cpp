//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Antonio Monje
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"
#include<stdlib.h>
//Purpose of the program: To generate the next case using the queue class 
//Algorithm: A while loop that loops until the queue is full removing the first element then adding the next three using the removed element finally siplaying the contents. But you have to start with the first three inputs being A B and C
int main()
{// A, B, C in the queue
  
  queue myLine; // string queue
  el_t x; //el_t for front of queue
  
  //the first three elements are added to the queue
  myLine.add("A");
  myLine.add("B");
  myLine.add("C");
  
  // shows the contents of the queue currently
  myLine.displayAll();
  
  while(!myLine.isFull()) 
    {
      try
	{
	  cout << endl;	    
	  myLine.remove(x);//removes front element that is used to add the next set 
	  cout << x << " was removed" << endl;
	  myLine.add(x + "A");
	  myLine.add(x + "B");
	  myLine.add(x + "C");
	  
	  myLine.displayAll();//displays the current elements in the queue
	  
	}
      // Catch exceptions and report problems and quit the program now.
      // Error messages describe what is wrong with the expression.
      catch (queue::Overflow)
	{cout << "Error: Cannot add!" << endl; exit(1);}
      catch (queue::Underflow) // for too few operands
	{cout << "Error: Cannot take out!" << endl; exit(1);}
      
    }
  return 0;
}

