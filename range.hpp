namespace itertools{

    template <class T>
    class range{
        private:

        T _first;
        T _last;

        class iterator{
            
            public:
            T value;

            iterator(T v){
               this->value=v;
            }

            T operator*() const{
                return this->value;
            }

            iterator& operator++(){
                ++this->value;
                return  *this;
            }  
        
            bool operator!=(iterator const &diff) const{
                return this->value != (diff.value);
            }           
        };
        public:
        range (T start, T end){
            this->_first=start;
            this->_last=end;
        } 
        iterator begin() const { 
            return iterator(_first); }  
        iterator end() const { 
            return iterator(_last); } 
    };
}


