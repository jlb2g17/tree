
#ifndef TREENODE_HPP_
#define TREENODE_HPP_


class Treenode
{
public:
	Treenode();

	std::string value;
	int count;
	Treenode * left;
	Treenode * right;
};

Treenode::Treenode()
{
	count = 1;
	left = NULL;
	right = NULL;
}


#endif /* TREENODE_HPP_ */
