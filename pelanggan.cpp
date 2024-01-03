#include "pelanggan.h"

void createListPelanggan(list_pelanggan &L)
{
    first(L) = NULL;
}

address_pelanggan alokasiPelanggan(infotype_pelanggan x)
{
    address_pelanggan P = new elmlist_pelanggan;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiPelanggan(address_pelanggan &P)
{
    delete P;
}

void insertPelanggan(list_pelanggan &L, address_pelanggan P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        address_pelanggan Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstPelanggan(list_pelanggan &L, address_pelanggan &P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastPelanggan(list_pelanggan &L, address_pelanggan &P)
{
    if (first(L) != NULL)
    {
        address_pelanggan Q = first(L);
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfterPelanggan(list_pelanggan &L, address_pelanggan Prec, address_pelanggan &P)
{
    if (first(L) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_pelanggan findPelanggan(list_pelanggan L, string nama, string no_telp)
{
    address_pelanggan P = first(L);
    while (P != NULL)
    {
        if (info(P).nama == nama && info(P).no_telp == no_telp) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfoPelanggan(list_pelanggan L)
{
    address_pelanggan P = first(L);
    cout << "=================== DAFTAR PELANGGAN ===================" << endl;
    while (P != NULL)
    {
        cout << "ID : " << info(P).id << endl;
        cout << "Nama : " << info(P).nama << endl;
        cout << "No. Telp : " << info(P).no_telp << endl;
         cout << "Alamat : " << info(P).alamat << endl;
        cout << "Tipe Motor : " << info(P).tipe_motor << endl;
        cout << endl;
        P = next(P);
    }
    cout << "========================================================" << endl;
}
address_pelanggan editDataPelanggan(list_pelanggan &LP, string nama, string no_telp){
    int opsip;
    address_pelanggan pelanggan = findPelanggan(LP, nama, no_telp);
    if (pelanggan != NULL){
        cout << "Bagian yang ingin diedit :" << endl;
        cout << "1. Nama Pelanggan" << endl;
        cout << "2. Alamat Pelanggan" << endl;
        cout << "3. No. Telphone Pelanggan" << endl;
        cout << "4. Tipe Motor Pelanggan" << endl;
        cout << "masukan opsi :" ;
        cin >> opsip;
        if (opsip == 1){
            cout << "Nama pelanggan baru :" << endl;
            cin >> info(pelanggan).nama;
        } else if(opsip == 2){
            cout << "Alamat Pelanggan :" << endl;
            cin >> info(pelanggan).alamat;
        } else if(opsip == 3){
            cout << "No. Telephone Pelanggan yang baru :" << endl;
            cin >> info(pelanggan).no_telp;
        } else if (opsip == 4){
            cout << "Tipe Motor Pelanggan yang baru :" << endl;
            cin >> info(pelanggan).tipe_motor;
        } else {
            cout << "opsi" << opsip << " tidak valid" << endl;
        }
    } else {
        cout << "Data Pelanggan tidak ditemukan" << endl;
    }
}
void printFindP(list_pelanggan LP, string nama ,string notelp){
    address_pelanggan P = findPelanggan(LP, nama, notelp);
    if (P!=NULL){
        cout << "================================================"<<endl;
        cout << "ID : " << info(P).id << endl;
        cout << "Nama : " << info(P).nama << endl;
        cout << "No. Telp : " << info(P).no_telp << endl;
        cout << "Alamat : " << info(P).alamat << endl;
        cout << "Tipe Motor : " << info(P).tipe_motor << endl;
        cout << endl;
        cout << "================================================"<<endl;
        cout << endl;
    } else{
        cout << "================================================"<<endl;
        cout << "            ID Pelanggan Tidak Ditemukan        "<< endl;
        cout << "================================================"<<endl;
        cout << endl;
    }
}

