#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
class Node
{
public:
	T val;
	Node<T>* left;
	Node<T>* right;
	Node(const T& v, Node<T>* l = nullptr, Node<T>* r = nullptr) :
		val(v), left(l), right(r) {}
};
template<class T>
pair<vector<T>, int> layerTraverse(Node<T>* root)
{
	//层次遍历
	if (!root) return pair<vector<T>, int>();
	vector<T> res;
	Node<T>* queue[100]{ nullptr }; //队列
	int front = 0, back = 0;
	int originalBack = 0;
	queue[back++] = root;
	int countLeaf = 0;
	while (queue[front])
	{
		originalBack = back;
		Node<T>* temp = queue[front];
		res.emplace_back(temp->val);
		front++;
		if (temp->left)
			queue[back++] = temp->left;
		if (temp->right)
			queue[back++] = temp->right;
		if (queue[back] == queue[originalBack])
			countLeaf++;
	}
	return pair<vector<T>, int>{res, countLeaf};
}
Node<int>* create()
{
	auto no9 = new Node<int>(4);
	auto no8 = new Node<int>(6);
	auto no7 = new Node<int>(22);
	auto no6 = new Node<int>(17);
	auto no5 = new Node<int>(8,no9, no8);
	auto no4 = new Node<int>(5);
	auto no3 = new Node<int>(20, no6, no7);
	auto no2 = new Node<int>(7, no4, no5);
	auto no1 = new Node<int>(12, no2, no3);
	
	//auto no2 = new Node<int>(7);
	//auto no1 = new Node<int>(12,no2);  //稳定性测试

	//auto no2 = new Node<int>(7);
	//auto no1 = new Node<int>(12, nullptr,no2); //稳定性测试

	//
	//auto no1 = new Node<int>(12); //稳定性测试

	//auto no1 = nullptr; //返回值0，稳定性测试

	return no1;
}
template<class T>
void swapTree(Node<T>* root)
{
	if (!root) return;
	Node<T>* stack[100] = { nullptr };
	
	int cnt = 0;
	int cnt2 = 0;
	stack[cnt++] = root;
	while (stack[0])
	{
		root = stack[cnt - 1];
		if (!root)
		{
			stack[--cnt] = nullptr;
			swap(stack[cnt - 1]->left,stack[cnt-1]->right);
			stack[--cnt] = nullptr;
			continue;
		}
		stack[cnt++] = nullptr;
		if (root->right)
		{
			stack[cnt++] = root->right;
		}
		if (root->left)
		{
			stack[cnt++] = root->left;
		}
	}
	
}
int main()
{
	
	Node<int>* root = create();
	for(int& i : layerTraverse(root).first)
		cout << i << " ";
	cout << endl;
	//cout << layerTraverse(root).second;
	swapTree(root);
	for(int& i : layerTraverse(root).first)
		cout << i << " ";
	cout << endl;
}
//O(n)