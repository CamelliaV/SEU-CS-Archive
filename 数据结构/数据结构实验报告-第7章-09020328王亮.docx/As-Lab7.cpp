#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdio>
#include<string>
#include<fstream>
#define SIZE 15
//#define _swap(a,b) int temp = a;a = b;b = temp;
template<class Ty>
inline void _swap(Ty& a, Ty& b)
{
	Ty temp = a;
	a = b;
	b = temp;
}

using namespace std;
template<class T>
class Sort 
{
private:
	static void adjust(T*arr,int root,int first,int last)
	{
		T e = arr[root+first-1];
		int i = 2 * root;
		for (; i <= last - first; i *= 2)
		{
			if (i < last - first && arr[i +first - 1] < arr[i+first-1 + 1]) i++;
			if (e >= arr[i +first-1]) break;
			arr[i / 2 +first-1] = arr[i+first-1];
		}
		arr[i / 2+first-1] = e;
	}

	static inline int __median(T* arr, int first, int mid, int last)
	{
		if (arr[first] < arr[mid])
			if (arr[mid] < arr[last])
				return mid;
			else if (arr[first] < arr[last])
				return last;
			else
				return first;
		else if (arr[first] < arr[last])
			return first;
		else if (arr[mid] < arr[last])
			return last;
		else return mid;
	}
	static int partition(T* arr, const T& pivot, int first, int last) {
		while (1)
		{
			/*cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (i == first) cout << "F*";
				if (i == last) cout << "L*";
				if (i == pivot) cout << "**";
				cout << arr[i] << " ";
			}*/
			while (arr[first] <= pivot) ++first;
			--last;
			while (pivot < arr[last]) --last; //only '<' required
			if (!(first < last)) return first;
			T temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
			//_swap(arr[first], arr[last]);
			++first;
		}
	}
	static int partition(T*arr,const T&pivot,int first,int last,int) {
		while (1)
		{
			/*cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (i == first) cout << "F*";
				if (i == last) cout << "L*";
				if (i == pivot) cout << "**";
				cout << arr[i] << " ";
			}*/
			while (arr[first] < pivot) ++first;
			--last;
			while (pivot < arr[last]) --last; //only '<' required
			if (!(first < last)) return first;
			T temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
			//_swap(arr[first], arr[last]);
			++first;
		}
	}
	
	static void merge(T* arr, T* res, int first, int last) {
		if (last - first <= 0) return;
		int mid = first + ((last - first) >> 1);
		merge(arr, res, first, mid);
		merge(arr, res, mid+1, last);
		int s1 = first, e1 = mid;
		int s2 = mid+1, e2 = last;
		int k = first;
		while (s1 <= e1 && s2 <= e2)
			res[k++] = arr[s1] < arr[s2] ? arr[s1++] : arr[s2++];
		while (s1 <= e1)
			res[k++] = arr[s1++];
		while (s2 <= e2)
			res[k++] = arr[s2++];
		for (k = first; k <= last; k++)
			arr[k] = res[k];
	}
public:
	//sort arr from first to last-1
	Sort() {
		/*testify(0,30);
		cout << endl;
		testify(7, 22,30);
		cout << endl;*/
		cout << "----------------正确性测试-----------------" << endl;
		testify(5, 22);
		cout << "----------------随机时间计算-----------------" << endl;
		countTimeAll();
		cout << "----------------最坏时间计算-----------------" << endl;
		countWorst();
	}
	static void insertSort(T* arr,int first,int last) {
		int start = first;
		for (;start != last; start++)
		{
			T temp = arr[start];
			int i = start - 1;
			/*for (; i >= first; i--)
			{
				if (temp < arr[i])
				{
					arr[i + 1] = arr[i];
				}
				else break;
			}*/
			while (i >= first && temp < arr[i])
				arr[i+1]=arr[i],i--;
			arr[i + 1] = temp;
		}
	}
	
