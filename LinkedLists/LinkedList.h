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

		Node(const T data) : data(data), next(nullptr) {}
		~Node() {};
	};

	class Iterator
	{

	private:

		Node* m_node;

	public:

		Iterator(Node* node) : m_node(node) {}
		~Iterator() {}

		Iterator operator ++ ();
		T operator * ();
		bool operator != (Iterator other);
		bool operator == (Iterator other);

	};

	Node* m_head;

public:

	LinkedList(const T data) : m_head(new Node(data)) {}
	~LinkedList() {}

	Iterator Begin() { return Iterator(m_head); }
	Iterator End() { return Iterator(nullptr); }

	void PushBack(const T data);

	void RemoveAt(int idx);

	T GetData(int idx);

	void SetData(const T data, int idx);
};

#pragma region IteratorDef

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator ++ () { m_node = m_node.next; return m_node; }

template<typename T>
T LinkedList<T>::Iterator::operator * () { return m_node.data; }

template<typename T>
bool LinkedList<T>::Iterator::operator != (Iterator other) { return m_node != other.m_node; }

template<typename T>
bool LinkedList<T>::Iterator::operator == (Iterator other) { return m_node == other.m_node; }

#pragma endregion

#pragma region LinkedListDef
template<typename T>
void LinkedList<T>::PushBack(const T data)
{
	Node* newNode = m_head;

	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
	}

	newNode->next = new Node(data);
}

/**
idx - The index where the element you want to delete is stored. Not position!!!
*/
template<typename T>
void LinkedList<T>::RemoveAt(int idx)
{
	Node* prevNode = m_head;

	// If removing head
	if (idx == 0)
	{
		m_head = prevNode->next;

		delete prevNode;
		prevNode = nullptr;

		return;
	}

	int count = 0;

	for (; count < (idx - 1); count++)
	{

		if (prevNode->next == nullptr)
		{
			if (idx == count) // If removing last element
			{
				delete prevNode->next;
				prevNode->next = nullptr;
				return;
			}
			if (idx > count) // If idx is out of range of list
			{
				std::cout << "Index passed in is out of range of list" << std::endl;
				return;
			}
		}

		// If removing last element
		if (prevNode->next == nullptr && idx == count)
		{
			delete prevNode->next;
			prevNode->next = nullptr;
			return;
		}

		// If idx is out of range of list
		if (prevNode->next == nullptr && idx > count)
		{
			std::cout << "Index passed in is out of range of list" << std::endl;
			return;
		}

		prevNode = prevNode->next;

	}

	prevNode->next = prevNode->next->next;
}

template<typename T>
T LinkedList<T>::GetData(int idx)
{
	Node* node = m_head;

	for (int i = 0; i < idx; i++)
	{
		if (node->next == nullptr)
			exit;

		node = node->next;
	}

	return node->data;
}

/**
Set data in node stored at idx
*/
template<typename T>
void LinkedList<T>::SetData(const T data, int idx)
{
	Node* node = m_head;

	for (int i = 0; i < idx; i++)
	{
		if (node->next == nullptr)
			exit;

		node = node->next;
	}

	node->data = data;
}
#pragma endregion