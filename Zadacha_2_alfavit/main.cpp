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
  Adress() : town("A"), street("B"), house("C"), apartament("D") {};
  string get_output_adress()
  {
    return this->town + ", " + this->street + ", " + this->house + ", " + this->apartament;
  };
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
  };
  void setApartament(string a)
  {
    this->apartament = a;
  };
  string getTownName()
  {
    return this->town;
  }

private:
  string town;
  string street;
  string house;
  string apartament;
};

void sor(Adress *arr, int size)
{
  vector<string> names; //-Сделали пустой вектор;

  for (int i = 0; i < size; i++)
  {
    names.push_back(arr[i].getTownName()); //-Добавили имена городов;
  };

  sort(names.begin(), names.end()); //- Сортируем массив по алфавиту;

  Adress *doubleArray = new Adress[size]; //-Сделали второй массив;

  for (int i = 0; i < size; i++) //-Берём первый номер...
  {
    for (int j = 0; j < size; j++) //-...прокручиваем весь массив объектов...
    {
      if (arr[j].getTownName() == names[i]) //...если город совпадает с вектором...
      {
        doubleArray[i] = arr[j]; //...заносим во второй массив объект из первого...
        arr[j].setTown("");      //...меняем имя города в первом массиве, чтоб не взять второй раз...
        break;                   //-...и выходим из цикла...
      };
    };
  };

  for (int i = 0; i < size; i++)
  {
    arr[i] = doubleArray[i]; //- Заносим в первый массив отсортированный второй;
  };

  delete[] doubleArray; //- Чистим память за вторым массивом;
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

  int numberObjects = 0;                        //-Кол-во объектов;
  inFile >> numberObjects;                      //-Читаем из файла;
  Adress *adresses = new Adress[numberObjects]; /*
   Сделали массив объектов типа Adress*/

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

    adresses[i].setTown(t);
    adresses[i].setStreet(s);
    adresses[i].setHouse(h);
    adresses[i].setApartament(a);
  }

  inFile.close(); //-Закрываем файл-источник;

  sor(adresses, numberObjects); //-Сортируем массив по алфавиту;

  ofstream outFile("./out.txt"); //- Открываем файл для записи;

  for (int i = 0; i < numberObjects; i++)
  {
    outFile << adresses[i].get_output_adress() << endl; //- Записываем в файл строчки;
  };

  outFile.close();   //- Закрываем файл;
  delete[] adresses; //- Чистим память за массивом;

  return 0;
}