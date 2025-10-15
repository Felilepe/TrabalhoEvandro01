#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* Circulo;

Circulo createCirculo(int id, double x, double  y, double r, char *corborda, char *corpreench);
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

double getCoordX(Circulo c);
/****************************************************************************************
* @brief Obtém a coordenada X do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/

double getCoordY(Circulo c);
/****************************************************************************************
* @brief Obtém a coordenada X do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/


double calcArea(Circulo c);
/****************************************************************************************
* @brief Obtém a área de um círculo.                                                    *
* @param c O círculo do qual a raio será obtida.                                        *
* @return Retorna o valor da área (um double).                                          *
****************************************************************************************/

double getRaio(Circulo c);
/****************************************************************************************
* @brief Obtém o raio de um círculo.                                                    *
* @param c O círculo do qual o raio será obtido.                                        *
* @return Retorna o valor do raio (um double).                                          *
****************************************************************************************/


int getID(Circulo c);
/****************************************************************************************
* @brief Obtém o ID de um círculo.                                                      *
* @param c O círculo do qual o ID será obtido.                                          *
* @return Retorna o valor do ID (um int).                                               *
****************************************************************************************/


#endif
