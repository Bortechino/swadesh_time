/*
 * counter_swadesh_time_release_v-01_.c
 *
 * Copyright 2019 Axel Wintermann aka Bortechino <bortechino@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define filenameF "lat-yakh" //область задания 
#define filenameS "eng-yakh" //файлов языков

int main()
{
 /*******************************************************************
 * **********Инициализация переменных********************************
 * ******************************************************************/
    FILE  *fpF, *fpS;
    int i, inumF, inumS, cnt_wordsF, cnt_wordsS, iF, cF, iS, cS;
    i=inumF=inumS=cnt_wordsF=cnt_wordsS=iF=cF=iS=cS=0;
    cnt_wordsF = cnt_wordsS = 0;
    float countdF[27] = {0};
    float countdS[27] = {0};
    float countFS[27] = {0};
    float countSS[27] = {0};
    float countFF[27] = {0};
    float  sumF, sumS, sumFS, sumSS, sumFF, num, deno, correlation;
    sumF = sumS = sumFS = sumSS = sumFF = num = deno = correlation=0.0;
    int countF[27] = {0};
    char chF, chS;
    chF= 0;
    chS= 0;
    const float N0=100.0;
    int countS[27] = {0};
    double  meanF, meanS, sumS1, sumF1, varianceF, varianceS,SDS, SDF;
    meanF = sumF1 = varianceF = SDF = varianceS=SDS=sumS1=0.0;
    double  swodesh_time;
    const double Lcoeff=0.05;
    swodesh_time=0.0;
 /******************************************************************
 * **********Область задания списка фонем***************************
 * *****************************************************************/
    const char Alpha[27] = "abcdefghijklmnopqrstuvwxyz"; 
    //const char Alpha[27] = "bcdfghjklmnpqrstvwxz";
    int strlen_alpha;
    strlen_alpha=0.0;
    strlen_alpha= strlen(Alpha);
    printf ("число букв в строке %s равно %d\n",Alpha, strlen_alpha);
/*********************************************************************
************Раздел обработки первого файла****************************
*********************************************************************/
    printf("File First\n");
    fpF = fopen(filenameF,"r");
     if(fpF == NULL){
        printf("файл filenameF не найден: exit\n");
          return 1;
	  }
    inumF=0;
       while ( (chF = fgetc(fpF))!= EOF)
       {
		   if(chF!='\n')
		   {
		   inumF++;
		 //  printf("%c = %d\n",chF, inumF);
		   }
	   }
       fseek (fpF, 0L,  SEEK_SET);
          while(fscanf(fpF, "%*[^\n]%*c") != EOF)
                     cnt_wordsF++;
        fseek (fpF, 0L,  SEEK_SET);

    while( (chF = fgetc(fpF)) != EOF)
     {
        cF = 0;
        while(Alpha[cF] != '\0')
        {
            if(Alpha[cF] == chF)
            {
                countF[cF]++;
                }
            cF++;
        }
    }
    for(iF = 0; iF<strlen_alpha;iF++)
    {
		countdF[iF]=countF[iF]/(float)inumF;
  //      printf("буква %c найдена %d раз в списке из %d букв %d словах\n",alpha[iF], countF[iF], inumF,cnt_wordsF);
    }
    fclose (fpF);
    for(iF = 0; iF<=strlen_alpha;iF++)
    {
		sumF+=countdF[iF];
	}
 //   printf("sumF = %0.9f\n",sumF);
    meanF=sumF/(float)cnt_wordsF;
//    printf("meanF = %2.9f\n",meanF);
    for(iF=0; iF<cF; iF++)
    {
		sumF1 = sumF1 + pow((countF[iF] - meanF),2);
		}
		varianceF = sumF1 / (float)cnt_wordsF;
		SDF = sqrt(varianceF);
		printf("Дисперсия по всем элементам файла = %.9f\n", varianceF);
		printf("Стандартное отклонение = %.9f\n", SDF);
/********************************************************************
*********Раздел обработки второго файла******************************
********************************************************************/
     printf("File Second\n");

    fpS = fopen(filenameS,"r");

    if(fpS == NULL)
    {
                printf("Файл filenameS не найден: exit\n");
          return 1;
	  }
        inumS=0;
       while ( (chS = fgetc(fpS))!= EOF)
       {
		   if(chS!='\n')
		   {
		   inumS++;
//		   printf("%c = %d\n",chS, inumS);
		   }
	   }
       fseek (fpS, 0L,  SEEK_SET);
          while(fscanf(fpS, "%*[^\n]%*c") != EOF)
                     cnt_wordsS++;
        fseek (fpS, 0L,  SEEK_SET);
        while( (chS = fgetc(fpS)) != EOF)
        {
			cS = 0;
			while(Alpha[cS] != '\0')
			{

            if(Alpha[cS] == chS)
            {
                countS[cS]++;
            }
            cS++;
        }
    }
    for(iS = 0; iS<strlen_alpha;iS++)
    {
		countdS[iS]=countS[iS]/(float)inumS;
 //       printf("буква %c найдена %d раз в списке из %d букв %d словах\n",alpha[iS], countS[iS], inumS,cnt_wordsS);
    }
    fclose (fpS);
    for(iS = 0; iS<=strlen_alpha;iS++)
    {
		sumS+=countdS[iS];
	}
  //  printf("sumS = %0.9f\n",sumS);
    meanS=sumS/(float)cnt_wordsS;
  ///  printf("meanS = %2.9f\n",meanS);
    for(iS=0; iS<cS; iS++)
    {
		sumS1 = sumS1 + pow((countS[iS] - meanS),2);
		}
		varianceS = sumS1 / (float)cnt_wordsS;
		SDS = sqrt(varianceS);
		printf("дисперсия по всем элементам = %.9f\n", varianceS);
		printf("стандартное отклонение = %.9f\n", SDS);
/***********************************************************************
 * ***********************Вычисление корреляции*************************
 * ********************************************************************/
  for (i = 0; i <=strlen_alpha;i++)
  {
	  countFS[i]=countdS[i]*countdF[i];
	  countSS[i]=countdS[i]*countdS[i];
	  countFF[i]=countdF[i]*countdF[i];
	  sumFS=sumFS+countFS[i];
	  sumSS=sumSS+countSS[i];
	  sumFF=sumFF+countFF[i];
//	  printf ("countS[i]=%d,countF[i]=%d,countFS[i]=%0.9f\n", countS[i],countF[i],countFS[i]);
  }
  num = 1.0 * ((strlen_alpha * sumFS) - (sumS * sumF));
  deno = 1.0 * ((strlen_alpha * sumSS - sumS * sumS)*(strlen_alpha * sumFF - sumF * sumF));
  correlation = num/deno;
  printf ("sumS=%0.9f, sumF=%0.9f\n",sumS,sumF);
  printf (" ковариация =%0.9f, deno=%0.9f, корреляция = %0.9f\n", num, deno, correlation);
/********************************************************************
*********Вычисление по формуле Сводеша*******************************
********************************************************************/

swodesh_time=sqrt((cnt_wordsS/N0)*log(correlation)/(-Lcoeff*correlation));
printf (" Время Сводеша= %0.9f\n", swodesh_time);
    return 0;
}
