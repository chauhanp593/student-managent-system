#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//password =bitcs@123
struct student
{ long long int roll,mob;
  int year;
  float fees,percent;
  char firstn[20],lstname[20],course[10];
}s1,stu1;
FILE *stu,*op, *search, *dp,*pwd;
int f,j=0,k,length,i,n,p; 
char ch; 
long long int getroll,temp1,B[100]; 
float A[100],temp;

struct pwd 
{
char password[10],gpassword[10],cpassword[10];
}p1,p2;
//FUNCTION TO GET STUDENT INFORMATIONS

void getdata()
{ system("cls");
  printf("\n\n\t\t\t\t\t\t:: RECORD ENTRY SECTION ::");
  printf("\n\tEnter Roll Number -"); scanf("%lli",&s1.roll);
  printf("\n\tEnter First Name -"); scanf("%s",&s1.firstn);
  printf("\n\tEnter Last Name -"); scanf("%s",&s1.lstname);
  printf("\n\tEnter Course -"); scanf("%s",&s1.course);
  printf("\n\tEnter Year-");scanf("%d",&s1.year);
  printf("\n\tEnter fees -");scanf("%f",&s1.fees);
  printf("\n\tEnter Percent -"); scanf("%f",&s1.percent);
  printf("\n\tEnter Mobile Number -"); scanf("%lli",&s1.mob);
  printf("\n\tPress 'A' or 'a' to add more or Press 'm' or 'M' for main menu....");
  scanf("%s",&ch);
  stu= fopen("ab.txt","a+");
  fwrite (&s1,sizeof(struct student),1,stu);
  fclose(stu);
 }
//FUNCTION TO SHOW STUDENT INFORMATIONS
 void display()
 { system("cls");
   k=1;
   printf("\n\n\n\t\t\t\t\t\t:: STUDENT INFORMATION ::\n");
   op =fopen("ab.txt","r+"); f=1;
   printf("S.No  Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No.");
   printf("\n");
   while(fread(&stu1,sizeof(struct student),1,op)==1)
   { printf("%-6d",k++);
     printf("%-15lli", stu1.roll);
     printf("%-17s", stu1.firstn);
    printf("%-16s", stu1.lstname);
    printf("%-13s",stu1.course);
    printf("%-12d",stu1.year);
    printf("%-15.2f", stu1.fees);
    printf("%-13.2f",stu1.percent);
    printf("%-13lli\n",stu1.mob);
    f=0;
   } 
   if(f==1)
   {
   printf("\n\n\n \t\t\tNO RECORD FOUND...!!!");
   }
   printf("\n\n\n \t\t\tPress Any Key For MAIN MENU...");
   getch();
   fclose(op);
 }
 
 
 //FUNCTION TO SEARCH A STUDENT'S INFORMATION
 void searching()
 { system("cls");
   printf("\n\n\n\t\t\t\t\t\t:: SEARCHING SECTION ::\n");
   printf("\n Enter Roll No to Search=");
   scanf("%lli",&getroll);
   f=0;
   search =fopen("ab.txt","r+"); 
   printf("\n");
   while(fread(&stu1,sizeof(struct student),1,search)==1)
   {if(stu1.roll==getroll) 
   {printf("Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No."); 
    printf("\n%-15lli", stu1.roll);
    printf("%-17s", stu1.firstn);
    printf("%-16s", stu1.lstname);
    printf("%-13s",stu1.course);
    printf("%-12d",stu1.year);
    printf("%-15.2f", stu1.fees);
    printf("%-13.2f",stu1.percent);
    printf("%-13lli\n",stu1.mob);
    printf("\n\n\n \t\t\tPress Any Key For MAIN MENU...");
    f=1;
    getch();
    break;
   }
   }
   if(f==0)
   { system("color 4F");
   printf("\n\n\n\t\t\t Record not found...!!!!");
   printf("\n\n\n \t\t\tPress Any Key For MAIN MENU...");
   getch();
   }  
   fclose(op);
 }

