// My_ip_filter.cpp 


#include "IpPool.h"
#include "Version.h"








int main()
{
	IpPool pool("C:\\Users\\SuckVoyage\\Desktop\\мои коды\\Ip_filter\\My_ip_filter\\ip_filter.tsv");
	pool.print_where();
	pool.print_where(1);
	pool.print_where(46, 70);
	pool.print_where_anyone(46);


	std::cout << "Version = " << version::version();
}

