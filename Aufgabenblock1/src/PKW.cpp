/*
 * PKW.cpp
 *
 *  Created on: 02.12.2024
 *      Author: annaroessel
 */

#include "PKW.h"

#include <iostream>
#include <iomanip>

PKW::PKW(const std::string& sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen) :
Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch),
p_dTankvolumen(dTankvolumen), p_dTankinhalt(p_dTankvolumen / 2)
{
}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

double PKW::dTanken(const double dMenge){
	double dTankinhaltAlt = p_dTankinhalt;
	double dTestTankinhalt = p_dTankinhalt + dMenge;
	p_dTankinhalt = (dTestTankinhalt > p_dTankvolumen) ? p_dTankvolumen : dTestTankinhalt;
	return (p_dTankinhalt - dTankinhaltAlt);
}


void PKW::vSimulieren(){
	if (p_dTankinhalt <= 0){
		return;
	}
	double dStreckeAlt = p_dGesamtStrecke;
	Fahrzeug::vSimulieren();
	double dStrecke = p_dGesamtStrecke - dStreckeAlt;
	double dTestTankinhalt = p_dTankinhalt - dStrecke * p_dVerbrauch/100;
	p_dTankinhalt = (dTestTankinhalt < 0) ? 0 : dTestTankinhalt;
}

void PKW::vAusgeben(std::ostream& out) const
{
	Fahrzeug::vAusgeben(out);
	out<<std::setw(22)<< p_dGesamtStrecke * p_dVerbrauch/100;
	out<<std::setw(17)<< p_dTankinhalt;
}
