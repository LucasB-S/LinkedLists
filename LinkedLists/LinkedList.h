#pragma once

#include <string>
#include <iostream>


template<typename T>
class LinkedList
{
private:

	struct Node
	{
	public:
		T data;
		Node* next;

		Node() : data(T()), next(nullptr) {}
		~Node() {};

		Node(const T data) : data(data), next(nullptr) {}
	};

	Node* m_head;

public:

	class Iterator
	{

	private:

		Node* m_node;

	public:

		Iterator(Node* node) : m_node(node) {}
		~Iterator() {}

		T& operator* () const;
		Iterator& operator++ ();
		bool operator != (const Iterator& other) const;
		bool operator == (const Iterator& other) const;

	};

	LinkedList() : m_head(nullptr) {}
	~LinkedList();
	LinkedList(const T data) : m_head(new Node(data)) {}

	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(nullptr); }

	void PushBack(const T data);
	void RemoveAt(int idx);

	T GetData(int idx);
	void SetData(const T data, int idx);

	void PrintList();
};

#pragma region IteratorDef

template<typename T>
T& LinkedList<T>::Iterator::operator * () const { return m_node->data; }

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator ++ () { m_node = m_node->next; return *this; }

template<typename T>
bool LinkedList<T>::Iterator::operator != (const Iterator& other) const { return m_node != other.m_node; }

template<typename T>
bool LinkedList<T>::Iterator::operator == (const Iterator& other) const { return m_node == other.m_node; }

#pragma endregion

#pragma region LinkedListDef
template<typename T>
LinkedList<T>::~LinkedList() 
{
	Node* current = m_head;

	while (current != nullptr) 
	{
		Node* next = current->next;
		delete current;
		current = next;
	}

	m_head = nullptr; // Just to be safe
}

template<typename T>
void LinkedList<T>::PushBack(const T data)
{
	if (m_head == nullptr) 
	{
		m_head = new Node(data); 
		return; 
	}


	Node* newNode = m_head;

	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
	}

	newNode->next = new Node(data);
}

template<typename T>
void LinkedList<T>::RemoveAt(int idx)
{
	Node* node = m_head;

	// If removing head
	if (idx == 0)
	{
		m_head = node->next;

		delete node;
		node = nullptr;

		return;
	}

	for (int i = 0; i < (idx - 1); i++)
	{

		if (node->next == nullptr)
		{
			if (idx == i) // If removing last element
			{
				delete node->next;
				node->next = nullptr;
				return;
			}
			if (idx > i) // If idx is out of range of list
			{
				std::cout << "Could not remove data. Index Out Of Range" << std::endl;
				return;
			}
		}

		node = node->next;

	}

	node->next = node->next->next;
}

template<typename T>
T LinkedList<T>::GetData(int idx)
{
	Node* node = m_head;

	for (int i = 0; i < idx; i++)
	{
		if (node->next == nullptr)
		{
			std::cout << "Could not get data. Index Out Of Range" << std::endl;
			return T();
		}

		node = node->next;
	}

	return node->data;
}

template<typename T>
void LinkedList<T>::SetData(const T data, int idx)
{
	Node* node = m_head;

	for (int i = 0; i < idx; i++)
	{
		if (node->next == nullptr)
		{
			std::cout << "Could not set data. Index Out Of Range" << std::endl;
			return;
		}

		node = node->next;
	}

	node->data = data;
}

template<typename T>
void LinkedList<T>::PrintList()
{
	Node* node = m_head; 
	
	while (node != nullptr) 
	{ 
		std::cout << node->data << " ";
		node = node->next; 
	}

	std::cout << std::endl;
}

#pragma endregion