#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include <ctype.h>
#include<assert.h>


#define MAX 100

#define GOODS_FILE_NAME "goodsinfo.txt"


#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30


typedef struct {
	char    goods_id[MAX_ID_LEN];
	char    goods_name[MAX_NAME_LEN];
	int     goods_price;
	char    goods_discount[MAX_DISCOUNT_LEN];
	int     goods_amount;
	int     goods_remain;
} GoodsInfo;

typedef struct node
{
	GoodsInfo data;
	struct node *next;
} GoodsList;


//ȫ�ֱ������洢��ǰ��Ʒ������
int CurrentCnt;

GoodsInfo read_goods_info();
void init_list(GoodsList **pL);
void destory_list(GoodsList **pL);
void destory_list_and_file(GoodsList **pL);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char* goods_id);
GoodsList* search_item(GoodsList *L, char* goods_id);
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);


int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

/**********************************************************
 * main    
 **********************************************************/
int main(void)
{
    GoodsList *goodsList;
    init_list(&goodsList);
    GoodsInfo item;
    char temp_id[MAX_ID_LEN];
    while (1) {
	int choice;
	printf("������Ʒ����ϵͳ\n");
	printf("********************************************\n");
	printf("1.��ʾ������Ʒ����Ϣ:\n");
	printf("2.�޸�ĳ����Ʒ����Ϣ:\n");
	printf("3.����ĳ����Ʒ����Ϣ:\n");
	printf("4.ɾ��ĳ����Ʒ����Ϣ:\n");
	printf("5.����ĳ����Ʒ����Ϣ:\n");
	printf("6.��Ʒ���̲��˳�ϵͳ:\n");
	printf("7.����Ʒ�۸��������:\n");
	printf("8.(����)ɾ����������:\n");
	printf("����.�����̲��˳�ϵͳ:\n");
	printf("********************************************\n");
	printf("��������ѡ��: ");

	scanf("%d", &choice);
	switch (choice) {
	  case 1:
	  	output_all_items(goodsList);
		 /* �������*/
	  case 2:
		item = read_goods_info();
		printf("����Ҫ�޸ļ�¼�� ID��");
		read_line(temp_id, MAX_ID_LEN);
		change_item(goodsList, temp_id, item);
		 /* �������read_line����*/
		 /* �������change_item����*/
		break;
  	  case 3:
		item = read_goods_info();
		int pos;
		printf("�������ֱ�����Ҫ�������Ʒλ�ã�0.��Ʒ�б�β�� 1.��Ʒ�б�ͷ�� i.��Ʒ�б��м��i��λ��\n");
		scanf("%d", &pos);
		insert_item(goodsList, item, pos);
		 /* �������insert_item����*/
		break;
	  case 4:
		printf("����Ҫɾ����¼�� ID��");
		read_line(temp_id, MAX_ID_LEN);
		delete_item(goodsList, temp_id);
		 /* �������read_line����*/
		 /* �������delete_item����*/
		break;
	  case 5:
		printf("����Ҫɾ����¼�� ID��");
		read_line(temp_id, MAX_ID_LEN);
		search_item(goodsList, temp_id);
		 /* �������read_line����*/
		 /* �������search_item����*/
		break;	
	  case 6:
		 /* �������save_to_file����*/
		 save_to_file(goodsList);
		printf("���Ѿ����̲��˳�������Ʒ����ϵͳ!\n");
		return 0;
	  case 7:
	  	bubble_sort(goodsList);
		 /* �������bubble_sort����*/
		break;
	  case 8:
	  	destory_list_and_file(&goodsList);
		/* �������destory_list_and_file����*/
		printf("���Ѿ�ɾ����Ʒ�ļ������Լ���������!\n");
		break;
	  default:
		/* �������destory_lis����*/
		destory_list(&goodsList);
		printf("���Ѿ��˳�������Ʒ����ϵͳ!\n");
		return 0;
	}
    }
}

/**********************************************************
 * init_list   
 **********************************************************/
void init_list(GoodsList **L) {
    FILE *fp;
    GoodsInfo goodsInfo;
    GoodsList *p, *r;

    (*L) = (GoodsList *)malloc(sizeof(GoodsList));
    r = (*L);
    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL)
    {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
		printf("��ʾ�����ܴ�����Ʒ�ļ�\n");
    }
    else {
        while (!feof(fp))
        {
            fscanf(fp, "%s", goodsInfo.goods_id);
			fscanf(fp, "%s", goodsInfo.goods_name);
			fscanf(fp, "%d", &goodsInfo.goods_price);
			fscanf(fp, "%s", goodsInfo.goods_discount);
			fscanf(fp, "%d", &goodsInfo.goods_amount);
			fscanf(fp, "%d\n", &goodsInfo.goods_remain);
            /* ��дfscanf���goodsInfo�������ֵ�����*/
            p = (GoodsList*)malloc(sizeof(GoodsList));
            if(p == NULL) exit(0);
            assert(p != NULL);
			p->data = goodsInfo;
			p->next = r->next;
			r->next = p;
            /* ���GoodsList�Ĺ���*/
            CurrentCnt++;
        }
        fclose(fp);
    }
    //r->next = NULL;
    printf("��Ʒ�������ļ��ѽ�������%d����Ʒ��¼\n", CurrentCnt);
}


