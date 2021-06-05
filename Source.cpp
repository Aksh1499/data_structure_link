using namespace std;

#include<iostream>

class Node
{
	int data;
	Node* next;

public:
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	void setData(int data)
	{
		this->data = data;
	}
	Node* getNext()
	{
		return this->next;
	}
	int getData()
	{
		return this->data;
	}
};//class Node ends here

class LinkedList
{
	Node* start;
public:

	LinkedList()
	{
		this->start = NULL;

	}//default constructor ends here

	void addAtEnd(int data)
	{
		Node* nn= new Node(data);

		if (nn == NULL)
		{
			cout << "\n Memory Alloaction ERROR";
			return;
		}
		if (this->start == NULL)
		{
			this->start = nn;
			return;
		}
		else
		{
			Node* ep = start;

			while (ep->getNext()!=NULL)
			{
				ep = ep->getNext();
			}
			ep->setNext(nn);

		}
	
	}//addAtEnd()

	void display()
	{
		cout << "\n";
		Node * ep;
		if (this->start == NULL)
		{
			cout << " Linkedlist is Empty";
		}
		else
		{
			ep = start;

			while (ep->getNext() != NULL)
			{
				cout << "\t " << ep->getData();
				ep = ep->getNext();
			}//loop ends here

			cout << "\t " << ep->getData();
		}

	}
	void addAtBegining(int data)
	{

		Node* nn = new Node(data);

		if (nn == NULL)
		{
			cout << "\n Memory Alloaction ERROR";
			return;
		}
		if (this->start == NULL)
		{
			this->start = nn;
			return;
		}
		else
		{
			nn->setNext(start);
			start = nn;

		}

	}

	void delBegining()
	{
		if (start == NULL)
		{
			cout << " Linkedlist is Empty";
		}
		else
		{
			Node* temp;
			temp = start;
			start = start->getNext();
			delete temp;
		}
	}

	void delFromEnd()
	{
		if (start == NULL)
		{
			cout << " Linkedlist is Empty";
			return;
		}
		if (start->getNext() == NULL)
		{
			delete start;
			start = NULL;
			return;
		}
		else
		{
			Node * pre = start;
			while (pre->getNext()->getNext() != NULL)
			{
				
				pre = pre->getNext();
			}//loop ends here

			Node* temp = pre->getNext();
			pre->setNext(NULL);
			delete temp;
		}
	}
};//LL class ends here

int main()
{
	LinkedList L1;


	L1.addAtEnd(10);
	L1.addAtEnd(20);
	L1.addAtEnd(30);
	L1.addAtEnd(40);

	L1.display();//10 20 30 40 

	L1.delFromEnd();
	L1.display();//10 20 30
	cout << "\n\n\n\n";
}
void main1()
{
	LinkedList L1;

	//L1.display();//Empty

	L1.addAtEnd(10);
	L1.addAtEnd(20);
	L1.addAtEnd(30);
	L1.addAtEnd(40);

	L1.display();//10 20 30 40 

	L1.addAtBegining(5);
	L1.display();//5 10 20 30 40

	cout << "\n";

	L1.delBegining();
	L1.display();// 10 20 30 40
	cout << "\n";

	L1.delBegining();
	L1.display();// 20 30 40
	cout << "\n";

	L1.delBegining();
	L1.display();// 30 40
	cout << "\n";

	L1.delBegining();
	L1.display();// 40
	cout << "\n";

	L1.delBegining();
	L1.display();// 40
	cout << "\n";
}//main ends here
