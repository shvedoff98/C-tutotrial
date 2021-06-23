#ifndef _REMOVE_LINES_H
#define _REMOVE_LINES_H

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>


class Cleaner 
{
    private:
	std::ifstream input;
	std::vector<std::string> vec;

    public:

	Cleaner(std::string&&);

	void print_vec();
	void rm_empty_lines();
	void write(std::string&&);
	virtual ~Cleaner();

};



Cleaner::~Cleaner()
{
}



Cleaner::Cleaner(std::string&& file) : input (file, std::istream::in)
{
}



void Cleaner::print_vec()
{
    if (!vec.empty())
    {
    	for (auto const& x :vec)
    	{
    	    std::cout << x << "\n";
    	}
    }
    else
    {
    	throw std::runtime_error ("Vector is empty! Check the content of parsing file!\n" 
				"Or first call Cleaner::rm_empty_lines()\n");
    }

}



void Cleaner::rm_empty_lines()
{
    std::string str;
    while (std::getline(input, str))
    {
		if ( str.find_first_not_of((" \t\n\v\f\r")) != std::string::npos)
		{
		    vec.push_back(str);
		}
    }
}


void Cleaner::write(std::string&& str)
{
    std::ofstream output_file {str};
    std::ostream_iterator <std::string> ost (output_file, "\n");
    std::copy (begin(vec), end(vec), ost);
}

#endif
