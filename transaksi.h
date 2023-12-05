#ifndef TRANSAKSI_H_INCLUDED
#define TRANSAKSI_H_INCLUDED

#include <iostream>
#include "pelanggan.h"
#include "sparepart.h"

using namespace std;

#define first(L) L.first
#define next(P) P->next
#define pelanggan(P) P->pelanggan
#define sparepart(P) P->sparepart
#define item(P) P->item
#define info(P) P->info

typedef struct elmlist_transaksi *address_transaksi;
typedef struct elmlist_sparepart_transaksi *address_sparepart_transaksi;
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
    address_sparepart_transaksi sparepart;
    address_transaksi next;
};

struct elmlist_sparepart_transaksi {
    address_sparepart_transaksi next;
    address_sparepart item;
};

struct list_transaksi {
    address_transaksi first;
};

void createListTransaksi(list_transaksi &L);
void insertLast(list_transaksi &L, address_transaksi P);
void deleteFirstTransaksi(list_transaksi &L, address_transaksi &P);
void deleteLastTransaksi(list_transaksi &L, address_transaksi &P);
void deleteAfterTransaksi(list_transaksi &L, address_transaksi Prec, address_transaksi &P);
address_transaksi findTransaksi(list_transaksi L, infotype_transaksi x);
void printInfoTransaksi(list_transaksi L);
address_transaksi alokasiTransaksi(infotype_transaksi x);
void dealokasiTransaksi(address_transaksi &P);

void addTransaksi(list_transaksi &L, address_transaksi P, address_pelanggan Q, address_sparepart R);
void addSparepartTransaksi(list_transaksi &L, address_transaksi P, address_sparepart R);

#endif // TRANSAKSI_H_INCLUDED