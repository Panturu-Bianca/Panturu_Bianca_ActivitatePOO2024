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

    // Constructor de copiere
    Telefon(const Telefon& t) : codFabricatie(t.codFabricatie) {
        this->pret = t.pret;
        this->marca = t.marca;
        this->nrStocari = t.nrStocari;
        this->dimensiuneStocare = new int[t.nrStocari];
        for (int i = 0; i < t.nrStocari; i++) {
            this->dimensiuneStocare[i] = t.dimensiuneStocare[i];
        }
    }

    // Operator de atribuire
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

    // op ==
    bool operator==(const Telefon& t) {
        return (this->marca == t.marca && this->pret == t.pret && this->nrStocari == t.nrStocari);
    }

    // op ++
    Telefon& operator++() {
        this->pret += 100;
        return *this;
    }

    // op +
    Telefon operator+(const Telefon& t) {
        Telefon temp;
        temp.pret = this->pret + t.pret;
        return temp;
    }

    // Destructor
    ~Telefon() {
        if (this->dimensiuneStocare) {
            delete[] this->dimensiuneStocare;
        }
    }



    // Func?ie static?
    static int getAnulFabricatiei() {
        return anulFabricatiei;
    }

    // Func?ie de afisare
    void afisare() {
        cout << "Telefon marca: " << marca << ", Pret: " << pret << ", Nr. Stocari: " << nrStocari << ", Cod Fabricatie: " << codFabricatie << endl;
    }

    // Functie prietena
    friend void afiseazaDetaliiTelefon(const Telefon& t);
};


int Telefon::anulFabricatiei = 2022;

// Functie prietena
void afiseazaDetaliiTelefon(const Telefon& t) {
    cout << "Telefonul " << t.marca << " are pretul " << t.pret << " si " << t.nrStocari << " stocuri disponibile." << endl;
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
        this->producator = NULL;
    }

    // Constructor cu parametri
    Laptop(float pret, string model, int memorie) : memorieRAM(memorie) {
        this->pret = pret;
        this->model = model;
        this->producator = new char[strlen("Asus") + 1];
        strcpy_s(this->producator, strlen("Asus") + 1, "Asus");
    }

    // Constructor de copiere
    Laptop(const Laptop& l) : memorieRAM(l.memorieRAM) {
        this->pret = l.pret;
        this->model = l.model;
        this->producator = new char[strlen(l.producator) + 1];
        strcpy_s(this->producator, strlen(l.producator) + 1, l.producator);
    }

    // Operator de atribuire
    Laptop& operator=(const Laptop& l) {
        if (this != &l) {
            if (this->producator) {
                delete[] this->producator;
            }
            this->pret = l.pret;
            this->model = l.model;
            this->producator = new char[strlen(l.producator) + 1];
            strcpy_s(this->producator, strlen(l.producator) + 1, l.producator);
        }
        return *this;
    }

    // op ==
    bool operator==(const Laptop& l) {
        return (this->model == l.model && this->pret == l.pret);
    }

    // op ++
    Laptop& operator++() {
        this->pret += 200;
        return *this;
    }

    // op +
    Laptop operator+(const Laptop& l) {
        Laptop temp;
        temp.pret = this->pret + l.pret;
        return temp;
    }

    // Destructor
    ~Laptop() {
        if (this->producator) {
            delete[] this->producator;
        }
    }


    // Func?ie static?
    static string getProcesor() {
        return procesor;
    }

    // Func?ie de afisare
    void afisare() {
        cout << "Laptop model: " << model << ", Pret: " << pret << ", Memorie RAM: " << memorieRAM << ", Producator: " << (producator ? producator : "N/A") << endl;
    }

    // Functie prietena
    friend void afiseazaDetaliiLaptop(const Laptop& l);
};


string Laptop::procesor = "Intel i7";

