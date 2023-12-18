#include "transaksi.h"
#include "pelanggan.h"
#include "sparepart.h"

void createListTransaksi(list_transaksi &L)
{
    first(L) = NULL;
}

address_transaksi alokasiTransaksi(infotype_transaksi x)
{
    address_transaksi P = new elmlist_transaksi;
    info(P) = x;
    next(P) = NULL;
    return P;
}

address_sparepart_transaksi alokasiSparepartTransaksi(address_sparepart adrSparepart)
{
    address_sparepart_transaksi S = new elmlist_sparepart_transaksi;
    next(S) = NULL;
    item(S) = adrSparepart;
    return S;
}

void insertTransaksi(list_transaksi &L, address_transaksi P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        address_transaksi Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstTransaksi(list_transaksi &L, address_transaksi &P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastTransaksi(list_transaksi &L, address_transaksi &P)
{
    if (first(L) != NULL)
    {
        address_transaksi Q = first(L);
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfterTransaksi(list_transaksi &L, address_transaksi Prec, address_transaksi &P)
{
    if (first(L) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_transaksi findTransaksi(list_transaksi L, string no_transaksi)
{
    address_transaksi P = first(L);
    while (P != NULL)
    {
        if (info(P).no_transaksi != no_transaksi)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfoTransaksi(list_transaksi L)
{
    address_transaksi P = first(L);
    while (P != NULL)
    {
        cout << "ID Pelanggan : " << info(pelanggan(P)).id << endl;
        cout << "Nama Pelanggan : "<< info(pelanggan(P)).nama << endl;
        cout << "No Transaksi : " << info(P).no_transaksi << endl;
        cout << "Tanggal Transaksi : " << info(P).tgl_transaksi << endl;
        cout << "Jumlah : " << info(P).jumlah << endl;
        cout << "Service : " << info(P).service << endl;
        cout << "Harga : " << info(P).harga << endl;
        cout << "Total : " << info(P).total << endl;
        cout << endl;
        P = next(P);
    }
}

void addTransaksi(list_transaksi &L, list_sparepart &LS, address_transaksi transaksi, address_pelanggan adrPelanggan, int nSparepart)
{
    insertTransaksi(L, transaksi);
    pelanggan(transaksi) = adrPelanggan;
    sparepart(transaksi) = NULL;
    list_sparepart_transaksi LST;
    first(LST) = sparepart(transaksi);
    string kode;

    info(transaksi).jumlah = nSparepart;
    for (int i = 0; i < nSparepart; i++)
    {
        cout << "Masukkan kode sparepart: ";
        cin >> kode;
        // Mencari address sparepart berdasarkan kode
        address_sparepart sparepart = findSparepart(LS, kode);

        if (sparepart != NULL){
            if (info(sparepart).stok == 0) {
                cout << "Stok " << info(sparepart).nama << " kosong";
            } else {
                cout << "Harga : " << info(sparepart).harga << endl;
                cout << "Service fee : " << info(sparepart).service_fee << endl;
                cout << "Stok : " << info(sparepart).stok << endl;

                info(transaksi).harga += info(sparepart).harga;
                info(transaksi).service += info(sparepart).service_fee;
                info(transaksi).total = info(transaksi).total + info(transaksi).harga + info(transaksi).service;
                info(sparepart).stok -= 1;
                addSparepartTransaksi(LST, transaksi, sparepart);
            }
        } else {
            cout << "Sparepart " << kode << " tidak ditemukan!" << endl;
        }
    }
}

void addSparepartTransaksi(list_sparepart_transaksi &LST, address_transaksi T, address_sparepart adrSparepart)
{
    address_sparepart_transaksi ST = alokasiSparepartTransaksi(adrSparepart);

    // Jika list sparepart yang dibeli kosong, masukkan sebagai elemen pertama
    if (sparepart(T) == NULL)
    {
        first(LST) = ST;
        sparepart(T) = ST;
    }
    // Jika tidak kosong, masukkan sebagai elemen terakhir
    else
    {
        address_sparepart_transaksi Q = sparepart(T);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = ST;
    }
}
void deleteFirstlistST(list_sparepart_transaksi &LST, address_sparepart_transaksi &P)
{
    if (first(LST) != NULL)
    {
        P = first(LST);
        first(LST) = next(P);
        next(P) = NULL;
    }
}

void deleteLastListST(list_sparepart_transaksi &LST, address_sparepart_transaksi &P)
{
    if (first(LST) != NULL)
    {
        address_sparepart_transaksi Q = first(LST);
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}
void deleteAfterListST(list_sparepart_transaksi &LST, address_sparepart_transaksi Prec, address_sparepart_transaksi &P)
{
    if (first(LST) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void insertListSparepartTransaksi(list_sparepart_transaksi &LST, address_sparepart_transaksi P)
{
    if (first(LST) == NULL){
        first(LST) = P;
    }else{
        address_sparepart_transaksi Q = first(LST);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
address_sparepart_transaksi findSparepartTransaksi(list_sparepart_transaksi LST, string kode){
    address_sparepart_transaksi P = first(LST);
    while (P != NULL){
        if (info(item(P)).kode != kode){
            return P;
        }
        P = next(P);
    }
    return NULL;
}
address_sparepart_transaksi hapusListST(list_sparepart_transaksi &LST, string kode){
    address_sparepart_transaksi listST = findSparepartTransaksi(LST, kode);
    if (first(LST)== listST){
        deleteFirstlistST(LST, listST);

    } else if (next(listST)== NULL) {
        deleteLastListST(LST, listST);

    } else {
        address_sparepart_transaksi prec;
        deleteAfterListST(LST, prec, listST);
    }
}

address_transaksi editDataTransaksi(list_transaksi &LT, string kode){
    int opsiT;
    address_transaksi P;

    address_transaksi transaksi = findTransaksi(LT, kode);
    if (transaksi != NULL){
        cout << "Bagian yang ingin diedit :" << endl;
        cout << "1. Tanggal Transaksi" << endl;
        cout << "2. Ganti Sparepart" << endl;
        cout << "masukan opsi :" ;
        cin >> opsiT;
        if (opsiT == 1){
            cout << "Tanggal Transaksi baru :" << endl;
            cin >> info(P).tgl_transaksi;
        } else if(opsiT == 2){
            list_sparepart_transaksi LST;
            hapusListST(LST, kode);
            int jumlah;
            cout << "Masukkan jumlah Sparepart Baru : ";
            cin >> jumlah;
            for(int i = 0; i<jumlah; i++){
                address_sparepart_transaksi P;
                cout << "Masukkan Kode : ";
                cin >> info(item(P)).kode;
                insertListSparepartTransaksi(LST, P);
            }
        } else {
            cout << "opsi" << opsiT << " tidak valid" << endl;
        }
    } else {
        cout << "Data Pelanggan tidak ditemukan" << endl;
    }
}

