#ifndef main_h
#define main_h

#include <string>

class Block_Node;

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
	Token(char chr,  int line,  int offset);
	
	Token();

	TokenType type;
	char chr;
	 int line;
	 int offset;
	std::string to_string();
};

class Lexer
{
public:
	virtual Token * get_next_token() = 0;
	//Lexer();
	 int current_line;
	 int current_offset;
};

class First_Lexer : public Lexer
{
public:
	Token * get_next_token();
	First_Lexer(std::string bf_filename);
};






void info(std::string info_msg);
void infon(std::string info_msg);

extern Lexer * lexer;
extern Block_Node * root;

#endif
