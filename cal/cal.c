/**************/
/*  関数電卓  */
/**************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

void  main( )
{
    char    c[128],fnc[128];
    double  x=0,y,z=0;
    double  rd=PI/180.0;  // 1度(ラジアン）

    printf("\n**************************");
    printf("\n*  関数電卓              *");
    printf("\n*  sin X, cos X, tan X,  *");
    printf("\n*  exp X, log X, ln X    *");
    printf("\n*  sqr X, X ^ Y          *");
    printf("\n*  ※角度の単位は度です  *");
    printf("\n*************************\n");

    //--入力--
    printf("\n数値 X: ");
    gets(c); x=atof(c);                   // 数値X 入力
    printf("\n関  数: ");
    gets(fnc);                            // 関数記号入力
    if ( strcmp(fnc,"^")==0 )
        {
            printf("\n数値 Y: ");
            gets(c); y=atof(c);           // 数値Y 入力
        }

    //--計算実行--
    if ( strcmp(fnc,"sin")==0 )
        { z=sin(x*rd); }
    else if ( strcmp(fnc,"cos")==0 )
        { z=cos(x*rd); }
    else if ( strcmp(fnc,"tan")==0 )
        { z=tan(x*rd); }
    else if ( strcmp(fnc,"exp")==0 )
        { z=exp(x); }
    else if ( strcmp(fnc,"log")==0 )
        { z=log10(x); }
    else if ( strcmp(fnc,"ln")==0 )
        { z=log(x); }
    else if ( strcmp(fnc,"sqr")==0 )
        { z=sqrt(x); }
    else if ( strcmp(fnc,"^")==0 )
        { z=pow(x,y); }
    else
      { printf("\a関数がありません"); }   // ブザー

    //--結果表示--
    printf("\n答：%4.8f\n\n",z);
}