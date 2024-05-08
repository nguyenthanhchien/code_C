/*
 * Node.c
 *
 * Created on   :   May [6-9], 2024
 * Author       :   NTC
 * Topic        :   Node
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node* Next; // Sử dụng từ khóa struct
} Node;

// Hàm khởi tạo danh sách, không cần truyền tham chiếu
Node* init(Node* head)
{
    head = NULL;
    return head;
}

// Hàm tạo một node mới
Node* createNode(int value)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("No memory\n");
    }
    p->value = value;
    p->Next = NULL;
    return p;
}

// Hàm thêm một node vào cuối danh sách
void push_back(Node** array, int value)
{
    Node* p = createNode(value);
    if ((*array) == NULL)
    {
        *array = p;
    }
    else
    {
        Node* nodecurrent = *array;
        while (nodecurrent->Next != NULL)
        {
            nodecurrent = nodecurrent->Next;
        }
        nodecurrent->Next = p;
    }
}
// Hàm thêm một node vào đầu danh sách
void push_front(Node** array, int value)
{
    Node* p = createNode(value);
    p->Next = *array;
    *array = p;
}

void pop_front(Node **head) // xoa node dau tien
{
    if(*head != NULL)
    {
        Node* p = *head;    // tạo 1 Node p gán head 
        *head = p->Next;    // chuyen head sang bien node thứ 2
        p->Next = NULL;     // trỏ next đầu tiên thành Null
        free(p);            //xóa bộ nhớ nó 
    }
    else{
        printf("khong con j de xoa,xoa head \n");
    }
}
// xoa Node sau cung 
void pop_back(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không có gì để xóa\n");
    }
    else
    {
        Node *Prev = NULL;
        Node *Last = *head;
        while (Last->Next != NULL)
        {
            Prev = Last;
            Last = Last->Next;
        }
        // Nếu danh sách chỉ có 1 phần tử
        if (Prev == NULL)
        {
            free(Last);
            *head = NULL; // Đặt head thành NULL vì danh sách rỗng
        }
        else
        {
            Prev->Next = NULL;
            free(Last);
        }
    }
}


int front(Node *head) // lay gia tri cua node dau tien
{
    return head->value;
}
int back(Node *head)// lay gia tri cua node cuoi cung
{
    while(head->Next != NULL)
    {
        head = head->Next;
    }
    return head->value;
}
void insert(Node **head, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    Node* p = createNode(value);        //tao 1 node new
    Node* q = *head;                    // tao bien tam
    int count = 0;
    
    // Duyệt danh sách để tìm vị trí cần chèn
    while (q != NULL && count < pos - 1)
    {
        count++;
        q = q->Next;
    }
    
    if (q != NULL)   // Trong danh sách có vị trí cần chèn
    { 
        p->Next = q->Next;
        q->Next = p;
    }
    else            // check rong hay da chay den cuoi ds
    {
        if (count == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            printf("Vị trí không tồn tại\n");
        }
    }
}



void deletee(Node **head, int pos) // xoa 1 node tai mot vi tri bat ky
{
    Node* Last = *head;
    Node* Pre = NULL;
    int count = 0;
    
    // Duyệt danh sách để tìm vị trí cần xóa
    while (Last != NULL && count != pos)
    {
        Pre = Last;
        Last = Last->Next;
        count++;
    }
    
    // Kiểm tra nếu nút cần xóa được tìm thấy
    if (Last != NULL)
    {
        // Nếu nút cần xóa là nút đầu tiên trong danh sách
        if (Pre == NULL)
        {
            pop_front(head);
        }
        else
        {
            Pre->Next = Last->Next;
            Last->Next = NULL;
            free(Last);
        }
    }
}


int size(Node **head) // lay kich thuoc cua list
{
    Node* p = *head;
    int count=1;
    if(p==NULL){count=0;} // ds co rong
    else{
        while(p->Next!=0)
        {
            count++;
            p = p->Next;
        }
    }
    return count;
}
int get(Node **head, int pos)      // lay value tai vitri Pos 
{
    Node* p = *head;
    int count = 0;
    while(p->Next != NULL && count<pos-1)       // XÉT DS CÓ RONG HAY CUỐI DS K,VỊ TRÍ ĐẾM SAU POS 
    {                                           // POS : 1 2 3 4 5 6            pOS = 3 
        count++;                                // COUNT =2
        p=p->Next;                              //P= ARRAY[2]
    }
    if (p->Next != NULL) //co vi tri get
    {
        return p->value;
    }
    else{
        printf("No Position\n");
        return -1;
    }

}


void clear(Node **head) // Xóa toàn bộ danh sách
{
    while (*head != NULL)
    {
        pop_front(head);
    }
}

bool Empty(Node *head) // Kiểm tra danh sách có rỗng không
{
    return head == NULL;
}
// Hàm xuất danh sách
void outputNode(Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        printf("%d\t", p->value);
        p = p->Next;
    }
    printf("\n");
}
int main()
{
    Node* head = NULL; // Khởi tạo head
    head = init(head); // Gọi hàm init để khởi tạo danh sách
    push_front(&head,1);
    push_front(&head,0);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    outputNode(head);
    // pop_back(&head);
    // outputNode(head);
    // pop_front(&head);
    // outputNode(head);
    // printf("Value head array is : %d\n",front(head));
    // printf("Value Last array is : %d\n",back(head));
    insert(&head,5,4);
    outputNode(head);
    deletee(&head,4);
    outputNode(head);
    // clear(&head);
    // outputNode(head);
    printf("kich thuoc : %d\n",size(&head));
    printf("value in pos : %d\n",get(&head,10));
    return 0;
}
