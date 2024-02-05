//Threaded lab program
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
    int rt;
};

typedef struct node *Node;

Node getnode()
{
    Node x;
    x = (Node)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory");
        exit(0);
    }
    return x;
}

void freenode(Node x)
{
    free(x);
}

Node inorder_successor(Node x)
{
    Node t;
    t = x->rlink;
    if (x->rt == 1)
        return t;
    while (t->llink != NULL)
        t = t->llink;
    return t;
}

void inorder(Node head)
{
    Node t;
    if (head->llink == NULL)
    {
        printf("Tree Empty\n");
        return;
    }

    printf("Inorder traversal of the tree is \n");
    t = head;
    for (;;)
    {
        t = inorder_successor(t);
        if (t == head)
            return;
        printf("%d ", t->info);
    }
}

void insert_left(int item, Node x)
{
    Node t;
    t = getnode();
    t->info = item;
    x->llink = t;
    t->llink = NULL;
    t->rlink = x;
    t->rt = 1;
}

void insert_right(int item, Node x)
{
    Node t, r;
    t = getnode();
    t->info = item;
    r = x->rlink;
    x->rlink = t;
    x->rt = 0;
    t->llink = NULL;
    t->rlink = r;
    t->rt = 1;
}

Node insert(int item, Node head)
{
    int d;
    Node cur;
    if (head->llink == NULL)
    {
        insert_left(item, head);
        return head;
    }

    cur = head->llink;
    for (;;)
    {
        printf("Insert %d towards left or right of %d (for left enter 1): ", item, cur->info);
        scanf("%d", &d);
        printf("\n");
        if (d == 1)
        {
            if (cur->llink == NULL)
            {
                insert_left(item, cur);
                return head;
            }
            else
                cur = cur->llink;
        }
        else
        {
            if (cur->rt == 1)
            {
                insert_right(item, cur);
                return head;
            }
            else
                cur = cur->rlink;
        }
    }
}

int main()
{
    Node head;
    int ch, item;
    head = getnode();
    head->rlink = head;
    head->rt = 0;
    head->llink = NULL;
    for (;;)
    {
        printf("1.Insert\n");
        printf("2.Inorder traversal\n");
        printf("3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            head = insert(item, head);
            break;
        case 2:
            inorder(head);
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
