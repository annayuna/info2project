/*
 * Fahrzeug.cpp
 *
 *  Created on: 29.10.2024
 *      Author: annaroessel
 */

#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"

#include <iomanip>
#include <istream>


Fahrzeug::Fahrzeug() :
		Simulationsobjekt("")
{
	std::cout << "Fahrzeug mit ID " << p_iID << " wurde erstellt (default Konstruktor)." << std::endl;
}

Fahrzeug::Fahrzeug(const std::string& s, const double d):
		Simulationsobjekt(s), p_dMaxGeschwindigkeit((d>0)?d:0)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde erstellt." << std::endl;
}


Fahrzeug::~Fahrzeug()
{

}

void Fahrzeug::vKopf()
{
	std::cout<<std::resetiosflags(std::ios::right)<<std::setiosflags(std::ios::left);
	std::cout<<std::setw(4)<<"ID";
	std::cout<<std::setw(15)<<"Name";
	std::cout<<std::setw(35)<<"Momentangeschwindigkeit[km/h]";
	std::cout<<std::setw(20)<<"Gesamtstrecke";
	std::cout<<std::setw(22)<<"Gesamtverbrauch";
	std::cout<<std::setw(17)<<"Tankinhalt"<<std::endl;
	std::cout<<"----------------------------------------------------------------------------------------------------------"<<std::endl;
}

void Fahrzeug::vAusgeben(std::ostream& out) const
{
	Simulationsobjekt::vAusgeben(out);
	out<<std::setw(35)<< dGeschwindigkeit();
	out<<std::setw(20)<< p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren(){
	double dDiffZeit = dGlobaleZeit - p_dZeit;
	if(dDiffZeit <= 1e-10){
		return;
	}

	double dGefahreneStrecke = (p_pVerhalten == nullptr) ?
			dDiffZeit * dGeschwindigkeit() :
			p_pVerhalten->dStrecke(*this, dDiffZeit); //dStrecke von Verhalten wird aufgerufen,

	p_dGesamtStrecke += dGefahreneStrecke;
	p_dAbschnittStrecke += dGefahreneStrecke;
	p_dGesamtZeit += dDiffZeit;
	p_dZeit = dGlobaleZeit;
}

double Fahrzeug::dTanken(const double dMenge){
	return 0;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(const Fahrzeug& tFahrzeug) const
{
	return (p_dGesamtStrecke < tFahrzeug.p_dGesamtStrecke);
}

void Fahrzeug::operator=(const Fahrzeug& tFahrzeug)
{
	// Name und MaxGeschwindigkeit können nicht zugewiesen werden, da als const deklariert
	p_dGesamtStrecke = tFahrzeug.p_dGesamtStrecke;
	p_dGesamtZeit = tFahrzeug.p_dGesamtZeit;
	p_dZeit = tFahrzeug.p_dZeit;
}

void Fahrzeug::vNeueStrecke(Weg& aWeg)
{
	p_pVerhalten = std::make_unique<Fahren>(aWeg);
	p_dAbschnittStrecke = 0;
}

void Fahrzeug::vNeueStrecke(Weg& aWeg, const double dStartZeit)
{
	p_pVerhalten = std::make_unique<Parken>(aWeg, dStartZeit);
	p_dAbschnittStrecke = 0;
}

double Fahrzeug::getAbschnittStrecke() const
{
	return p_dAbschnittStrecke;
}

bool Fahrzeug::getbLiegengeblieben() const
{
    return p_bLiegengeblieben;
}

void Fahrzeug::vZeichnen(const Weg& aWeg) const
{
	std::cout << "Fehler: vZeichnen sollte immer in der Unterklasse ausgeführt werden." << std::endl;
}

void Fahrzeug::vEinlesen(std::istream& in)
{
	Simulationsobjekt::vEinlesen(in);
	in >> p_dMaxGeschwindigkeit;
}




