#pragma once


template<typename T> requires std::floating_point<T>


class complex_number
{
    T re, im;
    
public:
    complex_number(){ /*Costruttore di default*/
        re = 0;
        im = 0;
    }

    complex_number(T a, T b){ /*Costruttore definito dall'utente*/
        re = a;
        im = b;
    }

    explicit complex_number(T a){
        re = a;
        im = 0;
        std::cout << "Si sta assumendo che il numero complesso " << a << " chiamato abbia parte immaginaria nulla." << std::endl;
    }
    
    complex_number conjugate(void) const{
        return complex_number(re, -im);
    }
    
    T Re(void) const{
        return re;
    }

    T Im(void) const{
        return im;
    }
    
    /*Somma di numeri complessi*/

    complex_number& operator+=(const complex_number& other) {
        T a = re;
        T b = im;
        T c = other.re;
        T d = other.im;
        re = a + c;
        im = b + d;
        return *this;
	}
    
	complex_number operator+(const complex_number& other) const {
        complex_number res = *this;
        res += other;
        return res;
    }

    /*Somma di un numero complesso e un numero reale*/
     complex_number& operator+=(const T& other) {
        re += other;
        return *this;
	}
	
	complex_number operator+(const T& other) const {
        complex_number res = *this;
        res += other;
        return res;
    }

    /*Prodotto di numeri complessi*/
    complex_number& operator*=(const complex_number& other) { /*(a+ib)(c+id)=ac-bd+i*(ad+bc)*/
        T a = re;
        T b = im;
        T c = other.re;
        T d = other.im;
        re = a*c - b*d;
        im = a*d + b*c;
        return *this;
	}
    
	complex_number operator*(const complex_number& other) const {
        complex_number resu = *this;
        resu *= other;
        return resu;
    }

    /*Prodotto di un numero complesso e un numero reale*/
     complex_number& operator*=(const T& other) {
        re *= other;
        im *= other;
        return *this;
	}
	
	complex_number operator*(const T& other) const {
        complex_number resul = *this;
        resul *= other;
        return resul;
    }

    
    
};

/* Commutatività delle operazioni in C */

template<typename T>
complex_number<T>
operator+(const T& t, const complex_number<T>& c)
{
    return c + t;
}

template<typename T>
complex_number<T>
operator*(const T& t, const complex_number<T>& c)
{
    return c * t;
}

/* Overload di <<, per stampare i complessi. */
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
        T re = c.Re();
        T im = c.Im();
        if (re == 0 && im == 0){
            os << "0";
        }else if (re == 0 && im != 0){
            os << c.Im() << "i";
        }else if (re != 0 && im == 0){
            os << c.Re();
        }else if(re != 0 && im > 0){
        os << c.Re() << "+" << c.Im() << "i";
        }else if(re != 0 && im < 0){
        im = c.Im();
        im = -im;
        os << c.Re() << "-" << im << "i";   
        }
        return os;
}
