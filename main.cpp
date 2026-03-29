#include <iostream>
#include <numeric>
using namespace std;
// ex1
class Fraction {
public:
    // Constructeurs
    Fraction() : num(0), den(1) {}
    Fraction(int i) : num(i), den(1) {}
    Fraction(int n, int d) : num(n), den(d) {
        normalise();
    }
    Fraction(const Fraction& f) : num(f.num), den(f.den) {}

    // Destructeur
    ~Fraction() {}

    // Méthode d'affichage
    void affiche() const {
        if (den == 1) {
            std::cout << num << std::endl;
        } else {
            std::cout << num << "/" << den << std::endl;
        }
    }

    // Surcharge des opérateurs
    Fraction operator+(const Fraction& f) const {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(const Fraction& f) const {
    if (f.num == 0) {
        cerr << "Erreur : division par zero !" << endl;
        exit(1);
    }
    return Fraction(num * f.den, den * f.num);
}

private:
    int num, den;

    // Calcul du PGCD avec l’algorithme d’Euclide
    int pgcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a < 0) ? -a : a; // toujours positif
    }

    void normalise() {
        if (den == 0) {
            std::cerr << "Erreur : denominateur nul !" << std::endl;
            exit(1);
        }

        if (den < 0) {
            num = -num;
            den = -den;
        }

        int div = pgcd(num, den);
        num /= div;
        den /= div;
    }
};
int main(){
     Fraction f1(1, 2);
    Fraction f2(3, 4);

    cout << "f1 = "; f1.affiche();
    cout << "f2 = "; f2.affiche();

    Fraction sum = f1 + f2;
    cout << "f1 + f2 = "; sum.affiche();

    Fraction diff = f1 - f2;
    cout << "f1 - f2 = "; diff.affiche();

    Fraction prod = f1 * f2;
    cout << "f1 * f2 = "; prod.affiche();

    Fraction div = f1 / f2;
    cout << "f1 / f2 = "; div.affiche();

    return 0;


}
