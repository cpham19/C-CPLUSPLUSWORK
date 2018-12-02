#ifndef MAPENTRY_H
#define MAPENTRY_H

#include <iostream>
using namespace std;

template<class K, class V> class MapEntry {
public:
        MapEntry();
        MapEntry(K key, V value);
        void setKey(K keyIn);
        void setValue(V valueIn);
        K getKey() const;
        V getValue() const;
        bool operator<(const MapEntry<K, V> &r);
        template <class C, class F> friend ostream &operator<<(ostream &output, const MapEntry<C, F> &e);
    private:
        K key;
        V value;
};

template<class K, class V> ostream &operator<<(ostream &output, const MapEntry<K, V> &e) {
    output << "Key: " << e.getKey() << "; Value: " << e.getValue() << endl;
    
    return output;
}

// so that we can't instatiate without key and value
template<class K, class V> MapEntry<K, V>::MapEntry() = default;

template<class K, class V> MapEntry<K, V>::MapEntry(K keyIn, V valueIn) : key(keyIn), value(valueIn) {
}

template<class K, class V> void MapEntry<K, V>::setKey(K keyIn) {
    key = keyIn;
}

template<class K, class V> void MapEntry<K, V>::setValue(V valueIn) {
    value = valueIn;
}

template<class K, class V> K MapEntry<K, V>::getKey() const {
    return key;
}

template<class K, class V> V MapEntry<K, V>::getValue() const {
    return value;
}

template<class K, class V> bool MapEntry<K, V>::operator<(const MapEntry<K, V> &r) {
    return getKey() < r.getKey();
}


#endif


