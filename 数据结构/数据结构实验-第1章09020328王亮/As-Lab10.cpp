#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
int BinarySearch(int* a, const int x, const int n,int& timesCount)
{
	timesCount = 0;
	int left = 0, right = n - 1;
	while (left <= right)
	{
		timesCount++;
		int middle = (left + right) / 2;
		if (x < a[middle]) right = middle - 1;
		else if (x > a[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}
int main()
{
	fstream tar;
	tar.open("rawData.txt", ios::out);


	int timesCount = 0;
	double sum = 0;
	int* Array = new int[101];
	for (int i = 0; i <= 100; i++) 
		Array[i] = i;
	for(int n = 0;n <= 100;n++)
	{
		time_t start = clock();
		for (int i = 0; i < 1000000; i++)
			BinarySearch(Array, -1, n,timesCount);
		time_t end = clock();
		cout << "---------Round[n = " << n << "]--------- \n";
		cout << "Takes: " << double(end - start)/CLOCKS_PER_SEC << endl;
		cout << "Times: " << timesCount << endl;
		sum += double(end - start) / CLOCKS_PER_SEC;
		tar << n << " " << double(end - start) / CLOCKS_PER_SEC << " " << timesCount << endl;
	}
	cout << "--------------------------------\n";
	cout << "--------------------------------\n";
	cout << "Average: " << sum / 101 << endl;
	delete[] Array;
	tar.close();
}