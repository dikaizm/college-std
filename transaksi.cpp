#include "transaksi.h"
#include "pelanggan.h"
#include "sparepart.h"

void createListTransaksi(list_transaksi &L)
{
    first(L) = NULL;
}

void createListSparepartTransaksi(list_sparepart_transaksi &LST)
{
    first(LST) = NULL;
}

address_transaksi alokasiTransaksi(infotype_transaksi x)
{
    address_transaksi P = new elmlist_transaksi;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiTransaksi(address_transaksi &P)
{
    delete P;
}

address_sparepart_transaksi alokasiSparepartTransaksi(address_sparepart adrSparepart)
{
    address_sparepart_transaksi S = new elmlist_sparepart_transaksi;
    next(S) = NULL;
    item(S) = adrSparepart;
    return S;
}

void insertLastTransaksi(list_transaksi &L, address_transaksi P)
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
        if (info(P).no_transaksi == no_transaksi)
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

    cout << "=================== DAFTAR TRANSAKSI ===================" << endl;
    if (first(L) != NULL)
    {
        while (P != NULL)
        {
            cout << "No Transaksi : " << info(P).no_transaksi << "  |  ";
            cout << "Tanggal Transaksi : " << info(P).tgl_transaksi << endl;
            cout << "Nama Pelanggan : " << info(pelanggan(P)).nama << "  |  ";
            cout << "Telepon Pelanggan : " << info(pelanggan(P)).no_telp << endl;

            cout << "Jumlah Sparepart : " << info(P).jumlah << endl;
            cout << "Daftar Sparepart : " << endl;

            address_sparepart_transaksi ST = first(sparepart(P));
            while (ST != NULL)
            {
                cout << "    "
                     << "Kode : " << info(item(ST)).kode << endl;
                cout << "    "
                     << "Nama : " << info(item(ST)).nama << endl;
                cout << "    "
                     << "Harga : " << info(item(ST)).harga << endl;
                cout << "    "
                     << "Service : " << info(item(ST)).service_fee << endl;
                cout << "    "
                     << "------------" << endl;

                ST = next(ST);
            }

            cout << "Total Harga : " << info(P).harga << endl;
            cout << "Total Service : " << info(P).service << endl;
            cout << "___________________________ +" << endl;
            cout << "Total : " << info(P).total << endl;
            cout << "--------------------------------------" << endl;

            P = next(P);
        }
    }
    else
    {
        cout << "Transaksi kosong" << endl;
    }
}

void addTransaksi(list_transaksi &L, list_sparepart &LS, address_transaksi transaksi, address_pelanggan adrPelanggan, int nSparepart)
{
    insertLastTransaksi(L, transaksi);
    pelanggan(transaksi) = adrPelanggan;

    list_sparepart_transaksi LST;
    createListSparepartTransaksi(LST);

    sparepart(transaksi) = LST;

    string kode;

    info(transaksi).jumlah = nSparepart;
    for (int i = 0; i < nSparepart; i++)
    {
        cout << "Masukkan kode sparepart: ";
        cin >> kode;
        // Mencari address sparepart berdasarkan kode
        address_sparepart sparepart = findSparepart(LS, kode);

        if (sparepart != NULL)
        {
            if (info(sparepart).stok == 0)
            {
                cout << "Stok " << info(sparepart).nama << " kosong";
            }
            else
            {
                cout << "Harga : " << info(sparepart).harga << endl;
                cout << "Service fee : " << info(sparepart).service_fee << endl;
                cout << "Stok : " << info(sparepart).stok << endl;
                cout << endl;

                info(transaksi).harga += info(sparepart).harga;
                info(transaksi).service += info(sparepart).service_fee;
                info(sparepart).stok -= 1;
                info(sparepart).trx_count += 1;

                insertSparepartTransaksi(sparepart(transaksi), transaksi, sparepart);
            }
        }
        else
        {
            cout << "Sparepart " << kode << " tidak ditemukan!" << endl;
        }
    }

    info(transaksi).total = info(transaksi).harga + info(transaksi).service;
}

void insertSparepartTransaksi(list_sparepart_transaksi &LST, address_transaksi T, address_sparepart adrSparepart)
{
    address_sparepart_transaksi ST = alokasiSparepartTransaksi(adrSparepart);

    // Jika list sparepart yang dibeli kosong, masukkan sebagai elemen pertama
    if (first(LST) == NULL)
    {
        first(LST) = ST;
    }
    // Jika tidak kosong, masukkan sebagai elemen terakhir
    else
    {
        address_sparepart_transaksi Q = first(LST);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = ST;
    }
}

void deleteFirstST(list_sparepart_transaksi &LST, address_sparepart_transaksi &P)
{
    if (first(LST) != NULL)
    {
        P = first(LST);
        first(LST) = next(P);
        next(P) = NULL;
    }
}

