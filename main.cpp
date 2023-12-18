#include "pelanggan.h"
#include "sparepart.h"
#include "transaksi.h"

int main()
{
    list_pelanggan LP;
    list_sparepart LS;
    list_transaksi LT;

    createListPelanggan(LP);
    createListSparepart(LS);
    createListTransaksi(LT);

    int opsi = -1;
    while (opsi != 00) {
        cout << "=================== APLIKASI SERVICE MOTOR ===================" << endl;
        cout << "1. SPAREPART" << endl;
        cout << "2. TRANSAKSI" << endl;
        cout << "3. PELANGGAN" << endl;
        cout << "00. Keluar" << endl;

        cout << "Pilih Menu: ";
        cin >> opsi;

        cout << "==============================================================" << endl;
        cout << endl;

        if (opsi == 1) {
            int opsiS = -1;
            while (opsiS != 0) {
                cout << "=================== SPAREPART ===================" << endl;
                cout << "1. Tambah sparepart" << endl;
                cout << "2. Lihat daftar sparepart" << endl;
                cout << "3. Edit Data Sparepart" << endl;
                cout << "4. Hapus Data Sparepart"<< endl;
                cout << "0. Kembali" << endl;

                cout << "Pilih menu: ";
                cin >> opsiS;
                if (opsiS == 1) {
                    int nSparepart;

                    cout << "Masukkan jumlah sparepart baru: ";
                    cin >> nSparepart;
                    for (int i = 0; i < nSparepart; i++) {
                        infotype_sparepart infoS;
                        cout << "----------------------" << endl;
                        cout << "Input ke-" << i+1 << endl;
                        cout << "Masukkan data sparepart baru:" << endl;
                        cout << "Kode: ";
                        cin >> infoS.kode;
                        cout << "Nama: ";
                        cin >> infoS.nama;
                        cout << "Stok: ";
                        cin >> infoS.stok;
                        cout << "Harga: ";
                        cin >> infoS.harga;
                        cout << "Biaya service: ";
                        cin >> infoS.service_fee;

                        insertSparepart(LS, alokasiSparepart(infoS));
                    }
                } else if (opsiS == 2) {
                    printInfoSparepart(LS);
                } else if (opsiS == 3){
                    string kode;
                    cout << "masukkan kode : ";
                    cin >> kode;
                    editDataSparepart(LS, kode);
                } else if(opsiS == 4){
                    string kode;
                    cout << "masukkan kode : ";
                    cin >> kode;
                    address_sparepart sparepart = findSparepart(LS,kode);
                    if (first(LS) == sparepart){
                        deleteFirstSparepart(LS, sparepart);
                    } else if (next(sparepart)== NULL) {
                        deleteLastSparepart(LS, sparepart);
                    } else {
                        address_sparepart prec;
                        deleteAfterSparepart(LS, prec, sparepart);
                    }
                    printInfoSparepart(LS);
                }else if (opsiS == 0) {
                    cout << "Kembali..." << endl;
                } else {
                    cout << "Opsi " << opsiS << " tidak valid" << endl;
                }
            }

            cout << endl;
        } else if (opsi == 2) {
            int opsiT = -1;
            while (opsiT != 0) {
                cout << "=================== TRANSAKSI ===================" << endl;
                cout << "1. Tambah transaksi" << endl;
                cout << "2. Lihat daftar transaksi" << endl;
                cout << "3. Edit Data Transaksi" << endl;
                cout << "4. Hapus Data Transaksi" << endl;
                cout << "0. Kembali" << endl;

                cout << "Pilih menu: ";
                cin >> opsiT;
                if (opsiT == 1) {
                    // masukkan nama dan no telp pelanggan
                    infotype_pelanggan infoP;
                    cout << "Masukkan data pelanggan: " << endl;
                    cout << "ID: ";
                    cin >> infoP.id;
                    cout << "Nama: ";
                    cin >> infoP.nama;
                    cout << "No. Telepon: ";
                    cin >> infoP.no_telp;
                    infoP.alamat = "";
                    infoP.tipe_motor = "";

                    // cek apakah pelanggan sudah ada di list pelanggan
                    address_pelanggan adrPelanggan = findPelanggan(LP, infoP.nama, infoP.no_telp);

                    // jika tidak masukkan data pelanggan baru
                    if (adrPelanggan == NULL) {
                        cout << "Alamat: ";
                        cin >> infoP.alamat;
                        cout << "Tipe Motor: ";
                        cin >> infoP.tipe_motor;

                        adrPelanggan = alokasiPelanggan(infoP);
                        insertPelanggan(LP, adrPelanggan);
                    }

                    infotype_transaksi infoT;
                    cout << "Masukkan data transaksi: " << endl;
                    cout << "No Transaksi: ";
                    cin >> infoT.no_transaksi;
                    cout << "Tanggal transaksi: ";
                    cin >> infoT.tgl_transaksi;

                    infoT.jumlah = 0;
                    infoT.harga = 0;
                    infoT.service = 0;
                    infoT.total = 0;
                    address_transaksi adrTransaksi = alokasiTransaksi(infoT);

                    int nSparepart;
                    cout << "Berapa sparepart yang diganti? ";
                    cin >> nSparepart;
                    addTransaksi(LT, LS, adrTransaksi, adrPelanggan, nSparepart);
                } else if (opsiT == 2) {
                    printInfoTransaksi(LT);
                } else if (opsiT == 0) {
                    cout << "Kembali..." << endl;
                } else {
                    cout << "Opsi " << opsiT << " tidak valid" << endl;
                }
            }

        } else if (opsi == 3){
            int opsiP = -1;
            string nama, no_telp;
            while (opsiP != 0) {
                cout << "=================== PELANGGAN ===================" << endl;
                printInfoPelanggan(LP);
                cout << endl;
                cout << "1. Edit Pelanggan" << endl;
                cout << "2. Hapus Pelanggan" << endl;
                cout << "0. Kembali" << endl;
                cout << "pilih menu : ";
                cin >> opsiP;
                if (opsiP == 1) {
                    string nama, no_telp;
                    cout << "Masukkan Nama: ";
                    cin >> nama;
                    cout << "Masukkan No. Telp: ";
                    cin >> no_telp;
                    editDataPelanggan(LP, nama, no_telp);
                } else if (opsiP == 2) {
                    string nama, no_telp;
                    cout << "Masukkan Nama : ";
                    cin >> nama;
                    cout << "Masukkan No. Telp : ";
                    cin >> no_telp;
                    address_pelanggan pelanggan = findPelanggan(LP, nama, no_telp);
                    if (first(LP) == pelanggan){
                        deleteFirstPelanggan(LP, pelanggan);
                    } else if (next(pelanggan)== NULL) {
                        deleteLastPelanggan(LP, pelanggan);
                    } else {
                        address_pelanggan prec;
                        deleteAfterPelanggan(LP, prec, pelanggan);
                    }
                    printInfoPelanggan(LP);
                } else if (opsiP == 0) {
                    cout << "Kembali..." << endl;
                } else {
                    cout << "Opsi " << opsiP << " tidak valid" << endl;
                }
            }

        } else {
            cout << "Opsi " << opsi << " tidak valid" << endl;
        }
    }

    cout << "Terima kasih, sampai jumpa kembali" << endl;
    return 0;
}
