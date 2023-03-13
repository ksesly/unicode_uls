#include "../inc/libmx.h"
//#include <locale.h> 

int mx_size(wchar_t c) {
    int size = 4;
    if (c < 0x80)
        size = 1;
    else if (c < 0x0800) 
        size = 2;
    else if (c < 0x010000)
        size = 3;
    return size;
}

void mx_print_unicode(wchar_t c) {
    char temp[4];
    int size = mx_size(c);
    int step = 0;
    int move = (size - 1) * 6;
    while (step < size) {
        if (step == 0 && size == 1)
            temp[step] = (c >> move & 0x7F) | 0x00;
        else if (step == 0 && size == 2)
            temp[step] = (c >> move & 0x1F) | 0xC0;
        else if (step == 0 && size == 3)
            temp[step] = (c >> move & 0x0F) | 0xE0;
        else 
            temp[step] = (c >> move & 0x3F) | 0x80;
        step++;
        move = move - 6;
    } 
    write(1, &temp, size);
}

// int main (void) {
//     setlocale(LC_ALL, "en_US.UTF-8");
//     mx_print_unicode(0x1F);
// }

