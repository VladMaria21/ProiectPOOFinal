#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Locatie.h";
#include "Eveniment.h";

using namespace std;

int Locatie::locTot = 0;

Locatie::Locatie() :nrLocMax(0)
{
	tip = "";
	nrZone = 0;
	zone = nullptr;
	nrLocTot = 0;
	nrRanduriTot = 0;
	nrLocZona = 0;
	nrRanduriZona = 0;
	ev = nullptr;
	nrEv = 0;
	preturi = nullptr;
	locTot++;
}

Locatie::Locatie(string tip, int nrZone, char** zone, int nrLocTot, int nrRanduriTot, int nrLocZona, int nrRanduriZona, float* preturi) :nrLocMax(nrLocMax)
{
	this->tip = tip;
	if (nrZone > 0)
	{
		if (zone != nullptr)
		{
			this->zone = new char* [nrZone];
			this->nrZone = nrZone;
			for (int i = 0; i < nrZone; i++)
			{
				this->zone[i] = new char[strlen(zone[i]) + 1];
				strcpy_s(this->zone[i], strlen(zone[i]) + 1, zone[i]);
			}
		}
	}
	else
	{
		this->zone = nullptr;
		this->nrZone = 0;
	}
	this->nrLocTot = nrLocTot;
	this->nrRanduriTot = nrRanduriTot;
	this->nrLocZona = nrLocZona;
	this->nrRanduriZona = nrRanduriZona;
	ev = nullptr;
	nrEv = 0;
	if (nrZone > 0)
	{
		if (preturi != nullptr)
		{
			this->preturi = new float[nrZone];
			this->nrZone = nrZone;
			for (int i = 0; i < nrZone; i++)
			{
				this->preturi[i] = preturi[i];
			}
		}
	}
	else
	{
		this->preturi = nullptr;
		this->nrZone = 0;
	}
	locTot++;
}

Locatie::Locatie(const Locatie& l) :nrLocMax(l.nrLocMax)
{
	tip = l.tip;
	if (l.nrZone > 0)
	{
		if (l.zone != nullptr)
		{
			zone = new char* [l.nrZone];
			nrZone = l.nrZone;
			for (int i = 0; i < l.nrZone; i++)
			{
				zone[i] = new char[strlen(l.zone[i]) + 1];
				strcpy_s(zone[i], strlen(l.zone[i]) + 1, l.zone[i]);
			}
		}
	}
	else
	{
		zone = nullptr;
		nrZone = 0;
	}
	nrLocTot = l.nrLocTot;
	nrRanduriTot = l.nrRanduriTot;
	nrLocZona = l.nrLocZona;
	nrRanduriZona = l.nrRanduriZona;

	if (l.nrEv > 0)
	{
		if (l.ev != nullptr)
		{
			ev = new Eveniment[l.nrEv];
			nrEv = l.nrEv;
			for (int i = 0; i < l.nrEv; i++)
			{
				ev[i] = l.ev[i];
			}
		}
	}
	else
	{
		ev = nullptr;
		nrEv = 0;
	}
	if (l.nrZone > 0)
	{
		if (l.preturi != nullptr)
		{
			preturi = new float[l.nrZone];
			nrZone = l.nrZone;
			for (int i = 0; i < nrZone; i++)
			{
				preturi[i] = l.preturi[i];
			}
		}
	}
	else
	{
		preturi = nullptr;
		nrZone = 0;
	}
	locTot = l.locTot;
}

Locatie::~Locatie()
{
	if (zone != nullptr)
	{
		delete[]zone;
		zone = nullptr;
	}
	nrZone = 0;
	if (ev != nullptr)
	{
		delete[]ev;
		ev = nullptr;
	}
	nrEv = 0;
	if (preturi != nullptr)
	{
		delete[]preturi;
		preturi = nullptr;
	}
	nrZone = 0;
}

float Locatie::pretMediu(float* preturi)
{
	float medie = 0;
	if (nrZone > 0)
	{
		for (int i = 0; i < nrZone; i++)
		{
			medie += preturi[i];
		}
		medie /= nrZone;
	}
	return medie;
}

