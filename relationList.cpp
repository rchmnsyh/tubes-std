#include "relationList.h"
#include "childData.h"
#include "parentData.h"

void createListRelation(ListRelation &L){
    first(L) = NULL;
}

addressRelation allocateRelation(addressParent aP, addressChild aC){
    addressRelation P = new elmlistRelation;
    parent(P) = aP;
    child(P)  = aC;
    next(P) = NULL;
    return P;
}

void deallocateRelation(addressRelation &P){
    delete P;
}

void insertRelation(ListRelation &L, addressRelation P){
    if(first(L) == NULL){
        first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

void deleteRelation(ListRelation &L, addressRelation &P){
    if(first(L) != NULL){
        if(P == first(L)){
            first(L) = next(first(L));
        }
        addressRelation Q = first(L);
        while(next(Q) != NULL){
            if(next(Q) == P){
                next(Q) = next(P);
                break;
            }
            Q = next(Q);
        }
    }
}

addressRelation findRelation(ListRelation L, addressParent aP, addressChild aC){
    if(first(L) != NULL){
        addressRelation P = first(L);
        while(P != NULL){
            if((parent(P) == aP) && (child(P) == aC)){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printLaguDanGenreByID(addressParent pLagu, ListRelation listRelasi){
    view_data_lagu(info(pLagu));
    bool ada = false;
    addressRelation pRelasi = first(listRelasi);
    cout<<"  Genre Lagu     : ";
    while(pRelasi != NULL){
        if(parent(pRelasi) == pLagu){
            ada = true;
            cout<<info(child(pRelasi)).nama_genre<<", ";
        }
        pRelasi = next(pRelasi);
    }
    if(ada == false){
        cout<<"<kosong>";
    }
}

void printLaguDanGenre(ListParent listLagu, ListRelation listRelasi){
    addressParent pLagu = first(listLagu);
    while(pLagu != NULL){
        printLaguDanGenreByID(pLagu,listRelasi);
        cout<<endl<<endl;
        pLagu = next(pLagu);
    }
}

void printGenreDanLagu(ListChild listGenre, ListRelation listRelasi){
    addressChild pGenre = first(listGenre);
    do{
        view_data_genre(info(pGenre));
        bool ada = false;
        addressRelation pRelasi = first(listRelasi);
        cout<<"  List Lagu ber-genre "<<info(pGenre).nama_genre<<endl;
        while(pRelasi != NULL){
            if(child(pRelasi) == pGenre){
                ada = true;
                cout<<"  -> "<<info(parent(pRelasi)).judul_lagu<<" - "<<info(parent(pRelasi)).penyanyi_lagu<<endl;
            }
            pRelasi = next(pRelasi);
        }
        if(ada == false){
            cout<<"  Belum ada lagu yang terdaftar dengan genre '"<<info(pGenre).nama_genre<<"'"<<endl;
        }
        cout<<endl;
        pGenre = next(pGenre);
    }while(pGenre != first(listGenre));
}
