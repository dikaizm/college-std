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

address_transaksi findTransaksi(list_transaksi L, infotype_transaksi x)
{
    address_transaksi P = first(L);
    while (P != NULL && info(P).no_transaksi != x.no_transaksi)
    {
        P = next(P);
    }
    return P;
}

void printInfoTransaksi(list_transaksi L)
{
    address_transaksi P = first(L);
    while (P != NULL)
    {
        cout << "No Transaksi : " << info(P).no_transaksi << endl;
        cout << "Tanggal Transaksi : " << info(P).tgl_transaksi << endl;
        cout << "Jumlah : " << info(P).jumlah << endl;
        cout << "Harga : " << info(P).harga << endl;
        cout << "Total : " << info(P).total << endl;
        cout << "Service : " << info(P).service << endl;

        cout << endl;
        P = next(P);
    }
}

void addTransaksi(list_transaksi &L, list_sparepart &LS, address_transaksi transaksi, address_pelanggan adrPelanggan, int nSparepart)
{
    insertTransaksi(L, transaksi);
    pelanggan(transaksi) = adrPelanggan;
    sparepart(transaksi) = NULL;
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
                addSparepartTransaksi(transaksi, sparepart);
            }
        } else {
            cout << "Sparepart " << kode << " tidak ditemukan!" << endl;
        }
    }
}

void addSparepartTransaksi(address_transaksi T, address_sparepart adrSparepart)
{
    address_sparepart_transaksi ST = alokasiSparepartTransaksi(adrSparepart);

    // Jika list sparepart yang dibeli kosong, masukkan sebagai elemen pertama
    if (sparepart(T) == NULL)
    {
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
