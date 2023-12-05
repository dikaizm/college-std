#ifndef SPAREPART_H_INCLUDED
#define SPAREPART_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

typedef struct sparepart infotype_sparepart;
typedef struct elmlist_sparepart *address_sparepart;

struct sparepart {
    string kode;
    string nama;
    int harga;
    int stok;
    int service_fee;
};

struct elmlist_sparepart {
    infotype_sparepart info;
    address_sparepart next;
    address_sparepart prev;
};

struct list_sparepart {
    address_sparepart first;
    address_sparepart last;
};

void createListSparepart(list_sparepart &L);
address_sparepart alokasiSparepart(infotype_sparepart x);
void dealokasiSparepart(address_sparepart &P);
void insertSparepart(list_sparepart &L, address_sparepart P);
void deleteFirstSparepart(list_sparepart &L, address_sparepart &P);
void deleteLastSparepart(list_sparepart &L, address_sparepart &P);
void deleteAfterSparepart(list_sparepart &L, address_sparepart Prec, address_sparepart &P);

address_sparepart findSparepart(list_sparepart L, string kode);
void printInfoSparepart(list_sparepart L);

#endif // SPAREPART_H_INCLUDED