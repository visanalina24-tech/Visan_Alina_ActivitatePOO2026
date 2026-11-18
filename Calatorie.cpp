//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Calatorie {
//private:
//	char* numeDestinatie;
//	const int id;
//public:
//	Calatorie(const int idNou) :id(idNou) {
//		this->numeDestinatie = new char[strlen("Dubai") + 1];
//		strcpy(numeDestinatie, "Dubai");
//	}
//	Calatorie(const Calatorie& c) : id(c.id) {
//		this->numeDestinatie = new char[strlen(c.numeDestinatie) + 1];
//		strcpy(numeDestinatie, c.numeDestinatie);
//	}
//	~Calatorie() {
//		delete[] this->numeDestinatie;
//	}
//
//	int getId() {
//		return this->id;
//	}
//	void setNumeDestinatie(const char* numeNou) {
//		if (numeNou != nullptr && strlen(numeNou) > 0) {
//			delete[]this->numeDestinatie;
//			this->numeDestinatie = new char[strlen(numeNou) + 1];
//			strcpy(numeDestinatie, numeNou);
//		}
//	}
//
//	Calatorie& operator=(const Calatorie& c) {
//		if (this!=&c) {
//			delete[] this->numeDestinatie;
//			this->numeDestinatie = new char[strlen(c.numeDestinatie) + 1];
//			strcpy(numeDestinatie, c.numeDestinatie);
//		}
//		return *this;
//	}
//	void afisare() {
//		cout << "ID - ul este: " << this->id << endl;
//		cout << "Numele destinatiei este: " << this->numeDestinatie << endl;
//	}
//
//};
//
//void main()
//{
//	Calatorie c1(300);
//	c1.afisare();
//
//	cout << c1.getId() << endl;
//
//	Calatorie c2(100);
//	c2 = c1;
//	c2.afisare();
//
//	c2.setNumeDestinatie("Ibiza");
//	c2.afisare();
//
//}