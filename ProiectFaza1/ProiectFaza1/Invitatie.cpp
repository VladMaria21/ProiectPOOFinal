#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Bilet.h";
#include "Invitatie.h";

using namespace std;

Invitatie::Invitatie():Bilet()
{
	nume = "";
	prenume = "";
}

Invitatie::Invitatie(string tip, int* cnp, string nume, string prenume) :Bilet(tip, cnp)
{
	this->nume = nume;
	this->prenume = prenume;
}

Invitatie::Invitatie(const Invitatie& i) :Bilet(i)
{
	nume = i.nume;
	prenume = i.prenume;
}

int Invitatie::calculVip()
{
	
	if (Bilet::tip != "")
	{
		if (tip == "film") pretVip = 70;
		else if (tip == "piesa de teatru") pretVip = 100;
		else if (tip == "meci sportiv") pretVip = 130;
	}
	return pretVip;
}

//setteri

void Invitatie::setNume(string nume)
{
	this->nume = nume;
}
void Invitatie::setPrenume(string prenume)
{
	this->prenume = prenume;
}

//getteri

string Invitatie::getNume()
{
	return nume;
}
string Invitatie::getPrenume()
{
	return prenume;
}

//supraincarcari

Invitatie& Invitatie::operator=(const Invitatie& i)
{
	Bilet::operator=(i);
	nume = i.nume;
	prenume = i.prenume;
	return *this;
}

ostream& operator<<(ostream& out, Invitatie i)
{
	out << "Numele invitatului este: " << i.nume <<" "<<i.prenume << endl;
	out << "Tipul biletului: " << i.tip << endl;
	out << "Uid-ul biletului: ";
	for (int y = 0; y < i.getLungUid(); y++)out << i.getUid()[y];
	out << endl;
	if (i.getRez() == 0)out << "Biletul nu este rezervat" << endl;
	else out << "Biletul este rezervat" << endl;
	out << "Numarul total de bilete este: " << i.getBileteTot() << endl;
	return out;
}

