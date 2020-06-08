#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;
class trainstation
{
    int peronquantity;//колво перронов peronquantity
    string peron;// название перрона

public:
    trainstation(string p, int pe) :peron(p) {}
    trainstation() {}
    void set(trainstation v[]);
    void show(trainstation v[]);
};
class Train
{
    string on_dest;//пункт отправки
    string destination; //пункт назначение
    char departure;// выезд , отправка
    char time;//время , прибытия
    int vagon;//колво вагонов

public:

    Train(string on, string de, int d, int t, int v) : on_dest(on), destination(de), departure(d), time(t), vagon(v) {}
    Train() {}
    void set2();
    void show_Train()const;
};

class Vagon
{

    string tipe;//тип вагона
    int mest;//колво мест
    int new_mest;//колво свободных мест

public:

    Vagon(int v, string t, int m, int nm) :tipe(t), mest(m), new_mest(nm) {}
    Vagon() {}
    void set_Vagon();
    void show_Vagon()const;
    void buy_Vagon();

};
class Passenger
{

    char name[20];//имя пассажира
    char surname[20]; //фамилия пассажира
    char gender[20];//пол
    int age;//возраст
    int pasport;//номер паспорта

public:
  
    void set_Passenger();
    void show_Passenger()const;

};

void Train::set2()
{
    {
        cout << "Введите пункт отбытия: ";
        cin.get();
        cin >> on_dest;
        cout << "Введите пункт назначения: ";
        cin.get();
        cin >> destination;

        cout << "Введите время отбытия: ";
        while (!(cin >> departure) || departure < 1 || departure>10000)
        {
            cout << "Error\n\n";
            cout << "Введите время отбытия : ";
        }

        cout << "Введите время прибытия: ";
        while (!(cin >> time) || time < 1 || time>10000)
        {
            cout << "Error\n\n";
            cout << "Введите время в пути: ";
        }
        cout << "Введите количество вагонов: ";
        while (!(cin >> vagon) || vagon < 1 || vagon>10000)
        {
            cout << "Error\n\n";
            cout << "Введите количество вагонов: ";
        }
    }
}
void Train::show_Train()const
{
    {
        cout << "Пункт отбытия: " << on_dest << endl;
        cout << "Пункт назначения:  " << destination << endl;
        cout << "Время отбытия:  " << departure << endl;
        cout << "Время прибытия:  " << time << endl;
        cout << "Количество вагонов:  " << vagon << endl;
    }
}

void trainstation::set(trainstation v[])
{
    cout << "Введите количество перронов:" << endl;
    cin >> peronquantity;
    for (int i = 0; i < peronquantity; i++)
    {
        cout << "Введите название перрона : " << endl;
        cin >> v[i].peron;
    }
}
void trainstation::show(trainstation v[])
{
    for (int i = 0; i < peronquantity; i++)
    {
        cout << i + 1 << ":\n";
        cout << "Название перрона: " << v[i].peron << endl;
    }
}
void Vagon::set_Vagon()
{
    cout << "тип вагона :" << endl;
    cin >> tipe;
    cout << "количество мест :" << endl;
    cin >> mest;
    cout << "количество свободных мест :" << endl;
    cin >> new_mest;
}
void Vagon::show_Vagon()const
{
    cout << "Тип вагона : " << tipe << endl;
    cout << "Количество мест : " << mest << endl;
    cout << "Количество свободных мест: " << new_mest << endl;

}
void Vagon::buy_Vagon()
{
    int n;
    int ticket;
    cout << "Введите кол-во покупаемых билетов" << endl;
    cin >> ticket;
    for (int i = 0; i < ticket; i++)
    {
        n = new_mest - ticket;
    }
    cout << "Колво оставшихся свободных мест" << n << endl;
}

void Passenger::set_Passenger()
{
    cout << "введите имя: " << endl;
    cin >> name;
    cout << "введите фамилию: " << endl;
    cin >> surname;
    cout << "введите пол пассажира: " << endl;
    cin >> gender;
    cout << "введите возраст пассажира: " << endl;
    cin >> age;
    cout << "введите номер паспорта: " << endl;
    cin >> pasport;
}

void Passenger::show_Passenger()const
{
    cout << "Имя:  " << name << endl;
    cout << "Фамилия:  " << surname << endl;
    cout << "Пол:  " << gender << endl;
    cout << "Возраст:  " << age << endl;
    cout << "Номер паспорта:  " << pasport << endl;
}

int main() {
    system("chcp 1251");

    Passenger A;
    cout << "Введите информацию о пассажире: " << endl;
    cout << endl;
    A.set_Passenger();
    cout << "Информация о пассажире: " << endl;
    cout << endl;
    A.show_Passenger();
    cout << endl;
    Vagon B;
    cout << "Введите информацию о вагоне: " << endl;
    cout << endl;
    B.set_Vagon();
    cout << "Информация о вагоне: " << endl;
    cout << endl;
    B.show_Vagon();
    cout << endl;
    B.buy_Vagon();
    cout << endl;
    Train C;
    cout << "Заполните список сведениями о поезде:" << endl;
    C.set2();
    C.show_Train();
    cout << endl;
    cin.get();
    trainstation D;
    cout << "Заполните данные о перронах:" << endl;
    trainstation* v = new trainstation;
    D.set(v);
    cout << endl;
    D.show(v);
    cin.get();
    return 0;
}
