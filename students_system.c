#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001 //ѧ��ϵͳ��������
void sort_id();//ѧ������
void sort_rank();//�ֳܷɼ�����
void sort_chi();//���ĳɼ�����
void sort_math();//��ѧ�ɼ�����
void sort_eng();//Ӣ��ɼ�����
void changestu(int k);//�޸�ѧ����Ϣ
void menu();//�����˵�����
int search_id();//��������ѧ�ź���
int search_name();//����������������
int search();//���������ܺ���


struct Stu {
	long int id;//ѧ��
	char name[20];//ѧ������
	float chi_mark;//���ĳɼ�
	float math_mark;//��ѧ�ɼ�
	float eng_mark;//Ӣ��ɼ�
	float sum;//�ܳɼ�
	float ave;//ƽ����
} stus[N];

int cnt = 0; //��¼����
int choose = 1;//ѡ��

void in_put() { //����ѧ����Ϣ����
	while (1) {
		system("cls");
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%ld", &stus[cnt].id);
		getchar();
		printf("������ѧ����������\n");
		scanf("%s", stus[cnt].name);
		getchar();
		printf("������ѧ�������ĳɼ���\n");
		scanf("%f", &stus[cnt].chi_mark);
		getchar();
		printf("������ѧ������ѧ�ɼ���\n");
		scanf("%f", &stus[cnt].math_mark);
		getchar();
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%f", &stus[cnt].eng_mark);
		getchar();
		stus[cnt].sum = stus[cnt].chi_mark + stus[cnt].math_mark + stus[cnt].eng_mark;
		stus[cnt].ave = (stus[cnt].chi_mark + stus[cnt].math_mark + stus[cnt].eng_mark) / 3;
		++cnt;
		printf("�Ƿ�����������ݣ�(y/n)\n");
		char ch;
		ch=getchar();
		if (ch == 'y') {
			continue;
		}
		else if (ch == 'n') {
			break;
		}
		else {
			printf("������󣬷������˵�\n");
			system("pause");
			break;
		}
	}
	
}

void edit() { //�༭ѧ����Ϣ����
	char choice;
	int biao;
	while (1) {
		system("cls");
		getchar();
		biao=search();
		if(biao!=N){	
		printf("��ȷ����Ҫ�޸ĵ�ѧ���Ƿ�������ʾ(y/n)\n");
				getchar();
				choice = getchar();
				if(choice=='y'){
					changestu(biao);
				}
				else if (choice == 'n') {
					printf("����������ˣ�������\n");
					system("pause");
				}
				else {
					printf("�������,������[y/n]\n");
					system("pause");
					continue;
				}
		}
		else if(biao==N){
			continue;
		}
		system("cls");
		printf("�Ƿ�����޸�����ѧ����Ϣ(y/n):");
		char ch;
		getchar();
		scanf("%c",&ch);
		if (ch == 'y') {
			continue;
		}
		else {
			return;
		}
	}
}

void shan() {////ɾ��ѧ����Ϣ����
	char mych;
	int biao;
	while (1) {
		system("cls");
		getchar();
		biao=search();
		if(biao!=N){
			printf("�Ƿ�ȷ��ɾ��[y/n]\n");
			getchar();
			mych=getchar();
			if (mych=='y')
			{
				for(int i=biao;i<cnt;++i){
					stus[biao]=stus[biao+1];
				}
				printf("ɾ���ɹ���\n");
				--cnt;
				system("pause");
			}
			else if (mych=='n')
				{
				printf("δ�����ɾ������\n");
				system("pause");
			}
			else {
				printf("������������²�ѯ\n");
				system("pause");
				continue;
			} 
		}
		else if(biao==N){
			continue;
		}
		printf("�Ƿ����ɾ��(y/n)\n");
		char ch;
		getchar();
		ch=getchar();
		if (ch == 'y') {
			continue;
		}
		else if (ch == 'n') {
			break;
		}
	}
}

void view() {//����ѧ����Ϣ����
	char mych;
	system("cls");
	printf("�Ƿ����ð��ִܷӸߵ�������˳��[y/n]\n");
	getchar();
	mych=getchar();
	if(mych=='y')
		{
			system("cls");
			printf("ѧ���ɼ�������(�ܷ�����)\n");
			sort_rank();
			printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
			for (int j = 0; j < cnt; ++j) {
			printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
				stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
			}
			system("pause");
		}
	else if(mych=='n')
	{
		sort_id();
		system("cls");
		printf("ѧ���ɼ�������\n");
		printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
		for (int j = 0; j < cnt; ++j) {
			printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
				stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
		}
		system("pause");
	}
	else
		{
			printf("�������������\n");
			system("pause");
			view();
		}
		
}

