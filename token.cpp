#include "main.h"
#include <iostream>
#include <string>

// Token
Token::Token(char chr, unsigned int line, unsigned int offset)
{
		this->chr = chr;
		switch(chr)
		{
			case '<':
			{
				this->type = LEFT;
				break;
			}
			case '>':
			{
				this->type = RIGHT;
				break;
			}
			case '+':
			{
				this->type = ADD;
				break;
			}
			case '-':
			{
				this->type = SUB;
				break;
			}
			case ',':
			{
				this->type = IN;
				break;
			}
			case '.':
			{
				this->type = OUT;
				break;
			}
			case '[':
			{
				this->type = LOOPL_NZ;
				break;
			}
			case ']':
			{
				this->type = LOOPR_NZ;
				break;
			}
		}
		this->line = line;
		this->offset = offset;


	}

Token::Token()
{
	this->line = 0;
	this->offset = 0;
	this->type = END;
}
std::string Token::to_string()
{
	std::string ret_string("");
	ret_string += "line: ";
	ret_string += std::to_string(this->line);
	ret_string += "; offset: ";
	ret_string += std::to_string(this->offset);
	ret_string += "; token: ";
	ret_string += this->chr;
	return ret_string;
}