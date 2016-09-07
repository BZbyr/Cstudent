#include<stdio.h>                 //C���Ա�׼�������ͷ�ļ�
#include<stdlib.h>                //�ļ�������Ҫ�õ���ͷ�ļ�
#include<string.h>                // 2

struct data
{
	char id[11];
	char college[21];
	char name[21];
	char phone[20];
	char password[81];
	char email[81];
}teacher[50];   
/*********************************************************/
struct data1
{
	char id[20];
	char college[21];
	char prof[21];
	char name[21];
	char phone[12];
	char password[81];
	char email[81];
	char course1[81];
	char course2[81];
	char course3[81]; 
}student[50];
/*********************************************************/
struct data2
{
	char college[11];
	char id[11];
	char name[81]; 
	char score[5];
	char times[5];
	char nature[21];
	char teacherName[21];
	char teacherID[10]; 
	char term[81];
	char week[21];
	char starT[6];
	char stopT[6]; 
	char classroom[11];
	int stuNum;
	int renshu; 
	char intro[81];
	char messag[81]; 
}lesson [50];
/*********************************************************/
struct data4
{
	char college[11];
	char id[11];
	char name[81]; 
	char score[5];
	char times[5];
	char nature[21];
	char teacherName[21];
	char teacherID[10]; 
	char term[81];
	char week[21];
	char starT[6];
	char stopT[6]; 
	char classroom[11];
	int stuNum;
	int renshu; 
	char intro[81];
	char messag[81]; 
}min;
/*********************************************************/
struct data5
{
	char college[11];
	char id[11];
	char name[81]; 
	char score[5];
	char times[5];
	char nature[21];
	char teacherName[21];
	char teacherID[10]; 
	char term[81];
	char week[21];
	char starT[6];
	char stopT[6]; 
	char classroom[11];
	int stuNum;
	int renshu; 
	char intro[81];
	char messag[81]; 
}temp;
/*********************************************************/
int choose;     //ÿһ�ι���ѡ���õĶ���choose 
int teacherL,studentL;   //
int teacherNum,studentNum,lessonNum; 
char teacherID[20],teacherPassword[81];  
char studentID[20],studentPassword[81]; 
void competence();
/*********************************************************/
void readLessonInformation()
{
	FILE *fp5;
	if((fp5=fopen("�γ�����.txt","r"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(lessonNum=0;!feof(fp5);lessonNum++)
		fscanf(fp5,"%s%s%s%s%s%s%s%s%s%s%s%s%s %d %d %s%s\n",lesson[lessonNum].college,lesson[lessonNum].id,lesson[lessonNum].name,lesson[lessonNum].score,lesson[lessonNum].times,lesson[lessonNum].nature,lesson[lessonNum].teacherName,lesson[lessonNum].teacherID,lesson[lessonNum].term,lesson[lessonNum].week,lesson[lessonNum].starT,lesson[lessonNum].stopT,lesson[lessonNum].classroom,&lesson[lessonNum].stuNum,&lesson[lessonNum].renshu,lesson[lessonNum].intro,lesson[lessonNum].messag);
	fclose(fp5);
}
/*************************************************************/ 
void over()                          //���������Ϻ���
{
	printf("\n\n------�����˳�ѡ�ι���ϵͳ------\n\n");  //������Խ����¼��ʾ 
	exit(0); 
}
/********************************************************/
void readTeacherInformation()
{
	FILE *fp5;
	if((fp5=fopen("��ʦ��Ϣ.txt","r"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(teacherNum=0;!feof(fp5);teacherNum++)
		fscanf(fp5,"%s%s%s%s%s%s\n",teacher[teacherNum].id,teacher[teacherNum].college,teacher[teacherNum].name,teacher[teacherNum].phone,teacher[teacherNum].password,teacher[teacherNum].email);
	fclose(fp5);
}
/*********************************************************/
void readStudentInformation()  //��ȡѧ����Ϣ ���� 
{
	FILE *fp5;
	if((fp5=fopen("ѧ����Ϣ.txt","r"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(studentNum=0;!feof(fp5);studentNum++)
		fscanf(fp5,"%s%s%s%s%s%s%s%s%s%s\n",student[studentNum].id,student[studentNum].college,student[studentNum].prof,student[studentNum].name,student[studentNum].phone,student[studentNum].password,student[studentNum].email,student[studentNum].course1,student[studentNum].course2,student[studentNum].course3);
	fclose(fp5);
}
/*******************************************************/
int teacherRegistration()                    //��֤��ʦ������Ϣ�ĺ���
{
	printf("        ���������Ľ�ʦID :");
	scanf("%s",teacherID);
	int i=0;
	while(strcmp(teacherID,teacher[i].id)!=0)
	{
		i++;
		if(i>teacherNum)
		{
			printf("        �����ID��Ч\n");
        	printf("        ���������� :");
        	scanf("%s",teacherID);
        	i=0;
		}
	}
	printf("        ����������:");
	scanf("%s",teacherPassword);
	while(strcmp(teacherPassword,teacher[i].password)!=0)
	{
		printf("        ������Ч\n");
        printf("        �������������� :");
        scanf("%s",teacherPassword);
	}
	return i;
}
/********************************************************/
void openedAllCourses() //��ѯ�����Ѿ�����Ŀγ�
{
	int i;
	printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
	for(i=0;i<=lessonNum;i++)
	{
		printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	}
	printf("����������ص���ʦ����ѡ�����\n"); 
	system("pause");
} 
/********************************************************/
void teacherFunction();
void studentFunction();
void searchCourseNamet()  //���ݿγ����Ʋ�ѯ ���� 
{
	char courseName[21];
	int  i=0; 
	printf("        ������������ѯ�Ŀγ����� :");
	scanf("%s",courseName);
	while(strcmp(courseName,lesson[i].name)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.��������Ҫ��ѯ�γ�����------------------------------\n");
            printf("------------------2.�ص���ʦ����ѡ�����--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
            { 
	            printf("�����������Ч�����������루1����2��:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch���ѡ��ִ�й���
			 {
                case 1:		  
	            system("cls");//���� 
	            printf("        ��Ҫ��ѯ�Ŀγ̲�����\n");
        	    printf("        ����������γ����� :");
        	    scanf("%s",courseName);
        	    i=0;
	            break; 
                case 2:
	            teacherFunction();   //�ص���ʦ���ܽ��� 
			    break;  
	         }                        
		}
	}
	printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
	printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	printf("����������ص���ʦ����ѡ�����\n"); 
	system("pause");
}
/********************************************************/
void searchStudentNamet()  //����ѧ�����Ʋ�ѯ ���� 
{
	char studentName[21];
	int  i=0; 
    printf("        ������������ѯ��ѧ������ :");
	scanf("%s",studentName);
	while(strcmp(studentName,student[i].name)!=0)
	{
		i++;
		if(i>studentNum)
		{
			printf("------------------1.��������Ҫ��ѯѧ������------------------------------\n");
            printf("------------------2.�ص���ʦ����ѡ�����--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
            { 
	            printf("�����������Ч�����������루1����2��:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch���ѡ��ִ�й���
			 {
                case 1:		  
	            system("cls");//���� 
	            printf("        ��Ҫ��ѯ��ѧ������������\n");
        	    printf("        ����������ѧ������ :");
        	    scanf("%s",studentName);
        	    i=0;
	            break; 
                case 2:
	            teacherFunction();   //�ص���ʦ���ܽ��� 
			    break;  
	         }                        
		}
	}
    printf("ѧ������  ID          ��ѡ�γ�        \n");
	printf("%-10s%-12s%-15s%-15s%-15s\n",student[i].name,student[i].id,student[i].course1,student[i].course2,student[i].course3); 
	printf("����������ص���ʦ����ѡ�����\n"); 
	system("pause");
}
/***********************************************/
void changeCourse()    //���� �޸Ŀγ���Ϣ ���� 
{
	
    FILE *fs;
    int i,determinant,newLimit;
    char newBook[20];
    char newIntro[20];
    char instruct[11];
    printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
    for(i=0;i<lessonNum;i++)
    {
        if(strcmp(teacherID,lesson[i].teacherID)==0) 
        printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    }
    printf("\n���������޸ĵĿγ̱�ţ�");
    scanf("%s",instruct); 
    i=0;
    while(strcmp(instruct,lesson[i].id)!=0 || strcmp(teacherID,lesson[i].teacherID)!=0 )
    {
        i++;
        if(i>lessonNum)
        {
            printf("\n����Ŀγ̱����Ч������������:");
            scanf("%s",instruct);	
        }  	
    }
    if(lesson[i].renshu==0)
        determinant=0;
    else
       determinant=1;
    switch (determinant)
    {
    	case 0:
            if((fs=fopen("�γ�����.txt","w"))==NULL)
            { 
                printf("�ļ���Ч\n");
                exit(1); 
            }	
            printf("\n�ÿγ���δ��ѧ��ѡ����������������������޸�");
            printf("\n1.�̲� 2.�γ̼�� 3.��������");
            printf("\n��ѡ��");
            scanf("%d",&choose);
            while(choose<1||choose>3) 
            { 
	            printf("�����������Ч�����������루1����3��:");
	            scanf("%d",&choose);
            }     
  
            switch(choose)
            {
                case 1:
                    printf("\n�������µĿα���Ϣ:");
                    scanf("%s",newBook);
                    strcpy(lesson[i].messag,newBook);
                    for(i=0;i<lessonNum;i++)
                       fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
                    fclose(fs);	
                    break;
                case 2:
                    printf("\n�������µĿγ̼��:");
                    scanf("%s",newIntro);
                    strcpy(lesson[i].intro,newIntro);
                    for(i=0;i<lessonNum;i++)
                        fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
                    fclose(fs);	
                    break;
                case 3:
                    printf("\n�������µĿγ���������:");
                    scanf("%d",newLimit);
                    while(newLimit!=80 && newLimit!=100)
                    { 
	                    printf("����������Ч�����������루80/100):");
	                    scanf("%d",&newLimit);
                    }     
                    lesson[i].stuNum=newLimit;
                    for(i=0;i<lessonNum;i++)
                        fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
                    fclose(fs);
                    break;	
            }
            break;
        case 1:
            printf("\n����ѧ��ѡ��ÿγ̣��������µ�����������");
            scanf("%d",&newLimit);
            while(newLimit!=80 && newLimit!=100)
            { 
	            printf("����������Ч�����������루80/100):");
	            scanf("%d",&newLimit);
            }    
            lesson[i].stuNum=newLimit;
            if((fs=fopen("�γ�����.txt","w"))==NULL)
            { 
                printf("�ļ���Ч\n");
                exit(1); 
            }
            for(i=0;i<lessonNum;i++)
                fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
            fclose(fs);
            break;
    }
   	printf("����������ص���ʦ����ѡ�����\n"); 
	system("pause");
}	
/********************************************************/
void searchExisted()    //��ѯ�Լ��ѿ���γ̺��� 
{
    int i=0;
    printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
    while(i<=lessonNum)
    {
        if(strcmp(teacherID,lesson[i].teacherID)==0)
        {
            printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
        }
        i++;	
    }
    system("pause");
}

/******************************************************/
void courseCensus()    //���� ͳ���ѿ���γ���Ŀ ���� 
{  
    int sum=0,i=0;
    while(i<=teacherNum)
    {
        if(strcmp(teacherID,lesson[i].teacherID)==0)
        {
            sum++;
        }
        i++;
    }
    printf("���ѿ���Ŀγ���Ϊ%d\n",sum);
    system("pause");	
}
/********************************************************/
void addCourse()            //��ʦ��ӿγ�
{
	int i,num=0;
	for(i=0;i<lessonNum;i++)
	{
		if(strcmp(lesson[i].teacherName,teacher[teacherL].name)==0)
			num++;
	}
	if(num>=2)   //ͬһ����ʦһ��ѧ�����ֻ�ܿ�����ѡ�޿�
	{
		printf("�㿪��Ŀγ�����");
		printf("����������ص���ʦ����ѡ�����\n"); 
	    system("pause");
		teacherFunction(); 
	}
	strcpy(temp.id,teacher[teacherL].id);
	strcpy(temp.name,teacher[teacherL].name);
	printf("��ʼ��ӿγ�");
	printf("\n����γ�����:");
	scanf("%s",temp.name);
	system("cls");
	printf("\n����γ�ID:");
	scanf("%s",temp.id);
	system("cls");
	printf("\n�����Ͽ���Ŀ:");
	scanf("%s",temp.week);
	system("cls");
	printf("\n1. 08:00--09:50");
	printf("\n2. 10:00--11:50");
	printf("\n3. 13:30--15:20");
	printf("\n4. 15:30--17:20");
	printf("\n5. 18:30--20:20");
	printf("\nѡ���Ͽ�ʱ��:");
	scanf("%d",&choose);
    while(choose<1||choose>5)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        strcpy(temp.starT,"08:00");
			strcpy(temp.stopT,"09:50"); 
	        break;
		case 2:  
	        strcpy(temp.starT,"10:00");
			strcpy(temp.stopT,"11:50"); 
			break;
		case 3:  
	        strcpy(temp.starT,"13:30");
			strcpy(temp.stopT,"15:20"); 
			break;    
		case 4:  
	        strcpy(temp.starT,"15:30");
			strcpy(temp.stopT,"17:20"); 
			break;
		case 5:  
	        strcpy(temp.starT,"18:30");
			strcpy(temp.stopT,"20:20"); 
			break;
    }     
    system("cls");
	printf("\n���뿪��ѧԺ:");
	scanf("%s",temp.college);
	system("cls");
	printf("\n1. ����");
	printf("\n2. ѡ��"); 
	printf("\nѡ��γ�����:");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        strcpy(temp.nature,"����"); 
	        break;
		case 2:
		    strcpy(temp.nature,"ѡ��");
			break;
    }
    system("cls");
	printf("\n����γ�ѧ��:");
	scanf("%s",temp.score);
	system("cls");
	printf("\n����γ̿�ʱ:");
	scanf("%s",temp.times);
	system("cls");
	printf("\n1. 80");
	printf("\n2. 100\n"); 
	printf("\nѡ�񿪿�����(80/100):");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        temp.stuNum=80; 
	        break;
		case 2:
		    temp.stuNum=100;
			break;
    }
    system("cls");
	printf("\n����γ̽���:");
	scanf("%s",temp.intro);
	system("cls");
	printf("\n����γ���Ϣ:");
	scanf("%s",temp.messag);
	system("cls");
	printf("\n1. 2014-2015ѧ��ڶ�ѧ��4-16��");
	printf("\n2. 2015-2016ѧ���һѧ��4-16��"); 
	printf("\nѡ��γ̿���ѧ��:");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        strcpy(temp.term,"2014-2015ѧ��ڶ�ѧ��4-16��"); 
	        break;
		case 2:
		    strcpy(temp.term,"2015-2016ѧ���һѧ��4-16��");
			break;
    }
    system("cls");
	printf("�����Ͽν���:");
	scanf("%s",temp.classroom);
	temp.renshu=0; 
	
	for(i=0;i<lessonNum;i++)   //ͨ�� for �� if ���ж�ͬһ����ʦ���Ͽ�ʱ�䲻�ܳ�ͻ 
	{
		if(strcmp(lesson[i].name,temp.name)==0)   //�γ������γ̺Ų����ظ�
		{
			printf("�γ����Ƴ�ͻ");
			printf("��������γ�����:");
	        scanf("%s",temp.name);
		}
		if(strcmp(lesson[i].id,temp.id)==0)
		{
			printf("�γ�ID��ͻ");
			printf("��������γ�ID:");
	        scanf("%s",temp.id);
		}
		if(strcmp(lesson[i].teacherName,temp.teacherName)==0)    //  �Լ����Ͽ�ʱ�䲻�ܳ�ͻ 
		{
			if(strcmp(lesson[i].week,temp.week)==0)
			{
				if(strcmp(lesson[i].starT,temp.starT)==0)
				{
					printf("�ÿγ̸��Լ��Ͽ�ʱ���ͻ");
			        printf("\n���������Ͽ���Ŀ:");
	                scanf("%s",temp.name);
	                printf("\n���������Ͽο�ʼʱ��:");
	                scanf("%s",temp.name);
				} 
	        }
		}
		if(strcmp(lesson[i].week,temp.week)==0)    //�ͱ��˵��Ͽ�ʱ��ص���Ҳ��ܳ�ͻ 
		{
			if(strcmp(lesson[i].starT,temp.starT)==0)
			{
				if(strcmp(lesson[i].classroom,temp.classroom)==0)
				{
					printf("�ÿγ̸������Ͽ�ʱ��ص��ͻ");
			        printf("\n���������Ͽ���Ŀ:");
	                scanf("%s",temp.name);
	                printf("\n���������Ͽο�ʼʱ��:");
	                scanf("%s",temp.name);
	                printf("\n���������Ͽν���:");
	                scanf("%s",temp.classroom);
				} 
			} 
		}
	}
	FILE *fp5;
	if((fp5=fopen("�γ�����.txt","a"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",temp.college,temp.id,temp.name,temp.score,temp.times,temp.nature,teacher[teacherL].name,teacher[teacherL].id,temp.term,temp.week,temp.starT,temp.stopT,temp.classroom,temp.stuNum,temp.renshu,temp.intro,temp.messag);
	fclose(fp5);
	system("cls");
	printf("�ɹ���ӿγ�");
	system("pause");
} 
/********************************************************/
void deleteCourse()    //  ��ʦɾ���γ�  ���� 
{
    FILE *fs;
    int i,deletedLine;
    char instruct[11]; 
    printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
    for(i=0;i<lessonNum;i++)
    {
        if(lesson[i].renshu<30 && strcmp(teacherID,lesson[i].teacherID)==0) 
        printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    }
    printf("��������ɾ���γ̵ı�ţ�");
    scanf("%s",instruct);
    i=0;
    while(strcmp(instruct,lesson[i].id)!=0 || strcmp(teacherID,lesson[i].teacherID)!=0 || lesson[i].renshu>30)
    {
        i++;
        if(i>lessonNum)
        {
            printf("����Ŀγ̱����Ч������������:");
            scanf("%s",instruct);	
        }	
    }
   deletedLine=i;
   if((fs=fopen("�γ�����.txt","w"))==NULL)
   { 
        printf("�ļ���Ч\n");
        exit(1); 
   }
   for(i=0;i<lessonNum;i++)
   {
   	    if(i!=deletedLine)
   	        fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
   }
   fclose(fs);
   system("cls");
   printf("ɾ����ϡ�1.����ɾ���γ� 2.���ؽ�ʦ������");
   printf("\n��ѡ��");
   scanf("%d",&choose);
   while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
   { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
   }   
   switch(choose) 
   {
   	    case 1:
   	        system("cls");	
   	        readLessonInformation();
   	        deleteCourse();
	        break;
	    case 2:
	        system("cls");	
	        teacherFunction();
            break;  	
   }
}
/********************************************************/
void changeTeacher();
void changeEmailT()    // ����Email���� 
{
	int i;
	char email[81];
	printf("�����µ�����:");
	scanf("%s",email);
	strcpy(teacher[teacherL].email,email);	
	FILE *fs;
    if((fs=fopen("��ʦ��Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<teacherNum;i++)
    {
   	    fprintf(fs,"%9s%10s%8s%13s%8s%30s\n",teacher[i].id,teacher[i].college,teacher[i].name,teacher[i].phone,teacher[i].password,teacher[i].email);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.�����޸ĸ�����Ϣ -------------------------\n");
    printf("-------- 2.�ص���ʦ����ѡ����� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeTeacher();      //���ø��Ľ�ʦ����  
	        break;
		case 2:
	        system("cls");      //����  
	        teacherFunction();     //�ص���ʦ����ѡ�� 
			break;  
    }     
}
void changePasswordT()
{
	char password[81];
	int i;
	printf("�����µ�����:");
	scanf("%s",password);
	strcpy(teacher[teacherL].password,password);
	
	FILE *fs;
    if((fs=fopen("��ʦ��Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<teacherNum;i++)
    {
   	    fprintf(fs,"%9s%10s%8s%13s%8s%30s\n",teacher[i].id,teacher[i].college,teacher[i].name,teacher[i].phone,teacher[i].password,teacher[i].email);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.�����޸ĸ�����Ϣ -------------------------\n");
    printf("-------- 2.�ص���ʦ����ѡ����� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeTeacher();      //���ø��Ľ�ʦ����  
	        break;
		case 2:
	        system("cls");      //����  
	        teacherFunction();     //�ص���ʦ����ѡ�� 
			break;
    }   
}
void changeTeacher()           //��ʦ������Ϣ���� ���� 
{
	printf("-------------------------------------------------\n");
    printf("-------- 1.�޸ĸ������� -------------------------\n");
    printf("-------- 2.�޸ĸ������� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeEmailT();      //���ø���Email����  
	        break;
		case 2:
	        system("cls");      //���� 
	        changePasswordT(); //����  ���ݿγ����Ʋ�ѯ ���� 
			break;
    }      
}
/********************************************************/
void orderNumber();
void teacherFunction()    //��ʦ����ѡ����
{
	readTeacherInformation();    //��ȡ�ļ���Ľ�ʦ��Ϣ
	readStudentInformation();    //��ȡ�ļ��е�ѧ����Ϣ    
	readLessonInformation();     //��ȡ�ļ���Ŀγ���Ϣ 
	system("cls");                         //����   
    printf("-------------------------------------------------\n");
    printf("-------- 1.��ѯ�ѿ�����Ŀγ� -------------------\n");
    printf("-------- 2.��ѯ�γ�ѧ����Ϣ ---------------------\n");
    printf("---------3.ͳ�ƿ�����Ŀγ���Ŀ------------------\n");
    printf("---------4.��ѡ�������������п�����Ŀγ�--------\n");
    printf("---------5.��ѯ�����Ѿ�����Ŀγ�----------------\n");
    printf("---------6.���ݿγ�����ѯ------------------------\n");
    printf("---------7.�޸Ŀγ�------------------------------\n");
    printf("---------8.��ӿγ�------------------------------\n");
    printf("---------9.ɾ���γ�------------------------------\n");
    printf("---------10.������Ϣ����-------------------------\n");
    printf("---------11.�˳���Ȩ��ѡ�����-------------------\n");
	printf("---------12.�˳�������---------------------------\n");
	printf("-------------------------------------------------\n");
    printf("Choose the function��"); 
    scanf("%d",&choose);
    while(choose<1||choose>12)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����12��:");
	    scanf("%d",&choose);
    }     
    switch(choose)//switch���ѡ��ִ�й���
    {
    	case 1:
            system("cls");
			searchExisted();   //���ò�ѯ�Լ��ѿ���γ̺��� 
			teacherFunction();
			break;
		case 2:
		    system("cls");
			searchStudentNamet(); //���� ��ѯѧ������ ���� 
			teacherFunction();
			break;
	    case 3:
		    system("cls");
			courseCensus();   //���� ͳ���ѿ���γ���Ŀ ���� 
			teacherFunction(); 
			break;
    	case 4:
	        system("cls");         //���� 
	        orderNumber();         //���� ����ѡ�������������пγ� ���� 
	        teacherFunction();     //�ص�ѧ������ѡ�� 
	        break;
		case 5:		  
	        system("cls");      //���� 
	        openedAllCourses();    //���� ��ѯ���п�����Ŀγ�  ���� 
	        teacherFunction();     //�ص���ʦ����ѡ�� 
	        break;
		case 6:
	        system("cls");         //���� 
	        searchCourseNamet();   //����  ���ݿγ����Ʋ�ѯ ���� 
	        teacherFunction();     //�ص���ʦ����ѡ�� 
			break;
		case 7:
		    system("cls");
			changeCourse();   //���� �޸Ŀγ���Ϣ ���� 
			teacherFunction(); 
		case 8:
	        system("cls");       //���� 
	        addCourse();         //����  ��ӿγ� ���� 
	        teacherFunction();   //�ص���ʦ����ѡ�� 
			break;
		case 9:
            system("cls");
            deleteCourse();     //���� ɾ���γ�  ���� 
            teacherFunction();
            break;	
        case 10:
	        system("cls");       //���� 
            changeTeacher();         //���á���ʦ������Ϣ���� ���� 
			teacherFunction(); 
			break;    
		case 11:
	        system("cls");         //���� 
	        competence();           //����  Ȩ�޽��� ���� 
			break;
		case 12:
	        system("cls");         //���� 
	        over();           //����  ���������� ���� 
			break;
    }
}

/*******************************************************/
int studentRegistration()                    //��֤ѧ��������Ϣ�ĺ���
{
	printf("       ����������ѧ��ID:");
	scanf("%s",studentID);
	int i=0;
	while(strcmp(studentID,student[i].id)!=0)
	{
		i++;
		if(i>studentNum)
		{
			printf("        �����ID��Ч\n");
        	printf("        ���������� :");
        	scanf("%s",studentID);
        	i=0;
		}
	}
	printf("       ��������������:");
	scanf("%s",studentPassword);
	while(strcmp(studentPassword,student[i].password)!=0)
	{
		printf("         ������Ч\n");
        printf("         ��������������:");
        scanf("%s",studentPassword);
	}
	return i;
}
/********************************************************/
void orderRest()         //���ݿ�������ѯ
{
	int i,j,minidx,rest,rest2;
	for(i=0;i<(lessonNum-1);i++)
	{
	    strcpy(min.college,lesson[i].college);
	    strcpy(min.id,lesson[i].id);
	    strcpy(min.name,lesson[i].name);
	    strcpy(min.score,lesson[i].score);
	    strcpy(min.score,lesson[i].score);
	    strcpy(min.times,lesson[i].times);
	    strcpy(min.nature,lesson[i].nature);
	    strcpy(min.teacherName,lesson[i].teacherName);
	    strcpy(min.teacherID,lesson[i].teacherID);
	    strcpy(min.term,lesson[i].term);
	    strcpy(min.week,lesson[i].week);
	    strcpy(min.starT,lesson[i].starT);
	    strcpy(min.stopT,lesson[i].stopT);
	    strcpy(min.classroom,lesson[i].classroom);
	    min.stuNum=lesson[i].stuNum;
	    min.renshu=lesson[i].renshu;
	    strcpy(min.intro,lesson[i].intro);
	    strcpy(min.messag,lesson[i].messag);
	    minidx=i;
	    for(j=i+1;j<lessonNum;j++)
	    {
		    if(lesson[j].stuNum-lesson[j].renshu<min.stuNum-min.renshu)
		    {
		    	
			    strcpy(min.college,lesson[j].college);
	            strcpy(min.id,lesson[j].id);
	            strcpy(min.name,lesson[j].name);
	            strcpy(min.score,lesson[j].score);
	            strcpy(min.score,lesson[j].score);
	            strcpy(min.times,lesson[j].times);
	            strcpy(min.nature,lesson[j].nature);
	            strcpy(min.teacherName,lesson[j].teacherName);
	            strcpy(min.teacherID,lesson[j].teacherID);
	            strcpy(min.term,lesson[j].term);
	            strcpy(min.week,lesson[j].week);
	            strcpy(min.starT,lesson[j].starT);
	            strcpy(min.stopT,lesson[j].stopT);
	            strcpy(min.classroom,lesson[j].classroom);
	            min.stuNum=lesson[j].stuNum;
	            min.renshu=lesson[j].renshu;
	            strcpy(min.intro,lesson[j].intro);
	            strcpy(min.messag,lesson[j].messag);
			    minidx=j;
		    }
	        if(min.stuNum-min.renshu<lesson[i].stuNum-lesson[i].renshu)
	        {
		        strcpy(temp.college,lesson[i].college);
		        strcpy(temp.id,lesson[i].id);
		        strcpy(temp.name,lesson[i].name);
		        strcpy(temp.score,lesson[i].score);
		        strcpy(temp.times,lesson[i].times);
		        strcpy(temp.nature,lesson[i].nature);
		        strcpy(temp.teacherName,lesson[i].teacherName);
		        strcpy(temp.teacherID,lesson[i].teacherID);
		        strcpy(temp.term,lesson[i].term);
		        strcpy(temp.week,lesson[i].week);
		        strcpy(temp.starT,lesson[i].starT);
		        strcpy(temp.stopT,lesson[i].stopT);
		        strcpy(temp.classroom,lesson[i].classroom);
		        temp.stuNum=lesson[i].stuNum;
		        temp.renshu=lesson[i].renshu;
		        strcpy(temp.intro,lesson[i].intro);
		        strcpy(temp.messag,lesson[i].messag);
		
		        strcpy(lesson[i].college,min.college);
		        strcpy(lesson[i].id,min.id);
		        strcpy(lesson[i].name,min.name);
		        strcpy(lesson[i].score,min.score);
		        strcpy(lesson[i].times,min.times);
		        strcpy(lesson[i].nature,min.nature);
		        strcpy(lesson[i].teacherName,min.teacherName);
		        strcpy(lesson[i].teacherID,min.teacherID);
		        strcpy(lesson[i].term,min.term);
		        strcpy(lesson[i].week,min.week);
		        strcpy(lesson[i].starT,min.starT);
		        strcpy(lesson[i].stopT,min.stopT);
		        strcpy(lesson[i].classroom,min.classroom);
		        lesson[i].stuNum=min.stuNum;
                lesson[i].renshu=min.renshu;
		        strcpy(lesson[i].intro,min.intro);
		        strcpy(lesson[i].messag,min.messag);
		
		        strcpy(lesson[minidx].college,temp.college);
		        strcpy(lesson[minidx].id,temp.id);
		        strcpy(lesson[minidx].name,temp.name);
		        strcpy(lesson[minidx].score,temp.score);
		        strcpy(lesson[minidx].times,temp.times);
		        strcpy(lesson[minidx].nature,temp.nature);
		        strcpy(lesson[minidx].teacherName,temp.teacherName);
		        strcpy(lesson[minidx].teacherID,temp.teacherID);
		        strcpy(lesson[minidx].term,temp.term);
		        strcpy(lesson[minidx].week,temp.week);
		        strcpy(lesson[minidx].starT,temp.starT);
		        strcpy(lesson[minidx].stopT,temp.stopT);
		        strcpy(lesson[minidx].classroom,temp.classroom);
		        lesson[minidx].stuNum=temp.stuNum;
                lesson[minidx].renshu=temp.renshu;
		        strcpy(lesson[minidx].intro,temp.intro);
		        strcpy(lesson[minidx].messag,temp.messag);
		    }
		}
    }
    for(i=0;i<lessonNum;i++)
        printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
}
/********************************************************/
void orderNumber()     //��ѡ���������� 
{
	int i,j,minidx;
	for(i=0;i<(lessonNum-1);i++)
	{
	    strcpy(min.college,lesson[i].college);
	    strcpy(min.id,lesson[i].id);
	    strcpy(min.name,lesson[i].name);
	    strcpy(min.score,lesson[i].score);
	    strcpy(min.score,lesson[i].score);
	    strcpy(min.times,lesson[i].times);
	    strcpy(min.nature,lesson[i].nature);
	    strcpy(min.teacherName,lesson[i].teacherName);
	    strcpy(min.teacherID,lesson[i].teacherID);
	    strcpy(min.term,lesson[i].term);
	    strcpy(min.week,lesson[i].week);
	    strcpy(min.starT,lesson[i].starT);
	    strcpy(min.stopT,lesson[i].stopT);
	    strcpy(min.classroom,lesson[i].classroom);
	    min.stuNum=lesson[i].stuNum;
	    min.renshu=lesson[i].renshu;
	    strcpy(min.intro,lesson[i].intro);
	    strcpy(min.messag,lesson[i].messag);
	    minidx=i;
	    for(j=i+1;j<lessonNum;j++)
	    {
		    if(lesson[j].renshu>min.renshu)
		    {
		    	
			    strcpy(min.college,lesson[j].college);
	            strcpy(min.id,lesson[j].id);
	            strcpy(min.name,lesson[j].name);
	            strcpy(min.score,lesson[j].score);
	            strcpy(min.score,lesson[j].score);
	            strcpy(min.times,lesson[j].times);
	            strcpy(min.nature,lesson[j].nature);
	            strcpy(min.teacherName,lesson[j].teacherName);
	            strcpy(min.teacherID,lesson[j].teacherID);
	            strcpy(min.term,lesson[j].term);
	            strcpy(min.week,lesson[j].week);
	            strcpy(min.starT,lesson[j].starT);
	            strcpy(min.stopT,lesson[j].stopT);
	            strcpy(min.classroom,lesson[j].classroom);
	            min.stuNum=lesson[j].stuNum;
	            min.renshu=lesson[j].renshu;
	            strcpy(min.intro,lesson[j].intro);
	            strcpy(min.messag,lesson[j].messag);
			    minidx=j;
		    }
	        if(min.renshu>lesson[i].renshu)
	        {
		        strcpy(temp.college,lesson[i].college);
		        strcpy(temp.id,lesson[i].id);
		        strcpy(temp.name,lesson[i].name);
		        strcpy(temp.score,lesson[i].score);
		        strcpy(temp.times,lesson[i].times);
		        strcpy(temp.nature,lesson[i].nature);
		        strcpy(temp.teacherName,lesson[i].teacherName);
		        strcpy(temp.teacherID,lesson[i].teacherID);
		        strcpy(temp.term,lesson[i].term);
		        strcpy(temp.week,lesson[i].week);
		        strcpy(temp.starT,lesson[i].starT);
		        strcpy(temp.stopT,lesson[i].stopT);
		        strcpy(temp.classroom,lesson[i].classroom);
		        temp.stuNum=lesson[i].stuNum;
		        temp.renshu=lesson[i].renshu;
		        strcpy(temp.intro,lesson[i].intro);
		        strcpy(temp.messag,lesson[i].messag);
		
		        strcpy(lesson[i].college,min.college);
		        strcpy(lesson[i].id,min.id);
		        strcpy(lesson[i].name,min.name);
		        strcpy(lesson[i].score,min.score);
		        strcpy(lesson[i].times,min.times);
		        strcpy(lesson[i].nature,min.nature);
		        strcpy(lesson[i].teacherName,min.teacherName);
		        strcpy(lesson[i].teacherID,min.teacherID);
		        strcpy(lesson[i].term,min.term);
		        strcpy(lesson[i].week,min.week);
		        strcpy(lesson[i].starT,min.starT);
		        strcpy(lesson[i].stopT,min.stopT);
		        strcpy(lesson[i].classroom,min.classroom);
		        lesson[i].stuNum=min.stuNum;
                lesson[i].renshu=min.renshu;
		        strcpy(lesson[i].intro,min.intro);
		        strcpy(lesson[i].messag,min.messag);
		
		        strcpy(lesson[minidx].college,temp.college);
		        strcpy(lesson[minidx].id,temp.id);
		        strcpy(lesson[minidx].name,temp.name);
		        strcpy(lesson[minidx].score,temp.score);
		        strcpy(lesson[minidx].times,temp.times);
		        strcpy(lesson[minidx].nature,temp.nature);
		        strcpy(lesson[minidx].teacherName,temp.teacherName);
		        strcpy(lesson[minidx].teacherID,temp.teacherID);
		        strcpy(lesson[minidx].term,temp.term);
		        strcpy(lesson[minidx].week,temp.week);
		        strcpy(lesson[minidx].starT,temp.starT);
		        strcpy(lesson[minidx].stopT,temp.stopT);
		        strcpy(lesson[minidx].classroom,temp.classroom);
		        lesson[minidx].stuNum=temp.stuNum;
                lesson[minidx].renshu=temp.renshu;
		        strcpy(lesson[minidx].intro,temp.intro);
		        strcpy(lesson[minidx].messag,temp.messag);
		    }
		}
    }
    printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
    for(i=0;i<lessonNum;i++)
    printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    system("pause");
 }
/********************************************************/
void searchCourseName()  //���ݿγ����Ʋ�ѯ ���� 
{
	void studentFunction(); 
	char courseName[21];
	int  i=0; 
	printf("        �����������ѯ�Ŀγ�����:\n");
	scanf("%s",courseName);
	while(strcmp(courseName,lesson[i].name)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.��������Ҫ��ѯ�γ�����------------------------------\n");
            printf("------------------2.�ص�ѧ������ѡ�����--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
            { 
	            printf("�����������Ч�����������루1����2��:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch���ѡ��ִ�й���
			 {
                case 1:		  
	            system("cls");//���� 
	            printf("        ��Ҫ��ѯ�Ŀγ̲�����\n");
        	    printf("        ����������γ�����:");
        	    scanf("%s",courseName);
        	    i=0;
	            break; 
                case 2:
	            studentFunction();   
			    break;  
	         }                        
		}
	}
	printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
	printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	system("pause");
} 
/********************************************************/ 
void searchCollegeName()  //���ݿ���ѧԺ��ѯ ����
{ 
	char courseCollege[11];
	int  i=0; 
	printf("        �����������ѯ��ѧԺ :");
	scanf("%s",courseCollege);
	while(strcmp(courseCollege,lesson[i].college)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.��������ѧԺ����------------------------------\n");
            printf("------------------2.�ص�ѧ������ѡ�����--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
            { 
	            printf("�����������Ч�����������루1����2��:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch���ѡ��ִ�й���
			 {
                case 1:		  
	            system("cls");//���� 
	            printf("        ��Ҫ��ѯ��ѧԺ������\n");
        	    printf("        ����������ѧԺ���� :");
        	    scanf("%s",courseCollege);
        	    i=0;
	            break; 
                case 2:
	            studentFunction();   
			    break;  
	         }                        
		}
	}
	printf("����ѧԺ �γ�ID �γ�����            ѧ�� ѧʱ ���� ��ʦ   ����  ����ѧ��                    ��Ŀ �Ͽε� �¿ε� ����  ���� ���� �γ̽���       �γ���Ϣ\n");
	for(i=0;i<lessonNum;i++)
	{
		if(strcmp(courseCollege,lesson[i].college)==0)
		{
			printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 	
		}
	} 
	system("pause");
}
/********************************************************/ 
void searchStudentC()
{
	printf("����������ѡ�ν��\n");
    printf("%s  %s  %s  %s  %s \n",student[studentL].id,student[studentL].name,student[studentL].course1,student[studentL].course2,student[studentL].course3);
    printf("����������ص�ѧ������ѡ�����\n"); 
	system("pause");
}
/********************************************************/ 
void chooseLessonFunction()
{
	char id[11];
	int i=0,L1,L2,L3;
    for(L1=0;strcmp(student[studentL].course1,lesson[i].name)==0;L1++)
    {
        if(L1>lessonNum)
        {
        	strcpy(lesson[L1].starT,"��"); 
        	strcpy(lesson[L1].week,"��"); 
        	break;
        }
    }
    for(L2=0;strcmp(student[studentL].course2,lesson[i].name)==0;L2++)
    {
        if(L2>lessonNum)
        {
        	strcpy(lesson[L2].starT,"��"); 
        	strcpy(lesson[L2].week,"��"); 
        	break;
        }
    }
    for(L3=0;strcmp(student[studentL].course3,lesson[i].name)==0;L3++)
    {
        if(L3>lessonNum)
        {
        	strcpy(lesson[L3].starT,"��"); 
        	strcpy(lesson[L3].week,"��"); 
        	break;
        }
    }
	printf("��������Ҫѡ��Ŀγ̵Ŀγ̺�:\n");
	scanf("%s",&id);
    for(i=0;i<lessonNum;i++)
    {
    	if(strcmp(id,lesson[i].id)==0)
        {
            if(lesson[i].stuNum-lesson[i].renshu==0)
        	{
        		printf("�γ��ѱ�������ѡ�������γ�\n");
        		printf("�����������ѡ��\n");
        		system("pause");
        		chooseLessonFunction();
        	}
        	else
        	{
        		if(strcmp(student[studentL].course1,"NULL")==0&&strcmp(student[studentL].course2,lesson[i].name)!=0&&strcmp(student[studentL].course3,lesson[i].name)!=0&&(strcmp(lesson[L2].week,lesson[i].week)!=0||lesson[L2].starT,lesson[i].starT!=0)&&(strcmp(lesson[L3].week,lesson[i].week)!=0||lesson[L3].starT,lesson[i].starT!=0))
        		{
        			strcpy(student[studentL].course1,lesson[i].name);
        		    lesson[i].renshu=lesson[i].renshu+1;
        		}
        		else if(strcmp(student[studentL].course1,"NULL")!=0)
        		{
        			if(strcmp(student[studentL].course2,"NULL")==0&&strcmp(student[studentL].course1,lesson[i].name)!=0&&strcmp(student[studentL].course3,lesson[i].name)!=0&&(strcmp(lesson[L1].week,lesson[i].week)!=0||lesson[L1].starT,lesson[i].starT!=0)&&(strcmp(lesson[L3].week,lesson[i].week)!=0||lesson[L3].starT,lesson[i].starT!=0))
        			{
        			    strcpy(student[studentL].course2,lesson[i].name);
        		        lesson[i].renshu=lesson[i].renshu+1;
        		    }
        		    else if(strcmp(student[studentL].course2,"NULL")!=0)
        		    {
        		    	if(strcmp(student[studentL].course3,"NULL")==0&&strcmp(student[studentL].course2,lesson[i].name)!=0&&strcmp(student[studentL].course1,lesson[i].name)!=0&&(strcmp(lesson[L2].week,lesson[i].week)!=0||lesson[L2].starT,lesson[i].starT!=0)&&(strcmp(lesson[L1].week,lesson[i].week)!=0||lesson[L1].starT,lesson[i].starT!=0))
        		    	{
        		    		strcpy(student[studentL].course3,lesson[i].name);
        		            lesson[i].renshu=lesson[i].renshu+1;
        		    	}
        		    	if(strcmp(student[studentL].course3,"NULL")!=0&&strcmp(student[studentL].course2,"NULL")!=0&&strcmp(student[studentL].course1,"NULL")!=0)
        		    	{
        		    		printf("���Ѿ������γ�\n");
        		    		printf("�����������ѧ������ѡ�����\n");
        		    	    system("pause");
        		    		studentFunction();
        		    	}
        		    }
        		    else 
        		    {
        		        printf("���Ѿ�ѡ��ÿγ̻��߸ÿγ̺�����ѡ�γ̳�ͻ\n");
        		        printf("�����������ѡ��\n");
        		        system("pause");
        		        chooseLessonFunction();
        	        }
        		}
        		else
        		{
        		    printf("���Ѿ�ѡ��ÿγ̻��߸ÿγ̺�����ѡ�γ̳�ͻ\n");
        		    printf("�����������ѡ��\n");
        		    system("pause");
        		    chooseLessonFunction();
        	    }
        	}
        } 
    }
    FILE *fp5;
	if((fp5=fopen("�γ�����.txt","w"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(i=0;i<lessonNum;i++)
		fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
	fclose(fp5);
    FILE *fp4;
	if((fp4=fopen("ѧ����Ϣ.txt","w"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(i=0;i<studentNum;i++)
		fprintf(fp4,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
	fclose(fp4);
	printf("���Ѿ��ɹ�ѡ��\n");
    printf("�����������ѧ������ѡ�����\n");
    system("pause");

}
/********************************************************/
void delCourse()  //ѧ��ɾ���γ� ���� 
{
    int i=0,deletedLine;
    char instruct[81];
    printf("\n��ѡ�γ�1      ��ѡ�γ�2    ��ѡ�γ�3 ");
    if(strcmp(student[studentL].course1,"NULL")==0&&strcmp(student[studentL].course2,"NULL")==0&&strcmp(student[studentL].course2,"NULL")==0)
	{ 
        printf("��û����ѡ�Ŀγ�");
		printf("�����������ѧ������ѡ�����");
        system("pause");
        studentFunction();
    }
	if(strcmp(student[studentL].course1,"NULL")!=0)
		if(strcmp(student[studentL].course2,"NULL")==0)
			if(strcmp(student[studentL].course3,"NULL")==0)
				 printf("\n%s",student[studentL].course1);
    if(strcmp(student[studentL].course1,"NULL")==0)
    	if(strcmp(student[studentL].course2,"NULL")!=0)
			if(strcmp(student[studentL].course3,"NULL")==0)
				printf("\n%s",student[studentL].course2);
    if(strcmp(student[studentL].course1,"NULL")==0)
		if(strcmp(student[studentL].course2,"NULL")==0)
			if(strcmp(student[studentL].course3,"NULL")!=0)
				printf("\n%s",student[studentL].course3);
    if(strcmp(student[studentL].course1,"NULL")!=0)
		if(strcmp(student[studentL].course2,"NULL")!=0)
			if(strcmp(student[studentL].course3,"NULL")==0)
				printf("\n%s %s",student[studentL].course1,student[studentL].course2);
	if(strcmp(student[studentL].course1,"NULL")!=0)
		if(strcmp(student[studentL].course2,"NULL")==0)
			if(strcmp(student[studentL].course3,"NULL")!=0)
				printf("\n%s %s",student[studentL].course1,student[studentL].course3);
	if(strcmp(student[studentL].course1,"NULL")==0)
		if(strcmp(student[studentL].course2,"NULL")!=0)
			if(strcmp(student[studentL].course3,"NULL")!=0)
				printf("\n%s %s",student[studentL].course2,student[studentL].course3);
	if(strcmp(student[studentL].course1,"NULL")!=0)
		if(strcmp(student[studentL].course2,"NULL")!=0)
			if(strcmp(student[studentL].course3,"NULL")!=0)
				printf("\n%s %s %s",student[studentL].course1,student[studentL].course2,student[studentL].course3);
    printf("\n��������ɾ���γ̵����ƣ�");
    scanf("%s",instruct); 
    if(strcmp(instruct,student[studentL].course3)!=0)
    {
    	if(strcmp(instruct,student[studentL].course2)!=0)
    	{
    		if(strcmp(instruct,student[studentL].course1)!=0)
    		{
                printf("������Ŀγ����Ʋ���ȷ\n");
                printf("1.��������ɾ���γ�����\n");
                printf("2.�ص�ѧ������ѡ�����\n");
                scanf("%d",&choose);
                while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
                {    
	                printf("�����������Ч�����������루1����2��:");
	                scanf("%d",&choose);
	            }  
                switch(choose)
                {
        	        case 1:
				        system("cls");
        			    delCourse();
        	        case 2:
        	    	    system("cls");
        	    	    studentFunction();
		        }
		    }
	    } 
    }
    while(strcmp(instruct,lesson[i].name)!=0)
    {
        i++;
        if(i>lessonNum)
        {
            printf("����Ŀγ�������Ч������������:");
            scanf("%s",instruct);	
        }	
    }
    if(strcmp(instruct,student[studentL].course1)==0)
        strcpy(student[studentL].course1,"NULL");
    if(strcmp(instruct,student[studentL].course2)==0)
        strcpy(student[studentL].course2,"NULL");
    if(strcmp(instruct,student[studentL].course3)==0)
        strcpy(student[studentL].course3,"NULL");
    deletedLine=i;
	lesson[deletedLine].renshu=lesson[deletedLine].renshu-1;    
    FILE *fs;
    if((fs=fopen("ѧ����Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    fclose(fs);
    
    FILE *fp5;
	if((fp5=fopen("�γ�����.txt","w"))==NULL)
	{ 
	printf("�ļ���Ч\n");
	exit(1); 
	}
	for(i=0;i<lessonNum;i++)
		fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
	fclose(fp5);
	
    system("cls");
    printf("ɾ����ϡ�1.����ɾ���γ� 2.����ѧ��������");
    printf("\n��ѡ��");
    scanf("%d",&choose);
    while(choose<1||choose>2)   //�����������еĹ�������ʱѭ��
    {  
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
	} 
    switch(choose) 
    {
   	    case 1:
   	        system("cls");
			readLessonInformation();  
			readStudentInformation(); 	
   	        delCourse();
	        break;
	    case 2:
	        system("cls");	
	        studentFunction();
            break;  	
    }
}
/********************************************************/
void changeStudent();
void changeEmailS()    // ����Email���� 
{
	int i;
	char email[81];
	printf("�����µ�����:");
	scanf("%s",email);
	strcpy(student[studentL].email,email);
	
	FILE *fs;
    if((fs=fopen("ѧ����Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.�����޸ĸ�����Ϣ -------------------------\n");
    printf("-------- 2.�ص�ѧ������ѡ����� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeStudent();      //���ø���ѧ������  
	        break;
		case 2:
	        system("cls");      //����  
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;  
    }     
}
void changePasswordS()
{
	char password[81];
	int i;
	printf("�����µ�����:");
	scanf("%s",password);
	strcpy(student[studentL].password,password);
	
	FILE *fs;
    if((fs=fopen("ѧ����Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.�����޸ĸ�����Ϣ -------------------------\n");
    printf("-------- 2.�ص�ѧ������ѡ����� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeStudent();      //���ø���ѧ������  
	        break;
		case 2:
	        system("cls");      //����  
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break; 
    }     
}
void changePhone()
{
	char phone[12];
	int i;
	printf("�����µ��ֻ���:");
	scanf("%s",phone);
	strcpy(student[studentL].phone,phone);
	
	FILE *fs;
    if((fs=fopen("ѧ����Ϣ.txt","w"))==NULL)
    { 
        printf("�ļ���Ч\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.�����޸ĸ�����Ϣ -------------------------\n");
    printf("-------- 2.�ص�ѧ������ѡ����� -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>2)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");      //���� 
	        changeStudent();      //���ø���ѧ������  
	        break;
		case 2:
	        system("cls");      //����  
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;
    }       
}
void changeStudent()           //��ʦ������Ϣ���� ���� 
{
	printf("-------------------------------------------------\n");
    printf("-------- 1.�޸ĸ������� -------------------------\n");
    printf("-------- 2.�޸ĸ������� -------------------------\n");
    printf("-------- 3.�޸ĸ��˵绰 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("ѡ����Ҫ���ĵ���Ϣ");
	scanf("%d",&choose);
    while(choose<1||choose>3)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����3��:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch���ѡ��ִ�й���
    {
		case 2:		  
	        system("cls");      //���� 
	        changeEmailS();      //���ø���Email����  
	        break;
		case 1:
	        system("cls");      //���� 
	        changePasswordS();   //����  �������� ���� 
			break;
		case 3:
	        system("cls");      //���� 
	        changePhone();   //����  ���ĵ绰 ���� 
			break;
    }      
}
/********************************************************/
void studentFunction()  //����ѡ����
{   
    readTeacherInformation();    //��ȡ�ļ���Ľ�ʦ��Ϣ
	readStudentInformation();    //��ȡ�ļ��е�ѧ����Ϣ    
	readLessonInformation();     //��ȡ�ļ���Ŀγ���Ϣ 
	system("cls");                         //���� 
    printf("-------------------------------------------------\n");
    printf("-------- 1.���ݿγ�����ѯ -----------------------\n");
    printf("-------- 2.���ݿ���ѧԺ��ѯ ---------------------\n");
    printf("---------3.���ݿ������������пγ�----------------\n");
    printf("---------4.����ѡ�������������пγ�--------------\n");
    printf("---------5.�鿴����ѡ�޹��Ŀγ�------------------\n");
    printf("---------6.ɾ��ѡ�ν��--------------------------\n");
    printf("---------7.������Ϣ����--------------------------\n");
    printf("---------8.�˳���Ȩ��ѡ�����--------------------\n");
	printf("---------9.�˳�������----------------------------\n");
	printf("-------------------------------------------------\n");
    printf("��ѡ���ܣ�"); 
    scanf("%d",&choose);
    while(choose<1||choose>9)//�ݴ�  �����������еĹ�������ʱѭ�� 
    { 
	    printf("�����������Ч�����������루1����9��:");
	    scanf("%d",&choose);
    }     
    switch(choose)                 //switch���ѡ��ִ�й���
    {
		case 1:		  
	        system("cls");         //���� 
	        searchCourseName();    //����  ���ݿγ����Ʋ�ѯ ���� 
	        chooseLessonFunction();
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;
		case 2:
	        system("cls");         //���� 
	        searchCollegeName();   //����  ���ݿ���ѧԺ��ѯ ���� 
	        chooseLessonFunction();
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;
		case 3:
	        system("cls");         //���� 
	        orderRest();           //���� ���ݿ������������пγ� ���� 
	        chooseLessonFunction();
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break; 
		case 4:
	        system("cls");         //���� 
	        orderNumber();         //���� ����ѡ�������������пγ� ���� 
	        chooseLessonFunction();
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;
		case 5:
	        system("cls");         //���� 
	        searchStudentC();      //����  �鿴����ѡ�޹��Ŀγ� ���� 
	        studentFunction();     //�ص�ѧ������ѡ�� 
			break;
		case 6:
	        system("cls");         //���� 
	        delCourse();           //����  ɾ��ѡ�ν�� ���� 
			break;
        case 7:
	        system("cls");         //���� 
	        changeStudent();           //����  ѧ��������Ϣ���� ���� 
			break;
		case 8:
	        system("cls");         //���� 
	        competence();           //����  Ȩ�޽��� ���� 
			break;
		case 9:
	        system("cls");         //���� 
	        over();           //����  ���������� ���� 
			break;
    }
}
/********************************************************/
void competence()                  //ѡ��Ȩ�޺��� 
{
	printf("------------------------------------------------------------\n");
    printf("------------------------------------------------------------\n");
    printf("-----------Student Course Management System-----------------\n");
    printf("---------------------1.Student------------------------------\n");
    printf("---------------------2.teacher------------------------------\n");
    printf("---------------------3.Exit------------------------------\n");
    printf("           Chooose your competence:");
	scanf("%d",&choose);
    while(choose<1||choose>3)      //�����������еĹ�������ʱѭ��
    { 
	    printf("�����������Ч�����������루1����2��:");
	    scanf("%d",&choose);
    }    
    switch(choose)   //switch���ѡ��ִ�й���
    {
        case 2:		  
	        system("cls");//���� 
	        readTeacherInformation();    //��ȡ�ļ���Ľ�ʦ��Ϣ
			readStudentInformation();    //��ȡ�ļ��е�ѧ����Ϣ    
	        readLessonInformation();     //��ȡ�ļ���Ŀγ���Ϣ 
			teacherL=teacherRegistration(); //������λ��ʦ���ڵ����� 
	        teacherFunction();
	        break; 
        case 1:
	        system("cls"); //����
	        readStudentInformation();    //��ȡ�ļ��е�ѧ����Ϣ 
	        readLessonInformation();     //��ȡ�ļ��еĿγ���Ϣ 
	        studentL=studentRegistration();  //������λѧ�����ڵ����� 
	        studentFunction();   
			break; 
		case 3:
	        system("cls");         //���� 
	        over();           //����  ���������� ���� 
			break; 
	}                       
}
/************************************************************/
int main()  //������ �ṹ 
{
	competence();
	return 0;
}
