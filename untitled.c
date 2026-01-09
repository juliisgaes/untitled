// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

int menu(float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr) {

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
	DrawRectangle(*posicion_jugador_x_ptr, *posicion_jugador_y_ptr, 50, 50, WHITE);

	return 0;

}

int main(void) {

	// Inicializando variables.
	int escena_actual = 1;
	float posicion_jugador_x = 0, posicion_jugador_y = 450;

	// Inicializando punteros.
	float* posicion_jugador_x_ptr = &posicion_jugador_x;
	float* posicion_jugador_y_ptr = &posicion_jugador_y;

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
			case 1:
				menu(posicion_jugador_x_ptr, posicion_jugador_y_ptr);
			break;
		}

		// Terminando de dibujar.
		EndDrawing();

	}

	return 0;

}
