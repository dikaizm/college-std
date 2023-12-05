#include "pelanggan.h"
void createListPelanggan(list_pelanggan &L){
    first(L) = NULL;

}
address_pelanggan alokasiPelanggan(infotype_pelanggan x){
    address_pelanggan P = new elmlist_pelanggan;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void dealokasiPelanggan(address_pelanggan &P){
    delete P;

}
void insertPelanggan(list_pelanggan &L, address_pelanggan P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        address_pelanggan Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }

}
void deleteFirstPelanggan(list_pelanggan &L, address_pelanggan &P){
    if (first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLastPelanggan(list_pelanggan &L, address_pelanggan &P){
    if (first(L) != NULL){
        address_pelanggan Q = first(L);
        while (next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}
void deleteAfterPelanggan(list_pelanggan &L, address_pelanggan Prec, address_pelanggan &P){
    if (first(L) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_pelanggan findPelanggan(list_pelanggan L, infotype_pelanggan x){
    address_pelanggan P = first(L);
    while (P != NULL && info(P).id != x.id){
        P = next(P);
    }
    return P;
}
void printInfoPelanggan(list_pelanggan L){
    address_pelanggan P = first(L);
    cout << "=================== DAFTAR PELANGGAN ===================" << endl;
    while (P != NULL){
        cout << "ID Pelanggan : " << info(P).id << endl;
        cout << "Nama Pelanggan : " << info(P).nama << endl;
        cout << "Alamat Pelanggan : " << info(P).alamat << endl;
        cout << "No. Telp Pelanggan : " << info(P).no_telp << endl;
        cout << "Tipe Motor Pelanggan : " << info(P).tipe_motor << endl;
        cout << endl;
        P = next(P);
    }
    cout << "========================================================" << endl;

}