#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "node.h"
#include "main.h"
#include "parser.h"
#include "backend.h"

std::set<char> bf_chars;

Lexer * lexer = NULL;
Block_Node * root = NULL;

std::ifstream bf_file;
int main(int argc, char ** argv)
{
	std::cout<<"Compiling "<<argv[1]<<std::endl;

	{
		bf_chars.insert('+');
		bf_chars.insert('-');
		bf_chars.insert('<');
		bf_chars.insert('>');
		bf_chars.insert(',');
		bf_chars.insert('.');
		bf_chars.insert('[');
		bf_chars.insert(']');
	}
	std::string bf_filname(argv[1]);
	std::string c_filename(argv[2]);
	lexer = new First_Lexer(bf_filname);
	Parser * parser = new BF_Parser;
	Backend * backend = new C_Backend;
	root = parser->program();
	if(parser->is_error)
	{
		std::cout<<"Compiling failed!"<<std::endl;
	}
	backend->output(c_filename);
	return 0;
}








First_Lexer::First_Lexer(std::string bf_filename)
{
	bf_file.open(bf_filename);
	current_offset = -1;
	current_line = 1;
}


Token * First_Lexer::get_next_token()
{
	while(!bf_file.eof())
	{
		current_offset++;
		char current_char = bf_file.get();
		if(bf_chars.count(current_char)!=0)
		{
			return new Token(current_char, current_line, current_offset);
		}
		if('\n' == current_char)
		{
			current_offset = -1;
			current_line++;
		}
	}
	bf_file.close();
	return new Token();

}

















void info(std::string info_msg)
{
	std::cout<<info_msg;
}


void infon(std::string info_msg)
{
	std::cout<<info_msg<<std::endl;
}