#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "astronauta.h"



//REINICIAR SISTEMA
void reiniciarSistema()
{

    int reiniciador;
    char confirmacion[maxCaracteres];

    printf("|1| Reiniciar sistema\n|0|Seguir con los datos cargados\n");
    scanf("%i", &reiniciador);


    while (reiniciador != 1 && reiniciador != 0)
    {

        printf("Ingrese un valor valido\n");
        fflush(stdin);
        scanf("%i", &reiniciador);
    }


    while(reiniciador == 1)
    {

        printf("Escriba CONFIRMAR, para seguir ");
        fflush(stdin);
        gets(confirmacion);

        if  (strcmp(confirmacion, "CONFIRMAR") == 0)
        {

            astronautasPredeterminados();
            reiniciador =0;

        }

        else
        {
            printf("\nAsegurese de escribir CONFIRMAR de forma identica\n");
            printf("\n|1| Intentar nuevamente\n|0| Cerrar programa con datos guardados \n");
            int val;

            scanf("%i", &val);

            while (val != 0 &&  val != 1){

                printf("Inserte numero valido: ");
                fflush(stdin);
                scanf("%i", &val);
            }


            if(val == 1)
            {
                reiniciador = 1;
            }
            else
                reiniciador = 0;
        }


    }
}


//-----------OPCIONES DE ACIONES------------

void menuOpcionesFunciones()
{

    printf("\nQue queres hacer\n");
    printf("|1| CARGAR ASTRONAUTAS\n");
    printf("|2| BUSCAR ASTRONAUTA POR SU ID\n");
    printf("|3| CAMBIAR ESTADO DE ASTRONAUTA\n");
    printf("|4| MODIFICAR DATOS DEL ASTRONAUTA\n");
    printf("|5| MOSTRAR ASTRONAUTAS\n");

}


//----------------------------MODIFICAR ASTRNAUTA---------------------------------

void modificarAstronauta()
{


    FILE * archi = fopen(archiAstronauta, "r+b");

    printf("Seleccione el aspecto que desea modificar del astronauta: ");
    menuModificaciones();

    int dato;
    scanf("%i", &dato);

    while ( dato < 1 || dato > 11 ) {

        printf("Ingrese una opcion valida \n");
        fflush(stdin);
        scanf("%i", &dato);
    }
    astronauta astro;

    switch(dato)
    {

    case 1:
        cambiarNombreAstronauta();
        break;

    case 2:
        cambiarApellidoAstronauta();
        break;

    case 3:
        cambiarApodoAstronauta();
        break;

    case 4:
        cambiarEdadAstronauta();
        break;

    case 5:
        cambiarNacionalidadAstronauta();
        break;

    case 6:
        cambiarEspecialidadAstronauta();
        break;

    case 7:
        cambiarHorasVueloAcumuladasAstronauta();
        break;

    case 8:
        cambiarHorasEnEEI();
        break;

    case 9:
        cambiarMisionesEspaciales();
        break;

    case 10:
        cambiarEstadoAstronauta();
        break;

    default:
        printf("El numero ingresado no corresponde con las opciones");
        break;
    }

    fclose(archi);
}


void mostrarAstronautas(){

int opcion;
mostrarListaOpcionesMostrar();



scanf("%i", &opcion);

while(opcion < 1 || opcion > 3){


    printf("\nIngrese una opcion correcta: ");
    fflush(stdin);
    scanf("%i", &opcion);
}


switch(opcion){

case 1:
    mostrarAstronautaArchivo();
    break;

    case 2:
    mostrarAstronautasActivos();
    break;

    case 3:
    mostrarAstronautasRetirados();
    break;

}

}

void mostrarListaOpcionesMostrar(){
printf("\n Seleccione la opcion que desee\n");
printf("|1| Mostrar todos los astronautas\n");
printf("|2| Mostrar astronautas en activo\n");
printf("|3| Mostrar astronautas retirados\n");



}





void mostrarAstronautasActivos(){

astronauta astro;
FILE* archi =  fopen(archiAstronauta, "rb");


while (fread(&astro, sizeof(astronauta),1, archi) > 0){

    if(astro.estado == 1){

            mostrarDatosAstronauta(astro);

        }
    }

fclose(archi);
}


void mostrarAstronautasRetirados(){

astronauta astro;

FILE* archi = fopen(archiAstronauta, "rb");

while (fread(&astro, sizeof(astronauta), 1, archi) > 0){

    if (astro.estado == 2){

        mostrarDatosAstronauta(astro);
    }
}


}



//---------------MENU DE MMODIFICACIONES--------------------
void menuModificaciones()
{


    printf("\n|1| = Nombre \n");
    printf(  "|2| = Apellido\n");
    printf(  "|3| = Apodo\n");
    printf(  "|4| = Edad\n");
    printf(  "|5| = Nacionalidad\n");
    printf(  "|6| = Especialidad\n");
    printf(  "|7| = Horas de vuelo acumuladas\n");
    printf(  "|8| = Horas en la EEI\n");
    printf(  "|9| = Viajes realizados\n");
    printf(  "|10| = Estado\n");

}

//----------------CAMBIAR NOMBRE----------------------

