#include <string.h>
#include <stdio.h>
#include <string.h>

struct stud
	{
		char name[15], year[15], fac[15], group[15], status[15];
	};

void newdatabase();

void showdatabase();

void editdatebase();

int main() 
{
	int a;
	do
	{
		printf("1 - �������� �����\n2 - ��ᬮ���� ���� ������\n3 - ।���஢��� ������\n4 - ��室\n");
		scanf("%d",  &a);
		switch(a)
			{
				case 1: newdatabase(); break;
				case 2: showdatabase(); break;
				case 3: editdatebase(); break;
				case 4: break;
			}
	}
	while(a > 4);		
	return 0; 

}	

void newdatabase()
{
	FILE *f;
	struct stud std;
	char ptext[15];
	int i, n, a;
	do
	{
		printf("1 - ������� ���� 䠩�\n2 - �������� � �������騩\n");
		scanf("%d", &a);
		if(a < 1 || a > 2)
			continue;
		if (a == 1)
		{
			f = fopen("database.txt", "w+"); 
		}
		if (a == 2)
		{
			f = fopen("database.txt", "a+"); 
		}
   		 	printf("�������⢮ ��㤥�⮢: ");
    		scanf("%d",&n);
			for(i=0; i<n; i++)
        	{
	    		printf("�������: ");
	    		scanf("%s", std.name);
	    		printf("��� ஦�����: ");
	    		scanf("%s", std.year);
    			printf("�������: ");
    			scanf("%s", std.fac);
    			printf("��㯯�: ");
    			scanf("%s", std.group);
    			printf("����� ����㯫����: ");
    			scanf("%s", std.status);
    			fwrite(&std,sizeof(stud),1,f);
    			printf("_____________________\n");
    		}
            break;
    }
    while(1);        	    	
    fclose(f);
}

void showdatabase()
{
	struct stud std;
	FILE *f;
	f = fopen("database.txt", "r"); 
	while(!feof(f))
	{
		if(fread(&std,sizeof(stud),1,f))
		{
			printf("%s|%s|%s|%s|%s|\n", std.name, std.year, std.fac, std.group, std.status);
		}
	}	
	printf("_________________________________________________\n");	
	fclose(f);
}

void editdatebase()
{
	struct stud std;
	char name[15];
	FILE *f;
	int a, b;
	printf("1 - ������஢��� ���ଠ�� � ��㤥��\n2 - ������� ���ଠ�� � ��㤥��\n");
	f = fopen("database.txt", "r+");
	scanf("%d", &a);
	do
	{
		switch(a)
		{
			case 1: 
				printf("������ 䠬���� ��㤥��\n");
				scanf("%s", name);	
				while(!feof(f))
				{
					if(fread(&std,sizeof(stud),1,f))
					{
						if (strcmp (name,std.name) == 0)
						{
							printf("�� ������?\n1 - ��� ஦�����\n2 - �������\n3 - ��㯯�\n4 - ����� ����㯫����\n5 - �����");
							scanf("%d", &b);
							switch(b) {
								case 1:
									printf("��� ஦�����: ");
									scanf("%s", std.year);
									fwrite(&std,sizeof(stud),1,f);
								break;
								case 2:
									printf("�������: ");
			            			scanf("%s", std.fac);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 3:
			            			printf("��㯯�: ");
	            					scanf("%s", std.group);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 4:
			            			printf("����� ����㯫����: ");
			            			scanf("%s", std.status);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 5:
									continue;
								break;
							}
						}
						else printf("��� ⠪��� ��㤥�� � ���� ������\n");
					}
				}		
			break;
			case 2: 

			break;
		}
	}
	while(a > 3);
	fclose(f);
}