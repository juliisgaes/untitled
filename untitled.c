/* Versión 0.1 del proyecto "untitled". */

#include <raylib.h>

int main(void) {
	// Creando la ventana principal.
	InitWindow(500, 500, "untitled - 0.1");
	// Bucle para actualizar pantalla.
	while (!WindowShouldClose()) {
		// Comenzando a dibujar.
		BeginDrawing();
		// Limpiando el canvas.
		ClearBackground(GRAY);
		// Terminando de dibujar.
		EndDrawing();
	}
	return 0;
}
