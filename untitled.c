// Versión 0.1 del proyecto "untitled".

#include <raylib.h>

// Declarando funciones antes de definirlas.
int menu(unsigned int* escena_a_cambiar, unsigned int* escena_actual_ptr, float* temporizador_fondo_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* titulo_ptr, Texture2D* titulo_2_ptr);
int tutorial(bool* depuracion_ptr, unsigned int* escena_a_cambiar, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Vector2* coordenadas_espacio_ptr, float* temporizador_fondo_ptr, float* escala_espacio_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* espacio_ptr, Texture2D* espacio_2_ptr, Texture2D* cursor_ptr, Music* musica_ptr, Rectangle* hitbox_jugador_ptr, Rectangle* hitbox_salir_ptr);
int primerminijuego(unsigned int* escena_a_cambiar, unsigned int* escena_actual_ptr, float* temporizador_fondo_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr);

// Función principal.
int main(void) {

	// Declarando variables.
	bool depuracion = false;
	unsigned int escena_a_cambiar = 0, escena_actual = 0;

	// Declarando punteros.
	bool* depuracion_ptr = &depuracion;
	unsigned int* escena_a_cambiar_ptr = &escena_a_cambiar;
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
		ClearBackground(WHITE);

		// Comprobación de escenas.
		switch (escena_actual) {

			// Cargando menú.
			case 0:

				// Reservando memoria para el temporizador.
				float* menu_temporizador_fondo_ptr = MemAlloc(sizeof(float));
	  
				// Reservando memoria para texturas.
				Texture2D* menu_fondo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* menu_fondo_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* titulo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* titulo_2_ptr = MemAlloc(sizeof(Texture2D));

				// Asignando valores a los datos anteriormente creados.
				*menu_temporizador_fondo_ptr = 0;
				*menu_fondo_ptr = LoadTexture("recursos/fondos/menu.png");
				*menu_fondo_2_ptr = LoadTexture("recursos/fondos/menu_2.png");
				*titulo_ptr = LoadTexture("recursos/sprites/titulo.png");
				*titulo_2_ptr = LoadTexture("recursos/sprites/titulo_2.png");

				// Cambiando de escena.
				escena_actual = 1;

			break;

			// Ejecutando menú.
			case 1:
				menu(escena_a_cambiar_ptr, escena_actual_ptr, menu_temporizador_fondo_ptr, menu_fondo_ptr, menu_fondo_2_ptr, titulo_ptr, titulo_2_ptr);
			break;

			// Liberando memoria reservada para el menú.
			case 2:

				UnloadTexture(*titulo_2_ptr);
				UnloadTexture(*titulo_ptr);
				UnloadTexture(*menu_fondo_2_ptr);
				UnloadTexture(*menu_fondo_ptr);
				MemFree(titulo_2_ptr);
				MemFree(titulo_ptr);
				MemFree(menu_fondo_2_ptr);
				MemFree(menu_fondo_ptr);
				MemFree(menu_temporizador_fondo_ptr);

				// Cambiando de escena.
				escena_actual = escena_a_cambiar;

			break;

			// Cargando tutorial.
			case 3:

				// Reservando memoria para coordenadas del jugador.
				float* posicion_jugador_x_ptr = MemAlloc(sizeof(float));
				float* posicion_jugador_y_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para coordenadas del sprite de espacio.
				Vector2* coordenadas_espacio_ptr = MemAlloc(sizeof(Vector2));

				// Reservando memoria para los temporizadores.
				float* tutorial_temporizador_fondo_ptr = MemAlloc(sizeof(float));
				float* escala_espacio_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para hitboxes.
				Rectangle* hitbox_jugador_ptr = MemAlloc(sizeof(Rectangle));
				Rectangle* hitbox_salir_ptr = MemAlloc(sizeof(Rectangle));

				// Reservando memoria para texturas.
				Texture2D* tutorial_fondo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* tutorial_fondo_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* espacio_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* espacio_2_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* cursor_ptr = MemAlloc(sizeof(Texture2D));

				// Reservando memoria para la música.
				Music* musica_ptr = MemAlloc(sizeof(Music));

				// Asignando valores a los datos anteriormente creados.
				*posicion_jugador_y_ptr = 450;
				coordenadas_espacio_ptr -> x = 250;
				coordenadas_espacio_ptr -> y = 400;
				*tutorial_temporizador_fondo_ptr = 0;
				*escala_espacio_ptr = 0;
				*tutorial_fondo_ptr = LoadTexture("recursos/fondos/tutorial.png");
				*tutorial_fondo_2_ptr = LoadTexture("recursos/fondos/tutorial_2.png");
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
				escena_actual = 4;

			break;

			// Ejecutando tutorial.
			case 4:
				tutorial(depuracion_ptr, escena_a_cambiar_ptr, escena_actual_ptr, posicion_jugador_x_ptr, posicion_jugador_y_ptr, coordenadas_espacio_ptr, tutorial_temporizador_fondo_ptr, escala_espacio_ptr, tutorial_fondo_ptr, tutorial_fondo_2_ptr, espacio_ptr, espacio_2_ptr, cursor_ptr, musica_ptr, hitbox_jugador_ptr, hitbox_salir_ptr);
			break;

			// Liberando memoria reservada para el tutorial.
			case 5:

				StopMusicStream(*musica_ptr);
				UnloadTexture(*cursor_ptr);
				UnloadTexture(*espacio_2_ptr);
				UnloadTexture(*espacio_ptr);
				UnloadTexture(*tutorial_fondo_2_ptr);
				UnloadTexture(*tutorial_fondo_ptr);
				UnloadMusicStream(*musica_ptr);
				MemFree(musica_ptr);
				MemFree(cursor_ptr);
				MemFree(espacio_2_ptr);
				MemFree(espacio_ptr);
				MemFree(tutorial_fondo_2_ptr);
				MemFree(tutorial_fondo_ptr);
				MemFree(hitbox_salir_ptr);
				MemFree(hitbox_jugador_ptr);
				MemFree(escala_espacio_ptr);
				MemFree(tutorial_temporizador_fondo_ptr);
				MemFree(coordenadas_espacio_ptr);
				MemFree(posicion_jugador_y_ptr);
				MemFree(posicion_jugador_x_ptr);

				// Cambiando de escena.
				escena_actual = escena_a_cambiar;

			break;

			// Cargando primer mini juego.
			case 6:
		
				// Reservando memoria para el temporizador.
				float* primerminijuego_temporizador_fondo_ptr = MemAlloc(sizeof(float));

				// Reservando memoria para texturas.
				Texture2D* primerminijuego_fondo_ptr = MemAlloc(sizeof(Texture2D));
				Texture2D* primerminijuego_fondo_2_ptr = MemAlloc(sizeof(Texture2D));

				// Asignando valores a los datos anteriormente creados.
				*primerminijuego_temporizador_fondo_ptr = 0;
				*primerminijuego_fondo_ptr = LoadTexture("recursos/fondos/tutorial.png");
				*primerminijuego_fondo_2_ptr = LoadTexture("recursos/fondos/tutorial_2.png");

				// Cambiando de escena.
				escena_actual = 7;

			break;

			// Ejecutando primer mini juego.
			case 7:
				primerminijuego(escena_a_cambiar_ptr, escena_actual_ptr, primerminijuego_temporizador_fondo_ptr, primerminijuego_fondo_ptr, primerminijuego_fondo_2_ptr);
			break;

			// Liberando memoria reservada para el primer mini juego.
			case 8:

				UnloadTexture(*primerminijuego_fondo_2_ptr);
				UnloadTexture(*primerminijuego_fondo_ptr);
				MemFree(primerminijuego_fondo_2_ptr);
				MemFree(primerminijuego_fondo_ptr);
				MemFree(primerminijuego_temporizador_fondo_ptr);

				// Cambiando de escena.
				escena_actual = escena_a_cambiar;

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

// Menú.
int menu(unsigned int* escena_a_cambiar_ptr, unsigned int* escena_actual_ptr, float* temporizador_fondo_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* titulo_ptr, Texture2D* titulo_2_ptr) {

	// Comprobando entradas del jugador.
	if (IsKeyDown(KEY_P)) {
	
		*escena_a_cambiar_ptr = 3;
		*escena_actual_ptr = 2;
	
	}
	if (IsKeyDown(KEY_L)) {
	
		*escena_a_cambiar_ptr = 6;
		*escena_actual_ptr = 2;
	
	}

	// Administrando temporizador fondo.
	if (*temporizador_fondo_ptr >= 2) {

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

	return 0;

}

// Tutorial.
int tutorial(bool* depuracion_ptr, unsigned int* escena_a_cambiar_ptr, unsigned int* escena_actual_ptr, float* posicion_jugador_x_ptr, float* posicion_jugador_y_ptr, Vector2* coordenadas_espacio_ptr, float* temporizador_fondo_ptr, float* escala_espacio_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr, Texture2D* espacio_ptr, Texture2D* espacio_2_ptr, Texture2D* cursor_ptr, Music* musica_ptr, Rectangle* hitbox_jugador_ptr, Rectangle* hitbox_salir_ptr) {

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
	if (*temporizador_fondo_ptr >= 2) {

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
		DrawTextureEx(*espacio_ptr, *coordenadas_espacio_ptr, 0, *escala_espacio_ptr, WHITE);

		if (*escala_espacio_ptr <= 1 && coordenadas_espacio_ptr -> x >= 100) {
		
			// Reducir las coordenadas en eje x para mantener centrado el sprite.
			coordenadas_espacio_ptr -> x -= 150 * GetFrameTime();

			// Aumentar el temporizador del sprite de espacio.
			*escala_espacio_ptr += GetFrameTime();

		}
		if (IsKeyDown(KEY_SPACE)) {
		
			*escena_a_cambiar_ptr = 0;
			*escena_actual_ptr = 5;
		
		}

	}
	if (CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr) && *temporizador_fondo_ptr < 1) {
	
		// Mostrar el otro sprite de espacio.
		DrawTextureEx(*espacio_2_ptr, *coordenadas_espacio_ptr, 0, *escala_espacio_ptr, WHITE);

		if (*escala_espacio_ptr <= 1 && coordenadas_espacio_ptr -> x >= 100) {

			// Reducir las coordenadas en eje x para mantener centrado el sprite.
			coordenadas_espacio_ptr -> x -= 150 * GetFrameTime();

			// Aumentar el temporizador del sprite de espacio.
			*escala_espacio_ptr += GetFrameTime();
		
		}
		// Cambiar escena al presionar espacio.
		if (IsKeyDown(KEY_SPACE)) {
		
			*escena_a_cambiar_ptr = 0;
			*escena_actual_ptr = 5;
		
		}
	
	}
	// Definiendo que hacer al no detectar colisión.
	if (!CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr) && *temporizador_fondo_ptr > 1) {
	
		// Animación de salida del sprite de espacio.
		if (*escala_espacio_ptr >= 0 && coordenadas_espacio_ptr -> x < 250) {

			DrawTextureEx(*espacio_ptr, *coordenadas_espacio_ptr, 0, *escala_espacio_ptr, WHITE);
		
			coordenadas_espacio_ptr -> x += 150 * GetFrameTime();

			*escala_espacio_ptr -= GetFrameTime();
		
		}
		
	}
	if (!CheckCollisionRecs(*hitbox_jugador_ptr, *hitbox_salir_ptr) && *temporizador_fondo_ptr < 1) {
	
		// Animación de salida del sprite de espacio.
		if (*escala_espacio_ptr >= 0 && coordenadas_espacio_ptr -> x < 250) {

			DrawTextureEx(*espacio_2_ptr, *coordenadas_espacio_ptr, 0, *escala_espacio_ptr, WHITE);
		
			coordenadas_espacio_ptr -> x += 150 * GetFrameTime();

			*escala_espacio_ptr -= GetFrameTime();
		
		}
		
	}

	// Creando al jugador.
	DrawTexture(*cursor_ptr, *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, WHITE);

	// Reproduciendo música.
	UpdateMusicStream(*musica_ptr);

	// Cosas para depuración.
	if (*depuracion_ptr == true) {

		// Mostrando las coordenadas del jugador en pantalla.
		DrawText(TextFormat("posición x del jugador: %f\nposición y del jugador: %f\nescena actual: %i\ntemporizador fondo: %f\ntemporizador espacio: %f", *posicion_jugador_x_ptr, *posicion_jugador_y_ptr, *escena_actual_ptr, *temporizador_fondo_ptr, *escala_espacio_ptr), 10, 150, 12, BLACK);

	}

	return 0;

}

// Primer minijuego.
int primerminijuego(unsigned int* escena_a_cambiar, unsigned int* escena_actual_ptr, float* temporizador_fondo_ptr, Texture2D* fondo_ptr, Texture2D* fondo_2_ptr) {

	// Comprobando entradas del jugador.
	if (IsKeyDown(KEY_P)) {
		
		*escena_a_cambiar = 0;
		*escena_actual_ptr = 8;

	}

	// Administrando temporizador fondo.
	if (*temporizador_fondo_ptr >= 2) {

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

	return 0;

}
