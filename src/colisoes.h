#ifndef COLISOES_H
#define COLISOES_H

#include <stdbool.h>
#include "formas.h"
#include "linha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"  

bool checarColisao(forma f1, forma f2);

bool colisaoCircCirc(Circulo c1, Circulo c2);

bool colisaoCircLinha(Circulo c, Linha l);

bool colisaoCircRet(Circulo c, Retangulo r);

bool colisaoCircTxto(Circulo c, Texto t);

bool colisaoLinhaLinha(Linha l1, Linha l2);

bool colisaoLinhaRet(Linha l, Retangulo r);

bool colisaoLinhaTxto(Linha l, Texto t);

bool colisaoRetRet(Retangulo r1, Retangulo r2);

bool colisaoRetTxto(Retangulo r, Texto t);

bool colisaoTxtoTxto(Texto t1, Texto t2);

#endif