#include  "stdio.h"
main()
{
		int week=0, day, month=1 , MAX_DAY, year, i;
 	printf("��������λ�������(XXXX):");
 	scanf("%d",&year);
 	printf("\n���������Ԫ�������ڼ�(0=�����죬1=����һ...6=������)��");
 	scanf("%d",&week);
 	printf("\n**********%4d������*********",year);
 	while (month <=12)
		{	
			switch (month)
			{   
				case 1: case 3:	case 5: case 7: case 8:	case 10: case 12:
						MAX_DAY = 31;	                 /* ���� */
 						break;
 				case 2:									 /* 2�� */
 				       if (((year % 4)==0) && ((year % 100)!=0)
						 ||((year % 400)==0))MAX_DAY = 29;/* ���� */
 						else                 MAX_DAY = 28;/* ƽ�� */
 						break;
 				case 4:  case 6:  case 9:  case 11:
 						MAX_DAY = 30;			         /* С�� */
 						break;
 			}
printf(" \n==========%2d month ==========\n",month);
 		printf(" SUN MON TUE WED TUR FRI SAT\n");
			for(i=0; i<week; i++)printf("%4c",' ');
for(day=1;day<=MAX_DAY; day++)
		{   printf("%4d",day);
			week++; week %= 7;
			if(week == 0)printf("\n");
		}
		    month++;
 	    }
	}