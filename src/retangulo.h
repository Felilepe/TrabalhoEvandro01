#ifndef RETANGULO_H
#define RETANGULO_H

typedef void* Retangulo;

Retangulo createRetangulo(int id, double x, double  y, double w, double h, char *corborda, char *corpreench);
/****************************************************************************************
* @brief Cria e aloca a memória para um novo círculo com os parâmetros fornecidos.      *
* @param id Identificador único para o círculo.                                         *
* @param x Coordenada X do centro do círculo.                                           *
* @param y Coordenada Y do centro do círculo.                                           *
* @param r Raio do círculo.                                                             *
* @param corborda String que representa a cor da borda.                                 *
* @param corpreench String que representa a cor de preenchimento.                       *
* @return Retorna um ponteiro do tipo Retangulo para o círculo recém-criado.            *
****************************************************************************************/

double getCoordX(Retangulo c);
/****************************************************************************************
* @brief Obtém a coordenada X do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/

double getCoordY(Retangulo c);
/****************************************************************************************
* @brief Obtém a coordenada X do centro de um círculo.                                  *
* @param c O círculo do qual a coordenada será obtida.                                  *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/


double calcArea(Retangulo c);
/****************************************************************************************
* @brief Obtém a área de um círculo.                                                    *
* @param c O círculo do qual a raio será obtida.                                        *
* @return Retorna o valor da área (um double).                                          *
****************************************************************************************/

double getRaio(Retangulo c);
/****************************************************************************************
* @brief Obtém o raio de um círculo.                                                    *
* @param c O círculo do qual o raio será obtido.                                        *
* @return Retorna o valor do raio (um double).                                          *
****************************************************************************************/


int getID(Retangulo c);
/****************************************************************************************
* @brief Obtém o ID de um círculo.                                                      *
* @param c O círculo do qual o ID será obtido.                                          *
* @return Retorna o valor do ID (um int).                                               *
****************************************************************************************/


#endif
