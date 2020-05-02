#include "stack.h"

int main()
{
  Stack s;
  char ch = '\0';
  string br = "br";
  string tag = "";

  ifstream din;
  din.open("infile.txt");

  while (din.get(ch))
  {
    if(ch == '<')
    {
      char * str = new char[10];
      din.get(ch);
      if(ch != '/')
      {
        for(int i = 0; (ch != '>') && (ch != ' '); i++)
        {
          str[i] = ch;
          din.get(ch);
        }
        string check(str);
        cout << "Tag: " << "<" << check << ">\n";
        if (check != "br")
          s.Push(check);
        s.Print();
      }
      else
      {
        din.get(ch);
        for(int i = 0; (ch != '>') && (ch != ' '); i++)
        {
          str[i] = ch;
          din.get(ch);
        }
        string check(str);
        cout << "Tag: " << "</" << check << ">\n";
        s.Pop(tag);
        if (check != tag)
          cout << "Syntax Error\n";
        s.Print();
      }
      str = NULL;
      delete[] str;
    }
  }
  if(s.IsEmpty())
    cout << "Congratulations, all HTML tags match!\n";
}
