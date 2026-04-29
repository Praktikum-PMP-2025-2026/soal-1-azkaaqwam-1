

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilaipenting;
} Artefak;
int bandingkan_artefak(const void *a, const void *b) {
    Artefak *m1 = (Artefak *)a;
    Artefak *m2 = (Artefak *)b;
    
    return strcmp(m1->kategori,m2->kategori);
    if (m1->tahun != m2->tahun) {
        return m2->tahun - m1->tahun;
    }
    if (m1->nilaipenting != m2->nilaipenting) {
        return m1->nilaipenting - m2->nilaipenting;
    }
    return strcmp(m1->nama, m2->nama);
}
int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    Artefak daftar[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", daftar[i].nama, daftar[i].kategori, &daftar[i].tahun, &daftar[i].nilaipenting);
    }
    qsort(daftar, n, sizeof(Artefak), bandingkan_artefak);
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", daftar[i].nama, daftar[i].kategori, daftar[i].tahun, daftar[i].nilaipenting);
    }
    return 0;
}
