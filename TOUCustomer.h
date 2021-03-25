#include "Customer.h"

#pragma once

#ifndef TOUCUSTOMER
#define TOUCUSTOMER
class TOUCustomer : protected Customer {

public:

	//TOUCustmer Constructor
	TOUCustomer(Reading [], int);

	//Default Constructor
	TOUCustomer();

	//Destructor
	~TOUCustomer();

	double computeBalance()  override;

	//Accessor Methods
	double getTotalKW();

	double getBalance();
};
#endif // !TOUCustomer

