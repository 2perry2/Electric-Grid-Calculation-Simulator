#pragma once

#include "Customer.h"
#include "Reading.h"

#ifndef TIER
#define TIER
class TIERCustomer : protected Customer {
public:

	//Constructors and destructors
	TIERCustomer(Reading [], int);
	TIERCustomer();
	~TIERCustomer();

	//Accessor Method
	double getTotalKW();

	double getBalance();

	double computeBalance()  override;
};
#endif // !TIERCustomer

