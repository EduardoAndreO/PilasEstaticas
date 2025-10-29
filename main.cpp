#include <iostream>
#include <stdio.h>
#include <cstddef>

template<typename T, std::size_t N>
struct Stack {
    T buf[N];
    std::size_t cnt = 0;

    bool push(const T& v) noexcept {
        if (cnt == N) return false; // pila llena
        buf[cnt++] = v;
        return true;
    }

    bool pop() noexcept {
        if (cnt == 0) return false; // pila vacía
        --cnt;
        return true;
    }

    // Devuelve puntero al tope o nullptr si está vacía
    T* top() noexcept {
        return cnt ? &buf[cnt - 1] : nullptr;
    }

    bool empty() const noexcept { return cnt == 0; }
    bool full()  const noexcept { return cnt == N; }
    std::size_t size() const noexcept { return cnt; }
};

int main() {
    Stack<int, 4> s;

    std::cout << "---- Demostracion: Pila Estatica ----\n";

    // Apilar hasta llenar
    for (int i = 1; i <= 5; ++i) {
        if (s.push(i)) {
            std::cout << "push(" << i << ") Tama\xA4o = " << s.size() << '\n';
        } else {
            std::cout << "push(" << i << ") Pila llena\n";
        }
    }

    // Mostrar y desapilar
    std::cout << "\nDesapilando elementos:\n";
    while (!s.empty()) {
        std::cout << " tope = " << *s.top() << " -> pop()\n";
        s.pop();
    }

    // Intentar desapilar más para mostrar underflow
    if (!s.pop()) std::cout << "No se puede hacer pop(): pila vacia\n";

    return 0;
}