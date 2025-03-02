#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Prototipos de funciones
void cleanConsole();
void pauseProgram(const string &mensaje = "continuar");
int validateOption(const string &);
void generateTitle(const string &);
int generateMenu();

int main() {
	cout << "Hola Mundo!" << endl;

	cout << "\nPresione una tecla para continuar...";
	cin.get();

	return 0;
}

// Definición de funciones

void cleanConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pauseProgram(const string &mensaje) {
#ifdef _WIN32
	system("pause");
#else
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "Presione una tecla para " << mensaje << "...";
	cin.get();
#endif
}

int validateOption(const string &message) {
    
}

void generateTitle(const string &titulo) {
	const string lineas(titulo.length() * 2, '=');

	cleanConsole();
	cout << lineas << endl;
	cout << setw(titulo.length() + titulo.length() / 2) << titulo << endl;
	cout << lineas << endl << endl;
}

int generateMenu() {
	generateTitle("Menu de opciones");

	cout << "[1] Calcular Magnitud de un vector" << endl;
	cout << "[2] Calcular si un vector es unitario" << endl;
	cout << "[3] Calcular la dirección de un vector" << endl;
	cout << "[4] Calcular la suma de vectores" << endl;
	cout << "[5] Calcular la resta de vectores" << endl;
	cout << "[6] Calcular el producto escalar de vectores" << endl;
	cout << "[7] Calcular el angulo entre dos vectores" << endl;
	cout << "[8] Calcular si dos vectores son ortogonales" << endl;
	cout << "[9] Calcular si dos vectores son paralelos" << endl;
	cout << "[10] Calcular proyeccion de un vector sobre otro" << endl;
	cout << "[11] Calcular el producto vectorial o producto cruz" << endl;
}