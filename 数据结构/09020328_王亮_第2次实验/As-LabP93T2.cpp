//#include<iostream>
//#include<algorithm>
//using namespace std;
//class Lab2
//{
//public:
//	/*
//	* 不知道这所谓"ordered list"指的是什么
//	* 有可能是数组
//	* 亦有可能是链表
//	* 故使用模板, 并使用指针
//	* 不过要求重载小于 < 等于= 流插入<<运算符
//	* 一贯采用类封装了实验,所以最后输出返回值
//	* 于此函数下方提供测试用函数
//	*(方便起见使用int数组,假设每一位1 <= a[i] <= 9,尽管不符合此条件程序逻辑也成立)
//	*/
//	template<class T>
//	Lab2(T* a,int a_size,T* b,int b_size) 
//	{
//		for (int i = 0; i < a_size; i++)
//			cout << a[i] << " ";
//		cout << endl << endl;
//		for (int j = 0; j < b_size; j++)
//			cout << b[j] << " ";
//		cout << endl;
//		printf("本次返回值为: %d\n", Compare(a, a_size, b, b_size));
//	}
//	//记得使用srand((unsigned int)time(0));
//	//推荐使用while(1)配system("pause")进行测试
//
//  //比较不同长度
//	Lab2()
//	{
//		int a_size = rand() % 15 + 1,b_size = rand() % 15 + 1;
//		int* a = new int[a_size];
//		int* b = new int[b_size];
//		cout << "a:  ";
//		for (int i = 0; i < a_size; i++)
//			cout << (a[i] = i + 1) << " ";
//		cout << endl << endl;
//		cout << "b:  ";
//		for (int j = 0; j < b_size; j++)
//			cout << (b[j] = j + 1) << " ";
//		cout << endl;
//
//
//		printf("本次返回值为: %d\n", Compare(a,a_size, b,b_size));
//		delete[] a;
//		delete[] b;
//	}
//  //比较不同大小，不同长度
//	Lab2(int)
//	{
//		int a_size = rand() % 15 + 1, b_size = rand() % 15 + 1;
//		int* a = new int[a_size];
//		int* b = new int[b_size];
//		cout << "a:  ";
//		for (int i = 0; i < a_size; i++)
//			a[i] = rand() % 100 + 1;
//		sort(a, a + a_size);
//		for (int i = 0; i < a_size; i++)
//			cout << a[i] << " ";
//		cout << endl << endl;
//		cout << "b:  ";
//		for (int j = 0; j < b_size; j++)
//			b[j] = rand() % 100 + 1;
//		sort(b, b + b_size);
//		for (int j = 0; j < b_size; j++)
//			cout << b[j] << " ";
//		cout << endl;
//
//
//		printf("本次返回值为: %d\n", Compare(a, a_size, b, b_size));
//		delete[] a;
//		delete[] b;
//	}
//	template<class T>
//	int Compare(T* a,int a_size, T* b,int b_size)
//	{
//		if (a_size == 0 || b_size == 0) return -2; //error
//		for (int i = 0; i < min(a_size, b_size); i++)
//		{
//			if (a[i] > b[i]) return 1;
//			else if (a[i] < b[i]) return -1;
//			else continue;
//		}
//		if (a_size < b_size) return -1;
//		else if (a_size > b_size) return 1;
//		else return 0;
//	}
//};
//int main()
//{
//	srand(time(0));
//	while (1)
//	{
//		system("pause");
//		Lab2();
//		Lab2(0);
//	}
//}