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
int validateVectorLength(const string &, const int minimum = 2);
void generateTitle(const string &);
int generateMenu();

// Prototipos de calculo
vector<double> createVector(int);
double calculateMagnitude(const vector<double> &);
vector<double> unitVector(const vector<double> &);
double radiansToDegrees(double);
double degreesToRadians(double);
void calculateDirection(const vector<double> &);
void vectorAddition(const vector<vector<double>> &);
void vectorSubtraction(const vector<vector<double>> &);
double dotProduct(const vector<vector<double>> &);
double calculateAngleBetweenVectors(const vector<vector<double>> &);
bool orthogonalVector(const vector<vector<double>> &);
bool parallelVector(const vector<vector<double>> &);

int main() {
	bool exit = false;
	int option = 0, lengthvec, vs;
	string message;
	vector<vector<double>> vectores;

	while (!exit) {
		lengthvec = 0;
		vs = 0;
		message = "";
		option = generateMenu();

		switch (option) {
		case 1:
			// Calcular magnitud de un vector
			generateTitle("Calcular magnitud de un vector");
			vectores.push_back(createVector(validateVectorLength("Ingresa la longitud del vector")));
			cout << "La magnitud del vector es: " << calculateMagnitude(vectores[0]) << endl;
			break;
		case 2:
			generateTitle("Calcular si un vector es unitario");
			vectores.push_back(createVector(validateVectorLength("Ingresa la longitud del vector")));
			unitVector(vectores[0]);
			break;
		case 3:
			// Calcular direccion de un vector
			generateTitle("Calcular la direccion de un vector");
			vectores.push_back(createVector(validateVectorLength("Ingresa la longitud del vector")));
			calculateDirection(vectores[0]);
			break;
		case 4:
			// Calcular suma de vectores
			generateTitle("Calcular la suma de vectores");
			vs = validateVectorLength("Ingrese la cantidad de vectores a sumar");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < vs; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			vectorAddition(vectores);
			break;
		case 5:
			// Calcular resta de vectores
			generateTitle("Calcular la resta de vectores");
			vs = validateVectorLength("Ingrese la cantidad de vectores a restar");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < vs; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			vectorSubtraction(vectores);
			break;
		case 6:
			// Calcular producto escalar de vectores
			generateTitle("Calcular el producto escalar de vectores");
			vs = validateVectorLength("Ingrese la cantidad de vectores a multiplicar");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < vs; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			cout << "El producto escalar de los vectores es: " << dotProduct(vectores) << endl;
			break;
		case 7:
			// Calcular angulo entre dos vectores
			generateTitle("Calcular el angulo entre dos vectores");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < 2; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			cout << "El angulo entre los dos vectores es: " << endl;
			cout << calculateAngleBetweenVectors(vectores) << " radianes" << endl;
			cout << radiansToDegrees(calculateAngleBetweenVectors(vectores)) << " grados" << endl;
			break;
		case 8:
			// Calcular si dos vectores son ortogonales
			generateTitle("Calcular si dos vectores son ortogonales");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < 2; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			message = "Los vectores son ";
			message += (orthogonalVector(vectores)) ? "ortogonales" : "no ortogonales";

			cout << message << endl;
			break;
		case 9:
			// Calcular si dos vectores son paralelos
			generateTitle("Calcular si dos vectores son paralelos");
			lengthvec = validateVectorLength("Ingresa la longitud de los vectores");

			for (int i = 0; i < 2; i++) {
				vectores.push_back(createVector(lengthvec));
			}

			message = "Los vectores son ";
			message += (parallelVector(vectores)) ? "paralelos" : "no paralelos";

			cout << message << endl;
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
	T option = 0;

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

int validateVectorLength(const string &message, const int minimum) {
	int length = 0;

	while (length < minimum) {
		length = validateOption<int>(message);

		if (length < minimum) {
			cout << "La longitud del vector debe ser mayor a " << minimum << endl;
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

	cout << "Ingresa los valores del vector" << endl;

	for (int i = 0; i < amount; i++) {
		value = validateOption<double>("Ingresa el valor del vector [" + to_string(i + 1) + "]");

		vec.push_back(value);
	}

	cout << endl;

	return vec;
}

double calculateMagnitude(const vector<double> &vec) {
	double magnitude = 0;

	for (const auto &i : vec) {
		magnitude += pow(i, 2);
	}

	return sqrt(magnitude);
}

vector<double> unitVector(const vector<double> &vec) {
	double magnitude = calculateMagnitude(vec);
	vector<double> uvector;

	if (magnitude == 0) {
		cout << "El vector es un vector nulo, no se puede calcular el vector unitario." << endl;
		return vec;
	}

	if (magnitude == 1) {
		cout << "El vector es un vector unitario." << endl;
		return vec;
	}

	cout << "El vector no es unitario." << endl;
	cout << "Encontrando el vector unitario..." << endl;
	cout << "U =  (";

	for (int i = 0; i < vec.size(); i++) {
		cout << i << "/" << magnitude << ((i < vec.size() - 1) ? ", " : ")");
		uvector.push_back(vec[i] / magnitude);
	}

	cout << endl;
	return uvector;
}

double radiansToDegrees(double radians) { return radians * (180 / M_PI); }
double degreesToRadians(double degrees) { return degrees * (M_PI / 180); }

void calculateDirection(const vector<double> &vec) {
	double magnitude = calculateMagnitude(vec);
	vector<double> uvector;
	double angulo = 0;

	if (magnitude == 0) {
		cout << "El vector es un vector nulo, no se puede calcular la direccion." << endl;
		return;
	}

	uvector = unitVector(vec);

	cout << "\nLa direccion del vector es: " << endl;

	for (size_t i = 0; i < uvector.size(); i++) {
		char letter = 'A' + (i % 26);
		angulo = acos(uvector[i]);

		cout << letter << " = " << angulo << " radianes" << endl;
		cout << letter << " = " << radiansToDegrees(angulo) << " grados" << endl;
		cout << endl;
	}
}

void vectorAddition(const vector<vector<double>> &vectors) {
	vector<double> result = vectors[0];

	for (size_t i = 1; i < vectors.size(); i++) {
		for (size_t j = 0; j < vectors[i].size(); j++) {
			result[j] += vectors[i][j];
		}
	}

	cout << "La suma de los vectores es: (";
	for (const auto &i : result) {
		cout << i << ((&i != &result.back()) ? ", " : ")");
	}

	cout << endl;
}

void vectorSubtraction(const vector<vector<double>> &vectors) {
	vector<double> result = vectors[0];

	for (size_t i = 1; i < vectors.size(); i++) {
		for (size_t j = 0; j < vectors[i].size(); j++) {
			result[j] -= vectors[i][j];
		}
	}

	cout << "La resta de los vectores es: (";
	for (const auto &i : result) {
		cout << i << ((&i != &result.back()) ? ", " : ")");
	}

	cout << endl;
}

double dotProduct(const vector<vector<double>> &vectors) {
	double result = 0;

	for (size_t i = 0; i < vectors.size() - 1; i++) {
		for (size_t j = 0; j < vectors[0].size(); j++) {
			result += vectors[i][j] * vectors[i + 1][j];
		}
	}

	return result;
}

double calculateAngleBetweenVectors(const vector<vector<double>> &vectors) {
	double angle = 0, product = dotProduct(vectors), magnitudes = 1;

	for (const auto &vec : vectors) {
		magnitudes *= calculateMagnitude(vec);
	}

	angle = acos(product / magnitudes);

	return angle;
}

bool orthogonalVector(const vector<vector<double>> &vectors) {
	double angle = calculateAngleBetweenVectors(vectors);

	cout << "El angulo entre los dos vectores es: " << angle << " radianes" << endl;
	angle = radiansToDegrees(angle);
	cout << "El angulo entre los dos vectores es: " << angle << " grados" << endl;

	return (angle == 90);
}

bool parallelVector(const vector<vector<double>> &vectors) {
	double angle = calculateAngleBetweenVectors(vectors);

	cout << "El angulo entre los dos vectores es: " << angle << " radianes" << endl;
	angle = radiansToDegrees(angle);
	cout << "El angulo entre los dos vectores es: " << angle << " grados" << endl;

	return (angle == 0);
}