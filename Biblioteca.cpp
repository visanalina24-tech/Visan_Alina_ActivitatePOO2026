#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Biblioteca {
private:
	const int id;
	string nume; 
	int nrCarti;
	float* ratinguri;
public:
	// constructor default
	Biblioteca() :id(id) {
		this->nume = " ";
		this->nrCarti = 0;
		this->ratinguri = nullptr;
	}
	// constructor cu un parametru
	Biblioteca(int idNou) :id(idNou) {
		this->nume = "NATIONALA BUCURESTI";
		this->nrCarti = 2;
		this->ratinguri = new float[nrCarti];
		for (int i = 0;i < nrCarti;i++) {
			this->ratinguri[i] = 3;
		}
	}
	// constructor de copiere
	Biblioteca(const Biblioteca& b) :id(b.id) {
		this->nume = b.nume;
		this->nrCarti = b.nrCarti;
		if (b.nrCarti > 0) {
			this->ratinguri = new float[b.nrCarti];
			for (int i = 0;i < b.nrCarti;i++) {
				this->ratinguri[i] = b.ratinguri[i];
			}
		}
		else {
			this->nrCarti = 0;
			this->ratinguri = nullptr;
		}
	}
	~Biblioteca() {
		if (ratinguri != 0) {
			delete[] this->ratinguri;
		}
	}
	int getId() {
		return this->id;
	}
	void setRatinguri(float* vectorNou, int dim) {
		if (vectorNou != nullptr && dim > 0) {
			delete[] this->ratinguri;
			this->nrCarti = dim;
			this->ratinguri = new float[dim];
			for (int i=0;i < dim;i++) {
				this->ratinguri[i] = vectorNou[i];
			}
		}
		else {
			throw exception();
		}
	}

	//OPERATOR = -- DESCONS+COPIERE
	Biblioteca& operator=(const Biblioteca& b) {
		if (this != &b) {
			if (ratinguri != nullptr) {
				delete[] this->ratinguri;
			}
			this->nume = b.nume;
			this->nrCarti = b.nrCarti;
			if (b.nrCarti > 0) {
				this->ratinguri = new float[b.nrCarti];
				for (int i = 0;i < b.nrCarti;i++) {
					this->ratinguri[i] = b.ratinguri[i];
				}
			}
			else {
				this->nrCarti = 0;
				this->ratinguri = nullptr;
			}
		}
			return*this;
	}
	void afisare() {
		cout << "ID: " << this->id << endl;
		cout << "NUME: " << this->nume << endl;
		cout << "NRCARTI: " << this->nrCarti << endl;
		cout << "RATINGURI: " << this->nrCarti << endl;
		for (int i = 0;i < nrCarti;i++) {
			cout << ratinguri[i] << " " << endl;
		}
	}

};
void main() {
	Biblioteca b1;
	b1.afisare();
	Biblioteca b2(30);
	b2.afisare();
	cout << "ID-UL OBIECTULUI B2:" << b2.getId() << endl;
	b1 = b2;
	b1.afisare();
	// set memory leak + delete
	float* v = new float[3] { 4.5f, 3.0f, 5.0f };
	b2.setRatinguri(v, 3);
	delete[]v;

	b2.afisare();
	try {
		b2.setRatinguri(nullptr, 0);
	}
	catch (exception& e) {
		cout << endl << "Date invalide!";
	}
}