//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std; //ca sa pot scrie cout in loc de std::cout.
//
//class Companie {
//private: // inseamna ca atributele nu pot fi accesate direct din main; incapsularea: accesul se face doar prin metode (get/set).
//	char* numeCompanie;//un pointer catre un sir de caractere
//	const int id; //atributul nemodificabil
//	float cifraDeAfaceri;
//public:
//	// constructor default
//	Companie() :id(0) {
//		this->numeCompanie=new char[strlen("Necunoscut") + 1];
//		//this-> inseamna “atributul obiectului curent”.
//		//strlen("Necunoscut") = 10 caractere.
//		//+ 1 lasa loc pentru '\0', caracterul invizibil care marcheaza sfarsitul unui sir in C.Fara el, strcpy scrie in afara memoriei.
//		//new char[11] aloca 11 octeti in heap si intoarce adresa lor.
//		strcpy(this->numeCompanie, "Necunoscut");
//		//copiaza textul in memoria tocmai alocata
//		this->cifraDeAfaceri = 0;
//	}
//	// constructor cu un parametru
//	Companie(int idNou) :id(idNou) { // daca se cere pun toti parametrii si la final :id(id)
//		this->numeCompanie = new char[strlen("Necunoscut") + 1];
//		strcpy(this->numeCompanie, "Necunoscut");
//		this->cifraDeAfaceri = 0;
//	}
//	// constructor de copiere - necesar ca sa nu am probleme cu char*
//	Companie(const Companie& c) :id(c.id) { //se apeleaza cand creez un obiect nou dintr-unul existent: Companie c3 = c2;
//		//const = nu modifici obiectul sursa.
//		//& = referinta
//		//id(c.id): obiectul nou primeste acelasi id
//		this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
//		strcpy(this->numeCompanie, c.numeCompanie);
//		this->cifraDeAfaceri = c.cifraDeAfaceri;
//	}
//	// destructor - fara el am memory leak
//	~Companie() {
//		delete[] this->numeCompanie;
//	}
//	//operator =
//
//	//Companie& operator=(const Companie& c) {
//	//	if (this != &c) {
//	//		// DESTRUCTOR + CONSTRUCTOR DE COPIERE
//	//		delete[] this->numeCompanie;
//	//		this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
//	//		strcpy(this->numeCompanie, c.numeCompanie);
//	//		this->cifraDeAfaceri = c.cifraDeAfaceri;
//	//	}
//	//	return *this;
//	//}
//
//
//	int getId() {
//		return this->id;
//	}
//	void setNumeCompanie(const char* numeNou) {
//		if (numeCompanie != nullptr & strlen(numeNou) > 0) { // DACA NUMELE COMPANIEI EXISTA SI DACA NUMARUL DE CARACTERE AL NOULUI NUME
//			delete[] this->numeCompanie;// STERG NUMELE ANTERIOR
//			this->numeCompanie = new char[strlen(numeNou) + 1];
//			strcpy(this->numeCompanie, numeNou);// IN VARIABILA NUMECOMPANIE, PUN NUMELE NOU
//		}
//	}
//	// metoda de afisare a atributelor
//	void afisare() {
//		cout << endl << "Id: " << this->id;
//		cout << endl << "Nume: " << this->numeCompanie;
//		cout << endl << "Cifra de afaceri: " << this->cifraDeAfaceri << endl;
//	}
//
//};
//
//void main() {
//	// CONSTRUCTOR DEFAULT
//	Companie c1; 
//	c1.afisare();
//	// CONSTRUCTOR CU UN PARAMETRU
//	Companie c2(101);
//	c2.afisare();
//	//get
//	cout << endl << "ID: "<<c2.getId();
//	//set
//	c2.setNumeCompanie("IBM");
//	c2.afisare();
//	//operator =;
//	/*c1 = c2;
//	c1.afisare();*/
//}