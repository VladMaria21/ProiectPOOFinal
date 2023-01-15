#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Bilet.h";

using namespace std;

class Invitatie :public Bilet
{
private:
	string nume;
	string prenume;
public:

	Invitatie();
	Invitatie(string tip, int* cnp, string nume, string prenume);
	Invitatie(const Invitatie& i);

	int calculVip();

	void setNume(string nume);
	void setPrenume(string prenume);

	string getNume();
	string getPrenume();

	Invitatie& operator=(const Invitatie& i);
	friend ostream& operator<<(ostream& out, Invitatie i);
};