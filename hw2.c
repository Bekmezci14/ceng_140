#include<stdio.h>
#include<stdlib.h>

int transform_name(const char *name);

int** initialize_storage(int IA_size, int DA_size, int** DA_sizes);

void print_storage(int** storage, int IA_size, int* DA_sizes);

void insert(int** storage, int IA_size, const char* name, int* DA_sizes);

void insert2(int** storage, int IA_size, int name_code, int* DA_sizes);

void fill_new_storage(int** storage, int IA_size, int** new_storage, int *DA_sizes, int* new_DA_sizes);

void resize_IA(int*** storage, int* IA_size, int DA_size, int** DA_sizes);


int transform_name(const char *name)
{
    /* WRITE YOUR CODE HERE */
    int i;
    int result=0;
    for(i=0;name[i];i++)
    {
        result+=(i+1)*(i+1)*name[i];
    }
    return result;
}

int** initialize_storage(int IA_size, int DA_size, int** DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    int i;
    int **storage;
    storage = (int **)calloc(IA_size, sizeof(int*));
    *DA_sizes = (int *)calloc(IA_size, sizeof(int));
    for (i=0;i<IA_size;i++)
    {
        storage[i]=(int *)calloc(DA_size, sizeof(int));
        (*DA_sizes)[i] = DA_size;
    }
    return storage;
}

void print_storage(int** storage, int IA_size, int* DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    int i;
    int j;
    for (i=0;i<IA_size;i++)
    {
        printf("%d ->", i);
        for (j=0;j<DA_sizes[i];j++)
        {
            printf(" %d", storage[i][j]);
        }
        printf("\n");
    }
}

void insert(int** storage, int IA_size, const char* name, int* DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    int code = transform_name(name);
    int theindex = code%IA_size;
    int i;
    int done=0;
    int first_da_size=DA_sizes[theindex];
    HERE:
    for (i=0;i<DA_sizes[theindex];i++)
    {
        if (storage[theindex][i]==0)
        {
            storage[theindex][i]=code;
            done=1;
            break;
        }
    }
    if (!done)
    {
        DA_sizes[theindex]*=2;
        storage[theindex]=(int *)realloc(storage[theindex], DA_sizes[theindex]*sizeof(int));
        for (i=first_da_size;i<DA_sizes[theindex];i++)
        {
            storage[theindex][i]=0;
        }
        goto HERE;
    }
    
}

void insert2(int** storage, int IA_size, int name_code, int* DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    
    int theindex = name_code%IA_size;
    int i;
    int done=0;
    int first_da_size=DA_sizes[theindex];
    HERE:
    for (i=0;i<DA_sizes[theindex];i++)
    {
        if (storage[theindex][i]==0)
        {
            storage[theindex][i]=name_code;
            done=1;
            break;
        }
    }
    if (!done && name_code!=0)
    {
        DA_sizes[theindex]*=2;
        storage[theindex]=(int *)realloc(storage[theindex], DA_sizes[theindex]*sizeof(int));
        /*if (!storage[theindex]) printf("Haataaaaaaa");*/
        for (i=first_da_size;i<DA_sizes[theindex];i++)
        {
            storage[theindex][i]=0;
        }
        goto HERE;
    }
}

void fill_new_storage(int** storage, int IA_size, int** new_storage, int *DA_sizes, int** new_DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    int i;
    int j;
    int new_size = IA_size*2;
    for (i=0;i<IA_size;i++)
    {
        for (j=0;j<DA_sizes[i];j++)
        insert2(new_storage, new_size, storage[i][j], *new_DA_sizes);
    }
}

void resize_IA(int*** storage, int* IA_size, int DA_size, int** DA_sizes)
{
    /* WRITE YOUR CODE HERE */
    int i;
    int total=0;
    int **yeni_yer;
    int *yeni_sizes;
    for (i=0;i<(*IA_size);i++) total+=(*DA_sizes)[i];
    if (total>=(*IA_size)*DA_size*1.5)
    {
        *IA_size = (*IA_size)*2;
        
        yeni_yer=initialize_storage(*IA_size, DA_size, &yeni_sizes);
        fill_new_storage(*storage, (*IA_size)/2, yeni_yer, *DA_sizes, &yeni_sizes);
        free(*DA_sizes);
        for (i=0;i<(*IA_size)/2;i++) free((*storage)[i]);
        free(*storage);
        *storage = yeni_yer;
        *DA_sizes = yeni_sizes;
        
    }
}

