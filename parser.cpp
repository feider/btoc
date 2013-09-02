#include "parser.h"
#include "main.h"
#include "node.h"
#include <iostream>

Block_Node * BF_Parser::program()
{
	is_error = false;
	Block_Node * base = new Root_Node;
	base->init(0, 0, 0);
	Token * temp_token=NULL;
	do
	{
		temp_token = lexer->get_next_token();
		Node * temp_node;
		switch(temp_token->type)
		{
				case LEFT:
				{
					temp_node = new Pointer_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case RIGHT:
				{
					temp_node = new Pointer_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case ADD:
				{
					temp_node = new Cell_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case SUB:
				{
					temp_node = new Cell_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case IN:
				{
					temp_node = new IO_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case OUT:
				{
					temp_node = new IO_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case LOOPL_NZ:
				{
					temp_node = new Loop_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					this->loop((Block_Node*)temp_node);
					break;
				}
				case LOOPR_NZ:
				{
					std::cout<<"ERROR: ']' without '['"<<std::endl<<"\tline "<<std::to_string(temp_token->line)<<", offset "<<std::to_string(temp_token->offset)<<std::endl;
					is_error = true;
					break;
				}
				case END:
				{
					break;
				}
		}
		if(is_error)
		{
			return NULL;
		}
	}while(temp_token->type != END);
	return base;
}


void BF_Parser::bf_operator(Block_Node * base)
{

}

void BF_Parser::loop(Block_Node * base)
{
	Token * temp_token=NULL;
	do
	{
		temp_token = lexer->get_next_token();
		Node * temp_node;
		switch(temp_token->type)
		{
				case LEFT:
				{
					temp_node = new Pointer_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case RIGHT:
				{
					temp_node = new Pointer_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case ADD:
				{
					temp_node = new Cell_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case SUB:
				{
					temp_node = new Cell_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case IN:
				{
					temp_node = new IO_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					break;
				}
				case OUT:
				{
					temp_node = new IO_Node;
					temp_node->init(temp_token->line, temp_token->offset, true);
					base->nodes.push_back(temp_node);
					break;
				}
				case LOOPL_NZ:
				{
					temp_node = new Loop_Node;
					temp_node->init(temp_token->line, temp_token->offset, false);
					base->nodes.push_back(temp_node);
					this->loop((Block_Node*)temp_node);
					break;
				}
				case LOOPR_NZ:
				{
					return;
					break;
				}
				case END:
				{
					std::cout<<"ERROR: Missing ] at the end of file"<<std::endl;
					std::cout<<"\tloop must be closed"<<std::endl;
					return;
					break;
				}
		}
	}while(temp_token->type != END);
}