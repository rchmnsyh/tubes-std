#include "childData.h"

genre create_data_genre(){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    genre d;
    cout<<"  ID Genre (integer)  : ";
    cin>>d.id_genre;
    if(cin.fail()){
        cin.clear();
        d.id_genre = NULL;
        cout<<"  ID Genre yang anda inputkan bukan integer. Tekan 'Enter' untuk melanjutkan...";
    }
    else{
        cout<<"  Nama Genre          : ";
        cin.ignore();
        getline(cin, d.nama_genre);
    }
    return d;
}

void view_data_genre(genre d){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    cout<<"  ID Genre    : "<<d.id_genre<<endl;
    cout<<"  Nama Genre  : "<<d.nama_genre<<endl;
}

void edit_data_genre(genre &d){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    cout<<"  Nama Genre     : ";
    cin.ignore();
    getline(cin, d.nama_genre);
}
