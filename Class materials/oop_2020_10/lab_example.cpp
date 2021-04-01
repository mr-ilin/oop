#include <iostream>
#include <string>
#include <memory>

// Какая-то структура данных
template <class T>
struct MyStruct
{
    T value;
};

// оператор сравнения моих структур, понадобится для моего дерева
template <class T>
bool operator<(const MyStruct<T> &lhv, const MyStruct<T> &rhv)
{
    return lhv.value < rhv.value;
}

// оператор печати структуры в поток
template <class T>
std::ostream &operator<<(std::ostream &os, MyStruct<T> &rhv)
{
    os << rhv.value;
    return os;
}

// "Пустой" аллокатор - просто выделяет память
template <class T>
struct custom_allocator
{
    // типы, которые нужны см http://www.cplusplus.com/reference/memory/allocator_traits/
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    custom_allocator() noexcept {}

    // нам понадобится преобразование типа аллокатора
    template <class U>
    struct rebind
    {
        using other = custom_allocator<U>;
    };

    // выделяем память
    T *allocate(size_t n)
    {
        std::cout << "allocate" << std::endl;
        return  static_cast<T *>(::operator new(n));
    }

    // удаляем память
    void deallocate(T *pointer, size_t)
    {
        std::cout << "deallocate:" << pointer << std::endl;
        ::delete(pointer);
    }

    // обертка для вызова конструктора (просто скопируйте себе)
    template <typename U, typename... Args>
    void construct(U *p, Args &&... args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    // обертка для вызова деструктора
    void destroy(pointer p)
    {
        std::cout << "destroy" << std::endl;
        p->~T();
    }
};

// совсем не сбалансированное дерево
template <class T, class ALLOCATOR>
struct Tree
{
    // структура для хранения узла дерева - ее будем хранить в умном указателе
    struct TreeNode
    {
        // нам понадобится аллокатор для этой структуры, для этого мы его "сделаем" из аллокатора контейнера с помощью rebind
        // обратите внимание, что поскольку мы вызываем шаблон в шаблоне, то компилятору нужна подсказка в виде слова template после имени класса
        using allocator_type = typename ALLOCATOR::template rebind<TreeNode>::other;

        // значение узла
        T value;

        // левая ветвь дерева
        std::shared_ptr<TreeNode> left;

        //правая ветвь дерева
        std::shared_ptr<TreeNode> right;

        TreeNode(const T &v) : value(v){};
        ~TreeNode(){};

        // аллокатор делаем с помощью паттерна проектирования Singleton https://habr.com/ru/post/147373/
        // это поможет, если мы будем хранить в аллокаторе состояние - блок памяти (что нужно по заданию лабораторной работц)
        static allocator_type get_allocator()
        {
            static allocator_type allocator;
            return allocator;
        }

        // поскольку объекты мы будем отдавать на управление shared_ptr, то мы перегрузим оператор new и delete под использование аллокатора
        // в принципе, new можно было и не перегружать, но, это позволяет ни где не упоминать аллокатор в других местах кода
        void *operator new(size_t size)
        {
            return get_allocator().allocate(sizeof(TreeNode));
        }

        void operator delete(void *p)
        {
            get_allocator().destroy((TreeNode*)p);
            get_allocator().deallocate((TreeNode *)p, sizeof(TreeNode));
        }
    };

    // корень дерева
    std::shared_ptr<TreeNode> root;

    // добавляем элемент в дерево
    // дерево тут дано в виде примера, так что сильно к нему не предирайтесь :-)
    void add(const T &value)
    {
        std::shared_ptr<TreeNode> current = std::shared_ptr<TreeNode>(new TreeNode(value));
        if (!root)
            root = current;
        else
        {
            // для рекурсивного прохода по дереву можно создать лямбду
            // сохраняем ее в function, что бы компилятору было понятно как на нее ссылаться из тела самой лямбды
            std::function<void(std::shared_ptr<TreeNode>)> add_to_node = [&](std::shared_ptr<TreeNode> node) {
                if (value < node->value)
                {
                    if (node->left)
                        add_to_node(node->left);
                    else
                        node->left = current;
                }
                else
                {
                    if (node->right)
                        add_to_node(node->right);
                    else
                        node->right = current;
                }
            };

            add_to_node(root);
        }
    }

    //рекурсивный обход дерева с печатью на экран
    //так же делаем с помощью вспомогательной лямбды 
    void print(std::ostream &os)
    {
        std::function<void(std::shared_ptr<TreeNode>, size_t)> print_node = [&](std::shared_ptr<TreeNode> node, size_t offset) {
            for (size_t i = 0; i < offset; ++i)
                os << ' ';
            os << node->value << std::endl;
            ++offset;
            if (node->left)
                print_node(node->left, offset);
            if (node->right)
                print_node(node->right, offset);
        };
        if (root)
            print_node(root, 0);
    }
};

// тестовая программа
auto main() -> int
{
    using val_t = MyStruct<int>;
    Tree<val_t, custom_allocator<val_t>> tree;

    tree.add(val_t{5});
    tree.add(val_t{4});
    tree.add(val_t{6});
    tree.add(val_t{3});
    tree.add(val_t{7});
    tree.add(val_t{2});
    tree.add(val_t{8});
    tree.add(val_t{1});
    tree.add(val_t{9});
    tree.print(std::cout);

    return 1;
}