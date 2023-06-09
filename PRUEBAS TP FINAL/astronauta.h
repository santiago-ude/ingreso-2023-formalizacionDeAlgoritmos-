
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxCaracteres 100
#define cantNacionalidades 213
#define cantEspecialidades 5
#define cantidadOpciones 5

//---------------------------ARCHIVO----------------------------

#define archiAstronauta "astronauta.bin"

//-------------------ESTRUCTURAS------------------------------------

typedef struct
{
    int ID;
    char nombre[maxCaracteres];
    char apellido[maxCaracteres];
    char apodo[maxCaracteres];
    int edad;
    char nacionalidad[maxCaracteres];
    char especialidad[maxCaracteres];
    int horasVueloAcumuladas;
    int misionesEspacialesRealizadas;
    int horasAcumuladasEEI;
    int estado;
} astronauta;


//-------------------DECLARACION DE FUNCIONES-------------------------------------------


//------------------CARGAR ITEMS------------------------
void cargarNombre(astronauta* astro);

void cargarAstronautaNuevo(astronauta* astro);

void cargarApellido(astronauta* astro);

void cargarApodo(astronauta* astro);

void cargarNacionalidad(astronauta* astro);

void cargarEdad(astronauta* astro);

void cargarEspecialidad(astronauta* astro);

void astronautasPredeterminados();

void buscarAstronautaPorId();

void cargarId();

void cargarHorasVueloAcumuladas();

void cargarHorasEnEEI(astronauta *astro);

void cargarMisionesEspaciales(astronauta *astro);


//MOSTRAR COSAS

void mostrarDatosAstronauta(astronauta astronauta);

void mostrarCatalogoNacionalidades(char nacionalidades[66][maxCaracteres]);

void mostrarEspecialidades(char especialidades[][maxCaracteres]);

void baseNacionalidades(char nacionalidades[cantNacionalidades][maxCaracteres]);

void especialidadesAstronauta(char especialidades[][maxCaracteres]);

void mostrarAstronautaArchivo();

void menuModificaciones();

void menuOpcionesFunciones();

void menuID();

void mostrarListaID();


void mostrarAstronautas();

void mostrarListaOpcionesMostrar();

void mostrarAstronautasRetirados();

void mastrarAstronautasActivos();





//VALIDACIONES

int  validacionEdad(int edad);

int  validacionString(char string[maxCaracteres]);

int validacionEspecialidad (int seleccion);

int validacionNacionalidad(char nacionalidad[maxCaracteres], char nacionalidades[cantNacionalidades][maxCaracteres]);

void validacionRespuesta(char valor);

int validacionHoras(int horas);

int confirmarID(int idBuscado, int *confirm );

//-----------------DATOS DE RELEVANCIA-------------------

int ultimoId();

int tamanoArchi();

int idBuscado();




//--------------------MODIFICAR DATOS DEL ASTRONAUTA------------

void cambiarEstadoAstronauta();

void modificarAstronauta();

void cambiarNombreAstronauta();

void cambiarApellidoAstronauta();

void cambiarApodoAstronauta();

void cambiarEdadAstronauta();

void cambiarNacionalidadAstronauta();

void cambiarEspecialidadAstronauta();

void saludoFinal(char valor[2]);

void cambiarHorasVueloAcumuladasAstronauta();

void cambiarHorasEnEEI();

void cambiarMisionesEspaciales();

void reiniciarSistema();
