// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

int primerminijuego(unsigned int* escena_actual_ptr, float* temporizador_fondo_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr) {

	// Comprobando entradas del jugador.
	if (IsKeyDown(KEY_P)) {
		
		*escena_actual_ptr = 4;

	}

	// Administrando temporizador de fondo.
	if (*temporizador_fondo_ptr > 2) {

		*temporizador_fondo_ptr = 0;

	}
	if (*temporizador_fondo_ptr > 1 && *temporizador_fondo_ptr < 2) {
		
		DrawTexture(*fondo_2_ptr, 0, 0, WHITE);
		*temporizador_fondo_ptr += 2 * GetFrameTime();
	
	}
	if (*temporizador_fondo_ptr < 1) {
		
		DrawTexture(*fondo_ptr, 0, 0, WHITE);
		*temporizador_fondo_ptr += 2 * GetFrameTime();

	}

	return 0;

}

// Menú inicial.
int menu(bool* depuracion_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Vector2* coordenadas_espacio_ptr, float* temporizador_fondo_ptr, float* temporizador_espacio_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* espacio_ptr, Texture2D* espacio_2_ptr, Texture2D* cursor_ptr, Music* musica_ptr, Rectangle* hitbox_jugador_ptr, Rectangle* hitbox_salir_ptr) {

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

	// Administrando temporizador fondo.
	if (*temporizador_fondo_ptr > 2) {

		*temporizador_fondo_ptr = 0;

	}

	// Administrando fondos.
	if (*temporizador_fondo_ptr > 1) {
		
		DrawTexture(*fondo_2_ptr, 0, 0, WHITE);
		*temporizador_fondo_ptr += 2 * GetFrameTime();
	
	}
	else {
		
		DrawTexture(*fondo_ptr, 0, 0, WHITE);
		*temporizador_fondo_ptr += 2 * GetFrameTime();

	}

	// Comprobando colisiones.
	if (CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr) && *temporizador_fondo_ptr > 1) {

		// Mostrar el sprite de espacio.
		DrawTextureEx(*espacio_ptr, *coordenadas_espacio_ptr, 0, *temporizador_espacio_ptr, WHITE);

		if (*temporizador_espacio_ptr < 1) {
		
			// Aumentar el temporizador del sprite de espacio.
			*temporizador_espacio_ptr += GetFrameTime();

		}
		if (IsKeyDown(KEY_SPACE)) {
		
			*escena_actual_ptr = 2;
		
		}

	}
	if (CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr) && *temporizador_fondo_ptr < 1) {
	
		// Mostrar el otro sprite de espacio.
		DrawTextureEx(*espacio_2_ptr, *coordenadas_espacio_ptr, 0, *temporizador_espacio_ptr, WHITE);

		if (*temporizador_espacio_ptr < 1) {
		
			// Aumentar el temporizador del sprite de espacio.
			*temporizador_espacio_ptr += GetFrameTime();
		
		}
		if (IsKeyDown(KEY_SPACE)) {
		
			*escena_actual_ptr = 2;
		
		}
	
	}
	if (!CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr)) {
	
		*temporizador_espacio_ptr = 0;

	}

	// Creando al jugador.
	DrawTexture(*cursor_ptr, *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, WHITE);

	// Reproduciendo música.
	UpdateMusicStream(*musica_ptr);

	// Cosas para depuración.
	if (*depuracion_ptr == true) {

		// Mostrando las coordenadas del jugador en pantalla.
		DrawText(TextFormat("posición x del jugador: %f\nposición y del jugador: %f\nescena actual: %i\ntemporizador fondo: %f\ntemporizador espacio: %f", *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, *escena_actual_ptr, *temporizador_fondo_ptr, *temporizador_espacio_ptr), 10, 150, 12, BLACK);

	}

	return 0;

}

