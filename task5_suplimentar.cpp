#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
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
    Telefon() : codFabricatie(1000) {
        pret = 3000;
        nrStocari = 3;
        dimensiuneStocare = nullptr;
        marca = "Apple";
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
            if (this->dimensiuneStocare) {
                delete[] this->dimensiuneStocare;
            }
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

    bool operator==(const Telefon& t) const {
        return (this->marca == t.marca && this->pret == t.pret && this->nrStocari == t.nrStocari);
    }

    Telefon& operator++() { 
        this->pret += 100;
        return *this;
    }

    Telefon operator+(const Telefon& t) const {
        Telefon temp;
        temp.pret = this->pret + t.pret;
        temp.marca = this->marca + "-" + t.marca;
        temp.nrStocari = this->nrStocari + t.nrStocari;
        return temp;
    }

    ~Telefon() {
        if (dimensiuneStocare) {
            delete[] dimensiuneStocare;
        }
    }

    void afisare() const {
        cout << "Telefon marca: " << marca << ", Pret: " << pret << ", Nr. Stocari: " << nrStocari
            << ", Cod Fabricatie: " << codFabricatie << endl;
    }

    friend istream& operator>>(istream& in, Telefon& t);
    friend ostream& operator<<(ostream& out, const Telefon& t);
};

int Telefon::anulFabricatiei = 2022;

