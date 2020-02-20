#define TAM 6
int mostralElementosDeLaTienda();
int mostrarCarrito();
int clearScreen();
int agregarElementoAlCarrito();
int eliminarElementoDelCarrito();
char *articles[TAM]={"UNO", "DOS", "TRES", "CUATRO", "CINCO", '\0'};
int stock[TAM]={10, 10, 10, 10, 10, '\0'};
int cart[TAM]={0, 0, 0, 0, 0, '\0'};
float price[TAM]={5.5, 10.5, 20.0, 90.5, 100.0, '\0'};
int ver = 0;

int menu(){
	setbuf(stdin, NULL);
	int opt;
	printf("Selecciona un opción:\n");
	printf("1)\tMostrar elementos de la tienda.\n");
	printf("2)\tMostrar  carrito.\n");
	printf("3)\tAgregar  elemento  al  carrito.\n");
	printf("4)\tEliminar  elemento  del carrito.\n");
	printf("5)\tSalir de la aplicación.\n");
	if(scanf("%d", &opt) == 1){
		getchar();
		switch(opt){
			case 1:
				clearScreen();
				mostralElementosDeLaTienda();
			break;
			case 2:
				clearScreen();
				mostrarCarrito();
			break;
			case 3:
				clearScreen();
				agregarElementoAlCarrito();
			break;
			case 4:
				clearScreen();
				eliminarElementoDelCarrito();
			break;
			case 5:
				clearScreen();
				if(ver == 1){
					mostrarCarrito();
				}
				return 0;
			break;
			default:
				clearScreen();
				printf("Ésa no es un opción válida\n");
				menu();
			break;
		}
	}else{
		printf("Ésa no es un opción válida\n");
	}
	menu();
}

int clearScreen(){
	system("clear");
	return 0;
}

int mostralElementosDeLaTienda(){
	int i = 0;
	printf("ID\tArtículo\tCantidad en stock\tPrecio unitario\n");
	while(i < TAM - 1){
		printf("%d)\t%s\t\t%d\t\t\t$%g\n", i + 1, articles[i], stock[i], price[i]);
		i ++;
	}
	printf("Presione enter para continuar");
	getchar();
}

int mostrarCarrito(){
	ver = 0;
	setbuf(stdin, NULL);
	int i = 0, aux = 0;
       	float tot = 0;
	while(i < TAM - 1){
		if(cart[i] > 0){
			ver = 1;
			aux = 1;
		}
		i++;
	}
	i = 0;
	if(ver == 1){
		printf("Éste es tu carrito:\n");
		printf("ID\tArtículo\tCantidad en tu carrito\tP.Unitario\tP.Total\n");
		while(i < TAM - 1){
			if(cart[i] > 0){
				printf("%d)\t%s\t\t%d\t\t\t$%g\t\t$%g\n", i + 1, articles[i], cart[i], price[i], cart[i] * price[i]);
				tot += cart[i] * price[i];
			}
			i++;
		}
		printf("Total: $%g\n", tot);
		i = 0;
	}else{
		printf("Aún no hay nada en tu carro.\n");
	}
}

int agregarElementoAlCarrito(){
	int seleccionado = 0, cantidad = 0;
	mostralElementosDeLaTienda();
	printf("Seleccione ID del emento que desea agregar.\n");
	if(scanf("%d", &seleccionado) == 1 && seleccionado > 0 && seleccionado < TAM){
		printf("¿Cuántos desea agregar?\n");
		if(scanf("%d", &cantidad) == 1 && cantidad <= stock[seleccionado - 1]){
			cart[seleccionado - 1] += cantidad;
			stock[seleccionado - 1] -= cantidad;
		}else if(cantidad > stock[seleccionado]){
			printf("No hay tanta disponibilidad en stock.\n");
		}else{
			printf("Esa no es una opción válida.\n");
		}
	}else if(seleccionado > TAM){
		printf("Ese artículo no existe.\n");
	}else{
		printf("Esa no es una opción.\n");
	}
}
int eliminarElementoDelCarrito(){
	int seleccionado = 0, cantidad = 0;
	mostrarCarrito();
	if(ver == 1){
		printf("Seleccione ID del emento que desea eliminar.\n");
		if(scanf("%d", &seleccionado) == 1 && seleccionado > 0 && seleccionado < TAM){
			printf("¿Cuántos desea eliminar?\n");
			if(scanf("%d", &cantidad) == 1 && cantidad <= cart[seleccionado - 1]){
				cart[seleccionado - 1] -= cantidad;
				stock[seleccionado - 1] += cantidad;
			}else if(cantidad > cart[seleccionado]){
				printf("No tiene tantos elementos en el carrito.\n");
			}else{
				printf("Esa no es una opción válida.\n");
			}
		}else if(seleccionado > TAM){
			printf("Ese artículo no existe en el carrito.\n");
		}else{
			printf("Esa no es una opción.\n");
		}
	}
}
