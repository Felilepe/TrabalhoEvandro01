#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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


bool colisaoCircLinha(double xc, double yc, double rc, double x1l, double x2l, double y1l, double y2l);


bool colisaoCircTxto(double xc, double yc, double rc, double xt, double yt, int char_count);


bool colisaoLinhaRet(double x1l, double x2l, double y1l, double y2l, double xr, double yr, double wr, double hr)
{
    bool colisao_topo = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, (xr + wr), yr, yr);

    bool colisao_esq = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, xr, yr, (yr + hr));

    bool colisao_dir = colisaoLinhaLinha(x1l, x2l, y1l, y2l, (xr + wr), (xr + wr), yr, (yr + hr));

    bool colisao_chao = colisaoLinhaLinha(x1l, x2l, y1l, y2l, xr, (xr + wr), (yr + hr), (yr + hr));

    
    if(x1l >= xr && x1l <= (xr + wr) && y1l >= yr && y1l <= (yr + hr)) return true;
    
    
    return (colisao_chao || colisao_dir || colisao_esq || colisao_topo);
}

bool colisaoLinhaTxto(double x1l, double x2l, double y1l, double y2l, double xt, double yt, int char_count);


bool colisaoRetTxto(double xr, double yr, double wh, double hr, double xt, double yt, int char_count);

bool colisaoTxtoTxto(double xt1, double yt1, int char_count1, double xt2, double yt2, int char_count2)
{

}
