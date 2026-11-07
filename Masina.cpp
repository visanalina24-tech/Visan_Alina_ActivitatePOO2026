#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

enum Combustibil { BENZINA = 1, MOTORINA = 2, ELECTRIC = 3 }; // prescurtat de la enumeration, o lista de valori data de mine
// Se foloseste cand o variabila poate alege dintr-un set mic si fix de variante
// In spatele variabilelor de tip enum, daca nu le atribui valori, compilatorul le atribuie automat, incepand cu 0, doar valori de tip INT
// se declara inaintea clasei, pentru ca clasa il foloseste ca tip

class Masina {
private: // private = se pot folosi doar din interiorul clasei (encapsulare)
	const int id; // constant: nu se mai schimba, se initializeaza in lista de initializare
	// are o copie pentru fiecare obiect
	// daca s-ar putea modifica, ar putea ajunge 2 masini sa aiba acelasi ID
	Combustibil combustibil; // tip enum: BENZINA, MOTORINA, ELECTRIC
	string marca;            // text: marca masinii
	float kmParcursi;        // numar cu zecimale: km parcursi
	int nrReparatii;         // numar intreg: cate reparatii a avut (dimensiunea vectorului)
	float* costuri;          // pointer: vector alocat dinamic cu costul fiecarei reparatii
	// regula: nrReparatii si costuri trebuie sa fie mereu in acord
	// (daca costuri = nullptr, atunci nrReparatii = 0)
public:
	static int nrMasini; // static: o singura copie, comuna tuturor obiectelor
	// folosit ca numarator de masini si ca generator de id-uri

	// ---------------- CONSTRUCTOR IMPLICIT (fara parametri) ----------------
	Masina() :id(++nrMasini) { // lista de initializare: id(++nrMasini) genereaza automat id-uri unice
		this->combustibil = BENZINA;
		this->marca = "BMW";
		this->kmParcursi = 0;
		this->nrReparatii = 0;   // 0 reparatii, deci vectorul este nullptr (in acord)
		this->costuri = nullptr;
	}

	// ---------------- CONSTRUCTOR CU PARAMETRI ----------------
	Masina(string marca, float kmParcursi, int nrReparatii, float* costuri, Combustibil combustibil) :id(++nrMasini) { // id unic automat
		this->combustibil = combustibil;
		this->marca = marca;
		this->kmParcursi = kmParcursi;
		if (costuri != nullptr && nrReparatii > 0) {
			this->nrReparatii = nrReparatii;
			this->costuri = new float[nrReparatii]; // deep copy, nu se copiaza cu = pentru ca s-ar copia doar adresa (shallow copy)
			for (int i = 0; i < nrReparatii; i++)
			{
				this->costuri[i] = costuri[i];
			}
		}
		else {
			this->nrReparatii = 0;
			this->costuri = nullptr;
		}
		// FARA delete[] costuri aici: vectorul primit apartine celui care l-a creat (main)
	}

	// ---------------- CONSTRUCTOR DE COPIERE ----------------
	// se apeleaza cand un obiect e creat dintr-unul existent (Masina m2 = m1;)
	// sau cand e transmis prin valoare unei functii
	Masina(const Masina& m) :id(++nrMasini) { // copia primeste id nou
		this->combustibil = m.combustibil;
		this->marca = m.marca;
		this->kmParcursi = m.kmParcursi;
		this->nrReparatii = m.nrReparatii;
		if (m.costuri != nullptr) {
			this->costuri = new float[m.nrReparatii]; // deep copy, nu se copiaza cu = pentru ca s-ar copia doar adresa (shallow copy)
			for (int i = 0; i < m.nrReparatii; i++)
			{
				this->costuri[i] = m.costuri[i];
			}
		}
		else {
			this->costuri = nullptr;
		}
		// FARA delete[] costuri aici: copia are nevoie de vectorul ei pana la destructor
	}

	// ---------------- OPERATOR= ----------------
	// se apeleaza la atribuire intre obiecte DEJA existente (m2 = m1;)
	// id nu se copiaza, pentru ca e const
	void operator=(const Masina& m) {
		if (this != &m) { // protectie la autoatribuire (m1 = m1)
			this->combustibil = m.combustibil;
			this->marca = m.marca;
			this->kmParcursi = m.kmParcursi;
			this->nrReparatii = m.nrReparatii;

			// 1. intai stergem vechiul vector (altfel memory leak)
			if (this->costuri != nullptr) {
				delete[] this->costuri;
				this->costuri = nullptr;
			}

			// 2. apoi alocam unul nou si copiem (deep copy)
			if (m.costuri != nullptr) {
				this->costuri = new float[m.nrReparatii];
				for (int i = 0; i < m.nrReparatii; i++)
				{
					this->costuri[i] = m.costuri[i];
				}
			}
			// FARA delete[] costuri la final
		}
	}

	// ---------------- DESTRUCTOR ----------------
	// se apeleaza automat cand obiectul dispare (iese din scope sau delete)
	~Masina() {
		cout << endl << "S-a apelat destructorul";
		if (this->costuri != nullptr) {
			delete[] this->costuri; // eliberam memoria alocata cu new[]
		}
	}

	// ---------------- GETTER ----------------
	string getMarca() {
		return this->marca;
	}

	// ---------------- OPERATOR DE AFISARE ----------------
	// friend = functie din afara clasei, dar cu acces la campurile private
	// fara el, cout << m1; nu merge pe un tip facut de noi
	friend void operator<<(ostream& out, Masina c) {
		out << endl << "Masina afisata: ";
		out << endl << "Combustibil: ";
		// cout << combustibil ar afisa doar 1, 2 sau 3, de aceea afisam noi textul
		if (c.combustibil == BENZINA) out << "BENZINA";
		if (c.combustibil == MOTORINA) out << "MOTORINA";
		if (c.combustibil == ELECTRIC) out << "ELECTRIC";
		out << endl << "Id: " << c.id;
		out << endl << "Marca: " << c.marca;
		out << endl << "Km parcursi: " << c.kmParcursi;

		out << endl << "Numar reparatii: " << c.nrReparatii;
		if (c.costuri != nullptr) {
			out << endl << "Costuri: ";
			for (int i = 0; i < c.nrReparatii - 1; i++) {
				out << c.costuri[i] << " lei, ";
			}
			out << c.costuri[c.nrReparatii - 1] << " lei."; // ultimul pret separat, ca sa aiba punct in loc de virgula
		}
	} // aici se inchide operator<<
}; // aici se inchide clasa (obligatoriu cu ;)

int Masina::nrMasini = 0; // definirea variabilei statice, in afara clasei, o singura data
// se schimba la fiecare masina noua

void main() {
	float* costuri = new float[3] {20.5f, 100, 60.7f};
	Masina m1("VOLKSWAGEN", 230000, 3, costuri, MOTORINA); // ordinea argumentelor = ordinea din constructor
	delete[] costuri; // il stergem noi in main, pentru ca m1 si-a facut propria copie

	cout << m1.getMarca(); // getMarca se apeleaza prin obiect
	cout << m1;
}