void high() {//��ѧ����߷ֺ���
	system("cls");
	sort_chi();
	printf("������߷�ѧ����ѧ��:%ld ����:%s ���ĳɼ�:%.2f ��ѧ�ɼ�:%.2f Ӣ��ɼ�:%.2f �ܷ�:%.2f ƽ����:%.2f\n", 
		stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	sort_math();
	printf("��ѧ��߷�ѧ����ѧ��:%ld ����:%s ���ĳɼ�:%.2f ��ѧ�ɼ�:%.2f Ӣ��ɼ�:%.2f �ܷ�:%.2f ƽ����:%.2f\n", 
		stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	sort_eng();
	printf("Ӣ����߷�ѧ����ѧ��:%ld ����:%s ���ĳɼ�:%.2f ��ѧ�ɼ�:%.2f Ӣ��ɼ�:%.2f �ܷ�:%.2f ƽ����:%.2f\n", 
		stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	system("pause");
}

void rank_10() {//�ܷ�ǰʮ����
	system("cls");
	sort_rank();
	printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
	for(int j=0;j<10;++j){
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
			stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
	}
	system("pause");
}

int search() {//�����ܺ���
	int choice;
	int biao;
	while(1){
		system("cls");
		printf("��ѡ����ҷ�ʽ[1.ѧ��/2.����](������1��2����ѡ��)\n");
		scanf("%d",&choice);
		if(choice==1){
			biao=search_id();
			break;
		}
		else if(choice==2){
			biao=search_name();
			break;
		}
		else {
			printf("������������ԣ�[������1��2]\n");
			system("pause");
		}
	}
	return biao;
}

void load() { //��ʼ��ѧ�����ݺ���
	char temp[1000]= {0};
	int j;
	for (j=0; j < 50; ++j) 
	{
		itoa(j+1,temp,10);
		stus[j].id = 10001 + j;
		strcpy(stus[j].name,"ѧ��_");
		strcat(stus[j].name, temp);
		stus[j].chi_mark = j+49;
		stus[j].math_mark = j + 50;
		stus[j].eng_mark = j + 51;
		stus[j].sum = stus[j].chi_mark + stus[j].math_mark + stus[j].eng_mark;
		stus[j].ave = (stus[j].chi_mark + stus[j].math_mark + stus[j].eng_mark) / 3;
		++cnt;
	}
	system("pause");
}

void insert() {//���뺯��
	int biao;
	system("cls");
	sort_id();
	printf("ѧ���ɼ�������\n");
	printf("[ѧ��]\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
	for (int j = 0; j < cnt; ++j) {
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
			stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
	}
	printf("�ɲ��뵽�����[ѧ��]֮ǰ������д[ѧ��]:\n");
	system("pause");
	biao=search_id();
	if(biao!=N){
		for(int i=cnt;i>=biao;--i){
			stus[i+1]=stus[i];
			
		}
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%ld", &stus[biao].id);
		getchar();
		printf("������ѧ����������\n");
		scanf("%s", stus[biao].name);
		getchar();
		printf("������ѧ�������ĳɼ���\n");
		scanf("%f", &stus[biao].chi_mark);
		getchar();
		printf("������ѧ������ѧ�ɼ���\n");
		scanf("%f", &stus[biao].math_mark);
		getchar();
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%f", &stus[biao].eng_mark);
		getchar();
		stus[biao].sum = stus[biao].chi_mark + stus[biao].math_mark + stus[biao].eng_mark;
		stus[biao].ave = (stus[biao].chi_mark + stus[biao].math_mark + stus[biao].eng_mark) / 3;
		printf("����ɹ���\n");
		printf("���������:\n");
		printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
			stus[biao].id, stus[biao].name, stus[biao].chi_mark, stus[biao].math_mark, stus[biao].eng_mark, stus[biao].sum, stus[biao].ave);
		++cnt;
		system("pause");
	}
	else if(biao==N)
		return;
	
}

void faid(){//��������������
	system("cls");
	printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
	for(int i=0;i<cnt;++i){
		if(stus[i].chi_mark<60||stus[i].math_mark<60||stus[i].eng_mark<60){
			printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
			stus[i].id, stus[i].name, stus[i].chi_mark, stus[i].math_mark, stus[i].eng_mark, stus[i].sum, stus[i].ave);	
		}
	}
	printf("����Ϊ�в������Ŀ��ѧ������\n");
	system("pause");
}



int main() {
	do {
		menu();
		scanf("%d", &choose);
		switch (choose) {
			case 1:
				in_put();
				break;
			case 2:
				edit();
				break;
			case 3:
				shan();
				break;
			case 4:
				view();
				break;
			case 5:
				high();
				break;
			case 6:
				rank_10();
				break;
			case 7:
				search();
				break;
			case 8:
				load();//��ʼ��ѧ������
				break;
			case 9:
				insert();
				break;
			case 10:
				faid();
				break;
			case 0:
				break;
			default : {
				printf("������������ԣ�");
				system("pause");
			}
		};
		system("cls");
	} while (choose);
	printf("\ngood bye~");
	return 0;
}

void sort_id() {//ѧ��������
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].id > stus[j + 1].id) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_rank() {//�ܳɼ�������
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].sum < stus[j + 1].sum) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_chi() {//���ĳɼ���������
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].chi_mark < stus[j + 1].chi_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_math() {//��ѧ�ɼ���������
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].math_mark < stus[j + 1].math_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_eng() {//Ӣ��ɼ���������
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].eng_mark < stus[j + 1].eng_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}



