#include "Subtask2.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
#include<stdio.h>
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�

void Subtask2(){ //���潫�������Ϸ���, ȷ��return��taskid����Ϊ���ʵ�ֵ, 1~Gamecnt��ʾ��Ӧ�ؿ�, -1��ʾ�˳���Ϸ
    puts("Subtask2:"); //��ֻ��һ����ʾ���Զ���, ����ɾ��
    Data[id].taskid = Data[id].taskid > 2 ? Data[id].taskid : 2; //�����û�����߹ؿ���¼
	Switchtask(); //�л��ؿ�, �����˳�ʱ����
}