istream& operator>>(istream& in, Telefon& t) {
    cout << "Introduceti marca: ";
    in >> t.marca;
    cout << "Introduceti pretul: ";
    in >> t.pret;
    cout << "Introduceti numarul de stocari: ";
    in >> t.nrStocari;
    if (t.dimensiuneStocare) {
        delete[] t.dimensiuneStocare;
    }
    t.dimensiuneStocare = new int[t.nrStocari];
    for (int i = 0; i < t.nrStocari; i++) {
        cout << "Introduceti dimensiunea stocarii " << i + 1 << ": ";
        in >> t.dimensiuneStocare[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Telefon& t) {
    out << "Telefon marca: " << t.marca << ", Pret: " << t.pret << ", Nr. Stocari: " << t.nrStocari
        << ", Cod Fabricatie: " << t.codFabricatie << endl;
    return out;
}


class Laptop {
private:
    string model;
    float pret;
    int memorieRAM;

public:
    Laptop() {
        model = "Default";
        pret = 0.0;
        memorieRAM = 0;
    }

    Laptop(string model, float pret, int memorieRAM) {
        this->model = model;
        this->pret = pret;
        this->memorieRAM = memorieRAM;
    }

    Laptop& operator=(const Laptop& l) {
        if (this != &l) {
            this->model = l.model;
            this->pret = l.pret;
            this->memorieRAM = l.memorieRAM;
        }
        return *this;
    }

    bool operator==(const Laptop& l) const {
        return (this->model == l.model && this->pret == l.pret && this->memorieRAM == l.memorieRAM);
    }

    Laptop& operator++() { 
        this->pret += 200;
        return *this;
    }

    Laptop operator+(const Laptop& l) const {
        Laptop temp;
        temp.pret = this->pret + l.pret;
        temp.model = this->model + "-" + l.model;
        temp.memorieRAM = this->memorieRAM + l.memorieRAM;
        return temp;
    }

    void afisare() const {
        cout << "Laptop model: " << model << ", Pret: " << pret << ", Memorie RAM: " << memorieRAM << " GB" << endl;
    }

    friend istream& operator>>(istream& in, Laptop& l);
    friend ostream& operator<<(ostream& out, const Laptop& l);
};

istream& operator>>(istream& in, Laptop& l) {
    cout << "Introduceti modelul: ";
    in >> l.model;
    cout << "Introduceti pretul: ";
    in >> l.pret;
    cout << "Introduceti memoria RAM: ";
    in >> l.memorieRAM;
    return in;
}

ostream& operator<<(ostream& out, const Laptop& l) {
    out << "Laptop model: " << l.model << ", Pret: " << l.pret << ", Memorie RAM: " << l.memorieRAM << " GB" << endl;
    return out;
}


class Tableta {
private:
    bool suportSim;
    int capacitateBaterie;
    float dimensiuneEcran;

public:
    Tableta() {
        suportSim = false;
        capacitateBaterie = 0;
        dimensiuneEcran = 0.0;
    }

    Tableta(bool suportSim, int capacitateBaterie, float dimensiuneEcran) {
        this->suportSim = suportSim;
        this->capacitateBaterie = capacitateBaterie;
        this->dimensiuneEcran = dimensiuneEcran;
    }

    Tableta& operator=(const Tableta& t) {
        if (this != &t) {
            this->suportSim = t.suportSim;
            this->capacitateBaterie = t.capacitateBaterie;
            this->dimensiuneEcran = t.dimensiuneEcran;
        }
        return *this;
    }

    bool operator==(const Tableta& t) const {
        return (this->suportSim == t.suportSim && this->capacitateBaterie == t.capacitateBaterie &&
            this->dimensiuneEcran == t.dimensiuneEcran);
    }

    Tableta& operator++() { 
        this->capacitateBaterie += 500;
        return *this;
    }

    Tableta operator+(const Tableta& t) const {
        Tableta temp;
        temp.capacitateBaterie = this->capacitateBaterie + t.capacitateBaterie;
        temp.dimensiuneEcran = this->dimensiuneEcran + t.dimensiuneEcran;
        temp.suportSim = this->suportSim || t.suportSim;
        return temp;
    }

    void afisare() const {
        cout << "Tableta: Suport SIM: " << (suportSim ? "Da" : "Nu")
            << ", Capacitate baterie: " << capacitateBaterie << " mAh"
            << ", Dimensiune ecran: " << dimensiuneEcran << " inch" << endl;
    }

    friend istream& operator>>(istream& in, Tableta& t);
    friend ostream& operator<<(ostream& out, const Tableta& t);
};

istream& operator>>(istream& in, Tableta& t) {
    cout << "Introduceti suport SIM (0/1): ";
    in >> t.suportSim;
    cout << "Introduceti capacitatea bateriei: ";
    in >> t.capacitateBaterie;
    cout << "Introduceti dimensiunea ecranului: ";
    in >> t.dimensiuneEcran;
    return in;
}

ostream& operator<<(ostream& out, const Tableta& t) {
    out << "Tableta: Suport SIM: " << (t.suportSim ? "Da" : "Nu")
        << ", Capacitate baterie: " << t.capacitateBaterie << " mAh"
        << ", Dimensiune ecran: " << t.dimensiuneEcran << " inch" << endl;
    return out;
}

int main() {
    int n;

    // Vector de telefoane
    cout << "Introduceti numarul de telefoane: ";
    cin >> n;
    vector<Telefon> telefoane(n);
    for (int i = 0; i < n; i++) {
        cout << "Telefon " << i + 1 << ":" << endl;
        cin >> telefoane[i];
    }
    cout << "Afisare telefoane:" << endl;
    for (const auto& t : telefoane) {
        t.afisare();
    }

    // Vector de laptopuri
    cout << "Introduceti numarul de laptopuri: ";
    cin >> n;
    vector<Laptop> laptopuri(n);
    for (int i = 0; i < n; i++) {
        cout << "Laptop " << i + 1 << ":" << endl;
        cin >> laptopuri[i];
    }
    cout << "Afisare laptopuri:" << endl;
    for (const auto& l : laptopuri) {
        l.afisare();
    }

    // Vector de tablete
    cout << "Introduceti numarul de tablete: ";
    cin >> n;
    vector<Tableta> tablete(n);
    for (int i = 0; i < n; i++) {
        cout << "Tableta " << i + 1 << ":" << endl;
        cin >> tablete[i];
    }
    cout << "Afisare tablete:" << endl;
    for (const auto& t : tablete) {
        t.afisare();
    }

    return 0;
}

