/*
 * Fahrrad.cpp
 *
 *  Created on: 31.10.2024
 *      Author: annaroessel
 */

#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"

#include <cmath>

Fahrrad::Fahrrad(const std::string& sName, const double dMaxGeschwindigkeit) :
		Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad()
{
}



double Fahrrad::dGeschwindigkeit() const
{
	// Berechnung Geschwindigkeit als exponentielles Abklingen
	double dGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, floor(p_dGesamtStrecke/20));

	// Geschwindigkeit kleiner als 12 km/h ausschließen
	return (dGeschwindigkeit < 12) ? 12 : dGeschwindigkeit;
}

void Fahrrad::vZeichnen(const Weg& aWeg) const
{
	double dRelPosition = p_dAbschnittStrecke / aWeg.getLaenge();
	bZeichneFahrrad(p_sName, aWeg.getName(), dRelPosition, dGeschwindigkeit());
}

void Fahrrad::vEinlesen(std::istream& in)
{
	Fahrzeug::vEinlesen(in);
}