	static void quickSort(T* arr,int first,int last,int) {
		while (last - first > 1)
		{
			 //= __median(arr, first, first + ((last - first) >> 1), last - 1);
			int pivot_index;
			int mid = first + ((last - first) >> 1);
			int end = last - 1;
			if (arr[first] < arr[mid])
				if (arr[mid] < arr[end])
					pivot_index= mid;
				else if (arr[first] < arr[end])
					pivot_index= end;
				else
					pivot_index= first;
			else if (arr[first] < arr[end])
				pivot_index= first;
			else if (arr[mid] < arr[end])
				pivot_index= end;
			else pivot_index= mid;


			T pivot = arr[pivot_index];
			int cut = partition(arr, pivot, first, last,0);
			
			quickSort(arr, cut, last,0);
			last = cut;
		}
	}
	static void quickSort(T* arr, int first, int last)
	{
		if (!(last - first > 1))return;
		//int pivot_index = __median(arr, first, first + ((last - first) >> 1), last - 1);
		int pivot_index = first;
		T pivot = arr[pivot_index];
		int cut = partition(arr, pivot, first, last);
		quickSort(arr, first, cut);
		quickSort(arr, cut, last);
	}
	static void mergeSortRecursive(T* arr, int first, int last) {
		auto res = new T[last - first];
		merge(arr, res, first, last-1);
		delete[] res;
	}
	static void mergeSort(T* arr, int first, int last) {
		T* arrS = new T[last];
		T* arrO = arr;
		for (int seg = 1; seg < last - first; seg += seg)
		{
			for (int start = first; start < last; start += seg + seg)
			{
				int left = start, mid = min(start + seg, last), right = min(start + seg + seg, last);
				int k = left;
				int s1 = left, e1 = mid;
				int s2 = mid, e2 = right;
				while (s1 < e1 && s2 < e2)
					arrS[k++] = arrO[s1] < arrO[s2] ? arrO[s1++] : arrO[s2++];
				while (s1 < e1)
					arrS[k++] = arrO[s1++];
				while (s2 < e2)
					arrS[k++] = arrO[s2++];
			}
			//swap(arrS, arrO);
			T* temp = arrS;
			arrS = arrO;
			arrO = temp;
		}
		if (arrO != arr)
		{
			for (int i = first; i != last; i++)
				arrS[i] = arrO[i];
			arrS = arrO;
		}
		delete[] arrS;
	}
	static void heapSort(T* arr,int first,int last) {
		int len = last - first;
		if (len < 2)
			return;
		for (int i = len / 2; i >= 1; i--)
		{
			adjust(arr,i,first,last);
		}
		for (int i = len - 1; i >= 1;i--)
		{
			//swap(arr[first], arr[i + first - 1 + 1]);
			T temp = arr[first];
			arr[first] = arr[i + first - 1 + 1];
			arr[i + first - 1 + 1] = temp;
			adjust(arr, 1, first,first + i);
		}
	
	}
	//nlogn
	static void heapInsert(T*arr,int first,int i)
	{
		int j = i;
		T tar = arr[i + first - 1];
		for(;j / 2;j /= 2)
		{
			if (arr[j / 2 + first - 1] < tar)
			{
				arr[j + first - 1] = arr[j / 2 + first - 1];
			}
			else break;
		}
		arr[j + first - 1] = tar;
		
	}
	static void heapSort_insert(T* arr, int first, int last) {
		int len = last - first;
		if (len < 2)
			return;
		for (int i = 1; i != len + 1; i++)
		{
			heapInsert(arr, first, i);
		} //O(nlogn)
		for (int i = len - 1; i >= 1; i--)
		{
			//swap(arr[first], arr[i + first - 1 + 1]);
			T temp = arr[first];
			arr[first] = arr[i + first - 1 + 1];
			arr[i + first - 1 + 1] = temp;
			adjust(arr, 1, first, first + i);
		} //O(nlogn)
	}
	static void copyBack(T* arrO,T*arrS,int first,int last)
	{
		for (; first != last; ++first)
		{
			arrO[first] = arrS[first];
		}
	}
	static void printOut(T* arr, int first, int last)
	{
		for (; first != last; ++first)
		{
			cout << arr[first] << " ";
		}
		cout << endl;
	}
	void printOut(T* arr, int first, int last,int size)
	{
		for (int i = 0;i < first;i++)
		{
			cout << arr[i] << " ";
		}
		cout << "First-> ";
		for (; first != last; ++first)
		{
			cout << arr[first] << " ";
		}
		cout << "<-Last ";
		for (;last != size; last++)
			cout << arr[last] << " ";
		cout << endl;
	}
	static bool isEqual(T* arrO, T* arrR, int first, int last)
	{
		for (; first != last; ++first)
		{
			if (arrO[first] != arrR[first]) return false;
		}
		return true;
	}
	void testify(int first,int last)
	{
		int size = last - first;
		T* arrO = new T[last]; //Opeartion
		T* arrR = new T[last]; //Reference
		T* arrS = new T[last]; //Support
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };
		cout << boolalpha;
		printf("********************Testify Sorting For [ %d , %d ) *********************", first, last);
		cout << endl;
		cout << "--------------------Original Array---------------------" << endl;
		cout << "Sequence: ";
		for (int i = 0; i < last; i++)
		{
			arrR[i] = arrS[i] = arrO[i] = rand() % 175 + 1;
			cout << arrO[i] << " ";
		}
		cout << endl;


