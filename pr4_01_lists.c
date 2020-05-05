    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct node
    {
    int value;
    struct node *next;
    struct node *prev;
    } node;

    typedef struct list
    {
    struct node *head;
    struct node *tail;
    } list;

    // инициализация пустого списка
    void init(list *l)
    {
    l->head = NULL;
    l->tail = NULL;
    }

    // удалить все элементы из списка
    void clean(list *l)
    {
    if (l->head != NULL)
    {
    node *tmp = NULL;
    while (l->head->next)
    {
    tmp = l->head;
    l->head = l->head->next;
    free(tmp);
    }
    free(l->head);
    l->head = NULL;
    l->tail = NULL;
    tmp = NULL;
    }
    else
    printf("Error");
    }

    // проверка на пустоту списка
    bool is_empty(list *l)
    {
    if (l->head != NULL)
    return false;
    else
    return true;
    }

    // поиск элемента по значению. вернуть NULL если элемент не найден
    node *find(list *l, int value)
    {
    node *tmp = l->head;
    while ((tmp != NULL) && (tmp->value != value))
    tmp = tmp->next;
    if (tmp == NULL)
    {
    printf("0 ");
    return NULL;
    }
    else
    {
    printf("1 ");
    tmp = NULL;
    }
    }

    // вставка значения в конец списка, вернуть 0 если успешно
    int push_back(list *l, int value)
    {
    if (l->head != NULL)
    {
    node *tmp = l->head;
    while (tmp->next != NULL)
    tmp = tmp->next;
    tmp->next = malloc(sizeof(node));
    tmp->next->value = value;
    tmp->next->prev = tmp;
    tmp->next->next = NULL;
    l->tail = tmp->next;
    tmp = NULL;
    return 0;
    }
    else
    {
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = l->head;
    l->head = tmp;
    l->head->prev = NULL;
    l->tail = tmp;
    tmp = NULL;
    return 0;
    }
    }

    // вставка значения в начало списка, вернуть 0 если успешно
    int push_front(list *l, int value)
    {
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = l->head;
    tmp->prev = NULL;
    l->head->prev = tmp;
    l->head = tmp;
    tmp = NULL;
    return 0;
    }

    // вставка значения после указанного узла, вернуть 0 если успешно
    int insert_after(list *l, node *n, int value)
    {
    if (n != NULL)
    {
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = n->next;
    tmp->prev = n;
    if (n->next != NULL)
    n->next->prev = tmp;
    else
    l->tail = tmp;
    n->next = tmp;
    tmp = NULL;
    return 0;
    }
    else
    {
    printf("Error");
    return 2;
    }
    }

    // вставка значения перед указанным узлом, вернуть 0 если успешно
    int insert_before(list *l, node *n, int value)
    {
    if (n != NULL)
    {
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = n;
    tmp->prev = n->prev;
    if (n->prev != NULL)
    n->prev->next = tmp;
    else
    l->head = tmp;
    n->prev = tmp;
    tmp = NULL;
    return 0;
    }
    else
    {
    printf("Error");
    return 2;
    }
    }

    // поиск элемента по индексу
    node *list_index(list *l, int j)
    {
    node *tmp = l->head;
    int index = 0;
    while (index != j - 1 && tmp != NULL)
    {
    tmp = tmp->next;
    ++index;
    }
    return tmp;
    }

    // удалить первый элемент из списка с указанным значением, вернуть 0 если успешно
    int remove_first(list *l, int value)
    {
    if (l->head == NULL)
    return 1;
    else
    {
    node *tmp = l->head;
    while (tmp->next != NULL)
    {
    if (tmp->value == value)
    {
    if (tmp->prev == NULL)
    {
    l->head = tmp->next;
    l->head->prev = NULL;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    tmp = tmp->next;
    }
    if (tmp->value == value)
    {
    l->tail = tmp->prev;
    l->tail->next = NULL;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    return 1;
    }
    }

    // // удалить последний элемент из списка с указанным значением, вернуть 0 если успешно

    int remove_last(list *l, int value)
    {
    if (l->head == NULL)
    return 1;
    else
    {
    node *tmp = l->tail;
    while (tmp->prev != NULL)
    {
    if (tmp->value == value)
    {
    if (tmp->next == NULL)
    {
    l->tail = tmp->prev;
    l->tail->next = NULL;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    tmp = tmp->prev;
    }
    if (tmp->value == value)
    {
    l->head = tmp->next;
    l->head->prev = NULL;
    free(tmp);
    tmp = NULL;
    return 0;
    }
    return 1;
    }
    }

   // вывести все значения из списка в прямом порядке через пробел,
   // после окончания вывода перейти на новую строку
    void print(list *l)
    {
    node *tmp = l->head;
    while (tmp != NULL)
    {
    printf("%d ", tmp->value);
    tmp =
    tmp->next;
    }
    }

  // вывести все значения из списка в обратном порядке через пробел,
  // после окончания вывода перейти на новую строку
    void print_invers(list *l)
    {
    node *tmp = l->tail;
    while (tmp != NULL)
    {
    printf("%d ", tmp->value);
    tmp = tmp->prev;
    }
    }



    int main()
    {
    int n;
    (void)scanf("%d", &n);
    list l;
    init(&l);
    int a; 
    for (int i = 1; i <= n; ++i)
    {
    (void)scanf("%d", &a);
    push_back(&l, a);
    }
    print(&l); //вывод содержимого
    printf("\n");
    for (int k = 1; k <= 3; ++k) // поиск эл-ов по значению
    {
    (void)scanf("%d", &a);
    find(&l, a);
    }
    printf("\n");
    int b; //в конец списка
    (void)scanf("%d", &b);
    push_back(&l, b);
    print_invers(&l); //вывод в обр порядке
    printf("\n");
    int c; // в начало списка
    (void)scanf("%d", &c);
    push_front(&l, c);
    print(&l); // вывод в порядке
    printf("\n");
    int d, e; // добаволения эл-та после указанного узла
    (void)scanf("%d", &d);
    (void)scanf("%d", &e);
    node *usel = list_index(&l, d);
    insert_after(&l, usel, e);
    print_invers(&l); // в обр порядке
    printf("\n");
    int f, g; // добавления перед
    (void)scanf("%d", &f);
    (void)scanf("%d", &g);
    node *xsel = list_index(&l, f);
    insert_before(&l, xsel, g); //  
    print(&l); // вывод содержимого
    printf("\n");
    int h; //удалени 1г эл-та
    (void)scanf("%d", &h);
    remove_first(&l, h);
    print_invers(&l);
    printf("\n");
    int i; // удаление посл
    (void)scanf("%d", &i);
    remove_last(&l, i);
    print(&l); 
    printf("\n");
    clean(&l); // очистка списка
    bool bo = is_empty(&l); // проверка на пустоту
    return 0;
    }


