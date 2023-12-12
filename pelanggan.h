#ifndef PELANGGAN_H_INCLUDED
#define PELANGGAN_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef struct pelanggan infotype_pelanggan;
typedef struct elmlist_pelanggan *address_pelanggan;

struct pelanggan {
    int id;
    string nama;
    string alamat;
    string no_telp;
    string tipe_motor;
};

struct elmlist_pelanggan {
    infotype_pelanggan info;
    address_pelanggan next;
};

struct list_pelanggan {
    address_pelanggan first;
};

void createListPelanggan(list_pelanggan &L);
address_pelanggan alokasiPelanggan(infotype_pelanggan x);
void dealokasiPelanggan(address_pelanggan &P);
void insertPelanggan(list_pelanggan &L, address_pelanggan P);
void deleteFirstPelanggan(list_pelanggan &L, address_pelanggan &P);
void deleteLastPelanggan(list_pelanggan &L, address_pelanggan &P);
void deleteAfterPelanggan(list_pelanggan &L, address_pelanggan Prec, address_pelanggan &P);
address_pelanggan editData(list_pelanggan &LP, string nama, string no_telp);
address_pelanggan findPelanggan(list_pelanggan L, string nama, string no_telp);
void printInfoPelanggan(list_pelanggan L);

#endif // PELANGGAN_H_INCLUDED
