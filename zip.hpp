#include "iostream"
// #include <pair>
using namespace std;
#pragma once

namespace itertools{
      template <typename T1, typename T2>
      class zip{
           private:
            T1 one;
            T2 two;

        template <typename V1, typename V2>
        class iterator{
        private:
            V1 firstIterator;
            V2 secondIterator;

        public:
            iterator(V1 first, V2 second): firstIterator(first), secondIterator(second){
                // this->firstIterator=first;
                // this->secondIterator=second;
            }

            iterator<V1,V2>& operator++(){
                 ++this->firstIterator;
                 ++this->secondIterator;
                return  *this;
            }

            std::pair<decltype(*firstIterator),decltype(*secondIterator)> operator*() const{
                return std::pair<decltype(*firstIterator),decltype(*secondIterator)>(*firstIterator,*secondIterator);
            }

            bool operator!=(iterator<V1,V2> const &diff) {
                return (this->firstIterator != (diff.firstIterator)) && (this->secondIterator != (diff.secondIterator));
            }

        };
        public:
        zip (T1 start, T2 end):one(start), two(end){
            // this->one=start;
            // this->two=end;
        }
        
        auto begin() const { 
            return iterator<decltype(this->one.begin()),decltype(this->two.begin())>(this->one.begin(),this->two.begin()); 
            }  
        auto end() const { 
            return iterator<decltype(this->one.end()),decltype(this->two.end())>(this->one.end(),this->two.end()); 
             } 
          
      };
    
}
    template <typename T,typename E>
         ostream& operator<< (ostream& os, const std::pair<T,E>& Pa){
            return (os << Pa.first << ',' << Pa.second) ;
        }
