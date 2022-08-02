
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int NMAX = 101;
int N;
int a[NMAX], ids[NMAX];

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        read(a[i]);
        --a[i];
    }
    for (int i = 0; i < N; i++) {
        read(ids[i]);
    }
    int b[N];
    for (int i = 0; i < N; i++) {
        b[a[i]] = i;
    }
    for (int s = 0; s < 3; s++) {
        int cpy[N];
        memcpy(cpy, ids, 4 * N);
        for (int i = 0; i < N; i++) {
            ids[b[i]] = cpy[i];
        }
    }
    for (int i = 0; i < N; i++) {
        print(ids[i], '\n');
    }
    return 0;
}
