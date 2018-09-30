
#ifndef TREE_HPP_
#define TREE_HPP_

#include "treenode.hpp"


class Tree
{
public:
	Tree();
	void insertValue(const std::string &value);
	void deleteValue(const std::string &value);
	int getCount(const std::string &value);
	void printTree();
	int getSize() {return size;}

private:
	void insertNode(Treenode * &treenode, const std::string &value);
	void deleteNode(Treenode * &treenode, const std::string &value);
	Treenode * searchTree(Treenode * &treenode, const std::string &value);
	void traverseTree(Treenode * treenode);

	int size;
	int totalcount;
	Treenode * root;
};

Tree::Tree()
{
	size = 0;
	totalcount = 0;
	root = NULL;
}

void Tree::insertNode(Treenode * &treenode, const std::string &value)
{
	if (treenode == NULL)
	{
		treenode = new Treenode;
		treenode->value = value;

		if (size == 0)
		{
			root = treenode;
		}

		size += 1;
		totalcount += 1;
	}
	else if (value < treenode->value)
	{
		insertNode(treenode->left, value);
	}
	else if (value > treenode->value)
	{
		insertNode(treenode->right, value);
	}
	else // value == tree->value
	{
		treenode->count += 1;
		totalcount += 1;
	}
}

void Tree::deleteNode(Treenode * &treenode, const std::string &value)
{
	if (treenode == NULL)
	{
		return;
	}

	deleteNode(treenode->left, value);
	deleteNode(treenode->right, value);

	if (treenode->count > 1)
	{
		treenode->count -= 1;
	}
	else
	{
		delete treenode;
		treenode = NULL;
	}
}

Treenode * Tree::searchTree(Treenode * &treenode, const std::string &value)
{
	if (treenode == NULL)
	{
		return NULL;
	}
	else if (value < treenode->value)
	{
		searchTree(treenode->left, value);
	}
	else if (value > treenode->value)
	{
		searchTree(treenode->right, value);
	}
	else // value == tree->value
	{
		return treenode;
	}

	return NULL;
}

void Tree::traverseTree(Treenode * treenode)
{
	if (treenode != NULL)
	{
		traverseTree(treenode->left);
		std::cout << treenode->value << ": count = " << treenode->count << std::endl;
		traverseTree(treenode->right);
	}
}

void Tree::insertValue(const std::string &value)
{
	insertNode(root, value);
}

void Tree::deleteValue(const std::string &value)
{
	deleteNode(root, value);
}

int Tree::getCount(const std::string &value)
{
	Treenode * treenode = searchTree(root, value);
	if (treenode != NULL)
	{
		return treenode->count;
	}
	else
	{
		return 0;
	}
}

void Tree::printTree()
{
	traverseTree(root);
}


#endif /* TREE_HPP_ */
