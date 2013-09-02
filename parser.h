#ifndef parser_h
#define parser_h
#include "node.h"

class Parser
{
public:
	bool is_error;
	virtual Block_Node * program() = 0;
	virtual void bf_operator(Block_Node * base) = 0;
	virtual void loop(Block_Node * base) = 0;
};

class BF_Parser : public Parser
{
public:
	Block_Node * program();
	void bf_operator(Block_Node * base);
	void loop(Block_Node * base);
};


#endif