void changestu(int k) {//�޸�ѧ���ɼ�����
	int mych;
while(1){
	printf("��ѡ������Ҫ�޸ĵĲ���:\n1.ѧ��\n2.����\n3.���ĳɼ�\n4.��ѧ�ɼ�\n5.Ӣ��ɼ�\n");
	scanf("%d",&mych);
	switch (mych) {
	case 1:
		getchar();
		printf("������ѧ����ѧ�ţ�\n");
		scanf("%ld", &stus[k].id);
		break;
	case 2:
		getchar();
		printf("������ѧ����������\n");
		scanf("%s", stus[k].name);
		break;
	case 3:
		getchar();
		printf("������ѧ�������ĳɼ���\n");
		scanf("%f", &stus[k].chi_mark);
		break;
	case 4:
		getchar();
		printf("������ѧ������ѧ�ɼ���\n");
		scanf("%f", &stus[k].math_mark);
		break;
	case 5:
		getchar();
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%f", &stus[k].eng_mark);
		break;
	default:
		printf("��������밴��Ž���ѡ��\n");
		system("pause");
		break;
	}
	stus[k].sum = stus[k].chi_mark + stus[k].math_mark + stus[k].eng_mark;
	stus[k].ave = (stus[k].chi_mark + stus[k].math_mark + stus[k].eng_mark) / 3;
	printf("�޸ĺ������:\n");
	printf("ѧ��\t\t����\t\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t\tƽ����\n");
	printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
		stus[k].id, stus[k].name, stus[k].chi_mark, stus[k].math_mark, stus[k].eng_mark, stus[k].sum, stus[k].ave);
	printf("�Ƿ�����޸ĸ�ѧ������Ϣ(y/n)\n");
	char mych_1;
	getchar();
	scanf("%c",&mych_1);
	if (mych_1=='y') {
		continue;
	}
	else if (mych_1=='n') {
		return;
	}
	else 
		{
		printf("������󣬽����޸�\n");
		system("pause");
		return;
		}
	}
}

void menu() {//�˵�
	printf("*               ***********\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("********        *********** \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *        *********** \n\n");//logo
	printf(">>**ѧ���ɼ�����ϵͳ**<< \n");
	printf("��ѡ�������һ��ܣ�����0~10���ֽ���ѡ��\n");
	printf("1.ѧ���ɼ�����¼��\n2.ѧ���ɼ������޸�\n3.ѧ���ɼ�����ɾ��\n4.ѧ���ɼ�����\n5.�鿴��ѧ����߷�\n6.�鿴�ܷ�ǰʮ\n7.��ѯѧ����Ϣ\n8.��ʼ��ѧ������\n9.����ѧ����Ϣ\n10.��ѯ����������\n0.�˳�ϵͳ\n");}

int search_id() {//����ѧ�Ź���
	long int f;
	int j;
	system("cls");
	printf("����������Ҫ���ҵ�ѧ��ѧ��\n");
	scanf("%ld", &f);
	for (j = 0; j < cnt; ++j) {
		if (f==stus[j].id) {
			printf("ѧ��:%ld ����:%s ���ĳɼ�:%.2f ��ѧ�ɼ�:%.2f Ӣ��ɼ�:%.2f �ܷ�:%.2f ƽ����:%.2f\n", stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
			system("pause");
			break;
		} 
	}
	if(f!=stus[j].id){
		printf("ѧ�Ų����ڣ�����������\n");
		system("pause");
		return N;
	}
	return j;
}

int search_name() {//������������
	char f[20];
	int j;
	system("cls");
	printf("����������Ҫ���ҵ�ѧ������\n");
	getchar();
	scanf("%s", f);
	for (j = 0; j < cnt; ++j) {
		if (strcmp(f,stus[j].name)==0) {
			printf("ѧ��:%ld ����:%s ���ĳɼ�:%.2f ��ѧ�ɼ�:%.2f Ӣ��ɼ�:%.2f �ܷ�:%.2f ƽ����:%.2f\n", stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
			system("pause");
			break;
		} 
	}
	if(strcmp(f,stus[j].name)!=0){
		printf("���������ڣ�����������\n");
		system("pause");
		return N;
	}
	return j;
}


