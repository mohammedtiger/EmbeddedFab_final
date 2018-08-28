

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME_SIZE   		10
#define MAX_EMPOLYEE	   		10

enum
{
	EMPOLYEE_1,
	EMPOLYEE_2,
	EMPOLYEE_3,
	EMPOLYEE_4,
	EMPOLYEE_5,
	EMPOLYEE_6,
	EMPOLYEE_7,
	EMPOLYEE_8,
	EMPOLYEE_9,
	EMPOLYEE_10,
};


typedef struct data Data_t;
struct data
{

	char name[MAX_NAME_SIZE];
	int salary ;
	int id ;




};

typedef struct company Company_t;

struct company
{
	Data_t *Emp;
	void (*print)(Company_t *);
	void (*scan)(Company_t *);
};


void printname(Company_t *user);
void scanname(Company_t *user);

void init_company(Company_t *user , int size);



Company_t ALI;

int main(void) {







	return EXIT_SUCCESS;
}




void init_company(Company_t *user , int size)
{
	for(int index = 0 ; index <MAX_EMPOLYEE ; index ++)
	{
		if(user)
		{
			user->Emp = (Data_t *) malloc (size * sizeof(Data_t));
			user->scan = scanname;
			user->print = printname;

			for(int index = 0; index < MAX_NAME_SIZE ; index ++)
			{
				memset(user->Emp[index].name , 0 , MAX_NAME_SIZE);
			}
		}
	}


}

void scanname(Company_t *user)
{

	for(int index_1 = 0 ; index_1 < MAX_EMPOLYEE ; index_1 ++)
	{
		for(int index = 0 ; index < MAX_NAME_SIZE ; index ++)
		{
			scanf("%c" , &user->Emp[index_1].name[index]);
			if(user->Emp[index_1].name[index] == '\n')
			{
				break;
			}
		}
	}
}

void printname(Company_t *user)
{
	for (int index_1 = 0 ; index_1 < MAX_EMPOLYEE ; index_1++)
	{
		printf("%s" , user->Emp[index_1].name);
	}
}
