#include "Map.h"
#include <iostream>
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

bool Map::get(const KeyType& key, ValueType& value) const
{
	if (contains(key))
	{
		Node* p;
		for (p = head; p->m_key != key; p = p->m_next);
		value = p->m_value;
		return true;
	}
	else
		return false;
}


bool Map::get(int i, KeyType& key, ValueType& value) const
{
	if (i > 0 && i <= size())
	{
		int k;
		Node* p;
		for (p = head, k = 1; k != i; p = p->m_next, k++);
		key = p->m_key;
		value = p->m_value;
		return true;
	}
	else
		return false;
}

/*
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
	double x;
	Map cool;
	if (cool.empty())
		cout << "empty" << endl;
	cool.insertOrUpdate("tree", 5);
	cool.insertOrUpdate("phylogeny", 90);
	cool.insertOrUpdate("cream cheese", 6464);
	if (cool.size() == 3)
		cout << "size 3" << endl;
	cool.erase("tree");
	if (cool.contains("cream cheese"))
		cout << "here" << endl;
	if (!cool.contains("tree"))
		cout << "not here" << endl;
	cool.get("phylogeny", x);
	cout << x << endl;
	if (cool.size() == 2)
		cout << "size 2" << endl;
	cool.insertOrUpdate("phylogeny", 6999);
	cool.get("phylogeny", x);
	cout << x << endl;
	if (cool.size() == 2)
		cout << "size 2" << endl;
	cool.erase("phylogeny");
	if (cool.size() == 1)
		cout << "size 1" << endl;
	cool.erase("cream cheese");
	if (cool.size() == 0)
		cout << "size 0" << endl;
	if (cool.empty())
		cout << "empty" << endl;
}
