#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
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
        this->dimensiuneStocare = nullptr;
        this->marca = "Apple";
    }

    Telefon(float pret, string marca, int cod, int nrStocari) : codFabricatie(cod) {
        this->pret = pret;
        this->marca = marca;
        this->nrStocari = nrStocari;
        this->dimensiuneStocare = new int[nrStocari];
        for (int i = 0; i < nrStocari; i++) {
            this->dimensiuneStocare[i] = 280;
        }
    }

    Telefon(const Telefon& t) : codFabricatie(t.codFabricatie) {
        this->pret = t.pret;
        this->marca = t.marca;
        this->nrStocari = t.nrStocari;
        this->dimensiuneStocare = new int[t.nrStocari];
        for (int i = 0; i < t.nrStocari; i++) {
            this->dimensiuneStocare[i] = t.dimensiuneStocare[i];
        }
    }

    Telefon& operator=(const Telefon& t) {
        if (this != &t) {
            delete[] this->dimensiuneStocare;
            this->pret = t.pret;
            this->marca = t.marca;
            this->nrStocari = t.nrStocari;
            this->dimensiuneStocare = new int[t.nrStocari];
            for (int i = 0; i < t.nrStocari; i++) {
                this->dimensiuneStocare[i] = t.dimensiuneStocare[i];
            }
        }
        return *this;
    }

    bool operator==(const Telefon& t) {
        return (this->pret == t.pret && this->marca == t.marca && this->nrStocari == t.nrStocari);
    }

    Telefon& operator++() {
        this->pret += 500;
        return *this;
    }

    Telefon operator+(const Telefon& t) {
        Telefon temp = *this;
        temp.pret += t.pret;
        return temp;
    }

    ~Telefon() {
        delete[] dimensiuneStocare;
    }

    static int getAnulFabricatiei() {
        return anulFabricatiei;
    }

    void afisare() {
        cout << "Marca: " << marca << ", Pret: " << pret
            << ", Cod fabricatie: " << codFabricatie
            << ", Nr. stocari: " << nrStocari << endl;
    }

    friend void afiseazaAnulFabricatiei(const Telefon& t);

    friend istream& operator>>(istream& in, Telefon& t) {
        cout << "Introduceti marca: ";
        in >> t.marca;
        cout << "Introduceti pretul: ";
        in >> t.pret;
        cout << "Introduceti numarul de stocari: ";
        in >> t.nrStocari;
        delete[] t.dimensiuneStocare;
        t.dimensiuneStocare = new int[t.nrStocari];
        for (int i = 0; i < t.nrStocari; i++) {
            cout << "Introduceti dimensiunea stocarii " << (i + 1) << ": ";
            in >> t.dimensiuneStocare[i];
        }
        return in;
    }
};

int Telefon::anulFabricatiei = 2023;

void afiseazaAnulFabricatiei(const Telefon& t) {
    cout << "Anul fabricatiei telefonului este: " << t.anulFabricatiei << endl;
}

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

    Laptop(float pret, string model, int memorie) : memorieRAM(memorie) {
        this->pret = pret;
        this->model = model;
        this->producator = new char[strlen("Asus") + 1];
        strcpy_s(this->producator, strlen("Asus") + 1, "Asus");
    }

    Laptop(const Laptop& l) : memorieRAM(l.memorieRAM) {
        this->model = l.model;
        this->pret = l.pret;
        this->producator = new char[strlen(l.producator) + 1];
        strcpy_s(this->producator, strlen(l.producator) + 1, l.producator);
    }

    Laptop& operator=(const Laptop& l) {
        if (this != &l) {
            delete[] this->producator;
            this->model = l.model;
            this->pret = l.pret;
            this->producator = new char[strlen(l.producator) + 1];
            strcpy_s(this->producator, strlen(l.producator) + 1, l.producator);
        }
        return *this;
    }

    bool operator==(const Laptop& l) {
        return (this->pret == l.pret && this->model == l.model);
    }

    Laptop& operator++() {
        this->pret += 1000;
        return *this;
    }

    Laptop operator+(const Laptop& l) {
        Laptop temp = *this;
        temp.pret += l.pret;
        return temp;
    }

    ~Laptop() {
        delete[] producator;
    }

    static string getProcesor() {
        return procesor;
    }

    void afisare() {
        cout << "Model: " << model << ", Pret: " << pret
            << ", Memorie RAM: " << memorieRAM << "GB" << endl;
    }

    friend void afiseazaProcesorLaptop(const Laptop& l);

    friend istream& operator>>(istream& in, Laptop& l) {
        cout << "Introduceti modelul: ";
        in >> l.model;
        cout << "Introduceti pretul: ";
        in >> l.pret;
        cout << "Introduceti memorie RAM (GB): ";
        in >> l.memorieRAM;
        l.producator = new char[strlen("Asus") + 1];
        strcpy_s(l.producator, strlen("Asus") + 1, "Asus");
        return in;
    }
};

