#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void print_filters(void)  // функция печати ваирантов выбора 
                                //парсинга лог файла пользователем
{

    cout << "\nNow choosе the string search criteria:\n\n";
        
    cout << "1 | Search for the SUBSTRING in the file and "
                                    << "GET the lines CONTAINING this string.\n";

    cout << "2 | Search for the SUBSTRING in the file and "
                                    << "GET the number of times this SUBSTRING"
                                    << " occurs in the file.\n";

    cout << "3 | Search for the lines which do not contain chosen substring.\n";

    cout << "4 | Search for the SUBSTRING in the file and "
                                    << "GET the number of lines in which this SUBSTRING"
                                   << " does not occur.\n\n";

    cout << "Type in the number which represents the option(1,2,3,4): ";
}

void condition_1(istream& ist, ostream& ost) // принимает два потока(входной, выходной)
{
    cout << "Enter the substring to look for: ";
    string sbstr; cin >> sbstr;
    vector<string>temps;                   // для хранения строк
    string str;

    while (getline(ist, str))
    {
        if (str.find(sbstr, 0) != string::npos)         // string::find
        {                                         // (const string& value, size_t pos)
             temps.push_back(str);
        }                                       // найти введенную подстроку в строке ,
    }                                          //которую принимает std::getline()
   
    for (int i=0; i<temps.size(); ++i)
        ost << temps[i] << "\n";           // записать в поток ofstream ost{..}
}                                           // в котором открыт файл выхода данных

void condition_2(istream& ist, ostream& ost, string iname)
{
    cout << "Enter the substring to look for: ";
    string sbstr; cin >> sbstr;
    string str;
    int count = 0;
    while (getline(ist, str))
    {
        if (str.find(sbstr, 0) != string::npos)
        {
            ++count;         // считаем строки , в которых есть подстрока,
        }                   //введенная пользователем
    }    
    
    ost << count << " times, substring: "  << "\"" << sbstr << "\"  occures in the file: "
                << "\"" << iname << "\".\n";
}

void condition_3(istream& ist, ostream& ost)
{
    cout << "Enter the substring which should not be in the line: ";
    string sbstr; cin >> sbstr;
    vector<string>temps;
    string str;

    while (getline(ist, str))            // считываем строку посредством 
                                         //getline() и записываем в str
    {
        if (str.find(sbstr, 0) == string::npos) 
        { 
            temps.push_back(str);
        }
    }
    for (int i=0; i<temps.size(); ++i)
        ost << temps[i] << "\n"; 
}

void condition_4(istream& ist, ostream& ost, string iname)
{
    cout << "Enter the substring which should not be in the line: ";
    string sbstr; cin >> sbstr;                 // считываение подстроки
    string str;                                 // запись строки из файла
    int count = 0;
    while (getline(ist, str))
    {
        if (str.find(sbstr, 0) == string::npos)         // если строка не найдена
                                                        //инкрементируем счетчик 
        {
            ++count;                     // в итоге подсчитываем все строки, на которых нет подстроки
        }
    }
    ost << "There are "  << count << " lines in the file "
        << "\"" << iname << "\" which do not contain " << "\"" << sbstr << "\".\n";
}

void skip_to_int(void)
{
    if (cin.fail())              // обнаружено нечто, не являющееся целым числом
    {
        cin.clear();                    // возвращаем поток в состояние good()
        for (char ch; cin >> ch;)               //отбрасываем не цифры
        {
            if (isdigit(ch) || ch == '-')
            {
                cin.unget();                    // возвращаем цифру в поток,
                                                // чтобы можно было считать число
                return;
            }
        }
    }
    perror ("No input provided!\n");   // состояние bad() или eof

}

void check_for_error(int& choise)               // проверка введеного значения
{                                               // если введена не цифра или цифра >4
    while (true)                                // выдаем ошибку и просим ввести заново
    {
        if (cin >> choise)                      // введено целое число. Проверяем его
        {
            if ( 1<=choise && choise<=4 ) break;
            cout << "Sorry, " << choise
                << " is out of range [1, 4]; Try again!\n";
        }
        else {
            cout << "Sorry, it's not a number; Try again!\n";
            skip_to_int();
        }
    }
}
