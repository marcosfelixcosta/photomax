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