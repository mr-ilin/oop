int main()
{
    {
        int *ptr = new int{42};
    } // выход за scope - утечка

    {
        int value = 0;
        int *ptr = new int{50};
        // опять потеряли адрес - утечка
        ptr = &value;
    }
    {
        int *ptr = new int{79};
        // Утечка, если функция бросит исключение
        someFunctionHere();
        delete ptr;
    }
}
