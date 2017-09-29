//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Antonio Monje
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <stdlib.h>
#include "stack.h"

//Purpose of the program: to evaluate postfix expressions using the stack class
//Algorithm: overall the algorithm is a while loop that tries to evaluates the expression to tell between a number operator or and invalid item in order to do the math of a postfix expression. once it sees an operator it pops the two numbers before it and does math depending on that operator. It then displays the result if nothing went wrong with the program. If something goes wrong the program catches it and display the right error message.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  if((item >= '0' && item <= '9'))
	    {
	      item = item - 48; 
	      postfixstack.push(item);
	    }
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
		{
		  result = (box2) - (box1);
		}
	      if (item == '+')
		{
		  result = (box2) + (box1);
		}
	      if (item == '*') 
		{
		  result = (box2) * (box1);
		}
	      // ** also do the + and * cases 
	      // ** Finally push the result
	      postfixstack.push(result);
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cout << "Error: Expression is to long!" << endl; exit(1);}
      catch (stack::Underflow) // for too few operands
	{cout << "Error: To few operands!" << endl; exit(1);}
      catch (char const* errorcode) // for invalid item
	{cout << "Error: " << errorcode << endl; exit(1);}
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  
  postfixstack.pop(result);
  
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if(!postfixstack.isEmpty())
    {
      cout << "Error: A incomplete expression was found left in the stack!" << endl;
    }
  if(postfixstack.isEmpty())
    {
      cout << "The answer is: " << result << endl;
    }

  return 0;
}// end of the program
