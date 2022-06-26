#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main() {

    char exam_domain[] = "knking.com";
    char exam[100];
    build_index_url(exam_domain, exam);

    printf("%s", exam);

    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "https://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}
