/*
	Name: 密码生成器 
	Copyright: 
	Author: 折竹子 
	Date: 03/11/19 12:09
	Description: 1.0
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
 
#define  number_start  		0
#define  number_end    		9
#define  big_letter_start 	10
#define  big_letter_end 	35
#define  small_letter_start 36
#define  small_letter_end   61
#define  character_start    62
#define  character_end      69
#define  min_len            4
#define  max_len            256
 
char pwdch[]={
	'0','1','2','3','4','5','6','7','8','9',
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','a','b','c','d',
	'e','f','g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v','w','x',
	'y','z','!','@','#','$','%','^','&','*'
};//密码字符库
 
/*随机界限判断*/
void passwordStartEnd(int *start,int *end,int number,int big_letter,int small_letter,int character)
{
	if(0==(number||big_letter||small_letter||character))
	{
		printf("错误,没有所选字符");		
	}
	/*选择最小随机数*/
	if(number)
	{
		*start=number_start;	
	}
	else if(big_letter)
	{
		*start=big_letter_start;
	}
	else if(small_letter)
	{
		*start=small_letter_start; 
	}
	else
	{
		*start=character_start;
	}
	/*选择最大随机数*/
	if(character)
	{
		*end=character_end;	
	}
	else if(small_letter)
	{
		*end=small_letter_end;
	}
	else if(big_letter)
	{
		*end=big_letter_end;
	}
	else
	{
		*end=number_end;
	}
	/*
		由于前期的不合理设计造成代码结构混乱 
	*/ 
 
}
char *runPassword(int number,int big_letter,int small_letter,int character,int password_len)
{
	Sleep(1000);
	/*参数的合理性检测*/
	if(password_len>max_len)
	{
		printf("密码的长度超过最大限制\n");
	}
	if(password_len<min_len)
	{
		printf("密码的长度低于最小限制\n");	
	}
	int start,end;//求取随机数的上下界
	passwordStartEnd(&start,&end,number,big_letter,small_letter,character);//寻找范围 
	srand((unsigned)time(NULL));//置随机数种子
	int random;
	char pwdstring[password_len+1]={0};
	for(int i=0;i<password_len;i++)
	{
		do{
			random=rand()%(end-start+1)+start;//生成随机密码
		}while(
			!(
			number&&number_start<=random&&random<=number_end||
			big_letter&&big_letter_start<=random&&random<=big_letter_end||
			small_letter&&small_letter_start<=random&&random<=small_letter_end||
			character&&character_start<=random&&random<=character_end
			)
		);
		pwdstring[i]=pwdch[random]; 
	}
	printf("%s\n",pwdstring);
	return pwdstring;	
} 
int main()
{
	for(int i=0;i<10;i++)
	{
		runPassword(true,true,true,true,256); 
	}
 
	return 0;
} 
