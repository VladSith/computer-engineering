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
    double departure;// выезд , отправка
    double time;//время , прибытия
    int Сarriage = 15;//колво вагонов

public:

    Train(string on, string de, int d, int t, int c) : on_dest(on), destination(de), departure(d), time(t), Сarriage(c) {}
    Train() {}
    void set2();
    void show_Train()const;
};

class Сarriage
{

    string tipe;//тип вагона
    int seat;//колво мест
    int loose_seat;//колво свободных мест

public:

    Сarriage(int v, string t, int m, int nm) :tipe(t), seat(m), loose_seat(nm) {}
    Сarriage() {}
    void set_Сarriage();
    void show_Сarriage()const;
    void buy_Seat();

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
    }
}
void Train::show_Train()const
{
    {
        cout << "Пункт отбытия: " << on_dest << endl;
        cout << "Пункт назначения:  " << destination << endl;
        cout << "Время отбытия:  " << departure << endl;
        cout << "Время прибытия:  " << time << endl;
        cout << "Количество вагонов:  " << Сarriage << endl;
    }
}

void trainstation::set(trainstation v[])
{
    for (int i = 0; i < peronquantity; i++)
    {
        cout << "Введите номер перрона: " << endl;
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
void Сarriage::set_Сarriage()
{
    cout << "Тип вагона: " << endl;
    cin >> tipe;
    if (tipe == "Купе" || tipe=="Купэ") {
        seat = 36;
    }
    else{
        seat == 54;
    }
    
    srand(time(NULL));
    loose_seat = rand() % seat;
}
void Сarriage::show_Сarriage()const
{
    cout << "Тип вагона: " << tipe << endl;
    cout << "Количество мест: " << seat << endl;
    cout << "Количество свободных мест: " << loose_seat << endl;

}
void Сarriage::buy_Seat()
{
    int n;
    int ticket;
    cout << "Введите кол-во покупаемых билетов" << endl;
    cin >> ticket;
    for (int i = 0; i < ticket; i++)
    {
        n = loose_seat - ticket;
    }
    cout << "Колво оставшихся свободных мест: " << n << endl;
}

void Passenger::set_Passenger()
{
    cout << "Фамилия и имя пассажира: " << endl;
    cin >> surname >> name;
    cout << "Введите пол пассажира: " << endl;
    cin >> gender;
    cout << "Введите возраст пассажира: " << endl;
    cin >> age;
    cout << "Введите номер паспорта: " << endl;
    cin >> pasport;
}

void Passenger::show_Passenger()const
{
    cout << "Имя:  " << name << endl;
    cout << "Фамилия:  " << surname << endl;
    cout << "Пол:  " << gender << endl;
    cout << "Возраст:  " << age << endl;
    if (age < 14) {
        cout << "Дети путешествую только в сопровождении родителей";
    }
    cout << "Номер паспорта:  " << pasport << endl;
}

int main() {
    system("chcp 1251");

    Passenger A;
    cout << "Введите информацию о пассажире" << endl;
    cout << endl;
    A.set_Passenger();
    cout << "Информация о пассажире" << endl;
    cout << endl;
    A.show_Passenger();
    cout << endl;
    Сarriage B;
    cout << "Введите информацию о вагоне" << endl;
    cout << endl;
    B.set_Сarriage();
    cout << "Информация о вагоне" << endl;
    cout << endl;
    B.show_Сarriage();
    cout << endl;
    B.buy_Seat();
    cout << endl;
    Train C;
    cout << "Заполните список сведениями о поезде" << endl;
    C.set2();
    C.show_Train();
    cout << endl;
    cin.get();
    trainstation D;
    cout << "Заполните данные о перронах:" << endl;
    trainstation* с = new trainstation;
    D.set(с);
    cout << endl;
    D.show(с);
    cin.get();
    return 0;
}