/**********************************************************
 * insert_item  
 **********************************************************/
bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice) {
    GoodsList *temp;
    GoodsList *pre = L, *p = L->next;
    int i;
    if (CurrentCnt >= 100) {
        printf("��Ϣ��������Ҫ��������ɾ��һ��������Ʒ����!\n");
        return false;
    }

    switch (choice) {
        case 0:
                //β�巨��������Ʒ
                /* �������*/		
                return true;
        case 1:
                //ͷ�巨��������Ʒ
                /* �������*/		
               return true;
         default:
                //�м�i��λ�ò�������Ʒ�����磺����3��Ӧ���ڵڶ����ڵ������½ڵ�
	// CurrentCnt ��Ϊ CurrentCnt+1����Ϊ�� CurrentCnt Ϊ2ʱ����������������¼��
	// ��ʱ����3���� choiseΪ 3����ʾ�ڵڶ�����¼��������ݣ��¼�¼��Ϊ��3������
	if (choice <= CurrentCnt+1 && choice > 0) {
	         /* �������*/
	}
	else {
   	         printf("�����λ�ó�����ǰ��Ʒ�б�Χ\n");
                         return false;
	}
        }
}



/**********************************************************
 * delete_item  
 **********************************************************/
bool delete_item(GoodsList *L, char* goods_id) {
     GoodsList *pre = L, *p = L->next;
      /* �������*/
}


/**********************************************************
 * search_item   
 **********************************************************/
GoodsList* search_item(GoodsList *L, char* goods_id) {
    GoodsList *p = L->next;
    /* �������*/
}


/**********************************************************
 * change_item  
 **********************************************************/
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info) {
     GoodsList *p = L->next;
     GoodsList *ptarget = search_item(L, goods_id);
     /* �������*/
}


/**********************************************************
 *output_one_item   
 **********************************************************/
void output_one_item(GoodsList *p){
	/* �������*/
}
/**********************************************************
 * output_all_items   
 **********************************************************/
void output_all_items(GoodsList *L)
{
	/* �������*/
}


/**********************************************************
 * destory_list
 **********************************************************/
void destory_list(GoodsList **L) {
	if (L == NULL || *L == NULL)
		return;
	GoodsList *pre = *L, *p = (*L)->next;
	/* �������*/
}

/**********************************************************
 * destory_list_and_file
 **********************************************************/

void destory_list_and_file(GoodsList **L) {
	 /* ������룺����destory_list*/
	remove(GOODS_FILE_NAME);
}
/**********************************************************
 * save_to_file   
 **********************************************************/
int save_to_file(GoodsList *L) {
    if(L == NULL)
        return 0;
    GoodsList *p = L->next;
    FILE *fp;
    if ((fp = fopen("goodsinfo.txt", "w")) == NULL)
    {
        printf("��ʾ�����ܴ���Ʒ�ļ�\n");
        return 0;
    }
    int save_count = 0;
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->data.goods_id);
       /* ��дfprintf���goodsInfo�������ֵ�����*/
        p = p->next;
        save_count++;
    }
    fclose(fp);
    return save_count;
}


/**********************************************************
 * bubble_sort  
 **********************************************************/
void bubble_sort(GoodsList *L) {
    GoodsList *p;
    GoodsInfo temp;
    int n = CurrentCnt;
    int i, j;
    
    if (L == NULL || L->next == NULL)
        printf("��ǰ������û����Ʒ\n");
    for (j = 1; j < n; ++j) {
        p = L->next;
        for (i = 0; i < n - j; ++i) {
            if (p->data.goods_price > p->next->data.goods_price) {
	/* �������*/
            }
            p = p->next;
        }
    }
}


/**********************************************************
 * read_goods_info  
 **********************************************************/
GoodsInfo read_goods_info(){
	GoodsInfo goodsInfo;
	printf("������Ҫ�������Ʒ��Ϣ��\n");
	printf("��ƷID��");
	 /* �������read_line����*/
	printf("��Ʒ���ƣ�");
	 /* �������read_line����*/
	printf("��Ʒ�۸�");
	scanf("%d",&goodsInfo.goods_price);
	printf("��Ʒ�ۿۣ�");
	 /* �������read_line����*/
	printf("��Ʒ������");
	scanf("%d", &goodsInfo.goods_amount);
	printf("��Ʒʣ�ࣺ");
	scanf("%d", &goodsInfo.goods_remain);
	return goodsInfo;
}



