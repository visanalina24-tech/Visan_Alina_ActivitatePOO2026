#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum Combustibil { BENZINA = 1, MOTORINA = 2, ELECTRIC = 3 }; // prescurtat de la enumeration, o lista de valori data de mine
// Se foloseste cand o variabila poate alege dintr-un set mic si fix de variante
// In spatele variabilelor de tip text, daca nu le atribui valori, compilatorul le atribui automat, incepand cu 0, dopar valori de tip INT
// se declara inaintea clasei, pentru ca clasa il folseste ca tip

class Masina {
private:
	const int id;// constant: nu se mai schimba, se intiliazeaza in lista de initializare
	//are o copie pt fiecare obiect
	// Daca se modifica pot ajunge 2 masini sa aiba acelasi ID
	Combustibil combustibil; //tip enum: BENZINA, MOTOTINA, ELECTRIC
	string marca; //text: marca masinii
	float kmParcursi; //numar cu zecimale: km parcursi
	int nrReparatii; // numar intreg: cate reparatii a avut
	float* costuri; //pointer: vector alocat dinamic cu costul fiecarei reparatii
public:
	static int nrMasini; // static: o singura copie comuna obiectivelor
	Masina() :id(++nrMasini) { // id(++nrMasini) genereaza automat id-uri unice
		// lista de initializare
		this->combustibil = BENZINA;
		this->marca = "BMW";
		this->kmParcursi = 0;
		this->nrReparatii = 0;
		this->costuri = nullptr;
		//constructor implicit
	}
	Masina(string marca, float kmParcursi, int nrReparatii, float* costuri, Combustibil combustibil) :id(++nrMasini) { // id(++nrMasini) genereaza automat id-uri unice
		// lista de initializare
		this->combustibil = combustibil;
		this->marca = marca;
		this->kmParcursi = kmParcursi;
		this->nrReparatii = nrReparatii;
		this->costuri = new float[this->nrReparatii]; // deep copy, nu se copiaza cu = pentru ca s-ar copia doar adresa (shallow copy)
		for (int i = 0; i < nrReparatii;i++)
		{
			this->costuri[i] = costuri[i];
		}
		delete[] costuri;
		//constructor cu parametrii
	}
	Masina(const Masina& m):id(++nrMasini) {
		// lista de initializare
		this->combustibil = m.combustibil;
		this->marca = m.marca;
		this->kmParcursi = m.kmParcursi;
		this->nrReparatii = m.nrReparatii;
		this->costuri = new float[this->nrReparatii]; // deep copy, nu se copiaza cu = pentru ca s-ar copia doar adresa (shallow copy)
		for (int i = 0; i < m.nrReparatii;i++)
		{
			this->costuri[i] = m.costuri[i];
		}
		delete[] costuri;
		//constructor de copiere
	}

	~Masina() {
		cout << endl << "S-a apelat desconstructorul";
		if (this->costuri != nullptr) {
			delete[]this->costuri;
		}
	}

};

int Masina::nrMasini = 0; // definirea variabilei statice, in afara clasei, o singura data
// se schimba la fiecare masina noua
void main() {
	Masina m1;
