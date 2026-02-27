#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define VERSION "0.1v"

void optionhelp() {
  printf("Uso de Camry: \n");
  printf("-h --help   Despliega este mensaje. \n");
  printf("-v --version  Muestra la versión de Camry. \n");
}

int main(int argc, char *argv[]) {

	int c;

  static struct option long_options[] =
  {
			{"help", no_argument, 0, 'h'},
			{"version", no_argument, 0, 'v'},
			{0, 0, 0, 0}
	};


	while (1) 
  {
    if( (c = getopt_long(argc, argv, "hv", long_options, 0)) == -1) break;
		switch (c) 
    {
			case 'h':
				optionhelp();
				break;
			case 'v':
				printf("Camry Version: %s\n", VERSION);
				break;
			case '?':
				break;
			default:
				break;
		}
	}
	
	if (argc == 1 || optind == 1)
  {
      printf("No se encontraron argumentos. (usa --help para ayuda).\n");
      exit(EXIT_FAILURE);
	    exit(EXIT_SUCCESS);
	}
}
