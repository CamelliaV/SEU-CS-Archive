//#include<iostream>
//#include<vector>
//
//using namespace std;
//template<class T>
//class Node
//{
//public:
//	T val;
//	Node<T>* left;
//	Node<T>* right;
//	Node(const T& v,Node<T>* l = nullptr,Node<T>* r = nullptr):
//		val(v),left(l),right(r){}
//};
//template<class T>
//pair<vector<T>, int> layerTraverse(Node<T>* root)
//{
//	//层次遍历
//	if (!root) return pair<vector<T>, int>();
//	vector<T> res;
//	Node<T>* queue[100]{ nullptr }; //队列
//	int front = 0, back = 0;
//	int originalBack = 0;
//	queue[back++] = root;
//	int countLeaf = 0;
//	while (queue[front])
//	{
//		originalBack = back;
//		Node<T>* temp = queue[front];
//		res.emplace_back(temp->val);
//		front++;
//		if (temp->left)
//			queue[back++] = temp->left;
//		if (temp->right)
//			queue[back++] = temp->right;
//		if (queue[back] == queue[originalBack])
//			countLeaf++;
//	}
//	return pair<vector<T>, int>{res, countLeaf};
//}	
//Node<char>* create()
//{
//	/*auto no7 = new Node<char>(22);
//	auto no6 = new Node<char>(17);
//	auto no5 = new Node<char>(8);
//	auto no4 = new Node<char>(5);
//	auto no3 = new Node<char>(20, no6, no7);
//	auto no2 = new Node<char>(7, no4, no5);
//	auto no1 = new Node<char>(12, no2, no3);*/
//
//	auto no7 = new Node<char>('g');
//	auto no6 = new Node<char>('f');
//	auto no5 = new Node<char>('e');
//	auto no4 = new Node<char>('d');
//	auto no3 = new Node<char>('c', no6, no7);
//	auto no2 = new Node<char>('b', no4, no5);
//	auto no1 = new Node<char>('a', no2, no3);
//	return no1;
//}
//int main() 
//{
//	pair<vector<char>,int> res = layerTraverse<char>(create());
//	for(char &i : res.first)
//		cout << i << " ";
//	cout << res.second << endl;
//}
////O(n)