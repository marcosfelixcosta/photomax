/*
- Aplicação para tratamento de imagens

- Analista: Marcos Felix
- Data: 25/04/2024


*/
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

class ArgumentParse 
{
public:
	void RegisterFlag(const string& flag)
	{
		if (!flag.empty())
		{
			m_Flags[flag] = false;
	 }
	}
	bool GetFlag(const string& flag) const
	{
		if (!flag.empty())
		{
			auto flagIt = m_Flags.find(flag);
			if (flagIt != end (m_Flags))
			{
				return flagIt->second;
			}
		}
		return false;
	}
	void Parse(int argc, char* argv[])
	{
		if (argc > 1)
	 {
			for (int i = 1; i < argc; i++)
			{
				string arg = argv[i];
				if (arg.length() >= 3)
				{
					if (arg[0] == '-' && arg[1] == '-')
					{
						arg = arg.substr(2);

						if (arg.find_first_of('=') != string::npos)
						{
							//Isso 'e uma opção
						}
						else
						{
							auto flagIt = m_Flags.find(arg);
							if (flagIt != ::end(m_Flags))
							{
                             //Achamos uma flag registrada
								flagIt->second = true;
							}
						}
					}
				}
		    }
	 }
	}

private:
	map<string, bool> m_Flags;
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