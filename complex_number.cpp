#include <iostream>



class ComplexNumber {

private:

    double real;

    double imag;



public:

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}



    // Addition

    ComplexNumber operator+(const ComplexNumber& other) const {

        std::cout<<"Other Real : " << other.real << "\tOther Imag : "<<other.imag;

        std::cout<<"\tReal : " << real << "\tImag : "<<imag<<std::endl;

        return {real + other.real, imag + other.imag};

    }



    // Subtraction

    ComplexNumber operator-(const ComplexNumber& other) const {

        return {real - other.real, imag - other.imag};

    }



    // Multiplication

    ComplexNumber operator*(const ComplexNumber& other) const {

        return {real * other.real - imag * other.imag, real * other.imag + imag * other.real};

    }



    // Division

    ComplexNumber operator/(const ComplexNumber& other) const {

        double denominator = other.real * other.real + other.imag * other.imag;

        return {(real * other.real + imag * other.imag) / denominator,

                       (imag * other.real - real * other.imag) / denominator};

    }



    // Display complex number

    void display() const

    {

        if (imag >= 0)

        {

            std::cout << real << " + " << imag << "i";

        }

        else

        {

            std::cout << real << " - " << -imag << "i";

        }

    }

};



int main() {

    ComplexNumber num1(3.0, 4.0);

    ComplexNumber num2(1.0, 2.0);



    ComplexNumber sum = num1 + num2;

    std::cout << "Addition: ";

    sum.display();

    std::cout << std::endl;



    ComplexNumber diff = num1 - num2;

    std::cout << "Subtraction: ";

    diff.display();

    std::cout << std::endl;



    ComplexNumber prod = num1 * num2;

    std::cout << "Multiplication: ";

    prod.display();

    std::cout << std::endl;



    ComplexNumber quot = num1 / num2;

    std::cout << "Division: ";

    quot.display();

    std::cout << std::endl;



    return 0;

}
