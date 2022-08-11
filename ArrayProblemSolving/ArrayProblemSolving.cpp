#include<iostream>
#include<vector>

using namespace std;


void MultipleMissingElementGeneric()
{
	vector<int> MissingElement, A = { 5,20,25,30,45,50 };
	int ElementDiff=A[1]-A[0], Incrementor, ActuralDiff = A[0];

	//Finding the element difference in the missing element array
	for (int i = 1,j=2;i < A.size() - 1;i++,j++)
	{

		if (A[j] - A[i] < ElementDiff)
			ElementDiff = A[j] - A[i];
	}
	cout << "Element Difference : " << ElementDiff << endl;

	//find the incrementor
	Incrementor = ElementDiff - 1;

	//Finding the missing element in the array

	for (int i = 0;i < A.size();i++)
	{
		if ((A[i] - i) != ActuralDiff)
		{
			while (ActuralDiff < (A[i] - i))
			{
				MissingElement.push_back(ActuralDiff + i);
				ActuralDiff += ElementDiff;
			}
		}
		ActuralDiff += Incrementor;
	}

	//Display the output

	cout << "Missing elements in the given Array : " << endl;
	for (int x : MissingElement)
		cout << x << " ";
	cout << endl;


}






void MultipleMissingElementInSeries()
{
	vector<int> MissingElements,A = { 6,7,8,9,11,12,15,16,17,18,19 };
	int diff = A[0];

	//looping to find the missing number 
	for (int i = 0;i < A.size();i++)
	{
		if ((A[i] - i) != diff)
		{
			while (diff < (A[i] - i))
			{
				MissingElements.push_back(diff + i);
				diff++;
			}
		}
	}
	cout << "Missing Elements in the given Array :" << endl;
	for (int x : MissingElements)
		cout << x << " ";

}


void MissingElementInIncreasingSequence()
{
	vector<int> A = { 7,14,28,35};
	int ElementDiff, Incrementor, ActualDiff, MissingElement;

	// difference between the element in array in consequent places -> element difference
	ElementDiff = A[1] - A[0];

	//for any kind of increasing sequence -> incrementor changes
	Incrementor = ElementDiff - 1;

	//condition checked with difference between value and index -> actual difference
	ActualDiff = A[0];

	for (int i = 0;i < A.size();i++)
	{
		if ((A[i] - i) != ActualDiff)
		{
			MissingElement = ActualDiff + i;
			break;
		}
		ActualDiff += Incrementor;
	}

	cout << "Missing element in the array is : " << MissingElement<<endl;

}






void MissingElementInSequenceM1()
{
	vector<int> A = { 1,2,3,4,6,7,8,9,10,11,12 };

	int SumOfNumbers = 0, SumInArray = 0, MissingElement;

	int lastElement = A.back();

	// sum of n natural numbers , n-> last element

	SumOfNumbers = (lastElement * (lastElement + 1)) / 2;

	cout << "Sum of " << lastElement << " Consequtive Number = " << SumOfNumbers << endl;

	// sum of elements in the Array

	for (int i = 0;i < A.size();i++)
		SumInArray += A[i];

	cout << "Sum of elements in the Array = " << SumInArray << endl;

	// finding the missing element 

	MissingElement = SumOfNumbers - SumInArray;

	cout << "Missing element in the Array is : " << MissingElement << endl;

}

void MissingElementInSequenceM2()
{
	vector<int> A = { 6,7,8,9,10,11,13,14,15,16,17 };

	int diff = A[0],MissingElement;

	//looping to find the missing element 

	for (int i = 0; i < A.size();i++)
	{
		if (A[i]-i!=diff)
		{
			MissingElement = diff + i;
			break;
		}
	}

	cout << "Missing Element in Array is : " << MissingElement << endl;

}


int main()
{
	//MissingElementInSequenceM1();
	//MissingElementInSequenceM2();
	//MissingElementInIncreasingSequence();
	//MultipleMissingElementInSeries();
	MultipleMissingElementGeneric();

	return 0;
}
