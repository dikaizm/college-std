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
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        address_pelanggan Q = last(L);
        next(Q) = P;
        last(L) = P;
    }
}
void deleteFirstPelanggan(list_pelanggan &L, address_pelanggan &P){
    if (first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    } else if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        cout << "Data Pelanggan Kosong" << endl;
    }
}
void deleteLastPelanggan(list_pelanggan &L, address_pelanggan &P){
    if (first(L) != NULL && last(L) != NULL) {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    } else {
        cout << "Data Pelanggan Kosong" << endl;
    }
}
void deleteAfterPelanggan(list_pelanggan &L, address_pelanggan Prec, address_pelanggan &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
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