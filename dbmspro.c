#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fields{
        char batch_no[100];
        char product_name[100];
        int price;
        int quantity_per_carton;
        int carton_in_stock;
        char manufacturing_date[50];
        char expiry_date[50];
        char manufacturer[100];
        char schedule[10];
};

main()
{
	int i;
	FILE *fp;
	struct fields f[200];

	if ( (fp = fopen("data.txt", "r")) == NULL )
	{
		printf("No such file\n");
		return;	
	}

	for (i=0 ; i<14; i++)
	{
		fscanf(fp,"%s    %s    %d    %d    %d    %s    %s    %s    %s",f[i].batch_no,f[i].product_name,&f[i].price,&f[i].quantity_per_carton,&f[i].carton_in_stock,f[i].manufacturing_date,f[i].expiry_date,f[i].manufacturer,f[i].schedule);
	}


	printf("\n");
	printf("TELL ME SCHEDULE 'H' DRUG\n");
	printf("__________________________\n");
	printf("Batch_No                       Product_Name                     Price   QiC     CiS     Mfg_date        Exp._Date           Manufacturer\n");	
	for (i=0; i<14; i++)
	{	
		if(strcmp(f[i].schedule,"H") == 0)
		{
			printf("%s	%s	%d	%d	%d	%s	%s	%s\n",f[i].batch_no,f[i].product_name,f[i].price,f[i].quantity_per_carton,f[i].carton_in_stock,f[i].manufacturing_date,f[i].expiry_date,f[i].manufacturer);
		}
	}
}
