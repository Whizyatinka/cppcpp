import addList
import time

lst = list(range(1, 10001))

def py_add_list(lst):
    start = time.time()
    s = 0
    for x in lst:
        s += int(x)
    end = time.time()
    return s, end - start

def main(lst):
    c_sum, c_time = addList.add(lst)
    p_sum, p_time = py_add_list(lst)

    print("C++:   сумма =", c_sum, "время =", round(c_time, 2), "с")
    print("Python: сумма =", p_sum, "время =", round(p_time, 2), "с")

    if c_time > 0:
        print("Python медленнее примерно в", round(p_time / c_time, 2), "раз")

if __name__ == "__main__":
    main(lst)

