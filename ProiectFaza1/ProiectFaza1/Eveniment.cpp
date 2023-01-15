#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include "Bilet.h";
#include "Ocazie.h";
#include "Eveniment.h";

using namespace std;

int Eveniment::evTot = 0;

Eveniment::Eveniment()
{
	denumire = "";
	data.an = 0;
	data.luna = 0;
	data.zi = 0;
	data.ora = 0;
	data.minut = 0;
	bilete = nullptr;
	nrBilete = 0;
	nrZone = 0;
	zone = nullptr;
	nrLocuriZona = 0;
	locZ = nullptr;
	evTot++;
}

Eveniment::Eveniment(string denumire, Data data)
{
	this->denumire = denumire;
	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
	this->data.ora = data.ora;
	this->data.minut = data.minut;
	bilete = nullptr;
	nrBilete = 0;
	nrZone = 0;
	zone = nullptr;
	nrLocuriZona = 0;
	locZ = nullptr;
	evTot++;
}

Eveniment::Eveniment(const Eveniment& e)
{
	denumire = e.denumire;
	data.an = e.data.an;
	data.luna = e.data.luna;
	data.zi = e.data.zi;
	data.ora = e.data.ora;
	data.minut = e.data.minut;

	if (e.nrBilete > 0)
	{
		if (e.bilete != nullptr)
		{
			bilete = new Bilet[e.nrBilete];
			nrBilete = e.nrBilete;
			for (int i = 0; i < e.nrBilete; i++)
			{
				bilete[i] = e.bilete[i];
			}
		}
	}
	else
	{
		bilete = nullptr;
		nrBilete = 0;
	}

	if (e.nrZone > 0)
	{
		if (e.zone != nullptr)
		{
			zone = new char* [e.nrZone];
			nrZone = e.nrZone;
			for (int i = 0; i < e.nrZone; i++)
			{
				zone[i] = new char[strlen(e.zone[i]) + 1];
				strcpy_s(zone[i], strlen(e.zone[i]) + 1, e.zone[i]);
			}
		}
	}
	else
	{
		zone = nullptr;
		nrZone = 0;
	}

	if (e.nrLocuriZona > 0)
	{
		if (e.locZ != nullptr)
		{
			locZ = new int[e.nrLocuriZona];
			nrZone = e.nrZone;
			for (int i = 0; i < e.nrLocuriZona; i++)
			{
				locZ[i] = e.locZ[i];
			}
		}
	}
	else
	{
		locZ = nullptr;
		nrLocuriZona = 0;
	}

	evTot = e.evTot;
}

Eveniment::~Eveniment()
{
	if (bilete != nullptr)
	{
		delete[]bilete;
		bilete = nullptr;
	}
	nrBilete = 0;
	if (zone != nullptr)
	{
		delete[]zone;
		zone = nullptr;
	}
	nrZone = 0;
	if (locZ != nullptr)
	{
		delete[]locZ;
		locZ = nullptr;
	}
	nrLocuriZona = 0;
	evTot--;
}

int Eveniment::existaCopii()
{
	return 1;
}

int Eveniment::validareData(Data x)
{
	if (x.luna == 2)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 29) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else if (x.luna == 4 || x.luna == 6 || x.luna == 9 || x.luna == 11)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 30) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else if (x.luna == 1 || x.luna == 3 || x.luna == 5 || x.luna == 7 || x.luna == 8 || x.luna == 10 || x.luna == 12)
	{
		if ((x.an >= 2022 && x.an <= 2023) && (x.zi >= 1 && x.zi <= 31) && (x.ora >= 0 && x.ora <= 24) && (x.minut >= 0 && x.minut <= 59))
		{
			return 1;
		}
	}
	else return 0;
}

int* Eveniment::cumparaBilet(int i)
{
	if (locZ[i] <= nrLocuriZona)
	{
		cin >> bilete[nrBilete];
		nrBilete++;
	}
	return bilete[nrBilete - 1].getUid();
}

//setteri

void Eveniment::setDenumire(string denumire)
{
	this->denumire = denumire;
}

void Eveniment::setData(Data data)
{
	this->denumire = denumire;
	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
	this->data.ora = data.ora;
	this->data.minut = data.minut;
}

void Eveniment::setBilete(Bilet* bilete, int nrBilete)
{
	if (this->bilete != nullptr)
	{
		delete[]this->bilete;
		this->bilete = nullptr;
	}
	this->nrBilete = nrBilete;
	this->bilete = new Bilet[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		this->bilete[i] = bilete[i];
	}
}

void Eveniment::setNrBilete(int nrBilete)
{
	this->nrBilete = nrBilete;
}

void Eveniment::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

void Eveniment::setZone(char** zone, int nrZone)
{
	if (this->zone != nullptr)
	{
		delete[]this->zone;
		this->zone = nullptr;
	}
	this->nrZone = nrZone;
	this->zone = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		this->zone[i] = new char[strlen(zone[i]) + 1];
		strcpy_s(this->zone[i], strlen(zone[i]) + 1, zone[i]);
	}
}

