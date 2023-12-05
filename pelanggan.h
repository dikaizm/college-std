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

void createList(list_pelanggan &L);
address_pelanggan alokasi(infotype_pelanggan x);
void dealokasi(address_pelanggan &P);
void insertLast(list_pelanggan &L, address_pelanggan P);

#endif // PELANGGAN_H_INCLUDED