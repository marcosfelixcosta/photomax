/*
- Aplicação para tratamento de imagens

- Analista: Marcos Felix
- Data: 25/04/2024


*/
#include <iostream>
#include "ArgunmentParse.h"
using namespace std;

int main(int argc, char* argv []) {
	setlocale(LC_ALL,"pt_BR");
	
	ArgumentParse argParser;
	argParser.RegisterFlag("rename");
	argParser.RegisterFlag("convert");
	argParser.RegisterFlag("resize");
	argParser.RegisterFlag("scale");
	argParser.RegisterOption("folder");
	argParser.RegisterOption("amount");

	argParser.Parse(argc, argv);

	cout << boolalpha  << "rename  : " << argParser.GetFlag("rename")  << endl;
	cout << boolalpha  << "convert : " << argParser.GetFlag("convert") << endl;
	cout << boolalpha  << "resize  : " << argParser.GetFlag("resize")  << endl;
	cout << boolalpha  << "scale   : " << argParser.GetFlag("scale")   << endl;
	cout << "Folder :" << argParser.GetOption("folder") << endl;
	cout << "Amount :" << argParser.GetOption("amount") << endl;

	return 0;
}