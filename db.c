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
		printf("1 - Добавить данные\n2 - Посмотреть базу данных\n3 - редактировать даннные\n4 - Выход\n");
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
		printf("1 - Создать новый файл\n2 - Добавить в существующий\n");
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
   		 	printf("Колличество студентов: ");
    		scanf("%d",&n);
			for(i=0; i<n; i++)
        	{
	    		printf("Фамилия: ");
	    		scanf("%s", std.name);
	    		printf("Год рождения: ");
	    		scanf("%s", std.year);
    			printf("Факультет: ");
    			scanf("%s", std.fac);
    			printf("Группа: ");
    			scanf("%s", std.group);
    			printf("Статус поступления: ");
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
	printf("1 - Редактировать информацию о студенте\n2 - Удалить информацию о студенте\n");
	f = fopen("database.txt", "r+");
	scanf("%d", &a);
	do
	{
		switch(a)
		{
			case 1: 
				printf("Введите фамилию студента\n");
				scanf("%s", name);	
				while(!feof(f))
				{
					if(fread(&std,sizeof(stud),1,f))
					{
						if (strcmp (name,std.name) == 0)
						{
							printf("что менять?\n1 - год рождения\n2 - Факультет\n3 - Группа\n4 - Статус поступления\n5 - назад");
							scanf("%d", &b);
							switch(b) {
								case 1:
									printf("Год рождения: ");
									scanf("%s", std.year);
									fwrite(&std,sizeof(stud),1,f);
								break;
								case 2:
									printf("Факультет: ");
			            			scanf("%s", std.fac);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 3:
			            			printf("Группа: ");
	            					scanf("%s", std.group);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 4:
			            			printf("Статус поступления: ");
			            			scanf("%s", std.status);
			            			fwrite(&std,sizeof(stud),1,f);
								break;
								case 5:
									continue;
								break;
							}
						}
						else printf("Нет такого студента в базе данных\n");
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