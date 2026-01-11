# untitled.

## instrucciones para compilar.

```
# clonar el repositorio.
git clone --depth 1 https://github.com/juliisgaes/untitled.git

# entrar en el directorio del repositorio.
cd untitled

# compilar con gcc (estas instrucciones generan un binario estático).
cc -I raylib-5.5_linux_amd64/include/ -static-libgcc -L raylib-5.5_linux_amd64/lib/ -o untitled untitled.c -lraylib -lm
```