void cambiarNombreAstronauta()
{
    menuID();
    int id = idBuscado();

    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarNombre(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;

        }
    }


    fclose(archi);
}


//----------CAMBIAR APELLIDO---------------
void cambiarApellidoAstronauta()
{
    menuID();
    int id = idBuscado();

    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarApellido(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;
        }
    }



    fclose(archi);
}

//----------------------CAMBIA APODO---------------------------------------------------------
void cambiarApodoAstronauta()
{
    menuID();
    int id = idBuscado();

    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarApodo(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;

        }
    }

    fclose(archi);
}


//--------------CAMBIAR ESTADO-------------------------

void cambiarEstadoAstronauta()
{
    astronauta astro;
    menuID();
    int id = idBuscado();
    int seleccion;

    FILE* archi = fopen(archiAstronauta, "r+b");

    printf("|1| DAR DE ALTA \n|2| DAR DE BAJA\n");
    scanf("%i", &seleccion);

    while (fread(&astro, sizeof(astronauta), 1, archi) > 0)
    {

        if(astro.ID == id)
        {
            astro.estado = seleccion;

            fseek(archi, sizeof(astronauta) * -1, SEEK_CUR);
            fwrite(&astro, sizeof(astronauta),1,archi);

            mostrarDatosAstronauta(astro);
            break;
        }
    }

    fclose(archi);
}


//------------------CAMBIAR EDAD--------------------------
void cambiarEdadAstronauta()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarEdad(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;

        }
    }

    fclose(archi);
}

//----------CAMBIAR NACIONALIDA--------------
void cambiarNacionalidadAstronauta()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarNacionalidad(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;

        }
    }

    fclose(archi);
}

//---------CAMBIAR ESPECIALIDAD------------------
void cambiarEspecialidadAstronauta()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarEspecialidad(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;

        }
    }

    fclose(archi);
}




//------------------ASTRONAUTAS PREDETERMINADOS---------------------

void astronautasPredeterminados()
{

    FILE * archi = fopen(archiAstronauta, "wb");

    astronauta astroPredeterminado1;


    astroPredeterminado1.ID = 101;
    strcpy(astroPredeterminado1.nombre, "Neil");
    strcpy(astroPredeterminado1.apellido, "Armstrong");
    strcpy(astroPredeterminado1.apodo, "Kike");
    astroPredeterminado1.edad = 34;
    strcpy(astroPredeterminado1.nacionalidad, "Estados Unidos");
    strcpy(astroPredeterminado1.especialidad, "Piloto");
    astroPredeterminado1.horasVueloAcumuladas = 346;
    astroPredeterminado1.horasAcumuladasEEI = 2067;
    astroPredeterminado1.misionesEspacialesRealizadas = 23;
    astroPredeterminado1.estado = 1;

    fwrite(&astroPredeterminado1, sizeof(astronauta),1,archi);

    astronauta astroPredeterminado2;

    astroPredeterminado2.ID = 102;
    strcpy(astroPredeterminado2.nombre, "Juan");
    strcpy(astroPredeterminado2.apellido, "Rodriguez");
    strcpy(astroPredeterminado2.apodo, "Cachito");
    astroPredeterminado2.edad = 29;
    strcpy(astroPredeterminado2.nacionalidad, "Mexico");
    strcpy(astroPredeterminado2.especialidad, "Ingeniero Espacial");
    astroPredeterminado2.horasVueloAcumuladas = 115;
    astroPredeterminado2.horasAcumuladasEEI = 0;
    astroPredeterminado2.misionesEspacialesRealizadas = 2;
    astroPredeterminado2.estado = 1;

    fwrite(&astroPredeterminado2, sizeof(astronauta),1,archi);

    astronauta astroPredeterminado3;

    astroPredeterminado3.ID = 103;
    strcpy(astroPredeterminado3.nombre, "Agustin");
    strcpy(astroPredeterminado3.apellido, "Grillo");
    strcpy(astroPredeterminado3.apodo, "Maestro");
    astroPredeterminado3.edad = 51;
    strcpy(astroPredeterminado3.nacionalidad, "Argentina");
    strcpy(astroPredeterminado3.especialidad, "Piloto");
    astroPredeterminado3.horasVueloAcumuladas = 568;
    astroPredeterminado3.horasAcumuladasEEI = 3867;
    astroPredeterminado3.misionesEspacialesRealizadas = 45;
    astroPredeterminado3.estado = 2;


    fwrite(&astroPredeterminado3, sizeof(astronauta),1,archi);

    astronauta astroPredeterminado4;


    astroPredeterminado4.ID = 104;
    strcpy(astroPredeterminado4.nombre, "Zlatan");
    strcpy(astroPredeterminado4.apellido, "Olsen");
    strcpy(astroPredeterminado4.apodo, "Tanol");
    astroPredeterminado4.edad = 32;
    strcpy(astroPredeterminado4.nacionalidad, "Suecia");
    strcpy(astroPredeterminado4.especialidad, "Astrofisico");
    astroPredeterminado4.horasVueloAcumuladas = 46;
    astroPredeterminado4.horasAcumuladasEEI = 1867;
    astroPredeterminado4.misionesEspacialesRealizadas = 7;
    astroPredeterminado4.estado = 1;

    fwrite(&astroPredeterminado4, sizeof(astronauta),1,archi);


    fclose(archi);
}


