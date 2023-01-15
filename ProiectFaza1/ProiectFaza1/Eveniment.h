#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Bilet.h";
#include "Ocazie.h";

using namespace std;

typedef struct Data
{
	int an, luna, zi;
	int ora, minut;
};

class Eveniment:public Ocazie
{
private:
	string denumire;
	Data data;
	Bilet* bilete;
	int nrBilete;
	int nrZone;
	char** zone;
	int nrLocuriZona;
	int* locZ;//locuri ocupate din fiecare zona
	static int evTot;//numarul de evenimente care exista

public:
	friend class Bilet;

	Eveniment();
	Eveniment(string denumire, Data data);
	Eveniment(const Eveniment& e);
	~Eveniment();

	int existaCopii();
	int validareData(Data x);
	int* cumparaBilet(int i);

	void setDenumire(string denumire);
	void setData(Data data);
	void setBilete(Bilet* bilete, int nrBilete);
	void setNrBilete(int nrBilete);
	void setNrZone(int nrZone);
	void setZone(char** zone, int nrZone);
	void setNrLocuriZona(int nrLocuriZona);
	void setLocZ(int* locZ, int nrZone);
	void setEvTot(int evTot);

	string getDenumire();
	Data getData();
	Bilet* getBilete();
	int getNrBilete();
	int getNrZone();
	char** getZone();
	int getNrLocuriZona();
	int* getLocZ();
	static int getEvTot();

	Eveniment& operator=(const Eveniment& e);
	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);
	friend ifstream& operator>>(ifstream& fin, Eveniment& e);

	Eveniment& operator++();//amana data evenimentului pentru o zi
	Eveniment& operator++(int i);
	bool operator<=(const Eveniment& e);//compara nr de bilete vandute pentru evenimentele date
};