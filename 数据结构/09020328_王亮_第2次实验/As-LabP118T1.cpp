#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class LabP118T1
{
	//建立以ascii一一映射的散列表
	//可使用正则101(regex 101)验证，可参考附件图表
public:
	LabP118T1(const string& test)
	{
		Process(test);
	}
	LabP118T1(const char* test, int size)
	{
		Process(test, size);
	}
private:
	void Process(const string& test)
	{
		int hash[128]{ 0 }; //HashTable
		for (int i = 0; i < test.size(); i++)
		{
			hash[test[i] - '\0']++;
		}

		for (int i = 0; i < 128; i++)
		{
			if (hash[i] != 0)
			{
				cout << (char)i << " with times : " << hash[i] << endl;
				file << (char)i << "," << hash[i] << endl;
			}
		}

	}
	void Process(const char* test, int size)
	{
		int hash[128]{ 0 }; //HashTable
		for (int i = 0; i < size; i++)
		{
			hash[test[i] - '\0']++;
		}
		for (int i = 0; i < 128; i++)
		{
			if (hash[i] != 0)
				cout << (char)i << " with times : " << hash[i] << endl;
		}
	}
};
int main()
{
	LabP118T1(string("The world puts off its mask of vastness to its lover. It becomes small as one song, as one kiss of the eternal."));
}