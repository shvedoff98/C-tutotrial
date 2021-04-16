#include <fstream>
#include "filters.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


// Объявляем все функции , которые используем в программе
void skip_to_int(void);
void print_filters(void);
void condition_1(istream& , ostream&);
void condition_2(istream& , ostream&, string iname);
void condition_3(istream& , ostream&);
void condition_4(istream& , ostream&, string iname);
void check_for_error(int& ); 

int main(int argc, char* argv[])
{

    cout << "Enter the log FILE's name: ";
    string iname; cin >> iname; // ввод имени файла в поток cin 
    
    ifstream ist {iname}; // записываем считанный файл во входной поток
    if (!ist) perror ("Unable to open the log file!\n");

    cout << "Enter the OUTPUT file: ";
    string oname; cin >> oname; 

    ofstream ost {oname}; // записываем считанный файл в выходной поток
    if (!ost) perror ("Unable to open the output file!\n"); // ошибка, если не
                                                            //удалось открыть файл
    print_filters();

    int choise; check_for_error(choise); // проверяем на ошибку ввода
                                         // и вводим число
    switch(choise)
    {
        case 1: 
            {
                condition_1(ist, ost);
                cout << "\nDone! Now, open the output file!\n";
                break;
            }
        case 2:
            {
                condition_2(ist, ost, iname);
                cout << "\nDone! Now, open the output file!\n";
                break;
            }
        case 3:
            {
                condition_3(ist, ost);
                cout << "\nDone! Now, open the output file!\n";
                break;
            }
        case 4:
            {
                condition_4(ist, ost, iname);
                cout << "\nDone! Now, open the output file!\n";
                break;
            }
    }
}
