#include <iostream>


Month operator++ (Month& m)
{
	m = (m == Month::Dec) ? Month::Jan : Month (int(m) +1);
	return m;
}
	
ostream& operator << (ostream& os, Month m)
{
	return os << month_tbl[int(m)];
}


int main(int argc, char* argv[])
{
		enum class Month {
		Jan = 1, Feb, Mar, Apr, May, June, Jule, Aug, Sep, Oct, Nov, Dec
	};



	Month m = Month::Sep;
	++m;
	++m;
	++m;
}