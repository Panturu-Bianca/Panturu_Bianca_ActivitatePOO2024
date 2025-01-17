#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Telefon {
public:
	const int codFabricatie;
	static int anulFabricatiei;
	float pret;
	int nrStocari;
	int* dimensiuneStocare;
	string marca;

	//constr fara parametrii

	Telefon() :codFabricatie(1000) {
		this->pret = 3000;
		this->nrStocari = 3;
		this->dimensiuneStocare = NULL;
		this->marca = "Apple";

	}

	//constr parametrii

	Telefon(float pret, string marca, int cod, int nrStocari) :codFabricatie(cod) {
		this->pret = pret;
		this->marca = marca;
		this->nrStocari = nrStocari;
		this->dimensiuneStocare = new int[nrStocari];
		for (int i = 0; i < nrStocari; i++) {
			this->dimensiuneStocare[i] = 280;

		}

	}

	//constr copiere

	Telefon(const Telefon& t) :codFabricatie(t.codFabricatie) {
		this->pret = t.pret;
		this->nrStocari = t.nrStocari;
		this->dimensiuneStocare = new int[nrStocari];
		for (int i = 0; i < t.nrStocari; i++) {
			dimensiuneStocare[i] = t.dimensiuneStocare[i];
		}
		this->marca = t.marca;
	}


	//functie statica

	static int getAnulFabricatiei() {
		return Telefon::anulFabricatiei;
	}

	void afisare() {
		cout << "Codul Fabricatiei:" << this->codFabricatie << endl;
		cout << " An fabricatie: " << this->anulFabricatiei << endl;
		cout << "Pretul: " << this->pret << endl;
		cout << "Numarul de stocari: " << this->nrStocari << endl;
		cout << "Dimensiune stocare:" << this->dimensiuneStocare << endl;
		cout << "Marca:" << this->marca << endl;
	}

};

int Telefon::anulFabricatiei = 2017;


class Laptop {
public:
	string model;
	char* producator;
	float pret;
	const int memorieRAM;
	static string procesor;

	//constr fara parametrii

	Laptop() :memorieRAM(8) {
		this->model = "Asus";
		this->pret = 5000;
		this->producator = NULL;

	}

	//constr patrametrii

	Laptop(float pret, string model, int memorie) : memorieRAM(memorie) {
		this->pret = pret;
		this->model = model;
		this->producator = new char[strlen("Asus") + 1];
		strcpy_s(this->producator, strlen("Asus") + 1, "Asus");

	}

	//constr copiere


	Laptop(const Laptop& l) :memorieRAM(l.memorieRAM) {
		this->pret = l.pret;
		this->model = l.model;
		this->producator = new char[strlen(l.producator) + 1];
		strcpy_s(this->producator, strlen(l.producator) + 1, l.producator);
	}

	static string getProcesor() {
		return Laptop::procesor;
	}


	void afisare() {
		cout << "Modelul:" << this->model << endl;
		cout << " Producatorul este: " << this->producator << endl;
		cout << "Pretul: " << this->pret << endl;
		cout << "Memorie RAM: " << this->memorieRAM << endl;
		cout << "Procesor:" << this->procesor << endl;

	}

};
string Laptop::procesor = "Core";


class Tableta {
public:

	const float dimensiuneEcran;
	int capacitateBaterie;
	bool suportSim;
	static int anLansare;
	char* nume;

	// constructor fara parametrii

	Tableta() :dimensiuneEcran(18) {
		this->capacitateBaterie = 100;
		this->suportSim = true;
		this->nume = NULL;

	}

	//constr parametrii

	Tableta(bool suportSim, int capacitateBaterie, float dimensiune) :dimensiuneEcran(dimensiune) {
		this->suportSim = suportSim;
		this->capacitateBaterie = capacitateBaterie;
		this->nume = new char[strlen("Samsung") + 1];
		strcpy_s(this->nume, strlen("Samsung") + 1, "Samsung");


	}

	// constr copiere

	Tableta(const Tableta& T) :dimensiuneEcran(T.dimensiuneEcran) {
		this->suportSim = T.suportSim;
		this->capacitateBaterie = T.capacitateBaterie;
		this->nume = new char[strlen(T.nume) + 1];
		strcpy_s(this->nume, strlen(T.nume) + 1, T.nume);
	}

	static int getAnLansare() {
		return Tableta::anLansare;
	}


	void afisare() {
		cout << "Dimensiune Ecran:" << this->dimensiuneEcran << endl;
		cout << " Capacitatea Bateriei: " << this->capacitateBaterie << endl;
		cout << "Are suport Sim? " << this->suportSim << endl;
		cout << "Anul Lansarii: " << this->anLansare << endl;
		cout << "Nume:" << this->nume << endl;

	}

};

int Tableta::anLansare = 2020;

int main() {
	cout << "Constructorii fara parametri pentru cele trei clase:" << endl;
	Telefon t;
	t.afisare();
	Laptop l;
	l.afisare();
	Tableta T;
	T.afisare();
	cout << endl << endl << endl;

	cout << "Constructorii cu parametri pentru cele trei clase:" << endl;
	Telefon t2(6000, "Huawei", 5, 73);
	t2.afisare();
	Laptop l2(7000, "Asus", 500);
	l2.afisare();
	Tableta T2(true, 100, 21);
	T2.afisare();

	return 0;

}






