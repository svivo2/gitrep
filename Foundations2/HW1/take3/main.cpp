#include "review.h"

int main()
{
  string command = "";
  Review * r = new Review[100];
  int count = 0;

  cout << "Welcome! To enter a new review, please type \"enter\". "
      << "To search for reviews, please type \"search\". "
      << "To quit, please type \"quit\".\n"
      << "Please enter a command: ";

  cin >> command;


  while (command != "quit")
  {
    if (command == "enter")
    {
      r->insertReview(r);
      count++;
    }
    if (command == "search")
    {
      r->searchReview(r,count);
    }
    cout << "Type \"enter\" to enter a new review, "
        << "\"search\" to search for a review, "
        << "and \"quit\" to quit.\n";

    cin >> command;
  }

}
