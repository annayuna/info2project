/*
 * Streckenende.h
 *
 *  Created on: 03.12.2024
 *      Author: annaroessel
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme {
public:
	Streckenende(Weg& aWeg, const Fahrzeug& aFzg);
	virtual ~Streckenende();

	void vBearbeiten() const;
};

#endif /* STRECKENENDE_H_ */
