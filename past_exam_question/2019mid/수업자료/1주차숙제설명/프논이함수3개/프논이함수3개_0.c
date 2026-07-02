#논리 1

int isPrime(int n)
{
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
        return 1;
    }
}



#논리 2

int equalArray(int a[], int asize, int b[], int bsize)
{
    if (asize != bsize)
        return 0;
    for (int i = 0; i < asize; i++) {
        if (a[i] != b[i])
            return 0;
        else
            return 1;
    }
}



#논리 3

int search(int a[], int sizeA, int key)
{
    for (int i = 0; i < sizeA; i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}