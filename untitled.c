// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

// Probablemente en un futuro esto se encuentre en un archivo "header".
int menu(bool* depuracion_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D cursor);

// Función principal.
int main(void) {

	// Inicializando variables.
	bool depuracion = true;
	int escena_actual = 1;
	float posicion_jugador_x = 0, posicion_jugador_y = 450;

	// Inicializando punteros.
	bool* depuracion_ptr = &depuracion;
	float* posicion_jugador_x_ptr = &posicion_jugador_x;
	float* posicion_jugador_y_ptr = &posicion_jugador_y;

	// Creando la ventana principal.
	InitWindow(500, 500, "untitled - 0.1");

	// Cargando texturas a la gpu.
	Texture2D cursor = LoadTexture("recursos/cursor.png");

	// Estableciendo el límite de FPS.
	SetTargetFPS(60);

	// Bucle para actualizar pantalla.
	while (!WindowShouldClose()) {

		// Comenzando a dibujar.
		BeginDrawing();

		// Limpiando el canvas.
		ClearBackground(GRAY);

		// Comprobación de escenas.
		switch (escena_actual) {
			case 1:
				menu(depuracion_ptr, posicion_jugador_x_ptr, posicion_jugador_y_ptr, cursor);
			break;
		}

		// Terminando de dibujar.
		EndDrawing();

	}

	// Descargando texturas de la gpu.
	UnloadTexture(cursor);

	return 0;

}

// Menú inicial.
int menu(bool* depuracion_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D cursor) {

	// Comprobando entradas del jugador.
	if (IsKeyDown(KEY_D) && *posicion_jugador_x_ptr <= 450) {

		*posicion_jugador_x_ptr += 100 * GetFrameTime();

	}
	if (IsKeyDown(KEY_W) && *posicion_jugador_y_ptr >= 0) {
	
		*posicion_jugador_y_ptr -= 100 * GetFrameTime();
	
	}
	if (IsKeyDown(KEY_A) && *posicion_jugador_x_ptr >= 0) {
	
		*posicion_jugador_x_ptr -= 100 * GetFrameTime();

	}
	if (IsKeyDown(KEY_S) && *posicion_jugador_y_ptr <= 450) {
			
		*posicion_jugador_y_ptr += 100 * GetFrameTime();

	}

	// Creando al jugador.
	DrawTexture(cursor, *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, WHITE);

	// Cosas para depuración.
	if (*depuracion_ptr == true) {

		// Mostrando las coordenadas del jugador en pantalla.
		DrawText(TextFormat("posición x del jugador: %f\nposición y del jugador: %f", *posicion_jugador_x_ptr, *posicion_jugador_y_ptr), 0, 0, 10, WHITE);

	}

	return 0;

}
