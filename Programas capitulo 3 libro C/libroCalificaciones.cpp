#include <iostream>
#include <string>

class LibroCalificaciones {
private:
    std::string nombreCurso;
    std::string nombreInstructor;

public:
    LibroCalificaciones(std::string curso, std::string instructor)
        : nombreCurso(curso), nombreInstructor(instructor) {}

    void establecerNombreCurso(std::string curso) {
        nombreCurso = curso;
    }

    std::string obtenerNombreCurso() const {
        return nombreCurso;
    }

    void establecerNombreInstructor(std::string instructor) {
        nombreInstructor = instructor;
    }

    std::string obtenerNombreInstructor() const {
        return nombreInstructor;
    }

    void mostrarMensaje() const {
        std::cout << "Bienvenido al libro de calificaciones para " << obtenerNombreCurso() << "!\n";
        std::cout << "Este curso es presentado por: " << obtenerNombreInstructor() << std::endl;
    }
};

int main() {
    LibroCalificaciones libro("Programacion en C++", "Dr. Smith");
    libro.mostrarMensaje();
    return 0;
}
