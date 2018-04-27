#include <iostream>
#include <cstdlib>
#include "parentList.h"
#include "childList.h"
#include "relationList.h"
#include "caseFunctionality.h"

using namespace std;

int main()
{
    ListParent listLagu;
    ListChild listGenre;
    ListRelation listRelasi;

    lagu l;
    genre g;

    addressParent aP;
    addressChild aC;
    addressRelation aR;

    int menu;

    createListLagu(listLagu);
    createListGenre(listGenre);
    createListRelation(listRelasi);

    l.id_lagu = 2;
    l.judul_lagu = "Rose-Colored Boy";
    l.penyanyi_lagu = "Paramore";
    l.rating_lagu = 9;
    aP = allocateLagu(l);
    insertLastLagu(listLagu, aP);

    l.id_lagu = 1;
    l.judul_lagu = "Everything Has Changed";
    l.penyanyi_lagu = "Taylor Swift, Ed Sheeran";
    l.rating_lagu = 8.5;
    aP = allocateLagu(l);
    insertFirstLagu(listLagu, aP);

    l.id_lagu = 3;
    l.judul_lagu = "Road of Resistance";
    l.penyanyi_lagu = "BABYMETAL";
    l.rating_lagu = 9.5;
    aP = allocateLagu(l);
    insertLastLagu(listLagu, aP);

    l.id_lagu = 4;
    l.judul_lagu = "1-800-273-8255";
    l.penyanyi_lagu = "Logic, Alessia Cara, Khalid";
    l.rating_lagu = 10;
    aP = allocateLagu(l);
    insertLastLagu(listLagu, aP);

    l.id_lagu = 5;
    l.judul_lagu = "Lost Paradise";
    l.penyanyi_lagu = "Yellow Claw, Sody";
    l.rating_lagu = 9;
    aP = allocateLagu(l);
    insertLastLagu(listLagu, aP);

    g.id_genre = 2;
    g.nama_genre = "Pop";
    aC = allocateGenre(g);
    insertLastGenre(listGenre, aC);

    g.id_genre = 1;
    g.nama_genre = "Folk";
    aC = allocateGenre(g);
    insertFirstGenre(listGenre, aC);

    g.id_genre = 3;
    g.nama_genre = "Metal";
    aC = allocateGenre(g);
    insertLastGenre(listGenre, aC);

    g.id_genre = 4;
    g.nama_genre = "Rap";
    aC = allocateGenre(g);
    insertLastGenre(listGenre, aC);

    g.id_genre = 5;
    g.nama_genre = "Trap";
    aC = allocateGenre(g);
    insertLastGenre(listGenre, aC);

    l.id_lagu = 1;
    g.id_genre = 1;
    aR = allocateRelation(findElmLagu(listLagu, l), findElmGenre(listGenre, g));
    insertRelation(listRelasi, aR);

    l.id_lagu = 2;
    g.id_genre = 2;
    aR = allocateRelation(findElmLagu(listLagu, l), findElmGenre(listGenre, g));
    insertRelation(listRelasi, aR);

    l.id_lagu = 3;
    g.id_genre = 3;
    aR = allocateRelation(findElmLagu(listLagu, l), findElmGenre(listGenre, g));
    insertRelation(listRelasi, aR);

    l.id_lagu = 4;
    g.id_genre = 4;
    aR = allocateRelation(findElmLagu(listLagu, l), findElmGenre(listGenre, g));
    insertRelation(listRelasi, aR);

    l.id_lagu = 5;
    g.id_genre = 5;
    aR = allocateRelation(findElmLagu(listLagu, l), findElmGenre(listGenre, g));
    insertRelation(listRelasi, aR);

    while(true){
        cout<<endl;
        cout<<"    _______________________________________________    "<<endl;
        cout<<"   /                                               \\  "<<endl;
        cout<<"  /---------------- Tubes STD 2018 -----------------\\ "<<endl;
        cout<<"  |                                                 |  "<<endl;
        cout<<"  |     Rachmansyah Adhi Widhianto - 1301170066     |  "<<endl;
        cout<<"  |     Muhammad Khaifa Gifari     - 1301170382     |  "<<endl;
        cout<<"  |                                                 |  "<<endl;
        cout<<"  \\------------------  IF-41-08  -------------------/ "<<endl;
        cout<<"   \\_______________________________________________/  "<<endl;
        cout<<"   /                                               \\  "<<endl;
        cout<<"  /----------------  Lagu & Genre  -----------------\\ "<<endl;
        cout<<"  |                                                 |  "<<endl;
        cout<<"  |     1.  Input Lagu                              |  "<<endl;
        cout<<"  |     2.  Input Genre                             |  "<<endl;
        cout<<"  |     3.  Edit Lagu by ID                         |  "<<endl;
        cout<<"  |     4.  Edit Genre by ID                        |  "<<endl;
        cout<<"  |     5.  Delete Lagu by ID                       |  "<<endl;
        cout<<"  |     6.  Delete Genre by ID                      |  "<<endl;
        cout<<"  |     7.  Buat Koneksi Lagu dan Genre             |  "<<endl;
        cout<<"  |     8.  Putuskan Koneksi Lagu dan Genre         |  "<<endl;
        cout<<"  |     9.  Periksa Koneksi Lagu dan Genre          |  "<<endl;
        cout<<"  |     10. List Lagu                               |  "<<endl;
        cout<<"  |     11. List Genre                              |  "<<endl;
        cout<<"  |     12. List Lagu dan Genrenya                  |  "<<endl;
        cout<<"  |     13. List Genre dan Lagunya                  |  "<<endl;
        cout<<"  |     14. Tampilkan Lagu dan Genrenya             |  "<<endl;
        cout<<"  |     15. Rata-rata Rating Lagu per Genre         |  "<<endl;
        cout<<"  |                                                 |  "<<endl;
        cout<<"  |     0.  Keluar Program                          |  "<<endl;
        cout<<"  |                                                 |  "<<endl;
        cout<<"  |-------------------------------------------------|  "<<endl;
        cout<<"  \\_________________________________________________/ "<<endl;

        cout<<endl;
        cout<<"  Pilihan (integer): ";
        cin>>menu;
        if(cin.fail()){
            cin.clear();
            cout<<"  Pilihan bukan integer. Tekan 'Enter' untuk melanjutkan...";
            cin.sync();
            cin.get();
            system("CLS");
        }
        else{
            switch(menu){
                case 0:
                    return 0;
                break;
                case 1:
                    l = create_data_lagu();
                    if(findElmLagu(listLagu,l) == NULL){
                        if((l.rating_lagu <= 10) && (l.rating_lagu >= 0)){
                            aP = allocateLagu(l);
                            insertLastLagu(listLagu, aP);
                            cout<<"  Lagu berhasil diinput! Tekan 'Enter' untuk melanjutkan...";
                        }
                        else{
                            cout<<"  Rating lagu harus diantara 0 - 10! Tekan 'Enter' untuk melanjutkan...";
                        }
                    }
                    else{
                        cout<<"  ID duplikat! Tekan 'Enter' untuk melanjutkan...";
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 2:
                    g = create_data_genre();
                    if(findElmGenre(listGenre,g) == NULL){
                        aC = allocateGenre(g);
                        insertLastGenre(listGenre, aC);
                        cout<<"  Genre berhasil diinput! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        cout<<"  ID duplikat! Tekan 'Enter' untuk melanjutkan...";
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 3:
                    cout<<"  Input ID Lagu  : ";
                    cin>>l.id_lagu;
                    aP = findElmLagu(listLagu,l);
                    if(aP == NULL){
                        cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        l = info(aP);
                        edit_data_lagu(info(aP));
                        if((info(aP).rating_lagu <= 10) && (info(aP).rating_lagu >= 0)){
                            cout<<"  Lagu berhasil diedit! Tekan 'Enter' untuk melanjutkan...";
                        }
                        else{
                            info(aP) = l;
                            cout<<"  Rating lagu harus diantara 0 - 10! Tekan 'Enter' untuk melanjutkan...";
                        }
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 4:
                    cout<<"  Input ID Genre  : ";
                    cin>>g.id_genre;
                    aC = findElmGenre(listGenre,g);
                    if(aC == NULL){
                        cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        edit_data_genre(info(aC));
                        cout<<"  Genre berhasil diedit! Tekan 'Enter' untuk melanjutkan...";
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 5:
                    cout<<"  Input ID Lagu: ";
                    cin>>l.id_lagu;
                    aP = findElmLagu(listLagu,l);
                    if(aP == NULL){
                        cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        deleteByIDLagu(listLagu,aP);

                        aR = first(listRelasi);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(parent(aR) == aP){
                                deleteRelation(listRelasi,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        cout<<"  Lagu berjudul '"<<info(aP).judul_lagu<<"' berhasil dihapus! Tekan 'Enter' untuk melanjutkan...";
                        deallocateLagu(aP);
                    }
                    cin.sync();
                    cin.get();
                break;
                case 6:
                    cout<<"  Input ID Genre: ";
                    cin>>g.id_genre;
                    aC = findElmGenre(listGenre,g);
                    if(aC == NULL){
                        cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        deleteByIDGenre(listGenre,aC);
                        aR = first(listRelasi);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(child(aR) == aC){
                                deleteRelation(listRelasi,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        cout<<"  Genre '"<<info(aC).nama_genre<<"' berhasil dihapus! Tekan 'Enter' untuk melanjutkan...";
                        deallocateGenre(aC);
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 7:
                    cout<<"  Input ID Lagu  : ";
                    cin>>l.id_lagu;
                    cout<<"  Input ID Genre : ";
                    cin>>g.id_genre;
                    aP = findElmLagu(listLagu, l);
                    aC = findElmGenre(listGenre, g);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(listRelasi,aP,aC);
                        if(aR == NULL){
                            aR = allocateRelation(aP,aC);
                            insertRelation(listRelasi, aR);
                        }
                        cout<<"  Lagu '"<<info(aP).judul_lagu<<"' telah terelasi dengan genre '"<<info(aC).nama_genre<<"'.";
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  ID Lagu dan ID Genre tidak ditemukan!";
                    }
                    else if(aC == NULL){
                        cout<<"  ID Genre tidak ditemukan!";
                    }
                    else if(aP == NULL){
                        cout<<"  ID Lagu tidak ditemukan!";
                    }
                    cout<<" Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 8:
                    cout<<"  Input ID Lagu  : ";
                    cin>>l.id_lagu;
                    cout<<"  Input ID Genre : ";
                    cin>>g.id_genre;
                    aP = findElmLagu(listLagu, l);
                    aC = findElmGenre(listGenre, g);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(listRelasi,aP,aC);
                        if(aR != NULL){
                            deleteRelation(listRelasi,aR);
                            cout<<"  Relasi lagu '"<<info(aP).judul_lagu<<"' dengan genre '"<<info(aC).nama_genre<<"' telah terputus.";
                        }
                        else{
                            cout<<"  Relasi lagu '"<<info(aP).judul_lagu<<"' dan genre '"<<info(aC).nama_genre<<"' tidak ditemukan.";
                        }
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  ID Lagu dan ID Genre tidak ditemukan!";
                    }
                    else if(aC == NULL){
                        cout<<"  ID Genre tidak ditemukan!";
                    }
                    else if(aP == NULL){
                        cout<<"  ID Lagu tidak ditemukan!";
                    }
                    cout<<" Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 9:
                    cout<<"  Input ID Lagu  : ";
                    cin>>l.id_lagu;
                    cout<<"  Input ID Genre : ";
                    cin>>g.id_genre;
                    aP = findElmLagu(listLagu, l);
                    aC = findElmGenre(listGenre, g);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(listRelasi,aP,aC);
                        if(aR != NULL){
                            cout<<"  Lagu '"<<info(aP).judul_lagu<<"' sudah terelasi dengan genre '"<<info(aC).nama_genre<<"'.";
                        }
                        else{
                            cout<<"  Lagu '"<<info(aP).judul_lagu<<"' belum terelasi dengan genre '"<<info(aC).nama_genre<<"'.";
                        }
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  ID Lagu dan ID Genre tidak ditemukan!";
                    }
                    else if(aC == NULL){
                        cout<<"  ID Genre tidak ditemukan!";
                    }
                    else if(aP == NULL){
                        cout<<"  ID Lagu tidak ditemukan!";
                    }
                    cout<<" Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 10:
                    cout<<endl;
                    cout<<"  ---------------  List Lagu  ---------------"<<endl;
                    printInfoLagu(listLagu);
                    cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 11:
                    cout<<endl;
                    cout<<"  ---------------  List Genre  ---------------"<<endl;
                    printInfoGenre(listGenre);
                    cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 12:
                    cout<<endl;
                    cout<<"  ----------  List Lagu dan Genrenya  ----------"<<endl;
                    printLaguDanGenre(listLagu, listRelasi);
                    cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 13:
                    cout<<endl;
                    cout<<"  ----------  List Genre dan Lagunya  ----------"<<endl;
                    printGenreDanLagu(listGenre, listRelasi);
                    cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 14:
                    cout<<"  Input ID Lagu  : ";
                    cin>>l.id_lagu;
                    aP = findElmLagu(listLagu,l);
                    if(aP == NULL){
                        cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk melanjutkan...";
                    }
                    else{
                        cout<<endl;
                        printLaguDanGenreByID(aP,listRelasi);
                        cout<<endl;
                        cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    }
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                case 15:
                    cout<<endl;
                    cout<<"  ------  Rata-rata Rating Lagu per Genre  ------"<<endl;
                    AverageRatingPerGenre(listGenre, listRelasi);
                    cout<<"  Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
                default:
                    cout<<"  Pilihan tidak tersedia. Tekan 'Enter' untuk melanjutkan...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                break;
            }
        }
    }
}
