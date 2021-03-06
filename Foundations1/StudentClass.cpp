#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
   Student();
   Student(const Student & student);
   ~Student();

   void Set(const int uaid, const string name, const float gpa);
   void Get(int & uaid, string & name, float & gpa) const;
   void Print() const;
   void Read();

private:
   int Uaid;
   string Name;
   float Gpa;
};

Student::Student()
{
   cout << "Constructor\n";
   Uaid = 0;
   Name = "none";
   Gpa = 0;
}

Student::Student(const Student & student)
{
   cout << "Copy constructor\n";
   Uaid = student.Uaid;
   Name = student.Name;
   Gpa = student.Gpa;
}

Student::~Student()
{
   cout << "Destructor\n";
}

void Student::Set(const int uaid, const string name, const float gpa)
{
   cout << "Set\n";
   Uaid = uaid;
   Name = name;
   Gpa = gpa;
   if(gpa < 0.0) Gpa = 0.0;
   else if(gpa > 4.0) Gpa = 4.0;
}

void Student::Get(int &uaid, string & name, float &gpa) const
{
   cout << "Get\n";
   uaid = Uaid;
   name = Name;
   gpa = Gpa;
}

void Student::Print() const
{
   cout << "Print\n";
   cout << Uaid << " " << Name << " " << Gpa << endl;
}

void Student::Read()
{
   cout << "Read\n";
   cin >> Uaid >> Name >> Gpa;
   if(Gpa < 0.0) Gpa = 0.0;
   else if(Gpa > 4.0) Gpa = 4.0;
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.Set(1234, "John", 2.5);
   student1.Print();
   Student student2(student1);
   student2.Print();
   student2.Set(2345, "Susan", 3.9);
   student2.Print();
   Student student3;
   student3.Read();
   student3.Print();
   return 0;
}