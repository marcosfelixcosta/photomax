/*
- Aplicação para tratamento de imagens

- Analista: Marcos Felix
- Data: 25/04/2024


*/
#include <iostream>
#include "ArgunmentParse.h"
using namespace std;

namespace Args
{
	namespace Flags 
	{
		static constexpr const char* Rename  = "rename";
		static constexpr const char* Convert = "convert";
		static constexpr const char* Resize  = "resize";
		static constexpr const char* Scale   = "scale";
	}
	  
}

void ValidateAguments(const ArgumentParse& argParser) 
{
	//Ler as flags que o ArgumentParser identificou
	const bool bRenameMode  = argParser.GetFlag (Args::Flags::Rename);
	const bool bConvertMode = argParser.GetFlag (Args::Flags::Convert);
	const bool bResizeMode  = argParser.GetFlag (Args::Flags::Resize);
	const bool bScaleMode   = argParser.GetFlag (Args::Flags::Scale);
	//Verificar se somente um modo do photmax esta ativo
	if (!(bRenameMode ^ bConvertMode ^ bResizeMode ^ bScaleMode))
	{
		throw std::invalid_argument("Somente um modo pode estar ativo!");
	}

}

int main(int argc, char* argv []) {
	setlocale(LC_ALL,"pt_BR");
	setlocale(LC_NUMERIC,"en_US");
	
	ArgumentParse argParser;
	argParser.RegisterFlag(Args::Flags::Rename);
	argParser.RegisterFlag(Args::Flags::Convert);
	argParser.RegisterFlag(Args::Flags::Resize);
	argParser.RegisterFlag(Args::Flags::Scale);
    //argParser.RegisterOption("empty");
	//argParser.RegisterOption("folder");
	//argParser.RegisterOption("amount");

	argParser.Parse(argc, argv);

	try
	{
		ValidateAguments(argParser);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	/*
	cout << boolalpha  << "rename  : " << argParser.GetFlag(Args::Flags::Rename)  << endl;
	cout << boolalpha  << "convert : " << argParser.GetFlag(Args::Flags::Convert) << endl;
	cout << boolalpha  << "resize  : " << argParser.GetFlag(Args::Flags::Resize)  << endl;
	cout << boolalpha  << "scale   : " << argParser.GetFlag(Args::Flags::Scale)   << endl;
	cout << boolalpha  << "Empty   : " << argParser.GetFlag("empty") << endl;
	cout << "Folder :" << argParser.GetOptionAs<const string&>("folder") << endl;
	cout << "Amount (float):" << argParser.GetOptionAs<float>("amount") << endl;
	cout << "Amount (int) :" << argParser.GetOptionAs<int>("amount") << endl;
	*/
	return 0;
}