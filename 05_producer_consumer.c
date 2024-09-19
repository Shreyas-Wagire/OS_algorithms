#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,choice,bufferSpace=0;
    printf("Enter the buffer space --> ");
    scanf(" %d",&n);
    int buffer[n];
    printf("Enter your choice --> \n");
    
    do
    {
        printf("1.Create Producer\t2.Create Consumer\t3.EXIT");
    scanf(" %d",&choice);
        switch (choice)
    {
      case 1:
    // statements
        if(bufferSpace==n-1){
            printf("The buffer is full cannot create more producer\n");
            break;
        }
        bufferSpace++;
        printf("Producer created\n");
        break;
    case 2:
    // statements
        if (bufferSpace==0) 
        {
            printf("The buffer is empty cannot create more consumer\n");
            break;
        }   
        bufferSpace--;
        printf("Consumer Created\n");
        break;
    
    case 3:
    printf("Session Terminated\n");
    break;
    
    
      default:
      printf("Invalid Choice");
    }

    }while(choice!=3);
    return 0;
}
