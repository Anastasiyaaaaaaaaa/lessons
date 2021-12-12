//
// Created by anastasia on 12.12.21.
//

#ifndef UNTITLED12_PREVIE_FILE_H
#define UNTITLED12_PREVIE_FILE_H

#include<iostream>
#include<fstream>
#include<cstring>
#include "raspisanie.h"
using namespace std;

void file_preview(fstream &input) {
    raspisanie rasp;

    input.read(reinterpret_cast<char *>(&rasp), sizeof(rasp));
    while (!input.eof()) {
        cout << "Номер маршрута: " << rasp.nomer << endl;
        cout << "ФИО водителя: " << rasp.inicial << endl;
        cout << "Пункт отправления: " << rasp.punktot << endl;
        cout << "Пункт назначения: " << rasp.punktnaz << endl;
        cout << endl;

        input.read(reinterpret_cast<char *>(&rasp), sizeof(rasp));
    }
    cout << endl;
    // f.close();
}

void file_preview(const char* filename) {
    fstream f;
    f.open(filename, ios::binary | ios::out);
    file_preview(f);
    f.close();
}




#endif //UNTITLED12_PREVIE_FILE_H
