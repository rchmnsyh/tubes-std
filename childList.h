#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED

#include <iostream>
#include "childData.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmlistChild *addressChild;

struct elmlistChild{
    genre info;
    addressChild next;
};

struct ListChild{
    addressChild first;
};

void createListGenre(ListChild &L);
addressChild allocateGenre(genre x);
void deallocateGenre(addressChild &P);

// define insert and delete procedure
void insertFirstGenre(ListChild &L, addressChild P);
void insertLastGenre(ListChild &L, addressChild P);
void insertAfterGenre(ListChild &L, addressChild Prec, addressChild P);
void deleteFirstGenre(ListChild &L, addressChild &P);
void deleteLastGenre(ListChild &L, addressChild &P);
void deleteAfterGenre(ListChild &L, addressChild Prec, addressChild &P);
void deleteByIDGenre(ListChild &L, addressChild &P);

// define search-by-ID function and view procedure
addressChild findElmGenre(ListChild L, genre x);
void printInfoGenre(ListChild L);

#endif // CHILDLIST_H_INCLUDED
