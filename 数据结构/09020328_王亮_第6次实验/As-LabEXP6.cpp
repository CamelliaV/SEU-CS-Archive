//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int id;
//	node* next;
//	node(int i, node* n = nullptr) :
//		id(i), next(n) {}
//};
//bool* visited = new bool[8]{ false };
//node** adjlist = new node * [8];
//void dfs(int v)
//{
//	if (visited[v]) return;
//	visited[v] = true;
//	cout << "·ÃÎÊ£º" << v << endl;
//	node* temp = adjlist[v];
//	while (temp)
//	{
//		if(!visited[temp->id])
//			dfs(temp->id);
//		temp = temp->next;
//	}
//}
//void bfs(int v)
//{
//	node* queue[1000]{nullptr};
//	int front = 0, end = 0;
//	queue[end++] = adjlist[0];
//	while (front != end)
//	{
//		node* head = queue[front];
//		front++;
//		visited[head->id] = true;
//		node* adjtraverse = adjlist[head->id];
//		while (adjtraverse)
//		{
//			if (!visited[adjtraverse->id])
//				queue[end++] = adjtraverse, visited[adjtraverse->id] = true;
//			adjtraverse = adjtraverse->next;
//		}
//	}
//	for (int i = 0;; i++)
//	{
//		if (!queue[i]) break;
//		cout << "·ÃÎÊ£º" << queue[i]->id << endl;
//	}
//}
//int main()
//{
//	
//	adjlist[0] = new node(1, new node(2));
//	adjlist[1] = new node(0, new node(3,new node(4)));
//	adjlist[2] = new node(0, new node(5,new node(6)));
//	adjlist[3] = new node(1, new node(7));
//	adjlist[4] = new node(1, new node(7));
//	adjlist[5] = new node(2, new node(7));
//	adjlist[6] = new node(2, new node(7));
//	adjlist[7] = new node(3, new node(4,new node(5, new node(6))));
//	node* adjtraverse;
//	for (int i = 0;i < 8;i++)
//	{
//		adjtraverse = adjlist[i];
//		while (adjtraverse)
//		{
//			cout << "id: " << adjtraverse->id << " ";
//			adjtraverse = adjtraverse->next;
//		}
//		cout << endl;
//	}
//	cout << endl << "----------DFS---------------" << endl;
//	
//	dfs(0);
//	for (int i = 0; i < 8; i++)
//		visited[i] = false;
//	cout << endl << "----------BFS---------------" << endl;
//	bfs(adjlist[0]->id); //1
//}