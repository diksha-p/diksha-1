#include<stdio.h>
#include <time.h>


void printset(int p,int k, int arr[20000])
{

    FILE * rstFile;
    rstFile = fopen ("rstfile.txt","w");
    rstFile = fopen ("rstfile.txt","a");








    int i,j,r,l,resa[500000],resb[500000],resc[500000],resd[500000],q=0,flag,m;
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
                                {   if(q==0) {
                                        resa[0]=arr[i];
                                        resb[0]=arr[j];
                                        resc[0]=arr[r];
                                        resd[0]=arr[l];
                                        q++;
                                        fprintf(rstFile, "\"%d,%d,%d,%d\"\n",resa[0],resb[0],resc[0],resd[0]);
                                    }
                                    else
                                    {

                                        for(m=0; m<q; m++)
                                        {   flag=0;


                                            if(arr[i]==resa[m] && arr[j]==resb[m] && arr[r]==resc[m] && arr[l]==resd[m])
                                            {   flag=0;
                                                break;
                                            } else
                                                flag=1;
                                        }
                                        if(flag==1)

                                        {
                                            resa[q]=arr[i];
                                            resb[q]=arr[j];
                                            resc[q]=arr[r];
                                            resd[q]=arr[l];
                                            fprintf(rstFile, "\"%d,%d,%d,%d\"\n",resa[q],resb[q],resc[q],resd[q]);
                                            q++;
                                        }
                                    }
                                }

                            } else continue;

                        }
                    } else continue;
                }
            } else continue;
        }
    }

    printf("%d",q);

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
