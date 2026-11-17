//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Benzinarie {
//private:
//	const int id;
//	int nrPompe;
//	float* capacitatiPompe;
//public:
//	//CONSTRUCTOR CU PARAMETRII
//	Benzinarie(const int idNou) :id(idNou) { // daca se cere cu mai multi parametrii pun :id(id)
//		this->nrPompe = 2;
//		if (capacitatiPompe != nullptr && nrPompe > 0) {
//			this->capacitatiPompe = new float[nrPompe];
//			for (int i = 0; i < nrPompe;i++)
//			{
//				this->capacitatiPompe[i] = 3;
//			}
//		}
//		else {
//			this->nrPompe = 0;
//			this->capacitatiPompe = nullptr;
//		}
//	}
//	// CONSTRUCTOR DE COPIERE
//	Benzinarie(const Benzinarie& b) :id(b.id) {
//		this->nrPompe = b.nrPompe;
//		if (b.capacitatiPompe != nullptr) {
//			this->capacitatiPompe = new float[b.nrPompe];
//			for (int i = 0; i < b.nrPompe;i++)
//			{
//				this->capacitatiPompe[i] = b.capacitatiPompe[i];
//			}
//		}
//		else {
//			this->capacitatiPompe = nullptr;
//		}
//	}
//	//DESTRUCTOR
//	~Benzinarie()
//	{
//		if (this->capacitatiPompe != nullptr)
//		delete[] this->capacitatiPompe;
//	}
//
//	Benzinarie& operator=(const Benzinarie& b) {
//		if (this != &b) {
//			if (this->capacitatiPompe != nullptr) {
//				delete[] this->capacitatiPompe;
//				this->capacitatiPompe = nullptr;;
//			}
//			if (b.capacitatiPompe != nullptr) {
//				this->capacitatiPompe = new float[b.nrPompe];
//				for (int i = 0; i < b.nrPompe;i++)
//				{
//					this->capacitatiPompe[i] = b.capacitatiPompe[i];
//				}
//			}
//
//
//		}
//	}
//
//
//
//	void afisare() {
//		cout << "Id-ul: " << this->id << endl;
//		cout << "NR POMPE: " << this->nrPompe << endl;
//		cout << "CAPACITATI POMPE: " << endl;
//		for (int i = 0; i < nrPompe;i++)
//		{
//			cout << capacitatiPompe[i]<<" " << endl;
//		}
//	}
//	int getId() {
//		return this->id;
//	}
//	void setNumarPompe(int numarNou) {
//		if (numarNou > 0) {
//			this->nrPompe = numarNou;
//		}
//		else {
//			throw exception();
//		}
//	}
//};
//
//void main() {
//	Benzinarie b1(1);
//	b1.afisare();
//	Benzinarie b2 = b1;
//	b2.afisare();
//
//	cout << b1.getId();
//	b2.setNumarPompe(5);
//	b2.afisare();
//	// daca se cere constructorul cu mai multi parametrii fac asa:
//	// float* capacitatiPompe = new float[] {5, 2.34, 1.5};
//    //	Benzinarie* vaccin2 = new Vaccin(7, "ANTIRABIC", 3, grame);
//    //	vaccin2.afisare();
//}