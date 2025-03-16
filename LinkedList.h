#pragma once


#include <iostream>
#include <exception>
using namespace std;

template <class T>
struct Node
{
	Node(T value)
	{
		this->value = value;
		Next = nullptr;
	}
	T value;
	Node<T>* Next = nullptr;
};

template <class T>
class LinkedList
{
	Node<T>* Head;
	int count;

public:
	LinkedList()
	{
		Head = nullptr;
		count = 0;
	}

	~LinkedList()
	{
		Node<T>* temp = Head;
		while (Head)
		{
			temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}

	void Add(T value)
	{
		Node<T>* newnode = new Node<T>(value);

		if (!Head)
		{
			Head = newnode;
			count++;
			return;
		}


		newnode->Next = Head;
		Head = newnode;
		count++;
	}

	int GetCount()
	{
		return count;
	}
	bool IsEmpty()
	{
		return count == 0;
	}

	void clear()
	{
		Node<T>* temp;

		while (Head)
		{
			temp = Head;
			Head = Head->Next;
			delete temp;
		}

	}


	void PrintAllNodes()
	{
		Node<T>* temp = Head;

		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->Next;
		}
	}

	bool Delete(int index)
	{
		if (index < 0 || index >= count || (!Head))
		{
			return false;
		}

		if (index == 0)
		{
			Node<T>* temp = Head;
			Head = Head->Next;
			count--;
			delete temp;
			return true;
		}

		int Counter = index - 1;

		Node<T>* temp = Head;

		while (temp && Counter)
		{
			temp = temp->Next;
			Counter--;
		}

		if (!temp)
		{
			return false;
		}

		Node<T>* t = temp->Next;

		temp->Next = temp->Next->Next;
		delete t;
		count--;
		return true;

	}
	bool RemoveFirst()
	{
		if (count > 0)
		{
			return Delete(0);
		}
		else
			return false;
	}
	bool RemoveLast()
	{
		if (count > 0)
		{
			return Delete(count - 1);
		}
		else
			return false;
	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > count)
		{
			return false;
		}

		Node<T>* newNode = new Node<T>(value);

		//insert at beginning
		if (index == 0)
		{
			newNode->Next = Head;
			Head = newNode;
			count++;
			return true;
		}


		Node<T>* current = Head;
		Node<T>* Prev = new Node<T>(0);

		int counter = 0;
		while (current && counter < index)
		{
			Prev = current;
			current = current->Next;
			counter++;
		}

		//insert at end
		if (index == count)
		{
			Prev->Next = newNode;
			count++;
			return true;
		}


		newNode->Next = current;
		Prev->Next = newNode;
		count++;
		return true;
	}
	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}
	bool InsertAtEnd(T Value)
	{
		return InsertAt(count, Value);
	}

	void Reverse()
	{
		if (count > 1)
		{
			Node<T>* Current = Head;
			Node<T>* Front = Head->Next;

			Node<T>* Temp = NULL;
			while (Front != NULL)
			{
				Temp = Front;
				Front = Front->Next;
				Temp->Next = Current;
				Current = Temp;
			}
			Head->Next = NULL;
			Head = Current;
		}

	}

	int Search(T value)
	{
		if (Head)
		{
			Node<T>* Temp = Head;
			int Counter = 0;
			while (Temp)
			{
				if (Temp->value == value)
				{
					return Counter;
				}
				Counter++;
				Temp = Temp->Next;
			}

		}
		return -1;
	}

	T GetValue(int index)
	{
		if (index < 0 || index >= count)
		{
			throw "Error, index out of range.";
		}

		Node<T>* Temp = Head;
		for (int i = 0;i < index;i++)
		{
			Temp = Temp->Next;
		}
		return Temp->value;
	}

	T* ConvertToArray()
	{
		if (count > 0)
		{
			T* array = new T[count];
			Node <T>* temp = Head;
			for (int i = 0;i < count;i++)
			{
				array[i] = temp->value;
				temp = temp->Next;
			}
			return array;
		}
		return nullptr;
	}

	bool Contains(T Value)
	{

		Node<T>* Temp = Head;
		while (Temp)
		{

			if (Temp->value == Value)
			{
				return true;
			}
			Temp = Temp->Next;
		}
		return false;
	}

};

