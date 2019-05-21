#pragma once
#include <set> 
#include <cmath>
#include <iostream>
#include "zip.hpp"
using namespace std;
namespace itertools
{
    template <typename T>
    class powerset
    {
        private:
        T myPowerSet;

        public:

        powerset(T first) : myPowerSet(first) {

        }
        
        template <typename T2>
        class iterator
        {
            private:
            T2 first_iter;
            T2 second_iter;
            unsigned index;
            unsigned num_of_index;

            typedef
               typename std::remove_const<
               typename std::remove_reference<
               decltype(*first_iter)>::type>::type Element;

            public:
            iterator(T2 iter1, T2 itr2) : first_iter(iter1), second_iter(itr2), index(0), num_of_index(0) {
                T2 start=this->first_iter;
                while(start != second_iter ){
                    ++this->num_of_index;
                    ++start;
                }
                this->num_of_index = std::pow(2, this->num_of_index);
            }

            set<Element> operator*() const {

            T2 _element_iterator = first_iter;
            std::set<Element> mySet;
            unsigned int i = index;
            while (i != 0 && _element_iterator != second_iter)
            { 
                unsigned int r = i % 2;
                i = i >> 1; 

                if (r == 1)
                    mySet.insert(*_element_iterator);

                ++_element_iterator;
            }

                return mySet;            
            }

            iterator<T2>& operator++() {
                this->index++;
			    return *this;
            }

		    bool operator!=(iterator<T2> diff) const {
			    return ((num_of_index - index) != (diff.num_of_index - diff.index - 1));
            }
        };

        public:

        auto begin() const{ 
            return iterator<decltype(myPowerSet.begin())> (myPowerSet.begin(), myPowerSet.end()); 
        } 
        auto end()  const{ 
            return iterator<decltype(myPowerSet.begin())>(myPowerSet.end(), myPowerSet.end());
        } 

    };
}

template <typename D>
std::ostream &operator<<(std::ostream &os, const std::set<D> &S)
{
    os << "{";

    auto it = S.begin();
    if(it != S.end())
    { // first element is without comma seperator.
        os << *it; 
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}