//-------------------GUARDAR ASTRONAUTAS EN ARCHIVO--------------------


void mostrarAstronautaArchivo()
{

    astronauta astro;

    FILE *archi;

    archi = fopen(archiAstronauta, "rb");


    while (fread(&astro, sizeof(astronauta),1,archi) > 0)
    {
        mostrarDatosAstronauta(astro);
    }

    fclose(archi);

}


//FUNCION PRINCIPAL PARA CARGAR EL ASTRONAUTA--------------------------------------------------------------------------


void cargarAstronautaNuevo(astronauta* astro)
{

    FILE* archi;

    archi = fopen(archiAstronauta, "ab+");

    astro->ID = ultimoId();
    cargarNombre(astro);
    cargarApellido(astro);
    cargarApodo(astro);
    cargarEdad(astro);
    cargarNacionalidad(astro);
    cargarEspecialidad(astro);
    astro->horasVueloAcumuladas = 0;
    astro->horasAcumuladasEEI = 0;
    astro->misionesEspacialesRealizadas = 0;
    astro->estado = 1;



    fwrite(astro, sizeof(astronauta),1, archi);

    fclose(archi);
}
//---------------CARGAR ID-------------------------------------------------------------------------------------------



//------------------CONOCAR TAMAÑO DEL ARCHIVO------------------------

int ultimoId()
{
    astronauta aux;

    FILE *archi = fopen(archiAstronauta,"rb");
    if(archi == NULL || tamanoArchi() == 0)
    {
        fclose(archi);
        return 1;
    }

    fseek(archi,(sizeof(astronauta) * -1),SEEK_END);
    fread(&aux,sizeof(astronauta),1,archi);

    printf("ID: %i", aux.ID + 1);
    return aux.ID + 1;

}



int tamanoArchi()
{
    FILE *fich;

    fich=fopen(archiAstronauta,"rb");

    fseek(fich, 0, SEEK_END);
    fclose(fich);
    return ftell(fich)/sizeof(astronauta);

}


//FUNCION QUE CARGA Y VALIDA EL NOMBRE---------------------------------------------------------------------------------

void cargarNombre(astronauta* astro)
{
    char nombre[maxCaracteres];
    printf("\nNombre: ");

    fflush(stdin);
    gets(nombre);

    int valido = validacionString(nombre);


    if(valido == 1)
    {
        strcpy(astro->nombre, nombre);
    }

    else if(valido == 0)
    {

        while (valido == 0)
        {

            printf("Ingrese un nombre valido\nNombre: ");
            fflush(stdin);
            gets(nombre);

            valido = validacionString(nombre);

        }
    }

    strcpy(astro->nombre, nombre);
}
//---------------------------------------------------------------------------------------------------------------------

//VALIDA QUE EL STRING INGRESADO NO TENGA NUMEROS Y SEA UNICAMENTE LETRAS----------------------------------------------
int validacionString(char string[maxCaracteres])
{

    int cantidadCaracteres = strlen(string);
    int i;

    for (i = 0; i < cantidadCaracteres; i++)
    {
        char caracter = string[i];

        if (isalpha(caracter) == 0)
        {
            return 0;
        }
    }

    return 1;
}
//---------------------------------------------------------------------------------------------------------------------

//CARGA Y VALIDA EL APELLIDO-------------------------------------------------------------------------------------------
void cargarApellido(astronauta* astro)
{

    char apellido[maxCaracteres];

    printf("\nApellido: ");

    fflush(stdin);
    gets(apellido);
    int valido = validacionString(apellido);

    if(valido == 1)
    {
        strcpy(astro->apellido, apellido);
    }
    else if (valido == 0)
    {
        while (valido == 0)
        {

            printf("Inserte un apellido valido\nApellido: ");
            fflush(stdin);
            gets(apellido);

            valido = validacionString(apellido);
        }
    }

    strcpy(astro->apellido,apellido);
}
//---------------------------------------------------------------------------------------------------------------------

//CARGA Y VALIDA EL APODO----------------------------------------------------------------------------------------------
void cargarApodo(astronauta* astro)
{

    char apodo[maxCaracteres];

    printf("\nApodo: ");
    fflush(stdin);
    gets(apodo);

    int valido = validacionString(apodo);

    if(valido == 1)
    {

        strcpy(astro->apodo, apodo);

    }

    else if(valido == 0)
    {
        while(valido == 0)
        {
            printf("Ingrese un apodo valido\nApodo: ");
            fflush(stdin);
            gets(apodo);

            valido = validacionString(apodo);
        }
    }

    strcpy(astro->apodo, apodo);
}
//---------------------------------------------------------------------------------------------------------------------

