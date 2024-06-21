#include "Fixed.hpp"

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

int main() {
    // コンストラクタのテスト
    Fixed a; // デフォルトコンストラクタ
    Fixed b(10); // intコンストラクタ
    Fixed c(3.14f); // floatコンストラクタ
    Fixed d(b); // コピーコンストラクタ

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // 代入演算子のテスト
    a = c;
    std::cout << "a (after assignment): " << a << std::endl;

    // 比較演算子のテスト
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // 算術演算子のテスト
    Fixed e = b + c;
    Fixed f = b - c;
    Fixed g = b * c;
    Fixed h = b / c;

    std::cout << "b + c: " << e << std::endl;
    std::cout << "b - c: " << f << std::endl;
    std::cout << "b * c: " << g << std::endl;
    std::cout << "b / c: " << h << std::endl;

    // インクリメント/デクリメント演算子のテスト
    Fixed i;
    std::cout << "i: " << i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i: " << i << std::endl;

    std::cout << "--i: " << --i << std::endl;
    std::cout << "i--: " << i-- << std::endl;
    std::cout << "i: " << i << std::endl;

    // min, max関数のテスト
    Fixed minVal = Fixed::min(b, c);
    Fixed maxVal = Fixed::max(b, c);

    std::cout << "min(b, c): " << minVal << std::endl;
    std::cout << "max(b, c): " << maxVal << std::endl;

    return 0;
}
