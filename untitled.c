// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

// Probablemente en un futuro esto se encuentre en un archivo "header".
int menu(bool* depuracion_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D cursor);

// Función principal.
int main(void) {

	// Declarando variables.
	bool depuracion = true;
	unsigned int escena_actual;

	// Declarando punteros.
	bool* depuracion_ptr = &depuracion;
	unsigned int* escena_actual_ptr = &escena_actual;

	// Creando la ventana principal.
	InitWindow(500, 500, "untitled - 0.1");

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

			// Cargando menú.
			case 0:
				float* posicion_jugador_x_ptr = MemAlloc(sizeof(float));
				float* posicion_jugador_y_ptr = MemAlloc(sizeof(float));
				*posicion_jugador_y_ptr = 450;
				Texture2D cursor = LoadTexture("recursos/cursor.png");
				escena_actual++;
			break;

			// Ejecutando menú.
			case 1:
				menu(depuracion_ptr, escena_actual_ptr, posicion_jugador_x_ptr, posicion_jugador_y_ptr, cursor);
			break;

			// Descargando menú.
			case 2:
				MemFree(posicion_jugador_x_ptr);
				MemFree(posicion_jugador_y_ptr);
				UnloadTexture(cursor);
			break;

		}

		// Terminando de dibujar.
		EndDrawing();

	}

	return 0;

}

// Menú inicial.
int menu(bool* depuracion_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D cursor) {

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
	if (IsKeyDown(KEY_P)) {
		
		*escena_actual_ptr = 2;

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
