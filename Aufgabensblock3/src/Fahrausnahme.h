/*
 * Fahrausnahme.h
 *
 *  Created on: 03.12.2024
 *      Author: annaroessel
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception>

class Weg;
class Fahrzeug;

class Fahrausnahme : std::exception {
public:
	Fahrausnahme(Weg& aWeg, const Fahrzeug& aFzg);
	virtual ~Fahrausnahme();

	virtual void vBearbeiten() const = 0;

protected:
	Weg& p_pWeg;
	const Fahrzeug& p_pFahrzeug;
};

#endif /* FAHRAUSNAHME_H_ */
