#pragma once
#include <string>
#include <map>
using namespace std;

class ArgumentParse
{
public:
	//Registra uma flag usada durante o Parse
	void RegisterFlag(const string& flag);

	//Registar uma op��o usada durante o parse
	void RegisterOption(const string& option);
	
	//Pega o valor de uma flag obtida durante o Parse
	bool GetFlag(const string& flag) const;

	//Obter o valor de uma op��o lida durante o parse
	const string& GetOption(const string& option) const;

	//Faz o parse da lista de argumento em argv
	void Parse(int argc, char* argv[]);

private:
	map<string, bool> m_Flags;
	map<string, string> m_Options;
};