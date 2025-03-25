#include <stdio.h>


    
    /* TODO: Implement here */
    

char m[126][3]={{'C','C','A'},{'C','G','A'},{'C','A','A'},{'T','A','A'},{'A','A','T'},{'A','G','A'},{'T','G','A'},{'G','G','A'},{'C','T','A'},{'C','T','T'},{'T','T','T'},{'G','C','A'},{'T','T','A'},{'G','T','T'},{'A','C','G'},{'T','A','C'},{'A','C','C'},{'A','A','A'},{'A','T','A'},{'G','T','A'},{'A','T','T'},{'C','C','G'},{'C','G','G'},{'C','A','G'},{'T','A','G'},{'A','A','C'},{'A','G','G'},{'T','G','G'},{'G','G','G'},{'C','T','G'},{'C','T','C'},{'T','T','C'},{'G','C','G'},{'T','T','G'},{'G','T','C'},{'A','C','A'},{'0','0','0'},{'0','0','0'},{'A','A','G'},{'A','T','G'},
{'G','T','G'},{'A','T','C'},{'C','C','T'},{'C','G','T'},{'C','A','T'},{'T','A','T'},{'G','A','A'},{'A','G','T'},{'T','G','T'},{'G','G','T'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'G','C','T'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'A','C','T'},{'C','C','C'},{'C','G','C'},{'C','A','C'},{'0','0','0'},{'G','A','G'},{'A','G','C'},{'T','G','C'},{'G','G','C'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'G','C','C'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},
{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'G','A','T'},{'T','C','A'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'T','C','T'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'G','A','C'},{'T','C','G'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'T','C','C'},{'0','0','0'},{'0','0','0'},{'0','0','0'},
{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'}};

char codon(char array[])
{
    int i;
    for (i=0;i<126;i++)
    {
        if (array[0]==m[i][0] && array[1]==m[i][1] && array[2]==m[i][2]) break;
    }
    switch (i%21)
    {
        case 0: return 'g';
        case 1: return 'a';
        case 2: return 'v';
        case 3: return 'i';
        case 4: return 'l';
        case 5: return 's';
        case 6: return 't';
        case 7: return 'p';
        case 8: return 'd';
        case 9: return 'e';
        case 10: return 'k';
        case 11: return 'r';
        case 12: return 'n';
        case 13: return 'q';
        case 14: return 'c';
        case 15: return 'm';
        case 16: return 'w';
        case 17: return 'f';
        case 18: return 'y';
        case 19: return 'h';
        case 20: return '.'; /*stop kodonuna . dedik.*/
        default: return '0'; /*nolur nolmaz*/
    }
}

int include(int array[], int n)    /*checks for if array includes n*/
{
    int i;
    for (i=0;i<30;i++)
    {
        if (array[i]==n) return 1;
    }
    return 0;
}

int notzero(int array[])        /*returns the index of the first zero*/
{
    int i;
    int result=0;
    for(i=0;i<10;i++)
    {
        if (array[i]!=0)
        {
            ++result;
        }
    }
    return result;
}



int main() {

int i;
int k;
int n;

int l_dna;
int l_protein;

char temp;
char templist[3];
char templist2[3];
char listem[3] = {'0','0','0'};  /*kontrol edilen kodon*/

char dna[3000]={'0'};
char protein[2900];

int flag[3000]={0};
int result[1000]={0};
int result2[100]={0};
int twice[1000]={0}; /*iki kere bastirilcaklar icin.*/




for (i=0;i<=3000;i++)
{
    scanf(" %c ", &temp);
    dna[i]=temp;
    if (temp=='.') break;
}
for (n=0;n<=2900;n++)
{
    scanf(" %c ", &temp);
    protein[n]=temp;
    if (temp=='.') break;                 /*read dna and protein*/
}


templist[0]=dna[i-3];
templist[1]=dna[i-2];
templist[2]=dna[i-1];
if (codon(templist)!='.' || n>1000)       /*checks the stop codon and protein length*/
{
    printf("NONE");
    goto END;
}
l_dna = i+1;
l_protein=n+1;

HERE:



for (i=0,k=0,n=0;i<3000;i+=3)         /*flag listesi = intronlarin indexleri*/
{
    if(dna[i]=='.')  break;
    listem[0] = dna[i];
    listem[1] = dna[i+1];
    listem[2] = dna[i+2];
    if (codon(listem)==protein[k])
    {
        k+=1;
    }
    else
    {
        flag[n]=i;
        ++n;
        i-=2;
    }
}


for (i=0,k=0,n=0;i<1000;i++)                     /*result = intron baslangic bitis indexleri*/
{
    if (flag[i-1]+1!=flag[i] || flag[i]!=flag[i+1]-1)
    {
        result[k]=flag[i];
        ++k;
    }
    if (flag[i-1]+1!=flag[i] && flag[i]!=flag[i+1]-1)
    {
        twice[n]=flag[i];
        ++n;
    }
}

if (notzero(result)==4) goto RESULT_IS_OK;

for (i=1;i<1000;i++)
{
    if (result[i]+4==result[i+1])
    {
        dna[result[i]+1]='x';
        for (k=0;k<1000;k++)
        {
            flag[k]=0;
            result[k]=0;
            twice[k]=0;
        }
        goto HERE;
    }
}


RESULT_IS_OK:



for (i=0,n=0;i<100;i++,n++)             /*result2 = result + twice - {0}*/
{
    if (result[n]!=0)
    {
        result2[i]=result[n];
        if (include(twice, result[n]))
        {
            result2[i+1]=result[n];
            ++i;
        }
    }
}
if(result2[0]==0 || result2[1]==0) {printf("NONE"); goto END;}

if (result2[3]==0 && result2[1]<l_dna-4)
{
    templist[0]=dna[result2[0]-3];
    templist[1]=dna[result2[0]-2];
    templist[2]=dna[result2[0]-1];
    for (i=result2[0]+1;i<result2[1]-2;i++)
    {
        templist2[0]=dna[i];
        templist2[1]=dna[i+1];
        templist2[2]=dna[i+2];
        if (codon(templist)==codon(templist2))
        {
            if (i+3<result2[1]){
            result2[3]=result2[1];
            result2[1]=i-1;
            result2[2]=i+3;
            result2[0]-=3;    
            break;
            }
        }
    }
}



if (result2[3]==0 || result2[4]!=0)
{
    printf("NONE");
    goto END;
}

printf("%d %d %d %d", result2[0], result2[1], result2[2], result2[3]);

END:

return 0;
}