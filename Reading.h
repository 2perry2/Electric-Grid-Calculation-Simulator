#pragma once
#ifndef reading
#define reading


class Reading {

private:
	float meterRead;
	int hour;

public:

	Reading();
	Reading(int, float);
	~Reading();

	//Accessor methods

	float getMeterRead();
	int getHour();

	//mutator methods
	void setMeterRead(float);
	void setHour(int);
};
#endif // !reading