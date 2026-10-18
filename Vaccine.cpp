#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Vaccin {
private:
	const int id;
	string denumire;
	int nrDoze;
	float* grame;
public:
	static int nrVaccine;
	Vaccin() :id(++nrVaccine) {
		//this->id = 0;
		this->denumire = "HPV";
		this->nrDoze = 0;
		this->grame = nullptr;
	}

	Vaccin(int id, string denumire, int nrDoze, float* grame) :id(id) {
		//this->id = 0;
		nrVaccine++;
		this->denumire = denumire;
		this->nrDoze = nrDoze;
		this->grame = new float[nrDoze];
		for (int i = 0; i < this->nrDoze; i++)
		{
			this->grame[i] = grame[i];
		}
		delete[] grame;
	}
	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Nr. doze: " << this->nrDoze;
		if (this->nrDoze > 0) {
			cout << " cu urmatoarele gramaje: ";
			for (int i = 0; i < this->nrDoze - 1; i++)
			{
				cout << this->grame[i] << " g, ";
			}
			cout << this->grame[this->nrDoze - 1] << "g.";
		}
	}
};
int Vaccin::nrVaccine = 0;

void main() {
	Vaccin vaccin1;
	vaccin1.afisare();

	float* grame = new float[] {5, 2.34, 1.5};
	Vaccin* vaccin2 = new Vaccin(7, "ANTIRABIC", 3, grame);
	vaccin2->afisare();

	delete vaccin2;

	cout << endl << "Numar vaccine: " << Vaccin::nrVaccine;
}

