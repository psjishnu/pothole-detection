#include<stdio.h>
int main()
{ 
  int i,j,a[50][50],m,pp=1,lno=0,ii=0,q=0,aa,cc,v=0,d,b,ba=1,kl,mp,mj,e,me,f=0;
  int xx=1,ja=0,xy=0,mn,mf=1;
  printf("\nENTER ORDER OF MATRIX\n");
  scanf("%d",&m);
  aa=m-1;
  cc=m-1;
  mp=m-1;
  kl=m-1;
  mj=m-1;
  me=m-1;
  mn=m-1;
  
  printf("\nENTER THE MATRIX\n");
  for(i=0;i<m;i++)
  {
   for(j=0;j<m;j++){scanf("%d",&a[i][j]);}
  }
  for(i=0;i<m;i++)
  
  {for(j=0;j<m;j++){printf("%d\t",a[i][j]);}printf("\n");
  }
        printf("\n\n\n");
	lno=(m+(m-1));
 printf("THE NUMBERS PRINTED IN THE GIVEN PATTERN:");
        while(1)
	{
		if(q!=lno)
		{for(j=ja;j<=mp;j++)if(a[ii][j]!='\0'){printf("%d  ",a[ii][j]);}q=q+1;}
		else break;
		

		if(q!=lno)
		{for(b=ba;b<=mj-1;b++)if(a[b][aa]!='\0'){printf("%d  ",a[b][aa]);}q=q+1;}
		else break;
		

		if(q!=lno)
		{for(d=mn;d>=xy;d--)if(a[cc][d]!='\0'){printf("%d  ",a[cc][d]);}q=q+1;}
		else break;
		

		if(q!=lno)
		{for(e=me-1;e>=pp;e--)if(a[e][f]!='\0'){printf("%d  ",a[e][f]);}q=q+1;}
		else break;


    		ii=ii+1;mp=mp-1;ja=ja+1;       //1
		aa=aa-1;ba=ba+1;mj=mj-1;       //2
		mn=mn-1;cc=cc-1;xy=xy+1;       //3
		f=f+1;me=me-1;pp=pp+1;         //4

	}printf("\n");return 0;

}
