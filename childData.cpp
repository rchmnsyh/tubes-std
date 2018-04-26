#include "childData.h"

genre create_data_genre(){
    genre d;
    cout<<"  ID Genre    : ";
    cin>>d.id_genre;
    cout<<"  Nama Genre  : ";
    cin.ignore();
    getline(cin, d.nama_genre);
    return d;
}

void view_data_genre(genre d){
    cout<<"  ID Genre    : "<<d.id_genre<<endl;
    cout<<"  Nama Genre  : "<<d.nama_genre<<endl;
}

void edit_data_genre(genre &d){
    cout<<"  Nama Genre     : ";
    cin.ignore();
    getline(cin, d.nama_genre);
}
