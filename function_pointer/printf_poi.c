// Q. HOW TO CALL PRINTF AND SCANF FUNCTION USING FUNCTION POINTER 
#include<string.h>
#include<stdio.h>
int main()
{
	int i;
	char s[100];
	float f=10.20;

	// printf 
	int (*p)(const char *,...)=printf;	// initilizing printf fun using fun pointer 
	printf("Through normal printf call -->Vijay Magadum\n");
	//p=printf;
	(*p)("Through fun pointer -->Vijay magadum\n");

	// scanf 
	int (*q)(const char *,...)=scanf;    // initilization scanf fun using fun pointer 
	p("Enter the in value\n");
	(*q)("%d",&i);	// calling scanf fun using fun pointer 
	printf("i=%d\n",i);

	// sprintf 
	char s1[100];
	int (*sf)(char *,const char *,...)=sprintf;
	(*p)("Enter the string \n");
	(*q)("%s",s);
	(*sf)(s1,"%d %s %f\n",i,s,f);
	printf("sprintf : %s\n",s1);

	// strlen 
	int l;
	char s3[50];
	size_t (*sl)(const char *)=strlen;
	(*p)("Enter the string \n");
	(*q)("%s",s3);
	l=(*sl)(s3);
	(*p)("String length : %d\n",l);

	// strcpy 
	char sr[50],dr[50];
	char * (*cp)(char *,const char *)=strcpy;
	(*p)("Enetr the source string \n");
	(*q)("%s",sr);
	(*cp)(dr,sr);
	(*p)("strcpy :  %s\n",dr);

	// strncpy
	int n;
	char s4[50],s5[50];
	char * (*spn)(char *,const char *,size_t )=strncpy;
	(*p)("Enter the source string and size to be copy \n ");
	(*q)("%s",s4);
	(*q)("%d",&n);
	(*spn)(s5,s4,n);
	(*p)("strncpy : %s\n",s5);

	// strcat
char s6[50],s7[50];
char * (*strc)(char *,const char *)=strcat;
(*p)("Enter the string 1\n");
(*q)("%s",s6);
(*p)("Enter the string 2\n")	;
(*q)("%s",s7);
(*strc)(s7,s6);
(*p)("strcat : %s",s7);


}