// Función principal.
int main(void) {

	// Declarando variables.
	bool depuracion = true;
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

			// Cargando elementos.
			case 0:

				// Reservando memoria para coordenadas del jugador.
				float* posicion_jugador_x_ptr = MemAlloc(sizeof(float));
				float* posicion_jugador_y_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para coordenadas del sprite de espacio.
				Vector2* coordenadas_espacio_ptr = MemAlloc(sizeof(Vector2));

				// Reservando memoria para los temporizadores.
				float* temporizador_fondo_ptr = MemAlloc(sizeof(float));
				float* temporizador_espacio_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para hitboxes.
				Rectangle* hitbox_jugador_ptr = MemAlloc(sizeof(Rectangle));
				Rectangle* hitbox_salir_ptr = MemAlloc(sizeof(Rectangle));

				// Reservando memoria para texturas.
				Texture2D* fondo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* fondo_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* espacio_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* espacio_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* cursor_ptr = MemAlloc(sizeof(Texture2D));

				// Reservando memoria para la música.
				Music* musica_ptr = MemAlloc(sizeof(Music));

				// Asignando valores a los datos anteriormente creados.
				*posicion_jugador_y_ptr = 450;
				coordenadas_espacio_ptr -> x = 100;
				coordenadas_espacio_ptr -> y = 400;
				*temporizador_fondo_ptr = 0;
				*fondo_ptr = LoadTexture("recursos/fondos/menu.png");
				*fondo_2_ptr = LoadTexture("recursos/fondos/menu_2.png");
				*espacio_ptr = LoadTexture("recursos/sprites/espacio.png");
				*espacio_2_ptr = LoadTexture("recursos/sprites/espacio_2.png");
				*cursor_ptr = LoadTexture("recursos/cursor.png");
				*musica_ptr = LoadMusicStream("recursos/musica/menu.mp3");
				hitbox_jugador_ptr -> width = 50;
				hitbox_jugador_ptr -> height = 50;
				hitbox_salir_ptr -> x = 150;
				hitbox_salir_ptr -> y = 0;
				hitbox_salir_ptr -> width = 200;
				hitbox_salir_ptr -> height = 100;

				// Iniciando el stream de música.
				PlayMusicStream(*musica_ptr);

				// Cambiando de escena.
				escena_actual = 1;

			break;

			// Ejecutando menú.
			case 1:
				menu(depuracion_ptr, escena_actual_ptr, posicion_jugador_x_ptr, posicion_jugador_y_ptr, coordenadas_espacio_ptr, temporizador_fondo_ptr, temporizador_espacio_ptr, fondo_ptr, fondo_2_ptr, espacio_ptr, espacio_2_ptr, cursor_ptr, musica_ptr, hitbox_jugador_ptr, hitbox_salir_ptr);
			break;

			// Liberando memoria reservada para el menú.
			case 2:
				StopMusicStream(*musica_ptr);
				UnloadTexture(*cursor_ptr);
				UnloadTexture(*espacio_ptr);
				UnloadTexture(*espacio_2_ptr);
				UnloadMusicStream(*musica_ptr);
				MemFree(posicion_jugador_x_ptr);
				MemFree(posicion_jugador_y_ptr);
				MemFree(coordenadas_espacio_ptr);
				MemFree(temporizador_espacio_ptr);
				MemFree(espacio_ptr);
				MemFree(espacio_2_ptr);
				MemFree(cursor_ptr);
				MemFree(musica_ptr);
				MemFree(hitbox_jugador_ptr);
				MemFree(hitbox_salir_ptr);
				escena_actual = 3;
			break;

			// Ejecutando primer mini juego.
			case 3:
				primerminijuego(escena_actual_ptr, temporizador_fondo_ptr, fondo_ptr, fondo_2_ptr);
			break;

			// Liberando memoria reservada para el primer mini juego.
			case 4:
				UnloadTexture(*fondo_ptr);
				UnloadTexture(*fondo_2_ptr);
				MemFree(temporizador_fondo_ptr);
				MemFree(fondo_ptr);
				MemFree(fondo_2_ptr);
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