//setteri

void Locatie::setTip(string tip)
{
	this->tip = tip;
}

void Locatie::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

void Locatie::setZone(char** zone, int nrZone)
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

void Locatie::setNrLocTot(int nrLocTot)
{
	this->nrLocTot = nrLocTot;
}

void Locatie::setNrRanduriTot(int nrRanduriTot)
{
	this->nrRanduriTot = nrRanduriTot;
}

void Locatie::setNrLocZona(int nrLocZona)
{
	this->nrLocZona = nrLocZona;
}

void Locatie::setNrRanduriZona(int nrRanduriZona)
{
	this->nrRanduriZona = nrRanduriZona;
}

void Locatie::setEv(Eveniment* ev, int nrEv)
{
	if (this->ev != nullptr)
	{
		delete[]this->ev;
		this->ev = nullptr;
	}
	this->nrEv = nrEv;
	this->ev = new Eveniment[nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		this->ev[i] = ev[i];
	}
}

void Locatie::setNrEv(int nrEv)
{
	this->nrEv = nrEv;
}

void Locatie::setPreturi(float* preturi, int nrZone)
{
	if (this->preturi != nullptr)
	{
		delete[]this->preturi;
		this->preturi = nullptr;
	}
	this->nrZone = nrZone;
	this->preturi = new float[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		this->preturi[i] = preturi[i];
	}
}

void Locatie::setLocTot(int locTot)
{
	Locatie::locTot = locTot;
}

//getteri

string Locatie::getTip()
{
	return tip;
}

int Locatie::getNrZone()
{
	return nrZone;
}

char** Locatie::getZone()
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

int Locatie::getNrLocTot()
{
	return nrLocTot;
}

int Locatie::getNrRanduriTot()
{
	return nrRanduriTot;
}

int Locatie::getNrLocZona()
{
	return nrLocZona;
}

int Locatie::getNrRanduriZona()
{
	return nrRanduriZona;
}

Eveniment* Locatie::getEv()
{
	Eveniment* copie;
	copie = new Eveniment[nrEv];
	for (int i = 0; i < nrEv; i++)
	{
		copie[i] = ev[i];
	}
	return copie;
}

int Locatie::getNrEv()
{
	return nrEv;
}

float* Locatie::getPreturi()
{
	float* copie;
	copie = new float[nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie[i] = preturi[i];
	}
	return copie;
}

int Locatie::getLocTot()
{
	return locTot;
}

//supraincarcari

