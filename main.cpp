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
                cout << "0. Kembali" << endl;

                cout << "Pilih menu: ";
                cin >> opsiS;
                if (opsiS == 1) {
                    int nSparepart;
                    infotype_sparepart infoS;
                    cout << "Masukkan jumlah sparepart baru: ";
                    cin >> nSparepart;
                    for (int i = 0; i < nSparepart; i++) {
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
                } else {
                    cout << "Opsi " << opsiS << " tidak valid" << endl;
                }
            }

            cout << endl;
        } else if (opsi == 2) {
            infotype_pelanggan infoP;
            cout << "Masukkan data pelanggan: " << endl;
            cout << "ID: ";
            cin >> infoP.id;
            cout << "Nama: ";
            cin >> infoP.nama;
            cout << "Alamat: ";
            cin >> infoP.alamat;
            cout << "No. Telphone: ";
            cin >> infoP.no_telp;
            cout << "Tipe Motor: ";
            cin >> infoP.tipe_motor;

            address_pelanggan adrPelanggan = alokasiPelanggan(infoP);
            // masukkan nama pelanggan
            // cek apakah pelanggan sudah ada di list pelanggan
            // jika ada, pakai address pelanggan
            // jika tidak masukkan data pelanggan baru

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
        } else if (opsi == 3){
            cout << "=================== PELANGGAN ===================" << endl;
            printInfoPelanggan(LP);

            cout << endl;
            cout << "1. Edit Pelanggan" << endl;
            cout << "2. Hapus Pelanggan" << endl;
            cout << "0. Kembali" << endl;

            int opsiP;
            cout << "Pilih menu: ";
            cin >> opsiP;
            string nama, no_telp;
            if (opsiP == 1) {
                editData(LP, nama, no_telp);
            } else if (opsiP == 2) {
               address_pelanggan pelanggan = findPelanggan(LP, nama, no_telp);
                if (first(LP) == pelanggan){
                    deleteFirstPelanggan(LP, pelanggan);
                } else if (next(pelanggan)== NULL) {
                    deleteLastPelanggan(LP, pelanggan);
                } else {
                    address_pelanggan prec;
                    deleteAfterPelanggan(LP, prec, pelanggan);
                }
            } else {
                cout << "Opsi " << opsiP << " tidak valid" << endl;
            }

        } else {
            cout << "Opsi " << opsi << " tidak valid" << endl;
        }
    }

    cout << "Terima kasih, sampai jumpa kembali" << endl;
    return 0;
}
