#pragma once
#include <set> // for set operations

// #include <pair>
using namespace std;
namespace itertools
{
    template <typename T>
    class powerset
    {
        private:
        T one;

        public:

        powerset(T first) : one(first) {

        }
        
        template <typename T2>
        class iterator
        {
            private:
            T2 first;
            T2 second;

            public:
            iterator(T2 iter1, T2 itr2) : first(iter1), second(itr2) {
            }

            set<decltype(*first)> operator*() const {

             return set<decltype(*first)>{};
            
            }

            iterator<T2>& operator++() {

			    return *this;
            }

		    bool operator==(iterator<T2> it) const {
			    return false;
		    }

		    bool operator!=(iterator<T2> it) const {
			    return false;
            }
        };

        public:

        auto begin() const{ 
            return iterator<decltype(one.begin())> (one.begin(), one.end()); 
        } 
        auto end()  const{ 
            return iterator<decltype(one.begin())>(one.end(), one.end());
        } 

    };
}

template<typename T>
ostream& operator<< (ostream& out, const set<T>& the_set) {
    for (auto element: the_set) {
        out << element << ",";
    }
    return out;
}

// template <typename T,typename E>
//     ostream& operator<< (ostream& os, const std::pair<T,E>& Pa){
//     return (os << Pa.first << ',' << Pa.second) ;
// }

