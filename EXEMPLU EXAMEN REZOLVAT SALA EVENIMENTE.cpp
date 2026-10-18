//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//class SalaEvenimente {
//	//VARIABILELE SA FIE MEREU PRIVATE SI CONSTRUCTORII MEREU PUBLICI
//private:
//	string numeSala;
//	int numarInvitati;
//	float pretBilet;
//	int* varsteInvitati;
//public:
//	SalaEvenimente() {
//		this->numeSala = "";
//		this->numarInvitati = 0;
//		this->pretBilet = 0;
//		this->varsteInvitati = nullptr;
//	}
//	// METODA DE ACCES CEL PUTIN UN MEMBRU
//	string getNumeSala() {
//		return this->numeSala; // imi vine mai usor sa aleg VARIABILA DE TIP STRING, E CAM INUTILA NU PREA LUCREZ
//	}
//	// CONSTRUCTOR CU PARAMETRI
//	SalaEvenimente(string numeSala, int numarInvitati, float pretBilet, const int* varsteInvitati) {
//		this->numeSala = numeSala;
//		this->numarInvitati = numarInvitati;
//		this->pretBilet = pretBilet;
//		this->varsteInvitati = new int[this->numarInvitati]; //deobicei VECTORUL INT*/FLOAT* SE LEAGA DE CONSTANTA INT
//		for (int i = 0;i < numarInvitati;i++) {
//			this->varsteInvitati[i] = varsteInvitati[i];
//		}
//	}
//	// CONSTRUCTOR DE COPIERE
//	SalaEvenimente(const SalaEvenimente& s) {
//		this->numeSala = s.numeSala;
//		this->numarInvitati = s.numarInvitati;
//		this->pretBilet = pretBilet;
//		this->varsteInvitati = new int[this->numarInvitati]; //deobicei VECTORUL INT*/FLOAT* SE LEAGA DE CONSTANTA INT
//		for (int i = 0;i < s.numarInvitati;i++) {
//			this->varsteInvitati[i] = s.varsteInvitati[i];
//		}
//	}
//	//DESCTRUCTOR/DEZALOCARE MEMORIA VECTORULUI
//	~SalaEvenimente()
//	{
//		if (varsteInvitati != nullptr)
//		{
//			delete[] this->varsteInvitati;
//		}
//	}
//	//OPERATORUL = DE ATRIBUIRE: DESCTRUCTOR + CONSTRUCTOR DE COPIERE
//
//	SalaEvenimente& operator=(const SalaEvenimente& s) {
//		if (varsteInvitati != nullptr)
//		{
//			delete[] this->varsteInvitati;
//		}
//		this->numeSala = s.numeSala;
//		this->numarInvitati = s.numarInvitati;
//		this->pretBilet = pretBilet;
//		this->varsteInvitati = new int[this->numarInvitati]; //deobicei VECTORUL INT*/FLOAT* SE LEAGA DE CONSTANTA INT
//		for (int i = 0;i < s.numarInvitati;i++) {
//			this->varsteInvitati[i] = s.varsteInvitati[i];
//		}
//		return*this;
//	}
//	//OPERATORUL DE AFISARE OSTREAM
//	friend ostream& operator<<(ostream& out, const SalaEvenimente& s) {
//		out<<s.numeSala<<" "<<s.numarInvitati<<" "<<s.pretBilet;
//		for (int i = 0;i < s.numarInvitati;i++) {
//			out<<" "<<s.varsteInvitati[i];
//		}
//		return out;
//	}
//	// PANA AICI TREBUIE SA STIU TOT
//	
//};
//int main() {
//	//INITIALIZAM VARIABILA INT + VECTORUL LEGAT DE VARIABILA INT
//	int numarInvitati = 3;
//	int varsteInvitati[] = { 30,40,50 };
//	//INNITIALIZARE CONSTRUCTOR
//	SalaEvenimente s("Sala Palatului", 3, 15, varsteInvitati);
//	//VERIFICARE DACA PUTEM ACCESA ELEMENTELE
//	cout << s.getNumeSala();
//
//	}