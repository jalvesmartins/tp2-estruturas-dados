#ifndef ITEM_HPP
#define ITEM_HPP

typedef int Key;

typedef int Load;

class Package {
    public:
        Package() : k(-1), l(0) {} 
        Package(Key k, Load l) : k(k), l(l) {}
        ~Package();

        Key getKey();
        Load getLoad();
        Key setKey(Key* new_k);
        Load setLoad(Load* new_l);

    private:
        Key k;
        Load l;
};

#endif