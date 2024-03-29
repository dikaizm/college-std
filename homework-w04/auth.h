#ifndef AUTH_H_INCLUDED
#define AUTH_H_INCLUDED

#include <iostream>
#include <string>
#define Nil NULL
#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define first(L) (L).first
#define last(L) (L).last

using namespace std;

typedef struct User infotype;
typedef struct elmlist *address;

struct User {
    string username;
    string password;
};

struct elmlist {
    User info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

address createNewElm(infotype akun);

void insertLast(address p, list &L);

address findAkun(string username, list L);

void signUp(infotype akun, list &L);

void deleteFirst(list &L, address p);

void deleteAfter(list &L, address q, address p);

void deleteLast(list &L, address p);

void removeAkun(string username, list &L);

#endif // AUTH_H_INCLUDED
