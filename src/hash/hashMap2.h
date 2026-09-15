//
// Created by francesco on 9/14/26.
//

#ifndef DES_AED_2026_2_HASHMAP2_H
#define DES_AED_2026_2_HASHMAP2_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<typename key_type, typename value_type>
struct my_map {
    int m;
    int _size;
    vector<vector<pair<key_type, value_type>>> chains;

    // Constructor con valor por defecto m = 1
    my_map(int m = 1) : m(m), _size(0) {
        chains.resize(m);
    }

    // Acceso / Inserción por operador []
    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            chains[chain_position].emplace_back(key, value_type());
            ++_size;
        }
        return chains[chain_position][at].second;
    }

    // Eliminación de un elemento por su llave
    void erase(const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        if (at != chains[chain_position].size()) {
            if (at + 1 < chains[chain_position].size()) {
                swap(chains[chain_position][at], chains[chain_position].back());
            }
            chains[chain_position].pop_back();
            --_size;
        }
    }

    // Consulta de existencia de la llave
    bool has_key(const key_type &key) const {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        return at != chains[chain_position].size();
    }

    // Función de hash de enteros por defecto
    int _hash(key_type key) const {
        unsigned int x = static_cast<unsigned int>(key);
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x % m;
    }

    // Retorna el número de elementos guardados en O(1)
    int size() const {
        return _size;
    }

    // Verifica si la estructura está vacía en O(1)
    bool empty() const {
        return _size == 0;
    }

    // Imprime el contenido de cada bucket
    void print() const {
        for (int i = 0; i < m; ++i) {
            cout << "Bucket " << i << ": " << endl;
            for (const auto &e : chains[i]) {
                cout << e.first << " --> " << e.second << endl;
            }
            cout << "End bucket" << endl;
        }
    }
};

#endif //DES_AED_2026_2_HASHMAP2_H
