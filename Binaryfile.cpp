#include <iostream>
#include <vector>
#include <fstream>
#include <string>   
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Программа не связана с лабораторными, но связана с бинарными файлами.
// Структура кода вже була готова.Лише вніс деякі зміни


class foo
{
public:
    string Name = "С++";
    int Age = 10;

    void show()
    {
        cout << "Name = " << Name << endl;
        cout << "Age = " << Age << endl;
    }

    void write(ostream& os) const
    {
        os.write((const char*)&Age, sizeof Age);

        size_t len = Name.length();
        os.write((const char*)&len, sizeof len);
        os.write(Name.c_str(), len);
    }

    void read(istream& in)
    {
        in.read((char*)&Age, sizeof Age);

        size_t len;
        in.read((char*)&len, sizeof len);
        Name.resize(len);
        in.read(&Name[0], len);
    }
};



int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");
    foo* obj = new foo();
    obj->Age = 10;
    obj->Name = "С++";

    ofstream file("file.bin", ios::binary | ios::app);
    if (file.is_open()) {
        obj->write(file);
        obj->show();
    }
    file.close();

    foo* result = new foo();
    ifstream file1("file.bin", ios::binary);
    if (file1.is_open()) {
        result->read(file1);
        file1.close();
        result->show();
    }
    file1.close();

    return 0;
}