string Laptop::procesor = "Intel Core i7";

void afiseazaProcesorLaptop(const Laptop& l) {
    cout << "Procesorul laptopului este: " << l.procesor << endl;
}

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

    Tableta(bool suportSim, int capacitateBaterie, float dimensiune) : dimensiuneEcran(dimensiune) {
        this->suportSim = suportSim;
        this->capacitateBaterie = capacitateBaterie;
        this->nume = new char[strlen("Samsung") + 1];
        strcpy_s(this->nume, strlen("Samsung") + 1, "Samsung");
    }

    Tableta(const Tableta& t) : dimensiuneEcran(t.dimensiuneEcran) {
        this->capacitateBaterie = t.capacitateBaterie;
        this->suportSim = t.suportSim;
        this->nume = new char[strlen(t.nume) + 1];
        strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
    }

    Tableta& operator=(const Tableta& t) {
        if (this != &t) {
            delete[] this->nume;
            this->capacitateBaterie = t.capacitateBaterie;
            this->suportSim = t.suportSim;
            this->nume = new char[strlen(t.nume) + 1];
            strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
        }
        return *this;
    }

    bool operator==(const Tableta& t) {
        return (this->capacitateBaterie == t.capacitateBaterie && this->suportSim == t.suportSim);
    }

    Tableta& operator++() {
        this->capacitateBaterie += 10;
        return *this;
    }

    Tableta operator+(const Tableta& t) {
        Tableta temp = *this;
        temp.capacitateBaterie += t.capacitateBaterie;
        return temp;
    }

    ~Tableta() {
        delete[] nume;
    }

    static int getAnLansare() {
        return anLansare;
    }

    void afisare() {
        cout << "Nume: " << (nume ? nume : "N/A") << ", Capacitate baterie: " << capacitateBaterie
            << "%, Suport SIM: " << (suportSim ? "Da" : "Nu") << endl;
    }

    friend void afiseazaAnLansare(const Tableta& t);

    friend istream& operator>>(istream& in, Tableta& t) {
        cout << "Introduceti numele: ";
        in.ignore(); // pentru a ignora caracterele din buffer
        getline(in, t.nume);  // citire corecta pentru string
        cout << "Introduceti capacitatea bateriei (%): ";
        in >> t.capacitateBaterie;
        cout << "Introduceti suport SIM (0 - nu, 1 - da): ";
        in >> t.suportSim;
        return in;
    }
};

int Tableta::anLansare = 2022;

void afiseazaAnLansare(const Tableta& t) {
    cout << "Anul lansarii tabletei este: " << t.anLansare << endl;
}

int main() {
    const int N = 3;

    Telefon telefoane[N];
    Laptop laptopuri[N];
    Tableta tablete[N];

    cout << "Introduceti date pentru telefoane:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> telefoane[i];
    }

    cout << "Introduceti date pentru laptopuri:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> laptopuri[i];
    }

    cout << "Introduceti date pentru tablete:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> tablete[i];
    }

    cout << "\nTelefoane:" << endl;
    for (int i = 0; i < N; i++) {
        telefoane[i].afisare();
    }

    cout << "\nLaptopuri:" << endl;
    for (int i = 0; i < N; i++) {
        laptopuri[i].afisare();
    }

    cout << "\nTablete:" << endl;
    for (int i = 0; i < N; i++) {
        tablete[i].afisare();
    }

    const int M = 2;
    Laptop matriceLaptopuri[M][M];

    cout << "\nIntroduceti date pentru matricea de laptopuri:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriceLaptopuri[i][j];
        }
    }

    cout << "\nMatrice de laptopuri:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            matriceLaptopuri[i][j].afisare();
        }
    }

    return 0;
}
