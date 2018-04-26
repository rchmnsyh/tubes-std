#ifndef CHILDDATA_H_INCLUDED
#define CHILDDATA_H_INCLUDED

#include <iostream>
using namespace std;

struct genre{
    int id_genre;
    string nama_genre;
};

genre create_data_genre();
void view_data_genre(genre d);
void edit_data_genre(genre &d);

#endif // CHILDDATA_H_INCLUDED
