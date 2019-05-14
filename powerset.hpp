#pragma once
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

            pair<decltype(*first),decltype(*second)> operator*() const {

             return pair<decltype(*first),decltype(*second)> (*first , *second);
            
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

        auto begin() { 
            return iterator<decltype(one.begin())> (one.begin(), one.end()); 
        } 
        auto end()  { 
            return iterator<decltype(one.begin())>(one.end(), one.end());
        } 

    };
}


