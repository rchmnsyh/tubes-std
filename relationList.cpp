#include "relationList.h"
#include "childData.h"
#include "parentData.h"

void createListRelation(ListRelation &L){
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
    first(L) = NULL;
}

addressRelation allocateRelation(addressParent aP, addressChild aC){
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
    addressRelation P = new elmlistRelation;
    parent(P) = aP;
    child(P)  = aC;
    next(P) = NULL;
    return P;
}

void deallocateRelation(addressRelation &P){
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
    delete P;
}

void insertRelation(ListRelation &L, addressRelation P){
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
    if(first(L) == NULL){
        first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

void deleteRelation(ListRelation &L, addressRelation &P){
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
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
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
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
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
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
    //Dibuat oleh Rachmansyah Adhi Widhianto - 1301170066
    addressParent pLagu = first(listLagu);
    while(pLagu != NULL){
        printLaguDanGenreByID(pLagu,listRelasi);
        cout<<endl<<endl;
        pLagu = next(pLagu);
    }
}