//MUESTRA DATOS DEL ASTRONAUTA (FALTA COMPLETAR)-----------------------------------------------------------------------
void mostrarDatosAstronauta(astronauta astro)
{
    printf("\nID------------------------------- %i", astro.ID);
    printf("\nNOMBRE--------------------------- %s", astro.nombre);
    printf("\nAPELLIDO------------------------- %s", astro.apellido);
    printf("\nAPODO---------------------------- %s", astro.apodo);
    printf("\nEDAD----------------------------- %i", astro.edad);
    printf("\nNACIONALIDAD--------------------- %s", astro.nacionalidad);
    printf("\nESPECIALIDAD--------------------- %s", astro.especialidad);
    printf("\nHORAS DE VUELO ACUMULADAS-------- %i", astro.horasVueloAcumuladas);
    printf("\nHORAS ACUMULADAS DE EEI---------- %i", astro.horasAcumuladasEEI);
    printf("\nMISIONES ESPACIALES ACUMULADAS--- %i", astro.misionesEspacialesRealizadas);
    printf("\nESTADO |1|activo |2|inactivo----- %i", astro.estado);

    printf("\n");

}
//---------------------------------------------------------------------------------------------------------------------


//CARGA Y VALIDA LA NACIONALIDAD POR MEDIO DE UN MENU------------------------------------------------------------------
void cargarNacionalidad(astronauta* astro)
{
    int catalogo;
    int valido;
    char nacionalidades[cantNacionalidades][maxCaracteres];

    baseNacionalidades(nacionalidades);

    char nacionalidad[maxCaracteres];

    printf("\nNacionalidad: ");
    fflush(stdin);
    gets(nacionalidad);

    valido = validacionNacionalidad(nacionalidad, nacionalidades);

    if(valido == 1)
    {

        strcpy(astro->nacionalidad, nacionalidad);
    }
    else if(valido == 0)
    {

        while(valido == 0)
        {

            printf("\nLas naccionalidades deben ser con la inicial en mayuscula\n");
            printf("\n0 = Escribir nuevamente \n");
            printf("1 = Menu de nacinalidades \n");

            scanf("%i", &catalogo);

            if(catalogo == 1)
            {

                mostrarCatalogoNacionalidades(nacionalidades);
            }

            printf("\nNacionalidad: ");
            fflush(stdin);
            gets(nacionalidad);


            valido = validacionNacionalidad(nacionalidad, nacionalidades);
        }
    }

    strcpy(astro->nacionalidad, nacionalidad);
}
//---------------------------------------------------------------------------------------------------------------------

