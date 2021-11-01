#include <iostream>
using namespace std;

int compareCounter = 0;
int moveCounter = 0;
const int SIZE = 1000;
int data[SIZE];

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
	 data[posn] = data[posn - 1];
	 posn--;
   compareCounter++;
      }

      // Put new value into array
      data[posn] = value;
      moveCounter++;
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
        compareCounter++;
      }

      // Scan right to left
      while ((left < right) && (data[right] >= pivot))
      {
        right--;
        compareCounter++;
      }

      // Swap data values
      int temp = data[left];
      data[left] = data[right];
      data[right] = temp;
      moveCounter++;
   }

   // Swap pivot to mid
   mid = left;
   data[high] = data[mid];
   data[mid] = pivot;
   moveCounter++;
}

//----------------------------------------------------------------
// Recursive Quicksort algorithm using basic partition function.
//----------------------------------------------------------------
void quick_sort(int data[], int low, int high)
{
   // Check terminating condition
   if (low < high)
   {
      compareCounter++;
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
        compareCounter++;
        if (data[index1] < data[index2])
        {
          compareCounter++;
          copy[index++] = data[index1++];
          moveCounter++;
        }
        else
          moveCounter++;
          copy[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
      {
        compareCounter++;
	       copy[index++] = data[index1++];
         moveCounter++;
       }
      // Copy any remaining entries from the second half
      while (index2 <= high)
      {
        compareCounter++;
        copy[index++] = data[index2++];
        moveCounter++;
      }

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
      {
        data[low + index] = copy[index];
        moveCounter++;
      }
      delete []copy;
   }
}
void hybrid_merge_sort(int data[], int low, int high)
{
   // Check terminating condition
   if (high < 50)
      insertion_sort(data, low, high);
   {
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
          compareCounter++;
          if (data[index1] < data[index2])
          {
            compareCounter++;
            copy[index++] = data[index1++];
            moveCounter++;
          }
          else
            moveCounter++;
            copy[index++] = data[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
        {
          compareCounter++;
  	       copy[index++] = data[index1++];
           moveCounter++;
         }
        // Copy any remaining entries from the second half
        while (index2 <= high)
        {
          compareCounter++;
          copy[index++] = data[index2++];
          moveCounter++;
        }

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
      {
        data[low + index] = copy[index];
        moveCounter++;
      }
      delete []copy;
   }
 }
}

int main()
{
  for( int n = 10; n <= 1000; n = n * 10 )
  {
    create_random_data(data, n, n);
    hybrid_merge_sort(data, 0, n - 1);

    cout << "\nhybrid_merge_sort: \n\n";
    cout << "N: " << n << endl;
    cout << "Compares: " << compareCounter << endl;
    cout << "Moves: " << moveCounter << endl;
    compareCounter = 0;
    moveCounter  = 0;

    create_random_data(data, n, n);
    merge_sort(data, 0, n - 1);

    cout << "\nmerge_sort: \n\n";
    cout << "N: " << n << endl;
    cout << "Compares: " << compareCounter << endl;
    cout << "Moves: " << moveCounter << endl;
    compareCounter = 0;
    moveCounter  = 0;

    create_random_data(data, n, n);
    insertion_sort(data, 0, n - 1);

    cout << "\ninsertion_sort: \n\n";
    cout << "N: " << n << endl;
    cout << "Compares: " << compareCounter << endl;
    cout << "Moves: " << moveCounter << endl;
    compareCounter = 0;
    moveCounter = 0;

    create_random_data(data, n, n);
    quick_sort(data, 0, n - 1);

    cout << "\nquick_sort: \n\n";
    cout << "N: " << n << endl;
    cout << "Compares: " << compareCounter << endl;
    cout << "Moves: " << moveCounter << endl;
    compareCounter = 0;
    moveCounter = 0;

  }


}
