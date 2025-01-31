#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include "IpAdress.h"



class IpPool
{
	std::vector<IpAdress> ipPool;
	std::string path;
public:
	IpPool(std::vector<IpAdress>& pool) : ipPool(pool) {}

	IpPool(std::string path);

	void print_where() const;
	void print_where(int first) const;
	void print_where(int first, int second) const;
	void print_where_anyone(int anyone) const;

};

