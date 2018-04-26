#ifndef RELATIONLIST_H_INCLUDED
#define RELATIONLIST_H_INCLUDED

#include <iostream>
#include "childList.h"
#include "parentList.h"

#define first(L) L.first
#define parent(P) P->parent
#define child(P) P->child
#define next(P) P->next


using namespace std;

typedef struct elmlistParent *addressParent;
typedef struct elmlistChild *addressChild;
typedef struct elmlistRelation *addressRelation;


struct elmlistRelation{
    addressParent parent;
    addressChild child;
    addressRelation next;
};

struct ListRelation{
    addressRelation first;
};

void createListRelation(ListRelation &L);
addressRelation allocateRelation(addressParent aP, addressChild aC);
void deallocateRelation(addressRelation &P);

void insertRelation(ListRelation &L, addressRelation P);
void deleteRelation(ListRelation &L, addressRelation &P);
addressRelation findRelation(ListRelation L, addressParent aP, addressChild aC);

void printLaguDanGenreByID(addressParent pLagu, ListRelation listRelasi);
void printLaguDanGenre(ListParent listLagu, ListRelation listRelasi);
void printGenreDanLagu(ListChild listGenre, ListRelation listRelasi);

#endif // RELATIONLIST_H_INCLUDED
