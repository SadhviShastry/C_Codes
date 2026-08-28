#include<stdio.h>
#define maxsize 7 
int queue[maxsize];
int front = -1, rear =-1 ;
int isFull(){
    return(rear+1)%maxsize==front;
}
int isEmpty()
{
return front == -1 ;
}
void enqueue(int data)
{
    if(isFull()){
        printf("Queue OVerflow\n");
return ;
    }
 if(front ==-1){
    front=0;
 }
 rear =(rear+1)%maxsize;
 queue[rear]=data;
 printf("Element %d inserted\n",data);
 }

 int dequeue()
 {
    if(isEmpty()){
        printf("Queue Underflow\n");
        return -1;
    }
    int data =queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }else{
        front=(front+1)%maxsize;

    }
    
return data;
 }
 void display()
 {
     if(isEmpty()){
        printf("Queue is empty ");
        return ;
     } 
     printf("Queue Elements :");
     int i = front ;
     while (i!=rear)
     {
        printf("%d",queue[i]);
        i=(i+1)%maxsize;
     }
     printf("%d\n",queue[rear]);
 }
int main (){
printf("--Cicular Queue --\n");
printf("==============================\n");
enqueue(10);
enqueue(20);
enqueue(80);
enqueue(90);
display();
printf("Dequeue element %D\n",dequeue());
display();
return 0 ;
}
