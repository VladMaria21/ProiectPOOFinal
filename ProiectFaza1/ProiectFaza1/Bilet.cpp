#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Bilet.h";

using namespace std;

int Bilet::bileteTot = 0;

Bilet::Bilet()
{
	bileteTot++;
	nrBilet = bileteTot;
	tip = "";
	for (int i = 0; i < 13; i++)cnp[i] = 0;
	uid = nullptr;
	lungUid = 0;
	rez = 0;
}

Bilet::Bilet(string tip, int* cnp)
{
	bileteTot++;
	nrBilet = bileteTot;
	this->tip = tip;
	for (int i = 0; i < 13; i++)this->cnp[i] = cnp[i];

	int copie = nrBilet;
	int lung = 0;
	while (copie)
	{
		lung++;
		copie /= 10;
	}
	copie = nrBilet;
	int* v;
	v = new int[lung];
	for (int i = lung - 1; i >= 0; i--)
	{
		v[i] = copie % 10;
		copie /= 10;
	}
	lungUid = lung + 6;//lungimea nr de bilete + 6 caractere din cnp
	uid = new int[lungUid];
	int j = 6;
	for (int i = 0; i < lungUid; i++)
	{
		if (i < lung)uid[i] = v[i];
		else
		{
			uid[i] = cnp[j - 1];
			uid[i + 1] = cnp[j];
			i++;
			j = j - 2;
		}
	}
	rez = 1;
}

Bilet::Bilet(const Bilet& b)
{
	bileteTot = b.bileteTot;
	nrBilet = b.nrBilet;
	tip = b.tip;
	for (int i = 0; i < 13; i++)cnp[i] = b.cnp[i];
	lungUid = b.lungUid;
	uid = new int[lungUid];
	for (int i = 0; i < lungUid; i++)uid[i] = b.uid[i];
	rez = b.rez;
}

Bilet::~Bilet()
{
	if (uid != nullptr)delete[]uid;
	uid = nullptr;
	bileteTot--;
}

int Bilet::validareUid(int* copie)
{
	if (copie == nullptr)return 0;
	else
	{
		for (int i = 0; i < lungUid; i++)
		{
			if (copie[i] != uid[i])return 0;
		}
	}
	return 1;
}

int Bilet::calculVip()
{
	if (tip != "")
	{
		if (tip == "film") pretVip = 100;
		else if (tip == "piesa de teatru") pretVip = 150;
		else if (tip == "meci sportiv") pretVip = 200;
	}
	return pretVip;
}

//setteri

void Bilet::setTip(string tip)
{
	this->tip = tip;
}

void Bilet::setCnp(int* cnp)
{
	for (int i = 0; i < 13; i++)this->cnp[i] = cnp[i];
}

void Bilet::setUid(int* uid, int lungUid)
{
	this->lungUid = lungUid;
	this->uid = new int[lungUid];
	for (int i = 0; i < lungUid; i++)this->uid[i] = uid[i];
}

void Bilet::setLungUid(int lungUid)
{
	this->lungUid = lungUid;
}

void Bilet::setNrBilet(int nrBilet)
{
	this->nrBilet = nrBilet;
}

void Bilet::setRez(int rez)
{
	this->rez = rez;
}

void Bilet::setBileteTot(int bileteTot)
{
	Bilet::bileteTot = bileteTot;
}

//getteri

string Bilet::getTip()
{
	return tip;
}

int* Bilet::getCnp()
{
	return cnp;
}

int* Bilet::getUid()
{
	int* copie;
	copie = new int[lungUid];
	for (int i = 0; i < lungUid; i++)copie[i] = uid[i];
	return copie;
}

int Bilet::getLungUid()
{
	return lungUid;
}

int Bilet::getNrBilet()
{
	return nrBilet;
}

int Bilet::getRez()
{
	return rez;
}

int Bilet::getBileteTot()
{
	return bileteTot;
}

//supraincarcari

Bilet& Bilet::operator=(const Bilet& b)
{
	tip = b.tip;
	for (int i = 0; i < 13; i++)cnp[i] = b.cnp[i];
	lungUid = b.lungUid;
	uid = new int[lungUid];
	for (int i = 0; i < lungUid; i++)uid[i] = b.uid[i];
	rez = b.rez;
	bileteTot = b.bileteTot;
	return *this;
}

ostream& operator<<(ostream& out, Bilet b)
{
	out << "Tipul biletului: " << b.tip << endl;
	out << "Uid-ul biletului: ";
	for (int i = 0; i < b.lungUid; i++)out << b.uid[i];
	out << endl;
	if (b.rez == 0)out << "Biletul nu este rezervat" << endl;
	else out << "Biletul este rezervat" << endl;
	out << "Numarul total de bilete este: " << b.bileteTot<<endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Introduceti tipul biletului: ";
	in >> b.tip;
	cout << endl;
	cout << "Introduceti cnp-ul: ";
	char nr[14];
	in >> nr;
	for (int i = 0; i < 13; i++)
	{
		b.cnp[i] = nr[i] - 48;
	}

	//generare uid
	int copie = b.nrBilet;
	int lung = 0;
	while (copie)
	{
		lung++;
		copie /= 10;
	}

	b.lungUid = lung + 6;

	copie = b.nrBilet;
	int* v;
	v = new int[lung];
	for (int i = lung - 1; i >= 0; i--)
	{
		v[i] = copie % 10;
		copie /= 10;
	}

	b.uid = new int[lung + 6];
	int j = 6;
	for (int i = 0; i < lung + 6; i++)
	{
		if (i < lung)b.uid[i] = v[i];
		else
		{
			b.uid[i] = b.cnp[j - 1];
			b.uid[i + 1] = b.cnp[j];
			i++;
			j = j - 2;
		}
	}

	cout << endl;
	cout << "Uid-ul biletului cumparat este: ";
	for (int i = 0; i < b.lungUid; i++)cout << b.uid[i];
	cout << endl;
	b.rez = 1;
	return in;
}

ifstream& operator>>(ifstream& fin, Bilet& b)
{

	getline(fin, b.tip);
	char nr[14];
	fin >> nr;

	for (int i = 0; i < 13; i++)
	{
		b.cnp[i] = nr[i] - 48;
	}

	//generare uid
	int copie = b.nrBilet;
	int lung = 0;
	while (copie)
	{
		lung++;
		copie /= 10;
	}

	b.lungUid = lung + 6;

	copie = b.nrBilet;
	int* v;
	v = new int[lung];
	for (int i = lung - 1; i >= 0; i--)
	{
		v[i] = copie % 10;
		copie /= 10;
	}

	b.uid = new int[lung + 6];
	int j = 6;
	for (int i = 0; i < lung + 6; i++)
	{
		if (i < lung)b.uid[i] = v[i];
		else
		{
			b.uid[i] = b.cnp[j - 1];
			b.uid[i + 1] = b.cnp[j];
			i++;
			j = j - 2;
		}
	}
	b.rez = 1;
	return fin;
}

bool Bilet::operator!()
{
	return rez != 0;
}

bool Bilet::operator==(const Bilet& b)
{
	for (int i = 0; i < 13; i++)
	{
		if (cnp[i] != b.cnp[i])return 0;
	}
	return 1;
}