#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Prototipos de funciones

// Prototipos de utilidad
void cleanConsole();
void pauseProgram(const string &mensaje = "continuar");
template <typename T> T validateOption(const string &);
int validateVectorLength(const string &);
void generateTitle(const string &);
int generateMenu();

// Prototipos de calculo
vector<double> createVector(int);
double calculateMagnitude(const vector<double> &);

int main() {
	bool exit = false;
	int option = 0;
	vector<vector<double>> vectores;

	while (!exit) {
		option = generateMenu();

		switch (option) {
		case 1:
			// Calcular magnitud de un vector
			generateTitle("Calcular magnitud de un vector");
			vectores.push_back(createVector(validateVectorLength("Ingresa la longitud del vector")));
            cout << "La magnitud del vector es: " << calculateMagnitude(vectores[0]) << endl;
			break;
		case 2:
			// Calcular vector unitario
			break;
		case 3:
			// Calcular direccion de un vector
			break;
		case 4:
			// Calcular suma de vectores
			break;
		case 5:
			// Calcular resta de vectores
			break;
		case 6:
			// Calcular producto escalar de vectores
			break;
		case 7:
			// Calcular angulo entre dos vectores
			break;
		case 8:
			// Calcular si dos vectores son ortogonales
			break;
		case 9:
			// Calcular si dos vectores son paralelos
			break;
		case 10:
			// Calcular proyeccion de un vector sobre otro
			break;
		case 11:
			// Calcular producto vectorial o producto cruz
			break;
		case 0:
			exit = true;
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion invalida, por favor ingresa una opcion valida.\n";
			break;
		}

		pauseProgram((exit) ? "salir" : "continuar");

		vectores.clear();
	}

	return 0;
}

// Definición de funciones

// Funciones de utilidad
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
	cout << endl << "Presione una tecla para " << mensaje << " . . .";
	cin.get();
#endif
}

template <typename T> T validateOption(const string &message) {
	int option = 0;

	while (true) {
		cout << message << ": ";

		if (cin >> option) {
			if (cin.peek() == '\n') {
				break;
			}
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Entrada invalida, por favor ingresa un numero valido.\n";
	}

	return option;
}

int validateVectorLength(const string &message) {
	int length = 0;

	while (length < 2) {
		length = validateOption<int>(message);

		if (length < 2) {
			cout << "La longitud del vector debe ser mayor a 1.\n";
		}
	}

	return length;
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
	cout << "[3] Calcular la direccion de un vector" << endl;
	cout << "[4] Calcular la suma de vectores" << endl;
	cout << "[5] Calcular la resta de vectores" << endl;
	cout << "[6] Calcular el producto escalar de vectores" << endl;
	cout << "[7] Calcular el angulo entre dos vectores" << endl;
	cout << "[8] Calcular si dos vectores son ortogonales" << endl;
	cout << "[9] Calcular si dos vectores son paralelos" << endl;
	cout << "[10] Calcular proyeccion de un vector sobre otro" << endl;
	cout << "[11] Calcular el producto vectorial o producto cruz" << endl;
	cout << "[0] Salir" << endl;

	return validateOption<int>("Ingresa una opcion");
}

// Funciones de calculo

vector<double> createVector(int amount) {
	vector<double> vec;
	double value = 0;

	for (int i = 0; i < amount; i++) {
		value = validateOption<double>("Ingresa el valor del vector [" + to_string(i + 1) + "]");

		vec.push_back(value);
	}

	return vec;
}

double calculateMagnitude(const vector<double> &vec) {
	double magnitude = 0;

	for (const auto &i : vec) {
		magnitude += pow(i, 2);
	}

	return sqrt(magnitude);
}