#pragma once

#include "p5/data/Iterator.t.hpp"
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

namespace p5
{

    template <typename K, typename V>
    class Dict
    {
    public:
        Dict(){};
        Dict(size_t length)
        {
            // Not sure what to do here. Maybe something java HashMap specific
        }
        Dict(const std::vector<std::pair<K, V>> &pairs)
        {
            VectorIterator<std::pair<K, V>>(pairs).forEachRemaining(
                [this](const std::pair<K, V> &p)
                {
                    set(p.first, p.second);
                });
        }
        Dict(const Iterator<typename std::pair<K, V>> &source)
        {
            source.forEachRemaining([this](const std::pair<K, V> &t)
                                    { this->set(t.first, t.second); });
        }
        Dict(const std::vector<K> &k, const std::vector<V> &v)
        {

            for (size_t i = 0; i < k.size(); i++)
            {
                set(k[i], v[i]);
            }
        }
        Dict(const Dict<K, V> &d)
        {
            _map = std::map<K, V>(d._map);
        }
        ~Dict()
        {
            clear();
        }

        // int index(const V& what) const;
        // void setIndex(int index, const K& key, const V& value);

        void clear()
        {
            _map.clear();
        }
        Dict<K, V> copy() const
        {
            return Dict<K, V>(*this);
        }
        std_iterator_wrapper<std::map<K, V>> entryIterator() const
        {
            return std_iterator_wrapper<std::map<K, V>>(_map.begin(), _map.end());
        }
        V get(const K &key) const
        {
            return _map.at(key);
        }
        V get(const K &key, const V &_default) const
        {
            try
            {
                return _map.at(key);
            }
            catch (const std::out_of_range &e)
            {
                return _default;
            }
        }
        bool hasKey(const K &key) const
        {
            try
            {
                get(key);
                return true;
            }
            catch (const std::out_of_range &e)
            {
                return false;
            }
        }
        void print() const
        {
            std::cout << toString() << "\n";
        }
        V remove(const K &key)
        {
            _map.erase(key);
        }
        void set(const K &key, const V &value)
        {
            _map[key] = value;
        }
        int size() const
        {
            return _map.size();
        }
        std::string toJSON() const;
        std::string toString() const
        {
            std::stringstream s;
            s << "{";
            this->entryIterator().forEachRemaining(
                [this, &s](const std::pair<K, V> &p)
                {
                    s << p.first << ": " << p.second << ", ";
                });
            s.seekp(-2, s.cur);
            s << "}";
            return s.str();
        }

        // void save(java.io.File file);
        // void write(java.io.PrintWriter writer);

        // V value(int index) const;
        // std::vector<V> valueVector() const;
        // V *valueArray() const;
        // V *valueArray(const V buffer[]) const;
        // Iterator<V> valueIterator() const;
        // K key(int index) const;
        // V removeIndex(int index);
        // void resize(int length);
        // std::vector<K> keyVector() const;
        // K *keyArray() const;
        // K *keyArray(const K buffer[]) const;
        // Iterator<K> keyIterator() const;
        // void sortKeys();
        // void sortKeysReverse();
        // void sortValues();
        // void sortValuesReverse();
        // void swap(int a, int b);

    private:
        std::map<K, V> _map;
    };
}