/*
 * Fahren.h
 *
 *  Created on: 03.12.2024
 *      Author: annaroessel
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"

class Fahren : public Verhalten {
public:
	Fahren(Weg& aWeg);
	virtual ~Fahren();

	double dStrecke(const Fahrzeug& aFzg, const double dZeitIntervall) const override;

};

#endif /* FAHREN_H_ */
