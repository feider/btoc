#include "main.h"
#include <iostream>
#include <string>

// Token
Token::Token(char chr,  int line,  int offset)
{
		this->chr = chr;
		bool is_token = false;
		switch(chr)
		{
			case '<':
			{
				this->type = LEFT;
				is_token = true;
				break;
			}
			case '>':
			{
				this->type = RIGHT;
				is_token = true;
				break;
			}
			case '+':
			{
				this->type = ADD;
				is_token = true;
				break;
			}
			case '-':
			{
				this->type = SUB;
				is_token = true;
				break;
			}
			case ',':
			{
				this->type = IN;
				is_token = true;
				break;
			}
			case '.':
			{
				this->type = OUT;
				is_token = true;
				break;
			}
			case '[':
			{
				this->type = LOOPL_NZ;
				is_token = true;
				break;
			}
			case ']':
			{
				this->type = LOOPR_NZ;
				is_token = true;
				break;
			}
		}
		this->line = line;
		this->offset = offset;
		if(is_token)
		{
			//std::cout<<"Token "<<chr<<", line "<<std::to_string(line)<<", offset "<<std::to_string(offset)<<std::endl;
		}


	}

Token::Token()
{
	this->line = 0;
	this->offset = 0;
	this->type = END;
}

std::string Token::to_string()
{
	std::string ret_string = "";
	ret_string += "line: ";
	ret_string += std::to_string(this->line);
	ret_string += "; offset: ";
	ret_string += std::to_string(this->offset);
	ret_string += "; token: ";
	ret_string += this->chr;
	return ret_string;
}