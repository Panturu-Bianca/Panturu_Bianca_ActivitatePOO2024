#include<iostream>
using namespace std;


class Magazin {

private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024) {   //constr fara param
		this->oras = "Braila";
		this->nrAngajati = 3;
		this->salarii = NULL;

	}

	Magazin(string oras, int nrAngajati, float suprfata, int an) : anDeschidere(an) { //constr param
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = nrAngajati;
		}
		this->suprafata = suprafata;

	}

	~Magazin() {    //destructor
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	Magazin(const Magazin& m) : anDeschidere(m.anDeschidere) {   //constr copiere
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.nrAngajati;
		}
		this->suprafata = m.suprafata;

	}


	Magazin operator=(const Magazin& m) {    //operator=
		if (&m != this) {   //autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.nrAngajati;
			}
			this->suprafata = m.suprafata;

		}
		return *this;
	}


	//geteri
	string getOras() {
		return this->oras;
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}

	static int getImpozitM2() {
		return Magazin::impozitM2;
	}

	float* getSalarii() {
		return this->salarii;
	}


	//seteri   nu se face pt const si static

	void setOras(string oras) {
		if (oras.size() > 4) {
			this->oras = oras;
		}
	}

	void setNrAngajati(int nrAngajati) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
		}
	}

	void setNrAngajati(int nrAngajati, float* salarii) {  //la * trb sa depinda de parametru
		if (nrAngajati > 0) {   //seter nr ang
			this->nrAngajati = nrAngajati;
		}
		if (this->salarii) {   //destructor
			delete[]this->salarii;
		}
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = nrAngajati;
		}

	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}


	operator float() {    //op functie
		float s = 0;
		for (int i = 0; i < nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}

	void afisare() {
		cout << "oras:" << this->oras << endl;
		cout << "nrAngajati:" << this->nrAngajati << endl;
		cout << "suprafata:" << this->suprafata << endl;
		cout << "anDeschidere:" << this->anDeschidere << endl;
		cout << "impozit pe M2:" << Magazin::impozitM2 << endl;

	}
};
int Magazin::impozitM2 = 4;//initializ atribut static

int main() {
	Magazin m1;
	m1.afisare();
	m1.setNrAngajati(6, new float[6] {2, 5, 4, 8, 6, 3});

	cout << m1.getOras() << endl;
	cout << m1.getNrAngajati() << endl;
	cout << m1.getSalarii() << endl;
	cout << m1.getImpozitM2() << endl;
	m1.setOras("Buzau");
	m1.setNrAngajati(4);


	Magazin m2("Braila", 4, 150, 2020);
	m2.setNrAngajati(6, new float[4] {2, 9, 10,3});
	//m2.afisare();
	//float salarii[] = { 200,500 };
	cout << m2.getOras() << endl;
	cout << m2.getNrAngajati() << endl;
	cout << m2.getSalarii() << endl;
	m2.setOras("Bucuresti");
	m2.setNrAngajati(6);

	int nrAngajati = (int)m2;
	float salariiTotale = m2;
	cout << endl << "Salarii totale:" << salariiTotale;
	


	return 0;

}

