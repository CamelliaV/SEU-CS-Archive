#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
template<class T>
class Iterator
{
public:
	vector<T*> data;
	int cnt = 0;
	Iterator(vector<T*> val) :data(val) {}
	bool hasNext()
	{
		return (!(cnt == data.size()));
	}
	T next()
	{
		return *(data[cnt++]);
	}
};
template<class T>
class BinaryTree
{
public:
	T* data;
	BinaryTree<T>* left;
	BinaryTree<T>* right;
	BinaryTree() :data(nullptr), left(nullptr), right(nullptr) {}
	bool isEmpty() { return !data; }
	BinaryTree(const BinaryTree& tar)
	{
		auto temp = copy(&tar);
		this->data = temp->data;
		this->left = temp->left;
		this->right = temp->right;
	}
	BinaryTree<T>* copy(const BinaryTree<T>* tar) const
	{
		if (!tar) return nullptr;
		auto res = new BinaryTree<T>;
		res->data = new T(*(tar->data));
		res->left = copy(tar->left);
		res->right = copy(tar->right);
		return res;
	}
	BinaryTree(BinaryTree<T>* bt1,const T& item, BinaryTree<T>* bt2) {
		data = new T(item);
		left = copy(bt1);
		right = copy(bt2);
	}
	BinaryTree(BinaryTree<T>* bt1, const T& item, BinaryTree<T>* bt2,int) {
		data = new T(item);
		left = bt1;
		right = bt2;
	}
	BinaryTree<T>LeftSubtree() { return copy(this->left); }
	BinaryTree<T>RightSubtree() { return copy(this->right); }
	T RootData() { return *data; }
	~BinaryTree(){
		deleteE(this);
	}
	void deleteE(BinaryTree<T>* tar)
	{
		if (!tar) return;
		deleteE(tar->left);
		deleteE(tar->right);
		delete tar;
	}
	vector<T*> PreOrderTraverse(){
		BinaryTree<T>* root = this;
		vector<T*> res;
		stack<BinaryTree<T>*> Stack;
		while (!Stack.empty() || root)
		{
			while (root)
			{
				Stack.push(root);
				res.push_back(root->data);
				root = root->left;
			}
			if (!Stack.empty())
			{
				root = Stack.top();
				Stack.pop();
				root = root->right;
			}
		}
		return res;
	}
	Iterator<T> PreOrderIterator() {
		return Iterator<T>(PreOrderTraverse());
	}
	Iterator<T> InOrderIterator() {
		return Iterator<T>(InOrderTraverse());
	}
	Iterator<T> PostOrderIterator() {
		return Iterator<T>(PostOrderTraverse());
	}
	Iterator<T> LevelOrderIterator() {
		return Iterator<T>(LevelOrderTraverse());
	}
	vector<T*> InOrderTraverse() {
		BinaryTree<T>* root = this;
		vector<T*> res;
		stack<BinaryTree<T>*> Stack;
		while (!Stack.empty() || root)
		{
			while (root)
			{
				Stack.push(root);
				
				root = root->left;
			}
			if (!Stack.empty())
			{
				root = Stack.top();
				res.push_back(root->data);
				Stack.pop();
				root = root->right;
			}
		}
		return res;
	}
	vector<T*> PostOrderTraverse() {
		vector<T*> res;
		stack<BinaryTree<T>*> Stack;
		BinaryTree<T>* root = this;
		Stack.push(root);
		while (!Stack.empty())
		{
			root = Stack.top();
			if (root == nullptr)
			{
				Stack.pop();
				res.push_back(Stack.top()->data);
				Stack.pop();
				continue;
			}
			Stack.push(nullptr);
			if (root->right)
			{
				Stack.push(root->right);
			}
			if (root->left)
			{
				Stack.push(root->left);
			}
		}
		return res;
	}
	vector<T*> LevelOrderTraverse() {
		queue<BinaryTree<T>*> Queue;
		vector<T*>res;
		BinaryTree<T>* root = this;
		Queue.push(root);
		while (!Queue.empty())
		{
			root = Queue.front();
			Queue.pop();
			res.push_back(root->data);
			if (root->left) Queue.push(root->left);
			if (root->right) Queue.push(root->right);
		}
		return res;
	}
};
int main()
{
	auto N8 = new BinaryTree<int>(nullptr,8,nullptr);
	auto N7 = new BinaryTree<int>(nullptr,7,nullptr);
	auto N6 = new BinaryTree<int>(nullptr,6,nullptr);
	auto N5 = new BinaryTree<int>(nullptr,5,nullptr);
	auto N4 = new BinaryTree<int>(N8,4,nullptr);
	auto N3 = new BinaryTree<int>(N6,3,N7);
	auto N2 = new BinaryTree<int>(N4,2,N5);
	auto N1 = new BinaryTree<int>(N2,1,N3);

	auto N0 = new BinaryTree<int>(new BinaryTree<int>(*N1), 0, nullptr);

	//N4->left = nullptr;
	cout << "----------删除8号节点后：----------" << endl;
	N1->left->left->left = nullptr;
	auto item2 = N0->LevelOrderIterator();
	auto item = N1->LevelOrderIterator();
	cout << "---------------------------------" << endl;
	cout << "----------原树：----------" << endl;
	while (item.hasNext())
	{
		cout << item.next() << " ";
	}
	cout << endl;
	cout << "----------调用拷贝的树：----------" << endl;
	while (item2.hasNext())
	{
		cout << item2.next() << " ";
	}
	cout << endl;
	cout << "----------迭代器遍历：----------" << endl;
	cout << "----------层次遍历：----------" << endl;
	auto itemL = N0->LevelOrderIterator();
	while (itemL.hasNext())
	{
		cout << itemL.next() << " ";
	}
	cout << endl;
	cout << "----------前序遍历：----------" << endl;
	auto itemP = N0->PreOrderIterator();
	while (itemP.hasNext())
	{
		cout << itemP.next() << " ";
	}
	cout << endl;
	cout << "----------中序遍历：----------" << endl;
	auto itemI = N0->InOrderIterator();
	while (itemI.hasNext())
	{
		cout << itemI.next() << " ";
	}
	cout << endl;
	cout << "----------后序遍历：----------" << endl;
	auto itemPo = N0->PostOrderIterator();
	while (itemPo.hasNext())
	{
		cout << itemPo.next() << " ";
	}
	cout << endl;
}