		cout << "--------------------After STL Sort---------------------" << endl;
		cout << "Reference sorting" << endl; //对齐
		sort(arrR + first, arrR + last);
		cout << "Sequence: ";
		printOut(arrR, first, last);
		//copyBack(arrO, arrS, first,last);

		cout << "--------------------After QuickSort---------------------" << endl;
		quickSort(arrO, first, last,0);
		printf("Did %-10s function well? -> ", names[0].c_str());
		cout <<( isEqual(arrO, arrR, first, last) ? true : false )<< endl;
		cout << "Sequence: ";
		printOut(arrO,first,last);
		copyBack(arrO, arrS, first,last);

		cout << "--------------------After MergeSort---------------------" << endl;
		mergeSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[1].c_str());
		cout <<( isEqual(arrO, arrR, first, last) ? true : false )<< endl;
		cout << "Sequence: ";
		printOut(arrO,first,last);
		copyBack(arrO, arrS, first,last);

		cout << "--------------------After InsertSort---------------------" << endl;
		insertSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[2].c_str());
		cout <<( isEqual(arrO, arrR, first, last) ? true : false )<< endl;
		cout << "Sequence: ";
		printOut(arrO,first,last);
		copyBack(arrO, arrS, first,last);

		cout << "--------------------After HeapSort---------------------" << endl;
		heapSort(arrO,first,last);
		printf("Did %-10s function well? -> ", names[3].c_str());
		cout <<( isEqual(arrO, arrR, first, last) ? true : false )<< endl;
		cout << "Sequence: ";
		printOut(arrO,first,last);
		copyBack(arrO, arrS, first,last);

		cout << "---------------------END------------------" << endl;
		delete[] arrO, arrS, arrR;
	}
	static clock_t countTime(int index,int size,T*arrO,T*arrR,T*arrS)
	{
		clock_t start,end;
		if (index == 0)
		{
			start = clock();
			quickSort(arrO, 0, size, 0);
			end = clock();
		}
			
		else if (index == 1)
		{
			start = clock();
			mergeSort(arrO, 0, size);
			end = clock();
		}
			
		else if (index == 2)
		{
			start = clock();
			insertSort(arrO, 0, size);
			end = clock();
		}
		else
		{
			start = clock();
			heapSort(arrO, 0, size);
			end = clock();
		}
			
		
		if (!(isEqual(arrO, arrR, 0, size)))
		{
			copyBack(arrO, arrS,0,size);
			return -1;
		}
		copyBack(arrO, arrS, 0, size);
		return end - start;
	}
	static void finalSort(int size, T* arrO)
	{
		clock_t start, end;
		if (size < 16)
		{
			insertSort(arrO, 0, size);
		
		}

		else if (size < 1289)
		{
			quickSort(arrO, 0, size, 0);
		}

		else 
		{
			mergeSort(arrO, 0, size);
		}
		/*else
		{
			
			heapSort(arrO, 0, size);
			
		}*/
	}
	static void finalSortWorst(int size, T* arrO)
	{
		clock_t start, end;
		mergeSort(arrO, 0, size);
	}
	static clock_t worstTime(int index, int size, int* arr)
	{
		clock_t start, end;
		int* arrR = new int[size];
		int* arrS = new int[size];
		for (int i = 0; i != size; i++)
		{
			arrS[i] = arrR[i] = arr[i];
		}
		if (index == 0)
		{
			start = clock();
			quickSort(arr, 0, size);
			end = clock();
			//return 0;
		}
		
		else if (index == 1)
		{
			start = clock();
			mergeSort(arr, 0, size);
			end = clock();
		}

		else if (index == 2)
		{
			start = clock();
			insertSort(arr, 0, size);
			end = clock();
		}
		else
		{
			start = clock();
			heapSort_insert(arr, 0, size);
			end = clock();
		}
		sort(arrR + 0, arrR + size);
		if (!(isEqual(arr, arrR, 0, size)))
		{
			copyBack(arr, arrS, 0, 0 + size);
			delete[] arrR, arrS;
			return -INT_MAX;
		}
		copyBack(arr, arrS, 0, 0 + size);
		delete[] arrR,arrS;
		return end - start;
	}
	void Quick_Sort(T* arr, int begin, int end) {
		if (begin > end)
			return;
		int tmp = arr[begin];
		int i = begin;
		int j = end;
		while (i != j) {
			while (arr[j] >= tmp && j > i)
				j--;
			while (arr[i] <= tmp && j > i)
				i++;
			if (j > i) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
		arr[begin] = arr[i];
		arr[i] = tmp;
		Quick_Sort(arr, begin, i - 1);
		Quick_Sort(arr, i + 1, end);
	}
	static int binaryReverse(int v)
	{
		int s = 4 * 8;
		int mask = ~0;
		while ((s >>= 1) > 0)
		{
			mask ^= (mask << s);
			v = ((v >> s) & mask) | ((v << s) & ~mask);
		}
		return v;
	}
	static int* generate(int index,int size)
	{
		if (index == 0) //quickSort
		{
			int* res = new int[size];
			for (int i = 0; i != size; i++)
			{
				//res[i] = size;

				res[i] = i+1;
			}
			return res;
		}
		else if (index == 1) //mergeSort
		{
			int* res = new int[size];
			for (int i = 1; i != size+1; i++)
			{
				res[i - 1] = /*binaryReverse(i);*/ rand() % 10000000000 + 1;
			}
			return res;
		}
		else if (index == 2) //insertSort
		{
			int* res = new int[size];
			for (int i = 0; i != size; i++)
			{
				res[i] = size - i;
			}
			return res;
		}
		else //heapSort
		{
			int* res = new int[size];
			for (int i = 0; i != size; i++)
			{
				res[i] = i + 1;
			}
			return res;
		}
	}
	static void countWorst()
	{
		int sizes[6] = { 500,1000,2000,3000,4000,5000 };
		int* testArrs[4][6];
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };
		for(int i = 0;i != 4;i++)
			for (int j = 0; j != 6; j++)
			{
				testArrs[i][j] = generate(i, sizes[j]);
			}
		fstream tar("countWorst.csv", ios::out);
		double timeSet[4][6]{ 0 };
		int cntName = 0;
		int cntSize = 0;

		for (cntName = 0; cntName != 4; cntName++)
		{
			printf("********************Worst time of %s *********************\n", names[cntName].c_str());
			for (cntSize = 0; cntSize != 6; cntSize++)
			{
				
				for (int i = 1; i <= 1000; i++)
					timeSet[cntName][cntSize] += (worstTime(cntName, sizes[cntSize],testArrs[cntName][cntSize]));
				timeSet[cntName][cntSize] /= 1000;
				tar << sizes[cntSize] << "," << timeSet[cntName][cntSize] << endl;
				printf("------------- %s with size %d takes: %lf--------------\n", names[cntName].c_str(), sizes[cntSize], timeSet[cntName][cntSize]);
			}
		}

		for (int i = 0; i != 4; i++)
			for (int j = 0; j != 6; j++)
			{
				delete[] testArrs[i][j];
			}
	}
	static void countTimeAll()
	{
		int sizes[6] = { 500,1000,2000,3000,4000,5000 };
		T* arrO = new T[sizes[5]]; //Opeartion
		T* arrR = new T[sizes[5]]; //Reference
		T* arrS = new T[sizes[5]]; //Support
		double* timeSet = new double[6]{0};
		int cntName = 0;
		int cntSize = 0;
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort"};

		for (int i = 0; i < sizes[5]; i++)
		{
			arrR[i] = arrS[i] = arrO[i] = rand() % 1000000000 + 1;
		}
		random_shuffle(arrO + 0, arrO + sizes[5]);
		for (int i = 0; i < sizes[5]; i++)
		{
			arrR[i] = arrS[i] = arrO[i];
		}
		cout << endl;
		
		fstream tar("countTime.csv", ios::out);
		for (cntName = 0; cntName != 4;cntName++)
		{
			printf("********************Count time of %s *********************\n", names[cntName].c_str());
			for (cntSize = 0; cntSize != 6; cntSize++)
			{
				sort(arrR + 0, arrR + sizes[cntSize]);
				for(int i = 1;i <= 1000;i++)
					timeSet[cntSize] += (countTime(cntName, sizes[cntSize],arrO,arrR,arrS));
				timeSet[cntSize] /= 1000;
				tar << sizes[cntSize] << "," << timeSet[cntSize] << endl;
				copyBack(arrR, arrS, 0, sizes[cntSize]);
				printf("------------- %s with size %d takes: %lf--------------\n",names[cntName].c_str(),sizes[cntSize],timeSet[cntSize]);
				timeSet[cntSize] = 0;
			}
		}
		
		cout << "---------------------END------------------" << endl;

	}
	static void functionMaker()
	{
		int size = 5000;
		int sizes[5000];
		for (int i = 0; i != 5000; i++)
			sizes[i] = i + 1;
		T* arrO = new T[size]; //Opeartion
		T* arrR = new T[size]; //Reference
		T* arrS = new T[size]; //Support
		double* timeSet = new double[size]{ 0 };
		int cntName = 0;
		
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };

		for (int i = 0; i < size; i++)
		{
			arrR[i] = arrS[i] = arrO[i] = rand() % 1000000000 + 1;
		}
		random_shuffle(arrO + 0, arrO + size);
		for (int i = 0; i < size; i++)
		{
			arrR[i] = arrS[i] = arrO[i];
		}
		cout << endl;

		fstream tar("countTimeGood.csv", ios::out);
		int cntSize = 1;
		for (cntName = 0; cntName != 4; cntName++)
		{
			//printf("********************Count time of %s *********************\n", names[cntName].c_str());
			for (cntSize = 1; cntSize <= 5000; cntSize++)
			{
				sort(arrR + 0, arrR + cntSize);
				for (int i = 1; i <= 1000; i++)
					timeSet[cntSize - 1] += (countTime(cntName, cntSize, arrO, arrR, arrS));
				timeSet[cntSize - 1] /= 1000;
				tar << cntSize << "," << timeSet[cntSize - 1] << endl;
				copyBack(arrR, arrS, 0, cntSize);
				//printf("------------- %s with size %d takes: %lf--------------\n", names[cntName].c_str(), size, timeSet[cntSize]);
				timeSet[cntSize - 1] = 0;
			}
				
		}
		cout << "---------------------END------------------" << endl;

	}
	static void functionMakerWorst()
	{
		int size = 5000;
		int sizes[5000];
		for (int i = 0; i != 5000; i++)
			sizes[i] = i + 1;
		int* testArrs[4][5000];
		for (int i = 0; i != 4; i++)
			for (int j = 0; j != 5000; j++)
			{
				testArrs[i][j] = generate(i, sizes[j]);
			}
		double* timeSet = new double[size] { 0 };
		int cntName = 0;
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };

		fstream tar("countTimeWorstAll.csv", ios::out);
		int cntSize = 1;
		for (cntName = 0; cntName != 4; cntName++)
		{
			for (cntSize = 1; cntSize <= 5000; cntSize++)
			{
				for (int i = 1; i <= 100; i++)
					timeSet[cntSize - 1] += (worstTime(cntName, cntSize, testArrs[cntName][cntSize-1]));
				timeSet[cntSize - 1] /= 100;
				tar << cntSize << "," << timeSet[cntSize - 1] << endl;
				timeSet[cntSize - 1] = 0;
			}

		}
		cout << "---------------------END------------------" << endl;

		for (int i = 0; i != 4; i++)
			for (int j = 0; j != 5000; j++)
			{
				delete[] testArrs[i][j];
			}
	}
	static void countEX()
	{
		int size = 1000000;
		
		T* arrO = new T[size]; //Opeartion
		T* arrR = new T[size]; //Reference
		T* arrS = new T[size]; //Support
		double timeSet[3]{0};
		int cntName = 0;
		int cntSize = 0;
		int cnt = 0;
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };

		for (int i = 0; i < size; i++)
		{
			arrR[i] = arrS[i] = arrO[i] = rand() % 1000000000 + 1;
		}
		random_shuffle(arrO + 0, arrO + size);
		for (int i = 0; i < size; i++)
		{
			arrR[i] = arrS[i] = arrO[i];
		}
		cout << endl;
		for (cntName = 0; cntName != 4; cntName++)
		{
			if (cntName == 2) continue;
			 
			printf("********************Count time of %s *********************\n", names[cntName].c_str());
			sort(arrR + 0, arrR + size);
			for (int i = 0; i != 100; i++)
				timeSet[cnt] += (countTime(cntName, size, arrO, arrR, arrS));
			timeSet[cnt] /= 100;
			copyBack(arrR, arrS, 0, size);
			printf("------------- %s with size %d takes: %lf--------------\n", names[cntName].c_str(), size, timeSet[cnt]);
			timeSet[cnt] = 0;
			cnt++;
			
		}
	}
	void testify(int first, int last,int size)
	{
		T* arrO = new T[size]; //Opeartion
		T* arrR = new T[size]; //Reference
		T* arrS = new T[size]; //Support
		string names[4] = { "quickSort","mergeSort","insertSort","heapSort" };
		cout << boolalpha;
		printf("********************Testify Sorting For [ %d , %d ) *********************", first,last);
		cout << endl;
		cout << "--------------------Original Array---------------------" << endl;
		cout << "Sequence: ";
		for (int i = 0; i < size; i++)
		{
			arrR[i] = arrS[i] = arrO[i] = rand() % 175 + 1;
		}
		printOut(arrR, first, last, size);
		cout << endl;


		cout << "--------------------After STL Sort---------------------" << endl;
		cout << "Reference sorting" << endl; //对齐
		sort(arrR + first, arrR + last);
		cout << "Sequence: ";
		printOut(arrR, first, last, size);
		//copyBack(arrO, arrS, first,last);

		cout << "--------------------After QuickSort---------------------" << endl;
		quickSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[0].c_str());
		cout << (isEqual(arrO, arrR, first, last) ? true : false) << endl;
		cout << "Sequence: ";
		printOut(arrO, first, last, size);
		copyBack(arrO, arrS, 0, size);

		cout << "--------------------After MergeSort---------------------" << endl;
		mergeSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[1].c_str());
		cout << (isEqual(arrO, arrR, first, last) ? true : false) << endl;
		cout << "Sequence: ";
		printOut(arrO, first, last, size);
		copyBack(arrO, arrS, 0, size);

		cout << "--------------------After InsertSort---------------------" << endl;
		insertSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[2].c_str());
		cout << (isEqual(arrO, arrR, first, last) ? true : false) << endl;
		cout << "Sequence: ";
		printOut(arrO, first, last, size);
		copyBack(arrO, arrS, 0, size);

		cout << "--------------------After HeapSort---------------------" << endl;
		heapSort(arrO, first, last);
		printf("Did %-10s function well? -> ", names[3].c_str());
		cout << (isEqual(arrO, arrR, first, last) ? true : false) << endl;
		cout << "Sequence: ";
		printOut(arrO, first, last, size);
		copyBack(arrO, arrS, 0, size);

		cout << "---------------------END------------------" << endl;
		delete[] arrO, arrS, arrR;
	}
};

