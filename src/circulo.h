#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* Circulo;

Circulo circulo_create(int id, double x, double  y, double r, char *corborda, char *corpreench);
/****************************************************************************************
* @brief Cria e aloca a memória para um novo círculo com os parâmetros fornecidos.      *
* @param id Identificador único para o círculo.                                         *
* @param x Coordenada X do centro do círculo.                                           *
* @param y Coordenada Y do centro do círculo.                                           *
* @param r Raio do círculo.                                                             *
* @param corborda String que representa a cor da borda.                                 *
* @param corpreench String que representa a cor de preenchimento.                       *
* @return Retorna um ponteiro do tipo Circulo para o círculo recém-criado.              *
****************************************************************************************/

double circulo_getCoordX(Circulo c);
/****************************************************************************************
* @brief Obtém a coordenada X do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/

double circulo_getCoordY(Circulo c);
/****************************************************************************************
* @brief Obtém a coordenada Y do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada Y (um double).                                  *
****************************************************************************************/


double circulo_calcArea(Circulo c);
/****************************************************************************************
* @brief Obtém a área de um círculo.                                                    *
* @param c O círculo do qual a área será obtida.                                        *
* @return Retorna o valor da área (um double).                                          *
****************************************************************************************/



int circulo_getID(Circulo c);
/****************************************************************************************
* @brief Obtém o ID de um círculo.                                                      *
* @param c O círculo do qual o ID será obtido.                                          *
* @return Retorna o valor do ID (um int).                                               *
****************************************************************************************/

char* circulo_getCorBorda(Circulo c);

char* circulo_getCorPreench(Circulo c);



double circulo_getRaio(Circulo c);
/****************************************************************************************
* @brief Obtém o raio de um círculo.                                                    *
* @param c O círculo do qual o raio será obtido.                                        *
* @return Retorna o valor do raio (um double).                                          *
****************************************************************************************/



void circulo_setCoordX(Circulo c, double x);

void circulo_setCoordY(Circulo c, double y);

void circulo_setRaio(Circulo c, double r);

void circulo_setCorBorda(Circulo c, char *corborda);

void circulo_setCorPreench(Circulo c, char *corpreench);

#endif
