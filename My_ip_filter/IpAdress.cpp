#include "IpAdress.h"

bool IpAdress::operator>(const IpAdress& other) const
{
	if (this->first > other.first) 
	{
		return true;
	}
	else 
	{
		if (this->first == other.first) {
			if (this->second > other.second)
			{
				return true;
			}
			else
			{
				if (this->second == other.second) {
					if (this->third > other.third)
					{
						return true;
					}
					else
					{
						if (this->third == other.third) {
							if (this->fourth > other.fourth)
							{
								return true;
							}
						}
						return false;
					}
				}
				else {
					return false;
				}
			}
		}
		else { return false; }
	}
}

bool IpAdress::operator < (const IpAdress& other) const
{
	if (*this > other)
	{
		return false;
	}
	return true;
}

bool IpAdress::operator == (const IpAdress& other) const
{
	if ((this->first == other.first) && (this->second == other.second)
		&& (this->third == other.third) && (this->fourth == other.fourth)) 
	{
		return true;
	}
	return false;
}

bool IpAdress::operator != (const IpAdress& other) const
{
	if (*this == other)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, const IpAdress& object)
{
	return out << object.first << "." << object.second << "." << object.third << "." << object.fourth;
}
