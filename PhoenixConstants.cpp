#include "PhoenixConstants.h"

// Singleton instance
PhoenixConstants *  PhoenixConstants::m_SingletonInstance = NULL;

PhoenixConstants * PhoenixConstants::GetInstance()
{
	if(m_SingletonInstance == NULL)
	{
		m_SingletonInstance = new PhoenixConstants();
	}
	return m_SingletonInstance;
}

PhoenixConstants::PhoenixConstants()
	:
	m_Lexer(new PhoenixLib::PhoenixLexer())
{
	m_Lexer->AddToken("", "#[^\\n]*"); // Ignore comments
	m_Lexer->AddToken("LeftBracket", "\\[");
	m_Lexer->AddToken("RightBracket", "\\]");
	m_Lexer->AddToken("Equals", "=");
	m_Lexer->AddToken("Semicolon", ";");
	m_Lexer->AddToken("Number", "-?[0-9]*\\.?[0-9]+");
	m_Lexer->AddToken("Name", "[A-Za-z0-9_-]+");
	RestoreData();
}

/// Returns a bool indicating if the key/value pair exists 
bool PhoenixConstants::DoesKeyExist(string key)
{
	return (bool) m_Data.count(key);
}

double PhoenixConstants::GetValueForKey(char* key)
{
	if(DoesKeyExist(string(key)))
	{
		return m_Data[string(key)].numeric;
	}
	else
	{
		printf("Missing constant: %s!!\nKilling FRC_RobotTask\n", key);
		PhoenixLib::PrintToLCD("Missing constant!!\n%s\n\nKilling FRC_RobotTask", key);
		wpi_selfTrace();
		exit(1); // kill the robot
		return 0;
	}
}

template <typename T>
T PhoenixConstants::GetValueForKey(char* key)
{
	if(DoesKeyExist(string(key)))
	{
		// use a stringstream to convert to T
		T result;
		std::istringstream iss(m_Data[string(key)].value);
		if(!(iss > result).fail())
		{
			// successful conversion
			return result;
		}
		else
		{
			printf("Bad conversion for constant: %s!!\nKilling FRC_RobotTask\n", key);
			PhoenixLib::PrintToLCD("Bad conversion!!\n%s\n\nKilling FRC_RobotTask", key);
			wpi_selfTrace();
			exit(1); // kill the robot
			return 0;	
		}
	}
	else
	{
		printf("Missing constant: %s!!\nKilling FRC_RobotTask\n", key);
		PhoenixLib::PrintToLCD("Missing constant!!\n%s\n\nKilling FRC_RobotTask", key);
		wpi_selfTrace();
		exit(1); // kill the robot
		return 0;
	}
}

void PhoenixConstants::SetValueForKey(string key, string value)
{
	m_Data[key].value = value;
	m_Data[key].numeric = atof(value.c_str());
}

void PhoenixConstants::GrammarError(char* expectedTokenDescription, string value, string receivedToken)
{
	printf("Error: expected %s before \"%s\", instead got \"%s\"\nAborting parsing\n", expectedTokenDescription, value.c_str(), receivedToken.c_str());
}

void PhoenixConstants::RestoreData(char* filename)
{
	// Clear constants info
	m_Data.clear();
	
	// Load in our file
	string data;
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if(!file)
	{
		printf("Error: could not read %s\nNo constants were loaded.\n", filename);
		return;
	}
	file.seekg(0, std::ios::end);
	data.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&data[0], data.size());
	file.close();
	
	ParseINI(data, filename);
}

void PhoenixConstants::ParseINI(string data, char* filename)
{
	char robotName[64] = {0};
	gethostname(robotName, 64);
	
	// Tokenize
	std::vector<PhoenixLib::PhoenixLexer::st_Token> tokens = m_Lexer->TokenizeString(data);
	
	char* currentSection = NULL;
	
	// Start parsing INI grammar
	if(tokens.size() == 0)
	{
		// This is a really bizzare case, not sure how to write a descriptive error
		printf("Warning: %s does not appear to be a proper constants file.\nNo constants were loaded.\n", filename);
		return;
	}
	
	// Add an end of file token so that we don't miss dangling tokens
	PhoenixLib::PhoenixLexer::st_Token eof;
	eof.type = "<EOF>";
	eof.value = "<EOF>";
	tokens.push_back(eof);
	
	// Make sure our first token is okay before we loop
	if(tokens[0].type != "LeftBracket" && tokens[0].type != "Name")
	{
		return GrammarError("\"[\" or name", tokens[1].value, tokens[0].value);
	}
	
	// This loop looks at every token after the first one and makes sure it makes sense to go after the token behind it
	// For example, putting a semicolon after a left bracket wouldn't make since, and causes an error
	for(unsigned int i = 1; i < tokens.size(); i++)
	{
		PhoenixLib::PhoenixLexer::st_Token t = tokens[i];
		if(t.type == "LeftBracket" &&
		   tokens[i-1].type != "RightBracket" &&
		   tokens[i-1].type != "Semicolon")
		{
			return GrammarError("\"]\" or \";\"", t.value, tokens[i-1].value);
		}
		else if(t.type == "Name" &&
		   tokens[i-1].type != "LeftBracket" &&
		   tokens[i-1].type != "RightBracket" &&
		   tokens[i-1].type != "Semicolon")
		{
			return GrammarError("\"]\" or \";\"", t.value, tokens[i-1].value);
		}
		else if(t.type == "RightBracket")
		{
			if(tokens[i-1].type != "Name")
			{
				return GrammarError("name", t.value, tokens[i-1].value);
			}
			else if(i == 1)
			{
				printf("Error: unmatched \"]\" after \"%s\"\nAborting parsing\n", tokens[i-1].value.c_str());
				return;
			}
			else if(tokens[i-2].type != "LeftBracket")
			{
				printf("Error: unmatched \"]\" after \"%s\"\nAborting parsing\n", tokens[i-1].value.c_str());
				return;
			}
			else
			{
				currentSection = (char*)tokens[i-1].value.c_str();
			}
		}
		else if(t.type == "Equals")
		{
			if(tokens[i-1].type != "Name")
			{
				return GrammarError("name", t.value, tokens[i-1].value);
			}
		}
		else if(t.type == "Number")
		{
			if(tokens[i-1].type != "Equals")
			{
				return GrammarError("\"=\"", t.value, tokens[i-1].value);
			}
			else
			{
				if(currentSection == NULL || strcmp(currentSection, robotName) == 0)
				{
					if(currentSection != NULL)
					{
						printf("%s.", currentSection);
					}
					printf("%s: %s\n", tokens[i-2].value.c_str(), t.value.c_str());
					SetValueForKey(tokens[i-2].value, t.value);
				}
			}
		}
		else if(t.type == "Semicolon")
		{
			if(tokens[i-1].type != "Number")
			{
				return GrammarError("number", t.value, tokens[i-1].value);
			}
		}
		else if(t.type == "<EOF>")
		{
			if(tokens[i-1].type != "RightBracket" &&
			   tokens[i-1].type != "Semicolon")
			{
				return GrammarError("\"]\" or \";\"", t.value, tokens[i-1].value);
			}
		}
	}
}
