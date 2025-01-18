#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
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

    Telefon() : codFabricatie(1000) {
        this->pret = 3000;
        this->nrStocari = 3;
        this->dimensiuneStocare = NULL;
        this->marca = "Apple";
    }

    // Constructor cu parametri
    Telefon(float pret, string marca, int cod, int nrStocari) : codFabricatie(cod) {
        this->pret = pret;
        this->marca = marca;
        this->nrStocari = nrStocari;
        this->dimensiuneStocare = new int[nrStocari];
        for (int i = 0; i < nrStocari; i++) {
            this->dimensiuneStocare[i] = 280;
        }
    }

    // Destructor
    ~Telefon() {
        if (this->dimensiuneStocare) {
            delete[] this->dimensiuneStocare;
        }
    }

   
    static int getAnulFabricatiei() {
        return anulFabricatiei;
    }

    // Funcție de afisare
    void afisare() const {
        cout << "Telefon marca: " << marca << ", Pret: " << pret << ", Nr. Stocari: " << nrStocari << ", Cod Fabricatie: " << codFabricatie << endl;
    }

   
};

int Telefon::anulFabricatiei = 2022;


class Laptop {
private:
    string model;
    char* producator;
    float pret;
    const int memorieRAM;
    static string procesor;

public:

    Laptop() : memorieRAM(8) {
        this->model = "Asus";
        this->pret = 5000;
        this->producator = nullptr;
    }

    // Constructor cu parametri
    Laptop(float pret, string model, int memorie) : memorieRAM(memorie) {
        this->pret = pret;
        this->model = model;
        this->producator = new char[strlen("Asus") + 1];
        strcpy_s(this->producator, strlen("Asus") + 1, "Asus");
    }

    // Destructor
    ~Laptop() {
        if (this->producator) {
            delete[] this->producator;
        }
    }

    
    static string getProcesor() {
        return procesor;
    }

    // Funcție de afisare
    void afisare() const {
        cout << "Laptop model: " << model << ", Pret: " << pret << ", Memorie RAM: " << memorieRAM << ", Producator: " << (producator ? producator : "N/A") << endl;
    }

    
};

string Laptop::procesor = "Intel i7";


class Tableta {
private:
    const float dimensiuneEcran;
    int capacitateBaterie;
    bool suportSim;
    static int anLansare;
    char* nume;

public:

    Tableta() : dimensiuneEcran(18) {
        this->capacitateBaterie = 100;
        this->suportSim = true;
        this->nume = nullptr;
    }

    // Constructor cu parametri
    Tableta(bool suportSim, int capacitateBaterie, float dimensiune) : dimensiuneEcran(dimensiune) {
        this->suportSim = suportSim;
        this->capacitateBaterie = capacitateBaterie;
        this->nume = new char[strlen("Samsung") + 1];
        strcpy_s(this->nume, strlen("Samsung") + 1, "Samsung");
    }

    // Destructor
    ~Tableta() {
        if (this->nume) {
            delete[] this->nume;
        }
    }

    
    static int getAnLansare() {
        return anLansare;
    }

    // Funcție de afisare
    void afisare() const {
        cout << "Tableta nume: " << (nume ? nume : "N/A") << ", Capacitate baterie: " << capacitateBaterie << ", Suport SIM: " << (suportSim ? "Da" : "Nu") << endl;
    }

};

int Tableta::anLansare = 2023;


class Magazin {
private:
    string numeMagazin;
    vector<Telefon*> telefoane;
    vector<Laptop*> laptopuri;
    vector<Tableta*> tablete;

public:
    // Constructor
    Magazin(string numeMagazin) {
        this->numeMagazin = numeMagazin;
    }

    // Destructor
    ~Magazin() {
        for (auto t : telefoane) delete t;
        for (auto l : laptopuri) delete l;
        for (auto T : tablete) delete T;
    }

    string getNumeMagazin() const {
        return numeMagazin;
    }

    void setNumeMagazin(const string& nume) {
        numeMagazin = nume;
    }

    friend ostream& operator<<(ostream& os, const Magazin& magazin) {
        os << "Magazin: " << magazin.numeMagazin << endl;
        os << "Telefoane: " << endl;
        for (auto t : magazin.telefoane) {
            t->afisare();
        }
        os << "Laptopuri: " << endl;
        for (auto l : magazin.laptopuri) {
            l->afisare();
        }
        os << "Tablete: " << endl;
        for (auto T : magazin.tablete) {
            T->afisare();
        }
        return os;
    }

    void operator+=(Telefon* telefon) {
        telefoane.push_back(telefon);
    }

    void operator+=(Laptop* laptop) {
        laptopuri.push_back(laptop);
    }

    void operator+=(Tableta* tableta) {
        tablete.push_back(tableta);
    }





    // Adaugare produse
    void adaugaTelefon(Telefon* telefon) {
        telefoane.push_back(telefon);
    }

    void adaugaLaptop(Laptop* laptop) {
        laptopuri.push_back(laptop);
    }

    void adaugaTableta(Tableta* tableta) {
        tablete.push_back(tableta);
    }

    // Functie de afisare
    void afisareProduse() const {
        cout << "Produse in magazinul " << numeMagazin << ":\n";
        for (auto t : telefoane) t->afisare();
        for (auto l : laptopuri) l->afisare();
        for (auto T : tablete) T->afisare();
    }

    
    string getNumeMagazin() const { return numeMagazin; }
    void setNumeMagazin(const string& nume) { numeMagazin = nume; }
};

int main() {
    Telefon* telefon1 = new Telefon(3500, "Samsung", 1001, 4);
    Laptop* laptop1 = new Laptop(6000, "Dell", 16);
    Tableta* tableta1 = new Tableta(true, 120, 10);


    Magazin magazin("ElectroMag");
    magazin.adaugaTelefon(telefon1);
    magazin.adaugaLaptop(laptop1);
    magazin.adaugaTableta(tableta1);
    magazin.afisareProduse();



    return 0;
}