//FUNCTION TO DELETE A STUDENT INFORMATION
 void deleting()
 { stu = fopen("ab.txt","r+");
   dp = fopen("new.txt","a+");
   system("cls");
   printf("\n\n \t\t\t\t\t\t:: DELETION SECTION ::\n");
   printf("\nEnter the Roll No to be deleted=");
   scanf("%lli",&getroll);
   f=2;
   while(fread(&stu1,sizeof(struct student),1,stu)==1)
   { if(stu1.roll!=getroll)
      { 
	  fwrite(&stu1,sizeof(struct student),1,dp);
      }
	  else
	  {printf("Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No."); 
       printf("\n%-15lli", stu1.roll);
       printf("%-17s", stu1.firstn);
       printf("%-16s", stu1.lstname);
       printf("%-13s",stu1.course);
       printf("%-12d",stu1.year);
       printf("%-15.2f", stu1.fees);
       printf("%-13.2f",stu1.percent);
       printf("%-13lli\n",stu1.mob);
       f=1;
	  }    
   }
   fclose(stu);
   fclose(dp);
   remove("ab.txt");
   rename("new.txt","ab.txt");
   if(f==1)
   printf("\n\n \t\t\t Deleted Successfully...");
   else
   { system("color 4F");
     printf("\n\n \t\t\t Record not found...");
   }
   printf("\n\n \t\t\t Press Any Key For MAIN MENU....");
   getch(); 
 }
 
 //FUNCTION TO EDIT A STUDENT'S INFORMATION
 void modify()
 { stu = fopen("ab.txt","r+");
   dp = fopen("new.txt","a+");
   system("cls");
   printf("\n\t\t\t\t:: RECORD MODIFICATION SECTION ::\n\n");
   printf("\nEnter the Roll No to Edit Record=");
   scanf("%lli",&getroll);
   f=0;
   while(fread(&stu1,sizeof(struct student),1,stu)==1)
   { if(stu1.roll==getroll)
     {printf("Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No."); 
      printf("\n%-15lli", stu1.roll);
      printf("%-17s", stu1.firstn);
      printf("%-16s", stu1.lstname);
      printf("%-13s",stu1.course);
      printf("%-12d",stu1.year);
      printf("%-15.2f", stu1.fees);
      printf("%-13.2f",stu1.percent);
      printf("%-13lli\n",stu1.mob);
      printf("\t\t\t\t\t\t:: RECORD ENTRY SECTION ::");
        printf("\n\tEnter Roll Number -"); scanf("%lli",&stu1.roll);
      printf("\n\tEnter First Name -"); scanf("%s",&stu1.firstn);
      printf("\n\tEnter Last Name -"); scanf("%s",&stu1.lstname);
      printf("\n\tEnter Course -"); scanf("%s",&stu1.course);
      printf("\n\tEnter Year-");scanf("%d",&stu1.year);
      printf("\n\tEnter fees -");scanf("%f",&stu1.fees);
      printf("\n\tEnter Percent -"); scanf("%f",&stu1.percent);
      printf("\n\tEnter Mobile Number -"); scanf("%lli",&stu1.mob);
      fwrite(&stu1,sizeof(struct student),1,dp);
      f=1;
     }
      else
      fwrite(&stu1,sizeof(struct student),1,dp);
   }
   fclose(stu);
   fclose(dp);
   remove("ab.txt");
   rename("new.txt","ab.txt");
    if(f==1)
	printf("\n\n \t\t\t Updated Successfully...");
	else
	{ system("color 4F");
	  printf("\n\t\t\tRECORD NOT FOUND");
	}
    printf("\n\n\n \t\t\t Press Any Key For MAIN MENU....");
   getch();
 }
 
 //FUNCTION TO SORT STUDENT INFORMATIONS BY PERCENTAGE
void sorting()
 { stu = fopen("ab.txt","r+");
   system("cls");
   printf("\n\t\t\t\t:: RECORDS SORTED BY PERCENTAGE ::\n\n");
   while(fread(&stu1,sizeof(struct student),1,stu)==1)
   {  A[j]=stu1.percent;
      j++;
   }
   length=j;
  for( i=0;i<length-1;i++)
  {for( j =0;j<length-1-i;j++)
    { if(A[j]<A[j+1])
     { temp=A[j];
      A[j]=A[j+1];
      A[j+1]=temp;
     }
    }
   }
   k=1;
for( i=0;i<length;i++)
  { fseek(stu,0,SEEK_SET);
    while(fread(&stu1,sizeof(struct student),1,stu)==1)
   { if(A[i]==stu1.percent)
     {  
       if(i==0)
	   {
	   printf("S.No  Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No.\n\n");
       }
       printf("%-6d",k++);
       printf("%-15lli", stu1.roll);
       printf("%-17s", stu1.firstn);
       printf("%-16s", stu1.lstname);
       printf("%-13s",stu1.course);
       printf("%-12d",stu1.year);
       printf("%-15.2f", stu1.fees);
       printf("*%-12.2f",stu1.percent);
       printf("%-13lli\n",stu1.mob);
      }      
    } 

   }
    fclose(stu);    printf("\n\n\n \t\t\tPress Any Key For MAIN MENU...");

   getch(); 
 }
 
 //FUNCTION TO SORT STUDENTS INFORMATIONS BY ROLL
 void sorting1()
 { stu = fopen("ab.txt","r+");
   system("cls");
   printf("\n\t\t\t\t\t\t:: RECORDS SORTED BY ROLL ::\n\n");
   while(fread(&stu1,sizeof(struct student),1,stu)==1)
   {  B[j]=stu1.roll;
      j++;
   }
   length=j;
  for( i=0;i<length-1;i++)
  {for( j =0;j<length-1-i;j++)
    { if(B[j]>B[j+1])
     { temp1=B[j];
      B[j]=B[j+1];
      B[j+1]=temp1;
     }
    }
   }
   k=1;
for( i=0;i<length;i++)
  { fseek(stu,0,SEEK_SET);
    while(fread(&stu1,sizeof(struct student),1,stu)==1)
   { if(B[i]==stu1.roll)
      {   
        if(i==0)
	     {
	      printf("S.No  Roll no        First Name       Last Name       Course       Year        Fees           Percentage   Mobile No.\n\n");
         }
          printf("%-6d",k++);
          printf("%-15lli", stu1.roll);
          printf("%-17s", stu1.firstn);
          printf("%-16s", stu1.lstname);
          printf("%-13s",stu1.course);
          printf("%-12d",stu1.year);
          printf("%-15.2f", stu1.fees);
          printf("%-13.2f",stu1.percent);
          printf("%-13lli\n",stu1.mob);
      }      
    } 

   }
   fclose(stu);
   printf("\n\n\n \t\t\tPress Any Key For MAIN MENU...");
   getch(); 
 }
