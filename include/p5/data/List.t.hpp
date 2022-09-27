#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <functional>

#include <iostream>

#include "p5/data/Dict.t.hpp"
#include "p5/data/Iterator.t.hpp"

#define DEFAULT_LENGTH 10

namespace p5
{

    template <typename T>
    class List
    {
    public:
        List()
        {
            List(DEFAULT_LENGTH);
        }
        List(size_t length)
        {
            this->_list.resize(length);
        }
        List(const std::vector<T> &source)
        {
            for (size_t i = 0; i < source.size(); i++)
            {
                append(source[i]);
            }
        }
        List(Iterator<T> source)
        {
            source.forEachRemaining([this](const T &t)
                                    { this->append(t); });
        }
        List(const List<T> &l)
        {
            List(l.data());
        }

        ~List()
        {
            this->_list.clear();
        }

        VectorIterator<T> iterator() const
        {
            return VectorIterator<T>(data());
        }

        void append(const T &value)
        {
            this->_list.push_back(value);
        }
        void append(const std::vector<T> &values)
        {
            std::function<void(const T &)> f = [this, &values](const T &t)
            { this->append(t); };
            VectorIterator<T>(values).forEachRemaining(f);
        }
        void append(const List<T> &values)
        {
            append(values.data());
        }
        T *array();
        T *array(T array[]);
        void clear()
        {
            this->_list.clear();
        }
        List<T> copy() const
        {
            return List<T>(*this);
        }
        T get(int index) const
        {

            if (index < 0 || index >= size())
            {
                // std::stringstream m;
                // std::string err = (m << "IndexOutOfBounds with index: " << index << ", size" << size()).str();
                throw std::invalid_argument("IndexOutOfBounds");
            }

            return this->_list[index];
        }
        const std::vector<T> data() const
        {
            return this->_list;
        }

        // TODO Dict<T, int> getOrder();

        List<T> getSubset(int start) const
        {
            return getSubset(start, size() - start);
        }
        List<T> getSubset(int start, int len) const
        {
            List<T> l;
            Iterator<T> i = this->iterator();
            for (size_t i = start; i < Math::min(start + len, size()); i++)
            {
                l.append(this->get(i));
            }
            return l;
        }

        Dict<T, int> getTally() const
        {
            Dict<T, int> out;
            iterator().forEachRemaining([this, &out](const T &t)
                                        {
                if(! out.hasKey(t))
                    out.set(t, 0);
                out.set(t, out.get(t)+1); });
            return out;
        }
        List<T> getUnique() const
        {
            List<T> out;
            iterator().forEachRemaining([this, &out](const T &t)
                                        {
                    if (!out.hasValue(t))
                        out.append(t); });
            return out;
        }

        int index(T value) const
        {
            for (size_t i = 0; i < size(); i++)
                if (value == get(i))
                    return i;
            return -1;
        }
        bool hasValue(T value) const
        {
            return index(value) != -1;
        }

        void insert(int index, const T &value)
        {
            _list.insert(_list.begin() + index, value);
        }
        void insert(int index, const std::vector<T> &value)
        {
            std::function<void(const T &)> f = [index, this](T t)
            { this->insert(index, t); };
            // VectorIterator<T>(value).forEachRemaining(f);
        }
        void insert(int index, const List<T> &value)
        {
            std::function<void(const T &)> f = [](T t)
            { ; };
            value.iterator().forEachRemaining(f);
        }

        std::string join(std::string seperator) const
        {
            std::stringstream s;
            for (size_t i = 0; i < size() - 1; i++)
            {
                s << get(i) << seperator;
            }
            s << get(size() - 1);
            return s.str();
        }

        T pop()
        {
            T e = get(size() - 1);
            _list.erase(_list.end() - 1);
        }
        void push(T value)
        {
            append(value);
        }
        void print() const
        {
            std::cout << toString() << "\n";
        }

        int removeValue(T value)
        {
            for (size_t i = 0; i < size(); i++)
            {
                if (value == get(i))
                {
                    _list.erase(_list.begin() + i);
                    return i;
                }
            }
            return -1;
        }
        int removeValues(T value)
        {
            int i = 0;
            for (size_t i = 0; i < size(); i++)
            {
                if (value == get(i))
                {
                    _list.erase(_list.begin() + i);
                    i++;
                }
            }
            return i;
        }
        int replaceValue(T value, T newValue)
        {
            int r = removeValue(value);
            if (r > -1)
            {
                insert(r, newValue);
                return r;
            }
            return -1;
        }
        int replaceValues(T value, T newValue)
        {
            int p, i;
            while ((p = removeValue(value)) > -1)
            {
                insert(p, newValue);
                i++;
            }
            return i;
        }

        void resize(int length)
        {
            this->_list.resize(length);
        }
        void reverse()
        {
            std::reverse(_list.begin(), _list.end());
        }

        // void save(File file);

        void set(int index, T value)
        {
            _list[index] = value;
        }
        void shuffle();

        int size() const
        {
            return this->_list.size();
        }
        void sort()
        {
            std::sort(_list.begin(), _list.end());
        }
        void sortReverse()
        {
            sort();
            reverse();
        }

        std::string toJSON() const;
        std::string toString() const
        {
            std::stringstream out;
            out << "[";
            if (size() > 0)
            {

                size_t i = 0;
                for (; i < this->size() - 1; i++)
                {
                    out << get(i) << ", ";
                }
                out << get(i) << "]";
            }
            return out.str();
        }

        std::vector<T> values() const
        {
            return std::vector<T>(_list);
        }

    private:
        std::vector<T> _list;
    };
}