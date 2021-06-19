#include "remove_empty_lines.h"

#define FILE_NAME    "log"

int main(int argc, char* argv[])
{
    Cleaner obj(FILE_NAME);

    obj.rm_empty_lines();
    obj.print_vec();
    obj.write("log");


    exit(EXIT_SUCCESS);
}