// Functie prietena
void afiseazaDetaliiLaptop(const Laptop& l) {
    cout << "Laptopul " << l.model << " are pretul " << l.pret << " si un procesor " << l.procesor << "." << endl;
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
        this->nume = NULL;
    }

    // Constructor cu parametri
    Tableta(bool suportSim, int capacitateBaterie, float dimensiune) : dimensiuneEcran(dimensiune) {
        this->suportSim = suportSim;
        this->capacitateBaterie = capacitateBaterie;
        this->nume = new char[strlen("Samsung") + 1];
        strcpy_s(this->nume, strlen("Samsung") + 1, "Samsung");
    }

    // Constructor de copiere
    Tableta(const Tableta& t) : dimensiuneEcran(t.dimensiuneEcran) {
        this->capacitateBaterie = t.capacitateBaterie;
        this->suportSim = t.suportSim;
        this->nume = new char[strlen(t.nume) + 1];
        strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
    }

    // Operator de atribuire
    Tableta& operator=(const Tableta& t) {
        if (this != &t) {
            if (this->nume) {
                delete[] this->nume;
            }

            this->capacitateBaterie = t.capacitateBaterie;
            this->suportSim = t.suportSim;
            this->nume = new char[strlen(t.nume) + 1];
            strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
        }
        return *this;
    }

    //op ==
    bool operator==(const Tableta& t) {
        return (this->capacitateBaterie == t.capacitateBaterie && this->suportSim == t.suportSim);
    }

    // op  ++
    Tableta& operator++() {
        this->capacitateBaterie += 10;
        return *this;
    }

    // op +
    Tableta operator+(const Tableta& t) {
        Tableta temp;
        temp.capacitateBaterie = this->capacitateBaterie + t.capacitateBaterie;
        return temp;
    }

    // Destructor
    ~Tableta() {
        if (this->nume) {
            delete[] this->nume;
        }
    }


    // Func?ie static?
    static int getAnLansare() {
        return anLansare;
    }

    // Func?ie de afisare
    void afisare() {
        cout << "Tableta nume: " << (nume ? nume : "N/A") << ", Capacitate baterie: " << capacitateBaterie << ", Suport SIM: " << (suportSim ? "Da" : "Nu") << endl;
    }

    // Functie prietena
    friend void afiseazaDetaliiTableta(const Tableta& t);
};


int Tableta::anLansare = 2023;

// Functie prietena
void afiseazaDetaliiTableta(const Tableta& t) {
    cout << "Tableta " << t.nume << " are capacitatea bateriei " << t.capacitateBaterie << " si suporta SIM: " << (t.suportSim ? "Da" : "Nu") << endl;
}


int main() {
    cout << "Testare clase cu constructori fara parametri:" << endl;

    Telefon t1;  
    t1.afisare();

    Laptop l1;  
    l1.afisare();

    Tableta tb1;  
    tb1.afisare();

    cout << "\nTestare clase cu constructori cu parametri:" << endl;

    Telefon t2(4500, "Samsung", 2000, 5);  
    t2.afisare();

    Laptop l2(4500, "Dell", 16);  
    l2.afisare();

    Tableta tb2(false, 120, 10);  
    tb2.afisare();

    cout << "\nTestare clase cu constructori de copiere:" << endl;

    Telefon t3 = t2;  
    t3.afisare();

    Laptop l3 = l2;  

    Tableta tb3 = tb2; 
    tb3.afisare();

    cout << "\nTestare operatori:" << endl;

    t1 = t2;  // Operator de atribuire
    t1.afisare();
    if (t1 == t2) cout << "Telefoanele t1 si t2 sunt egale." << endl;
    t1.afisare();

    Laptop l4 = l2 + l3;  // Operator de adunare
    l4.afisare();

    tb2 = tb1;  // Operator de atribuire
    tb2.afisare();
    if (tb2 == tb1) cout << "Tabletele tb2 si tb1 sunt egale." << endl;
    tb2.afisare();
    Tableta tb4 = tb2 + tb3;  // Operator de adunare
    tb4.afisare();

    cout << "\nFunctii prietene:" << endl;
    afiseazaDetaliiTelefon(t1);  // Functie prietena
    afiseazaDetaliiLaptop(l1);   // Functie prietena
    afiseazaDetaliiTableta(tb1); // Functie prietena

    return 0;
}

