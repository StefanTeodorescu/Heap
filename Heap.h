//
// Created by Stefan Teodorescu on 01/05/16.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

template <typename T, typename Comp>
class Heap {
private:
    T* H;
    int size, capacity;

    void resize(const int& new_capacity) {
        T* new_H = new T[new_capacity];
        for (int i = 0; i < capacity; i ++) {
            new_H[i] = H[i];
        }

        delete[] H;
        H = new_H;
    }

    void pushUp() {
        int k = size - 1;

        while (k > 0 && !Comp(H[k], H[(k - 1) / 2])) {
            swap(H[k], H[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    void pushDown() {
        int k = 0;

        while (true) {
            if (2 * k + 1 < size) { //exista fiu stang
                if (2 * k + 2 < size) { //exista fiu drept
                    if (Comp(H[k], H[2 * k + 1]) && Comp(H[k], H[2 * k + 2])) { //proprietatea de heap este indeplinita
                        break;
                    }

                    if (Comp(H[2 * k + 1], H[2 * k + 2])) { //aleg fiul stang sa il aduc sus
                        swap(H[k], H[2 * k + 1]);
                        k = 2 * k + 1;
                        continue;
                    } else { //aleg fiul drept sa il aduc sus
                        swap(H[k], H[2 * k + 2]);
                        k = 2 * k + 2;
                        continue;
                    }
                } else { //exista fiu stang si nu exista drept
                    if (Comp(H[k], H[2 * k + 1])) { //proprietatea de heap este indeplinita
                        break;
                    } else {
                        swap(H[k], H[2 * k + 1]);
                        k = 2 * k + 1;
                        continue;
                    }
                }
            } //daca nu exista fiu, este indeplinita proprietatea
        }
    }

public:
    Heap() {
        size = 0;
        capacity = 1;
        H = new T[capacity];
    }

    Heap(int _capacity) {
        size = 0;
        capacity = _capacity;
        H = new T[capacity];
    }

    ~Heap() {
        delete[] H;
    }

    void insert(const T& elem) {
        if (size == capacity) {
            resize(capacity * 2);
        }

        H[size++] = elem;
        pushUp();
    }

    T front() {
        if (size == 0) {
            throw runtime_eror("front() method called for empty heap.");
        }
        return H[0];
    }

    T pop() {
        if (size == 0) {
            throw runtime_error("pop() method called for empty heap.");
        }

        const T ret = H[0];
        if (size > 1) {
            swap(H[0], H[size - 1]);
            size--;
            pushDown();
        } else { //size == 1
            size--;
        }

        return ret;
    }
};

#endif //HEAP_HEAP_H