void Eveniment::setNrLocuriZona(int nrLocuriZona)
{
	this->nrLocuriZona = nrLocuriZona;
}

void Eveniment::setLocZ(int* locZ, int nrZone)
{
	if (this->locZ != nullptr)
	{
		delete[]this->locZ;
		this->locZ = nullptr;
	}
	this->nrZone = nrZone;
	this->locZ = new int[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		this->locZ[i] = locZ[i];
	}
}

void Eveniment::setEvTot(int evTot)
{
	Eveniment::evTot = evTot;
}

//getteri

string Eveniment::getDenumire()
{
	return denumire;
}

Data Eveniment::getData()
{
	return data;
}

Bilet* Eveniment::getBilete()
{
	Bilet* copie;
	copie = new Bilet[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		copie[i] = bilete[i];
	}
	return copie;
}

int Eveniment::getNrBilete()
{
	return nrBilete;
}

int Eveniment::getNrZone()
{
	return nrZone;
}

char** Eveniment::getZone()
{
	char** copie;
	copie = new char* [nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = new char[strlen(zone[i]) + 1];
		strcpy_s(copie[i], strlen(zone[i]) + 1, zone[i]);
	}
	return copie;
}

int Eveniment::getNrLocuriZona()
{
	return nrLocuriZona;
}

int* Eveniment::getLocZ()
{
	int* copie;
	copie = new int[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = locZ[i];
	}
	return copie;
}

int Eveniment::getEvTot()
{
	return evTot;
}

//supraincarcari

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	denumire = e.denumire;
	data.an = e.data.an;
	data.luna = e.data.luna;
	data.zi = e.data.zi;
	data.ora = e.data.ora;
	data.minut = e.data.minut;
	if (bilete != nullptr)
	{
		delete[]bilete;
		bilete = nullptr;
	}

	if (e.nrBilete > 0)
	{
		if (e.bilete != nullptr)
		{
			bilete = new Bilet[e.nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				bilete[i] = e.bilete[i];
			}
		}
	}
	else
	{
		bilete = nullptr;
		nrBilete = 0;
	}

	if (zone != nullptr)
	{
		delete[]zone;
		zone = nullptr;
	}

	if (e.nrZone > 0)
	{
		if (e.zone != nullptr)
		{
			zone = new char* [e.nrZone];
			nrZone = e.nrZone;
			for (int i = 0; i < e.nrZone; i++)
			{
				zone[i] = new char[strlen(e.zone[i]) + 1];
				strcpy_s(zone[i], strlen(e.zone[i]) + 1, e.zone[i]);
			}
		}
	}
	else
	{
		zone = nullptr;
		nrZone = 0;
	}

	if (locZ != nullptr)
	{
		delete[]locZ;
		locZ = nullptr;
	}

	if (e.nrLocuriZona > 0)
	{
		if (e.locZ != nullptr)
		{
			locZ = new int[e.nrLocuriZona];
			nrZone = e.nrZone;
			for (int i = 0; i < e.nrLocuriZona; i++)
			{
				locZ[i] = e.locZ[i];
			}
		}
	}
	else
	{
		locZ = nullptr;
		nrLocuriZona = 0;
	}

	evTot = e.evTot;
	return *this;
}

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Numele evenimentului este: " << e.denumire << endl;
	out << "Data la care va avea loc este: " << e.data.zi << "/" << e.data.luna << "/" << e.data.an << ", la ora " << e.data.ora << ":" << e.data.minut << endl;
	out << "Biletele cumparate sunt: " << endl;
	for (int i = 0; i < e.nrBilete; i++)
	{
		out << e.bilete[i] << endl;
	}
	out << "Numarul total de evenimente este: " << e.evTot<<endl;
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Introduceti numele evenimentului: ";
	in >> e.denumire;
	cout << endl;
	cout << "Introduceti data si ora de forma zi/luna/an ora:minut: ";
	in >> e.data.zi >> e.data.luna >> e.data.an >> e.data.ora >> e.data.minut;
	cout << endl;
	return in;
}

ifstream& operator>>(ifstream& fin, Eveniment& e)
{
	fin >> e.denumire;
	fin >> e.data.zi >> e.data.luna >> e.data.an >> e.data.ora >> e.data.minut;
	return fin;
}

Eveniment& Eveniment::operator++()
{
	data.zi++;
	if (validareData(data) == 0)
	{
		data.zi = 1;
		data.luna++;
		if (validareData(data) == 0)
		{
			data.luna = 1;
			data.an++;
		}
	}
	return *this;
}

Eveniment& Eveniment::operator++(int i)
{
	Eveniment copie = *this;
	copie.data.zi++;
	if (validareData(copie.data) == 0)
	{
		copie.data.zi = 1;
		copie.data.luna++;
		if (validareData(copie.data) == 0)
		{
			copie.data.luna = 1;
			copie.data.an++;
		}
	}
	return *this;
}

bool Eveniment::operator<=(const Eveniment& e)
{
	if (nrBilete <= e.nrBilete)return true;
	else return false;
}