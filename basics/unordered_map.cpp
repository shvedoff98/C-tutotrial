#include <unordered_map>
#include <iostream>

int main(int argc, char* argv[])
{

    if ( argc < 2 ) 
    {
	fprintf (stderr, "Too few arguments.");
	return 1;
    }

    std::unordered_map<uint8_t, std::string> HDR {
	{ 0, "Undefined"    },
	{ 1, "BT.709"	    },
	{ 2, "Unspecified"  },
	{ 3, "Reserved"	    },
	{ 4, "BT.470M"	    },
	{ 5, "BT.470BG"	    },
	{ 6, "SMPTE 170M"   },
	{ 7, "SMPTE 240M"   },
	{ 8, "FILM"	    },
	{ 9, "BT.2020"	    },
	{ 10, "SMPTE 428"   },
	{ 11, "SMPTE 431"   },
	{ 12, "SMPTE 432"   },
	{ 22, "JEDEC P22" } };

	uint8_t ColorPrimaries = atoi(argv[1]);

	auto itr = HDR.find(ColorPrimaries);
	if (itr != HDR.end())
	{
	    std::cout << itr->second << "\n";
	}

	exit (EXIT_SUCCESS);
}
