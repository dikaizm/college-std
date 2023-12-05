#include "pelanggan.h"
#include "sparepart.h"
// #include "transaksi.h"

int main()
{
    list_pelanggan LP;
    list_sparepart LS;
    // list_transaksi LT;

    createListPelanggan(LP);

    infotype_pelanggan infoP;
    for (int i = 0; i < 2; i++)
    {
        cout << "Masukkan pelanggan: ";
        cin >> infoP.id >> infoP.nama >> infoP.alamat >> infoP.no_telp >> infoP.tipe_motor;
        insertPelanggan(LP, alokasiPelanggan(infoP));
    }

    printInfoPelanggan(LP);

    createListSparepart(LS);

    infotype_sparepart infoS;
    for (int i = 0; i < 2; i++)
    {
        cout << "Masukkan sparepart: ";
        cin >> infoS.kode >> infoS.nama >> infoS.harga >> infoS.stok >> infoS.service_fee;
        insertSparepart(LS, alokasiSparepart(infoS));
    }

    printInfoSparepart(LS);

    // createListTransaksi(LT);

    return 0;
}
