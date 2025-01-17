#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Telefon {
private:
	const int codFabricatie;
	static int anulFabricatiei;
	float pret;
	int nrStocari;
	int* dimensiuneStocare;
	string marca;

public:

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

	// Destructor
	~Telefon() {
		if (this->dimensiuneStocare) {
			delete[] this->dimensiuneStocare;
		}
	}


	//geteri

	int getCodFabricatiei() {
		return this->codFabricatie;
	}

	float getPret() {
		return this->pret;
	}

	int getNrStocari() {
		return this->nrStocari;
	}

	int* getDimensiuneStocare() {
		return this->dimensiuneStocare;
	}

	string getMarca() {
		return this->marca;
	}

	//seteri

	void setPret(float pret) {
		this->pret = pret;
	}

	

	void setMarca(string marca) {
		this->marca = marca;
	}

	void setNrStocari(int nrStocari) {
		if (this->dimensiuneStocare) {
			delete[] this->dimensiuneStocare;
		}
		this->nrStocari = nrStocari;
		this->dimensiuneStocare = new int[nrStocari];
	}


	//fct globala

	void modificaPret(Telefon& t, float pretNou) {
		t.pret = pretNou;
		cout << "Pretul telefonului a fost modificat la " << t.pret << " lei." << endl;
	}



	//functie statica

	static int getAnulFabricatiei() {
		return Telefon::anulFabricatiei;
	}

	void afisare() const{
		cout << "Codul Fabricatiei:" << this->codFabricatie << endl;
		cout << " An fabricatie: " << this->anulFabricatiei << endl;
		cout << "Pretul: " << this->pret << endl;
		cout << "Numarul de stocari: " << this->nrStocari << endl;
		cout << "Dimensiune stocare:" << this->dimensiuneStocare << endl;
		cout << "Marca:" << this->marca << endl;
	}

	friend void modificaPret(Telefon& t, float pretNou);
};

int Telefon::anulFabricatiei = 2017;


class Laptop {
private:
	string model;
	char* producator;
	float pret;
	const int memorieRAM;
	static string procesor;

public:
	
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


	// Destructor
	~Laptop() {
		if (this->producator) {
			delete[] this->producator;
		}
	}


	//geteri

	string getModel() {
		return this->model;
	}

	char* getProducator()  {
		return this->producator; 
	}

	float getPret() {
		return this->pret;
	}

	int getMemorieRAM()  { 
		return this->memorieRAM;
	}

	//seteri

	void setModel(string model) {
		this->model = model; 
	}

	void setProducator(const char* producator) {
		if (this->producator) delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	void setPret(float pret) { 
		this->pret = pret; 
	}

	//functie statica

	static string getProcesor() {
		return Laptop::procesor;
	}


	void afisare() const {
		cout << "Modelul:" << this->model << endl;
		cout << " Producatorul este: " << this->producator << endl;
		cout << "Pretul: " << this->pret << endl;
		cout << "Memorie RAM: " << this->memorieRAM << endl;
		cout << "Procesor:" << this->procesor << endl;

	}

};
string Laptop::procesor = "Core";


class Tableta {
private:

	const float dimensiuneEcran;
	int capacitateBaterie;
	bool suportSim;
	static int anLansare;
	char* nume;

public:

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

	// Destructor
	~Tableta() {
		if (this->nume) {
			delete[] this->nume;
		}
	}

	//geteri

	int getCapacitateBaterie() { 
		return this->capacitateBaterie;
	}

	bool getSuportSim() {
		return this->suportSim; 
	}

	char* getNume() { 
		return this->nume; 
	}

	float getDimensiuneEcran() { 
		return this->dimensiuneEcran; 
	}

	//seteri
	void setCapacitateBaterie(int capacitateBaterie) {
		this->capacitateBaterie = capacitateBaterie;
	}

	void setSuportSim(bool suportSim) {
		this->suportSim = suportSim; 
	}

	void setNume(const char* nume) {
		if (this->nume) delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	//fct statica

	static int getAnLansare() {
		return Tableta::anLansare;
	}


	void afisare() const {
		cout << "Dimensiune Ecran:" << this->dimensiuneEcran << endl;
		cout << " Capacitatea Bateriei: " << this->capacitateBaterie << endl;
		cout << "Are suport Sim? " << this->suportSim << endl;
		cout << "Anul Lansarii: " << this->anLansare << endl;
		cout << "Nume:" << this->nume << endl;

	}

};

int Tableta::anLansare = 2020;

int main() {
	Telefon t1;
	t1.afisare();
	cout << endl << endl;


	Laptop laptop1;
	laptop1.afisare();
	cout << endl << endl;

	Tableta tableta1;
	tableta1.afisare();
	cout << endl << endl;

	cout << "Apelam functia modificaPret:" << endl;
	modificaPret(t1, 2500);
	t1.afisare();

	cout << t1.getPret() << endl;
	cout << t1.getNrStocari() << endl;
	cout << t1.getMarca() << endl;
	cout << t1.getDimensiuneStocare() << endl;

	t1.setPret(3500);
	t1.setMarca("Samsung");

	Tableta tableta2(true, 100, 30);
	tableta2.afisare();

	Tableta tableta3 = tableta2;
	tableta3.afisare();
	cout << endl << endl;
	

	return 0;

}






