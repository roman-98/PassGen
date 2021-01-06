#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{

	char test[] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e',
	'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 
	'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r',
	'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y',
	'y', 'Z', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};

	unsigned short Passwords, Characters, size = sizeof(test) / sizeof(test[0]);
	srand(time(0));

	cout << "Кількість паролів: ";
	cin >> Passwords;

	cout << "Кількість символів в паролі: ";
	cin >> Characters;
	const unsigned short SaveCharacters = Characters;

	ofstream outFile("PassGen.txt");
		for(; Passwords > 0; Passwords--)
		{
			for(; Characters > 0; Characters--)
			{
				outFile << test[rand() % size];
			}

			if(Characters == 0)
			{
				Characters = SaveCharacters;
				outFile << endl;
			}
		}
	outFile.close();

	cout << "Паролі збережені в файл PassGen.txt\n";

	return 0;
}