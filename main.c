#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define DIMENSION 30

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

/// PROTOTIPADO ///

int cargarAlumno(stAlumno alumnos[], int dimension); //1
void mostrarAlumno(stAlumno alumnos[], int cantidad); //2
void mostrarUnAlumno(stAlumno alumnos); //2
void buscarAlumno(stAlumno alumnos[], int cantidad); //3
void ordenarSeleccion(stAlumno alumnos[], int validos); //4
void mostrarPorGenero(stAlumno alumnos[], int validos, char genero); //5
int agregarAlumnoOrdenadoPorMatricula(stAlumno alumnos[], int validos, int dimension, stAlumno alumnoNuevo); //6
void ordenarNombreInsercion(stAlumno alumnos[],int validos); //7
int cantidadGenero(stAlumno alumnos[], int validos, char genero); //8
void funcionMenu(); //9

/// MAIN ///

int main(){
    stAlumno listado[DIMENSION];
    char genre;
    int alumnosValidos;
    funcionMenu();
}

/// FUNCIONES ///

/// 1 Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario decida.
int cargarAlumno(stAlumno alumnos[], int dimension){
    int i=0;
    char opt='s';
    while(i<dimension&&opt=='s'){
        printf("\n INGRESE MATRICULA DEL ALUMNO: ");
        fflush(stdin);
        scanf("%d", &alumnos[i].matricula);
        printf(" INGRESE NOMBRE DEL ALUMNO: ");
        fflush(stdin);
        scanf("%s", &alumnos[i].nombre);
        printf(" INGRESE GENERO DEL ALUMNO m/f/o: ");
        fflush(stdin);
        scanf("%s", &alumnos[i].genero);
        i++;

        printf(" \nDESEA INGRESAR OTRO ALUMNO s/n: ");
        fflush(stdin);
        scanf("%c", &opt);
        system("cls");
    }
    return i;
}

/// 2.Hacer una funcion que muestre un arreglo de alumnos por pantalla.
void mostrarAlumno(stAlumno alumnos[], int cantidad){
    char m[]= {"MASCULINO"};
    char f[]= {"FEMENINO"};
    char o[]= {"OTRO"};
    int i=0;
    printf("\n LISTADO DE ALUMNOS\n");
    printf(" ---------------------\n");
    while(i<cantidad){
        color(10);
        printf(" MATRICULA: %d\n", alumnos[i].matricula);
        printf(" NOMBRE: %s\n", strupr(alumnos[i].nombre));

        if(alumnos[i].genero=='m'){
            printf(" GENERO: %s\n", m);
        }
        else if(alumnos[i].genero=='f'){
            printf(" GENERO: %s\n", f);
        }
        else{
            printf(" GENERO: %s\n", o);
        }
        i++;
        color(7);
        printf(" ---------------------\n");
    }
    printf("\n");
}

void mostrarUnAlumno(stAlumno alumnos){
    char m[]= {"MASCULINO"};
    char f[]= {"FEMENINO"};
    char o[]= {"OTRO"};
    color(10);
    printf("MATRICULA: %d\n", alumnos.matricula);
    printf("NOMBRE: %s\n", strupr(alumnos.nombre));
    if(alumnos.genero=='m'){
        printf("GENERO: %s\n", m);
    }
    else if(alumnos.genero=='f'){
        printf("GENERO: %s\n", f);
    }
    else{
        printf("GENERO: %s\n", o);
    }
    color(7);
}

/// 3. Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo
/// su matricula.
int existeAlumno(stAlumno alumnos[], int cantidad, int matricula){
    int flag=0;
    int i=0;
    while(i<cantidad&&flag==0){
        if(matricula==alumnos[i].matricula){
            flag=1;
        }
        i++;
    }
    return flag;
}

void buscarAlumno(stAlumno alumnos[], int cantidad){
    int i=0;
    int mat=0;
    int pos=-1;
    printf("\n BUSCAR MATRICULA NUMERO: ");
    scanf("%d", &mat);
    int flag=0;
    flag=existeAlumno(alumnos,cantidad,mat);
    if(flag==1){
        while(i<cantidad&&pos==-1){
            if(alumnos[i].matricula==mat){
                pos=i;
            }
            i++;
        }
        color(10);
        printf("\n LA MATRICULA PERTENECE A %s \n\n", alumnos[pos].nombre);
        color(7);
    }
    else{
        color(12);
        printf("\n LA MATRICULA NO EXISTE\n\n");
        color(7);
    }
}

