//#include<iostream>
//#include<cstddef>
//#include<algorithm>
//using namespace std;
//
//class Node
//{
//	
//public:
//	Node* rowLink;
//	Node* colLink;
//	int row;
//	int col;
//	int value;
//	Node(int v,int r,int c,Node* rowL = nullptr,Node* colL = nullptr):
//		value(v),row(r),col(c),rowLink(rowL),colLink(colL){}
//	Node(const Node&tar):Node(tar.value, tar.row, tar.col)
//	{
//		
//	}
//};
//class Matrix
//{
//	friend ostream& operator<<(ostream& cout, const Matrix& tar);
//	Node* head;
//	Node* dimension;
//public:
//	Matrix()
//	{
//		head = new Node(-1,-1,-1);
//		head->rowLink = head;
//		head->colLink = head;
//		dimension = new Node(0, -1, -1);
//	}
//	static Matrix* createTest()
//	{
//		auto test = new Matrix();
//		delete test->head;
//		test->head = new Node(INT_MAX,5,4);
//		delete test->dimension;
//		test->dimension = new Node(6,5, 4);
//		auto r5_c3 = new Node(6,4,2,test->head);
//		auto r4_c5 = new Node(1,3,3, r5_c3);
//		auto r3_c2 = new Node(8,3,0, r4_c5);
//		auto r2_c4 = new Node(3,1,3, r3_c2);
//		auto r1_c1 = new Node(4,1,0, r2_c4);
//		auto r0_c0 = new Node(2,0,0, r1_c1);
//		r0_c0->colLink = r1_c1;
//		r1_c1->colLink = r3_c2;
//		r3_c2->colLink = r5_c3;
//		r5_c3->colLink = r2_c4;
//		r2_c4->colLink = r4_c5;
//		r4_c5->colLink = test->head;
//		test->head->rowLink = r0_c0;
//		test->head->colLink = r0_c0;
//		return test;
//	}
//	static Matrix* createTest2()
//	{
//		auto test = new Matrix();
//		delete test->head;
//		test->head = new Node(INT_MAX, 5, 4);
//		delete test->dimension;
//		test->dimension = new Node(6, 4, 5);
//		auto r5_c3 = new Node(6, 3, 2, test->head);
//		auto r4_c5 = new Node(1, 3, 1, r5_c3);
//		auto r3_c2 = new Node(8, 3, 0, r4_c5);
//		auto r2_c4 = new Node(3, 1, 3, r3_c2);
//		auto r1_c1 = new Node(4, 1, 0, r2_c4);
//		auto r0_c0 = new Node(2, 0, 0, r1_c1);
//		r0_c0->colLink = r1_c1;
//		r1_c1->colLink = r3_c2;
//		r3_c2->colLink = r5_c3;
//		r5_c3->colLink = r2_c4;
//		r2_c4->colLink = r4_c5;
//		r4_c5->colLink = test->head;
//		test->head->rowLink = r0_c0;
//		test->head->colLink = r0_c0;
//		return test;
//	}
//	
//	void insert(Node* tar)
//	{
//		Node* rowFind = head->rowLink;
//		Node* colFind = head->colLink;
//		Node* last = head;
//		dimension->value++;
//		dimension->row = max(dimension->row,tar->row+1);
//		dimension->col = max(dimension->col,tar->col+1);
//		bool isAdd = false;
//		bool isEmpty = false;
//		if (head->rowLink == head)
//		{
//			head->rowLink = tar;
//			tar->rowLink = head;
//			isEmpty = true;
//		}
//		if (head->colLink == head)
//		{
//			head->colLink = tar;
//			tar->colLink = head;
//			isEmpty = true;
//		}
//		if (isEmpty) return;
//		while (1)
//		{
//			while(rowFind != head && rowFind->row < tar->row)
//				last = rowFind,rowFind = rowFind->rowLink;
//			while (rowFind != head && rowFind->row == tar->row && rowFind->col < tar->col)
//				last = rowFind, rowFind = rowFind->rowLink;
//			if (rowFind->row == tar->row && rowFind->col == tar->col)
//			{
//				rowFind->value += tar->value;
//				dimension->value--;
//				isAdd = true;
//				break;
//			}
//			last->rowLink = tar;
//			tar->rowLink = rowFind;
//			break;
//		}
//		while (1)
//		{
//			while (colFind != head && colFind->col < tar->col)
//				last = colFind, colFind = colFind->colLink;
//			while (colFind != head && colFind->col == tar->col && colFind->row < tar->row)
//				last = colFind, colFind = colFind->colLink;
//			if (colFind->row == tar->row && colFind->col == tar->col)
//			{
//				if (isAdd) break;
//				colFind->value += tar->value;
//				break;
//			}
//			last->colLink = tar;
//			tar->colLink = colFind;
//			break;
//		}
//	}
//	Matrix operator+(const Matrix& tar)
//	{
//		if (tar.dimension->row != this->dimension->row || this->dimension->col != tar.dimension->col)
//			throw runtime_error("Row or Col not matched!!!\n");
//		Matrix* res = new Matrix();
//		Node* rowTraverse = this->head->rowLink;
//		while (rowTraverse != this->head)
//		{
//			res->insert(new Node(*rowTraverse));
//			rowTraverse = rowTraverse->rowLink;
//		}
//		rowTraverse = tar.head->rowLink;
//		//Node* colTraverse = tar.head->colLink;
//		
//		while (rowTraverse != tar.head)
//		{
//			res->insert(new Node(*rowTraverse));
//			rowTraverse = rowTraverse->rowLink;
//		}
//		res->dimension = new Node(*(this->dimension));
//		return *res;
//	}
//	Node* get(int i, int j) const
//	{
//		Node* rowTraverse = this->head->rowLink;
//		while (rowTraverse != this->head && rowTraverse->row != i && rowTraverse->col != j)
//		{
//			rowTraverse = rowTraverse->rowLink;
//		}
//		if (rowTraverse->row == i && rowTraverse->col == j) return rowTraverse;
//		else return nullptr;
//	}
//	int getValue(int i, int j) const
//	{
//		Node* rowTraverse = this->head->rowLink;
//		while (rowTraverse != this->head && (rowTraverse->row != i || rowTraverse->col != j))
//		{
//			rowTraverse = rowTraverse->rowLink;
//		}
//		if (rowTraverse->row == i && rowTraverse->col == j) return rowTraverse->value;
//		else return 0;
//	}
//	Matrix operator*(const Matrix& tar)
//	{
//		if(this->dimension->col != tar.dimension->row) 
//			throw runtime_error("Matrix not matched!!!\n");
//		if (tar.head->rowLink == tar.head || tar.head->colLink == tar.head)
//		{
//			Matrix* res = new Matrix();
//			res->dimension = new Node(*(this->dimension));
//			res->dimension->col = tar.dimension->col;
//			res->head->rowLink = res->head;
//			res->head->colLink = res->head;
//			return *res;
//		}
//		int sum = 0;
//		Matrix* res = new Matrix();
//		for (int i = 0; i < dimension->row; i++)
//		{
//			for (int j = 0; j < tar.dimension->col; j++)
//			{
//				sum = 0;
//				for (int k = 0; k < this->dimension->row; k++)
//					sum += this->getValue(i, k) * tar.getValue(k, j);
//				if (sum)
//					res->insert(new Node(sum, i, j));
//			}
//		}
//		res->dimension->row = dimension->row;
//		res->dimension->col = tar.dimension->col;
//		return *res;
//	}
//
//};
//ostream& operator<<(ostream& cout,const Matrix& tar)
//{
//	Node* rowTravese = tar.head->rowLink;
//	//Node* colTravese = tar->head->colLink;
//	while (rowTravese != tar.head)
//	{
//		cout << "Row: " << rowTravese->row << " Col: " << rowTravese->col << " Value: " << rowTravese->value << endl;
//		rowTravese = rowTravese->rowLink;
//	}
//	
//	cout << "Terms: " << tar.dimension->value << " Rows: " << tar.dimension->row << " Cols: " << tar.dimension->col << endl;
//	return cout;
//}
//int main()
//{
//	Matrix* test = Matrix::createTest();
//	Matrix* testB = Matrix::createTest();
//	Node* A = new Node(/*val: */7,/*row: */ 0,/*col: */ 1);
//	Node* B = new Node(7, 1, 1);
//	Node* C = new Node(7, 1, 4);
//	Node* D = new Node(7, 5, 0);
//	Node* E = new Node(5, 3, 3);
//	testB->insert(A);
//	testB->insert(B);
//	testB->insert(C);
//	testB->insert(D);
//	testB->insert(E);
//	
//	cout << *test;
//	cout << "---------------------\n";
//	cout << *testB;
//	cout << "---------------------\n";
//	cout << *Matrix::createTest2();
//	cout << "---------------------\n";
//	try {
//		cout << *test + *Matrix::createTest2();
//		
//	}
//	catch (exception& e)
//	{
//		cout << e.what();
//	}
//	cout << "---------------------\n";
//	cout << *test + *test;
//	cout << "---------------------\n";
//	try {
//		cout << *test * *test;
//	}
//	catch (exception& e)
//	{
//		cout << e.what();
//	}
//	cout << "---------------------\n";
//	cout << *test * *Matrix::createTest2();
//	cout << "---------------------\n";
//}
//
