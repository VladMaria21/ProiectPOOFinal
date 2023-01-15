#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Eveniment.h";

using namespace std;

class Locatie
{
private:
	string tip;
	int nrZone;
	char** zone;
	int nrLocTot;
	int nrRanduriTot;
	int nrLocZona;
	int nrRanduriZona;
	Eveniment* ev;
	int nrEv;
	float* preturi;//preturile in functie de zone
	static int locTot;//numarul de locatii care exista
	const int nrLocMax;
public:
	friend class Eveniment;

	Locatie();
	Locatie(string tip, int nrZone, char** zone, int nrLocTot, int nrRanduriTot, int nrLocZona, int nrRanduriZona, float* preturi);
	Locatie(const Locatie& l);
	~Locatie();

	float pretMediu(float* preturi);

	void setTip(string tip);
	void setNrZone(int nrZone);
	void setZone(char** zone, int nrZone);
	void setNrLocTot(int nrLocTot);
	void setNrRanduriTot(int nrRanduriTot);
	void setNrLocZona(int nrLocZona);
	void setNrRanduriZona(int nrRanduriZona);
	void setEv(Eveniment* ev, int nrEv);
	void setNrEv(int nrEv);
	void setPreturi(float* preturi, int nrZone);
	void setLocTot(int locTot);

	string getTip();
	int getNrZone();
	char** getZone();
	int getNrLocTot();
	int getNrRanduriTot();
	int getNrLocZona();
	int getNrRanduriZona();
	Eveniment* getEv();
	int getNrEv();
	float* getPreturi();
	static int getLocTot();

	Locatie& operator=(const Locatie& l);
	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
	friend ifstream& operator>>(ifstream& fin, Locatie& l);

	Locatie& operator+(const Locatie& l);//aduna preturile
	float operator[](int index);//returneaza pretul zonei indexate

};
