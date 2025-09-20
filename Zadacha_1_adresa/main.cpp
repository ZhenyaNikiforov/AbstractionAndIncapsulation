/*-
Задание 1. Подпрограмма перезаписи
из файла in.txt в файл out.txt
-*/

#include <iostream>
#include <fstream>   //- Для работы с файлами
#include <Windows.h> //- Для кириллицы
using namespace std;

class Adress //- Класс для создания объектов
{
public:
  Adress() : town("A"), street("B"), house("C"), apartament("D") {}; /*
   Это чтоб было легче при тестировании, если инициализация не вышла*/

  void setTown(string t)
  {
    this->town = t;
  };

  void setStreet(string s)
  {
    this->street = s;
  };

  void setHouse(string h)
  {
    this->house = h;
  }

  void setApartament(string a)
  {
    this->apartament = a;
  }

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

  Adress *adresses = new Adress[objectNumber]; /*-
   Сделали динамич. массив объектов типа Adress-*/

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

    adresses[i].setTown(town);
    adresses[i].setStreet(street);
    adresses[i].setHouse(house);
    adresses[i].setApartament(apartament);
  };

  inFile.close(); //-Закрываем файл-источник;

  ofstream outFile("./out.txt"); /*-
   Открываем файл, в который будем записывать-*/

  outFile << objectNumber << endl;

  for (int i = (objectNumber - 1); i > -1; i--)
  {
    outFile << adresses[i].get_output_address() << endl;
  }

  outFile.close();   //-Закрываем файл-приёмник;
  delete[] adresses; //-Удаляем динамич. массив;
  return 0;          //-Выходим из функции main();
}