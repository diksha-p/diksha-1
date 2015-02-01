#include<stdio.h>
#include <time.h>


void printset(int p,int k, int arr[20000])
{

   FILE * rstFile;
    rstFile = fopen ("rstfile.txt","w");
    rstFile = fopen ("rstfile.txt","a");


    
        

      


    int i,j,r,l,resa[500000],resb[500000],resc[500000],resd[500000],q=0,flag,n=0;
    for(i=1; i<p; i++)
    {

        for(j=1; j<p; j++)
        {
            if(j!=i)
            {

                for(r=1; r<p; r++)
                {
                    if(r!=i && r!=j)
                    {

                        for(l=1; l<p; l++)
                        {
                            if(l!=i && l!=j && l!=r)
                            {

                                if(arr[i]+arr[j]+(arr[r]*arr[l])<=k)
                                {
                                    resa[q]=arr[i];
                                    resb[q]=arr[j];
                                    resc[q]=arr[r];
                                    resd[q]=arr[l];
                                    q++;
                                }

                            } else continue;

                        }
                    } else continue;
                }
            } else continue;
        }
    }

printf("%d",q);
    fprintf(rstFile, "%d,%d,%d,%d\n",resa[0],resb[0],resc[0],resd[0]);
    for(i=1; i<q; i++)
    {   flag=0;
        for(j=0; j<i; j++)
        {
            if(resa[i]==resa[j] && resb[i]==resb[j] && resc[i]==resc[j] && resd[i]==resd[j])
            {   flag=0;
                break;
            } else
                flag=1;
        }
        if(flag==1)
             fprintf(rstFile, "%d,%d,%d,%d\n",resa[i],resb[i],resc[i],resd[i]);
            //printf("%d,%d,%d,%d\n",resa[i],resb[i],resc[i],resd[i]);

    }
}

void main()

{
    clock_t start, end;
    double cpu_time_used;
    int arr[20000],i=0,p,k;
    FILE * optFile;
    start = clock();

    optFile = fopen ("optfile.txt","r");


    while(!feof(optFile))
    {
        fscanf(optFile, "%d," ,&arr[i]);

        i++;
    }

    p=i-1;
    k= arr[0];
    printset(p,k,arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n cpu time = %fs",cpu_time_used);

}
