#include "caseFunctionality.h"

void AverageRatingPerGenre(ListChild listGenre, ListRelation listRelasi){
    addressChild pGenre = first(listGenre);
    do{
        addressRelation pRelasi = first(listRelasi);
        float total_rating = 0;
        int total_data = 0;

        while(pRelasi != NULL){
            if(child(pRelasi) == pGenre){
                total_rating = total_rating + info(parent(pRelasi)).rating_lagu;
                total_data++;
            }
            pRelasi = next(pRelasi);
        }

        view_data_genre(info(pGenre));
        if(total_data > 0){
            cout<<"  Jumlah lagu ber-genre '"<<info(pGenre).nama_genre<<"'           : "<<total_data<<" lagu"<<endl;
            cout<<"  Total Rating Lagu ber-genre '"<<info(pGenre).nama_genre<<"'     : "<<total_rating<<endl;
            cout<<"  Rata-rata rating lagu ber-genre '"<<info(pGenre).nama_genre<<"' : "<<total_rating / total_data<<endl;
        }
        else{
            cout<<"  Tidak ada lagu yang ber-genre '"<<info(pGenre).nama_genre<<"'."<<endl;
        }
        cout<<endl;
        pGenre = next(pGenre);
    }while(pGenre != first(listGenre));
}
