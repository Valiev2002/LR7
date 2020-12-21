#include <iostream>
using namespace std;
//Стек работает по правилу портфеля,
// чтобы достать самую первую вещь,нужно достать все остальные которые идут до 1
//Вот что я понял,изучая данную тему
//по программе он похож на очередь,только работаем с конца
struct element_stack // cтруктура элемент
{
    element_stack* prev = nullptr; // указатель на предыдущий элемент
    int value=3; // значение
};

struct Stack // структура стек
{
    element_stack* first; // указатель на первый элемент
    element_stack* last;// указатель на последний элемент
    int count; // счетчик
};

void constructor(Stack& stack)// конструктор как в очереди
{
    stack.first = nullptr;
    stack.last= nullptr;
    stack.count= 0;
}

void destructor(Stack& stack)// деструтор
{
    while (stack.last != nullptr)//пока последний элемент не равен 0
    {
        element_stack* tmp;//указатль
        tmp=stack.last;//присваеваем ему значение последнего элемента
        stack.last=stack.last -> prev;//обращаемся к предыдущему жлементу
        delete tmp;//удаляем присвоенное значение
        stack.count --;//уменьшаем счетчик на 1
    }
}

unsigned int size(Stack& stack)//размер(просто показываем счетчик)
{
    return stack.count;
}

void push(Stack& stack, element_stack& element)//вставить
{
    auto* tmp = new element_stack;// динамическое выделение памяти
    tmp -> value = element.value;//обратимся к значению
    if (stack.first == nullptr)//если первый равен 0
    {
        stack.first = tmp;
        stack.last = tmp;
    }
    else//если какой то другой случай
    {
        tmp -> prev =stack.last;// образаемся к предвдущему эдеиенту и делаем его последним
        stack.last = tmp;// присваеваем  конец
    }
    stack.count ++; // уевличиваем на 1
}
element_stack pop(Stack& stack)// удаляем
{
    element_stack  *temp = stack.last;// временная переменная,УДАЛИ
    stack.last = stack.last -> prev;//все как в очереди,только с конца,второй элемент теперь последний
    delete temp;// удаляем
    stack.count --;// уменьшаем счетчик
}

void print(Stack& myStack)// печать
{
    element_stack *temp = myStack.last;//указатель на последний элемент
    while (temp != nullptr)//пока не равен 0
    {
        int element = temp->value;//значение пред элемента
        cout << element << endl;
        temp = temp->prev;// переходим к предыдущему элементу
    }
}

    int main()
    {
        Stack stack{};
        constructor(stack);
        destructor(stack);
        element_stack element;
        int h;
        int c;
        cout << "Enter how many elements will be  = ";//привет
        cin >> c;
        for (int i = 0; i <= c; ++i)//учитывая 0
        {
            cout << "enter " << i<<" : " ;//для пользователя
            cin >> h;
            element.value =h;
            push(stack, element);
        }
        print(stack);
        cout << endl;
        cout << "Size is " << size(stack) << endl;
        cout << "delete last element: " << stack.first->value << endl;
        pop(stack);
        cout << "now size is " << size(stack) << endl;
        print(stack);

        return 0;
    }
