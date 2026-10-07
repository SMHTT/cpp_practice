/*Problem: Remove Duplicate Elements from an Array

Given an array of n integers, remove all duplicate elements
while preserving the order of their first occurrence.

When a duplicate element is found, remove it by shifting
all elements after it one position to the left.

Constraints:
- Do not use a second array.
- Do not use vector, set, or sort.
- Use only arrays, loops, conditions, and basic variables*/

#include <iostream>
using namespace std;

int main()
{
int count;

cout << "count:";
cin >> count;

if (count == 0)
{
    cout << "null";
    return 0;
}

int arr[count];

for (int i = 0; i < count; i++)
{
   cout << "num:";
   cin >> arr[i];
}

for (int i = 0; i < count; i++)
{
    for (int j = i+1; j < count; j++)
    {
        if (arr[i] == arr[j])
        {
            for (int k = j+1; k < count; k++)
            {
                    arr[k-1] = arr[k];
            }
            count--;
            j--;
        }
    }
}

for (int i = 0; i < count; i++)
{
    cout << arr[i] << "  ";
}


    return 0;
}