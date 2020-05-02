#include <iostream>
using namespace std;
int move_counter, compare_counter = 0;

//------------------------------------------------------------------
// Initialize data array with random values
//------------------------------------------------------------------
void create_random_data(int data[], int count, int range)
{
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

//------------------------------------------------------------------
// Initialize data array with mostly sorted values
//------------------------------------------------------------------
void create_mostly_sorted_data(int data[], int count, int swaps)
{
   // Put sorted data values into array
   for (int index = 0; index < count; index++)
      data[index] = index;

   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < swaps; index++)
   {
      int pos1 = rand() % count;
      int pos2 = rand() % count;
      int temp = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}

//----------------------------------------------------------------
// Insertion sort algorithm
//----------------------------------------------------------------
void insertion_sort(int data[], int low, int high)
{
  // Insert each element of unsorted list into sorted list
  for (int unsorted = low+1; unsorted <= high; unsorted++)
  {
    // Select unsorted value to be inserted
    int value = data[unsorted];
    int posn = unsorted;

    // Make room for new data value
    while ((posn > 0) && (data[posn - 1] > value))
    {
      compare_counter++;
      data[posn] = data[posn - 1];
      posn--;
      move_counter++;
    }
    compare_counter++;

    // Put new value into array
    data[posn] = value;
    move_counter++;
  }
}

//----------------------------------------------------------------
// Partition function used by Quicksort.
//----------------------------------------------------------------
void partition(int data[], int low, int high, int &mid)
{
   // Select pivot value
   int pivot = data[high];
   int left = low;
   int right = high;
   // Partition array into two parts
   while (left < right)
   {
      // Scan left to right
      while ((left < right) && (data[left] < pivot))
      {
        left++;
        compare_counter++;
      }

      // Scan right to left
      while ((left < right) && (data[right] >= pivot))
      {
        right--;
        compare_counter++;
      }
      // Swap data values
      int temp = data[left];
      data[left] = data[right];
      data[right] = temp;
      move_counter++;
   }

   // Swap pivot to mid
   mid = left;
   data[high] = data[mid];
   data[mid] = pivot;
   move_counter++;
}

//----------------------------------------------------------------
// Recursive Quicksort algorithm using basic partition function.
//----------------------------------------------------------------
void quick_sort(int data[], int low, int high)
{
   // Check terminating condition
   if (low < high)
   {
      // Partition data into two parts
      int mid = 0;
      partition(data, low, high, mid);

      // Recursive calls to sort array
      quick_sort(data, low, mid - 1);
      quick_sort(data, mid + 1, high);
   }
}

//----------------------------------------------------------------
// Mergesort using secondary storage for data merging.
//----------------------------------------------------------------
void merge_sort(int data[], int low, int high)
{
  // Check terminating condition
  int range = high - low + 1;
  if (range > 1)
  {
    // Divide the array and sort both halves
    int mid = (low + high) / 2;
    merge_sort(data, low, mid);
    merge_sort(data, mid + 1, high);

    // Create temporary array for merged data
    int *copy = new int[range];

    // Initialize array indices
    int index1 = low;
    int index2 = mid + 1;
    int index = 0;

    // Merge smallest data elements into copy array
    while (index1 <= mid && index2 <= high)
    {
      if (data[index1] < data[index2])
        copy[index++] = data[index1++];
      else
        copy[index++] = data[index2++];
      compare_counter++;
      move_counter++;
    }

    // Copy any remaining entries from the first half
    while (index1 <= mid)
    {
      copy[index++] = data[index1++];
      move_counter++;
    }

    // Copy any remaining entries from the second half
    while (index2 <= high)
    {
      copy[index++] = data[index2++];
      move_counter++;
    }
    // Copy data back from the temporary array
    for (index = 0; index < range; index++)
    {
      data[low + index] = copy[index];
      move_counter++;
    }
    delete []copy;
  }
}

int main()
{
  int SIZE = 10000;
  int data[SIZE];

  for (int i = 10 ; i <= SIZE; i = i * 10)
  {
    /*cout << "----------------------------------------------------------------------------------\n";
    cout << "Insertion Sort Test\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------------------\n";
    create_random_data(data, i, i-1);
    insertion_sort(data,0,i-1);
    cout << "Random Data Move Counter with "<< i << " values: " << move_counter << endl;
    cout << "Random Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, i/10);
    insertion_sort(data,0,i);
    cout << "Mostly Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "Mostly Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, 0);
    insertion_sort(data,0,i);
    cout << "Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;
    cout << "----------------------------------------------------------------------------------\n";*/

    cout << "----------------------------------------------------------------------------------\n";
    cout << "Merge Sort Test\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------------------\n";

    create_random_data(data, i, i-1);
    merge_sort(data,0,i - 1);
    cout << "Random Data Move Counter with "<< i << " values: " << move_counter << endl;
    cout << "Random Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, i/10);
    merge_sort(data,0,i - 1);
    cout << "90% Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "90% Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, i/2);
    merge_sort(data,0,i - 1);
    cout << "50% Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "50% Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, 0);
    merge_sort(data,0,i - 1);
    cout << "Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;
    cout << "----------------------------------------------------------------------------------\n";

    /*cout << "----------------------------------------------------------------------------------\n";
    cout << "Quick Sort Test\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------------------\n";

    create_random_data(data, i, i-1);
    quick_sort(data,0,i - 1);
    cout << "Random Data Move Counter with "<< i << " values: " << move_counter << endl;
    cout << "Random Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, i/10);
    quick_sort(data,0,i - 1);
    cout << "Mostly Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "Mostly Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;

    move_counter = 0;
    compare_counter = 0;
    create_mostly_sorted_data(data, i, 0);
    quick_sort(data,0,i - 1);
    cout << "Sorted Data Move Counter with " << i << " values: " << move_counter << endl;
    cout << "Sorted Data Compare Counter with " << i << " values: " << compare_counter << endl;
    cout << "----------------------------------------------------------------------------------\n";*/

  }
}
