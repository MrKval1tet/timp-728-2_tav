    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct node {
    int value;
    struct node* next;
    } node;

    typedef struct list {
    struct node* head;
    struct node* tail;
    } list;

    bool is_empty(list* l);
    bool is_empty(list* l) {
    if (l->head == NULL)
    return 1;
    else
    return 0;
    }

    void init(list* l)
    {
    l->head = NULL;
    l->tail = NULL;
    }

    void clean(list* l) {
    if (is_empty(l)) {
    perror("clean on empty list");
    return;
    }
    node* one = NULL;
    node* two = NULL;
    one = l->head;
    while (one->next != NULL) {
    two = one->next;
    free(one);
    one = two;
    }
    free(one);
    l->head = NULL;
    l->tail = NULL;
    }

    node* find(list* l, int value) {
    node* one = NULL;
    one = l->head;
    while (one != l->tail) {
    if (one->value == value)
    return one;
    one = one->next;
    }
    if (one->value == value)
    return one;
    return NULL;
    }

    int push_back(list* l, int value)
    {
    node* one = malloc(sizeof(node));
    if (one == NULL) {
    perror("error");
    return 1;
    }
    one->value = value;
    one->next = NULL;
    if (is_empty(l)) {
    l->head = one;
    l->tail = l->head;
    }
    else {
    l->tail->next = one;
    l->tail = one;
    }
    return 0;
    }

    int push_front(list* l, int value) {
    node* one = malloc(sizeof(node));
    if (one == NULL) {
    perror("error");
    return 1;
    }
    one->value = value;
    one->next = l->head;
    l->head = one;
    return 0;
    }

    int insert_after(list* l, int index, int value) {
    if (index < 0) {
    perror("index < 1");
    return 1;
    }
    node* one = malloc(sizeof(node));
    if (one == NULL) {
    perror("error");
    return 1;
    }
    one->value = value;
    one->next = NULL;
    if (index == 0) {
    push_front(l, value);
    }
    node* two = NULL;
    two = l->head;
    int i;
    for (i = 1; i < index; ++i) {
    if (two->next == NULL) { //введен индекс больше количества элементов
    return 1;
    }
    two = two->next;
    }
    if (two == l->tail) { //индекс оказался концом списка
    l->tail = one;
    }
    one->next = two->next;
    two->next = one;
    return 0;
    }

    int remove_node(list* l, int value) {
    if (is_empty(l)) {
    return 1;
    }
    node* one = NULL;
    one = l->head;
    if (l->head->value == value) {
    if (l->head->next == NULL) {
    free(l->head);
    l->head = NULL;
    return 0;
    }
    one = l->head->next;
    free(l->head);
    l->head = one;
    return 0;
    }
    node* two = NULL;
    while (one->next != NULL) {
    if (one->next->value == value) {
    if (one->next == l->tail) {
    l->tail = one;
    }
    two = one->next->next;
    free(one->next);
    one->next = two;
    return 0;
    }
    one = one->next;
    }
    return 1;
    }

    void print(list* l) {
    node* one = NULL;
    one = l->head;
    while (one->next != NULL) {
    printf("%d ", one->value);
    one = one->next;
    }
    printf("%d\n", one->value);
    }

    void print(list* l);

    int main() {
    list a;
    init(&a);
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (push_back(&a, x) != 0) {
    printf("failed to push back\n");
    }
    }
    print(&a);
    for (i = 0; i < 3; ++i) {
    scanf("%d", &x);
    if (find(&a, x) != NULL) {
    printf("1 ");
    }
    else {
    printf("0 ");
    }
    }
    printf("\n");
    scanf("%d", &x);
    if (push_back(&a, x) != 0) {
    printf("failed to push back\n");
    }
    print(&a);
    scanf("%d", &x);
    if (push_front(&a, x) != 0) {
    printf("failed to push front\n");
    }
    print(&a);
    scanf("%d%d", &i, &x);
    if (insert_after(&a, i, x) != 0) {
    printf("failed to insert after\n");
    }
    print(&a);
    scanf("%d", &x);
    remove_node(&a, x);
    print(&a);
    clean(&a);
    return 0;
    };