/// 4. Hacer una funcion que ordene el arreglo de alumnos por medio de seleccion.
/// El criterio de ordenacion es el numero de matricula.
int buscaMenor(stAlumno alumnos[], int validos, int pos){
    int posMenor=pos;
    stAlumno menor=alumnos[pos];
    for(int i=pos+1; i<validos; i++){
        if(alumnos[i].matricula<menor.matricula){
            posMenor=i;
            menor=alumnos[i];
        }
    }
    return posMenor;
}

void ordenarSeleccion(stAlumno alumnos[], int validos){
    int i=0;
    stAlumno aux;
    int posMenor;
    while(i<validos-1){
        posMenor=buscaMenor(alumnos,validos,i);

        aux=alumnos[posMenor];
        alumnos[posMenor]=alumnos[i];
        alumnos[i]=aux;

        i++;
    }
}

/// 5 Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado.
void mostrarPorGenero(stAlumno alumnos[], int validos, char genero){
    int i=0;
    printf("\n INGRESE GENERO m/f/o: ");
    fflush(stdin);
    scanf("%c", &genero);
    printf("\n LISTADO DE ALUMNOS\n");
    printf(" ---------------------\n");
    while(i<validos){
        if(alumnos[i].genero==genero){
            mostrarUnAlumno(alumnos[i]);
            printf(" ---------------------\n");
        }
        i++;
    }
    printf("\n");

}

/// 6 Agregar alumno nuevo por matricula
int agregarAlumnoOrdenadoPorMatricula(stAlumno alumnos[], int validos, int dimension, stAlumno alumnoNuevo){
    int flag=0;
    printf("\n INGRESE MATRICULA DEL ALUMNO: ");
    fflush(stdin);
    scanf("%d", &alumnoNuevo.matricula);
    printf(" INGRESE NOMBRE DEL ALUMNO: ");
    fflush(stdin);
    scanf("%s", &alumnoNuevo.nombre);
    printf(" INGRESE GENERO DEL ALUMNO m/f/o: ");
    fflush(stdin);
    scanf("%s", &alumnoNuevo.genero);
    for(int i=(validos-1); i>=0 && flag==0; i--){
        if(alumnoNuevo.matricula<alumnos[i].matricula){
            alumnos[i+1]=alumnos[i];
        }
        else{
            alumnos[i+1]=alumnoNuevo;
            flag=1;
        }
    }
    validos++;
    return validos;
}

/// 7 Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.
void insertarAlumno(stAlumno alumnos[],int u,stAlumno alumnoNuevo){
    int i=u;
    while (i>=0 && strcmp(alumnoNuevo.nombre,alumnos[i].nombre)<0){
        alumnos[i+1]=alumnos[i];
        i--;
    }
    alumnos[i+1]=alumnoNuevo;
}

void ordenarNombreInsercion(stAlumno alumnos[],int validos){
    int u=0;
    while(u<validos-1){
        insertarAlumno(alumnos,u,alumnos[u+1]);
        u++;
    }
}

/// 8 Cantidad por genero
int cantidadGenero(stAlumno alumnos[], int validos, char genero){
    int i=0;
    int contador=0;
    printf("\n INGRESE EL GENERO: ");
    fflush(stdin);
    scanf("%c", &genero);
    printf("\n");
    while(i<validos){
        if(alumnos[i].genero==genero){
            contador++;
        }
        i++;
    }
    color(10);
    if(genero=='m'){
        printf(" LA CANTIDAD DE ALUMNOS ES DE: %i\n\n",contador);
    }
    else if(genero=='f'){
        printf(" LA CANTIDAD DE ALUMNAS ES DE: %i\n\n",contador);
    }
    else{
        printf(" LA CANTIDAD DE OTROS ES DE: %i\n\n",contador);
    }
    color(7);
    return contador;
}

