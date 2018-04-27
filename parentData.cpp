#include "parentData.h"

lagu create_data_lagu(){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    lagu d;
    cout<<"  ID Lagu (integer)  : ";
    cin>>d.id_lagu;
    if(cin.fail()){
        cin.clear();
        d.id_lagu = NULL;
        cout<<"  ID Lagu yang anda inputkan bukan integer. Tekan 'Enter' untuk melanjutkan...";
    }
    else{
        cout<<"  Judul Lagu         : ";
        cin.ignore();
        getline(cin, d.judul_lagu);
        cout<<"  Penyanyi Lagu      : ";
        getline(cin, d.penyanyi_lagu);
        cout<<"  Rating Lagu        : ";
        cin>>d.rating_lagu;
    }
    return d;
}

void view_data_lagu(lagu d){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    cout<<"  ID Lagu        : "<<d.id_lagu<<endl;
    cout<<"  Judul Lagu     : "<<d.judul_lagu<<endl;
    cout<<"  Penyanyi Lagu  : "<<d.penyanyi_lagu<<endl;
    cout<<"  Rating Lagu    : "<<d.rating_lagu<<endl;
}

void edit_data_lagu(lagu &d){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    cout<<"  Judul Lagu     : ";
    cin.ignore();
    getline(cin, d.judul_lagu);
    cout<<"  Penyanyi Lagu  : ";
    //cin.ignore();
    getline(cin, d.penyanyi_lagu);
    cout<<"  Rating Lagu    : ";
    cin>>d.rating_lagu;
}
