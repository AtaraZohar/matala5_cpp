#include "iostream"
namespace itertools{
      template <typename T1, typename T2>
      class chain{
           private:
            T1 one;
            T2 two;

        template <typename V1, typename V2>
        class iterator{
        private:
            V1 firstIterator;
            V2 secondIterator;
            bool type;

        public:
            iterator(V1 first, V2 second): firstIterator(first), secondIterator(second), type(true){
                // this->firstIterator=first;
                // this->secondIterator=second;
                // this->type=true;
            }

            iterator<V1,V2>& operator++(){
               if(this->type==true){
                 ++this->firstIterator;
                }
                else{
                   ++this->secondIterator;
                }
                return  *this;
            }

            decltype(*firstIterator) operator*() const{
                if(this->type==true){
                return *firstIterator;
                }
                else{
                    return *secondIterator;
                }
            }

            bool operator!=(iterator<V1,V2> const &diff) {
               if(this->type && !(this->firstIterator != (diff.firstIterator))){
                    this->type=false;
               }
               if(this->type==true){
                return this->firstIterator != (diff.firstIterator);
               }
               else{
                   return this->secondIterator != (diff.secondIterator);
               }
            }

        };
        public:
        chain (T1 start, T2 end): one(start), two(end){
        }
        
        auto begin() const { 
            return iterator<decltype(this->one.begin()),decltype(this->two.begin())>(this->one.begin(),this->two.begin()); 
            }  
        auto end() const { 
            return iterator<decltype(this->one.end()),decltype(this->two.end())>(this->one.end(),this->two.end()); 
             } 
          
      };
}