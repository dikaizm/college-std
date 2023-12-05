#ifndef TRANSAKSI_H_INCLUDED
#define TRANSAKSI_H_INCLUDED
#include <iostream>
#include "pelanggan.h"
#include "sparepart.h"
using namespace std;
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
typedef struct elmlist_transaksi *address_transaksi;
typedef struct transaksi infotype_transaksi;
struct transaksi {
    string no_transaksi;
    string tgl_transaksi;
    int jumlah;
    int harga;
    int total;
    int service;
};
struct elmlist_transaksi {
    infotype_transaksi info;
    address_pelanggan pelanggan;
    address_sparepart sparepart;
    address_transaksi next;
};
struct list_transaksi {
    address_transaksi first;
};
void createListTransaksi(list_transaksi &L);
void insertTransaksi(list_transaksi &L, address_transaksi P);
void deleteFirstTransaksi(list_transaksi &L, address_transaksi &P);
void deleteLastTransaksi(list_transaksi &L, address_transaksi &P);
void deleteAfterTransaksi(list_transaksi &L, address_transaksi Prec, address_transaksi &P);
address_transaksi findTransaksi(list_transaksi L, infotype_transaksi x);
void printInfoTransaksi(list_transaksi L);
address_transaksi alokasiTransaksi(infotype_transaksi x);
void dealokasiTransaksi(address_transaksi &P);

#endif // TRANSAKSI_H_INCLUDED