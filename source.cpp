// recursive form
template<typename T>
T gcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// iterative form
template<typename T>
T gcd(T a, T b, T& x, T& y) {
    x = 1, y = 0;
    T x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        T q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

// refernce = https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

####### python 3.8.2 #######

def GCD(a, b):
    if b == 0:
        x = 1
        y = 0
        return(x, y)
    A, B = GCD(b, a % b)
    x = B
    y = A-B*(a//b)
    return(x, y)

# iterative form


def GCD(a, b):
    x = 1
    y = 0
    x1, y1, a1, b1 = 0, 1, a, b
    while(b1):
        q = a1//b1
        x, x1 = x1, x-q*x1
        y, y1 = y1, y-q*y1
        a1, b1 = b1, a1-q*b1
    return(x, y)

