
#include <iostream>
#include "linklist.h"


using namespace std;


linklist::linklist()
{
	head=NULL;
}

void linklist::insert(int value)
{
    if(head==NULL){
      Node* temp=new Node();
      temp->value=value;
      temp->next=NULL;
      head=temp;
    }

	 else
	 {
    Node* temp=new Node();
	 	temp=head;

		while(temp->next!=NULL)
		{
      temp=temp->next;
	  }
	    Node *n=new Node();
	    n->value=value;
	    n->next=NULL;
	    temp->next=n;
	}
}


int linklist:: LengthIs()
{
    int length=0;

      Node* temp=new Node();
      temp=head;
      while(temp!=NULL)
      {
      length++;
      temp=temp->next;
      }

    return length;

}
