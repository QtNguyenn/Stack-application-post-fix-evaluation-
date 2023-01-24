
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

/*Purpose of the program: The purpose of the program is to create a postfix stack
application which take in the expression and do arithmetic with it. This program
also handling exception overflow/underflow.  

/*Algorithm: for the algorithm, this program uses a while loop:
While there are still items left in the expression and no error:
 {
   Try {
   1.  read an item (a character).  
   2.  if it is an operand (number), 
       push it (you might get Overflow exception)
   3.  else if it is an operator,
       pop the two operands (you might get Underflow exception), and
       apply the operator to the two operands, and
       push the result.
   4.else it is an invalid item (throws exception)
  }
Catch the 3 exceptions and report problems in a friendly way (*) and quit the program now. 
}// end of while

   After the loop successfully completes: 
   1.The result will be at the top of the stack so pop it and show it.
   2.If anything is still left on the stack, an incomplete expression was found, so inform the user.

*/
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
	 
	 // ** do all the steps in the algorithm given in Notes-1
	 
	 if (isdigit(item))
	   {
	     postfixstack.push(item -'0');
	     postfixstack.displayAll();
	   }

	   else if ((item == '+') || (item == '-') || (item== '*'))
	     {
	       postfixstack.pop(box1);     ////pop the value to box1
	       postfixstack.pop(box2);    ///pop the value to box2
	       if (item == '+')
		 {
		   result = box2+box1;
		 }
	       if (item == '-')
                 {
                   result = box2-box1;
                 }
	       if (item ==  '*')
                 {
                   result = box2*box1;
                 }
	       
	       postfixstack.push(result);

	     }
	   else
	     {
	       throw ("Invalid.");
	     }
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	    {
	      cout<<"Expression too long. Overflow."<<endl;
	      exit(0);
	    }//////////////////////////
      catch (stack::Underflow)
	    {  
	      cout<<"Too few operand. Underflow."<<endl;
	      exit(0);
	    }
      catch (char const* errormsg ) // for invalid item case
	    {
	      cout<<"Error--Invalid."<<endl;
	    exit(0);
        // go back to the loop after incrementing i
      i++;
      }
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.displayAll();

  postfixstack.pop(result);
  cout<<"Result = "<<result<<endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  ///
  if(!postfixstack.isEmpty())
    {
      cout<<"Incomplete expression."<<endl;
    }

}// end of the program
