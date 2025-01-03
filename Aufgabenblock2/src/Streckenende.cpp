/*
 * Streckenende.cpp
 *
 *  Created on: 03.12.2024
 *      Author: annaroessel
 */

#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>

Streckenende::Streckenende(Weg& aWeg, const Fahrzeug& aFzg) :
		Fahrausnahme(aWeg, aFzg)
{
}

Streckenende::~Streckenende()
{
}


void Streckenende::vBearbeiten() const
{
	std::cout << "Exception: Fahrzeug " << p_pFahrzeug.getName() << " auf Weg "
				<< p_pWeg.getName() << " ist am Wegende." << std::endl;

	// Fahrzeug wird aus der Fahrzeugliste entfernt
	//std::unique_ptr<Fahrzeug> aFzgTemp =
	p_pWeg.pAbgabe(p_pFahrzeug);

}
