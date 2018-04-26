#include "parentList.h"
#include "parentData.h"

void createListLagu(ListParent &L){
    first(L) = NULL;
    last(L)  = NULL;
}

addressParent allocateLagu(lagu x){
    addressParent P;
    P = new elmlistParent;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}

void deallocateLagu(addressParent &P){
    delete P;
}

void insertFirstLagu(ListParent &L, addressParent P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastLagu(ListParent &L, addressParent P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstLagu(L,P);
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfterLagu(ListParent &L, addressParent Prec, addressParent P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstLagu(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirstLagu(ListParent &L, addressParent &P){
    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteLastLagu(ListParent &L, addressParent &P){
    if(last(L) != NULL){
        P = last(L);
        if(first(L) == last(L)){
            deleteFirstLagu(L,P);
        }
        else{
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfterLagu(ListParent &L, addressParent Prec, addressParent &P){
    if((Prec != NULL) && next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteByIDLagu(ListParent &L, addressParent &P){
    if(P == first(L)){
        deleteFirstLagu(L,P);
    }
    else if(P == last(L)){
        deleteLastLagu(L,P);
    }
    else{
        addressParent Q = prev(P);
        deleteAfterLagu(L,Q,P);
    }
}

addressParent findElmLagu(ListParent L, lagu x){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressParent P = first(L);
        while(P != NULL){
            if(info(P).id_lagu == x.id_lagu){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printInfoLagu(ListParent L){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressParent P = first(L);
        while(P != NULL){
            view_data_lagu(info(P));
            cout<<endl;
            P = next(P);
        }
    }
}
