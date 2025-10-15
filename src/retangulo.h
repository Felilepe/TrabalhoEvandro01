#ifndef RETANGULO_H
#define RETANGULO_H

typedef void* Retangulo;

Retangulo createRetangulo(int id, double x, double  y, double w, double h, char *corborda, char *corpreench);
/****************************************************************************************
* @brief Cria e aloca a memória para um novo retângulo com os parâmetros fornecidos.    *
* @param id Identificador único para o retângulo.                                       *
* @param x Coordenada X do âncora do retângulo.                                         *
* @param y Coordenada Y do âncora do retângulo.                                         *
* @param w Largura do retângulo.                                                        *
*@param h Altura do retângulo                                                           *
*@param corborda String que representa a cor da borda.                                  *
* @param corpreench String que representa a cor de preenchimento.                       *
* @return Retorna um ponteiro do tipo Retangulo para o retângulo recém-criado.          *
****************************************************************************************/

double getCoordX(Retangulo r);
/****************************************************************************************
* @brief Obtém a coordenada X da âncora de um retângulo.                                *
* @param r O retângulo do qual a coordenada será obtida.                                *
* @return Retorna o valor da coordenada X (um double).                                  *
****************************************************************************************/

double getCoordY(Retangulo r);
/****************************************************************************************
* @brief Obtém a coordenada Y do âncora de um retângulo.                                *
* @param r O retângulo do qual a coordenada será obtida.                                *
* @return Retorna o valor da coordenada Y (um double).                                  *
****************************************************************************************/


double calcArea(Retangulo r);
/****************************************************************************************
* @brief Obtém a área de um retângulo.                                                  *
* @param r O retângulo do qual a área será obtida.                                      *
* @return Retorna o valor da área (um double).                                          *
****************************************************************************************/

double getHeight(Retangulo r);
/****************************************************************************************
* @brief Obtém a altura de um retângulo.                                                *
* @param r O retângulo do qual a altura será obtida.                                    *
* @return Retorna o valor da altura (um double).                                        *
****************************************************************************************/


double getWidth(Retangulo r);
/****************************************************************************************
* @brief Obtém a largura de um retângulo.                                               *
* @param r O retângulo do qual a largura será obtida.                                   *
* @return Retorna o valor da largura (um double).                                       *
****************************************************************************************/

int getID(Retangulo r);
/****************************************************************************************
* @brief Obtém o ID de um retângulo.                                                    *
* @param r O retângulo do qual o ID será obtido.                                        *
* @return Retorna o valor do ID (um int).                                               *
****************************************************************************************/

#endif
