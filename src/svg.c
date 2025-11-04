#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"
#include "circulo.h"
#include "fila.h"
#include "linha.h"
#include "texto.h"
#include "formas.h"

#define DEFAULT_WIDTH 1.5
#define OPACITY 0.5


FILE* startSVG(const char* file_path) {
	FILE* svg = fopen(file_path, "w");
	if (svg == NULL) {
		perror("Erro: Arquivo NULL.");
		exit(1);
	}

	fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
	fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n<g>\n");

	return svg;
}

void stopSVG(FILE *file_name)
{
    if (file_name == NULL) return;

	fprintf(file_name, "</g>\n</svg>\n");

	fclose(file_name);
}



void svg_insertCirculo(FILE *file_name, Circulo c)
{
    fprintf(file_name, " <circle id=\"%i\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"%lf\" stroke-width=\"%lf\" />\n",
    circulo_getID(c), circulo_getCoordX(c), circulo_getCoordY(c), circulo_getRaio(c), circulo_getCorBorda(c), circulo_getCorPreench(c), OPACITY, DEFAULT_WIDTH);
}

void svg_insertRetangulo(FILE *file_name, Retangulo r)
{
    fprintf(file_name, "\t<rect id=\"%d\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"%lf\" stroke-width=\"%lf\" />\n",
	    retangulo_getID(r), retangulo_getCoordX(r), retangulo_getCoordY(r), retangulo_getWidth(r), retangulo_getHeight(r), retangulo_getCorBorda(r), 
        retangulo_getCorPreench(r), OPACITY, DEFAULT_WIDTH);
}

void svg_insertLinha(FILE *file_name, Linha l)
{
    fprintf(file_name, "\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-dasharray=\"1, 1\" stroke-width=\"%lf\" />\n",
        linha_getID(l), linha_getCoordX1(l), linha_getCoordY1(l), linha_getCoordX2(l), linha_getCoordY2(l), linha_getCor(l), DEFAULT_WIDTH);
}

void svg_insertTexto(FILE *file_name, Texto t)
{
    fprintf(file_name, "\t<text id=\"%d\" x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%spt\" ",
        texto_getID(t), texto_getCoordX(t), texto_getCoordY(t), texto_getCorBorda(t), texto_getCorPreench(t), texto_getFamily(t), texto_getWeight(t),
        texto_getSize(t));


	char ancora = texto_getAnchor(t);
	switch (ancora) {
        case 'i': default: fprintf(file_name, "text-anchor=\"start\""); break;
		case 'm': fprintf(file_name, "text-anchor=\"middle\""); break;
		case 'f': fprintf(file_name, "text-anchor=\"end\""); break;
	}

    fprintf(file_name, ">%s</text>\n", texto_getTexto(t));
}

void svg_insertForma(FILE *file_name, forma f)
{
    switch (forma_getType(f))
    {
        case(TIPO_C): svg_insertCirculo(file_name, (Circulo)f); break;
        case(TIPO_R): svg_insertRetangulo(file_name, (Retangulo)f); break;
        case(TIPO_L): svg_insertLinha(file_name, (Linha)f); break;
        case(TIPO_T): svg_insertTexto(file_name, (Texto)f); break;
        default: printf("--- ERRO DE DEBUG ---\\n");
            printf("A forma com ID: %d retornou um TIPO desconhecido: %d\\n", forma_getID(f), forma_getType(f));
            printf("(Esperado: 1, 2, 3 ou 4)\\n");
            printf("---------------------\\n");
            exit(1); 
            break;
    }
}



void draw(item i, item aux)
{
    FILE* svg = (FILE*)aux;
    /* Chamada correta: primeiro FILE*, depois a forma opaca */
    svg_insertForma(svg, (forma)i);
}



void createSVG(char *file_name, Fila *formas)
{
    if(formas == NULL){
        fprintf(stderr, "Erro: fila de formas esta vazia para o arquvo %s\n.", file_name);
        exit(1);
    }

    FILE *svg = startSVG(file_name);
    if(!svg){
        printf("Erro: Falha ao abrir arquivo.");
        exit(1);
    }

    fila_passthrough(formas, draw, svg);

    stopSVG(svg);

    printf("Arquivo SVG criado com sucesso.");
}
