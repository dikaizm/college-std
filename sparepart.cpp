#include "sparepart.h"
void createListSparepart(list_sparepart &L){
    first(L) = NULL;
    last(L) = NULL;
}
address_sparepart alokasiSparepart(infotype_sparepart x){
    address_sparepart P = new elmlist_sparepart;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasiSparepart(address_sparepart &P){
    delete P;
}
void insertSparepart(list_sparepart &L, address_sparepart P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }

}
void deleteFirstSparepart(list_sparepart &L, address_sparepart &P){
    if (first(L) != NULL && last(L) != NULL){
        P = first(L);
        if (next(P) == NULL){
            first(L) = NULL;
            last(L) = NULL;
        }else{
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}
void deleteLastSparepart(list_sparepart &L, address_sparepart &P){
    if (first(L) != NULL && last(L) != NULL){
        P = last(L);
        if (prev(P) == NULL){
            first(L) = NULL;
            last(L) = NULL;
        }else{
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}
void deleteAfterSparepart(list_sparepart &L, address_sparepart Prec, address_sparepart &P){
    if (first(L) != NULL && last(L) != NULL){
        P = next(Prec);
        if (next(P) == NULL){
            deleteLastSparepart(L,P);
        }else if (prev(P) == NULL){
            deleteFirstSparepart(L,P);
        }else{
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }

}

address_sparepart findSparepart(list_sparepart L, infotype_sparepart x){
    address_sparepart P = first(L);
    while (P != NULL && info(P).kode != x.kode){
        P = next(P);
    }
    return P;
}
void printInfoSparepart(list_sparepart L){
    address_sparepart P = first(L);
    while (P != NULL){
        cout<<"Kode Sparepart : "<<info(P).kode<<endl;
        cout<<"Nama Sparepart : "<<info(P).nama<<endl;
        cout<<"Harga Sparepart : "<<info(P).harga<<endl;
        cout<<"Stok Sparepart : "<<info(P).stok<<endl;
        cout<<"Service Fee Sparepart : "<<info(P).service_fee<<endl;
        cout<<endl;
        P = next(P);
    }
}

