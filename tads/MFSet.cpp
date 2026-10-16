#include <cstdint>

class MFSet{

    private:
    int64_t *parent, n;
    int64_t* alturas;

    public:

    MFSet(int64_t n){
        parent = new int64_t[n+1];
        alturas = new int64_t[n+1];
        this->n=n;
        for(int64_t i=1; i<=n; i++){
            parent[i]=i;
            alturas[i]=1;
        }
    }

    int64_t find(int64_t x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int64_t x, int64_t y){
        int64_t xParent = find(x);
        int64_t yParent = find(y);

        int64_t xAltura = alturas[xParent];
        int64_t yAltura = alturas[yParent];

        if(xAltura > yAltura){
            parent[yParent] = xParent;
        } else if (xAltura < yAltura){
            parent[xParent] = yParent;
        } else {
            parent[yParent] = xParent;
            alturas[xParent]++;
        }
    }
};