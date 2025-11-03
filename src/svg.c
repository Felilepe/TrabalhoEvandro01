#include <stdio.h>
#include "retangulo.h"
#include "circulo.h"
#include "fila.h"
#include "linha.h"
#include "texto.h"
#include "formas.h"

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