//VALIDA QUE LA NACIONALIDAD INSERTADA SEA VALIDA CON RESPECTO A LOS PAISES ACTUALES DEL MUNDO-------------------------
int validacionNacionalidad(char nacionalidad[maxCaracteres], char nacionalidades[cantNacionalidades][maxCaracteres])
{

    int i;

    for(i = 0; i < cantNacionalidades; i++)
    {

        if(strcmp(nacionalidad, nacionalidades[i]) == 0)
        {
            return 1;
        }

    }

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------



//CARGA EN LA MATRIZ INGRESADA TODOS LOS PAISES VALIDOS ACTUALMENTE----------------------------------------------------
void baseNacionalidades(char nacionalidades[cantNacionalidades][maxCaracteres])
{
    //15 A-------------------------------


    strcpy(nacionalidades[0],"Afganistan");
    strcpy(nacionalidades[1],"Albania");
    strcpy(nacionalidades[2],"Alemania");
    strcpy(nacionalidades[3],"Andorra");
    strcpy(nacionalidades[4],"Angola");
    strcpy(nacionalidades[5],"Antigua y Barbuda");
    strcpy(nacionalidades[6],"Antillas Holandesas");
    strcpy(nacionalidades[7],"Arabia Saudi");
    strcpy(nacionalidades[8],"Argelia");
    strcpy(nacionalidades[9],"Argentina");
    strcpy(nacionalidades[10],"Armenia");
    strcpy(nacionalidades[11],"Aruba");
    strcpy(nacionalidades[12],"Australia");
    strcpy(nacionalidades[13],"Austria");
    strcpy(nacionalidades[14],"Azerbaiyan");

    // 18 B------------------------------


    strcpy(nacionalidades[15],"Bahamas");
    strcpy(nacionalidades[16],"Bahrein");
    strcpy(nacionalidades[17],"Bangladesh");
    strcpy(nacionalidades[18],"Barbados");
    strcpy(nacionalidades[19],"Belgica");
    strcpy(nacionalidades[20],"Belice");
    strcpy(nacionalidades[21],"Benin");
    strcpy(nacionalidades[22],"Bermudas");
    strcpy(nacionalidades[23],"Bielorrusia");
    strcpy(nacionalidades[24],"Bolivia");
    strcpy(nacionalidades[25],"Botsuana");
    strcpy(nacionalidades[26],"Bosnia");
    strcpy(nacionalidades[27],"Brasil");
    strcpy(nacionalidades[28],"Brunei");
    strcpy(nacionalidades[29],"Bulgaria");
    strcpy(nacionalidades[30],"Burkina Faso");
    strcpy(nacionalidades[31],"Burundi");
    strcpy(nacionalidades[32],"Butan");



    //17 C-------------------------------


    strcpy(nacionalidades[33],"Cabo Verde");
    strcpy(nacionalidades[34],"Camboya");
    strcpy(nacionalidades[35],"Camerun");
    strcpy(nacionalidades[36],"Canada");
    strcpy(nacionalidades[37],"Catar");
    strcpy(nacionalidades[38],"Chile");
    strcpy(nacionalidades[39],"China");
    strcpy(nacionalidades[40],"Chipre");
    strcpy(nacionalidades[41],"Colombia");
    strcpy(nacionalidades[42],"Comoras");
    strcpy(nacionalidades[43],"Congo");
    strcpy(nacionalidades[44],"Corea del Norte");
    strcpy(nacionalidades[45],"Corea del Sur");
    strcpy(nacionalidades[46],"Costa de Marfil");
    strcpy(nacionalidades[47],"Costa Rica");
    strcpy(nacionalidades[48],"Croacia");
    strcpy(nacionalidades[49],"Cuba");



    //2 D--------------------------------


    strcpy(nacionalidades[50],"Dinamarca");
    strcpy(nacionalidades[51],"Dominica");

    //11 E-------------------------------

    strcpy(nacionalidades[52],"Ecuador");
    strcpy(nacionalidades[53],"Egipto");
    strcpy(nacionalidades[54],"El Salvador");
    strcpy(nacionalidades[55],"Emiratos Arabes");
    strcpy(nacionalidades[56],"Eritrea");
    strcpy(nacionalidades[57],"Eslovaquia");
    strcpy(nacionalidades[58],"Eslovenia");
    strcpy(nacionalidades[59],"Espana");
    strcpy(nacionalidades[60],"Estados Unidos");
    strcpy(nacionalidades[61],"Estonia");
    strcpy(nacionalidades[62],"Etiopia");

    //4 F--------------------------------

    strcpy(nacionalidades[63],"Fiyi");
    strcpy(nacionalidades[64],"Filipinas");
    strcpy(nacionalidades[65],"Finlandia");
    strcpy(nacionalidades[66],"Francia");


    //13 G-------------------------------

    strcpy(nacionalidades[67],"Gabon");
    strcpy(nacionalidades[68],"Gambia");
    strcpy(nacionalidades[69],"Georgia");
    strcpy(nacionalidades[70],"Ghana");
    strcpy(nacionalidades[71],"Grecia");
    strcpy(nacionalidades[72],"Guam");
    strcpy(nacionalidades[73],"Guatemala");
    strcpy(nacionalidades[74],"Guayana Francesa");
    strcpy(nacionalidades[75],"Guinea-Bissau");
    strcpy(nacionalidades[76],"Guinea Ecuatorial");
    strcpy(nacionalidades[77],"Guinea");
    strcpy(nacionalidades[78],"Guyana");
    strcpy(nacionalidades[79],"Granada");

    //5 H--------------------------------

    strcpy(nacionalidades[80],"Haiti");
    strcpy(nacionalidades[81],"Honduras");
    strcpy(nacionalidades[82],"Hong Kong");
    strcpy(nacionalidades[83],"Hungria");
    strcpy(nacionalidades[84],"Holanda");

    //12 I-------------------------------

    strcpy(nacionalidades[85],"India");
    strcpy(nacionalidades[86],"Indonesia");
    strcpy(nacionalidades[87],"Irak");
    strcpy(nacionalidades[88],"Iran");
    strcpy(nacionalidades[89],"Irlanda");
    strcpy(nacionalidades[90],"Islandia");
    strcpy(nacionalidades[91],"Islas Caiman");
    strcpy(nacionalidades[92],"Islas Marshall");
    strcpy(nacionalidades[93],"Islas Pitcairn");
    strcpy(nacionalidades[94],"Islas Salomon");
    strcpy(nacionalidades[95],"Israel");
    strcpy(nacionalidades[96],"Italia");

    //3 J--------------------------------

    strcpy(nacionalidades[97],"Jamaica");
    strcpy(nacionalidades[98],"Japon");
    strcpy(nacionalidades[99],"Jordania");

    //6 K--------------------------------

    strcpy(nacionalidades[100],"Kazajstan");
    strcpy(nacionalidades[101],"Kenia");
    strcpy(nacionalidades[102],"Kirguistan");
    strcpy(nacionalidades[103],"Kiribati");
    strcpy(nacionalidades[104],"Kosovo");
    strcpy(nacionalidades[105],"Kuwait");

    //9 L--------------------------------

    strcpy(nacionalidades[106],"Laos");
    strcpy(nacionalidades[107],"Lesotho");
    strcpy(nacionalidades[108],"Letonia");
    strcpy(nacionalidades[109],"Libano");
    strcpy(nacionalidades[110],"Liberia");
    strcpy(nacionalidades[111],"Libia");
    strcpy(nacionalidades[112],"Liechtenstein");
    strcpy(nacionalidades[113],"Lituania");
    strcpy(nacionalidades[114],"Luxemburgo");

    //19 M-------------------------------

    strcpy(nacionalidades[115],"Macedonia");
    strcpy(nacionalidades[116],"Madagascar");
    strcpy(nacionalidades[117],"Malasia");
    strcpy(nacionalidades[118],"Malawi");
    strcpy(nacionalidades[119],"Maldivas");
    strcpy(nacionalidades[120],"Mali");
    strcpy(nacionalidades[121],"Malta");
    strcpy(nacionalidades[122],"Marianas del Norte");
    strcpy(nacionalidades[123],"Marruecos");
    strcpy(nacionalidades[124],"Mauricio");
    strcpy(nacionalidades[125],"Mauritania");
    strcpy(nacionalidades[126],"Mexico");
    strcpy(nacionalidades[127],"Micronesia");
    strcpy(nacionalidades[128],"Monaco");
    strcpy(nacionalidades[129],"Moldavia");
    strcpy(nacionalidades[130],"Mongolia");
    strcpy(nacionalidades[131],"Montenegro");
    strcpy(nacionalidades[132],"Mozambique");
    strcpy(nacionalidades[133],"Myanmar");

    //8 N--------------------------------

    strcpy(nacionalidades[134],"Namibia");
    strcpy(nacionalidades[135],"Nauru");
    strcpy(nacionalidades[136],"Nepal");
    strcpy(nacionalidades[137],"Nicaragua");
    strcpy(nacionalidades[138],"Niger");
    strcpy(nacionalidades[139],"Nigeria");
    strcpy(nacionalidades[140],"Noruega");
    strcpy(nacionalidades[141],"Nueva Zelanda");

    //2 O--------------------------------

    strcpy(nacionalidades[142],"Oman");
    strcpy(nacionalidades[143],"Orden de Malta");

    //11 P-------------------------------

    strcpy(nacionalidades[144],"Paises Bajos");
    strcpy(nacionalidades[145],"Pakistan");
    strcpy(nacionalidades[146],"Palestina");
    strcpy(nacionalidades[147],"Palau");
    strcpy(nacionalidades[148],"Panama");
    strcpy(nacionalidades[149],"Papua Nueva Guinea");
    strcpy(nacionalidades[150],"Paraguay");
    strcpy(nacionalidades[151],"Peru");
    strcpy(nacionalidades[152],"Polonia");
    strcpy(nacionalidades[153],"Portugal");
    strcpy(nacionalidades[154],"Puerto Rico");

    //9 R--------------------------------

    strcpy(nacionalidades[155],"Reino Unido");
    strcpy(nacionalidades[156],"Republica Centroafricana");
    strcpy(nacionalidades[157],"Republica Checa");
    strcpy(nacionalidades[158],"Republica del Congo");
    strcpy(nacionalidades[159],"Republica Democratica del Congo");
    strcpy(nacionalidades[160],"Republica Dominicana");
    strcpy(nacionalidades[161],"Ruanda");
    strcpy(nacionalidades[162],"Rumania");
    strcpy(nacionalidades[163],"Rusia");

    //22 S-------------------------------

    strcpy(nacionalidades[164],"Sahara Occidental");
    strcpy(nacionalidades[165],"Samoa Americana");
    strcpy(nacionalidades[166],"Samoa");
    strcpy(nacionalidades[167],"San Cristobal y Nieves");
    strcpy(nacionalidades[168],"San Marino");
    strcpy(nacionalidades[169],"Santa Lucia");
    strcpy(nacionalidades[170],"Santo Tome y Principe");
    strcpy(nacionalidades[171],"San Vicente y las Granadinas");
    strcpy(nacionalidades[172],"Senegal");
    strcpy(nacionalidades[173],"Serbia");
    strcpy(nacionalidades[174],"Seychelles");
    strcpy(nacionalidades[175],"Sierra Leona");
    strcpy(nacionalidades[176],"Singapur");
    strcpy(nacionalidades[177],"Siria");
    strcpy(nacionalidades[178],"Somalia");
    strcpy(nacionalidades[179],"Sri Lanka");
    strcpy(nacionalidades[180],"Sudafrica");
    strcpy(nacionalidades[181],"Sudan");
    strcpy(nacionalidades[182],"Sudan del Sur");
    strcpy(nacionalidades[183],"Suecia");
    strcpy(nacionalidades[184],"Suiza");
    strcpy(nacionalidades[185],"Suazilandia");

    //13 T-------------------------------

    strcpy(nacionalidades[186],"Tilandia");
    strcpy(nacionalidades[187],"Taiwan");
    strcpy(nacionalidades[188],"Tanzania");
    strcpy(nacionalidades[189],"Tayikistan");
    strcpy(nacionalidades[190],"Tibet");
    strcpy(nacionalidades[191],"Timor Oriental");
    strcpy(nacionalidades[192],"Togo");
    strcpy(nacionalidades[193],"Tonga");
    strcpy(nacionalidades[194],"Trinidad y Tobago");
    strcpy(nacionalidades[195],"Tunez");
    strcpy(nacionalidades[196],"Turkmenistan");
    strcpy(nacionalidades[197],"Turquia");
    strcpy(nacionalidades[198],"Tuvalu");

    //4 U--------------------------------

    strcpy(nacionalidades[199],"Ucrania");
    strcpy(nacionalidades[200],"Uganda");
    strcpy(nacionalidades[201],"Uruguay");
    strcpy(nacionalidades[202],"Uzbequistan");

    //4 V--------------------------------

    strcpy(nacionalidades[203],"Vanuatu");
    strcpy(nacionalidades[204],"Vaticano");
    strcpy(nacionalidades[205],"Venezuela");
    strcpy(nacionalidades[206],"Vietnam");

    //1 W--------------------------------


    strcpy(nacionalidades[207],"Wallis y Futuna");

    //2 Y--------------------------------

    strcpy(nacionalidades[208],"Yemen");
    strcpy(nacionalidades[209],"Yibuti");

    //3 Z--------------------------------

    strcpy(nacionalidades[210],"Zambia");
    strcpy(nacionalidades[211],"Zaire");
    strcpy(nacionalidades[212],"Zimbabue");
}
//---------------------------------------------------------------------------------------------------------------------


//CARGA Y VALIDA LA EDAD HACIENDO QUE SEA MAYOR DE 18 Y MENOR DE 100 AÑOS----------------------------------------------
void cargarEdad(astronauta* astro)
{

    int edad;

    printf("\nEdad: ");
    scanf("%i", &edad);


    int valido = validacionEdad(edad);

    if(valido == 1 )
    {
        astro->edad = edad;
    }
    else if (valido == 0)
    {

        while (valido == 0)
        {

            printf("\nInsertar una edad valida(+18 y -100)\nEDAD: ");
            fflush(stdin);
            scanf("%i", &edad);

            valido = validacionEdad(edad);
        }

        astro->edad = edad;
    }

}
//---------------------------------------------------------------------------------------------------------------------



//VALIDA LA CONDICION DE +18 Y -100 AÑOS-------------------------------------------------------------------------------
int validacionEdad(int edad)
{
    int valido = 0;
    if(edad >= 18 && edad < 100)
    {

        valido = 1;
    }
    else
    {
        valido = 0;

    }

    return valido;
}
//---------------------------------------------------------------------------------------------------------------------


//MUESTRA EL CATALOGO DE 213 PAISES Y LE ASIGNA UN VALOR PARA INSERTAR A CADA UNO DE ELLOS-----------------------------
void mostrarCatalogoNacionalidades(char nacionalidades[cantNacionalidades][maxCaracteres])
{

    int i = 0;

    printf("\nLISTA DE PAISES: \n");

    while(i < cantNacionalidades)
    {
        printf("%s\n", nacionalidades[i]);
        i++;
    }
}
//---------------------------------------------------------------------------------------------------------------------



//CARGA LA ESPECIALIDAD POR MEDIO DE UN MENU---------------------------------------------------------------------------
void  cargarEspecialidad(astronauta* astro)
{

    int seleccion;

    char especialidades[cantEspecialidades][maxCaracteres];
    especialidadesAstronauta(especialidades);

    printf("Seleccione la especialidad \n");
    mostrarEspecialidades(especialidades);
    scanf("%i", &seleccion);




    int valido = validacionEspecialidad(seleccion);

    if(valido == 1)
    {

        strcpy(astro->especialidad,especialidades[seleccion - 1]);

    }
    else if (valido == 0)
    {

        while (valido == 0)
        {

            printf("Inserta un numero asociado a una especialidad\nESPECIALIDAD: ");
            fflush(stdin);
            scanf("%i", &seleccion);

            valido = validacionEspecialidad(seleccion);
        }
    }
    strcpy(astro->especialidad,especialidades[seleccion - 1]);
}
//---------------------------------------------------------------------------------------------------------------------

//VALIDA QUE EL NUMERO INSERTADO ESTE ASOCIADO A ALGUNO DE LAS ESPECIALIDADES MOSTRADAS EN EL MENU---------------------
int validacionEspecialidad (int seleccion)
{

    int valido = 0;

    if(seleccion <= cantEspecialidades && seleccion > 0)
    {

        valido = 1;

    }
    else
    {

        valido = 0;
    }

    return valido;
}
//---------------------------------------------------------------------------------------------------------------------


//MUESTRA LA ESPECIALIDADES Y LE ASIGNA UN NUMERO A CADA UNO PARA INSERTAR Y ESCOGER UNA ESPECUALIDAD------------------
void mostrarEspecialidades(char especialidades[][maxCaracteres])
{

    int i = 0;
    int pos = 1;

    while (i< cantEspecialidades)
    {

        printf( "%i = ", pos);
        printf("%s \n", especialidades[i]);

        pos++;
        i++;
    }
}
//---------------------------------------------------------------------------------------------------------------------


//CARGA EN UNA MATRIZ INSERTADA LAS ESPECIALIDADES QUE LUEGO PODRAN SER ESCOGIDAS--------------------------------------
void especialidadesAstronauta(char especialidades[][maxCaracteres])
{


    printf("\n");
    strcpy(especialidades[0], "Piloto");
    strcpy(especialidades[1], "Astrofisico");
    strcpy(especialidades[2], "Ingeniero Espacial");
    strcpy(especialidades[3], "Biologo");
    strcpy(especialidades[4], "Comericial");

}



//BUSCA EL ASTRONAUTA QUE PERTENEZCA AL ID CORRESPONDIENT-------
void buscarAstronautaPorId()
{
    menuID();
    int id = idBuscado();


    FILE* archi = fopen(archiAstronauta, "rb");

    astronauta astro;

    while(fread(&astro, sizeof(astronauta), 1, archi) > 0)
    {
        if(astro.ID == id)
        {

            mostrarDatosAstronauta(astro);
            break;
        }
    }
    fclose(archi);
}

//EN CASO DE NO QUERER REALIZAR MAS OPERACIONES("no") MANDA UN SALUDO
void saludoFinal(char valor[2])
{

if(strcmp(valor, "no") == 0){

    printf("\n\n-------NOS VEMOS LA PROXIMA-------\n\n");
}
}


//CAMBIA LAS HORAS DE VUELO
void cambiarHorasVueloAcumuladasAstronauta()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarHorasVueloAcumuladas(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;
        }
    }

    fclose(archi);
}

