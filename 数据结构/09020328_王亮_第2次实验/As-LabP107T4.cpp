//#include<iostream>
//using namespace std;
//class Lab4
//{
//public:
//	class SparseMatrix
//	{
//	public:
//		class MatrixTerm
//		{
//		public:
//			int row, col, value;
//		};
//
//
//		MatrixTerm* smArray;
//		int rows, cols, terms, capacity;
//		SparseMatrix(int r = 6,int c = 6,int t = 8):rows(r),cols(c),terms(t)
//		{
//			capacity = terms;
//			smArray = new MatrixTerm[capacity];
//			smArray[0].row = 0, smArray[0].col = 0, smArray[0].value = 15;
//			smArray[1].row = 0, smArray[1].col = 3, smArray[1].value = 22;
//			smArray[2].row = 0, smArray[2].col = 5, smArray[2].value = -15;
//			smArray[3].row = 1, smArray[3].col = 1, smArray[3].value = 11;
//			smArray[4].row = 1, smArray[4].col = 2, smArray[4].value = 3;
//			smArray[5].row = 2, smArray[5].col = 3, smArray[5].value = -6;
//			smArray[6].row = 4, smArray[6].col = 0, smArray[6].value = 91;
//			smArray[7].row = 5, smArray[7].col = 2, smArray[7].value = 28;
//		}
//		void PrintMatrix()
//		{
//			for (int i = 0; i < terms; i++)
//				cout << smArray[i].row << "  " << smArray[i].col << "  " << smArray[i].value << endl;
//		}
//		SparseMatrix FastTranspose()
//		{
//			SparseMatrix b(cols, rows, terms);
//			if (terms > 0)
//			{
//				int* rowSize = new int[cols] {0};
//				for (int i = 0; i < terms; i++)
//					rowSize[smArray[i].col]++;
//				/*
//				*使用两个变量t,s解决rowStart问题:
//				*for以内三行为主要修改点:
//				*使用s记录此处rowSize[i]
//				*t将当前rowStart赋给此处rowSize数组
//				*计算下一次t
//				*/
//				int t = 0, s;
//				for (int i = 0; i < cols; i++)
//				{
//					s = rowSize[i];
//					rowSize[i] = t;
//					t = t + s;
//				}
//				for (int i = 0; i < terms; i++)
//				{
//					int j = rowSize[smArray[i].col];
//					b.smArray[j].row = smArray[i].col;
//					b.smArray[j].col = smArray[i].row;
//					b.smArray[j].value = smArray[i].value;
//					rowSize[smArray[i].col]++;
//				}
//				delete[] rowSize;
//			}
//			return b;
//		}
//	};
//	Lab4()
//	{
//		cout << "---------转置前： ---------" << endl;
//		SparseMatrix().PrintMatrix();
//		cout << endl;
//		cout << "---------转置后： ---------" << endl;
//		SparseMatrix().FastTranspose().PrintMatrix();
//	}
//	
//};
//int main()
//{
//	Lab4();
//}