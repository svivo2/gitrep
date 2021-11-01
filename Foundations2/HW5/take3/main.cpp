#include <iostream>
using namespace std;

void random(int data[], int low, int high, int size)
{
  for (int i = 0; i < size; i++)
    data[i] = low + (rand() % size);
}

//------------------------------------------------------------------
// Initialize data array with mostly sorted values
//------------------------------------------------------------------
void mostly(int data[], int low, int high, int size)
{
  for (int i = 0; i < size ; i++)
    data[i] = low + i;

  // Shuffle data by swapping random pairs of values
  for (int i = 0; i < (size/10); i++)
  {
    int pos1 = rand() % (size + 1);
    int pos2 = rand() % (size + 1);
    int temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
  }
}

void sorted(int data[], int low, int high, int size)
{
  for (int i = 0; i < size ; i++)
    data[i] = low + i;
}

//-----------------------------------------------------------------
// Bubble sort algorithm
//-----------------------------------------------------------------
void bubble(int data[], int size)
{
  int pass = 0;
  int exchange = 1;

  // Bubble largest value to the right N times
  while ((pass < size) && (exchange > 0))
  {
    // Scan unsorted part of data array
    exchange = 0;
    for (int i = 0; i < size - pass - 1; i++)
    {
      // Swap two data values if out of order
      if (data[i] > data[i + 1])
      {
        int temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
        exchange++;
      }
    }
    pass++;
  }
}

//---------------------------------------------------------------
// Selection sort algorithm
//---------------------------------------------------------------
void selection(int data[], int size)
{
  // Put largest unsorted value at end of sorted list
  for (int last = size - 1; last > 0; last--)
  {
    // Find index of largest value in unsorted array
    int largest = 0;
    for (int index = 0; index <= last; index++)
      if (data[index] > data[largest])
        largest = index;

    // Swap with last element in unsorted array
    int temp = data[last];
    data[last] = data[largest];
    data[largest] = temp;
  }
}

//-----------------------------------------------------------------
// Corn sort algorithm
//-----------------------------------------------------------------
void corn(int data[], int size)
{
  int pass = 0;
  int exchange = 1;

  // Bubble largest value to the right N times
  while ((pass < size) && (exchange > 0))
  {
    // Scan unsorted part of data array
    for (int i = pass; i < size - pass; i++)
    {
      // Swap two data values if out of order
      if (data[i] > data[i + 1])
      {
        int temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
        exchange++;
      }
    }
    for (int i = size ; i > pass; i--)
    {
      // Swap two data values if out of order
      if (data[i] < data[i - 1])
      {
        int temp = data[i];
        data[i] = data[i - 1];
        data[i - 1] = temp;
        exchange++;
      }
    }
    pass++;
  }
}

//---------------------------------------------------------------
// HighLow sort algorithm
//---------------------------------------------------------------
void highLow(int data[], int size)
{
  int first = 0;
  // Put largest unsorted value at end of sorted list
  for (int last = size - 1; last > first; last--)
  {
    // Find index of largest value in unsorted array
    int largest = last;
    int smallest = first;
    for (int index = first; index < last; index++)
    {
      if (data[index] > data[largest])
        largest = index;
      if (data[index] < data[smallest])
        smallest = index;
    }

    //Swap with last element in unsorted array
    int temp = data[last];
    data[last] = data[largest];
    data[largest] = temp;
    //Swap first element in unsorted array
    temp = data[first];
    data[first++] = data[smallest];
    data[smallest] = temp;
  }
}

void print(int data[], int size)
{
  for (int i = 0; i < size; i++)
    cout << data[i] << "  ";

  cout << endl;
}


int main()
{
  int size, high, low = 0;
  int * data = NULL;

  cout << "Enter the data's lower bound, "
       << "followed by the upper bound, "
       << "separated by a space\n";
  cin >> low >> high;

  size = high - low + 1;

  data = new int[size];

  random(data, low, high, size);
  bubble(data, size);
  print(data, size);
  random(data, low, high, size);
  selection(data, size);
  print(data, size);
  random(data, low, high, size);
  corn(data, size);
  print(data, size);
  random(data, low, high, size);
  highLow(data, size);
  print(data, size);

  mostly(data, low, high, size);
  bubble(data, size);
  print(data, size);
  mostly(data, low, high, size);
  selection(data, size);
  print(data, size);
  mostly(data, low, high, size);
  corn(data, size);
  print(data, size);
  mostly(data, low, high, size);
  highLow(data, size);
  print(data, size);

  sorted(data, low, high, size);
  bubble(data, size);
  print(data, size);
  sorted(data, low, high, size);
  selection(data, size);
  print(data, size);
  sorted(data, low, high, size);
  corn(data, size);
  print(data, size);
  sorted(data, low, high, size);
  highLow(data, size);
  print(data, size);

}
