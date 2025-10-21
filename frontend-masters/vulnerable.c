#include <stdio.h>
#include <string.h>

// Usamos una estructura para asegurarnos de que las variables
// estén una junto a la otra en la memoria.
struct InfoUsuario {
    char nombre[20];
    int acceso_permitido; // 0 = No, 1 = Sí
};

int main() {
    struct InfoUsuario usuario;
    char entrada[100];

    // Inicializamos las variables
    strcpy(usuario.nombre, "");
    usuario.acceso_permitido = 0; // El acceso está denegado por defecto

    printf("Introduce tu nombre de usuario: ");
    scanf("%s", entrada);

    // --- LA VULNERABILIDAD ESTÁ AQUÍ ---
    // strcpy no comprueba el tamaño y puede desbordar el buffer 'nombre'
    strcpy(usuario.nombre, entrada);
    // --- FIN DE LA VULNERABILIDAD ---

    printf("\nProcesando...\n");
    printf("Valor de 'acceso_permitido' en memoria: %d\n", usuario.acceso_permitido);

    if (usuario.acceso_permitido == 1) {
        printf("\n>>> ¡Acceso Concedido! Bienvenido, usuario LEGÍTIMO. <<<\n");
    } else {
        printf("\n>>> Acceso Denegado. <<<\n");
    }

    return 0;
}