/// 9 Menu
int menu(){
    int option;
    color(11);
        printf("====================================\n");
        printf(" TRABAJO PRACTICO N° 6: ESTRUCTURAS\n");
        printf("====================================\n");
        color(7);
        printf(" 1.HACER UNA FUNCION QUE CARGUE UN ARREGLO DE ALUMNOS, HASTA QUE EL USUARIO DECIDA\n\n");
        printf(" 2.HACER UNA FUNCION QUE MUESTRE UN ARREGLO DE ALUMNOS POR PANTALLA. MODULARIZAR\n\n");
        printf(" 3.HACER UNA FUNCION QUE MUESTRE POR PANTALLA LOS DATOS DE UN ALUMNO, CONOCIENDO SU MATRICULA. MODULARIZAR\n\n");
        printf(" 4.HACER UNA FUNCION QUE ORDENE EL ARREGLO DE ALUMNOS POR MEDIO DEL METODO DE SELECCION. EL CRITERIO DE ORDENACION ES EL NUMERO DE MATRICULA\n\n");
        printf(" 5.HACER UNA FUNCION QUE MUESTRE POR PANTALLA LOS DATOS DE LOS ESTUDIANTES DE UN GENERO DETERMINADO (SE ENVIA POR PARAMETRO). MODULARIZAR\n\n");
        printf(" 6.HACER UNA FUNCION QUE INSERTE EN UN ARREGLO ORDENADO POR MATRICULA UN NUEVO DATO, CONSERVANDO EL ORDEN\n\n");
        printf(" 7.HACER UNA FUNCION QUE ORDENE EL ARREGLO DE ALUMNOS POR MEDIO DEL METODO DE INSERCION. EL CRITERIO DE ORDENACION ES EL NOMBRE\n\n");
        printf(" 8.HACER UNA FUCNION QUE CUENTE Y RETORNE LA CANTIDAD DE ESTUDIATES DE UN GENERO DETERMINADO (SE ENVIA POR PARAMETRO) QUE TIENE UN ARREGLO DE ALUMNOS\n\n");
        printf(" 9.SALIR\n\n");
        printf("\n ELIJA UNA OPCIÓN: ");
        fflush(stdin);
        scanf("%i", &option);
        return option;
}

