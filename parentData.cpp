#include "parentData.h"

lagu create_data_lagu(){
    lagu d;
    cout<<"  ID Lagu        : ";
    cin>>d.id_lagu;
    cout<<"  Judul Lagu     : ";
    cin.ignore();
    getline(cin, d.judul_lagu);
    cout<<"  Penyanyi Lagu  : ";
    //cin.ignore();
    getline(cin, d.penyanyi_lagu);
    cout<<"  Rating Lagu    : ";
    cin>>d.rating_lagu;
    return d;
}

void view_data_lagu(lagu d){
    cout<<"  ID Lagu        : "<<d.id_lagu<<endl;
    cout<<"  Judul Lagu     : "<<d.judul_lagu<<endl;
    cout<<"  Penyanyi Lagu  : "<<d.penyanyi_lagu<<endl;
    cout<<"  Rating Lagu    : "<<d.rating_lagu<<endl;
}

void edit_data_lagu(lagu &d){
    cout<<"  Judul Lagu     : ";
    cin.ignore();
    getline(cin, d.judul_lagu);
    cout<<"  Penyanyi Lagu  : ";
    //cin.ignore();
    getline(cin, d.penyanyi_lagu);
    cout<<"  Rating Lagu    : ";
    cin>>d.rating_lagu;
}
