const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is ** for now        //////////////////
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
   //**// 
   class Overflow{};
   class Underflow{};
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide variable to get top element from el_t.
  void topElem(el_t&);
  


  //PURPOSE: **   The purpose of this function is to determine if the stack is empty or not ( return true if empty or false)
  bool isEmpty();

  //PURPOSE: **  The purpose of this function is to determine if the stack is full or not ( return true if full or false)
  bool isFull();

  //PURPOSE: **  The purspose of this function is to display the value of each element in the stack
  void displayAll();

  //PURPOSE: ** clear all the elements from the stack in other word  empty it.
  void clearIt();
  
};  
