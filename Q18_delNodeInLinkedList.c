#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int m_nValue;
    struct ListNode* m_pNext;
}ListNode;

void deleteNode(ListNode **pListHead, ListNode* pToBeDeleted)
{
    if (*pListHead == NULL || pToBeDeleted==NULL) {
        return;
    }
    
    // 如果待删除节点是头节点，则删除头结点，将头指针指向头结点的下一个节点
    if (pToBeDeleted == *pListHead) {
        ListNode *tmp = *pListHead;
        *pListHead = (*pListHead)->m_pNext;
        tmp->m_pNext = NULL;
        free(tmp);
        return;
    }
    
    // 如果待删除节点是尾节点，则需要遍历
    if (pToBeDeleted->m_pNext == NULL) {
        ListNode* pre = *pListHead;
        while(pre->m_pNext != NULL) {
            if (pre->m_pNext == pToBeDeleted) {
                pre->m_pNext = NULL;
                // free(pToBeDeleted);
                break;
            }
            pre = pre->m_pNext;
        }
        return;
    }
    
    // 不是尾节点，那么将待删除节点的下一个节点的值拷贝到该节点，删除下一个节点，时间复杂度为O(1)
    ListNode *tmp = pToBeDeleted->m_pNext;
    pToBeDeleted->m_nValue = tmp->m_nValue;
    pToBeDeleted->m_pNext = tmp->m_pNext;
    tmp->m_pNext=NULL;
//     free(tmp);
    
    return;
}

int main()
{
    ListNode *head,a1,a2,a3,a4,a5;
    head = (void *) malloc(sizeof(ListNode));
    head->m_nValue = 1;
    head->m_pNext = &a1;
    a1.m_nValue = 2;
    a1.m_pNext = &a2;
    a2.m_nValue = 3;
    a2.m_pNext = &a3;
    a3.m_nValue = 4;
    a3.m_pNext = &a4;
    a4.m_nValue = 5;
    a4.m_pNext = &a5;
    a5.m_nValue = 6;
    a5.m_pNext = NULL;
    
    deleteNode(&head, &a5);
    
    ListNode *h = head;
    while(h!=NULL) {
        printf("%d ", h->m_nValue);
        h=h->m_pNext;
    }
}