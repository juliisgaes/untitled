// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

// Probablemente en un futuro esto se encuentre en un archivo "header".
int menu(bool* depuracion_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* cursor_ptr, Rectangle* hitbox_jugador_ptr, Rectangle* hitbox_salir_ptr, float* temporizador_ptr, Music* musica_ptr);

// Función principal.
int main(void) {

	// Declarando variables.
	bool depuracion = false;
	unsigned int escena_actual = 0;

	// Declarando punteros.
	bool* depuracion_ptr = &depuracion;
	unsigned int* escena_actual_ptr = &escena_actual;

	// Creando la ventana principal.
	InitWindow(500, 500, "untitled - 0.1");

	// Inicializando audio.
	InitAudioDevice();

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

				// Reservando memoria para coordenadas del jugador.
				float* posicion_jugador_x_ptr = MemAlloc(sizeof(float));
				float* posicion_jugador_y_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para hitboxes.
				Rectangle* hitbox_jugador_ptr = MemAlloc(sizeof(Rectangle));
				Rectangle* hitbox_salir_ptr = MemAlloc(sizeof(Rectangle));

				// Reservando memoria para texturas.
				Texture2D* fondo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* fondo_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* cursor_ptr = MemAlloc(sizeof(Texture2D));

				// Reservando memoria para el temporizador.
				float* temporizador_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para la música.
				Music* musica_ptr = MemAlloc(sizeof(Music));

				// Asignando valores a los datos anteriormente creados.
				*posicion_jugador_y_ptr = 450;
				*fondo_ptr = LoadTexture("recursos/fondos/menu.png");
				*fondo_2_ptr = LoadTexture("recursos/fondos/menu_2.png");
				*cursor_ptr = LoadTexture("recursos/cursor.png");
				hitbox_jugador_ptr -> width = 50;
				hitbox_jugador_ptr -> height = 50;
				hitbox_salir_ptr -> x = 150;
				hitbox_salir_ptr -> y = 0;
				hitbox_salir_ptr -> width = 200;
				hitbox_salir_ptr -> height = 100;
				*temporizador_ptr = 0;
				*musica_ptr = LoadMusicStream("recursos/musica/menu.mp3");

				// Iniciando el stream de música.
				PlayMusicStream(*musica_ptr);

				// Cambiando de escena.
				escena_actual++;

			break;

			// Ejecutando menú.
			case 1:
				menu(depuracion_ptr, escena_actual_ptr, posicion_jugador_x_ptr, posicion_jugador_y_ptr, fondo_ptr, fondo_2_ptr, cursor_ptr, hitbox_jugador_ptr, hitbox_salir_ptr, temporizador_ptr, musica_ptr);
			break;

			// Liberando memoria reservada para el menú.
			case 2:
				StopMusicStream(*musica_ptr);
				UnloadTexture(*fondo_ptr);
				UnloadTexture(*fondo_2_ptr);
				UnloadTexture(*cursor_ptr);
				MemFree(posicion_jugador_x_ptr);
				MemFree(posicion_jugador_y_ptr);
				MemFree(fondo_ptr);
				MemFree(fondo_2_ptr);
				MemFree(cursor_ptr);
				MemFree(hitbox_jugador_ptr);
				MemFree(hitbox_salir_ptr);
				MemFree(temporizador_ptr);
				UnloadMusicStream(*musica_ptr);
				MemFree(musica_ptr);
			break;

		}

		// Terminando de dibujar.
		EndDrawing();

	}

	// Apagando audio.
	CloseAudioDevice();

	// Cerrando ventana.
	CloseWindow();

	return 0;

}

// Menú inicial.
int menu(bool* depuracion_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* cursor_ptr, Rectangle* hitbox_jugador_ptr, Rectangle* hitbox_salir_ptr, float* temporizador_ptr, Music* musica_ptr) {

	// Definiendo hitbox del jugador.
	hitbox_jugador_ptr -> x = *posicion_jugador_x_ptr;
	hitbox_jugador_ptr -> y = *posicion_jugador_y_ptr;

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

	// Comprobando colisiones.
	if (CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr)) {
		
		*escena_actual_ptr = 2;

	}

	// Administrando el temporizador.
	if (*temporizador_ptr >= 2) {

		*temporizador_ptr = 0;

	}
	else {
		
		*temporizador_ptr += 3 * GetFrameTime();
	
	}

	// Dibujando fondo.
	if (*temporizador_ptr > 1) {

		DrawTexture(*fondo_2_ptr, 0, 0, WHITE);

	}
	else {
	
		DrawTexture(*fondo_ptr, 0, 0, WHITE);

	}

	// Creando al jugador.
	DrawTexture(*cursor_ptr, *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, WHITE);

	// Reproduciendo música.
	UpdateMusicStream(*musica_ptr);

	// Cosas para depuración.
	if (*depuracion_ptr == true) {

		// Mostrando las coordenadas del jugador en pantalla.
		DrawText(TextFormat("posición x del jugador: %f\nposición y del jugador: %f\nescena actual: %i\ntemporizador: %f", *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, *escena_actual_ptr, *temporizador_ptr), 10, 150, 12, BLACK);

	}

	return 0;

}
