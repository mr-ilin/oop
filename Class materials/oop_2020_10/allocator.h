#ifndef MY_ALLOCATOR
#define MY_ALLOCATOR

namespace mai {
    template<class T,size_t BLOCK_SIZE>
    class allocator {
        private:
            T* _buffer;
            size_t _free_index;

        public:
            using value_type = T;
            using pointer = T * ;
            using const_pointer = const T*;
            using size_type = std::size_t;

            allocator() :  _buffer{},_free_index(0) {
                static_assert(BLOCK_SIZE>0);
                
            }

            ~allocator(){
                free(_buffer);
            }

            
            template<typename U>
            struct rebind {
                using other = allocator<U,BLOCK_SIZE>;
            };

            T* allocate(size_t n) {
                if(!_buffer) _buffer = (T*) malloc(sizeof(T)*BLOCK_SIZE);

                if((BLOCK_SIZE-_free_index)<n) throw std::bad_alloc();
                T* pointer = (_buffer+_free_index);
                _free_index+=n;

                return pointer;
            }

            void deallocate(T* ,  size_t ) {
                // тут надо бы удалить память
            }


            template<typename U, typename ...Args>
            void construct(U *p, Args &&...args) {
                new (p) U(std::forward<Args>(args)...);
            }

            void destroy(pointer p) {
                p->~T();
            }

    };
}

#endif

