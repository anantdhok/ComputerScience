#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct process
{   int at, bt, pn, ft;
    struct process *next;
}   *head, *temp, *sptr, *disp;
int i = 1;

void create ()
{   cout<<" Process P"<<i<<" - ";
    struct process *newprocess = (struct process*)malloc(sizeof(struct process));
    cout<<"\n\t Define Arrival Time : ";
    cin>>newprocess->at;
    cout<<"\t Define Burst Time : ";
    cin>>newprocess->bt;
    newprocess->pn = i++;
    newprocess->next = NULL;
    
    if(head == NULL)
    {   head = newprocess;   }
    else
    {   temp = head;
        sptr = head;
	    if(head->at > newprocess->at)
	    {   newprocess->next = head;
	        head = newprocess;
	    }
        else if(head->at < newprocess->at && head->next == NULL)
	    {   head->next = newprocess;   }
        else
        {  	while(temp->next != NULL && newprocess->at > temp->next->at)
	        {  temp = temp->next;  }
            newprocess->next = temp->next;
	        temp->next = newprocess; 
        }
    }
}

struct process *remove (struct process *node)
{   temp = head;
    if(head == node)
    {   head = head->next;
        return head;
    }
    while(temp->next != node)
    {   temp = temp->next;   }
    temp->next = node->next;
    struct process *disp = (struct process*)malloc(sizeof(struct process));
    disp = node;
    free(node);
    return head;
}

int main ()
{   system("cls");
    
    head = NULL;
    char ch = '0';
	while(true)
    {   create();
	    cout<<" Enter 'E' to execute, or continue to add process. ";
	    cin>>ch;
        cout<<endl;
	    if(ch == 'E' || ch == 'e')
	    {   break;  }
    }

    int c = 0, d = 0, t = 0;
    temp = head;
    cout<<" Gantt chart of the processes - \n";
    while(head != NULL)
    {   if(t < temp->at)
	    {   for(c = 0; c < abs(t-c); c++)
	        {   cout<<" _"; 
                t = t + 1;
            }
	    }
	    for(c = 0; c < temp->bt; c++)
	    {   cout<<" P"<<temp->pn;
            t = t + 1;
        }
	    head = remove(temp);
	    sptr = head;
	    temp = head->next;
	    while(temp != NULL)
	    {   if(sptr->bt > temp->bt && t >= temp->at)
	        {   sptr = temp;   }
	        temp = temp->next;
	    }
	    temp = sptr;
    }
    cout<<"\n";
}