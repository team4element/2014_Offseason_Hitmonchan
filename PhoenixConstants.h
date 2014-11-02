#ifndef __Phoenix_CONSTANTS_H__
#define __Phoenix_CONSTANTS_H__

#include <hostLib.h>
#include <WPILib.h>
#include <fstream>
#include <string>
#include <map>
#include "Declarations.h"
#include "PhoenixLib/PhoenixLib.h"

// Short way to access a constant.  There's probably a better way to do this.
#define CONSTANT PhoenixConstants::GetInstance()->GetValueForKey

class PhoenixConstants
{	
private:
	// Converting from a std::string to a double is expensive,
	// and almost every constant will be a double, so we cast
	// at load time instead of continuously
	typedef struct
	{
		string value;
		double numeric;
	} st_PhoenixConstant;
	
	map<string, st_PhoenixConstant> m_Data;		
	static PhoenixConstants * m_SingletonInstance;
	
	PhoenixLib::PhoenixLexer* m_Lexer;
	
	void GrammarError(char* expectedTokenDescription, string value, string receivedToken);
	void ParseINI(string data, char* filename);
	
	PhoenixConstants();
public:
	void RestoreData(char* filename = PhoenixCONSTANTS_DEFAULT_FILE);

	static PhoenixConstants * GetInstance();
	
	double GetValueForKey(char* key);
	template <typename T>
	T GetValueForKey(char* key);
	
	void SetValueForKey(string key, string value);
	
	bool DoesKeyExist(string key);	
};

#endif
