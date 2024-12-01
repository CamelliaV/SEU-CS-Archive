//#include<iostream>
//#include<cstddef>
//#include<utility>
//using namespace std;
//#define SIZE 6
//
//bool isJoin[SIZE];
//int lowCost[SIZE];
//
//
//pair<int*,int*> prim(int** matrix,const int v)
//{
//	int* MST = new int[SIZE]{INT_MAX};
//	int* ori = new int[SIZE];
//	int top = -1;
//	for (int i = 0; i < SIZE; i++)
//	{
//		isJoin[i] = false;
//		lowCost[i] = matrix[v][i];
//		ori[i] = v;
//	}
//	isJoin[v] = true;
//	lowCost[v] = INT_MAX;
//	MST[++top] = v;
//	for (int i = 0; i < SIZE - 1; i++)
//	{
//		int min = 0;
//		for (int j = 0; j < SIZE; j++)
//		{
//			if (!isJoin[j] && lowCost[min] > lowCost[j])
//				min = j;
//		}
//		if (!min) break;
//		isJoin[min] = true;
//		MST[++top] = min;
//		for (int j = 0; j < SIZE; j++)
//		{
//			if (!isJoin[j] && matrix[min][j] < lowCost[j])
//				lowCost[j] = matrix[min][j], ori[j] = min;
//		}
//	}
//	MST[++top] = INT_MAX;
//	return pair<int*,int*>(MST,ori);
//}
//void printMST(pair<int*,int*>tar)
//{
//	for (int i = 0; tar.first[i] != INT_MAX; i++)
//		cout << "节点：" << tar.first[i] << " 连接自：" << tar.second[tar.first[i]] << endl;
//	cout << endl;
//}
//int main()
//{
//	int** matrix = new int*[SIZE];
//	for (int i = 0; i < SIZE; i++)
//		matrix[i] = new int[SIZE];
//	for (int i = 0; i < SIZE; i++)
//		for (int j = 0; j < SIZE; j++)
//			matrix[i][j] = INT_MAX;
//	matrix[0][1] = 6;
//	matrix[0][2] = 5;
//	matrix[0][3] = 1;
//	matrix[1][3] = 5;
//	matrix[2][3] = 4;
//	matrix[1][4] = 3;
//	matrix[3][4] = 6;
//	matrix[4][5] = 6;
//	matrix[3][5] = 4;
//	matrix[2][5] = 2;
//	for (int i = 0; i < SIZE; i++)	
//	{	
//		for (int j = 0; j < SIZE; j++)
//		{
//			matrix[i][j] = min(matrix[i][j], matrix[j][i]);
//			if (matrix[i][j] == INT_MAX)
//				cout << 0 << " ";
//			else cout << (matrix[i][j]) << " ";
//		}
//		cout << endl;
//	}
//			
//	printMST(prim(matrix,0));
//}