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
		Node* prev;

		Node() : data(T()), next(nullptr), prev(nullptr) {}
		~Node() { data = T(); }

		Node(const T data) : data(data), next(nullptr), prev(nullptr) {}
	};

	Node* m_head; // First element
	Node* m_tail; // Last element. Not nullptr
	int m_length;

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

	LinkedList() : m_head(nullptr), m_tail(nullptr), m_length(0) {}
	~LinkedList();
	LinkedList(const T data) : m_head(new Node(data)), m_tail(m_head), m_length(1) {}

	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(nullptr); }

	void PushBack(const T data);
	T PopBack();
	void RemoveAt(int idx);

	T GetData(int idx);
	void SetData(const T data, int idx);

	int GetLength() const { return m_length; }

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
	Node* node = m_head;

	while (node != nullptr) 
	{
		Node* next = node->next;
		delete node;
		node = next;
	}

	// Just to be safe
	m_head = nullptr;
	m_tail = nullptr;
}

template<typename T>
void LinkedList<T>::PushBack(const T data)
{
	if (m_head == nullptr) 
	{
		m_head = new Node(data);
		m_tail = m_head;
		m_length++;
		return; 
	}

	Node* newNode = m_tail;

	newNode->next = new Node(data);
	newNode->next->prev = newNode;

	m_tail = newNode->next;

	m_length++;
}

template<typename T>
T LinkedList<T>::PopBack()
{
	if (m_head == nullptr)
	{
		std::cout << "Could not pop data. List is empty" << std::endl; 
		return T();
	}
	
	Node* node = m_tail; 
	
	m_tail = node->prev;

	T data = node->data;

	node->prev->next = nullptr;
	delete node;

	m_length--;

	return data;
}

template<typename T>
void LinkedList<T>::RemoveAt(int idx)
{
	Node* node = m_head;

	// If removing head
	if (idx == 0)
	{
		m_head = node->next; // If there is only m_head next will be nullptr
		m_head->prev = nullptr;

		delete node;
		node = nullptr;

		return;
	}

	for (int i = 0; i < idx; i++)
	{
		// If there is no next node
		if (node->next == nullptr) 
		{
			std::cout << "Could not remove data. Index Out Of Range" << std::endl;
			return;
		}

		node = node->next;
	}

	// If removing tail
	if (node == m_tail)
	{
		m_tail = node->prev;
		node->prev->next = nullptr;
		delete node;
		node = nullptr;
		return;
	}

	// Trying to remove node
	Node* next = node->next; 
	Node* prev = node->prev;

	node->prev->next = next;
	node->next->prev = prev;

	delete node;

	m_length--;

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