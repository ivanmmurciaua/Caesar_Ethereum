#include <iostream>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

/*
** @author Ivanovish10
*/
int main(int argc, char const *argv[]){

	string use  = "+------------------------------------------INCORRECT USE------------------------------------------+\n";
		   use += "|                                                                                                 |\n";
		   use += "|                                ./program_name [-d] [ENCRYPTED_KEY]                              |\n";
		   use += "|                                                                                                 |\n";
		   use += "+-------------------------------------------------------------------------------------------------+\n"; 

	string phrase = "";
	int _number = 0;

	if(argc != 3 && argc != 1) 
		cerr << use << endl;
	
	else {

		unordered_map<char, int> alphabet;

		alphabet['a'] = 1;  alphabet['A'] = 2;  alphabet['b'] = 3;  alphabet['B'] = 4;
		alphabet['c'] = 5;  alphabet['C'] = 6;  alphabet['d'] = 7;  alphabet['D'] = 8;
		alphabet['e'] = 9;  alphabet['E'] = 10; alphabet['f'] = 11; alphabet['F'] = 12;
		alphabet['g'] = 13; alphabet['G'] = 14; alphabet['h'] = 15; alphabet['H'] = 16;
		alphabet['i'] = 17; alphabet['I'] = 18; alphabet['j'] = 19; alphabet['J'] = 20;
		alphabet['k'] = 21; alphabet['K'] = 22; alphabet['l'] = 23; alphabet['L'] = 24;
		alphabet['m'] = 25; alphabet['M'] = 26; alphabet['n'] = 27; alphabet['N'] = 28;
		alphabet['o'] = 29; alphabet['O'] = 30; alphabet['p'] = 31; alphabet['P'] = 32;
		alphabet['q'] = 33; alphabet['Q'] = 34; alphabet['r'] = 35; alphabet['R'] = 36;
		alphabet['s'] = 37; alphabet['S'] = 38; alphabet['t'] = 39; alphabet['T'] = 40;
		alphabet['u'] = 41; alphabet['U'] = 42; alphabet['v'] = 43; alphabet['V'] = 44;
		alphabet['w'] = 45; alphabet['W'] = 46; alphabet['x'] = 47; alphabet['X'] = 48;
		alphabet['y'] = 49; alphabet['Y'] = 50; alphabet['z'] = 51; alphabet['Z'] = 52;
		
		// Numbers
		alphabet['1'] = 53; alphabet['2'] = 54;
		alphabet['3'] = 55; alphabet['4'] = 56;
		alphabet['5'] = 57; alphabet['6'] = 58;
		alphabet['7'] = 59; alphabet['8'] = 60;
		alphabet['9'] = 61; alphabet['0'] = 62;

		// Others
		alphabet['.'] = 63; alphabet[','] = 64; alphabet[' '] = 65;

		// Encrypt mode
		if(argc == 1) {

			string encrypted = "";
			string pk = "";

			cout << "Write your private key (¡¡THIS PROGRAM DOES NOT STORE YOUR PK!!): ";
			getline(cin, pk);

			do {
				cout << "Write a phrase with the size of your private key (e.g Ethereum PK average size is "<< pk.size() << "): ";
				getline(cin, phrase);
				
				if(phrase.size() != pk.size()) 
					cout << "Your phrase is " << phrase.size() << " length characters, please repeat it again" << endl;

			} while(phrase.size() != pk.size());

			for (int i = 0; i < phrase.size(); i++) {
				_number = alphabet[pk[i]] + alphabet[phrase[i]];

				while(_number > 65) _number -= 65;

				for (auto& it: alphabet){
					if(it.second == _number) {
						encrypted += (_number == 65) ? '/' : it.first;
						break; 
					}
				}
			}

			cout << "Your pk encrypted: " << encrypted << endl;

		}
		else{

			if(strcmp(argv[1], "-d") != 0) cerr << use << endl;

			//Decrypt mode
			else {
				
				string _pk = argv[2];				
				string decrypted = "";

				cout << "Write the phrase that you wrote for encrypt your private key: ";
				getline(cin, phrase);

				for (int i = 0; i < _pk.size(); i++){
					
					_number = (_pk[i] == '/') ? 65 - alphabet[phrase[i]] : alphabet[_pk[i]] - alphabet[phrase[i]];

					if(_number < 1) _number += 65;

					for (auto& it: alphabet){
						if(it.second == _number) {
							decrypted += it.first;
							break; 
						}
					}
				}

				cout << "Your pk decrypted: " << decrypted << endl;
			}
		}
	}

	return 0;
}