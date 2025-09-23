/*-
Подпрограмма перегрузки строк
из файла в файл с
сортировкой по алфавиту.
Названия файлов захардкоржены.
-*/

#include <iostream>
#include <algorithm> //-Для сортировки
#include <vector>    //- Тоже для сортировки
#include <Windows.h> //-Для кириллицы
#include <fstream>   //-Для файлов
using namespace std;

class Adress //- Методы публичные, но поля приватные;
{
public:
  Adress(string town = "A", string street = "B", string house = "C", string apartament = "D")
  {
    this->town = town;
    this->street = street;
    this->house = house;
    this->apartament = apartament;
  };

  string get_output_adress() //- Возвращает строку информации;
  {
    return this->town + ", " + this->street + ", " + this->house + ", " + this->apartament;
  };

  string getTownName() //- Возвращает имя города;
  {
    return this->town;
  };

private:
  string town;
  string street;
  string house;
  string apartament;
};

void sor(vector<Adress> &adresses)
{
  sort(adresses.begin(), adresses.end(), [](Adress &a, Adress &b)
       { return a.getTownName() < b.getTownName(); });
};

int main()
{
  SetConsoleOutputCP(CP_UTF8); //-Кодировка консоли

  ifstream inFile("./in.txt"); //-Открываем in.txt

  if (!inFile.is_open()) //- Если не открылся
  {
    cout << "Ошибка! Файл \"in.txt\" не найден!";
    inFile.close(); //-Закрываем файл in.txt;
    return 0;       //-Выходим из функции main;
  };

  int numberObjects = 0;   //-Кол-во объектов;
  inFile >> numberObjects; //-Читаем из файла;
  vector<Adress> adresses; /*
    Сделали вектор объектов типа Adress*/

  for (int i = 0; i < numberObjects; i++)
  {
    string t = "";
    string s = "";
    string h = "";
    string a = "";

    inFile >> t;
    inFile >> s;
    inFile >> h;
    inFile >> a;

    adresses.push_back(Adress(t, s, h, a));
  }

  inFile.close(); //-Закрываем файл-источник;

  sor(adresses); //-Сортируем массив по алфавиту;

  ofstream outFile("./out.txt");    //- Открываем файл для записи;
  outFile << numberObjects << endl; //- Пишем кол-во элементов;

  for (int i = 0; i < numberObjects; i++)
  {
    outFile << adresses[i].get_output_adress() << endl; //- Записываем в файл строчки;
  };

  outFile.close(); //- Закрываем файл;
  return 0;
}