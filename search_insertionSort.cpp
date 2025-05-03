
// Damian Acosta 


#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;


bool linear_search(int x, int* A, int n)
{
	if(n == 0)
	{
	    return false;
	}
    if(A[0] == x)
    {
        return true;
    }
    return linear_search(x, A + 1, n - 1);
}

bool binary_search(int x, int* A, int n)
{
    int l = 0;
    int r = n - 1;
    
    while(l <= r)
    {
        int mid = l + (r - 1) /  2;
        
        if(A[mid] == x)
        {
            return true;
        }
        else if (A[mid] < x)
        {
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }
    return false;
}

// Implement binary search
// Return true if x exist in the array A with size n, and return false otherwise
// s and n works like l and r in the iteration implementation. starting from s and ending at n
//So this function says search x in A from index l to r

bool binary_search_recursion(int x, int* A, int l, int r) 
{
    if (l > r)
    {
        return false;
    }
    int mid = l + (r-1) / 2;
    
    if(A[mid] == x)
    {
        return true;
    }
    if (x < A[mid])
    {
        return binary_search_recursion(x, A, l, mid - 1);
    }
    return binary_search_recursion(x, A, mid + 1, r);
}


// Implement Insertion Sort
// You can use a method "swap" to swap the location of two elements
// For example swap(A[0],A[n-1]) would swap the first element and last element

void insertion_sort(int* A, int n)
{
 for (int i = 1; i < n; i++)
    {  
        int key = A[i]; 
        int j = i - 1;  

      
        while (j >= 0 && A[j] > key) 
        {  
            A[j + 1] = A[j];  
            j--;
        }
        
        A[j + 1] = key;
    }
}




int main() {
	int A[10] = { 1, 3, 4, 7, 9, 11, 14, 15, 17, 20 };


	if (linear_search(0, A, 10) == false)
		cout << "0 is not in the array." << endl;
	else
		cout << " your linear algorithm is wrong" << endl;

	if (linear_search(9, A, 10))
		cout << "9 is in the array." << endl;
	else
		cout << " your linear algorithm is wrong" << endl;

	if (binary_search(0, A, 10) == false)
		cout << "0 is not in the array." << endl;
	else
		cout << " your binary algorithm is wrong" << endl;

	if (binary_search(17, A, 10))
		cout << "17 is in the array." << endl;
	else
		cout << " your binary algorithm is wrong" << endl;

	if (binary_search_recursion(0, A, 0, 10) == false)
		cout << "0 is not in the array." << endl;
	else
		cout << " your binary recursion algorithm is wrong" << endl;

	if (binary_search_recursion(17, A, 0, 10))
		cout << "17 is in the array." << endl;
	else
		cout << " your binary recursion algorithm is wrong" << endl;



	int B[11] = { 6, -1, 9, 3, 4, 6, 0, -5, -9, 7, 1 };

	insertion_sort(B, 11);

	cout << "the following array should be sorted" << endl;
	for (int i = 0; i < 11; ++i)
		cout << B[i] << " ";
	cout << endl;

	return 0;

}
