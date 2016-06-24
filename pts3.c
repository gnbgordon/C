#include  "stdio.h"
main()
{
		int week=0, day, month=1 , MAX_DAY, year, i;
 	printf("请输入四位数的年份(XXXX):");
 	scanf("%d",&year);
 	printf("\n请输入该年元旦是星期几(0=星期天，1=星期一...6=星期六)：");
 	scanf("%d",&week);
 	printf("\n**********%4d年日历*********",year);
 	while (month <=12)
		{	
			switch (month)
			{   
				case 1: case 3:	case 5: case 7: case 8:	case 10: case 12:
						MAX_DAY = 31;	                 /* 大月 */
 						break;
 				case 2:									 /* 2月 */
 				       if (((year % 4)==0) && ((year % 100)!=0)
						 ||((year % 400)==0))MAX_DAY = 29;/* 闰年 */
 						else                 MAX_DAY = 28;/* 平年 */
 						break;
 				case 4:  case 6:  case 9:  case 11:
 						MAX_DAY = 30;			         /* 小月 */
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