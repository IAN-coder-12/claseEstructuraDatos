//Ian Hernández Hernández
//A01276755

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <algorithm> 

class Solution {
public:
    int gcd(int a, int b){
        while (b != 0) {
            int residuo = a % b;
            a = b;
            b = residuo;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if(!head || !head->next){
            return head;
        }

        ListNode* nodo_actual = head;
        while(nodo_actual -> next != NULL){
            int gcdValor = gcd(nodo_actual -> val, nodo_actual-> next -> val);
            
            ListNode *nuevo_nodo = new ListNode(gcdValor);
            nuevo_nodo-> next = nodo_actual -> next;
            nodo_actual->next = nuevo_nodo;
            nodo_actual = nuevo_nodo-> next;
        }
    
        return head;
    }
};