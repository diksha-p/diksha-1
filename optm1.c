#include<stdio.h>


void printset(int p,int k, int arr[20000])
{
    int i,j,r,l,resa[10000],resb[10000],resc[10000],resd[10000],q=0,flag=0;
    for(i=0; i<p; i++)
    {

        for(j=0; j<p; j++)
        {
            if(j!=i)
            {

                for(r=0; r<p; r++)
                {
                    if(r!=i && r!=j)
                    {

                        for(l=0; l<p; l++)
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


    printf("%d,%d,%d,%d\n",resa[0],resb[0],resc[0],resd[0]);
    for(i=1; i<q; i++)
    {
        for(j=0; j<i; j++)
        {
            if(resa[i]!=resa[j] && resb[i]!=resb[j] && resc[i]!=resc[j] && resd[i]!=resd[j])
                flag=1;
        }
        if(flag==1)
            printf("%d,%d,%d,%d\n",resa[i],resb[i],resc[i],resd[i]);

    }




}

void main()

{
    int arr[20000],i=0,p,k;
    FILE * optFile;

    optFile = fopen ("optfile.txt","r");
    printf("enter the value of k ");
    scanf(" %d",&k);


    while(!feof(optFile))
    {
        fscanf(optFile, "%d," ,&arr[i]);

        i++;
    }

    p=i-1;
    
    printset(p,k,arr);

}
