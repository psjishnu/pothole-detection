#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data,exp;
	struct node *link;
};
struct node *pheader,*qheader,*rheader,*pptr,*qptr,*rptr,*rptr2,*ptr,*header,*new,*new2,*ptr,*prev; 
void add(struct node *pheader,struct node *qheader);
void traversal(struct node *header);
void mul(struct node *pheader,struct node *qheader);
void ins(struct node *header,int n1)

{	int i;
	ptr=header;
	for(i=0;i<n1;i++)
	{
		printf("enter coeff and power of term %d\t",i+1);
		new=(struct node*)malloc(sizeof(struct node));
		scanf("%d %d",&new->data,&new->exp);
		if(ptr==NULL)
		{
			pheader->link=new;
			new->link=NULL;
			ptr=header->link;
		}
		else
		{	ptr->link=new;
			new->link=NULL;
			ptr=ptr->link;
		}
	}
	
}
int main()
{
	int n1,n2,ch;
	pheader=(struct node*)malloc(sizeof(struct node));
	qheader=(struct node*)malloc(sizeof(struct node));
	pptr=pheader->link;
	qptr=qheader->link;
	while(1)
	{
	printf("\nenter choice 1.add  2.multiply\n");
	scanf("%d",&ch);
	if(ch!=1&&ch!=2) printf("enter a valid choice");
	else break;
	} 
	printf("enter no of terms in node1\t");
	scanf("%d",&n1);
	printf("enter details ofll1\n\n");
	ins(pheader,n1);
	printf("enter no of terms in node 2");
	scanf("%d",&n2);
	printf("enter details of ll2\n\n");
	ins(qheader,n2);
	printf("\nread succesfuly\n");
	
	printf("\n");
	if(ch==1) add(pheader,qheader);
	else if(ch==2)mul(pheader,qheader);
}
void add(struct node *pheader,struct node *qheader)
{
	pptr=pheader->link;
	qptr=qheader->link;
	rheader=(struct node*)malloc(sizeof(struct node));
	rptr=rheader;
	while(pptr!=NULL&&qptr!=NULL)
		{
			if(pptr->exp==qptr->exp)
			{	new2=(struct node*)malloc(sizeof(struct node));
				rptr->link=new2;
				rptr=new2;
				rptr->data=pptr->data+qptr->data;
				rptr->exp=pptr->exp;
				rptr->link=NULL;
				pptr=pptr->link;
				qptr=qptr->link;
			}
			else if(pptr->exp>qptr->exp)
			{	new2=(struct node*)malloc(sizeof(struct node));
				rptr->link=new2;
				rptr=new2;
				rptr->data=pptr->data;
				rptr->exp=pptr->exp;
				rptr->link=NULL;
				pptr=pptr->link;
			}
			else
			{	new2=(struct node*)malloc(sizeof(struct node));
				rptr->link=new2;
				rptr=new2;
				rptr->data=qptr->data;
				rptr->exp=qptr->exp;
				rptr->link=NULL;
				qptr=qptr->link;
			}
		}
		if(pptr!=NULL&&qptr==NULL)
			{	while(pptr!=NULL)
				{	new2=(struct node*)malloc(sizeof(struct node));
					rptr->link=new2;
					rptr=new2;
					rptr->data=pptr->data;
					rptr->exp=pptr->exp;
					rptr->link=NULL;
					pptr=pptr->link;
				}
			}
		if(pptr==NULL&&qptr!=NULL)
			{	while(qptr!=NULL)
				{	new2=(struct node*)malloc(sizeof(struct node));
					rptr->link=new2;
					rptr=new2;
					rptr->data=qptr->data;
					rptr->exp=qptr->exp;
					rptr->link=NULL;
					qptr=qptr->link;
				}
			}
		traversal(rheader);

				
			
		
}
void mul(struct node *pheader,struct node *qheader)
{
	pptr=pheader->link;
	qptr=qheader->link;
	rheader=(struct node*)malloc(sizeof(struct node));
	rheader->link=NULL;
	rptr=rheader;
	if(pptr==NULL||qptr==NULL) printf("zero");
	else
		{	while(pptr!=NULL)
			{	qptr=qheader->link;
				while(qptr!=NULL)
				{new=(struct node*)malloc(sizeof(struct node));
				if(rheader->link==NULL)
					{	rptr->link=new;
						rptr=new;
						rptr->data=pptr->data*qptr->data;
						rptr->exp=pptr->exp+qptr->exp;
						rptr->link=NULL;
					}
				else	{	prev=rheader;
						rptr2=rheader->link;
						new->data=pptr->data*qptr->data;
						new->exp=pptr->exp+qptr->exp;
					while(rptr2!=NULL)
						{	if(rptr2->exp<new->exp)
							{	new->link=rptr2;
								prev->link=new;
								break;
							}
							else if(rptr2->exp==new->exp)
							{	rptr2->data+=new->data;
								break;
							}
							else
							{	rptr2=rptr2->link;
								prev=prev->link;
							}
						}
					if(rptr2==NULL)
						{	prev->link=new;
							new->link=NULL;
							rptr=new;
						}
					}
				qptr=qptr->link;
			 }pptr=pptr->link;}
		}
		traversal(rheader);
}						


void traversal(struct node *header)
{
 int count=0;
 ptr=header->link;
 if(ptr!=NULL)
 	{while(ptr!=NULL)
 		{if(ptr->data<0)printf("%d*x^%d",ptr->data,ptr->exp);
 		 else	printf("+%d*X^%d",ptr->data,ptr->exp);
 		ptr=ptr->link;
 		}
 	}
 else printf("empty linked list");
 }	
