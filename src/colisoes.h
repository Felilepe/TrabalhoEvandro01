#ifndef COLISOES_H
#define COLISOES_H

#include <stdbool.h>

bool colisaoCircCirc(double xc1, double yc1, double rc1, double xc2, double yc2, double rc2);

bool colisaoCircLinha(double xc, double yc, double rc, double x1l, double x2l, double y1l, double y2l);

bool colisaoCircRet(double xc, double yc, double rc, double xr, double yr, double wr, double hr);

bool colisaoCircTxto(double xc, double yc, double rc, double xt, double yt, int char_count, char at);

bool colisaoLinhaLinha(double x1l1, double x2l1, double y1l1, double y2l1, double x1l2, double x2l2, double y1l2, double y2l2);

bool colisaoLinhaRet(double x1l, double x2l, double y1l, double y2l, double xr, double yr, double wr, double hr);

bool colisaoLinhaTxto(double x1l, double x2l, double y1l, double y2l, double xt, double yt, int char_count, char at);

bool colisaoRetRet(double xr1, double yr1, double wr1, double hr1, double xr2, double yr2, double wr2, double hr2);

bool colisaoRetTxto(double xr, double yr, double wr, double hr, double xt, double yt, int char_count, char at);

bool colisaoTxtoTxto(double xt1, double yt1, int char_count1, char at1, double xt2, double yt2, int char_count2, char at2);

#endif