#ifndef __Phoenix_LEXER_H__
#define __Phoenix_LEXER_H__

#include <stdio.h>
#include <string>
#include <vector>
#include <pcre.h>

namespace PhoenixLib
{
	class PhoenixLexer
	{
	private:
		typedef struct
		{
			std::string name;
			pcre* pattern;
			// Result info is stored for sorting
			int resultBeginOffset;
			int resultEndOffset;
		} st_PrivateToken;
	
		std::vector<st_PrivateToken> m_Tokens;
	public:
		typedef struct
		{
			std::string type;
			std::string value;
		} st_Token;
		PhoenixLexer();
		void AddToken(std::string name, char* pattern);
		std::vector<PhoenixLib::PhoenixLexer::st_Token> TokenizeString(std::string str);
	};
}

#endif
