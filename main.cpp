#include <iostream>
//Чтобы показать ,что я пишу сам,я буду объяснять что я делаю\
//Очередь рабопатьет по принципу первый зашел,первый вышел,как и в живой очереди
using namespace std;//чтобы не писать каждый раз std
struct element // создание стурктуры элемент
{
    element* q_next = nullptr;// показывает на след элемиент
    int value=3 ;//какаое либо значение
};
struct Queue // структура очередь
{
    element* first;// указатель на первый элемент
    element* last;// указатель на последний элемент
    int count; // счетчик
};
void constructor(Queue& myQueue) // в конструкторе мы просчто все обнуляем
{
    myQueue.first = nullptr;
    myQueue.last = nullptr;
    myQueue.count = 0;
}
void destructor (Queue& myQueue)// деструктор
{
    while (myQueue.first != nullptr)//пока первый элеиент не равен 0
    {
        element* temp = myQueue.first;//присваиваем значение временной переменной
        myQueue.first = myQueue.first -> q_next;
        delete temp;//удаляем ,потому что это 0обязательно для динамического выделения памяти
        myQueue.count --;//уменьшаем на 1
    }
}
void push(Queue& myQueue, element& Velement)// функция заполнения
{
    auto* q = new element;// динамически выделяем память
    q -> value = Velement.value; //обращение к элементу значения
    if (myQueue.first == nullptr)// если первый жлемент равен 0
    {
        myQueue.first = q;//присваиваем значение для первого элемента
        myQueue.last = q;//присваиваем значение для последнего элемента
    } else
    {
        myQueue.last -> q_next = q;// присваваем временной пременной следующее значения
        myQueue.last = q;// присваеваем конец очереди к этой переменной
    }
    myQueue.count ++;// шаг 1(увеличение)

}
int pop(Queue &myQueue)//удаление
{
    element *temp = myQueue.first;// временная переменная
    int znach=myQueue.first->value;
    myQueue.first = myQueue.first -> q_next;//список начинается со второго элемента
    delete temp;// удаляем первый элемент, записанный во временную переменную
    myQueue.count --;// уменьшаем на 1
    return znach;
}
int size(Queue& myQueue)// размер
{
    return myQueue.count;//счетчик
}
void print_elem(element*myQueue )
{
    if (myQueue != nullptr)
    {
        std::cout << myQueue->value << " ";
        print_elem(myQueue->q_next);
    }
}
void print_q(Queue& myQueue)
{
    print_elem(myQueue.first);
    std::cout << std::endl;
}
int main()
{
    Queue VQueue{};
    constructor(VQueue);
    element Element;
    int j;
    int q;
    cout << "Enter how many elements will be: ";
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cout << "enter " << i << " element:";
        cin >> j;
        Element.value = j;
        push(VQueue, Element);
    }
    print_q(VQueue);
    cout << '\n';
    cout << "Size is : " << size(VQueue) << endl;
    cout << "delete the first element: " << VQueue.first -> value << endl;
    pop(VQueue);
    cout << "Now size is : " << size(VQueue) << endl;
    print_q(VQueue);
    cout << "There are " << size(VQueue) <<" elements"<<std::endl;
    destructor(VQueue);
    return 0;
}