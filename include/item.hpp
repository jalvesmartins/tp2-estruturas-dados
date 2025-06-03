#ifndef ITEM_HPP
#define ITEM_HPP

typedef int Key;

typedef int Load;

class Item {
    public:
        Item() : k(-1), l(0) {} 
        Item(Key k, Load l) : k(k), l(l) {}
        ~Item();

        Key getKey();
        Load getLoad();
        Key setKey(Key* new_k);
        Load setLoad(Load* new_l);

    private:
        Key k;
        Load l;
};

#endif