/*
- Aplicação para tratamento de imagens

- Analista: Marcos Felix
- Data: 25/04/2024


*/
#include <iostream>
#include <iomanip>
using namespace std;

class ArgumentParse 
{
public:
	void RegisterFlag(const std::string& flag)
	{

	}
	bool GetFlag(const std::string& flag)
	{
		return false;
	}
	void Parse(int argc, char* argv[])
	{

	}

private:

};

int main(int argc, char* argv []) {
	setlocale(LC_ALL,"pt_BR");
	
	ArgumentParse argParser;
	argParser.RegisterFlag("rename");
	argParser.RegisterFlag("convert");
	argParser.RegisterFlag("resize");
	argParser.RegisterFlag("scale");

	argParser.Parse(argc, argv);

	cout << boolalpha  << "Rename  : " << argParser.GetFlag("rename")  << endl;
	cout << boolalpha  << "Convert : " << argParser.GetFlag("convert") << endl;
	cout << boolalpha  << "Resize  : " << argParser.GetFlag("resize")  << endl;
	cout << boolalpha  << "Scale   : " << argParser.GetFlag("scale")   << endl;

	return 0;
}