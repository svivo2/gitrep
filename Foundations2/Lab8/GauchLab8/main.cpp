//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
#include "stack.h"

int main()
{
   Stack stack;
   int n = 0;

   cout << "\nPushing 3";
   stack.Push(3);
   stack.Top(n);
   cout << "\nTop: " << n << endl;
   cout << "\nPushing 1";
   stack.Push(1);
   stack.Top(n);
   cout << "\nTop: " << n << endl;
   cout << "\nPushing 4";
   stack.Push(4);
   stack.Top(n);
   cout << "\nTop: " << n << endl;
   cout << "\nPushing 1";
   stack.Push(1);
   stack.Top(n);
   cout << "\nTop: " << n << endl;
   cout << "\nPushing 5";
   stack.Push(5);
   stack.Top(n);
   cout << "\nTop: " << n << endl;
   cout << "\nPushing 9";
   stack.Push(9);
   stack.Top(n);
   cout << "\nTop: " << n << endl;

   cout << "\nPrint: ";
   stack.Print();

   stack.Pop(n);
   cout << "\nPoping " << n ;
   stack.Pop(n);
   cout << "\nPoping " << n ;
   stack.Pop(n);
   cout << "\nPoping " << n ;
   stack.Pop(n);
   cout << "\nPoping " << n ;
   stack.Pop(n);
   cout << "\nPoping " << n ;
   stack.Pop(n);
   cout << "\nPoping " << n << endl;

}