void funcionMenu(){
    stAlumno alumnos[30];
    char genre;
    int alumnosValidos=0;
    setlocale(LC_ALL, "");
    int option=0;
    do{
        option=menu();
        system("cls");
        switch(option){
        case 1:{
            color(11);
            printf("  1.HACER UNA FUNCION QUE CARGUE UN ARREGLO DE ALUMNOS, HASTA QUE EL USUARIO DECIDA\n");
            color(7);
            alumnosValidos = cargarAlumno(alumnos,DIMENSION);
            system("pause");
            system("cls");
        }
        break;
        case 2:{
            color(11);
            printf("  2.HACER UNA FUNCION QUE MUESTRE UN ARREGLO DE ALUMNOS POR PANTALLA. MODULARIZAR\n");
            color(7);
            mostrarAlumno(alumnos,alumnosValidos);
            system("pause");
            system("cls");
        }
        break;
        case 3:{
            color(11);
            printf("  3.HACER UNA FUNCION QUE MUESTRE POR PANTALLA LOS DATOS DE UN ALUMNO, CONOCIENDO SU MATRICULA. MODULARIZAR\n");
            color(7);
            buscarAlumno(alumnos, alumnosValidos);
            system("pause");            system("cls");
        }
        break;
        case 4:{
            color(11);
            printf("  4.HACER UNA FUNCION QUE ORDENE EL ARREGLO DE ALUMNOS POR MEDIO DEL METODO DE SELECCION. EL CRITERIO DE ORDENACION ES EL NUMERO DE MATRICULA\n");
            color(7);
            ordenarSeleccion(alumnos,alumnosValidos);
            mostrarAlumno(alumnos,alumnosValidos);
            system("pause");
            system("cls");
        }
        break;
        system("cls");
        case 5:{
            color(11);
            printf("  5.HACER UNA FUNCION QUE MUESTRE POR PANTALLA LOS DATOS DE LOS ESTUDIANTES DE UN GENERO DETERMINADO (SE ENVIA POR PARAMETRO). MODULARIZAR\n");
            color(7);
            mostrarPorGenero(alumnos,alumnosValidos,genre);
            system("pause");
        }
        break;
        case 6:{
            color(11);
            printf("  6.HACER UNA FUNCION QUE INSERTE EN UN ARREGLO ORDENADO POR MATRICULA UN NUEVO DATO, CONSERVANDO EL ORDEN\n");
            color(7);
            stAlumno alumnoNuevo;
            alumnosValidos=agregarAlumnoOrdenadoPorMatricula(alumnos,alumnosValidos,DIMENSION, alumnoNuevo);
            mostrarAlumno(alumnos, alumnosValidos);
            system("pause");
            system("cls");
        }
        break;
        system("cls");
        case 7:{
            color(11);
            printf("  7.HACER UNA FUNCION QUE ORDENE EL ARREGLO DE ALUMNOS POR MEDIO DEL METODO DE INSERCION. EL CRITERIO DE ORDENACION ES EL NOMBRE\n");
            color(7);
            ordenarNombreInsercion(alumnos, alumnosValidos);
            mostrarAlumno(alumnos,alumnosValidos);
            system("pause");
        }
        break;
        case 8:{
            color(11);
            printf("  8.HACER UNA FUCNION QUE CUENTE Y RETORNE LA CANTIDAD DE ESTUDIATES DE UN GENERO DETERMINADO (SE ENVIA POR PARAMETRO) QUE TIENE UN ARREGLO DE ALUMNOS\n");
            color(7);
            cantidadGenero(alumnos,alumnosValidos,genre);
            system("pause");
            system("cls");
        }
        break;
        case 9:{
            color(11);
            printf("  9.SALIR\n");
            color(7);
        }
        break;
        default:
            color(12);
            printf("\n OPCION INCORRECTA\n\n");
            color(7);
            system("pause");
            system("cls");
        break;
        }
    }while(option!=9);
    color(12);
    printf("\n FIN DEL PROGRAMA\n\n");
    color(7);
    system("pause");
}







/// BACK UP ///
//    printf("EJERCICIO 1 - CARGA DE ALUMNOS\n");
//    printf("-------------------------------\n");
//    alumnosValidos=cargarAlumno(listado,30);
//    printf("EJERCICIO 2 - MOSTRAR LISTADO DE ALUMNOS\n");
//    printf("-----------------------------------------\n");
//    mostrarAlumno(listado,alumnosValidos);
//    printf("EJERCICIO 3 - BUSCAR ALUMNO POR MATRICULA\n");
//    printf("------------------------------------------\n");
//    buscarAlumno(listado,alumnosValidos);
//    printf("EJERCICIO 4 - ORDENAR LOS ALUMNOS POR MATRICULA\n");
//    printf("------------------------------------------------\n");
//    ordenarSeleccion(listado,alumnosValidos);
//    mostrarAlumno(listado,alumnosValidos);
//    printf("EJERCICIO 5 - MOSTRAR ALUMNOS POR GENERO\n");
//    printf("-----------------------------------------\n");
//    mostrarPorGenero(listado,alumnosValidos,genra);
//    printf("EJERCICIO 6 - INSERTAR UN ARREGLO ORDENADO POR MATRICULA\n");
//    printf("---------------------------------------------------------\n");
//    stAlumno alumnoNuevo;
//    alumnosValidos=agregarAlumnoOrdenadoPorMatricula(listado,alumnosValidos,30, alumnoNuevo);
//    mostrarAlumno(listado, alumnosValidos);
//    printf("EJERCICIO 7 - ORDEN NOMBRE INSERCION\n");
//    printf("------------------------------------\n");
//    ordenarNombreInsercion(listado, alumnosValidos);
//    mostrarAlumno(listado,alumnosValidos);
//    printf("EJERCICIO 8 - CANTIDAD POR GENERO\n");
//    printf("------------------------------------\n");
//    cantidadGenero(listado,alumnosValidos,genra);
