//#include<iostream>
//#include<algorithm>
//using namespace std;
//class Lab2
//{
//public:
//	/*
//	* ��֪������ν"ordered list"ָ����ʲô
//	* �п���������
//	* ���п���������
//	* ��ʹ��ģ��, ��ʹ��ָ��
//	* ����Ҫ������С�� < ����= ������<<�����
//	* һ��������װ��ʵ��,��������������ֵ
//	* �ڴ˺����·��ṩ�����ú���
//	*(�������ʹ��int����,����ÿһλ1 <= a[i] <= 9,���ܲ����ϴ����������߼�Ҳ����)
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
//		printf("���η���ֵΪ: %d\n", Compare(a, a_size, b, b_size));
//	}
//	//�ǵ�ʹ��srand((unsigned int)time(0));
//	//�Ƽ�ʹ��while(1)��system("pause")���в���
//
//  //�Ƚϲ�ͬ����
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
//		printf("���η���ֵΪ: %d\n", Compare(a,a_size, b,b_size));
//		delete[] a;
//		delete[] b;
//	}
//  //�Ƚϲ�ͬ��С����ͬ����
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
//		printf("���η���ֵΪ: %d\n", Compare(a, a_size, b, b_size));
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