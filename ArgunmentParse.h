#pragma once
#include <string>
#include <map>
using namespace std;

class ArgumentParse
{
public:
	//Registra uma flag usada durante o Parse
	void RegisterFlag(const string& flag);
	
	//Pega o valor de uma flag obtida durante o Parse
	bool GetFlag(const string& flag) const;

	//Faz o parse da lista de argumento em argv
	void Parse(int argc, char* argv[]);

private:
	map<string, bool> m_Flags;
};