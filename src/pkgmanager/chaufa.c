#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <err.h>

#define VERSION "0.1v"

int main(int argc, char *argv[]) {


	int helpflag = 0; 
	int instflag = 0; /* flags temporales hasta que
										   tengamos una libreria o
											 tengamos algun header file xd*/

	int c;
  static struct option long_options[] =
  {
			{"help", 		no_argument, 			 0, 'h'},
			{"install", required_argument, 0, 'I'},
			{0, 0, 0, 0}
	};
	while (1)
  {
    if( (c = getopt_long(argc, argv, "hI:", long_options, 0)) == -1) break;

		switch (c)
    {
			case 'h':
				if (helpflag)
					break;
				helpflag = 1;
				break;
			case 'I':
				if (instflag)
					errx(EXIT_FAILURE, "install es usable una unica vez.");
			  instflag = 1;
				break;
			case '?':
  			errx(EXIT_FAILURE, "chaufa usage: \n chaufa -h --help\t Despliega este mensaje.\n chaufa -i --install\t Instala un paquete.\n\n chaufa version: %s\t \n", VERSION);
				break;
			default:
				break;
		}
	}

	int evaluate = helpflag + instflag;
	if (evaluate > 1)
		errx(EXIT_FAILURE, "help y install son incombinables.");

  if (argc == 1 || optind == 1){
		errx(EXIT_FAILURE, "No se encontraron opciones.\n");
	}

// si se puede, arreglar este codigo sida

	if (helpflag)
  		printf("chaufa usage: \n chaufa -h --help\t Despliega este mensaje.\n chaufa -i --install\t Instala un paquete.\n\n chaufa version: %s\t \n", VERSION);
	if (instflag)
			printf("testing \n");

	exit(EXIT_SUCCESS);
}
