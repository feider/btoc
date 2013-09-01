#ifndef main_h
#define main_h

#include <string>



enum TokenType
{
	LEFT,
	RIGHT,
	ADD,
	SUB,
	IN,
	OUT,
	LOOPL_NZ,
	LOOPR_NZ,
	END
};

class Token
{
public:
	Token(char chr, unsigned int line, unsigned int offset);
	
	Token();

	TokenType type;
	char chr;
	unsigned int line;
	unsigned int offset;
	std::string to_string();
};

class Lexer
{
public:
	virtual Token * get_next_token() = 0;
	//Lexer();
	unsigned int current_line;
	unsigned int current_offset;
};

class First_Lexer : public Lexer
{
public:
	Token * get_next_token();
	First_Lexer(std::string bf_filename);
};



class Parser
{
public:
	
};




void info(std::string info_msg);

#endif