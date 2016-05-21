#include <iostream>
#include <cstring>
using namespace std;
bool esPanagrama(char*);
int indexOf(char*, char);
void contarPalabras(char*);
char charToMorse(char*);
bool compararString(char[6], char*);
int main(int argc, char const *argv[]){
	char* cadena = new char[144];
	int opcion;
	do{
		cout << "-----------------------" << endl;
		cout << "EJERCICIO 1" << endl;
		cout << "EJERCICIO 2" << endl;
		cout << "EJERCICIO 3" << endl;
		cout << "Ingrese la opcion" << endl;
		cin >> opcion;
		if(opcion == 1){
			cout << "Ingrese la palabra, frase, oracion, cancion o lo que ud desee" << endl;
			cin.ignore();
			cin.getline (cadena,144);
			cout << "LA CADENA ES " << (esPanagrama(cadena) ? "" : "NO ") << "PANGRAMAS" << endl;
		} else if (opcion == 2){
			int continuar = 0;
			int totalCadenas = 0;
			char** cadenas = new char*[10];
			do{
				cout << "Ingrese la palabra, frase, oracion, cancion o lo que ud desee" << endl;
				cin.ignore();
				cin.getline (cadena,144);
				contarPalabras(cadena);
				cadenas[totalCadenas] = new char[144];
				strcpy(cadenas[totalCadenas], cadena);
				totalCadenas++;
				cout << "Deseas continuar? 1/0" << endl;
				cin >> continuar;
			}while(continuar);
			continuar = 0;
			cout << "Desea imprimir todas las cadenas? 1/0 " << endl;
			cin >> continuar;
			if(continuar){
				for(int i = 0; cadenas[i]; i++){
					cout << "Cadena Numero " << i + 1 << " = " << cadenas[i] << endl;
				}
			}
			for(int CADENA = 0; cadenas[CADENA]; CADENA++){
				delete[] cadenas[CADENA];	
			}
			delete[] cadenas;
		} else if (opcion == 3){
			cout << "Ingrese la palabra, frase, oracion, cancion o lo que ud desee. PERO EN MORSE" << endl;
			cin.ignore();
			cin.getline (cadena,144);
			char* palabra = new char[4];
			int cantidadLetras = 0;

			int LETRA = 0;
			cout << "LA CADENA CONVERTIDA ES = ";
			while(1){
				if(cadena[LETRA] == '&' || !cadena[LETRA]){
					if(cantidadLetras != 4){
						for(int i = cantidadLetras; i < 4; i++){
							palabra[i] = '*';
						}
					}
					cout << charToMorse(palabra);
					palabra = new char[100];
					cantidadLetras = 0;
				}else{
					palabra[cantidadLetras] = cadena[LETRA];	
					cantidadLetras++;
				}
				if(!cadena[LETRA]){
					break;
				}
				LETRA++;
			}
			cout << endl;
			delete[] palabra;
		}
	}while(1);
	return 0;
	delete[] cadena;
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
int indexOf(char* cadena, char letra){
	int cantidad = 0;
	for(int i = 0; cadena[i]; i++){
		if(cadena[i] == letra){
			cantidad++;
		}		
	}
	return cantidad;
}
void contarPalabras(char* cadena){
	int cantidadPalabras = 1;
	int cantidadLetras = 0;
	char* palabra = new char[100];
	char* letrasContenidas = new char[100];
	int cantLetrasDistintas = 0;
	char abc[27] = "abcdefghijklmnopqrstuvwxyz";
	// for(int LETRA = 0; ; LETRA++){
	int LETRA = 0;
	while(1){
		if(cadena[LETRA] == ' ' || !cadena[LETRA]){
			cout << "PALABRA = \t" << palabra << endl;
			cout << "CANTIDAD DE LETRAS = \t" << cantidadLetras << endl;

			palabra = new char[100];
			cantidadPalabras++;
			cantidadLetras = 0;
		}else{
			palabra[cantidadLetras] = cadena[LETRA];	
			cantidadLetras++;
		}
		if(!cadena[LETRA]){
			break;
		}
		LETRA++;
	}
	cout << "LAS LETRAS ";
	for(int t = 0; t < 26; t++){
		if(!indexOf(cadena, abc[t])){
			cout << abc[t] << ", ";
		}
	}
	cout << "NO ESTAN EN LA CADENA" << endl;
	for(int i = 0; cadena[i]; i++){
		if(cadena[i] != ' ' && !indexOf(letrasContenidas, cadena[i])){
			letrasContenidas[cantLetrasDistintas] = cadena[i];
			cantLetrasDistintas++;
			cout << "LETRA = " << cadena[i] << "\tTOTAL DE VECES REPETIDAS = " << indexOf(cadena, cadena[i]) << endl;
		}
	}
	// char* abc = 
	cout << "CANTIDAD DE PALABRAS = " << cantidadPalabras - 1 << endl;
}
char charToMorse(char* clave){
	char todasClaves[27][6] = {
		".-**A",	"-...B",	"-.-.C",	"-..*D",
		".***E",	"..-.F",	"--.*G",	"....H",
		"..**I",	".---J",	"-.-*K",	".-..L",
		"--**M",	"-.**N",	"---*O", 	".--.P",
		"--.-Q",	".-.*R",	"...*S",	"-***T",
		"..-*U",	"...-V",	".--*W",	"-..-X",
		"-.--Y",	"--..Z"	
	};
	for(int i = 0; i < 26; i++){
		if(compararString(todasClaves[i], clave)){
			return todasClaves[i][4];
		}
	}
}
bool compararString(char cadena1[6], char* cadena2){
	for(int i = 0; i < 4; i++){
		if(cadena1[i] != cadena2[i]){
			return false;
		}
	}
	return true;
}
//the quick brown fox jumps over the lazy dog
//el viejo senor gomez pedia queso, kiwi y habas, pero le ha tocado un saxofon
//grumpy wizards make toxic brew for the evil queen and jack