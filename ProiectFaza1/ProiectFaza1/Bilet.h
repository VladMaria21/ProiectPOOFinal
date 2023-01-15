#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

class Bilet
{
private:
	
	int cnp[13];
	int* uid;
	int lungUid;
	int nrBilet;
	int rez;//0 daca e liber, 1 daca e rezervat
	static int bileteTot;//nr de bilete rezervate
	
protected:

	string tip;
	int pretVip;

public:

	Bilet();
	Bilet(string tip, int* cnp);
	Bilet(const Bilet& b);
	~Bilet();

	int validareUid(int* copie);
	//functie virtuala calcul pretVip in fct de tipul biletului
	virtual int calculVip();

	void setTip(string tip);
	void setCnp(int* cnp);
	void setUid(int* uid, int lungUid);
	void setLungUid(int lungUid);
	void setNrBilet(int nrBilet);
	void setRez(int rez);
	void setBileteTot(int bileteTot);

	string getTip();
	int* getCnp();
	int* getUid();
	int getLungUid();
	int getNrBilet();
	int getRez();
	static int getBileteTot();

	Bilet& operator=(const Bilet& b);
	friend ostream& operator<<(ostream& out, Bilet b);
	friend istream& operator>>(istream& in, Bilet& b);
	friend ifstream& operator>>(ifstream& fin, Bilet& b);

	bool operator!();//verifica daca biletul este rezervat
	bool operator==(const Bilet& b);//verifica daca cele doua bilete sunt rezervate de aceeasi persoana
};