void deleteLastST(list_sparepart_transaksi &LST, address_sparepart_transaksi &P)
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

void deleteAfterST(list_sparepart_transaksi &LST, address_sparepart_transaksi Prec, address_sparepart_transaksi &P)
{
    if (first(LST) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_sparepart_transaksi findSparepartTransaksi(list_sparepart_transaksi L, string kode)
{
    address_sparepart_transaksi P = first(L);
    while (P != NULL)
    {
        if (info(item(P)).kode != kode)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void editDataTransaksi(list_transaksi &LT, list_sparepart LS, string kode)
{
    int opsiT;
    address_transaksi P;

    address_transaksi transaksi = findTransaksi(LT, kode);
    if (transaksi != NULL)
    {
        cout << "Bagian yang ingin diedit :" << endl;
        cout << "1. Tanggal Transaksi" << endl;
        cout << "2. Tambah Sparepart" << endl;
        cout << "3. Ganti Sparepart" << endl;
        cout << "4. Hapus Sparepart" << endl;
        cout << "Masukan opsi : ";
        cin >> opsiT;
        if (opsiT == 1)
        {
            cout << "Tanggal Transaksi baru :" << endl;
            cin >> info(P).tgl_transaksi;
        }
        else if (opsiT == 2)
        {
            int jumlah;
            cout << "Masukkan jumlah sparepart baru : ";
            cin >> jumlah;
            for (int i = 0; i < jumlah; i++)
            {
                address_sparepart_transaksi P;
                cout << "Masukkan Kode : ";
                cin >> info(item(P)).kode;
                address_sparepart sparepart = findSparepart(LS, info(item(P)).kode);

                if (sparepart != NULL)
                {
                    if (info(sparepart).stok == 0)
                    {
                        cout << "Stok " << info(sparepart).nama << " kosong";
                    }
                    else
                    {
                        cout << "Harga : " << info(sparepart).harga << endl;
                        cout << "Service fee : " << info(sparepart).service_fee << endl;
                        cout << "Stok : " << info(sparepart).stok << endl;
                        cout << endl;

                        info(transaksi).harga += info(sparepart).harga;
                        info(transaksi).service += info(sparepart).service_fee;
                        info(sparepart).stok -= 1;
                        info(sparepart).trx_count += 1;

                        insertSparepartTransaksi(sparepart(transaksi), transaksi, sparepart);
                    }
                }
                else
                {
                    cout << "Sparepart " << info(item(P)).kode << " tidak ditemukan!" << endl;
                }
            }
        }
        else if (opsiT == 3)
        {
            string kode;
            cout << "Masukkan kode sparepart yang ingin diganti : ";
            cin >> kode;

            address_sparepart_transaksi sparepart = findSparepartTransaksi(sparepart(transaksi), kode);
            if (sparepart != NULL)
            {
                cout << "Masukkan kode sparepart baru : ";
                cin >> kode;

                address_sparepart newSparepart = findSparepart(LS, kode);
                if (newSparepart != NULL)
                {
                    info(item(sparepart)).stok += 1;
                    info(item(sparepart)).trx_count -= 1;

                    item(sparepart) = newSparepart;
                    info(item(sparepart)).stok -= 1;
                    info(item(sparepart)).trx_count += 1;
                }
                else
                {
                    cout << "Sparepart tidak ditemukan" << endl;
                }
            }
            else
            {
                cout << "Sparepart tidak ditemukan" << endl;
            }
        }
        else if (opsiT == 4)
        {
            string kode;
            cout << "Masukkan kode sparepart yang ingin dihapus : ";
            cin >> kode;

            address_sparepart_transaksi sparepart = findSparepartTransaksi(sparepart(transaksi), kode);
            if (sparepart != NULL)
            {
                info(item(sparepart)).stok += 1;
                info(item(sparepart)).trx_count -= 1;

                if (sparepart == first(sparepart(transaksi)))
                {
                    deleteFirstST(sparepart(transaksi), sparepart);
                }
                else if (next(sparepart) == NULL)
                {
                    deleteLastST(sparepart(transaksi), sparepart);
                }
                else
                {
                    address_sparepart_transaksi Prec = first(sparepart(transaksi));
                    while (next(Prec) != sparepart)
                    {
                        Prec = next(Prec);
                    }
                    deleteAfterST(sparepart(transaksi), Prec, sparepart);
                }
            }
            else
            {
                cout << "Sparepart tidak ditemukan" << endl;
            }
        }
        else
        {
            cout << "Opsi" << opsiT << " tidak valid" << endl;
        }
    }
    else
    {
        cout << "Data transaksi tidak ditemukan" << endl;
    }
}

void deleteDataTransaksi(list_transaksi &LT, string no_transaksi)
{
    address_transaksi transaksi = findTransaksi(LT, no_transaksi);
    if (transaksi != NULL)
    {
        address_sparepart_transaksi sparepart = first(sparepart(transaksi));
        while (sparepart != NULL)
        {
            info(item(sparepart)).stok += 1;
            info(item(sparepart)).trx_count -= 1;

            sparepart = next(sparepart);
        }

        if (transaksi == first(LT))
        {
            deleteFirstTransaksi(LT, transaksi);
        }
        else if (next(transaksi) == NULL)
        {
            deleteLastTransaksi(LT, transaksi);
        }
        else
        {
            address_transaksi Prec = first(LT);
            while (next(Prec) != transaksi)
            {
                Prec = next(Prec);
            }
            deleteAfterTransaksi(LT, Prec, transaksi);
        }
    }
    else
    {
        cout << "Transaksi tidak ditemukan" << endl;
    }
}

void deleteDataTransaksiByPelanggan(list_transaksi &LT, address_pelanggan pelanggan)
{
    int countDeleted = 0;
    address_transaksi transaksi = first(LT);
    while (transaksi != NULL)
    {
        if (pelanggan(transaksi) == pelanggan)
        {
            countDeleted++;
            address_sparepart_transaksi sparepart = first(sparepart(transaksi));
            while (sparepart != NULL)
            {
                info(item(sparepart)).stok += 1;
                info(item(sparepart)).trx_count -= 1;

                sparepart = next(sparepart);
            }

            if (transaksi == first(LT))
            {
                deleteFirstTransaksi(LT, transaksi);
            }
            else if (next(transaksi) == NULL)
            {
                deleteLastTransaksi(LT, transaksi);
            }
            else
            {
                address_transaksi Prec = first(LT);
                while (next(Prec) != transaksi)
                {
                    Prec = next(Prec);
                }
                deleteAfterTransaksi(LT, Prec, transaksi);
            }
            dealokasiTransaksi(transaksi);
        }

        transaksi = next(transaksi);
    }
    cout << "Berhasil menghapus " << countDeleted << " transaksi dengan pelanggan " << info(pelanggan).nama << endl;
}

void deleteDataTransaksiBySparepart(list_transaksi &LT, address_sparepart sparepart)
{
    int countDeleted = 0;
    address_transaksi transaksi = first(LT);
    while (transaksi != NULL)
    {
        bool found = false;
        address_sparepart_transaksi ST = first(sparepart(transaksi));
        while (ST != NULL)
        {
            if (item(ST) == sparepart)
            {
                found = true;
            }
            if (found)
            {
                info(item(ST)).stok += 1;
                info(item(ST)).trx_count -= 1;
            }

            ST = next(ST);
        }

        if (found)
        {
            countDeleted++;
            if (transaksi == first(LT))
            {
                deleteFirstTransaksi(LT, transaksi);
            }
            else if (next(transaksi) == NULL)
            {
                deleteLastTransaksi(LT, transaksi);
            }
            else
            {
                address_transaksi Prec = first(LT);
                while (next(Prec) != transaksi)
                {
                    Prec = next(Prec);
                }
                deleteAfterTransaksi(LT, Prec, transaksi);
            }
            dealokasiTransaksi(transaksi);
        }

        transaksi = next(transaksi);
    }
    cout << "Berhasil menghapus " << countDeleted << " transaksi dengan sparepart " << info(sparepart).nama << endl;
}
void printFindT(list_transaksi L, string kode){
     address_transaksi P = findTransaksi(L, kode);
    if (P!=NULL){
        cout << "No Transaksi : " << info(P).no_transaksi << "  |  ";
        cout << "Tanggal Transaksi : " << info(P).tgl_transaksi << endl;
        cout << "Nama Pelanggan : " << info(pelanggan(P)).nama << "  |  ";
        cout << "Telepon Pelanggan : " << info(pelanggan(P)).no_telp << endl;
        cout << "Jumlah Sparepart : " << info(P).jumlah << endl;
        cout << "Daftar Sparepart : " << endl;
        address_sparepart_transaksi ST = first(sparepart(P));
        while (ST != NULL){
               cout << "    "
                     << "Kode : " << info(item(ST)).kode << endl;
                cout << "    "
                     << "Nama : " << info(item(ST)).nama << endl;
                cout << "    "
                     << "Harga : " << info(item(ST)).harga << endl;
                cout << "    "
                     << "Service : " << info(item(ST)).service_fee << endl;
                cout << "    "
                     << "------------" << endl;
                ST = next(ST);
            }
            cout << "Total Harga : " << info(P).harga << endl;
            cout << "Total Service : " << info(P).service << endl;
            cout << "___________________________ +" << endl;
            cout << "Total : " << info(P).total << endl;
            cout << "--------------------------------------" << endl;
    } else{
        cout << "================================================"<<endl;
        cout << "           Kode Sparepart Tidak Ditemukan       "<< endl;
        cout << "================================================"<<endl;
        cout << endl;
    }
}
