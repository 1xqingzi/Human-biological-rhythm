#include<stdio.h>
#include<math.h>


int main()
{
	printf("\t\t\t\t\t\t欢迎来到人体生物节律查询\n\n\n");
	
	//介绍人体生物节律中的周期日，高潮日，临界日，低潮日
	printf("介绍人体生物节律中的周期日，高潮日，临界日，低潮日!\n");
	printf(" 周期日：每个周期的开始日\t高潮期：能量释放的阶段\t临界日：高潮期和低潮日相互过渡是交替日子\t低潮日：能量蓄积补充阶段\n\n\n");
	
	//如何使用
	printf("如何使用？\n");
	printf("先输入要测定年月日，回车，再输入公历生日年月日，回车，再查询表格\n\n\n");

	int cyear,cm,cd;//测定年，月，日
	int byear,bm,bd;//出生年，月，日
	printf("输入测定年及具体日期（格式：例如，1993,12,3）：");
	scanf("%d,%d,%d",&cyear,&cm,&cd);
	printf("\n输入生日年及具体日期（格式：例如，1993,12,3）：");
	scanf("%d,%d,%d",&byear,&bm,&bd);

	//判断输入的年月日是否正确
	



	//y为测定年与生日年的差
	int y;
	y=(cyear-byear);
	
	//判断测定年至出身年中的润年数

	int i;//i为润年数
	for( i=0,byear;byear<=cyear;byear++)
	{
		if((byear%4==0&&byear%100!=0)||byear%400==0)
	  {
	 	i+=1;
	  }
		else i=i;
	
	}
	
	 //计算1月1日至测定日期的总天数

	int j,e;             //j为1月1日至测定年的日期的总天数,e为月份
	for(j=0,e=0;e<cm&&e<=12;e+=1)
	{ 
		
		
			if((e==1)||(e==3)||(e==5)||(e==7)||(e==8)||(e==10)||(e==12)) j+=31;
			if((e==4)||(e==6)||(e==9)||(e==11)) j+=30;
			if(e==2)
				{
					if((cyear%4==0&&cyear%100!=0)||cyear%400==0) j+=29;
				   else j+=28;
			    }
		
     }
	j=j+cd;
	
	//计算1月1日至出生年的日期的总天数

	int bdt,m;             //bdt为1月1日至出生年的日期的总天数,m为月份
	for(bdt=0,m=0;m<bm && m<=12;m+=1)
	{ 
		
		
			if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)) bdt+=31;
			if((m==4)||(m==6)||(m==9)||(m==11)) bdt+=30;
			if(m==2)
				{
					if((byear%4==0 && byear%100!=0)||byear%400==0) bdt+=28;
					else bdt+=29;
			    } 
		
     }
	 bdt=bdt+bd;




	//计算经历的总天数total days
	int totalday;
	totalday=y*365+i-bdt+j;
	
	
	//计算体力ps，情绪mood，智力inte的余数
	int ps,mood,inte;
	  ps=totalday%23;
	  mood=totalday%28;
	  inte=totalday%33;
	  printf("\n体力余数=%d\n,情绪余数=%d\n,智力余数=%d\n\n\n",ps,mood,inte);


	  //表
	  printf("请查如下表\n\n");
	  printf("节律\t\t周期日\t\t高潮日\t\t临界日\t\t低潮期\n");
	  printf("体力节律\t余数等于0\t余数小于12\t余数等于12\t余数大于12\n");
	  printf("情绪节律\t余数等于0\t余数小与14\t余数等于14\t余数大于14\n");
	  printf("智力节律\t余数等于0\t余数小与17\t余数等于17\t余数大于17\n");
}