#include "IpPool.h"
#include "fstream"
#include <stdexcept>

auto str_to_int(std::string& str)
{
	std::string tmp;
	int iIp[4];
	int i = 0;
	for (char ch : str)
	{
		if (ch != '.')
		{
			tmp += ch;
		}
		if (ch == '.')
		{
			iIp[i] = stoi(tmp);
			i++;
			tmp.resize(0);
		}
	}
	iIp[i] = stoi(tmp);
	return IpAdress(iIp[0], iIp[1], iIp[2], iIp[3]);
}

IpPool::IpPool(std::string path) :path(path)
{
	std::string adress;

	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open()) 
	{
		throw std::runtime_error("File is not open");
	}
	int i = 0;
	while (!fin.eof()) 
	{
		if (fin.eof()) 
		{
			break;
		}
		fin >> adress;
		if (i % 3 == 0 && adress != "")
		{
			ipPool.push_back(str_to_int(adress));
		}
		adress.clear();
		i++;
	}
	fin.close();
	std::sort(ipPool.begin(), ipPool.end(), [](IpAdress& a, IpAdress& b) -> bool {return a > b; });
}

void IpPool::print_where() const
{
	for (IpAdress adress : ipPool) 
	{
		std::cout << adress << std::endl;
	}
}

void IpPool::print_where(int first) const
{
	for (IpAdress adress : ipPool)
	{
		if (adress.getFirst() == first)
			std::cout << adress << std::endl;
	}
}

void IpPool::print_where(int first, int second) const
{
	for (IpAdress adress : ipPool)
	{
		if (adress.getFirst() == first && adress.getSecond() == second)
			std::cout << adress << std::endl;
	}
}

void IpPool::print_where_anyone(int anyone) const
{
	for (IpAdress adress : ipPool)
	{
		if (adress.getFirst() == anyone || adress.getSecond() == anyone 
			|| adress.getThird() == anyone || adress.getFourth() == anyone)
			std::cout << adress << std::endl;
	}
}
