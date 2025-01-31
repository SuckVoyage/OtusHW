#pragma once

#include <iostream>
#include <string>
#include <fstream>


class IpAdress
{
	int first;
	int second;
	int third;
	int fourth;
public:
	// ctors
	IpAdress(int first, int second, int third, int fourth)
		: first(first), second(second), third(third), fourth(fourth) {}

	IpAdress() : IpAdress(0, 0, 0, 0) {}

	// operators

	bool operator > (const IpAdress& other) const;
	bool operator < (const IpAdress& other) const;
	bool operator == (const IpAdress& other) const;
	bool operator != (const IpAdress& other) const;
	
	friend std::ostream& operator << (std::ostream& out, const IpAdress& object);

	// getters

	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }
	int getFourth() { return fourth; }
};

