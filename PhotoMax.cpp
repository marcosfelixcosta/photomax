/*
- Aplica��o para tratamento de imagens

- Analista: Marcos Felix
- Data: 25/04/2024


*/

#include <iostream>
using namespace std;

int main(int argc, char* argv []) {
	setlocale(LC_ALL,"pt_BR");
	cout << "Aplica��o C++ para tratamento de imagens" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}