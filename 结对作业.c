#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int data;
	struct NODE *Next;
}NODE,*ListNODE;
ListNODE create(int lengh)
{
	int i;
    ListNODE Head=(ListNODE)malloc(sizeof(NODE));//创建头结点
    if(Head==NULL)
    {
        printf("ERROR!");
        exit(0);
    }
    Head->Next=NULL;
	Head->data=1;
    ListNODE Tail=Head;//创建始终指向尾结点的指针
    for(i=1;i<lengh;i++)
    {
        ListNODE p=(ListNODE)malloc(sizeof(NODE));
        if(NULL==p)
        {
            printf("ERROR!");
            exit(0);
        }
		p->data=i+1;
        Tail->Next=p;
        p->Next=NULL;
        Tail=p;
    }
	Tail->Next=Head;//尾结点指向首结点形成循环链表
    return Tail->Next;//返回首结点的地址
}
int ReachKing(ListNODE p,int x)
{
	int i,j=0,t;
	for(i=1;p!=p->Next;p=p->Next,i++)
    {
        if(i==x-1)//判断当前节点位置是否是所报数的前一个
        {
            j++;
            ListNODE q=p->Next;
            p->Next=q->Next;//将所在报数位置的节点删除
			printf("第%d个退出选拔猴子王的猴子的编号为：%d\n",j,q->data);
            free(q);
            i=0;
        }
    }
    printf("最终获选的猴子大王编号为：%d\n",p->data);
	t=p->data;
	return t;
}
void Delate(ListNODE p,int u)
{
	int i;
	for(i=1;;p=p->Next,i++)
	{
		if(i==u-1)
		{
			ListNODE q=p->Next;
			p->Next=q->Next;
			free(q);
			break;
		}
	}
}
void ReachQueen(ListNODE p,int m)
{
	int a;
	int i,t,k=0,j=0;
	t=m*2;
	for(i=1;p!=p->Next;p=p->Next,i++)
    {
        if(i==t-1)//判断当前节点位置是否是所报数的前一个
        {
			j++;
            ListNODE q=p->Next;
            p->Next=q->Next;//将所在报数位置的节点删除
			a=q->data;
			printf("第%d个退出选拔猴子王配偶的猴子的编号为：%d\n",j,q->data);
            free(q);
            i=0;
        }
    }
        printf("最终被猴子大王所选配偶的编号为：%d\n",p->data);
}
int main()
{
    int lengh;
    int number;
	int King;
	int a;
    printf("请输入参加选拔猴子的数目:");
    scanf("%d",&lengh);
    printf("请输入报数的大小:");
    scanf("%d",&number);
	if(number==0&&lengh!=0)
	{
		printf("因为报数为0，所以在%d只猴子中无法选出猴王\n",lengh); 
	}
	else if(number==0&&lengh==0)
	{
		printf("无法进行选拔\n");
	}
	else if(number!=0&&lengh==0)
	{
		printf("猴子的数量为0，无法进行选拔\n");
	}
	else if(number==1)
	{
		printf("最终获选的猴子大王编号为：%d\n",lengh);
		printf("                     |---在选拔完猴王后，猴王可以有权力是否选择配偶(选完猴王后需将猴王编号删除)---|\n");
		printf("                     |                          ------同意--------1                               |\n");
		printf("                     |                          ------不同意------2                               | \n");
		printf("(注：配偶选取规则为当选猴王的猴子编号不参与选拔配偶，用猴王所报数的二倍作为选取配偶的所报数进行选拔)\n");
		printf("猴王的意愿为：");
		scanf("%d",&a);
		if(a==1)
		{
		  ListNODE q=NULL;
		  q=create(lengh);
		  Delate(q,lengh);
		  ReachQueen(q,number);
		} 
		if(a==2)
		{
			printf("结束选拔\n");
		}
	}
	else if(number!=0&&lengh!=0)
	{
        ListNODE p=NULL;
        p=create(lengh);
        King=ReachKing(p,number);
		printf("                     |--------------在选拔完猴王后，猴王可以有权力是否选择配偶--------------------|\n");
		printf("                     |                          ------同意--------1                               |\n");
		printf("                     |                          ------不同意------2                               | \n");
		printf("(注：配偶选取规则为当选猴王的猴子编号不参与选拔配偶，用猴王所报数的二倍作为选取配偶的所报数进行选拔)\n");
		printf("猴王的意愿为：");
		scanf("%d",&a);
		if(a==1)
		{
		  ListNODE q=NULL;
		  q=create(lengh);
		  Delate(q,King);
		  ReachQueen(q,number);
		}
		if(a==2)
		{
			printf("结束选拔\n");
		}
	}
	return 0;
}
