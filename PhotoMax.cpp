#include <iostream>
using namespace std;

int main(int argc, char* argv []) {
	setlocale(LC_ALL,"pt_BR");
	//cout << "Primeira fun��o C++" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}