//CARGA LAS HORAS DE VUELO ACUMULADAS
void cargarHorasVueloAcumuladas(astronauta *astro)
{

    int horas;

    printf("\ncantidad de horas de vuelo acumuladas: ");
    scanf("%i", &horas);


    int valido = validacionHoras(horas);

    if(valido == 1 )
    {
        astro->horasVueloAcumuladas = horas;
    }
    else if (valido == 0)
    {

        while (valido == 0)
        {

            printf("\nInsertar cantidad de horas de vuelo validas: ");
            fflush(stdin);
            scanf("%i", &horas);

            valido = validacionHoras(horas);
        }

        astro->horasVueloAcumuladas = horas;
    }
}


//CARGA HORAS EN EEI
void cargarHorasEnEEI(astronauta *astro)
{

    int horas;

    printf("\ncantidad de horas en la EEI: ");
    scanf("%i", &horas);


    int valido = validacionHoras(horas);

    if(valido == 1 )
    {
        astro->horasAcumuladasEEI = horas;
    }
    else if (valido == 0)
    {

        while (valido == 0)
        {

            printf("\nInsertar cantidad de horas de vuelo validas: ");
            fflush(stdin);
            scanf("%i", &horas);

            valido = validacionHoras(horas);
        }

        astro->horasAcumuladasEEI = horas;
    }
}


