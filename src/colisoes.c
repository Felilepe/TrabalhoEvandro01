#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static double conversaoTxtoLinhaX1(double xt, int char_count, char at)
{
    double x1;

    switch(at){
        case 'i': x1 = xt; break;
        case 'm': x1 = xt - 10 * (double)char_count / 2; break;
        case 'f': x1 = xt - 10 * (double)char_count; break;
        default: printf("Erro, opcao de ancora invalida.");
            exit(1);     
    }

    return  x1;
}

static double conversaoTxtoLinhaX2(double xt, int char_count, char at)
{
    double x2;

    switch(at){
        case 'i': x2 = xt + 10 * (double)char_count; break;
        case 'm': x2 = xt + 10 * (double)char_count / 2; break;
        case 'f': x2 = xt; break;
        default: printf("Erro, opcao de ancora invalida.");
            exit(1);     
    }

    return x2;
}



bool colisaoCircCirc(double xc1, double yc1, double rc1, double xc2, double yc2, double rc2)
{
    double dist = sqrt(pow((xc1-xc2),2) + pow((yc1-yc2),2));

    return dist <= (rc1 + rc2);
}

bool colisaoRetRet(double xr1, double yr1, double wr1, double hr1, double xr2, double yr2, double wr2, double hr2)
{
    return !(xr1 > xr2 + wr2 || xr1 + wr1 < xr2 || yr1 > yr2 + hr2 || yr1 + hr1 < yr2); 
}

bool colisaoCircRet(double xc, double yc, double rc, double xr, double yr, double wr, double hr)
{
    double ponto_proxX = fmax(xr, xc);

    ponto_proxX = fmin(ponto_proxX, xr + wr);


    double ponto_proxY = fmax(yr, yc);

    ponto_proxY = fmin(ponto_proxY, yr + hr);

    double dist = sqrt(pow((xc-ponto_proxX),2) + pow((yc-ponto_proxY),2));

    return dist <= rc;
}

bool colisaoLinhaLinha(double x1l1, double x2l1, double y1l1, double y2l1, double x1l2, double x2l2, double y1l2, double y2l2)
{
    double D = (x1l1 - x2l1) * ( y1l2 - y2l2) - (y1l1 - y2l1) * (x1l2 - x2l2);

    if(!D) return false;

    double t = ((x1l1 - x1l2) * ( y1l2 - y2l2) - (y1l1 - y1l2) * (x1l2 - x2l2)) / D;

    double u = -(((x1l1 - x2l1) * (y1l1 - y1l2) - (y1l1 - y2l1) * (x1l1 - x1l2)) / D);

    return((t >= 0 && t <= 1) && (u >= 0 && u <= 1));
}

bool colisaoCircLinha(double xc, double yc, double rc, double x1l, double x2l, double y1l, double y2l)
{
    double deltaX = x2l - x1l;
    double deltaY = y2l - y1l;
    
    double linha_lenght = (deltaX * deltaX) + (deltaY * deltaY);
    
    if(!linha_lenght){
        double deltaX_ponto = x1l - xc;
        double deltaY_ponto = y1l - yc;
        double dist_sq_ponto = (deltaX_ponto * deltaX_ponto) + (deltaY_ponto * deltaY_ponto);
        return dist_sq_ponto <= (rc * rc);
    }


    double t = ((xc - x1l) * deltaX + (yc - y1l) * deltaY) / linha_lenght;


    t = fmax(0, t);
    t = fmin(1, t);


    double ponto_proxX = x1l + t * deltaX;
    double ponto_proxY = y1l + t * deltaY;


    return (pow((xc -ponto_proxX), 2) + pow((yc - ponto_proxY), 2)) <= (rc * rc);
}

bool colisaoCircTxto(double xc, double yc, double rc, double xt, double yt, int char_count, char at)
{
    double x1, x2;
    double y1, y2;

    x1 = conversaoTxtoLinhaX1(xt, char_count, at);
    x2 = conversaoTxtoLinhaX2(xt, char_count, at);
    y1 = y2 = yt;

    return colisaoCircLinha(xc, yc, rc, x1, x2, y1, y2);


}


bool colisaoLinhaRet(double x1l, double x2l, double y1l, double y2l, double xr, double yr, double wr, double hr)
{
    bool colisao_topo = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, (xr + wr), yr, yr);

    bool colisao_esq = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, xr, yr, (yr + hr));

    bool colisao_dir = colisaoLinhaLinha(x1l, x2l, y1l, y2l, (xr + wr), (xr + wr), yr, (yr + hr));

    bool colisao_chao = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, (xr + wr), (yr + hr), (yr + hr));

    
    if(x1l >= xr && x1l <= (xr + wr) && y1l >= yr && y1l <= (yr + hr)) return true;
    
    
    return (colisao_chao || colisao_dir || colisao_esq || colisao_topo);
}

bool colisaoLinhaTxto(double x1l, double x2l, double y1l, double y2l, double xt, double yt, int char_count, char at)
{
    double x1, x2, y1, y2;

    conversaoTxtoLinhaX1(xt, char_count, at);
    conversaoTxtoLinhaX2(xt, char_count, at);
    y1 = y2 = yt;

    return colisaoLinhaLinha(x1l, x2l, y1l, y2l, x1, x2, y1, y2);
}

bool colisaoRetTxto(double xr, double yr, double wr, double hr, double xt, double yt, int char_count, char at)
{
    double x1, x2, y1, y2;
    
    x1 = conversaoTxtoLinhaX1(xt, char_count, at);
    x2 = conversaoTxtoLinhaX2(xt, char_count, at);
    y1= y2 = yt;

    return colisaoLinhaRet(x1, x2, y1, y1, xr, yr, wr, hr);
}

bool colisaoTxtoTxto(double xt1, double yt1, int char_count1, char at1, double xt2, double yt2, int char_count2, char at2)
{
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;

    x1 = conversaoTxtoLinhaX1(xt1, char_count1, at1);
    x2 = conversaoTxtoLinhaX2(xt1, char_count1, at1);
    x3 = conversaoTxtoLinhaX1(xt2, char_count2, at2);
    x4 = conversaoTxtoLinhaX2(xt2, char_count2, at2);

    y1 = y2 = yt1;

    y3 = y4 = yt2;

    return colisaoLinhaLinha(x1, x2, y1, y2, x3, x4, y3, y4);
}
