#pragma once

#define LEN 10

struct month {
    char name[LEN];
    char abbr[4];
    int days;
    int m_num;
};

extern struct month year[];