Locatie& Locatie::operator=(const Locatie& l)
{
	tip = l.tip;
	if (l.nrZone > 0)
	{
		if (l.zone != nullptr)
		{
			zone = new char* [l.nrZone];
			nrZone = l.nrZone;
			for (int i = 0; i < l.nrZone; i++)
			{
				zone[i] = new char[strlen(l.zone[i]) + 1];
				strcpy_s(zone[i], strlen(l.zone[i]) + 1, l.zone[i]);
			}
		}
	}
	else
	{
		zone = nullptr;
		nrZone = 0;
	}
	nrLocTot = l.nrLocTot;
	nrRanduriTot = l.nrRanduriTot;
	nrLocZona = l.nrLocZona;
	nrRanduriZona = l.nrRanduriZona;

	if (l.nrEv > 0)
	{
		if (l.ev != nullptr)
		{
			ev = new Eveniment[l.nrEv];
			nrEv = l.nrEv;
			for (int i = 0; i < l.nrEv; i++)
			{
				ev[i] = l.ev[i];
			}
		}
	}
	else
	{
		ev = nullptr;
		nrEv = 0;
	}
	if (l.nrZone > 0)
	{
		if (l.preturi != nullptr)
		{
			preturi = new float[l.nrZone];
			nrZone = l.nrZone;
			for (int i = 0; i < nrZone; i++)
			{
				preturi[i] = l.preturi[i];
			}
		}
	}
	else
	{
		preturi = nullptr;
		nrZone = 0;
	}
	locTot = l.locTot;
	return *this;
}

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Tipul locatiei este: " << l.tip<<endl;
	out << "Numarul de zone al locatiei este: " << l.nrZone<<endl;
	out << "Acestea sunt: ";
	for (int i = 0; i < l.nrZone; i++)
	{
		out << l.zone[i] << " ";
	}
	out << endl;
	out << "Numarul total de locuri al locatiei este: " << l.nrLocTot<<endl;
	out << "Numarul total de randuri al locatiei este: " << l.nrRanduriTot<<endl;
	out << "Numarul de locuri al fiecarei zone este: " << l.nrLocZona<<endl;
	out << "Numarul de randuri al fiecarei zone este: " << l.nrRanduriZona<<endl;
	out << "Evenimentele existente sunt: " << endl;
	for (int i = 0; i < l.nrEv; i++)
	{
		out << l.ev[i] << endl;
	}
	out << "Preturile biletelor sunt: " << endl;
	for (int i = 0; i < l.nrZone; i++)
	{
		out << l.preturi[i] << " pentru zona " << l.zone[i] << endl;
	}
	out << "Numarul total de locatii este: " << l.locTot << endl;
	out << "Numarul maxim de locuri al locatiei este: " << l.nrLocMax << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Introduceti tipul locatiei: ";
	in >> l.tip;
	cout << endl;
	cout << "Introduceti numarul de zone: ";
	in >> l.nrZone;
	cout << endl;
	l.zone = new char* [l.nrZone];
	cout << "Introduceti zonele: ";
	char inter[256];
	for (int i = 0; i < l.nrZone; i++)
	{
		in >> inter;
		l.zone[i] = new char[strlen(inter) + 1];
		strcpy_s(l.zone[i], strlen(inter) + 1, inter);
		cout << endl;
	}
	cout << endl;
	cout << "Introduceti numarul total de locuri al locatiei: ";
	in >> l.nrLocTot;
	cout << endl;
	cout << "Introduceti numarul total de randuri al locatiei: ";
	in >> l.nrRanduriTot;
	cout << endl;
	cout << "Introduceti numarul de locuri al fiecarei zone: ";
	in >> l.nrLocZona;
	cout << endl;
	cout << "Introduceti numarul de randuri al fiecarei zone: ";
	in >> l.nrRanduriZona;
	cout << endl;
	cout << "Introduceti preturile biletelor pentru fiecare zona:";
	l.preturi = new float[l.nrZone];
	for (int i = 0; i < l.nrZone; i++)
	{
		cout << endl;
		cout << "Pentru zona " << l.zone[i] << ": ";
		in >> l.preturi[i];
	}
	cout << endl;
	return in;
}

ifstream& operator>>(ifstream& fin, Locatie& l)
{
	getline(fin, l.tip);
	fin >> l.nrZone;
	l.zone = new char* [l.nrZone];
	char inter[256];
	for (int i = 0; i < l.nrZone; i++)
	{
		//citeste pana la spatiu
		fin >> inter;
		l.zone[i] = new char[strlen(inter) + 1];
		strcpy_s(l.zone[i], strlen(inter) + 1, inter);
		cout << endl;
	}
	fin >> l.nrLocTot;
	fin >> l.nrRanduriTot;
	fin >> l.nrLocZona;
	fin >> l.nrRanduriZona;
	l.preturi = new float[l.nrZone];
	for (int i = 0; i < l.nrZone; i++)
	{
		fin >> l.preturi[i];
	}
	return fin;
}

Locatie& Locatie::operator+(const Locatie& l)
{
	Locatie copie = *this;
	for (int i = 0; i < copie.nrZone; i++)
	{
		copie.preturi[i] = preturi[i] + l.preturi[i];
	}
	return copie;
}

float Locatie::operator[](int index)
{
	if (index >= 0 && index <= nrZone)
	{
		return preturi[index];
	}
	else return 0;
}