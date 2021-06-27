#include <iostream>
#include <string>
#include <exception>

class dublicate
{
private:

    std::string prev;
    std::string curr;
public:

    explicit dublicate () : prev (""), curr ("") {}
    ~dublicate () {} 
    void check_prev () { std::cout << "Now previous becomes "
                                    "current: " <<  prev << "\n\n"; }

    std::string check (std::string& str);

};

std::string dublicate::check (std::string& str)
{
    curr = str;
    std::string result;
    int compare_value { prev.compare (curr) };
    ( compare_value > 0 ) ? result += "Not the same." :
    ( compare_value < 0 ) ? result += "Not the same." : 
    result += prev + " and " + curr + " are the same.";
    prev = curr; 
    return result;
}

int main(int argc, char* argv[])
{
    dublicate obj;
    std::string str;

    while (std::cin >> str)
    {
        if ( str == "~" ) break;


        else if (str == "~~")
        {
            throw std::runtime_error ("Enter \'~\' to exit.\n"
                          "Enter some string to continue.\n"); 
        }

        std::cout << obj.check (str) << "\n";
        obj.check_prev();
    }

    exit (EXIT_SUCCESS);
}