int main()
{
	srand(time(0));
	Sort<int>::Sort();
	// 
	// 
	// 
	/*int size = 5000;
	int* test = Sort<int>::generate(3, size);
	int* test2 = Sort<int>::generate(3, size);
	sort(test2 + 0, test2 + size);
	Sort<int>::heapSort_insert(test, 0, 0 + size);
	cout << Sort<int>::isEqual(test, test2, 0, size) << endl;*/

	//Sort<int>::countWorst();
	
	////testify quickSort()
	//cout << "------------testify quickSort()---------------" << endl;
	//cout << "------------original array--------------------" << endl;
	//int* arr = new int[SIZE] {42, 60, 63, 31, 68, 46, 69, 54, 39, 8, 42, 59, 33, 22, 67};
	//for (int i = 0; i < SIZE; i++)
	//{
	//	//arr[i] = rand() % 70 + 1; //1-70 range
	//	cout << arr[i] << " ";
	//}
	//cout << endl;
	//cout << "------------current array---------------------" << endl;
	///*Sort<int>::quickSort(arr, 0, 0+SIZE);*/
	///*Sort<int>::heapSort(arr, 0, 0 + SIZE);*/
	//Sort<int>::mergeSort(arr, 0, 0 + SIZE);
	///*Sort<int>::insertSort(arr, 0, 0 + SIZE);*/
	//for (int i = 0; i < SIZE; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	
}