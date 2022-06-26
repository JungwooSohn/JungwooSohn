#include <stdio.h>

int main() {


    return 0;
}

void remove_filename(char *url) {


    url += strlen(url);
    while(url != '/') {
        url--;
    }

    *url = '\0';
}
