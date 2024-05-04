#include "ArgunmentParse.h"
#include <algorithm>
#include <cctype>

string ToLower(string str)
{
	transform(begin(str), end(str), begin(str),
		[](unsigned char c) {return tolower(c); });

	return str;
}

void ArgumentParse:: RegisterFlag(const string& flag)
{
	if (!flag.empty())
	{
		m_Flags[flag] = false;
	}
}

bool ArgumentParse:: GetFlag(const string& flag) const
{
	if (!flag.empty())
	{
		auto flagIt = m_Flags.find(flag);
		if (flagIt != end(m_Flags))
		{
			return flagIt->second;
		}
	}
	return false;
}


void ArgumentParse::RegisterOption(const string& option)
{
	if (!option.empty())
	{
		m_Options[option] = "";
    }
}

const string& ArgumentParse::GetOption(const string& option) const
{
	if (!option.empty())
	{
		auto optionIt = m_Options.find(option);
		if (optionIt != end(m_Options))
		{
			return optionIt->second;
		}
	}
	static string EmptyOption = "";
	return EmptyOption;
}

void ArgumentParse::Parse(int argc, char* argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			//string arg = argv[i];
			string arg = ToLower(argv[i]);
			if (arg.length() >= 3)
			{
				if (arg[0] == '-' && arg[1] == '-')
				{
					arg = arg.substr(2);

					if (arg.find_first_of('=') != string::npos)
					{
						//Isso 'e uma opção
						const size_t equalSignPos = arg.find('=');
						if (equalSignPos !=string::npos) 
						{
							string optionName = arg.substr(0, equalSignPos);
							string optinValue = arg.substr(equalSignPos + 1);

							auto optionIt = m_Options.find(optionName);
							if (optionIt!= end(m_Options) )
							{
								optionIt->second = optinValue;
							}
						}
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