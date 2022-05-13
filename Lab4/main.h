#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
int* fillArray(int* a, int tamano, int limite) {
	srand(time(NULL));
	for (int i = 0; i < tamano;i++) {
		a[i] = 1 + rand() % ((limite + 1) - 1);
	}
	return a;
}
void imprimirArray(int* a, int tamano) {
	for (int i = 0; i < tamano;i++) {
		cout << "[" << a[i] << "] ";
	}
	cout << endl;
}
void mostrar_vector(const vector<int> elementos) {
	for (int elemento : elementos) cout << "[" << elemento << "]";
	cout << endl;
}
int Saltos(const vector<int>& elementos, int pos = 0) {
	int i, j, k;
	while (pos <= elementos.size()) {
		for (i = 1; i <= elementos[0];i++) {
			if (pos + i == elementos.size() - 1) {
				cout << "0 -> " << i << endl;
				pos = elementos.size() + 1;
			}
			else {
				for (j = 1; j <= elementos[i];j++) {
					if (j + i == elementos.size() - 1) {
						cout << "0 -> " << i << " -> " << i + j << endl;
						pos = elementos.size() + 1;
					}
					else {

						for (k = 1; k <= elementos[i + j];k++) {
							if (j + i + k == elementos.size() - 1) {
								cout << "0 -> " << i << " -> " << i + j << " -> " << i + j + k << endl;
								pos = elementos.size() + 1;
							}
							else if (i == elementos.size() && j == elementos.size() && k == elementos.size()) {
								cout << "No fue posible alcanzar el final :(";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
int main() {
	int opcion = 1;
	while (opcion != 0) {
		cout << "1. ORDENAMIENTO SIMPLE\n2. SALTOS\n3. SORTEO\n0. SALIR: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			int tamano, limite = 99;
			int* arregloPtr = NULL;
			cout << "Ingrese el size del arreglo : ";
			cin >> tamano;
			arregloPtr = new int[tamano];
			arregloPtr = fillArray(arregloPtr, tamano, limite);
			cout << "Unsorted:" << endl;
			imprimirArray(arregloPtr, tamano);
			int comparacion, pos = 0;
			for (int i = 0;i < tamano;i++) {
				comparacion = 100;
				for (int j = i;j < tamano;j++) {
					if (arregloPtr[j] < comparacion) {
						comparacion = arregloPtr[j];
						pos = j;
					}
				}
				arregloPtr[pos] = arregloPtr[i];
				arregloPtr[i] = comparacion;
				cout << "Iteracion #" << i + 1 << ":" << endl;
				imprimirArray(arregloPtr, tamano);
			}

		}
		case 2: {
			int num = 0;
			vector<int> ent1(0);
			cout << "Ingreso de numeros, ingrese -1 para salir" << endl;
			while (num >= 0) {
				cout << "Ingrese un numero: ";
				cin >> num;
				if (num >= 0) {
					ent1.push_back(num);
				}
			}
			cout << "vector: ";
			mostrar_vector(ent1);
			Saltos(ent1);
		}
		case 3: {
			int contador = 0,contador2=0, limite, Nganador, pos;
			string participante;
			vector<string> participantes(0);
			vector<string> participantes2(0);
			cout << "Ingreso de participantes, ingrese 0 para detener" << endl;
			while (participante != "0") {
				cout << "Ingrese el nombre #" << contador << ": ";
				cin >> participante;
				if (participante != "0") {
					participantes.push_back(participante);
				}
				contador++;
			}
			cout << "Numero maximo en random: ";
			cin >> limite;
			int* arreglo2Ptr = NULL;
			arreglo2Ptr = new int[participantes.size()];
			arreglo2Ptr = fillArray(arreglo2Ptr, participantes.size(), limite);
			
			participante = "0";
			srand(time(NULL));
			Nganador = 1 + rand() % ((limite + 1) - 1);
			contador = 1;
			while (participante == "0") {
				int* arregloPtr = NULL;
				arregloPtr = new int[participantes.size()];
				arregloPtr = arreglo2Ptr;
				int comparacion = limite;
				cout << "Ronda " << contador << "(Numero magico: " << Nganador << "):" << endl;
				for (int i = 0;i < participantes.size();i++) {
					cout << participantes[i] << " -> " << arregloPtr[i] << endl;
				}
				contador2 = 0;
				for (int i = 0;i < participantes.size();i++){
					if (arregloPtr[i] == Nganador) {
						participante = participantes[i];
						contador2++;
						pos = i;
					}
				}
				if (contador2 == 1) {
					cout << "Ganador/a:\n" << participantes[pos] << " -> " << arregloPtr[pos]<< endl;
				}
				else if (contador2 == 0) {
					cout << "Ganador/a:" << endl;
					for (int i = 0;i < participantes.size();i++) {
						if (comparacion > abs(Nganador - arregloPtr[i])) {
							comparacion = abs(Nganador - arregloPtr[i]);
						}
					}
					for (int i = 0;i < participantes.size();i++) {
						if (abs(Nganador - arregloPtr[i]) == comparacion){
							participantes2.push_back(participantes[i]);
						}
					}
					int* arreglo2Ptr = NULL;
					arreglo2Ptr = new int[participantes2.size()];

					for (int i = 0;i < participantes.size();i++) {
						if (abs(Nganador - arregloPtr[i]) == comparacion) {
							arreglo2Ptr[contador2] = arregloPtr[i];
							contador2++;
						}
					}

					for (int i = 0;i < participantes2.size();i++) {
						cout << participantes2[i] << " -> " << arreglo2Ptr[i];
					}
					contador2 = 0;
					comparacion = limite;
					participantes = participantes2;
				}
				else if (contador > 1) {
					for (int i = 0;i < participantes.size();i++) {
						if (arregloPtr[i] == Nganador) {
							participantes2.push_back(participantes[i]);
						}
					}
					int* arreglo2Ptr = NULL;
					arreglo2Ptr = new int[participantes2.size()];
					contador2 = 0;
					for (int i = 0;i < participantes.size();i++) {
						if (arregloPtr[i] == Nganador) {
							arreglo2Ptr[contador2] = arregloPtr[i];
							contador2++;
						}
					}
					for (int i = 0;i < participantes2.size();i++) {
						cout << participantes2[i] << " -> " << arreglo2Ptr[i];
					}
					contador2 = 0;
					comparacion = limite;
					participantes = participantes2;
				}
			}
		}
		}
	}
}
