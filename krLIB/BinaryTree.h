#pragma once
template <class IndexType, class ObjectType>
class BinaryTree
{
	class Node
	{
	public:
		explicit Node(IndexType index, ObjectType*object = nullptr,Node*parent = nullptr, Node*leftChild = nullptr, Node*rightChild = nullptr);
	private:
		IndexType index;
		ObjectType * object;
		Node * leftChild;
		Node * rightChild;
		Node * parent;
	};
public:
	BinaryTree();
	~BinaryTree();
	void Add(IndexType index, ObjectType*object=nullptr, Node*parent=nullptr, Node*leftChild = nullptr,Node*rightChild=nullptr);
private:
	Node*root;
	size_t numberOfNodes;
};

template <class IndexType, class ObjectType>
BinaryTree<IndexType, ObjectType>::Node::Node(IndexType index, ObjectType* object, Node* parent, Node* leftChild, Node* rightChild)
{
	this->index = index;
	this->object = object;
	this->parent = parent;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

template <class IndexType, class ObjectType>
BinaryTree<IndexType, ObjectType>::BinaryTree():root(nullptr), numberOfNodes(0){}

template <class IndexType, class ObjectType>
void BinaryTree<IndexType, ObjectType>::Add(IndexType index, ObjectType*object, Node* parent, Node* leftChild, Node* rightChild)
{
	if (!root)
		root = new Node(index, object, parent, leftChild, rightChild);
	numberOfNodes++;
}



