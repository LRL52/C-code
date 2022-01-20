#include "lrl52.h"
int a[N];

int findmax(int n){
    int ret = a[1];
    for(int i = 2; i <= n; ++i)
        ret = a[i] > ret ? a[i] : ret;
    return ret;
}