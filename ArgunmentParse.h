#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;

class ArgumentParse
{
#include <iostream>



public:
	//Registra uma flag usada durante o Parse
	void RegisterFlag(const string& flag);

	//Registar uma opção usada durante o parse
	void RegisterOption(const string& option);
	
	//Pega o valor de uma flag obtida durante o Parse
	bool GetFlag(const string& flag) const;

	//Obter o valor de uma opção lida durante o parse
	const string& GetOption(const string& option) const;

	//Obter um valor de uma opção convertida para float
	float GetOptionAsFloat(const string& option) const;

	// Obter um valor de uma opção convertida para int
	int GetOptionInt(const string& option) const;

	template<typename T>
	T GetOptionAs(const string& option) const;

	template<>
	const string& GetOptionAs(const string& option) const {return GetOption(option);}
	
	template<>
	float GetOptionAs(const string& option) const {return GetOptionAsFloat(option);}

	template<>
	int GetOptionAs(const string& option) const {return GetOptionInt(option);}

	
	//Faz o parse da lista de argumento em argv
	void Parse(int argc, char* argv[]);

private:
	map<string, bool> m_Flags;
	map<string, string> m_Options;
};