#include<stdio.h>
#include<string.h>

struct book
{
    char name[50],author[50];
    int year;
    double price;
}x[100];
int n,i,j=0,a=0,sum=0,g,flag,num=1;
void read();
void add();
void view();
void search();
void buy();
void del();
int main()
{
    int c;
    while(c!=6)
    {

        printf("**Enter your choice**\n\n1. Add New Book\n2. View Book Information\n3. Search Book\n4. Buy Books\n5. Exit\n\nOption=");
        scanf("%d",&c);
        fflush(stdin);
        if(c==1)
        {
            system("cls");
            add();
        }
        else if(c==2)
        {
            system("cls");
            view();
        }
        else if(c==3)
        {
            system("cls");
            search();
        }
        else if(c==4)
        {
            system("cls");
            buy();
        }
        else if(c==5)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter Book's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter Author = ");
        gets(x[i].author);
        fflush(stdin);
        printf("Enter publish year = ");
        scanf("%d",&x[i].year);
        fflush(stdin);
        printf("Enter price = ");
        scanf("%lf",&x[i].price);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void view()
{
    for(i=1; i<num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("author = ");
        puts(x[i].author);
        printf("Year = %d\n price = %lf\n",x[i].year,x[i].price);
        printf("\n\n");
    }
}
void buy()
{
    int f=1;
    char u[100];
        fflush(stdin);
        printf("Enter book name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
            printf("\n");
            printf("Name = ");
            puts(x[g].name);
            printf("author = ");
            puts(x[g].author);
            printf("publish year = %d\nprice= %lf",x[g].year,x[g].price);
            printf("\n\n");

            int click,q;
    double pricee,change,cP;
    printf("\nWant to buy this book?\n1.Yes\n2.No\n ");
    scanf("%d",&click);
    if(click==1)
    {
        system("cls");
        printf("\nQuantity= ");
        scanf("%d",&q);

            pricee=q*x[g].price;
            printf("plz pay : %lf\n",pricee);
            printf("customer paid= ");
            scanf("%lf",&cP);
            change=cP-pricee;
            printf("Changed= %lf",change);
            coinChange(change);

    }
         f=0;
        }
        if(f==1)
            printf("\nNot Found\n");

}
}
void search()
{
    int s,h,f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Book Name\n3.author name\n4.publish year.\n");
    scanf("%d",&h);
    if(h==1)
    {
        printf("Enter Serial number of the book=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
            puts(x[s].name);
            printf("author = ");
            puts(x[s].author);
            printf("publish year = %d\nprice= %lf",x[s].year,x[s].price);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)
    {
        int f=1;
        fflush(stdin);
        printf("Enter book name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
            printf("\n");
            printf("Name = ");
            puts(x[g].name);
            printf("author = ");
            puts(x[g].author);
            printf("publish year = %d\nprice= %lf",x[g].year,x[g].price);
            printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter author = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].author)==0)
            {
                printf("\n");
                printf("Name = ");
            puts(x[g].name);
            printf("author = ");
            puts(x[g].author);
            printf("publish year = %d\nprice= %lf",x[g].year,x[g].price);
            printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==4)
    {
        int f=1,k;
        printf("Enter Publish year = ");
        scanf("%d",&k);
        for(g=0; g<num; g++)
        {
            if(k==x[g].year)
            {
                printf("\n");
                printf("Name = ");
            puts(x[g].name);
            printf("author = ");
            puts(x[g].author);
            printf("publish year = %d\nprice= %lf",x[g].year,x[g].price);
            printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }

    else
        printf("\n\nInvalid input\n\n");

}
void min_coins(int coin_value[],int n,int amount)
{
  for( int i=0; i< n; i++ )
    while(amount >= coin_value[i])
    {

      amount= amount - coin_value[i];
      printf("%d  ",coin_value[i]);
    }
  printf("\n");
}


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}
void coinChange(double p)
{
    int i,j,n=9;

  int coin_value[]={1,2,5,10,20,50,100,500,1000};

  qsort(coin_value, n, sizeof(int), cmpfunc);
  printf( "\nThe selected currecy values are: \n");
  min_coins(coin_value,n,p);
}
