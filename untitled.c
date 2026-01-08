// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

int main(void) {

	// Inicializando variables.
	float posición_jugador_x = 0, posición_jugador_y = 450;

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

		// Comprobando entradas del jugador.
		if (IsKeyDown(KEY_D) && posición_jugador_x <= 450) {
		
			posición_jugador_x += 100 * GetFrameTime();

		}
		if (IsKeyDown(KEY_W) && posición_jugador_y >= 0) {
		
			posición_jugador_y -= 100 * GetFrameTime();
		
		}
		if (IsKeyDown(KEY_A) && posición_jugador_x >= 0) {
		
			posición_jugador_x -= 100 * GetFrameTime();

		}
		if (IsKeyDown(KEY_S) && posición_jugador_y <= 450) {
				
			posición_jugador_y += 100 * GetFrameTime();

		}

		// Creando al jugador.
		DrawRectangle(posición_jugador_x, posición_jugador_y, 50, 50, WHITE);

		// Terminando de dibujar.
		EndDrawing();

	}

	return 0;

}
