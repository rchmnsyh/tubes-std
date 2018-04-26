#ifndef PARENTLIST_H_INCLUDED
#define PARENTLIST_H_INCLUDED

#include <iostream>
#include "parentData.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmlistParent *addressParent;

struct elmlistParent{
    lagu info;
    addressParent next;
    addressParent prev;
};

struct ListParent{
    addressParent first;
    addressParent last;
};

void createListLagu(ListParent &L);
addressParent allocateLagu(lagu x);
void deallocateLagu(addressParent &P);

// define insert and delete procedure
void insertFirstLagu(ListParent &L, addressParent P);
void insertLastLagu(ListParent &L, addressParent P);
void insertAfterLagu(ListParent &L, addressParent Prec, addressParent P);
void deleteFirstLagu(ListParent &L, addressParent &P);
void deleteLastLagu(ListParent &L, addressParent &P);
void deleteAfterLagu(ListParent &L, addressParent Prec, addressParent &P);
void deleteByIDLagu(ListParent &L, addressParent &P);
// define search-by-ID function and view procedure
addressParent findElmLagu(ListParent L, lagu x);
void printInfoLagu(ListParent L);

#endif // PARENTLIST_H_INCLUDED
