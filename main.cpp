#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "node.h"
#include "main.h"

std::set<char> bf_chars;

Lexer * lexer = NULL;

std::ifstream bf_file;
int main(int argc, char ** argv)
{

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
	Node * root = program();
	return 0;
}








First_Lexer::First_Lexer(std::string bf_filename)
{
	bf_file.open(bf_filename);
	current_offset = 0;
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
			current_offset = 0;
			current_line = 0;
		}
	}
	bf_file.close();
	return new Token();

}




Node * program()
{

}


void bf_operator(Block_Node * base)
{

}

void loop(Block_Node * base)
{

}












void info(std::string info_msg)
{
	std::cout<<info_msg<<std::endl;
}