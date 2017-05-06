#pragma once
#include "RedBlackTree.h"
template <class Key, class Value>
class Map : RedBlackTree<Key, Value>
{
	typedef RedBlackTree<Key, Value> base;
public:
	Map();
	~Map();
	void push(Key*key, Value*value) throw(DuplicateException);
	void remove(Key*key);
	Value*pull(Key*key);
	const Value*peek(Key*key);
	void print();
};

template <class Key, class Value>
Map<Key, Value>::Map():RedBlackTree<Key, Value>()
{
}

template <class Key, class Value>
Map<Key, Value>::~Map()
{
}

template <class Key, class Value>
void Map<Key, Value>::push(Key* key, Value* value)
{
	pushOnce(key, value);
}

template <class Key, class Value>
void Map<Key, Value>::remove(Key* key)
{
	base::remove(key);
}

template <class Key, class Value>
Value* Map<Key, Value>::pull(Key* key)
{
	return base::pull(key);
}

template <class Key, class Value>
const Value* Map<Key, Value>::peek(Key* key)
{
	return base::peek(key);
}

template <class Key, class Value>
void Map<Key, Value>::print()
{
	base::print();
}

