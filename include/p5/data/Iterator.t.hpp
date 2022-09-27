#pragma once
#include <vector>
#include <functional>
#include <iterator>

namespace p5
{
    template <typename T>
    class Iterator
    {
    public:
        template<typename Functor>
        void forEachRemaining(Functor func)
        {
            while (hasNext())
                func(next());
        }

        virtual bool hasNext() = 0;
        virtual T next() = 0;
        virtual void remove() = 0;
    };

    template <typename T>
    class VectorIterator : public Iterator<T>
    {
    public:
        VectorIterator(const std::vector<T> &source)
        {
            this->_vector = source;
            this->index = 0;
            this->max = source.size();
        }
        ~VectorIterator(){};

        bool hasNext() override
        {
            return index < max;
        }

        T next() override
        {
            T e = _vector[index];
            index++;
            return e;
        }

        void remove() override
        {
            index++;
        }

    private:
        std::vector<T> _vector;
        int index;
        int max;
    };

    template <class _iter_type>
    class std_iterator_wrapper : public Iterator<typename _iter_type::value_type>
    {
    public:

        std_iterator_wrapper(const typename _iter_type::const_iterator& t, const typename _iter_type::const_iterator& end)
        {
            this->_i = t;
            this->_end = end;
        }

        ~std_iterator_wrapper(){};

        bool hasNext() override
        {
            return _i != _end;
        }

        typename _iter_type::value_type next() override
        {
            typename _iter_type::value_type e = *_i;
            remove();
            return e;
        }

        void remove() override
        {
            ++_i;
        }

    private:
        typename _iter_type::const_iterator _i;
        typename _iter_type::const_iterator _end;
    };
}