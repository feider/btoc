#include "backend.h"
#include "main.h"
#include <fstream>
#include <iostream>

std::string Test_Backend::to_string(Block_Node * loop_node, int depth)
{
	std::cout<<std::to_string(depth)<<std::endl;
	std::string return_string("");
	std::string tabs("");
	for(int i = 0; i<depth; i++)
	{
		tabs += "\t";
	}
	for(int i = 0; i<loop_node->nodes.size(); i++)
	{
		switch(loop_node->nodes[i]->type)
		{
			case LoopNode:
			{
				Block_Node * temp_node = (Block_Node*) loop_node->nodes[i];
				return_string += this->to_string(temp_node, depth+1);
				break;
			}
			case PointerNode:
			{
				return_string += tabs + "pointer\n";
				break;
			}
			case CellNode:
			{
				return_string += tabs + "cell\n";
				break;
			}
			case IONode:
			{
				return_string += tabs + "IO\n";
				break;
			}
		}
	}
	return return_string;
}

void Test_Backend::output(std::string output_filename)
{
	std::string output_string = this->to_string(root,0);
	std::cout << output_string;
}