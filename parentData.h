#ifndef PARENTDATA_H_INCLUDED
#define PARENTDATA_H_INCLUDED

#include <iostream>
using namespace std;

struct lagu{
    int id_lagu;
    string judul_lagu;
    string penyanyi_lagu;
    float rating_lagu;
};

lagu create_data_lagu();
void view_data_lagu(lagu d);
void edit_data_lagu(lagu &d);

#endif // PARENTDATA_H_INCLUDED