//CAMBIA LAS HORAS EN EEI
void cambiarHorasEnEEI()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarHorasEnEEI(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;
        }
    }

    fclose(archi);
}

//CARGA LAS MISIONES ESPACIALES REALIZADAS
void cargarMisionesEspaciales(astronauta *astro)
{

    int misiones;

    printf("\ncantidad de horas en la EEI: ");
    scanf("%i", &misiones);


    int valido = validacionHoras(misiones);

    if(valido == 1 )
    {
        astro->misionesEspacialesRealizadas = misiones;
    }
    else if (valido == 0)
    {

        while (valido == 0)
        {

            printf("\nInsertar cantidad de horas de vuelo validas: ");
            fflush(stdin);
            scanf("%i", &misiones);

            valido = validacionHoras(misiones);
        }

        astro->misionesEspacialesRealizadas = misiones;
    }
}

//CAMBIA LA CANTIDAD DE MISIONES ESPACIALES REALIZADAS
void cambiarMisionesEspaciales()
{
    menuID();
    int id = idBuscado();
    astronauta astro;

    FILE * archi = fopen(archiAstronauta, "r+b");

    while (fread(&astro, sizeof(astronauta),1, archi))
    {

        if(astro.ID == id)
        {

            fseek(archi,sizeof(astronauta) * -1, SEEK_CUR);

            cargarMisionesEspaciales(&astro);

            fwrite(&astro, sizeof(astronauta),1, archi);

            mostrarDatosAstronauta(astro);
            break;
        }
    }

    fclose(archi);
}


