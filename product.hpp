#include "iostream"
using namespace std;

namespace itertools{
      template <typename T1, typename T2>
      class product{
           private:
            T1 one;
            T2 two;

        template <typename V1, typename V2>
        class iterator{
        private:
            V1 firstIterator;
            V2 secondIterator;
             V2 reset;


        public:
            iterator(V1 first, V2 second): firstIterator(first), secondIterator(second),reset(second){
                // this->firstIterator=first;
                // this->secondIterator=second;
            }

            iterator<V1,V2>& operator++(){
                 ++this->secondIterator;
                return  *this;
            }

            pair<decltype(*firstIterator),decltype(*secondIterator)> operator*() const{
                return pair<decltype(*firstIterator),decltype(*secondIterator)>(*firstIterator,*secondIterator);
            }

            bool operator!=(iterator<V1,V2> const &diff) {
                if(firstIterator != (diff.firstIterator) && !(this->secondIterator != (diff.secondIterator))){
                    secondIterator = reset;
                    ++firstIterator;
                }
                return (this->firstIterator != (diff.firstIterator));
            }

             bool operator==(iterator<V1,V2> const &diffrent) const{
                 return this->secondIterator == (diffrent.secondIterator);
             }
        };
        public:
        product (T1 start, T2 end):one(start), two(end){
        }
        
        auto begin() const { 
            return iterator<decltype(this->one.begin()),decltype(this->two.begin())>(this->one.begin(),this->two.begin()); 
            }  
        auto end() const { 
            return iterator<decltype(this->one.end()),decltype(this->two.end())>(this->one.end(),this->two.end()); 
             } 
          
      };
}
