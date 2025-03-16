#include <iostream>
#include <string>
#include <cmath>

class PerfilMedico {
private:
    std::string primerNombre;
    std::string apellido;
    std::string sexo;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    double altura; // en cm
    double peso;   // en kg

public:
    PerfilMedico(std::string nombre, std::string apellido, std::string sexo, int dia, int mes, int anio, double altura, double peso)
        : primerNombre(nombre), apellido(apellido), sexo(sexo), diaNacimiento(dia), mesNacimiento(mes), anioNacimiento(anio), altura(altura), peso(peso) {}

    void establecerPrimerNombre(std::string nombre) {
        primerNombre = nombre;
    }

    std::string obtenerPrimerNombre() const {
        return primerNombre;
    }

    void establecerApellido(std::string apellido) {
        this->apellido = apellido;
    }

    std::string obtenerApellido() const {
        return apellido;
    }

    void establecerSexo(std::string sexo) {
        this->sexo = sexo;
    }

    std::string obtenerSexo() const {
        return sexo;
    }

    void establecerDiaNacimiento(int dia) {
        diaNacimiento = dia;
    }

    int obtenerDiaNacimiento() const {
        return diaNacimiento;
    }

    void establecerMesNacimiento(int mes) {
        mesNacimiento = mes;
    }

    int obtenerMesNacimiento() const {
        return mesNacimiento;
    }

    void establecerAnioNacimiento(int anio) {
        anioNacimiento = anio;
    }

    int obtenerAnioNacimiento() const {
        return anioNacimiento;
    }

    void establecerAltura(double altura) {
        this->altura = altura;
    }

    double obtenerAltura() const {
        return altura;
    }

    void establecerPeso(double peso) {
        this->peso = peso;
    }

    double obtenerPeso() const {
        return peso;
    }

    int calcularEdad(int anioActual) const {
        return anioActual - anioNacimiento;
    }

    int calcularFrecuenciaCardiacaMaxima(int anioActual) const {
        return 220 - calcularEdad(anioActual);
    }

    std::string calcularRangoFrecuenciaCardiaca(int anioActual) const {
        int frecuenciaMaxima = calcularFrecuenciaCardiacaMaxima(anioActual);
        return std::to_string(static_cast<int>(frecuenciaMaxima * 0.5)) + " - " + std::to_string(static_cast<int>(frecuenciaMaxima * 0.85));
    }

    double calcularBMI() const {
        double alturaMetros = altura / 100.0;
        return peso / (alturaMetros * alturaMetros);
    }

    void mostrarInformacion(int anioActual) const {
        std::cout << "Nombre: " << primerNombre << " " << apellido << "\n"
                  << "Sexo: " << sexo << "\n"
                  << "Fecha de Nacimiento: " << diaNacimiento << "/" << mesNacimiento << "/" << anioNacimiento << "\n"
                  << "Altura: " << altura << " cm\n"
                  << "Peso: " << peso << " kg\n"
                  << "Edad: " << calcularEdad(anioActual) << " anios\n"
                  << "Frecuencia Cardiaca Maxima: " << calcularFrecuenciaCardiacaMaxima(anioActual) << " bpm\n"
                  << "Rango de Frecuencia Cardiaca Esperada: " << calcularRangoFrecuenciaCardiaca(anioActual) << " bpm\n"
                  << "BMI: " << calcularBMI() << std::endl;
    }
};

int main() {
    PerfilMedico perfil("Juan", "Perez", "Masculino", 15, 5, 1990, 175, 70);
    perfil.mostrarInformacion(2023);

    return 0;
}
