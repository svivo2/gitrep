#include <cstring>
#include <iostream>

using namespace std;

void check(const string & s, const string & name)
{
  cout << "Checking " << name << ".\n";
  cout << name << " Contains " << s << endl;
  cout << name << " Capacity is " << s.capacity() << endl;
  cout << name << " Length is " << s.length() << endl;
  cout << name << " Size is " << s.size() << endl;
  cout << name << " Max Size is " << s.max_size() << endl;
}

int main()
{
  string s0;
  string s2;
  check(s0, "s0");
  check(s2, "s2");

  cout << "s0 is empty: " << s0.empty() << endl;

  string s1 ("Hello World!");
  check(s1, "s1");

  s2 = s1;
  check(s2, "s2");

  s2.push_back('!');
  check(s2, "s2");

  s1 += s2;
  check(s1, "s1");

  s1.insert(12, " ");
  check(s1, "s1");

  s0 = s1 + " " + s2;
  check(s0, "s0");

  s0.reserve(50);
  check(s0, "s0");

  char c = s0[12];
  cout << "c is " << c << endl;
  check(s0, "s0");

  s2.append(s2);
  check(s2, "s2");

  s2.replace(11, 2, "=");
  check(s2, "s2");

  const char * p = s2.c_str();
  cout << " p is " << p << endl;

  if (p == s2)
    cout << "p and s2 are the same.\n";
  else
    cout << "p and s2 are not the same.\n";

  s0[12] = s2[12];
  check(s0, "s0");

  s0.clear();
  s2.clear();
  check(s0, "s0");
  check(s2, "s2");

  cout << "p is " << p << endl;
  if (p == s2)
    cout << "p and s2 are the same.\n";
  else
    cout << "p and s2 are not the same.\n";
}
