#include "transaksi.h"
#include "pelanggan.h"
#include "sparepart.h"

void createListTransaksi(list_transaksi &L)
{
    first(L) = NULL;
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

void addTransaksi(list_transaksi &L, list_sparepart &LS, address_transaksi P, address_pelanggan Q, int nSparepart)
{
    insertTransaksi(L, P);
    pelanggan(P) = Q;
    string kode;

// input jumlah sparepart
    for (int i = 0; i < nSparepart; i++)
    {
        // masukkan kode sparepart
        cin >> kode;
        // find address sparepart
        address_sparepart R = findSparepart(LS, kode);
        addSparepartTransaksi(L, P, R);
    }
}

void addSparepartTransaksi(list_transaksi &L, address_transaksi P, address_sparepart R)
{
    address_sparepart_transaksi S = new elmlist_sparepart_transaksi;
    next(S) = NULL;
    item(S) = R;
    if (sparepart(P) == NULL)
    {
        sparepart(P) = S;
    }
    else
    {
        address_sparepart_transaksi Q = sparepart(P);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = S;
    }
}
