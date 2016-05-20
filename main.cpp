#include <iostream>
using namespace std;
bool esPanagrama(char*);
bool indexOf(char*, char);
int main(int argc, char const *argv[]){
	char* cadena = new char[144];
	cout << "Ingrese la palabra, frase, oracion, cancion o lo que ud desee" << endl;
	// cin >> cadena;
	// cin.ignore();
	cin.getline (cadena,144);
	cout << esPanagrama(cadena);
	return 0;
}
bool esPanagrama(char* cadena){
	char* letrasContenidas = new char[26];
	int posicionLetras = 0;
	for(int LETRA = 0; cadena[LETRA]; LETRA++){
		if(cadena[LETRA] != ' '){
			if(!indexOf(letrasContenidas, cadena[LETRA])){
				letrasContenidas[posicionLetras] = cadena[LETRA];
				posicionLetras++;
			}
		}
	}
	if(posicionLetras == 26){
		return 1;
	}
	return false;
}
bool indexOf(char* cadena, char letra){
	for(int i = 0; cadena[i]; i++){
			cout << letra << " == ";
			cout << "\t" << cadena[i] << endl;
		if(cadena[i] == letra){
			return 1;
		}		
	}
	return 0;
}
//the quick brown fox jumps over the lazy dog
// el viejo senor gomez pedia queso, kiwi y habas, pero le ha tocado un saxofon
//grumpy wizards make toxic brew for the evil queen and jack