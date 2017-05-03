//
// Created by Kamil Królikowski on 3/19/17.
// kamil-krolikowski@outlook.com
//

#ifndef KRLIB_LIST_H
#define KRLIB_LIST_H
#include <cstddef>

//--------------------------List class--------------------------------
template<class Type>
class List {
	class Node;
	
public:
	List();
	~List();
	bool PushFirst(Type *object);
	bool PushLast(Type * object);
	int GetSize() const;
	Type *Get(int index) const;
	Type *Pop(int index);
	Type *GetLast() const;
	Type *GetFirst() const;
	Type *PopFirst();
	Type *PopLast();
	bool Delete(int index);
private:
	Node *getElement(int index);
	int elementsNumber;
	Node *firstPtr;
	Node *lastPtr;
};

template <class Type>
class List<Type>::Node {
public:
	Node();
	~Node();
private:
	Node *nextPtr;
	Node *prevPtr;
	Type *object;
	template<class Object> friend class List;

};
template <class Type>
List<Type>::Node::Node()
{
	//printf("New list\n");

	nextPtr = nullptr;
	prevPtr = nullptr;
	object = nullptr;
}

template <class Type>
List<Type>::Node::~Node()
{
	if (object)
		delete object;
}

template<class Type>
List<Type>::List() {
	elementsNumber = 0;
	firstPtr = nullptr;
	lastPtr = nullptr;
}

template<class Type>
List<Type>::~List() {
	Node *el = firstPtr;
	Node *tmp;
	while (el) {
		tmp = el;
		el = el->nextPtr;
		delete tmp;
	}
}




template<class Type>
bool List<Type>::PushFirst(Type *object) {
	Node * element = new Node;
	if (object == nullptr) {
		//printf("Given pointer is nullptr");
		return false;
	}
	elementsNumber++;
	//If there is no elements in the list
	if (firstPtr == nullptr) {
		firstPtr = element;
		lastPtr = element;
		element->prevPtr = nullptr;
		element->nextPtr = nullptr;
	}
	else {
		firstPtr->prevPtr = element;
		element->prevPtr = nullptr;
		element->nextPtr = firstPtr;
		firstPtr = element;
	}
	element->object = object;
	return true;
}

template <class Type>
bool List<Type>::PushLast(Type *object) {
	Node *element = new Node;
	if (object == nullptr) {
		printf("Given pointer is nullptr\n");
		return false;
	}
	elementsNumber++;
	//If there is no elements in the list
	if (firstPtr == nullptr) {
		firstPtr = element;
		lastPtr = element;
		element->prevPtr = nullptr;
		element->nextPtr = nullptr;
	}
	else {
		lastPtr->nextPtr = element;
		element->nextPtr = nullptr;
		element->prevPtr = lastPtr;
		lastPtr = element;
	}
	element->object = object;
	return true;
}
template<class Type>
Type *List<Type>::Get(int index) const {
	Node *element = firstPtr;
	int i = 0;
	while (element != nullptr) {
		if (i++ == index) return element->object;
		element = element->nextPtr;
	}
	return nullptr;
}

template<class Type>
Type *List<Type>::Pop(int index) {
	Node *element = firstPtr;
	bool found = false;
	int i = 0;
	while (element != nullptr) {
		if (i++ == index) {
			found = true;
			break;
		};
		element = element->nextPtr;
	}
	if (found) {
		if (element == firstPtr)
			firstPtr = element->nextPtr;
		else
			element->prevPtr->nextPtr = element->nextPtr;
		if (element == lastPtr)
			lastPtr = element->prevPtr;
		else
			element->nextPtr->prevPtr = element->prevPtr;
		elementsNumber--;
		Type*object = element->object;
		element->object = nullptr;
		delete element;
		return object;
	}

	return nullptr;
}


template<class Type>
Type *List<Type>::GetLast() const {
	if (!lastPtr) return nullptr;
	return lastPtr->object;
}




template<class Type>
Type *List<Type>::GetFirst() const {
	if (!firstPtr) return nullptr;
	return firstPtr->object;
}
template<class Type>
Type *List<Type>::PopFirst() {
	if (firstPtr == nullptr) return nullptr;
	Node *element = firstPtr;
	firstPtr = element->nextPtr;
	if (lastPtr == element)
		lastPtr = nullptr;
	if (element->nextPtr)element->nextPtr->prevPtr = nullptr;
	elementsNumber--;
	Type*object = element->object;
	element->object = nullptr;
	delete element;
	return object;
}
template<class Type> Type *List<Type>::PopLast() {
	if (!lastPtr) return nullptr;
	Node *element = lastPtr;
	lastPtr = element->prevPtr;
	if (firstPtr == element)
		firstPtr = nullptr;
	if (element->prevPtr)element->prevPtr->nextPtr = nullptr;
	elementsNumber--;
	Type*object = element->object;
	element->object = nullptr;
	delete element;
	return object;
}
template<class Type>
bool List<Type>::Delete(int index) {
	Node *element = getElement(index);
	if (element == nullptr) return false;


	if (element->prevPtr != nullptr && element->nextPtr != nullptr) {
		element->prevPtr->nextPtr = element->nextPtr;
		element->nextPtr->prevPtr = element->prevPtr;
	}
	else {
		if (element->prevPtr == nullptr && element->nextPtr == nullptr) {
			firstPtr = nullptr;
			lastPtr = nullptr;
		}
		else {
			if (element->prevPtr == nullptr) {
				firstPtr = element->nextPtr;
				element->nextPtr->prevPtr = nullptr;
			}
			if (element->nextPtr == nullptr) {
				lastPtr = element->prevPtr;
				element->prevPtr->nextPtr = nullptr;
			}
		}
	}
	elementsNumber--;
	delete element;
	return true;
}

template<class Type>
typename List<Type>::Node *List<Type>::getElement(int index) {
	Node *element = firstPtr;
	int i = 0;
	while (element != nullptr) {
		if (i++ == index) return element;
		element = element->nextPtr;
	}
	return nullptr;
}
template <class Type>
int List<Type>::GetSize() const {
	return elementsNumber;
}


#endif //KRLIB_LIST_H 