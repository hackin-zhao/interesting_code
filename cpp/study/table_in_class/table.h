#ifndef _TABLE_H_
#define _TABLE_H_

#include <iostream>

typedef void (*rename)(const char name);
struct people {
    int age;
    char name;
    int height;
    rename rname;
};

// void re_name(const char name);
// void my_remame(const char name);

class Table {
public:
    Table();
    ~Table();

private:
    void re_name(const char name);
    void my_remame(const char name);

    struct people peo[10] = {
        { 110, '2', 10, re_name },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
        { 110, '2', 10, NULL },
    };
};

#endif // _TABLE_H_
