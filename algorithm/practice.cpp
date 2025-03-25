#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1e7 + 10;
int a[N];
void setprime(int r);
int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    setprime(r);
    int n = 0;
    while(a[n] < l) {
        n++;
    }
    while(a[n] < r){
        int num[9];
        int temp = a[n];
        int i = 0, j;
        for(int index = 0; temp; index++) {
            num[index] = temp % 10;
            temp /= 10;
            if (!temp) {
                j = index;
            }
        }
        int value = 1;
        while(i < j) {
            if(num[i++] != num[j--]) {
                value = 0;
            }
        }
        if (value) {
            printf("%d\n", a[n]);
        }
        n++;
    }
    return 0;
}

void setprime(int r) {
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    int n = 2;
    for(int i = 7; a[n] < r; i += 2) {
        int j = 0;
        int value = 1;
        while(i > a[j] * a[j] && j <= n) {
            if (!(i % a[j++])) {
                value = 0;
                break;
            }
        }
        if(value) {
            a[n] = i;
        }
        n++;
    }
}