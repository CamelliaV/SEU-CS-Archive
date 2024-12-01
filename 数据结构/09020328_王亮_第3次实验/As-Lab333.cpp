#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
int outForFly = 0;
int outForLand = 0;
int sumFly = 0;
int sumWait = 0;
int sumLeft = 0;
int emergencySum = 0;
class Plane
{
	int id = -1;
	int time = 0;
	int cnt = 0;
	bool isLand = false;
public:
	Plane() {}
	void setId(int id)
	{
		this->id = id;
	}
	int getId() const
	{
		return this->id;
	}
	void setTime(int time)
	{
		this->time = time;
	}
	int getTime() const
	{
		return this->time;
	}
	void setCnt(int cnt)
	{
		this->cnt = cnt;
	}
	int getCnt() const
	{
		return this->cnt;
	}
	void land()
	{
		isLand = true;
	}
	int getState() const
	{
		return this->isLand;
	}
	void tick()
	{
		time--;
		cnt++;
	}
};
class Queue
{
	Plane* data = new Plane[20];
	int capacity = 20;
	int front = 0;
	int end = 0;
public:

	Queue()
	{

	}
	int size()
	{
		return end - front;
	}
	Queue(int capacity)
	{
		this->capacity = capacity;
		data = new Plane[capacity];
	}
	void queueExpand()
	{
		capacity *= 2;
		Plane* temp = new Plane[capacity];
		int cnt = 0;
		for (int i = front; i < end; i++)
		{
			if (data[i].getState()) continue;
			temp[cnt++] = data[i];
		}
		delete[] data;
		data = temp;
		front = 0;
		end = cnt;
	}
	void queueUpdate()
	{
		Plane* temp = new Plane[capacity];
		int cnt = 0;
		for (int i = front; i < end; i++)
		{
			if (data[i].getState()) continue;
			temp[cnt++] = data[i];
		}
		delete[] data;
		data = temp;
		front = 0;
		end = cnt;
	}
	void enqueue(Plane& target)
	{
		if (this->size() >= capacity)
			queueExpand();
		data[end++] = target;
	}

	void dequeue()
	{
		data[front].land();
		front++;
	}

	const Plane& first() const
	{
		return data[front];
	}

	bool isEmpty()
	{
		return !this->size();
	}

	void tick()
	{
		for (int i = front; i < end; i++)
			data[i].tick();
	}

	void printOut()
	{
		for (int i = front; i < end; i++)
			cout << "Plane[id:" << data[i].getId() << "]" << "with time: " << data[i].getTime() << endl;
		cout << endl;
	}

	int findLand()
	{
		int cnt = 0;
		for (int i = front; i < end; i++)
			if (!data[i].getTime())
			{
				data[i].land();
				sumWait += data[i].getCnt();
				outForLand++;
				cnt++;
				if (cnt > 1) emergencySum++;
			}
		queueUpdate();
		return cnt;
	}

	void countWaitSum()
	{
		for (int i = front; i < end; i++)
			if (!(data[i].getState()))
				sumLeft += data[i].getTime();
	}


	~Queue()
	{
		delete[] data;
	}
};
	

class Airport
{
public:
	int round = 0;
	
	int leftRunway = 3;
	
	int totalWait = 0;
	int emergency = 0;
	class Lane
	{
		Queue wait;
		Queue wait2;
		Queue takeoff;

