//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
//class Depozit {
//private:
//	const int id;
//	int nrProduse;
//	float* preturi;
//public:
//	Depozit(const int idNou) :id(idNou) {
//		this->nrProduse = 2;
//		this->preturi = new float[nrProduse];
//		for (int i = 0;i < nrProduse;i++) {
//				this->preturi[i] = 3;
//			}	
//		
//	}
//	Depozit(const Depozit& d) :id(d.id) {
//		if (d.preturi != nullptr) {
//			this->nrProduse = d.nrProduse;
//			this->preturi = new float[d.nrProduse];
//			for (int i = 0;i < d.nrProduse;i++) {
//				this->preturi[i] = d.preturi[i];
//			}
//		}
//		else {
//			this->nrProduse = 0;
//			this->preturi = nullptr;
//		}
//	}
//	~Depozit() {
//		if(preturi != nullptr) {
//			delete[] this->preturi;
//		}
//	}
//	Depozit& operator=(const Depozit& d) {
//		if (this != &d) {
//			if (preturi != nullptr) {
//				delete[] this->preturi;
//			}
//
//			this->nrProduse = d.nrProduse;
//			this->preturi = new float[d.nrProduse];
//			for (int i = 0;i < d.nrProduse;i++) {
//				this->preturi[i] = d.preturi[i];
//			}
//		}
//		return*this;
//	}
//
//	int getId() {
//		return this->id;
//	}
//	void setNrProduse(int valoareNoua) {
//		if (valoareNoua > 0) {
//			this->nrProduse = valoareNoua;
//		}
//		else {
//			this->nrProduse = 0;
//		}
//		
//	}
//	void afisare() {
//		cout << "ID: " << this->id << endl;
//		cout << "NRPRODUSE: " << this->nrProduse << endl;
//		cout << "PRETURI: " << endl;
//		for (int i = 0;i < nrProduse;i++) {
//			cout << preturi[i] << " " << endl;
//		}
//	}
//};
//
//void main() {
//	Depozit d1(1);
//	d1.afisare();
//	Depozit d2(2);
//	d2 = d1;
//	d2.afisare();
//
//	cout << d2.getId();
//	d2.setNrProduse(5);
//	d2.afisare();
//}