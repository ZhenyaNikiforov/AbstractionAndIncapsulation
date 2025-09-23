/*-
Задание 1. Подпрограмма перезаписи
из файла in.txt в файл out.txt
-*/

#include <iostream>
#include <fstream>   //- Для работы с файлами
#include <Windows.h> //- Для кириллицы
#include <vector>    //- Для вектора
using namespace std;

class Adress //- Класс для создания объектов
{
public:
  Adress(string town = "A", string street = "B", string house = "C", string apartament = "D") /*
     Это чтоб было легче при тестировании, если инициализация не вышла*/
  {
    this->town = town;
    this->street = street;
    this->house = house;
    this->apartament = apartament;
  };

  string get_output_address()
  {
    return this->town + ", " + this->street + ", " + this->house + ", " + this->apartament;
  };

private:
  string town;
  string street;
  string house;
  string apartament;
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  ifstream inFile("./in.txt"); /*-
  Открываем файл-источник;*/

  if (!inFile.is_open()) //- Если не открылся...
  {
    cout << "Ошибка открытия файла \"in.txt\"" << endl;
    inFile.close(); //- Закрываем его;
    return 0;       //-Выходим из функции main();
  }

  int objectNumber = 0;
  inFile >> objectNumber; //- Кол-во объектов

  vector<Adress> adresses; /*-
    Сделали пустой вектор типа Adress-*/

  for (int i = 0; i < objectNumber; i++)
  {
    string town = "";
    string street = "";
    string house = "";
    string apartament = "";

    inFile >> town;
    inFile >> street;
    inFile >> house;
    inFile >> apartament;

    adresses.push_back(Adress(town, street, house, apartament));
  };

  ofstream outFile("./out.txt"); /*-
   Открываем файл, в который будем записывать-*/

  outFile << objectNumber << endl; //- Записываем кол-во элементов;

  for (int i = (objectNumber - 1); i > -1; i--)
  {
    outFile << adresses[i].get_output_address() << endl;
  }

  outFile.close(); //-Закрываем файл-приёмник;
  return 0;        //-Выходим из функции main();
}