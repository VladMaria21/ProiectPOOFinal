#include <iostream>
#include <string.h>
#include <fstream>
#include "Locatie.h";
#include "Eveniment.h";
#include "Bilet.h";
#include "Invitatie.h";

int main()
{
	//fisierul binar
	ofstream bout;
	bout.open("fisierBinar.bin", ios::out | ios::binary | ios::app);
	//fisierul txt
	ifstream fin;
	fin.open("FisierDateIntrare.txt", ios::in);

	Locatie locatii[100], l;
	Eveniment e;
	Bilet b;
	int nrLoc = 0, nrEv[100] = {0}, nrB[100][100]={0};
	int loc, ev;
	int modalitate, x;

	do
	{
		//alegerea metodei de introducere a datelor
		cout << "In ce fel doriti sa introduceti datele?" << endl;
		cout << "1. La consola." << endl;
		cout << "2. Prin fisier text." << endl;
		cout << "3. Inchide programul." << endl;
		cout << "Optiunea aleasa: ";
		cin >> modalitate;
		if (modalitate == 1 || modalitate == 2)
		{
			do
			{
				//alegerea optiunilor
				cout << endl;
				cout << "Alegeti o actiune:" << endl;
				cout << "1. Adaugare bilet." << endl;
				cout << "2. Adaugare eveniment." << endl;
				cout << "3. Adaugare locatie." << endl;
				cout << "4. Afisare locatii." << endl;
				cout << "5. Afisare evenimente." << endl;
				cout << "6. Inchide programul." << endl;
				cout << "Optiunea aleasa: ";
				if (modalitate == 2)
				{
					fin >> x;
					if (fin.fail())
					{
						cout << endl;
						cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
						modalitate = 3;
						break;
					}
					else cout << x << endl;
				}
				else cin >> x;
				if (x == 1)
				{
					cout << endl;
					cout << "Alegeti o locatie: ";
					if (modalitate == 2)
					{
						fin >> loc;
						if (fin.fail())
						{
							cout << endl;
							cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
							modalitate = 3;
							break;
						}
						else cout << loc << endl;
					}
					else cin >> loc;
					if (loc<nrLoc || loc>nrLoc)cout << "Locatia nu exista." << endl;
					else
					{
						cout << "Pentru ce eveniment doriti sa cumparati bilet?" << endl;
						cout << "Numele evenimentului: ";
						string denumire;
						if (modalitate == 2)
						{
							getline(fin, denumire);
							if (fin.fail())
							{
								cout << endl;
								cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
								modalitate = 3;
								break;
							}
							else cout << denumire << endl;
						}
						else cin >> denumire;
						ev = -1;
						for (int i = 0; i < nrEv[loc]; i++)
						{
							if (denumire == locatii[loc].getEv()[i].getDenumire()) ev = i;
						}
						if (ev == -1)cout << "Evenimentul nu exista.";
						else
						{
							cout << endl;
							if (modalitate == 2)
							{
								fin >> b;
								if (fin.fail())
								{
									cout << endl;
									cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
									modalitate = 3;
									break;
								}
							}
							else cin >> b;

							e = locatii[loc].getEv()[ev];
							e.setBilete(&b, 1);
							locatii[loc].setEv(&e, 1);

							nrB[loc][ev]++;

							//scriere in fisierul binar

							int lungime;
							lungime = b.getTip().length();
							bout.write((char*)&lungime, sizeof(lungime));
							bout.write(b.getTip().c_str(), lungime + 1);
							bout.write((char*)b.getCnp(), 14);
							lungime = b.getLungUid();
							bout.write((char*)&lungime, sizeof(lungime));
							bout.write((char*)b.getUid(), sizeof(b.getUid()));
							bout.write((char*)b.getLungUid(), sizeof(b.getLungUid()));
							bout.write((char*)b.getNrBilet(), sizeof(b.getNrBilet()));
							bout.write((char*)b.getRez(), sizeof(b.getRez()));
							bout.write((char*)b.getBileteTot(), sizeof(b.getBileteTot()));

							cout << "Biletul a fost inregistrat!" << endl;
						}
					}
					cout << endl;

				}
				else if (x == 2)
				{
					cout << endl;
					cout << "In ce locatie se afla evenimentul?" << endl;
					cout << "Numar locatie: ";
					if (modalitate == 2)
					{
						fin >> loc;
						if (fin.fail())
						{
							cout << endl;
							cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
							modalitate = 3;
							break;
						}
						else cout << loc << endl;
					}
					else cin >> loc;
					if (loc<nrLoc || loc>nrLoc)cout << "Locatia nu exista." << endl;
					else
					{
						cout << endl;
						if (modalitate == 2)
						{
							fin >> e;
							if (fin.fail())
							{
								cout << endl;
								cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
								modalitate = 3;
								break;
							}
						}
						else cin >> e;
						locatii[loc].setEv(&e, 1);

						nrEv[loc]++;
						cout << "Evenimentul a fost inregistrat!" << endl;
					}
					cout << endl;
				}
				else if (x == 3)
				{
					cout << endl;
					if (modalitate == 2)
					{
						fin >> l;
						if (fin.fail())
						{
							cout << endl;
							cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
							modalitate = 3;
							break;
						}
					}
					else cin >> l;
					locatii[nrLoc] = l;
					nrLoc++;
					cout << "Locatia a fost inregistrata!" << endl;
				}
				else if (x == 4)
				{
					if (nrLoc < 1)cout << "Nu exista locatii inregistrate la momentul actual." << endl;
					else
					{
						cout << endl;
						for (int i = 0; i < nrLoc; i++)
						{
							cout << "Locatia " << i + 1 << " :" << endl;
							cout << locatii[i] << endl;
						}
						cout << endl;
					}

				}
				else if (x == 5)
				{
					if (nrLoc < 1)cout << "Nu exista locatii sau evenimente inregistrate la momentul actual." << endl;
					else
					{
						cout << "Pentru ce locatie doriti sa se afiseze evenimentele?" << endl;
						if (modalitate == 2)
						{
							fin >> loc;
							if (fin.fail())
							{
								cout << endl;
								cout << "Fisierul text nu contine date corecte. Programul se va inchide." << endl;
								modalitate = 3;
								break;
							}
							else cout << loc << endl;
						}
						else cin >> loc;
						if (loc<nrLoc || loc>nrLoc)cout << "Locatia nu exista." << endl;
						else if (nrEv[loc] < 1)cout << "Nu exista evenimente inregistrate pentru locatia aleasa la momentul actual." << endl;
						else
						{
							cout << endl;
							for (int i = 0; i < nrEv[loc]; i++)
							{
								cout << "Evenimentul " << i + 1 << " :" << endl;
								e = locatii[loc].getEv()[i];
								cout << e << endl;
							}
							cout << endl;
						}
					}

				}
				else if (x == 6)
				{
					cout << "Programul s-a finalizat." << endl;
					modalitate = 3;
					break;
				}
				else
				{
					cout << "Va rugam sa alegeti una dintre optiunile puse la dispozitie." << endl;
				}
			} while (x != 6);
		}
		else if (modalitate == 3)
		{
			cout << "Programul s-a finalizat.";
			break;
		}
		else
		{
			cout << "Va rugam introduceti o optiune valida.";
		}

	} while (modalitate != 3);

	fin.close();
	bout.close();

	return 0;
}