#include<iostream>
using namespace std;
class Node {
public:
     int data;
	 Node * next;
	 Node() {
		 data = 0;
		 next = NULL;
	 }
	
	Node( int d) {
		 data = d;
	}
};
class Circular {
 public:
  Node * head;
   Circular() {
       head = NULL;
   }

   void print(){
		Node *ptr=head;
		if(head==NULL){
			cout<<"\nALERT : Linked list is empty!!!!\n";
		}
		else{
			cout<<"\nNODES :   ";
	        do{
	        	cout<<ptr->data<<"->";
	        	ptr=ptr->next;
			}while(ptr->next!=head);
			cout<<ptr->data<<endl;
	    }
	}
	void appendNode(){        //attheend
		int n;
		cout<<"Enter data of node to insert at the end\n";
		cin>>n;
		Node *temp=new Node;
		Node *ptr=head;
		temp->data=n;
		temp->next=head;
		if(head==NULL){
			head=temp;
		}
		else{
			while(ptr->next!=head){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=head;
		}
		cout<<"ALERT : Node appended!!\n";
	}
	void prependNode(){         //atthestart
		int n;
		cout<<"Enter data of node to insert at the start\n";
		cin>>n;
		Node *temp=new Node;
		Node *ptr;
		ptr=head;
		temp->data=n;
		if(head==NULL){
			temp->next=temp;
			head=temp;
		}
		else{
		    while(ptr->next!=head){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=head;
			head=temp;
		
	    }
	    cout<<"ALERT : Node prepended!!\n";
	}
	void insertNodeatpos(){              
		int n=0,pos=0,count=1;
		cout<<"Enter data of node \n";
		cin>>n;
		cout<<"Enter position after which you want to insert node\n";
		cin>>pos;
		Node *temp=new Node;
		Node *prev=head;
		Node *curr=head;
		temp->data=n;
		temp->next=NULL;
		if(head==NULL){
			temp->next=temp;
			head=temp;
		}
		else{
			while(count!=pos){
				count++;
				curr=curr->next;
			}
			temp->next=curr->next;
			curr->next=temp;
		}
	}
	void deleteNode(){
		int pos=0,count=1;
		cout<<"Enter position of the node u want to delete\n";
		cin>>pos;	
		if(head==NULL){
		   cout<<"Link list does not exist\n";
		}
		Node *temp=head;
		if(pos==1){
			while(temp->next!=head){
				temp=temp->next;
			}
			Node * todel=head;
			temp->next=head->next;
			head=head->next;
			delete todel;
		}
		else{
			Node *ptr=head;
			while(ptr!=NULL && count!=pos-1){
				count++;
				ptr=ptr->next;
			}
			Node *todel=ptr->next;
			ptr->next=ptr->next->next;
			delete todel;
		}
		cout<<"ALERT : NODE DELETED SUCCESSFULLY!!\n";
	}
	
};
int main(){
	Circular obj;
	int c;
	cout<<"\n**********************CIRCULAR SINGLY LINKED LIST*********************\n";
	while(1){
	cout<<"Enter your choice\n";
	cout<<"1.Display nodes\n";
	cout<<"2.PrependNode(at the start)\n";
	cout<<"3.AppendNode(at the end)\n";
	cout<<"4.Insert Node at a position\n";
	cout<<"5.Delete Node \n";
	cin>>c;
	switch(c){
		case 1:{
			obj.print();
			break;
		}
		case 2:{
			obj.prependNode();
			break;
		}
		case 3:{
			obj.appendNode();
			break;
		}
		case 4:{
			obj.insertNodeatpos();
			break;
		}	
		case 5:{
			obj.deleteNode();
			break;
		}
    	}
    	cout<<endl;
    }
}
