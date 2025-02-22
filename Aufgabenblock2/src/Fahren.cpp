/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2024
 *      Author: annaroessel
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren(Weg& aWeg) :
		Verhalten(aWeg)
{
}

Fahren::~Fahren()
{
}


double Fahren::dStrecke(const Fahrzeug& aFzg, const double dZeitIntervall) const
{
	// Distanz zum Wegende
	double dVerbleibendeStrecke = p_pWeg.getLaenge() - aFzg.getAbschnittStrecke();

	// Exception, falls am Streckenende angekommen
	if (dVerbleibendeStrecke < 1e-10)
	{
		throw Streckenende(p_pWeg, aFzg);
	}

	// Distanz, die das Fahrzeug ohne Einschränkungen zurücklegen könnte
	double dFahrzeugStrecke = aFzg.dGeschwindigkeit() * dZeitIntervall;

	return (dVerbleibendeStrecke < dFahrzeugStrecke) ? dVerbleibendeStrecke : dFahrzeugStrecke;
}