//VALIDA QUE LAS HORAS DE VUELO SEAN MAYORES A 0
int validacionHoras(int horas)
{
    int valido = 0;
    if(horas >= 0)
    {

        valido = 1;
    }
    else
    {
        valido = 0;

    }

    return valido;
}




//MUESTRA LA LISTA DE LOS ID EXISTENTE
void mostrarListaID()
{
FILE* archi;

archi = fopen(archiAstronauta, "rb");
astronauta astro;

while (fread(&astro, sizeof(astronauta), 1, archi) > 0){

    printf("ID: %i\n", astro.ID);
}

fclose(archi);
}



void menuID(){

int opera;


printf("\n|1|  Para ver menu de id \n|0|  Para seguir\n");
fflush(stdin);
scanf("%i", &opera);

while (opera != 1 && opera != 0){

    printf("Ingrese una opcion disponible: ");
    fflush(stdin);
    scanf("%i", &opera);

}

if (opera == 1){
    printf("\n");

    mostrarListaID();

    printf("\n");
}

else if (opera == 0)
{

    return;

}
}



int idBuscado()
{

    int iDBusca;
    int valido = 0;
    astronauta astro;


    FILE* archi;

    archi = fopen(archiAstronauta, "rb");


    printf("Inserte el ID del Astronauta: ");
    scanf("%i", &iDBusca);

    valido = validacionID(iDBusca);

    if (valido == 1){

        return iDBusca;
    }
    else if (valido == 0){

        while (valido == 0){

            printf("Inserta id correcto\n");
            menuID();
            printf("ID: ");
            scanf("%i", &iDBusca);
            valido = validacionID(iDBusca);
        }

        return iDBusca;
    }

    fclose(archi);
}




int validacionID(int id){

int validacion = 0;

FILE* archi;

archi = fopen(archiAstronauta, "rb");

astronauta astro;

while(fread(&astro, sizeof(astronauta), 1, archi) > 0){

    if(id == astro.ID){

        return 1;
    }

}

return 0;
}
