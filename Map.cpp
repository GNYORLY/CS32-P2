#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

Map::Map()
{}

/*
Map::Map(const Map& other)
{}

Map::~Map()
{}

Map& Map::operator=(const Map& rhs)
{}
*/

bool Map::empty() const
{
	Node* p = head;
	return (p == nullptr);
}

int Map::size() const
{
	int size = 0;
	for (Node* p = head; p != nullptr; p = p->m_next)
		size++;
	return size;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
	if (!contains(key))
	{
		Node* newguy = new Node;
		newguy->m_key = key;
		newguy->m_value = value;
		if (head == nullptr)
		{
			newguy->m_prev = head;
			newguy->m_next = tail;
			head = newguy;
			tail = newguy;
		}
		else
		{
			newguy->m_prev = tail;
			newguy->m_next = tail->m_next;
			tail->m_next = newguy;
			tail = newguy;
		}
		return true;
	}
	else
		return false;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
	if (contains(key))
	{
		Node* p;
		for (p = head; p->m_key != key; p = p->m_next);
		p->m_value = value;
		return true;
	}
	else
		return false;
}


bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
	if (!update(key, value))
		if (!insert(key, value))
			return false;
	return true;
}


bool Map::erase(const KeyType& key)
{
	if (contains(key))
	{
		Node* p;
		for (p = head; p->m_key != key; p = p->m_next);
		if (size() == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else if (p == head)
		{
			head = p->m_next;
			(p->m_next)->m_prev = p->m_prev;
		}
		else if (p == tail)
		{
			tail = p->m_prev;
			(p->m_prev)->m_next = p->m_next;
		}
		else
		{
			(p->m_prev)->m_next = p->m_next;
			(p->m_next)->m_prev = p->m_prev;
		}
		delete p;
		return true;
	}
	else
		return false;
}


bool Map::contains(const KeyType& key) const
{
	Node* p;
	for (p = head; p != nullptr && p->m_key != key; p = p->m_next);
	return (p != nullptr);
}

/*
bool Map::get(const KeyType& key, ValueType& value) const
{}

bool Map::get(int i, KeyType& key, ValueType& value) const
{}

void Map::swap(Map& other)
{}

//non-member function
bool combine(const Map& m1, const Map& m2, Map& result)
{}

void subtract(const Map& m1, const Map& m2, Map& result)
{}
*/

int main()
{
	Map cool;
	if (cool.empty())
		cout << "empty" << endl;
	cool.insertOrUpdate(500, 5);
	cool.insertOrUpdate(23543, 90);
	cool.insertOrUpdate(79979, 6464);
	cool.erase(500);
	if (cool.contains(79979))
		cout << "here" << endl;
	if (!cool.contains(500))
		cout << "not here" << endl;
	if (cool.size() == 2)
		cout << "size 2" << endl;
	cool.insertOrUpdate(23543, 6999);
	if (cool.size() == 2)
		cout << "size 2" << endl;
	cool.erase(23543);
	if (cool.size() == 1)
		cout << "size 1" << endl;
	cool.erase(79979);
	if (cool.size() == 0)
		cout << "size 0" << endl;
	if (cool.empty())
		cout << "empty" << endl;
}
