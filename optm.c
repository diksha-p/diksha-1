#include<stdio.h>


void printset(int p,int k, int arr[20000])
{
 int i,j,r,l,resa[10000],resb[10000],resc[10000],resd[10000],a,b,c,d,q;
for(i=0;i<p;i++)
  {

for(j=0;j<p;j++)
  {
if(j!=i)
      {

           for(r=0;r<p;r++)
             {
               if(r!=i && r!=j)
                  {

                    for(l=0;l<p;l++)
                       {
                         if(l!=i && l!=j && l!=r)
                           {
                              a=arr[i];
                              b=arr[j]; 
                              c=arr[r];
                              d=arr[l];

//printf("%d,%d,%d,%d\n",a,b,c,d);


 if(a+b+(c*d)<=k)
{
resa[q]=a;
resb[q]=b;
resc[q]=c;
resd[q]=d;
q++;
}

}else continue;

                        }
                    }else continue;}
       }else continue;}
}


for(i=0;i<q;i++)
printf("%d,%d,%d,%d\n",resa[i],resb[i],resc[i],resd[i]);

}




void main()

{
int arr[20000],i=0,p,k;
FILE * optFile;
 
optFile = fopen ("optfile.txt","r");
printf("enter the value of k");
scanf("%d",&k);


 while(!feof(optFile))       
  {
    fscanf(optFile, "%d," ,&arr[i]);
 
   i++; 
  }
//printf("value of i is %d\n ",i);
p=i-1;
printf("value of p is %d\n ",p);

 for(i=0;i<p;i++)
printf("%d \n",arr[i]);
printf("value of k is= %d \n" ,k);
  
printset(p,k,arr);
 
}
