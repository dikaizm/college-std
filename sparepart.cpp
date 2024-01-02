#include "sparepart.h"
#include "transaksi.h"

void createListSparepart(list_sparepart &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_sparepart alokasiSparepart(infotype_sparepart x)
{
    address_sparepart P = new elmlist_sparepart;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasiSparepart(address_sparepart &P)
{
    delete P;
}

void insertLast(list_sparepart &L, address_sparepart P)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertFirst(list_sparepart &L, address_sparepart P)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(first(L)) = P;
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(list_sparepart &L, address_sparepart Prec, address_sparepart P)
{
    if (first(L) != NULL && last(L) != NULL)
    {
        if (next(Prec) == NULL)
        {
            insertLast(L, P);
        }
        else
        {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        }
    }

}

void deleteFirstSparepart(list_sparepart &L, address_sparepart &P)
{
    if (first(L) != NULL && last(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteLastSparepart(list_sparepart &L, address_sparepart &P)
{
    if (first(L) != NULL && last(L) != NULL)
    {
        P = last(L);
        if (prev(P) == NULL)
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfterSparepart(list_sparepart &L, address_sparepart Prec, address_sparepart &P)
{
    if (first(L) != NULL && last(L) != NULL)
    {
        P = next(Prec);
        if (next(P) == NULL)
        {
            deleteLastSparepart(L, P);
        }
        else if (prev(P) == NULL)
        {
            deleteFirstSparepart(L, P);
        }
        else
        {
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

address_sparepart findSparepart(list_sparepart L, string kode)
{
    address_sparepart P = first(L);
    while (P != NULL)
    {
        if (info(P).kode == kode) {
            return P;
        }
        P = next(P);
    }

    return NULL;
}

void printInfoSparepart(list_sparepart L)
{
    address_sparepart P = first(L);
    cout << "=================== DAFTAR SPAREPART ===================" << endl;
    while (P != NULL)
    {
        cout << "Kode : " << info(P).kode << endl;
        cout << "Nama : " << info(P).nama << endl;
        cout << "Harga : " << info(P).harga << endl;
        cout << "Stok : " << info(P).stok << endl;
        cout << "Service Fee : " << info(P).service_fee << endl;
        cout << "Jumlah Transaksi : " << info(P).trx_count << endl;
        cout << endl;
        P = next(P);
    }
}

address_sparepart editDataSparepart(list_sparepart &LP, string kode){
    int opsis;
    address_sparepart sparepart = findSparepart(LP, kode);
    if (sparepart != NULL){
        cout << "Bagian yang ingin diedit :" << endl;
        cout << "1. Nama Sparepart" << endl;
        cout << "2. Harga Sparepart" << endl;
        cout << "3. Stok Sparepart" << endl;
        cout << "4. Service Fee Sparepart" << endl;
        cout << "Masukkan opsi : ";
        cin >> opsis;
        if (opsis == 1){
            cout << "Nama Sparepart Baru : ";
            cin >> info(sparepart).nama;
        } else if(opsis == 2){
            cout << "Harga Sparepart : ";
            cin >> info(sparepart).harga;
        } else if(opsis == 3){
            cout << "Stok Sparepart baru :" ;
            cin >> info(sparepart).stok;
        } else if (opsis == 4){
            cout << "Service Fee Sparepart baru :";
            cin >> info(sparepart).service_fee;
        } else {
            cout << "opsi" << opsis << " tidak valid" << endl;
        }
    } else {
        cout << "Data Sparepart tidak ditemukan" << endl;
    }
}

void printSparepartByMostService(list_sparepart L)
{
    address_sparepart P = first(L);

    list_sparepart sorted;
    createListSparepart(sorted);
    while (P != NULL)
    {
        address_sparepart Q = first(sorted);
        address_sparepart R = NULL;
        while (Q != NULL && info(P).trx_count < info(Q).trx_count)
        {
            R = Q;
            Q = next(Q);
        }

        if (R == NULL)
        {
            insertFirst(sorted, alokasiSparepart(info(P)));
        }
        else
        {
            insertAfter(sorted, R, alokasiSparepart(info(P)));
        }

        P = next(P);
    }

    printInfoSparepart(sorted);
}