#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void removeDuplicates() {

	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
	int next, val;

	for (int i = 0;i < nums.size();i++)
	{
		next = i + 1;
		val = nums[i];
		while (next<nums.size() && nums[next] == val)
			nums.erase(nums.begin() + next);
	}



}


void removeElement() {
	vector<int> nums = { 3,2,2,3 };
	int val=3;

	for (int i = 0;i < nums.size();i++)
	{
		while(i<nums.size()  && nums[i] == 3)
		nums.erase(nums.begin()+i);
	}
}


void merge() {
	vector<int> nums1={ 4,5,6,0,0,0}, nums2={ 1,2,3 };
	int m=nums1.size(), n=nums2.size(),i=0,j=0;

	for (; i < m && j < n;i++)
	{
		if (nums2[j] <= nums1[i])
		{
			nums1.insert(nums1.begin() + i, nums2[j]);
			
			++j;
			m++;
		}

	}


	while (j < n)
	{
		nums1.insert(nums1.begin() + i, nums2[j]);
		++i;
		++j;
		m++;
	}


}


void duplicateZeros1() {
	vector<int> arr = { 1,0,2,3,0,4,5,0 };
	for (int i = 0;i < arr.size();i++) {
		if (arr[i] == 0) {
			arr.pop_back();
			arr.insert(arr.begin() + i, 0);
			++i;
		}
	}

}

void duplicateZeros()
{
	vector<int> arr1,arr = { 1,0,2,3,0,4,5,0 };
	vector<int>::iterator i, end;

	end = arr.end();
	
	for (i = arr.begin();i != end;i++)
	{
		arr1.push_back(*i);
		if (*i == 0)
		{	
			arr1.push_back(0);
			end--;
			
		}
		

	}
	for (int x : arr1)
		cout << x << " ";
}


void sortedSquares()
{
	vector<int> nums = { 7,-3,2,3,11 };
	int a;
	for (int i = 0;i < nums.size();i++)
	{
		a = nums[i];
		nums[i] = pow(abs(a), 2);
	}

	for (int x : nums)
		cout << x << " ";
	cout << endl;

	sort(nums.begin(),nums.end());
	for (int x : nums)
		cout << x << " ";
	cout << endl;

}


void findNumbers() {
	vector<int> nums = {437,315,322,431,686,264,442};
	int count, total = 0, n;

	for (int i = 0;i < nums.size();i++)
	{
		n = nums[i];
		count = 0;

		while (n != 0)
		{
			n /= 10;
			count++;
		}
		if (count % 2 == 0)
			total++;

	}

	cout<< total;

}


void findMaxConsecutiveOnes() {
	vector<int> nums = { 1,1,0,1,1,1 };
	int helper, maxcount = 0;

	for (int i = 0;i < nums.size();i++)
	{
		if (nums[i] == 1)
		{
			helper = i + 1;
			while (helper < nums.size() && nums[helper] == 1 )
				helper++;
			if ((helper - i) > maxcount)
				maxcount = helper - i;
			i = helper - 1;
			

		}
	}
	cout<<maxcount;

}


void findDuplicateAndCountInSortedArray()
{
	vector<int> A = { 3,6,8,8,10,12,15,15,15,20 };
	map<int, int> DupCountMap;
	

	int helper,inext;

	for (int i = 0;i < A.size() - 1;i++)
	{
		inext = i + 1;
		if (A[i] == A[inext])
		{
			helper = i + 1;
			while (A[helper] == A[i])
				helper++;
			DupCountMap.insert(pair<int, int>(A[i], helper - i));

		}
	}

	//Display the output
	for (auto itr = DupCountMap.begin();itr != DupCountMap.end();itr++)
		cout << itr->first << " Duplicated " << itr->second << " times" << endl;


}


void findDuplicateInSortedArray()
{
	vector<int> Duplicate, A = { 3,6,8,8,10,12,15,15,15,20 };
	int lastDuplicate = 0;

	//Finding the duplicate element in the array
	for (int i = 0, j = 1;i < A.size()-1;i++, j++)
	{
		if (A[i] == A[j] && A[i]!=lastDuplicate)
		{
			Duplicate.push_back(A[i]);
			lastDuplicate = A[i];
			
		}
	}

	//Display the Duplicate elements
	cout << "Duplicate elements in the array : " << endl;
	for (int x : Duplicate)
		cout << x << " ";
	cout << endl;

}


void MissingElementInUnsortedArray()
{
	vector<int> A = { 3,7,4,9,12,6,1,11,2,10 };
	vector<int> MissingElement;

	//finding the minimun and maximum element in array
	int max =* max_element(A.begin(), A.end());
	int min = *min_element(A.begin(), A.end());
	//cout << max << endl;
	//cout << min << endl;

	int Hashsize = max + 1;
	vector<int> H(Hashsize);

	//updating the presence of element in hashtable
	for (int i = 0;i <A.size();i++)
		H[A[i]] = 1;

	//finding the missing element in the array with the help of hashtable
	for (int i = min;i <= max;i++)
	{
		if (H[i] == 0)
		{
			MissingElement.push_back(i);
		}
	}

	//Display the missing element
	cout << "Missing element in Array :";
	for (int x : MissingElement)
		cout << x << " ";
	cout << endl;

}


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
	//MultipleMissingElementGeneric();
	//MissingElementInUnsortedArray();
	//findDuplicateInSortedArray();
	//findDuplicateAndCountInSortedArray();
	//findMaxConsecutiveOnes();
	//findNumbers();
	//sortedSquares();
	//duplicateZeros();
	//duplicateZeros1();
	//merge();
	//removeElement();
	removeDuplicates();

	return 0;
}
