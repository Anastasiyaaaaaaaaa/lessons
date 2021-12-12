/*4. Разработайте программу, реализующую работу с бинарными файлами.
Необходимо хранить информацию о расписании автобусов:
- номер маршрута (уникален);
- ФИО водителя;
- пункт отправления;
- пункт назначения.
Реализовать следующие функции, вызываемые из меню:
1. Ввод информации о расписании с клавиатуры и сохранение ее в
бинарном файле с выбранным пользователем названием.
2. Просмотр содержимого бинарного файла с выбранным пользователем
названием.
3. Вывод информации о рейсах по введенной пользователем фамилии
водителя из выбранного пользователем файла.
4. Вывод информации обо всех рейсах с пунктом назначения Минск.
5. Удаление информации из выбранного бинарного файла о маршруте с
выбранным ФИО водителя.
6. Изменение информации о пункте отправления для всех маршрутов из выбранного пункта назначения.
7. Вывод ФИО водителя с максимальным номером маршрута из
выбранного файла.
8. Изменение информации о ФИО водителя по введенному номеру
маршрута. Файл вводит пользователь.*/



#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct raspisanie {
    int nomer;
    char inicial[10];
    char punktot[20];
    char punktnaz[20];
};

int showmenu() {
    int menu = 1, k = 0;
    while (menu) {
        cout << "Выберите действие:\n1)Ввод информации\n2)Просмотрт информации\n3)Поиск по фамилии\n4)Рейс с пунктом назначению Минск\n5)Удаление информации с выбранным ФИО водителя из бинарного файла\n6)Изменение информации о пункте отправления для всех маршрутов из выбранного пункта назначения.\n7)Вывод ФИО водителя с максимальным номером маршрута\n8)Изменение информации о ФИО водителя\n";
        cin >> menu;
        return menu;
    }
    return -1;
}


//1
void read_input(fstream &out){
    raspisanie rasp;
    int k;
    cout << "Введите количество автобусов: " << endl;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> rasp.nomer;
        cin >> rasp.inicial;
        cin >> rasp.punktot;
        cin >> rasp.punktnaz;
        out.write(reinterpret_cast<char*>(&rasp), sizeof(rasp));
    }
    cout<<endl;
}

void vivod() {
    raspisanie rasp;
    char name[20];
    cout << "Название файла: " << endl;
    cin >> name;
    cout << endl;
    fstream f(name, ios::binary | ios::in);
    f.read(reinterpret_cast<char *>(&rasp), sizeof(rasp));
    while (!f.eof()) {
        cout << "Номер маршрута: " << rasp.nomer << endl;
        cout << "ФИО водителя: " << rasp.inicial << endl;
        cout << "Пункт отправления: " << rasp.punktot << endl;
        cout << "Пункт назначения: " << rasp.punktnaz << endl;
        cout << endl;
        f.read(reinterpret_cast<char *>(&rasp), sizeof(rasp));
    }
    cout << endl;
    f.close();
}

void save_scedule_to_file(const char* filename) {
    fstream f;
    f.open(filename, ios::binary | ios::out);
    read_input(f);
    f.close();
}


void processMenu(int selected) {
    switch (selected) {
        case 1:
            save_scedule_to_file("2.bin");
            return;


        case 2:
            break;

        default:
            break;

    }

}



int main(){
    auto selected = showmenu();//возвращает выбранный пункт
    processMenu(selected);
}

