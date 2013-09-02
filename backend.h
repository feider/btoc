#ifndef backend_h
#define backend_h
#include <string>
#include "node.h"

class Backend
{
public:
	virtual void output(std::string output_filename)=0;

};




class Test_Backend : public Backend
{
public:
	std::string to_string(Block_Node * loop_node, int depth);
	void output(std::string output_filename);
};

#endif