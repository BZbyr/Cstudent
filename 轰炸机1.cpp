#include<stdio.h>                 //C语言标准输入输出头文件
#include<stdlib.h>                //文件操作需要用到的头文件
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
int choose;     //每一次功能选择用的都是choose 
int teacherL,studentL;   //
int teacherNum,studentNum,lessonNum; 
char teacherID[20],teacherPassword[81];  
char studentID[20],studentPassword[81]; 
void competence();
/*********************************************************/
void readLessonInformation()
{
	FILE *fp5;
	if((fp5=fopen("课程属性.txt","r"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(lessonNum=0;!feof(fp5);lessonNum++)
		fscanf(fp5,"%s%s%s%s%s%s%s%s%s%s%s%s%s %d %d %s%s\n",lesson[lessonNum].college,lesson[lessonNum].id,lesson[lessonNum].name,lesson[lessonNum].score,lesson[lessonNum].times,lesson[lessonNum].nature,lesson[lessonNum].teacherName,lesson[lessonNum].teacherID,lesson[lessonNum].term,lesson[lessonNum].week,lesson[lessonNum].starT,lesson[lessonNum].stopT,lesson[lessonNum].classroom,&lesson[lessonNum].stuNum,&lesson[lessonNum].renshu,lesson[lessonNum].intro,lesson[lessonNum].messag);
	fclose(fp5);
}
/*************************************************************/ 
void over()                          //程序测试完毕函数
{
	printf("\n\n------您已退出选课管理系统------\n\n");  //输出测试结果记录提示 
	exit(0); 
}
/********************************************************/
void readTeacherInformation()
{
	FILE *fp5;
	if((fp5=fopen("教师信息.txt","r"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(teacherNum=0;!feof(fp5);teacherNum++)
		fscanf(fp5,"%s%s%s%s%s%s\n",teacher[teacherNum].id,teacher[teacherNum].college,teacher[teacherNum].name,teacher[teacherNum].phone,teacher[teacherNum].password,teacher[teacherNum].email);
	fclose(fp5);
}
/*********************************************************/
void readStudentInformation()  //读取学生信息 函数 
{
	FILE *fp5;
	if((fp5=fopen("学生信息.txt","r"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(studentNum=0;!feof(fp5);studentNum++)
		fscanf(fp5,"%s%s%s%s%s%s%s%s%s%s\n",student[studentNum].id,student[studentNum].college,student[studentNum].prof,student[studentNum].name,student[studentNum].phone,student[studentNum].password,student[studentNum].email,student[studentNum].course1,student[studentNum].course2,student[studentNum].course3);
	fclose(fp5);
}
/*******************************************************/
int teacherRegistration()                    //验证老师输入信息的函数
{
	printf("        请输入您的教师ID :");
	scanf("%s",teacherID);
	int i=0;
	while(strcmp(teacherID,teacher[i].id)!=0)
	{
		i++;
		if(i>teacherNum)
		{
			printf("        输入的ID无效\n");
        	printf("        请重新输入 :");
        	scanf("%s",teacherID);
        	i=0;
		}
	}
	printf("        请输入密码:");
	scanf("%s",teacherPassword);
	while(strcmp(teacherPassword,teacher[i].password)!=0)
	{
		printf("        密码无效\n");
        printf("        请重新输入密码 :");
        scanf("%s",teacherPassword);
	}
	return i;
}
/********************************************************/
void openedAllCourses() //查询所有已经开设的课程
{
	int i;
	printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
	for(i=0;i<=lessonNum;i++)
	{
		printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	}
	printf("按任意键键回到教师功能选择界面\n"); 
	system("pause");
} 
/********************************************************/
void teacherFunction();
void studentFunction();
void searchCourseNamet()  //根据课程名称查询 函数 
{
	char courseName[21];
	int  i=0; 
	printf("        请输入您欲查询的课程名称 :");
	scanf("%s",courseName);
	while(strcmp(courseName,lesson[i].name)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.重新输入要查询课程名字------------------------------\n");
            printf("------------------2.回到教师功能选择界面--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //不在以上所列的功能以内时循环
            { 
	            printf("输入的数字无效，请重新输入（1——2）:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch语句选择执行功能
			 {
                case 1:		  
	            system("cls");//清屏 
	            printf("        您要查询的课程不存在\n");
        	    printf("        请重新输入课程名称 :");
        	    scanf("%s",courseName);
        	    i=0;
	            break; 
                case 2:
	            teacherFunction();   //回到教师功能界面 
			    break;  
	         }                        
		}
	}
	printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
	printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	printf("按任意键键回到教师功能选择界面\n"); 
	system("pause");
}
/********************************************************/
void searchStudentNamet()  //根据学生名称查询 函数 
{
	char studentName[21];
	int  i=0; 
    printf("        请输入您欲查询的学生姓名 :");
	scanf("%s",studentName);
	while(strcmp(studentName,student[i].name)!=0)
	{
		i++;
		if(i>studentNum)
		{
			printf("------------------1.重新输入要查询学生名字------------------------------\n");
            printf("------------------2.回到教师功能选择界面--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //不在以上所列的功能以内时循环
            { 
	            printf("输入的数字无效，请重新输入（1——2）:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch语句选择执行功能
			 {
                case 1:		  
	            system("cls");//清屏 
	            printf("        您要查询的学生姓名不存在\n");
        	    printf("        请重新输入学生姓名 :");
        	    scanf("%s",studentName);
        	    i=0;
	            break; 
                case 2:
	            teacherFunction();   //回到教师功能界面 
			    break;  
	         }                        
		}
	}
    printf("学生姓名  ID          所选课程        \n");
	printf("%-10s%-12s%-15s%-15s%-15s\n",student[i].name,student[i].id,student[i].course1,student[i].course2,student[i].course3); 
	printf("按任意键键回到教师功能选择界面\n"); 
	system("pause");
}
/***********************************************/
void changeCourse()    //调用 修改课程信息 函数 
{
	
    FILE *fs;
    int i,determinant,newLimit;
    char newBook[20];
    char newIntro[20];
    char instruct[11];
    printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
    for(i=0;i<lessonNum;i++)
    {
        if(strcmp(teacherID,lesson[i].teacherID)==0) 
        printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    }
    printf("\n请输入欲修改的课程编号：");
    scanf("%s",instruct); 
    i=0;
    while(strcmp(instruct,lesson[i].id)!=0 || strcmp(teacherID,lesson[i].teacherID)!=0 )
    {
        i++;
        if(i>lessonNum)
        {
            printf("\n输入的课程编号无效，请重新输入:");
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
            if((fs=fopen("课程属性.txt","w"))==NULL)
            { 
                printf("文件无效\n");
                exit(1); 
            }	
            printf("\n该课程尚未有学生选择，您可以输入下列序号来修改");
            printf("\n1.教材 2.课程简介 3.限制人数");
            printf("\n请选择：");
            scanf("%d",&choose);
            while(choose<1||choose>3) 
            { 
	            printf("输入的数字无效，请重新输入（1——3）:");
	            scanf("%d",&choose);
            }     
  
            switch(choose)
            {
                case 1:
                    printf("\n请输入新的课本信息:");
                    scanf("%s",newBook);
                    strcpy(lesson[i].messag,newBook);
                    for(i=0;i<lessonNum;i++)
                       fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
                    fclose(fs);	
                    break;
                case 2:
                    printf("\n请输入新的课程简介:");
                    scanf("%s",newIntro);
                    strcpy(lesson[i].intro,newIntro);
                    for(i=0;i<lessonNum;i++)
                        fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
                    fclose(fs);	
                    break;
                case 3:
                    printf("\n请输入新的课程上限人数:");
                    scanf("%d",newLimit);
                    while(newLimit!=80 && newLimit!=100)
                    { 
	                    printf("输入数字无效，请重新输入（80/100):");
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
            printf("\n已有学生选择该课程，请输入新的限制人数：");
            scanf("%d",&newLimit);
            while(newLimit!=80 && newLimit!=100)
            { 
	            printf("输入数字无效，请重新输入（80/100):");
	            scanf("%d",&newLimit);
            }    
            lesson[i].stuNum=newLimit;
            if((fs=fopen("课程属性.txt","w"))==NULL)
            { 
                printf("文件无效\n");
                exit(1); 
            }
            for(i=0;i<lessonNum;i++)
                fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
            fclose(fs);
            break;
    }
   	printf("按任意键键回到教师功能选择界面\n"); 
	system("pause");
}	
/********************************************************/
void searchExisted()    //查询自己已开设课程函数 
{
    int i=0;
    printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
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
void courseCensus()    //调用 统计已开设课程数目 函数 
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
    printf("您已开设的课程数为%d\n",sum);
    system("pause");	
}
/********************************************************/
void addCourse()            //教师添加课程
{
	int i,num=0;
	for(i=0;i<lessonNum;i++)
	{
		if(strcmp(lesson[i].teacherName,teacher[teacherL].name)==0)
			num++;
	}
	if(num>=2)   //同一名教师一个学期最多只能开两门选修课
	{
		printf("你开设的课程已满");
		printf("按任意键键回到教师功能选择界面\n"); 
	    system("pause");
		teacherFunction(); 
	}
	strcpy(temp.id,teacher[teacherL].id);
	strcpy(temp.name,teacher[teacherL].name);
	printf("开始添加课程");
	printf("\n输入课程名称:");
	scanf("%s",temp.name);
	system("cls");
	printf("\n输入课程ID:");
	scanf("%s",temp.id);
	system("cls");
	printf("\n输入上课周目:");
	scanf("%s",temp.week);
	system("cls");
	printf("\n1. 08:00--09:50");
	printf("\n2. 10:00--11:50");
	printf("\n3. 13:30--15:20");
	printf("\n4. 15:30--17:20");
	printf("\n5. 18:30--20:20");
	printf("\n选择上课时间:");
	scanf("%d",&choose);
    while(choose<1||choose>5)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
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
	printf("\n输入开设学院:");
	scanf("%s",temp.college);
	system("cls");
	printf("\n1. 必修");
	printf("\n2. 选修"); 
	printf("\n选择课程性质:");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        strcpy(temp.nature,"必修"); 
	        break;
		case 2:
		    strcpy(temp.nature,"选修");
			break;
    }
    system("cls");
	printf("\n输入课程学分:");
	scanf("%s",temp.score);
	system("cls");
	printf("\n输入课程课时:");
	scanf("%s",temp.times);
	system("cls");
	printf("\n1. 80");
	printf("\n2. 100\n"); 
	printf("\n选择开课人数(80/100):");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        temp.stuNum=80; 
	        break;
		case 2:
		    temp.stuNum=100;
			break;
    }
    system("cls");
	printf("\n输入课程介绍:");
	scanf("%s",temp.intro);
	system("cls");
	printf("\n输入课程信息:");
	scanf("%s",temp.messag);
	system("cls");
	printf("\n1. 2014-2015学年第二学期4-16周");
	printf("\n2. 2015-2016学年第一学期4-16周"); 
	printf("\n选择课程开设学期:");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        strcpy(temp.term,"2014-2015学年第二学期4-16周"); 
	        break;
		case 2:
		    strcpy(temp.term,"2015-2016学年第一学期4-16周");
			break;
    }
    system("cls");
	printf("输入上课教室:");
	scanf("%s",temp.classroom);
	temp.renshu=0; 
	
	for(i=0;i<lessonNum;i++)   //通过 for 和 if 来判断同一名教师的上课时间不能冲突 
	{
		if(strcmp(lesson[i].name,temp.name)==0)   //课程名及课程号不能重复
		{
			printf("课程名称冲突");
			printf("重新输入课程名称:");
	        scanf("%s",temp.name);
		}
		if(strcmp(lesson[i].id,temp.id)==0)
		{
			printf("课程ID冲突");
			printf("重新输入课程ID:");
	        scanf("%s",temp.id);
		}
		if(strcmp(lesson[i].teacherName,temp.teacherName)==0)    //  自己的上课时间不能冲突 
		{
			if(strcmp(lesson[i].week,temp.week)==0)
			{
				if(strcmp(lesson[i].starT,temp.starT)==0)
				{
					printf("该课程跟自己上课时间冲突");
			        printf("\n重新输入上课周目:");
	                scanf("%s",temp.name);
	                printf("\n重新输入上课开始时间:");
	                scanf("%s",temp.name);
				} 
	        }
		}
		if(strcmp(lesson[i].week,temp.week)==0)    //和别人的上课时间地点教室不能冲突 
		{
			if(strcmp(lesson[i].starT,temp.starT)==0)
			{
				if(strcmp(lesson[i].classroom,temp.classroom)==0)
				{
					printf("该课程跟他人上课时间地点冲突");
			        printf("\n重新输入上课周目:");
	                scanf("%s",temp.name);
	                printf("\n重新输入上课开始时间:");
	                scanf("%s",temp.name);
	                printf("\n重新输入上课教室:");
	                scanf("%s",temp.classroom);
				} 
			} 
		}
	}
	FILE *fp5;
	if((fp5=fopen("课程属性.txt","a"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",temp.college,temp.id,temp.name,temp.score,temp.times,temp.nature,teacher[teacherL].name,teacher[teacherL].id,temp.term,temp.week,temp.starT,temp.stopT,temp.classroom,temp.stuNum,temp.renshu,temp.intro,temp.messag);
	fclose(fp5);
	system("cls");
	printf("成功添加课程");
	system("pause");
} 
/********************************************************/
void deleteCourse()    //  教师删除课程  函数 
{
    FILE *fs;
    int i,deletedLine;
    char instruct[11]; 
    printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
    for(i=0;i<lessonNum;i++)
    {
        if(lesson[i].renshu<30 && strcmp(teacherID,lesson[i].teacherID)==0) 
        printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    }
    printf("请输入欲删除课程的编号：");
    scanf("%s",instruct);
    i=0;
    while(strcmp(instruct,lesson[i].id)!=0 || strcmp(teacherID,lesson[i].teacherID)!=0 || lesson[i].renshu>30)
    {
        i++;
        if(i>lessonNum)
        {
            printf("输入的课程编号无效，请重新输入:");
            scanf("%s",instruct);	
        }	
    }
   deletedLine=i;
   if((fs=fopen("课程属性.txt","w"))==NULL)
   { 
        printf("文件无效\n");
        exit(1); 
   }
   for(i=0;i<lessonNum;i++)
   {
   	    if(i!=deletedLine)
   	        fprintf(fs,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
   }
   fclose(fs);
   system("cls");
   printf("删除完毕。1.继续删除课程 2.返回教师主界面");
   printf("\n请选择：");
   scanf("%d",&choose);
   while(choose<1||choose>2)   //不在以上所列的功能以内时循环
   { 
	    printf("输入的数字无效，请重新输入（1——2）:");
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
void changeEmailT()    // 更改Email函数 
{
	int i;
	char email[81];
	printf("输入新的邮箱:");
	scanf("%s",email);
	strcpy(teacher[teacherL].email,email);	
	FILE *fs;
    if((fs=fopen("教师信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<teacherNum;i++)
    {
   	    fprintf(fs,"%9s%10s%8s%13s%8s%30s\n",teacher[i].id,teacher[i].college,teacher[i].name,teacher[i].phone,teacher[i].password,teacher[i].email);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.继续修改个人信息 -------------------------\n");
    printf("-------- 2.回到教师功能选择界面 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeTeacher();      //调用更改教师函数  
	        break;
		case 2:
	        system("cls");      //清屏  
	        teacherFunction();     //回到教师功能选择 
			break;  
    }     
}
void changePasswordT()
{
	char password[81];
	int i;
	printf("输入新的密码:");
	scanf("%s",password);
	strcpy(teacher[teacherL].password,password);
	
	FILE *fs;
    if((fs=fopen("教师信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<teacherNum;i++)
    {
   	    fprintf(fs,"%9s%10s%8s%13s%8s%30s\n",teacher[i].id,teacher[i].college,teacher[i].name,teacher[i].phone,teacher[i].password,teacher[i].email);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.继续修改个人信息 -------------------------\n");
    printf("-------- 2.回到教师功能选择界面 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeTeacher();      //调用更改教师函数  
	        break;
		case 2:
	        system("cls");      //清屏  
	        teacherFunction();     //回到教师功能选择 
			break;
    }   
}
void changeTeacher()           //老师个人信息管理 函数 
{
	printf("-------------------------------------------------\n");
    printf("-------- 1.修改个人邮箱 -------------------------\n");
    printf("-------- 2.修改个人密码 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeEmailT();      //调用更改Email函数  
	        break;
		case 2:
	        system("cls");      //清屏 
	        changePasswordT(); //调用  根据课程名称查询 函数 
			break;
    }      
}
/********************************************************/
void orderNumber();
void teacherFunction()    //教师功能选择函数
{
	readTeacherInformation();    //读取文件里的教师信息
	readStudentInformation();    //读取文件中的学生信息    
	readLessonInformation();     //读取文件里的课程信息 
	system("cls");                         //清屏   
    printf("-------------------------------------------------\n");
    printf("-------- 1.查询已开设过的课程 -------------------\n");
    printf("-------- 2.查询课程学生信息 ---------------------\n");
    printf("---------3.统计开设过的课程数目------------------\n");
    printf("---------4.按选课人数排序所有开设过的课程--------\n");
    printf("---------5.查询所有已经开设的课程----------------\n");
    printf("---------6.根据课程名查询------------------------\n");
    printf("---------7.修改课程------------------------------\n");
    printf("---------8.添加课程------------------------------\n");
    printf("---------9.删除课程------------------------------\n");
    printf("---------10.个人信息管理-------------------------\n");
    printf("---------11.退出到权限选择界面-------------------\n");
	printf("---------12.退出主程序---------------------------\n");
	printf("-------------------------------------------------\n");
    printf("Choose the function："); 
    scanf("%d",&choose);
    while(choose<1||choose>12)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——12）:");
	    scanf("%d",&choose);
    }     
    switch(choose)//switch语句选择执行功能
    {
    	case 1:
            system("cls");
			searchExisted();   //调用查询自己已开设课程函数 
			teacherFunction();
			break;
		case 2:
		    system("cls");
			searchStudentNamet(); //调用 查询学生姓名 函数 
			teacherFunction();
			break;
	    case 3:
		    system("cls");
			courseCensus();   //调用 统计已开设课程数目 函数 
			teacherFunction(); 
			break;
    	case 4:
	        system("cls");         //清屏 
	        orderNumber();         //调用 根据选课人数排序所有课程 函数 
	        teacherFunction();     //回到学生功能选择 
	        break;
		case 5:		  
	        system("cls");      //清屏 
	        openedAllCourses();    //调用 查询所有开设过的课程  函数 
	        teacherFunction();     //回到教师功能选择 
	        break;
		case 6:
	        system("cls");         //清屏 
	        searchCourseNamet();   //调用  根据课程名称查询 函数 
	        teacherFunction();     //回到教师功能选择 
			break;
		case 7:
		    system("cls");
			changeCourse();   //调用 修改课程信息 函数 
			teacherFunction(); 
		case 8:
	        system("cls");       //清屏 
	        addCourse();         //调用  添加课程 函数 
	        teacherFunction();   //回到教师功能选择 
			break;
		case 9:
            system("cls");
            deleteCourse();     //调用 删除课程  函数 
            teacherFunction();
            break;	
        case 10:
	        system("cls");       //清屏 
            changeTeacher();         //调用　老师个人信息管理 函数 
			teacherFunction(); 
			break;    
		case 11:
	        system("cls");         //清屏 
	        competence();           //调用  权限界面 函数 
			break;
		case 12:
	        system("cls");         //清屏 
	        over();           //调用  结束主程序 函数 
			break;
    }
}

/*******************************************************/
int studentRegistration()                    //验证学生输入信息的函数
{
	printf("       请输入您的学生ID:");
	scanf("%s",studentID);
	int i=0;
	while(strcmp(studentID,student[i].id)!=0)
	{
		i++;
		if(i>studentNum)
		{
			printf("        输入的ID无效\n");
        	printf("        请重新输入 :");
        	scanf("%s",studentID);
        	i=0;
		}
	}
	printf("       请输入您的密码:");
	scanf("%s",studentPassword);
	while(strcmp(studentPassword,student[i].password)!=0)
	{
		printf("         密码无效\n");
        printf("         请重新输入密码:");
        scanf("%s",studentPassword);
	}
	return i;
}
/********************************************************/
void orderRest()         //根据课余量查询
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
void orderNumber()     //按选课人数排序 
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
    printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
    for(i=0;i<lessonNum;i++)
    printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
    system("pause");
 }
/********************************************************/
void searchCourseName()  //根据课程名称查询 函数 
{
	void studentFunction(); 
	char courseName[21];
	int  i=0; 
	printf("        请输入您想查询的课程名称:\n");
	scanf("%s",courseName);
	while(strcmp(courseName,lesson[i].name)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.重新输入要查询课程名字------------------------------\n");
            printf("------------------2.回到学生功能选择界面--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //不在以上所列的功能以内时循环
            { 
	            printf("输入的数字无效，请重新输入（1——2）:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch语句选择执行功能
			 {
                case 1:		  
	            system("cls");//清屏 
	            printf("        您要查询的课程不存在\n");
        	    printf("        请重新输入课程名称:");
        	    scanf("%s",courseName);
        	    i=0;
	            break; 
                case 2:
	            studentFunction();   
			    break;  
	         }                        
		}
	}
	printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
	printf("%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag); 
	system("pause");
} 
/********************************************************/ 
void searchCollegeName()  //根据开设学院查询 函数
{ 
	char courseCollege[11];
	int  i=0; 
	printf("        请输入您想查询的学院 :");
	scanf("%s",courseCollege);
	while(strcmp(courseCollege,lesson[i].college)!=0)
	{
		i++;
		if(i>lessonNum)
		{
			printf("------------------1.重新输入学院名字------------------------------\n");
            printf("------------------2.回到学生功能选择界面--------------------------------\n");
			scanf("%d",&choose);
            while(choose<1||choose>2)   //不在以上所列的功能以内时循环
            { 
	            printf("输入的数字无效，请重新输入（1——2）:");
	            scanf("%d",&choose);
            }       
		     switch(choose)   //switch语句选择执行功能
			 {
                case 1:		  
	            system("cls");//清屏 
	            printf("        您要查询的学院不存在\n");
        	    printf("        请重新输入学院名称 :");
        	    scanf("%s",courseCollege);
        	    i=0;
	            break; 
                case 2:
	            studentFunction();   
			    break;  
	         }                        
		}
	}
	printf("开设学院 课程ID 课程名称            学分 学时 性质 老师   工号  开课学期                    周目 上课点 下课点 教室  上限 人数 课程介绍       课程信息\n");
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
	printf("以下是您的选课结果\n");
    printf("%s  %s  %s  %s  %s \n",student[studentL].id,student[studentL].name,student[studentL].course1,student[studentL].course2,student[studentL].course3);
    printf("按任意键键回到学生功能选择界面\n"); 
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
        	strcpy(lesson[L1].starT,"无"); 
        	strcpy(lesson[L1].week,"无"); 
        	break;
        }
    }
    for(L2=0;strcmp(student[studentL].course2,lesson[i].name)==0;L2++)
    {
        if(L2>lessonNum)
        {
        	strcpy(lesson[L2].starT,"无"); 
        	strcpy(lesson[L2].week,"无"); 
        	break;
        }
    }
    for(L3=0;strcmp(student[studentL].course3,lesson[i].name)==0;L3++)
    {
        if(L3>lessonNum)
        {
        	strcpy(lesson[L3].starT,"无"); 
        	strcpy(lesson[L3].week,"无"); 
        	break;
        }
    }
	printf("请输入您要选择的课程的课程号:\n");
	scanf("%s",&id);
    for(i=0;i<lessonNum;i++)
    {
    	if(strcmp(id,lesson[i].id)==0)
        {
            if(lesson[i].stuNum-lesson[i].renshu==0)
        	{
        		printf("课程已被报满请选择其他课程\n");
        		printf("按任意键重新选课\n");
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
        		    		printf("您已经报满课程\n");
        		    		printf("按任意键返回学生功能选择界面\n");
        		    	    system("pause");
        		    		studentFunction();
        		    	}
        		    }
        		    else 
        		    {
        		        printf("您已经选择该课程或者该课程和你已选课程冲突\n");
        		        printf("按任意键重新选课\n");
        		        system("pause");
        		        chooseLessonFunction();
        	        }
        		}
        		else
        		{
        		    printf("您已经选择该课程或者该课程和你已选课程冲突\n");
        		    printf("按任意键重新选课\n");
        		    system("pause");
        		    chooseLessonFunction();
        	    }
        	}
        } 
    }
    FILE *fp5;
	if((fp5=fopen("课程属性.txt","w"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(i=0;i<lessonNum;i++)
		fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
	fclose(fp5);
    FILE *fp4;
	if((fp4=fopen("学生信息.txt","w"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(i=0;i<studentNum;i++)
		fprintf(fp4,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
	fclose(fp4);
	printf("您已经成功选课\n");
    printf("按任意键返回学生功能选择界面\n");
    system("pause");

}
/********************************************************/
void delCourse()  //学生删除课程 函数 
{
    int i=0,deletedLine;
    char instruct[81];
    printf("\n已选课程1      已选课程2    已选课程3 ");
    if(strcmp(student[studentL].course1,"NULL")==0&&strcmp(student[studentL].course2,"NULL")==0&&strcmp(student[studentL].course2,"NULL")==0)
	{ 
        printf("您没有已选的课程");
		printf("按任意键返回学生功能选择界面");
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
    printf("\n请输入欲删除课程的名称：");
    scanf("%s",instruct); 
    if(strcmp(instruct,student[studentL].course3)!=0)
    {
    	if(strcmp(instruct,student[studentL].course2)!=0)
    	{
    		if(strcmp(instruct,student[studentL].course1)!=0)
    		{
                printf("你输入的课程名称不正确\n");
                printf("1.重新输入删除课程名称\n");
                printf("2.回到学生功能选择界面\n");
                scanf("%d",&choose);
                while(choose<1||choose>2)   //不在以上所列的功能以内时循环
                {    
	                printf("输入的数字无效，请重新输入（1——2）:");
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
            printf("输入的课程名称无效，请重新输入:");
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
    if((fs=fopen("学生信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    fclose(fs);
    
    FILE *fp5;
	if((fp5=fopen("课程属性.txt","w"))==NULL)
	{ 
	printf("文件无效\n");
	exit(1); 
	}
	for(i=0;i<lessonNum;i++)
		fprintf(fp5,"%-9s%-7s%-20s%-5s%-5s%-5s%-7s%-6s%-28s%-5s%-7s%-7s%-6s%-5d%-5d%-15s%-26s\n",lesson[i].college,lesson[i].id,lesson[i].name,lesson[i].score,lesson[i].times,lesson[i].nature,lesson[i].teacherName,lesson[i].teacherID,lesson[i].term,lesson[i].week,lesson[i].starT,lesson[i].stopT,lesson[i].classroom,lesson[i].stuNum,lesson[i].renshu,lesson[i].intro,lesson[i].messag);
	fclose(fp5);
	
    system("cls");
    printf("删除完毕。1.继续删除课程 2.返回学生主界面");
    printf("\n请选择：");
    scanf("%d",&choose);
    while(choose<1||choose>2)   //不在以上所列的功能以内时循环
    {  
	    printf("输入的数字无效，请重新输入（1——2）:");
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
void changeEmailS()    // 更改Email函数 
{
	int i;
	char email[81];
	printf("输入新的邮箱:");
	scanf("%s",email);
	strcpy(student[studentL].email,email);
	
	FILE *fs;
    if((fs=fopen("学生信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.继续修改个人信息 -------------------------\n");
    printf("-------- 2.回到学生功能选择界面 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeStudent();      //调用更改学生函数  
	        break;
		case 2:
	        system("cls");      //清屏  
	        studentFunction();     //回到学生功能选择 
			break;  
    }     
}
void changePasswordS()
{
	char password[81];
	int i;
	printf("输入新的密码:");
	scanf("%s",password);
	strcpy(student[studentL].password,password);
	
	FILE *fs;
    if((fs=fopen("学生信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.继续修改个人信息 -------------------------\n");
    printf("-------- 2.回到学生功能选择界面 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeStudent();      //调用更改学生函数  
	        break;
		case 2:
	        system("cls");      //清屏  
	        studentFunction();     //回到学生功能选择 
			break; 
    }     
}
void changePhone()
{
	char phone[12];
	int i;
	printf("输入新的手机号:");
	scanf("%s",phone);
	strcpy(student[studentL].phone,phone);
	
	FILE *fs;
    if((fs=fopen("学生信息.txt","w"))==NULL)
    { 
        printf("文件无效\n");
        exit(1);
    }
    for(i=0;i<studentNum;i++)
    {
   	    fprintf(fs,"%12s%10s%10s%8s%13s%8s%17s%15s%15s%15s\n",student[i].id,student[i].college,student[i].prof,student[i].name,student[i].phone,student[i].password,student[i].email,student[i].course1,student[i].course2,student[i].course3);
    }
    fclose(fs);
    
    printf("-------------------------------------------------\n");
    printf("-------- 1.继续修改个人信息 -------------------------\n");
    printf("-------- 2.回到学生功能选择界面 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>2)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 1:		  
	        system("cls");      //清屏 
	        changeStudent();      //调用更改学生函数  
	        break;
		case 2:
	        system("cls");      //清屏  
	        studentFunction();     //回到学生功能选择 
			break;
    }       
}
void changeStudent()           //老师个人信息管理 函数 
{
	printf("-------------------------------------------------\n");
    printf("-------- 1.修改个人密码 -------------------------\n");
    printf("-------- 2.修改个人邮箱 -------------------------\n");
    printf("-------- 3.修改个人电话 -------------------------\n");
	printf("-------------------------------------------------\n");
	printf("选择你要更改的信息");
	scanf("%d",&choose);
    while(choose<1||choose>3)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——3）:");
	    scanf("%d",&choose);
    }
	switch(choose)//switch语句选择执行功能
    {
		case 2:		  
	        system("cls");      //清屏 
	        changeEmailS();      //调用更改Email函数  
	        break;
		case 1:
	        system("cls");      //清屏 
	        changePasswordS();   //调用  更改密码 函数 
			break;
		case 3:
	        system("cls");      //清屏 
	        changePhone();   //调用  更改电话 函数 
			break;
    }      
}
/********************************************************/
void studentFunction()  //功能选择函数
{   
    readTeacherInformation();    //读取文件里的教师信息
	readStudentInformation();    //读取文件中的学生信息    
	readLessonInformation();     //读取文件里的课程信息 
	system("cls");                         //清屏 
    printf("-------------------------------------------------\n");
    printf("-------- 1.根据课程名查询 -----------------------\n");
    printf("-------- 2.根据开课学院查询 ---------------------\n");
    printf("---------3.根据课余量排序所有课程----------------\n");
    printf("---------4.根据选课人数排序所有课程--------------\n");
    printf("---------5.查看曾经选修过的课程------------------\n");
    printf("---------6.删除选课结果--------------------------\n");
    printf("---------7.个人信息管理--------------------------\n");
    printf("---------8.退出到权限选择界面--------------------\n");
	printf("---------9.退出主程序----------------------------\n");
	printf("-------------------------------------------------\n");
    printf("请选择功能："); 
    scanf("%d",&choose);
    while(choose<1||choose>9)//容错  不在以上所列的功能以内时循环 
    { 
	    printf("输入的数字无效，请重新输入（1——9）:");
	    scanf("%d",&choose);
    }     
    switch(choose)                 //switch语句选择执行功能
    {
		case 1:		  
	        system("cls");         //清屏 
	        searchCourseName();    //调用  根据课程名称查询 函数 
	        chooseLessonFunction();
	        studentFunction();     //回到学生功能选择 
			break;
		case 2:
	        system("cls");         //清屏 
	        searchCollegeName();   //调用  根据开设学院查询 函数 
	        chooseLessonFunction();
	        studentFunction();     //回到学生功能选择 
			break;
		case 3:
	        system("cls");         //清屏 
	        orderRest();           //调用 根据课余量排序所有课程 函数 
	        chooseLessonFunction();
	        studentFunction();     //回到学生功能选择 
			break; 
		case 4:
	        system("cls");         //清屏 
	        orderNumber();         //调用 根据选课人数排序所有课程 函数 
	        chooseLessonFunction();
	        studentFunction();     //回到学生功能选择 
			break;
		case 5:
	        system("cls");         //清屏 
	        searchStudentC();      //调用  查看曾经选修过的课程 函数 
	        studentFunction();     //回到学生功能选择 
			break;
		case 6:
	        system("cls");         //清屏 
	        delCourse();           //调用  删除选课结果 函数 
			break;
        case 7:
	        system("cls");         //清屏 
	        changeStudent();           //调用  学生个人信息管理 函数 
			break;
		case 8:
	        system("cls");         //清屏 
	        competence();           //调用  权限界面 函数 
			break;
		case 9:
	        system("cls");         //清屏 
	        over();           //调用  结束主程序 函数 
			break;
    }
}
/********************************************************/
void competence()                  //选择权限函数 
{
	printf("------------------------------------------------------------\n");
    printf("------------------------------------------------------------\n");
    printf("-----------Student Course Management System-----------------\n");
    printf("---------------------1.Student------------------------------\n");
    printf("---------------------2.teacher------------------------------\n");
    printf("---------------------3.Exit------------------------------\n");
    printf("           Chooose your competence:");
	scanf("%d",&choose);
    while(choose<1||choose>3)      //不在以上所列的功能以内时循环
    { 
	    printf("输入的数字无效，请重新输入（1——2）:");
	    scanf("%d",&choose);
    }    
    switch(choose)   //switch语句选择执行功能
    {
        case 2:		  
	        system("cls");//清屏 
	        readTeacherInformation();    //读取文件里的教师信息
			readStudentInformation();    //读取文件中的学生信息    
	        readLessonInformation();     //读取文件里的课程信息 
			teacherL=teacherRegistration(); //反馈那位老师所在的行数 
	        teacherFunction();
	        break; 
        case 1:
	        system("cls"); //清屏
	        readStudentInformation();    //读取文件中的学生信息 
	        readLessonInformation();     //读取文件中的课程信息 
	        studentL=studentRegistration();  //反馈那位学生所在的行数 
	        studentFunction();   
			break; 
		case 3:
	        system("cls");         //清屏 
	        over();           //调用  结束主程序 函数 
			break; 
	}                       
}
/************************************************************/
int main()  //主函数 结构 
{
	competence();
	return 0;
}
