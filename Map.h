//Map.h
#ifndef MAP_INCLUDED
#define MAP_INCLUDED

typedef int KeyType;
typedef int ValueType;

class Map
{
public:
	Map();
	/*Map(const Map& other);
	~Map();
	Map& operator=(const Map& rhs); */
	bool empty() const;
	int size() const; 
	bool insert(const KeyType& key, const ValueType& value);
	bool update(const KeyType& key, const ValueType& value); 
	bool insertOrUpdate(const KeyType& key, const ValueType& value);
	bool erase(const KeyType& key); 
	bool contains(const KeyType& key) const; /*
	bool get(const KeyType& key, ValueType& value) const;
	bool get(int i, KeyType& key, ValueType& value) const;
	void swap(Map& other); */
private:
	struct Node
	{
		KeyType m_key;
		ValueType m_value;
		Node* m_next;
		Node* m_prev;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
}; 

#endif //MAP_INCLUDED
