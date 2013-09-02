#ifndef node_h
#define node_h

#include <vector>

enum NodeType
{
	RootNode,
	LoopNode,
	PointerNode,
	CellNode,
	IONode
};

//Node
//	Block_Node
//		Root_Node
//		Loop_Node
//	Operation_Node
//		Pointer_Node left right
//		Cell_Node add sub
//		IO_Node	in out


class Node
{
public:
	NodeType type;
	 int line;
	 int offset;
	bool direction;
	virtual void init( int line,  int offset, bool direction)=0;
};

class Block_Node : public Node
{
public:
	std::vector<Node*> nodes;
};

class Root_Node : public Block_Node
{
public:
	void init( int line,  int offset, bool direction)
	{
		this->line = line;
		this->offset = offset;
		this->type = RootNode;
	}
};

class Loop_Node : public Block_Node
{
public:
	void init( int line,  int offset, bool direction)
	{
		this->line = line;
		this->offset = offset;
		this->type = LoopNode;
	}
};

class Operation_Node : public Node
{
public:
};

class Pointer_Node : public Operation_Node
{
public:
	void init( int line,  int offset, bool direction)
	{
		this->direction = direction;
		this->line = line;
		this->offset = offset;
		this->type = PointerNode;
	}
};

class Cell_Node : public Operation_Node
{
public:
	void init( int line,  int offset, bool direction)
	{
		this->direction = direction;
		this->line = line;
		this->offset = offset;
		this->type = CellNode;
	}
};

class IO_Node : public Operation_Node
{
public:
	void init( int line,  int offset, bool direction)
	{
		this->direction = direction;
		this->line = line;
		this->offset = offset;
		this->type = IONode;
	}
};



#endif