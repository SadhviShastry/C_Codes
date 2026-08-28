#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue {
 int no;
 struct queue *next;   };
struct queue *front = NULL, *rear = NULL;
void insertrear(int val) {
 struct queue *q;
 q = (struct queue *)malloc(sizeof(struct queue));
 q->no = val;
 q->next = NULL;
 if (front == NULL) {
 front = rear = q;
 return;  }
 rear->next = q;
 rear = q;   }
void insertfront(int val) {
 struct queue *q;
 q = (struct queue *)malloc(sizeof(struct queue));
 q->no = val;
 q->next = front;
 if (front == NULL) {
 front = rear = q;
 return;  }
 front = q;   }
int deletefront() {
 int val;
 struct queue *q;
 if (front == NULL) {
 printf("\nQueue is Empty");
 return -999;   }
 q = front;
 val = front->no;
 if (front == rear) {
 front = rear = NULL;
 } else {
 front = front->next;  }
 free(q);
 return val;   }
int deleterear() {
 int val;
 struct queue *q = front;
 if (front == NULL) {
 printf("\nQueue is Empty");
 return -999;  }
 val = rear->no;
 if (front == rear) {
 front = rear = NULL;
 } else {
 while (q->next->next != NULL)
 q = q->next;
 rear = q;
 q = q->next;
 rear->next = NULL;  }
 free(q);
 return val;   }
void show() {
 struct queue *q = front;
 if (front == NULL) {
 printf("\nQueue is Empty");
 return;   }
 while (q != NULL) {
 printf("%d\t", q->no);
 q = q->next;  }  }
void main() {
 int ch, n;
 printf("=====================\n DOUBLE ENDED QUEUE");
 do {
 printf("\n1. Insert in Front");
 printf("\n2. Insert in Rear");
 printf("\n3. Delete from Front");
 printf("\n4. Delete from Rear");
 printf("\n5. Show");
 printf("\n0. Exit");
 printf("\nEnter Your Choice: ");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("\nEnter Number: ");
 scanf("%d", &n);
 insertfront(n);
 break;
 case 2:
 printf("\nEnter Number: ");
 scanf("%d", &n);
 insertrear(n);
 break;
 case 3:
 n = deletefront();
 if (n != -999)
 printf("\n%d deleted", n);
 break;
 case 4:
 n = deleterear();
 if (n != -999)
 printf("\n%d deleted", n);
 break;
 case 5:
 show();
 break;
 case 0:
 break;
 default:
 printf("\nWrong Choice");  }  } while (ch != 0);
 printf("=======================================\n");
}