	public:
		Queue& waitingDecideQueue()
		{
			if (wait.size() > wait2.size())
				return wait2;
			else return wait;
		}
		Queue& takeoffQueue()
		{
			return takeoff;
		}
		void action()
		{
			int maxSize = max(max(wait.size(), wait2.size()), takeoff.size());
			if (!maxSize) return;
			if (wait.size() == maxSize && wait.first().getTime() == 0)
			{
				sumWait += wait.first().getCnt();
				outForLand++;
				wait.dequeue();
				wait.queueUpdate();
			}
			else if (wait2.size() == maxSize && wait2.first().getTime() == 0)
			{
				sumWait += wait2.first().getCnt();
				outForLand++;
				wait2.dequeue();
				wait2.queueUpdate();
			}
			else
			{
				sumFly += (takeoff).first().getCnt();
				outForFly++;
				takeoff.dequeue();
				takeoff.queueUpdate();
			}
		}
		void printOut()
		{
			cout << "wait1:" << endl;
			wait.printOut();
			cout << "wait2:" << endl;
			wait2.printOut();
			cout << "TakeoffQueue: " << takeoff.size() << " planes are to set off" << endl;
		}
		int countRunwayUsed()
		{
			return wait.findLand() + wait2.findLand();
		}
		int waitNum()
		{
			return wait.size() + wait2.size();
		}
		void countWaitSum()
		{
			wait.countWaitSum();
			wait2.countWaitSum();
		}
		void timeEvent()
		{
			wait.tick();
			wait2.tick();
			takeoff.tick();
		}
	};
	Lane lane1;
	Lane lane2;
	Lane lane3;
	void enterWaiting(Plane& target)
	{
		Queue& waitQueue = waitingDecide();
		int k = waitQueue.size();
		target.setId(2 * k + 1);
		target.setTime(rand() % 4 + 1);
		waitQueue.enqueue(target);
	}
	Queue& waitingDecide()
	{
		Queue& first = lane1.waitingDecideQueue();
		Queue& second = lane2.waitingDecideQueue();
		return first.size() > second.size() ? second : first;
	}
	void enterTakeoff(Plane& target)
	{
		Queue& takeoffQueue = takeoffDecide();
		int k = takeoffQueue.size();
		target.setId(2 * k);
		target.setCnt(1);
		takeoffQueue.enqueue(target);
	}
	Queue& takeoffDecide()
	{
		Queue& candidate1 = lane1.takeoffQueue();
		Queue& candidate2 = lane2.takeoffQueue();
		Queue& candidate3 = lane3.takeoffQueue();
		int minSize = min(min(candidate1.size(), candidate2.size()), candidate3.size());
		if (candidate1.size() == minSize) return candidate1;
		else if (candidate2.size() == minSize) return candidate2;
		else return candidate3;
	}
	void EmergencyHandler()
	{
		int temp = emergency;
		if (emergencySum != emergency)
			emergency = emergencySum;
		temp = emergency - temp;
		while(temp--)
			leftRunway--;
	}
	void checkForPriority()
	{
		leftRunway -= (lane1.countRunwayUsed() + lane2.countRunwayUsed());
	}
	void eventLoop()
	{
		Plane set[100];
		int index = 0;
		while (1)
		{
			int seed = rand() % 3;
			leftRunway = 3;
			enterTakeoff(set[index++]);
			enterTakeoff(set[index++]);
			enterWaiting(set[index++]);
			lane1.countWaitSum();
			lane2.countWaitSum();
			checkForPriority();
			EmergencyHandler();
			printOut();
			if(leftRunway >= 1)
				lane1.action();
			if(leftRunway >= 2)
				lane2.action();
			if(leftRunway == 3)
				lane3.action();
			lane1.timeEvent();
			lane2.timeEvent();
			lane3.timeEvent();
			getchar();
		}

	}
	void printOut()
	{
		sumLeft = 0;
		lane1.countWaitSum();
		lane2.countWaitSum();
		cout << "------------------------------------------------------------------------------\n";
		cout << "Round[" << round++ << "]:" << endl;
		cout << "Runway1:" << endl;
		lane1.printOut();
		cout << "Runway2:" << endl;
		lane2.printOut();
		cout << "Runway3:" << endl;
		cout << "TakeoffQueue: " << lane3.takeoffQueue().size() << " planes are to set off" << endl;
		cout << "Average time to set off: " << ((outForFly == 0) ? 0 : (sumFly / outForFly)) << endl;
		cout << "Average time to land on: " << ((outForLand == 0) ? 0 : (sumWait / outForLand)) << endl;
		cout << "Average time left to land: " << ((lane1.waitNum() + lane2.waitNum() == 0) ? 0 : (sumLeft / (lane1.waitNum() + lane2.waitNum()))) << endl;
		cout << "Emergence count: " << this->emergency << endl;
		cout << "------------------------------------------------------------------------------\n";
	}

};
int main()
{
	srand(time(0));
	Airport().eventLoop();
	return 0;
}