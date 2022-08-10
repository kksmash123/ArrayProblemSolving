#include<iostream>
#include<vector>

using namespace std;


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
	MissingElementInIncreasingSequence();
	return 0;
}
