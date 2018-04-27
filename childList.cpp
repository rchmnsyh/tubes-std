#include "childList.h"
#include "childData.h"

void createListGenre(ListChild &L){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    first(L) = NULL;
}

addressChild allocateGenre(genre x){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    addressChild P;
    P = new elmlistChild;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void deallocateGenre(addressChild &P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    delete P;
}

void insertFirstGenre(ListChild &L, addressChild P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else{
        addressChild Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLastGenre(ListChild &L, addressChild P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if(first(L) == NULL){
        insertFirstGenre(L,P);
    }
    else{
        addressChild Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void insertAfterGenre(ListChild &L, addressChild Prec, addressChild P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if((Prec != NULL) && (first(L) != NULL)){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstGenre(ListChild &L, addressChild &P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            first(L) = NULL;
        }
        else{
            addressChild Q = first(L);
            while(next(Q) != first(L)){
                Q = next(Q);
            }
            first(L) = next(P);
            next(Q) = first(L);
        }
    }
}

void deleteLastGenre(ListChild &L, addressChild &P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            deleteFirstGenre(L,P);
        }
        else{
            addressChild Q = first(L);
            while(next(next(Q)) != first(L)){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
        }
    }
}

void deleteAfterGenre(ListChild &L, addressChild Prec, addressChild &P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if((Prec != NULL) && (first(L) != NULL)){
        P = next(Prec);
        next(Prec) = next(P);
    }
}

void deleteByIDGenre(ListChild &L, addressChild &P){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if(P == first(L)){
        deleteFirstGenre(L,P);
    }
    else if(next(P) == first(L)){
        deleteLastGenre(L,P);
    }
    else{
        addressChild Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        deleteAfterGenre(L,Q,P);
    }
}

addressChild findElmGenre(ListChild L, genre x){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if(first(L) != NULL){
        addressChild P = first(L);
        do{
            if(info(P).id_genre == x.id_genre){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}

void printInfoGenre(ListChild L){
    //Dibuat oleh Muhammad Khaifa Gifari - 1301170382
    if(first(L) != NULL){
        addressChild P = first(L);
        do{
            view_data_genre(info(P));
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    }
}