void changepwd(); 
void menu()
   {
     start :
     system("cls");
     system("color fc");
     printf("\n \t\t\t\t\t-------------------------------\n");
     printf(" \t\t\t\t\t|           RECORD SECTON      |\n");
     printf(" \t\t\t\t\t-------------------------------\n");
   printf("\t1. ADD RECORD.\n");
   printf("\t2. VIEW RECORD.\n");
   printf("\t3. SEARCH.\n");
   printf("\t4. DELETE A RECORD.\n");
   printf("\t5. Modify A RECORD.\n");
   printf("\t6. View RECORD sorted by Marks.\n");
   printf("\t7. View RECORD sorted by Roll.\n");
   printf("\t8. EXIT.\n");
   printf("\t9. CHANGE ADMINSTRATION PASSWORD.\n");
   printf("\n \t ENTER YOUR CHOICE HERE = ");
   scanf("%d",&n);
   switch(n)
   { case 1: system("color fc");  start2 :
             getdata(); 
             if(ch=='M'||ch=='m')
             goto start;
             else
             goto start2;
     case 2: system("color fc");
	         display();
             goto start; 
     case 3: searching();
             goto start;
             
     case 4: deleting();
             goto start;
     case 5: modify();
	         goto start;
     case 6: sorting();
	         goto start;
     case 7: sorting1();
	         goto start;
     case 8: exit(0);        
     case 9: changepwd();
             goto start;
     default : system("color 4F");
	           printf("\n\n\n \t\t\t WRONG INPUT!!!! Press ENTER to input again...\n");
               getch();
               goto start;        
   }
}
 void changepwd()
 { p=0;
   startcp:
   system("cls");
   system("color fc");
   p++; 
   printf("\n\n \t\t\t\t CHANGING PASSWORD \n\n");
   strcpy(p2.password,"bitcs@123");
   pwd=fopen("pwd.dat","rb");
   fread(&p2,sizeof(struct pwd),1,pwd);
   printf("\n\n\n\n \t\t\t Enter Old password=");
   scanf("%s",&p1.gpassword);
   fclose(pwd);
   if(strcmp(p2.password,p1.gpassword)==0)
    { p=0;
      start3:
      if(p!=0)	
      system("cls");
	  printf("\n\n\n\n \t\t\t Enter New password(upto 10 char)=");
      scanf("%s",&p1.password);
      printf("\n \t\t\t Confirm New password(upto 10 char)=");
      scanf("%s",&p1.cpassword);
      if(strcmp(p1.password,p1.cpassword)==0)
      { printf("\n \t\t\t Password Changed Succesfully...(^.^)");
      pwd=fopen("pwd.dat","wb");
      fwrite(&p1,sizeof(struct pwd),1,pwd);
	  fclose(pwd);
	  getch();      
        menu();
	  }
	  else
	  { system("color 4F");
	    printf("\n\n \t\t\t Enter password again!!! confirm password in diffrent..\n");
	    printf("\t\t\t Press Enter to contine");
	    getch();
	    goto start3;
      }
	}
   else if(p<3)
   { system("color 4f");
     printf("\n\n WRONG PASSWORD %d ATTEMPT LEFT!! PRESS ENTER TO RETRY...",3-p);
     getch();
     goto startcp;
    }
   else
   exit(0);
 }

int passwrd()
{  p=0;
   startp:
   system("cls");
   system("color fc");
   p++; 
   printf("\n \t\t\t\t\t-------------------------------\n");
   printf(" \t\t\t\t\t|    WElCOME to DATABASE      |");
   printf("\n \t\t\t\t\t-------------------------------\n");
   strcpy(p2.password,"bitcs@123");
   pwd=fopen("pwd.dat","rb");
   fread(&p2,sizeof(struct pwd),1,pwd);
   printf("\n\n\n\n \t\t\t Enter password=");
   scanf("%s",&p1.gpassword);
   if(strcmp(p2.password,p1.gpassword)==0)
    menu();
   else if(p<3)
   { system("color 4f");
     printf("\n\n WRONG PASSWORD %d ATTEMPT LEFT!! PRESS ENTER TO RETRY...",3-p);
     getch();
     goto startp;
    }
   else
   exit(0);       
}

int main()
{   passwrd();   
}
