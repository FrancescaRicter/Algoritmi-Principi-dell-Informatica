#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 9999999999999999
#define max 200000000

struct HeapArray {__int64_t value;
    int index;} HeapArray;

__int64_t Dijkstra(__int64_t matrix[],__int64_t d)
{__int64_t A=0,I=0,paths[d],nodes[d],path,next=0,B=0;
    for(A=0;A<d;A++)
        for(B=0;B<d;B++)
            if(matrix[A*d+B]==0)
                matrix[A*d+B]=inf;
    for(A=0;A<d;A++)
    {paths[A]=matrix[0*d+A];
        nodes[A]=0;
    }
    paths[0]=0;
    nodes[0]=1;
    I=1;
    while(I<d-1)
    {path=inf;
        for(A=0;A<d;A++)
            if(paths[A]<path&&!nodes[A])
            {path=paths[A];
                next=A;
            }
        nodes[next]=1;
        for(A=0;A<d;A++)
            if(!nodes[A])
                if(path+matrix[next*d+A]<paths[A])
                {paths[A]=path+matrix[next*d+A];
                }
        I++;
    }
    B=0;
    for(A=0;A<d;A++)
        if(A!=0)
        {if (paths[A] != inf)
            { B = B + paths[A]; }
            else { B = B + 0; }
        }

    return B;
}

__int64_t MinPath (int d)
{char *vector,*box,*var;
    __int64_t matrix[d*d],Q=0,W=0,R=0,A=0,I=0,B=0;
    vector = malloc(sizeof(char) * d * 10);
    while (Q < d)
    {var = fgets(vector, 10*d, stdin);
        if (var==NULL)
            return 0;
        W = 0;
        B = 0;
        while (vector[W] != '\0' && vector[W] != '\n')
        {R = 0;
            box = malloc(sizeof(char) * 10);
            while (vector[W] != ',' && vector[W] != '\0' && vector[W] != '\n')
            {box[R] = vector[W];
                ++W;
                ++R;
            }
            box[R] = '\0';
            A = 0;
            for (I = 0; box[I] != '\0'; ++I) { A = A * 10 + box[I] - '0'; }
            free(box);
            matrix[Q*d+B] = A;
            ++W;
            ++B;
        }
        ++Q;
    }
    free(vector);
    A=Dijkstra(matrix,d);
    return A;
}

void MaxHeapify(struct HeapArray H[], int position,int dim)
{__int64_t L,R,bigger=position,temp=0;
    L=2*position+1;
    R=2*position+2;
    if (L<=dim && H[L].value>H[bigger].value)
        bigger=L;
    else
        bigger=position;
    if (R<=dim && H[R].value>H[bigger].value)
        bigger=R;
    if (bigger!=position)
    {temp= H[position].value;
        H[position].value=H[bigger].value;
        H[bigger].value=temp;
        temp= H[position].index;
        H[position].index=H[bigger].index;
        H[bigger].index=temp;
        MaxHeapify(H,bigger,dim);
    }
}

void BuildMaxHeap(struct HeapArray H[], int dim)
{int r;
    for (r=dim/2;r>=0;r--)
    {MaxHeapify(H,r,dim);}
}

int main()
{struct HeapArray List[max];
    char *vector,*var,array[15];
    __int64_t d=0,k=0,t=0,a=0,i=0,count=0,equal=0,first=0;
    var=fgets(array, 15, stdin);
    if (var==NULL)
        return 0;
    vector = malloc(10 * sizeof(char));
    while (array[a] != ' ')
    {vector[t] = array[a];
        a++;
        t++;
    }
    for (i = 0; vector[i] != '\0' && vector[i] != '\n'; ++i)
    { d = d * 10 + vector[i] - '0'; }
    a++;
    t = 0;
    while (array[a] != '\0' && array[a] != '\n')
    {vector[t] = array[a];
        a++;
        t++;
    }
    vector[t] = '\0';
    for (i = 0; vector[i] != '\0' && vector[i] != '\n'; ++i)
    { k = k * 10 + vector[i] - '0'; }
    free(vector);
    var=fgets(array, 15, stdin);
    count=0;
    while (var!=NULL)
    {if (array[0] == 'A')
        {i= MinPath(d);
            if (count==0)
            {first=i;
                equal++; }
            if (count+1<k)
            {List[count].value=i;
                List[count].index=count;
                if (i==first && equal==count)
                {equal++;}
            }
            else if (count+1==k)
            {List[count].value=i;
                List[count].index=count;
                if (equal+1==k && first==i)
                {equal++;}
                else
                    BuildMaxHeap(List,k);
            }
            else
            { if (i<List[0].value && i!=List[0].value)
                { List[0].value=i;
                    List[0].index=count;
                    if (equal==count)
                    {BuildMaxHeap(List,k);}
                    else
                        MaxHeapify(List,0,k);}
            }
            count++;
        }

        else if (array[0] == 'T')
        {for (i=0;i<k && i<count;++i)
            {if (i==0)
                {printf("%d",List[i].index);  }
                else
                {printf(" ");
                    printf("%d",List[i].index);}
            }
            printf("\n");
        }
        var=fgets(array, 15, stdin);
        if (var==NULL)
            return 0;
    }
}
