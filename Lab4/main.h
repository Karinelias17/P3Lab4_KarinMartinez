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
			if (pos + i == elementos.size()-1) {
				cout << "0 -> " << i << endl;
				pos = elementos.size() + 1;
			}
			else {
				for (j = 1; j <= elementos[i];j++) {
					if (j + i == elementos.size()-1) {
						cout << "0 -> " << i << " -> " << i + j << endl;
						pos = elementos.size() + 1;
					}
					else {
						
						for (k = 1; k <= elementos[i + j];k++) {
							if (j + i + k == elementos.size()-1) {
								cout << "0 -> " << i << " -> " << i + j <<" -> " << i+j+k << endl;
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
		}
	}
}
